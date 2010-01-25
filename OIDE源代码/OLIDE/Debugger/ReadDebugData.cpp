
#include "stdafx.h"
#include "ReadDebugData.h"
#include "PeFile.h"

CReadDebugData::CReadDebugData()
{
	m_uiCodeSegmentAddr = 0;
	m_uiCodeSegmentLength = 0;
	m_uiDataSegmentAddr = 0;		
	m_uiDataSegmentLength = 0;
}

CReadDebugData::~CReadDebugData()
{

}

int CReadDebugData::SearchSourceFileNameList(const CString& str)
{
	for(int i=0;i<m_strarrSourceFileNameList.GetCount();++i)
	{
		if(m_strarrSourceFileNameList.GetAt(i) == str)
			return i;
	}

	return -1;
}

bool CReadDebugData::Read(TCHAR* pchPEFileName)
{
	DWORD dwBinType = 0;
	//�ж��Ƿ�Ϊ32λ��ִ���ļ�
	if((!GetBinaryType(pchPEFileName,&dwBinType)) || (dwBinType != SCS_32BIT_BINARY))
	{
		return false;
	}

	CPeFile peFile;
	peFile.SetFileName(pchPEFileName);
	if(!peFile.LoadFile())//����PE�ļ�
	{
		return false;
	}

	PIMAGE_FILE_HEADER      pFH=NULL;
	PIMAGE_SECTION_HEADER   pSH=NULL;
	PIMAGE_OPTIONAL_HEADER  pOH=NULL;

	pFH = peFile.GetFileHeader();
	pOH = peFile.GetOptionalHeader();
	pSH = peFile.GetFirstSectionHeader();	

	m_strarrSourceFileNameList.RemoveAll();
	m_debugDataItemLine.ClearList();

	bool bResult = false;
	for(int i=0;i<pFH->NumberOfSections;i++)
	{
		//����ξ��п�ִ��������˵���Ǵ����
		if((pSH->Characteristics & IMAGE_SCN_MEM_EXECUTE) == IMAGE_SCN_MEM_EXECUTE)
		{
			m_uiCodeSegmentAddr = pOH->ImageBase + pSH->VirtualAddress;
			m_uiCodeSegmentLength = pSH->SizeOfRawData;
		}
		//��������ݶ�
		else if(strcmp((char*)pSH->Name,".data") == 0)
		{
			m_uiDataSegmentAddr = pOH->ImageBase + pSH->VirtualAddress;
			m_uiDataSegmentLength = pSH->SizeOfRawData;
		}
		//����ǵ��Զ�
		else if(strcmp((char*)pSH->Name,".odebug") == 0)
		{
			unsigned char *pSectionData = (unsigned char*)(pSH->PointerToRawData + (unsigned char*)peFile.m_stMapFile.ImageBase);
			unsigned char *pSectionDataStart = pSectionData;

			//����ڵ��Զ����ݷ�Χ�����ʼ�������ֽ���"OD"��ʶ���ʾ�ǺϷ��ĵ�������
			while((pSectionData < pSectionDataStart+pSH->SizeOfRawData) && (pSectionData[0] == 'O') && (pSectionData[1] == 'D'))
			{
				pSectionData += 2;
				unsigned short usSourceFileNameCount = *(unsigned short*)pSectionData;
				pSectionData += sizeof(unsigned short);

				int* pIndexArray = new int[usSourceFileNameCount];
				if(pIndexArray)
				{
					//��ȡԴ�����ļ���
					CString strSourceFileName;
					for(unsigned short i=0;i<usSourceFileNameCount;++i)
					{
						strSourceFileName = (char*)pSectionData;

						pIndexArray[i] = SearchSourceFileNameList(strSourceFileName);
						if(pIndexArray[i] < 0)//û��������
						{
							m_strarrSourceFileNameList.Add(strSourceFileName);
							pIndexArray[i] = m_strarrSourceFileNameList.GetCount() - 1;
						}

						pSectionData += strlen((char*)pSectionData);
						pSectionData ++;
					}

					//��ȡ����������
					unsigned long usDebugItemCount = *(unsigned long*)pSectionData;
					pSectionData += sizeof(unsigned long);
					for(unsigned long i=0;i<usDebugItemCount;++i)
					{
						unsigned short usDebugItemType = *(unsigned short*)pSectionData;
						pSectionData += sizeof(unsigned short);
						switch(usDebugItemType)
						{
							//������
						case DEBUG_NODE_TYPE_LINE:
							{
								DEBUG_DATA_ITEM_LINE debug_data_item_line;
								debug_data_item_line.m_usFileIndex = *(unsigned short*)pSectionData;
								if( (debug_data_item_line.m_usFileIndex >= 0) && (debug_data_item_line.m_usFileIndex < usSourceFileNameCount))
								{
									debug_data_item_line.m_usFileIndex = pIndexArray[debug_data_item_line.m_usFileIndex];
									pSectionData += sizeof(unsigned short);
									debug_data_item_line.m_lLine = *(long*)pSectionData;
									debug_data_item_line.m_lLine --; //ʵ�ʵ��к���õ����кŲ�1
									pSectionData += sizeof(long);
									debug_data_item_line.m_ulAddr = *(unsigned long*)pSectionData;
									pSectionData += sizeof(unsigned long);

									m_debugDataItemLine.Add(debug_data_item_line);	
								}												

								break;
							}
						}
					}

					delete[] pIndexArray;
				}				
			}	

			bResult = true;
		}

		pSH++;
	}

	//peFile.UnLoadFile();

	return bResult;
}

