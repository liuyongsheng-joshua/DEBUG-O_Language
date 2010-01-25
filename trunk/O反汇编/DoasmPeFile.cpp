
#include "stdafx.h"
#include "DoasmPeFile.h"
#include "./PeFile.h"
#include "./DoasmDll.h"

#define DOASM_INSNS_TO_TEXT_LENGTH 30

#pragma warning (disable:4996)

//�����ļ��Ƿ����
bool FileExist(const CString& strFileName,bool bDirectory)
{
	bool bExist = false;
	WIN32_FIND_DATA fd; 
	HANDLE hFind = FindFirstFile(strFileName, &fd);
	//���������
	if (hFind == INVALID_HANDLE_VALUE) 
	{ 
		bExist = false;
	}
	//�����Ŀ¼
	else if(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		if(bDirectory)
		{
			bExist = true;
		}
		else
		{
			bExist = false;
		}
	}
	else
	{
		bExist = true;
	}

	FindClose(hFind);

	return bExist;
}

BOOL GetFunctionNameByAddr(CPeFile& peFile,DWORD ddFunctionAddr,char* pchBuffer,int nBufferLen)
{
	PIMAGE_OPTIONAL_HEADER pOH = NULL;
	pOH = peFile.GetOptionalHeader();
	
	//DataDirectory�ĵڶ����������
	if ( pOH->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress == 0 &&
		pOH->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size == 0 )
	{
		//�����Ϊ��
		return FALSE;
	}

	//IMAGE_IMPORT_DESCRIPTOR�����ļ�ƫ��
	IMAGE_IMPORT_DESCRIPTOR* pImpDllTable = (IMAGE_IMPORT_DESCRIPTOR*)peFile.GetFileRawAddr(pOH->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
	
	for( ; ( pImpDllTable != 0 ) && ( pImpDllTable->Name != 0 ) ; pImpDllTable ++ )
	{			
		//��ǰģ������
		const char* pszDllName = (const char*)peFile.GetFileRawAddr(pImpDllTable->Name);
		
		DWORD*	pRVANameArray ;
		if( pImpDllTable->Characteristics != 0 )
		{
			pRVANameArray = (DWORD*)peFile.GetFileRawAddr(pImpDllTable->Characteristics ) ;
		}
		else
		{
			pRVANameArray = (DWORD*)peFile.GetFileRawAddr((DWORD)pImpDllTable->FirstThunk ) ;
		}

		//��һ��������ַ
		DWORD curFunVA = (DWORD)pImpDllTable->FirstThunk + pOH->ImageBase ;

		//���Һ���
		const char* pFunName;
		do
		{	
			//����ҵ���ַ��ȵĺ���
			if(ddFunctionAddr == curFunVA)
			{
				if(((*pRVANameArray ) & IMAGE_ORDINAL_FLAG ) != 0)
				{
					return FALSE;
				}
				else
				{
					pFunName = (const char*)&(((IMAGE_IMPORT_BY_NAME*)peFile.GetFileRawAddr(*pRVANameArray ))->Name)[0];
					strcpy_s(pchBuffer,nBufferLen,pszDllName);
					strcat(pchBuffer,"->");
					strcat(pchBuffer,pFunName);

					return TRUE;
				}
			}			
			
			curFunVA += 4; //��һ��������ַ
			pRVANameArray ++;
		}
		while( *pRVANameArray != 0 );
	}

	return FALSE;
}

DWORD GetFunctionRealAddr(CPeFile& peFile,DWORD pFunAddr)
{
	PIMAGE_FILE_HEADER      pFH=NULL;
	PIMAGE_SECTION_HEADER   pSH=NULL;
	PIMAGE_OPTIONAL_HEADER  pOH=NULL;

	pFH = peFile.GetFileHeader();
	pOH = peFile.GetOptionalHeader();
	pSH = peFile.GetFirstSectionHeader();	

	for(int i=0;i<pFH->NumberOfSections;i++)
	{
		//����ξ��п�ִ��������˵���Ǵ����
		if((pSH->Characteristics & IMAGE_SCN_MEM_EXECUTE) == IMAGE_SCN_MEM_EXECUTE)
		{
			unsigned char *pOpCode = (unsigned char*)(pSH->PointerToRawData + (unsigned char*)peFile.m_stMapFile.ImageBase);
			unsigned int ui_section_image_base = pOH->ImageBase + pSH->VirtualAddress; //���ݱ����ص��ڴ�ʱ�ĵ�ַ
			//�����ַ�ڱ�����
			if((pFunAddr >= (DWORD)ui_section_image_base) && (pFunAddr < (DWORD)ui_section_image_base+pSH->SizeOfRawData))
			{
				unsigned int uiOffset = (unsigned int)pFunAddr - (unsigned int)pOH->ImageBase - (unsigned int)pSH->VirtualAddress;
				unsigned char* puchFuncData = pOpCode + uiOffset;
				//�������תָ��
				if((puchFuncData[0] == 0xFF) && (puchFuncData[1] == 0x25))
				{
					DWORD ddAddr = *((PDWORD)(puchFuncData+2));
					return ddAddr;
				}
			}
		}

		pSH++;
	}

	return pFunAddr;
}

int DoasmPeFile(char* pchPeFile,char* pchLanguageFile,char* pchDoasmFile)
{
	int nErrorCode = 0;

	if(!FileExist(pchPeFile,false))
	{		
		nErrorCode = DOASM_MSG_PE_FILE_NOT_EXIST;
		printf(GetDoasmMessageInfo(nErrorCode),pchPeFile);

		return -nErrorCode;
	}

	DWORD dwBinType = 0;
	//�ж��Ƿ�Ϊ32λ��ִ���ļ�
	if((!GetBinaryType(pchPeFile,&dwBinType)) || (dwBinType != SCS_32BIT_BINARY))
	{
		nErrorCode = DOASM_MSG_PE_FILE_INVALID;
		printf(GetDoasmMessageInfo(nErrorCode),pchPeFile);

		return -nErrorCode;
	}

	CPeFile peFile;
	peFile.SetFileName(pchPeFile);
	if(!peFile.LoadFile())//����PE�ļ�
	{
		nErrorCode = DOASM_MSG_LOAD_PE_FILE_FAILD;
		printf(GetDoasmMessageInfo(nErrorCode),pchPeFile);

		return -nErrorCode;
	}

	//���������ļ�
	nErrorCode = doi_LoadLanguageFile(pchLanguageFile);
	if(nErrorCode < 0)
	{
		printf(GetDoasmMessageInfo(-nErrorCode),pchLanguageFile);

		return nErrorCode;
	}	

	PIMAGE_FILE_HEADER      pFH=NULL;
	PIMAGE_SECTION_HEADER   pSH=NULL;
	PIMAGE_OPTIONAL_HEADER  pOH=NULL;

	pFH = peFile.GetFileHeader();
	pOH = peFile.GetOptionalHeader();
	pSH = peFile.GetFirstSectionHeader();	

	/* ���ı���ʽ�򿪷��������ɵ��ļ� */
	FILE *stream;	
	if((stream = fopen(pchDoasmFile,"w+t")) == NULL)
	{		
		nErrorCode = DOASM_MSG_OPEN_DOASM_FILE_FAILD;
		printf(GetDoasmMessageInfo(nErrorCode),pchDoasmFile);

		return -nErrorCode;
	}

	char chDoasmData[1024];

	//���PE�ļ���
	sprintf(chDoasmData,GetDoasmMessageInfo(DOASM_MSG_DOASM_FILE_INFO),pchPeFile,pOH->ImageBase,pOH->ImageBase+pOH->AddressOfEntryPoint);
	fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);

	//�������Ϣ
	sprintf(chDoasmData,GetDoasmMessageInfo(DOASM_MSG_SEGMENT_INFO_TITLE),pFH->NumberOfSections);
	fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);
	PIMAGE_SECTION_HEADER   pSHTemp = pSH;
	for(int i=0;i<pFH->NumberOfSections;i++)
	{	
		sprintf(chDoasmData,GetDoasmMessageInfo(DOASM_MSG_SEGMENT_NAME),pSHTemp->Name);		
		int nNameLength = 8-strlen((char*)pSHTemp->Name);
		for(int j=0;j<nNameLength;++j)
		{
			//�������ո�
			strcat(chDoasmData," ");
		}
		fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);

		sprintf(chDoasmData,GetDoasmMessageInfo(DOASM_MSG_SEGMENT_INFO),
			pSHTemp->VirtualAddress,pSHTemp->PointerToRawData,pSHTemp->SizeOfRawData,pSHTemp->Characteristics);
		fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);

		pSHTemp ++;
	}

	bool bHasExecuteSection = false; //�ж��Ƿ��п�ִ�жα�ʶ
	for(int i=0;i<pFH->NumberOfSections;i++)
	{
		//����ξ��п�ִ��������˵���Ǵ����
		if((pSH->Characteristics & IMAGE_SCN_MEM_EXECUTE) == IMAGE_SCN_MEM_EXECUTE)
		{
			bHasExecuteSection = true;

			sprintf(chDoasmData,GetDoasmMessageInfo(DOASM_MSG_CODE_SEGMENT),pSH->Name,pSH->PointerToRawData,pSH->SizeOfRawData);
			fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);

			unsigned char *pOpCode = (unsigned char*)(pSH->PointerToRawData + (unsigned char*)peFile.m_stMapFile.ImageBase);
			unsigned int ui_section_image_base = pOH->ImageBase + pSH->VirtualAddress; //���ݱ����ص��ڴ�ʱ�ĵ�ַ
			unsigned int ui_code_length = pSH->SizeOfRawData;

			doi_DoasmInit(pOpCode,ui_code_length,ui_section_image_base);
			while(!doi_isEnd())
			{
				unsigned int ui_cur_pos = doi_GetDoasmDataCurPos();
				unsigned int ui_leave_length = ui_code_length - ui_cur_pos;//���µ����ݳ���
				unsigned char* pch_cur_data = pOpCode + ui_cur_pos;
				if(ui_leave_length >= 8)
				{
					//�ж����µ������Ƿ�ȫΪ0
					bool bIsAllZero = true;					
					for(unsigned int i=0;i<ui_leave_length;++i)
					{
						if(pch_cur_data[i] != 0x00)
						{
							bIsAllZero = false;
							break;
						}
					}
					//������µ�����ȫ��0
					if(bIsAllZero)
					{						
						//ȫ0���ݿ�ʼ�ָ���
						strcpy(chDoasmData,"\n");
						fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);

						unsigned int ui_insns_pos = ui_section_image_base + ui_cur_pos;						
						while(true)
						{
							char chText[50];

							chDoasmData[0] = 0;
							//����λ��
							sprintf(chText,"%08X    ",ui_insns_pos);
							strcat(chDoasmData,chText);

							if(ui_leave_length >= 8)
							{
								for(int j=0;j<DOASM_INSNS_TO_TEXT_LENGTH/2;++j)
								{
									if(j<8)
									{
										//�������
										sprintf(chText,"%02X",pch_cur_data[j]);										
										strcat(chDoasmData,chText);
									}
									else
									{
										//�������ո�
										strcat(chDoasmData,"  ");
									}									
								}								
								strcat(chDoasmData,GetDoasmMessageInfo(DOASM_MSG_ALL_ZERO_DATA));
								fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);

								ui_insns_pos += 8;
								pch_cur_data += 8;
								ui_leave_length -= 8;
							}
							else
							{
								if(ui_leave_length > 0)
								{
									for(unsigned int j=0;j<DOASM_INSNS_TO_TEXT_LENGTH/2;++j)
									{
										if(j<ui_leave_length)
										{
											//�������
											sprintf(chText,"%02X",pch_cur_data[j]);
											strcat(chDoasmData,chText);
										}
										else
										{
											//�������ո�
											strcat(chDoasmData,"  ");
										}										
									}
									strcat(chDoasmData,GetDoasmMessageInfo(DOASM_MSG_ALL_ZERO_DATA));
									fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);
								}								

								break;
							}
						}

						break;
					}
				}

				if(ui_leave_length > 3)
				{
					//�����  
					//55     ѹջ ��ַ32
					//8BEC   ��ַ32 = ջַ32
					//����Ϊ�Ǻ�����ʼ
					if((pch_cur_data[0] == 0x55) && (pch_cur_data[1] == 0x8B) && (pch_cur_data[2] == 0xEC))
					{
						//������ʼ�ָ�����
						strcpy(chDoasmData,"\n");
						fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);
					}
				}

				//������ڵ�ַ
				if(pOH->AddressOfEntryPoint == (pSH->VirtualAddress + ui_cur_pos))
				{
					strcpy(chDoasmData,GetDoasmMessageInfo(DOASM_MSG_ENTRY_POINT));
					fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);
				}

				//�����ָ��
				doi_DoasmData(chDoasmData);

				unsigned int unExternAddr;
				int nExternAddrType;
				doi_GetDoasmExternAddr(unExternAddr,nExternAddrType);
				//����е�ַ
				if(unExternAddr)
				{
					DWORD pFunAddr = (DWORD)unExternAddr;

					//��������ַ
					if(nExternAddrType == 1)
					{	
						pFunAddr = GetFunctionRealAddr(peFile,pFunAddr);
					}
					////ֻ��ƫ�������ڴ��ַ
					//else if(nExternAddrType == 2)
					//{

					//}
					
					//��ȡ������ַ
					char chFunctionName[512];
					if(GetFunctionNameByAddr(peFile,pFunAddr,chFunctionName,512))
					{		
						strcat(chDoasmData,"  ");
						if(nExternAddrType == 2)//ֻ��ƫ�������ڴ��ַ
						{
							strcat(chDoasmData,"//");
						}
						strcat(chDoasmData,chFunctionName);
					}

					//���������ַ
					doi_SetDoasmExternAddr(0,0);
				}
								
				strcat(chDoasmData,"\n");
				fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);
			}
		}		

		pSH++;
	}

	//û�п�ִ�ж�
	if(bHasExecuteSection == false)
	{
		sprintf(chDoasmData,GetDoasmMessageInfo(DOASM_MSG_NO_EXECUTE_SEGMENT));		
		fwrite(chDoasmData,sizeof(char),strlen(chDoasmData),stream);
	}

	fclose(stream);

	peFile.UnLoadFile();

	return 0;
}