DEBUG_DATA_ITEM_LINE* CReadDebugData::GetMatchLineItem(TCHAR* pchFileName,int nLine,bool bMatchLine)
{
	int nFileIndex = -1;
	for(int i=0;i<m_strarrSourceFileNameList.GetCount();++i)
	{
		if(m_strarrSourceFileNameList.GetAt(i) == pchFileName)
		{
			nFileIndex = i;
			break;
		}
	}
	if(nFileIndex < 0)
		return 0;

	for(m_debugDataItemLine.GetFirstElement();!m_debugDataItemLine.isEnd();m_debugDataItemLine.GetNextElement())
	{
		DEBUG_DATA_ITEM_LINE* p_debug_data_item_line = m_debugDataItemLine.GetCurDebugDataItemLine();
		//�ҵ���Ӧ����
		if((p_debug_data_item_line->m_usFileIndex == nFileIndex) && (p_debug_data_item_line->m_lLine == nLine))
		{
			return p_debug_data_item_line;
		}
	}

	//��ȷƥ����
	if(bMatchLine)
	{
		return  0;
	}

	//û���ҵ���Ӧ�����������������
	DEBUG_DATA_ITEM_LINE* p_debug_data_item_line_temp = 0;
	for(m_debugDataItemLine.GetFirstElement();!m_debugDataItemLine.isEnd();m_debugDataItemLine.GetNextElement())
	{
		DEBUG_DATA_ITEM_LINE* p_debug_data_item_line = m_debugDataItemLine.GetCurDebugDataItemLine();		
		if(p_debug_data_item_line->m_usFileIndex == nFileIndex)
		{
			if(p_debug_data_item_line->m_lLine > nLine)
			{
				if(p_debug_data_item_line_temp == 0)
				{
					p_debug_data_item_line_temp = p_debug_data_item_line;
				}
				else
				{
					if(p_debug_data_item_line->m_lLine < p_debug_data_item_line_temp->m_lLine)
					{
						p_debug_data_item_line_temp = p_debug_data_item_line;
					}
				}
			}
		}
	}

	return p_debug_data_item_line_temp;
}

DEBUG_DATA_ITEM_LINE* CReadDebugData::GetMatchAddrItem(unsigned long ulAddr)
{
	DEBUG_DATA_ITEM_LINE* p_debug_data_item_line = 0;
	for(m_debugDataItemLine.GetFirstElement();!m_debugDataItemLine.isEnd();m_debugDataItemLine.GetNextElement())
	{
		p_debug_data_item_line = m_debugDataItemLine.GetCurDebugDataItemLine();
		if(p_debug_data_item_line->m_ulAddr == ulAddr)
		{
			return p_debug_data_item_line;
		}
	}

	return 0;
}