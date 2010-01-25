#include "StdAfx.h"
#include ".\buildproject.h"
#include ".\olinterface.h"

#include "..\MainFrm.h"
#include "..\OLVisualStudioGlobal.h"

#define MAX_COMMAND_LINE 1024 //��������󳤶�

void OutPutMessage(LPCTSTR lpText)
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	if(pMainFrame->GetSafeHwnd())
	{
		pMainFrame->OutPutMessage(lpText);
	}
}

CString& GetAppPathName()
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	ASSERT(pMainFrame->GetSafeHwnd());

	return pMainFrame->GetAppPathName();
}

//ִ��CMD����
void RunCommand(char* pchCmdLine,const CString& strMsgFileName,bool bHideWnd)
{
	//����ض�������ļ���Ϊ����Ĭ�Ϸ�ʽ���������̨
	bool bOutputToFile = false;
	if(!strMsgFileName.IsEmpty())
	{
		bOutputToFile = true;
	}

	SECURITY_ATTRIBUTES sa={sizeof(sa),NULL,TRUE};
	SECURITY_ATTRIBUTES *psa=NULL;
	DWORD dwShareMode=FILE_SHARE_READ|FILE_SHARE_WRITE; 
	OSVERSIONINFO osVersion={0};
	osVersion.dwOSVersionInfoSize =sizeof(osVersion);
	if(GetVersionEx(&osVersion))
	{
		//���ݰ汾���ù���ģʽ�Ͱ�ȫ���� 
		if(osVersion.dwPlatformId >= VER_PLATFORM_WIN32_NT)
		{ 
			psa=&sa; 
			dwShareMode|=FILE_SHARE_DELETE;
		}
	}

	STARTUPINFO s={sizeof(s)}; 

	HANDLE hConsoleRedirect = NULL;
	if(bOutputToFile)
	{
		//������ʱ�ļ�
		hConsoleRedirect=CreateFile( 
			strMsgFileName, 
			GENERIC_WRITE, 
			dwShareMode, 
			psa, 
			OPEN_ALWAYS, 
			FILE_ATTRIBUTE_NORMAL, 
			NULL); 
		assert(hConsoleRedirect!=INVALID_HANDLE_VALUE);

		SetEndOfFile(hConsoleRedirect);

		s.hStdOutput =hConsoleRedirect;//���ļ���Ϊ��׼������ 
	}

	//ʹ�ñ�׼������ʾ���� 
	s.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES; 

	//���ؿ���̨����
	if(bHideWnd)
	{
		s.wShowWindow =SW_HIDE; 
	}

	PROCESS_INFORMATION pi={0}; 
	//��������,ִ�г���
	if(CreateProcess(NULL,pchCmdLine,NULL,NULL,TRUE,NULL,NULL,NULL,&s,&pi))
	{ 
		//�ȴ�����ִ����� 
		WaitForSingleObject(pi.hProcess ,INFINITE); 

		//�رս��̺����߳̾�� 
		CloseHandle(pi.hProcess ); 
		CloseHandle(pi.hThread ); 
	}

	//�رտ���̨��������ļ���� 
	if(bOutputToFile)
	{
		CloseHandle(hConsoleRedirect);
	}	
}

//����Ŀ���������obj�ļ�
void BuildAsmToObjectCode(const CString& strAsmFileName,int nAssemblerType)
{
	//�����MASM���
	if(nAssemblerType == OCT_MASM)
	{
		CString strBin,strAssemblerPathName,strIncludePath,strCmdOutPutFile;
		strBin = GetPathFromPathName(GetAppPathName());
		strBin += _T("bin\\MASM\\");
		strAssemblerPathName = strBin +  _T("ML.EXE");
		strIncludePath =  strBin +  _T("INCLUDE");

		//�õ�����ļ�·��
		CString strAssembleFilePath = GetPathFromPathName(strAsmFileName);
		strCmdOutPutFile = strAssembleFilePath + _T("~OLOUTPUT.TXT");

		CString strParam;
		strParam.Format("/Fo \"%s\\\" /coff /c /I \"%s\"",strAssembleFilePath,strIncludePath);

		char cmdLine[MAX_COMMAND_LINE];
		memset(cmdLine,0,MAX_COMMAND_LINE);
		wsprintf(cmdLine,"\"%s\" %s \"%s\"",strAssemblerPathName,strParam,strAsmFileName);

		//ɾ����ʱ�ļ�
		//DeleteFile(strTemp);

		RunCommand(cmdLine,strCmdOutPutFile,true);

		CStdioFile fileOutPut;
		CString strTemp;
		if(fileOutPut.Open(strCmdOutPutFile, CFile::modeRead | CFile::typeText))
		{
			while(fileOutPut.ReadString(strTemp))
			{
				//���˵������ʾ
				if(strTemp.Find(" Assembling: ") == 0)
					continue;

				OutPutMessage("\n");
				OutPutMessage(strTemp);
			}

			fileOutPut.Close();
		}

		return ;
	}

	//�����NASM���
	if(nAssemblerType == OCT_NASM)
	{
		CString strBin,strAssemblerPathName,strIncludePath,strCmdOutPutFile;
		strBin = GetPathFromPathName(GetAppPathName());
		strBin += _T("bin\\NASM\\");

		strAssemblerPathName = strBin +  _T("nasmw.exe"); //NASM����
		strIncludePath =  strBin +  _T("INCLUDE\\"); //�����ļ�·��
		strCmdOutPutFile = strBin + _T("~NLOUTPUT.TXT"); //��������ļ�

		//-f���������Ŀ���ļ�����
		//-i������·��
		//-E  ��������ļ�
		CString strTemp;
		strTemp.Format("-f obj -i \"%s\" -E \"%s\"",strIncludePath,strCmdOutPutFile);

		char cmdLine[MAX_COMMAND_LINE];
		memset(cmdLine,0,MAX_COMMAND_LINE);
		wsprintf(cmdLine,"%s %s %s",strAssemblerPathName,strTemp,strAsmFileName);

		//ɾ����ʱ�ļ�
		//DeleteFile(strTemp);

		RunCommand(cmdLine,strCmdOutPutFile,true);

		CStdioFile fileOutPut;
		if(fileOutPut.Open(strCmdOutPutFile, CFile::modeRead | CFile::typeText) ) 
		{
			while(fileOutPut.ReadString(strTemp))
			{
				OutPutMessage("\n");
				OutPutMessage(strTemp);
			}

			fileOutPut.Close();
		}

		return;
	}    

	//�����OASM���
	if(nAssemblerType == OCT_OASM)
	{
		return;
	}
}

void LinkObjectCode(const CString& strProjectFileName)
{
	//ͨ�������ļ����Ƶõ��������Խ��
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	ASSERT(pMainFrame->GetSafeHwnd());
	HTREEITEM hItemProject = pMainFrame->GetProjectItemFromProjectFileName(strProjectFileName);
	CProjectProperty* pProjectProperty = pMainFrame->GetProjectProperty(hItemProject);
	ASSERT(pProjectProperty);

	CString strOutPutFloder = pProjectProperty->GetProjectAbsolutePathOutPut();
	CString strProgramFileName = pProjectProperty->GetProjectAbsolutePathOutPutFileName();

	//�����MASM���
	if(pProjectProperty->m_nAssemblerType == OCT_MASM)
	{
		CString strParamFile = strOutPutFloder + "ol.olp";
				
		CString strBin,strLinkerPathName,strLibPath,strSubSystem;
		strBin = GetPathFromPathName(GetAppPathName());
		strBin += _T("bin\\MASM\\");
		strLinkerPathName = strBin +  _T("LINK.EXE");
		strLibPath = strBin + _T("LIB");

		if(pProjectProperty->m_nProgramType == CProjectProperty::PROGRAM_TYPE::PT_CONSOL)
		{
			strSubSystem = _T("CONSOLE");
		}
		else
		{
			strSubSystem = _T("WINDOWS");
		}

		CString strParam;
		strParam.Format("/SUBSYSTEM:%s /LIBPATH:\"%s\" /OUT:\"%s\" /NOLOGO",strSubSystem,strLibPath,strProgramFileName);
		
		//ɾ��ԭ�е�ִ���ļ�
		DeleteFile(strProgramFileName);

		//ִ����������
		char cmdLine[MAX_COMMAND_LINE];
		memset(cmdLine,0,MAX_COMMAND_LINE);
		wsprintf(cmdLine,"\"%s\" %s @\"%s\"",strLinkerPathName,strParam,strParamFile);

		CString strCmdOutPutFile = strOutPutFloder + _T("~OLOUTPUT.TXT");

		//ɾ����ʱ�ļ�
		//DeleteFile(strCmdOutPutFile);

		RunCommand(cmdLine,strCmdOutPutFile,true);

		////���ִ���ļ��������ʾ����ɹ�
		//FileExist(strProgramFileName);

		//���������Ϣ
		CStdioFile fileOutPut;
		if(fileOutPut.Open( strCmdOutPutFile, CFile::modeRead | CFile::typeText) ) 
		{
			while(fileOutPut.ReadString(strCmdOutPutFile))
			{
				OutPutMessage("\n");
				OutPutMessage(strCmdOutPutFile);
			}

			fileOutPut.Close();
		}
	}

	//�����NASM���
	if(pProjectProperty->m_nAssemblerType == OCT_NASM)
	{
		//return strProgramFileName;
	}

	//�����OASM���
	if(pProjectProperty->m_nAssemblerType == OCT_OASM)
	{
		//return strProgramFileName;
	}
}

void BuildCmdInterface(int nCmdType,const char* pchValue,int nValue)
{
	switch(nCmdType)
	{
		//����ı�
	case BICT_OUTPUT:
		OutPutMessage(pchValue);
		break;
		//�������
	case BICT_BUILD_CODE:
		BuildAsmToObjectCode(pchValue,nValue);
		break;
		//��������ִ���ļ�
	case BICT_LINK_EXE:
		LinkObjectCode(pchValue);
		break;
	default:
		break;
	}
}

CBuildProject::CBuildProject(void)
{
}

CBuildProject::~CBuildProject(void)
{
}

void CBuildProject::BuildProject(CProjectProperty* pProjectProperty)
{	
	CString strMessage;
	strMessage.Format("\n��ʼ���빤�̣�%s ...",pProjectProperty->m_strProjectName);
	OutPutMessage(strMessage);

	//�����������Ŀ¼
	CString strOutPutFloder = pProjectProperty->GetProjectAbsolutePathOutPut();
	CreateDepthDirectory(strOutPutFloder);

	//������������ļ�Ŀ¼
	CString strProgramFileName = pProjectProperty->GetProjectAbsolutePathOutPutFileName();
	CreateDepthDirectory(strProgramFileName);

	//���빤��
	Build(pProjectProperty->m_strProjectFilePath);

	////�����������д������������
	//if(CErrorTableOper::GetErrorCount() > 0)
	//{
	//	OutPutError();
	//}
	////�����������ɿ�ִ���ļ�
	//else
	//{
	//	strMessage.Format("\n��������Ŀ���ļ�...",strProgramFileName);
	//	OutPutMessage(strMessage);

	//	//����OBJ�ļ�����EXEִ���ļ�
	//	if(LinkObjectCode(strOutPutFloder,strProgramFileName,pProjectProperty))
	//	{
	//		strMessage.Format("\n���ɳ���%s",strProgramFileName);
	//		OutPutMessage(strMessage);
	//	}
	//	else
	//	{
	//		strMessage.Format("\n����ִ���ļ�ʧ��");
	//		OutPutMessage(strMessage);
	//	}
	//}	

	strMessage.Format("\n%s ���̱������",pProjectProperty->m_strProjectName);
	OutPutMessage(strMessage);
}

void CBuildProject::Build(const char* pchFileName)
{
	ASSERT(g_OLInterface.GetInterface());

	//���ó�Ա����
	BUILDPROJECT lpfnBuildProject = (BUILDPROJECT)GetProcAddress(g_OLInterface.GetInterface(),"InterfaceBuildProject");
	if(lpfnBuildProject == NULL)
		return ;

	lpfnBuildProject(pchFileName,BuildCmdInterface);
}

//#include "./errortableoper.h"
//
//void CBuildProject::OutPutError()
//{
//	CSysErrorAttr* pSysErrorAttr = NULL;
//	for(SYS_ERROR_POSITION posSysError = CErrorTableOper::GetFirstSysError();posSysError != CErrorTableOper::GetEndSysError();++posSysError)
//	{
//		CErrorInfo errorInfo;
//		CErrorTableOper::GetSysErrorAttr(posSysError,errorInfo);
//
//		CString strMessage;
//		if(errorInfo.m_strErrorSymbol.IsEmpty())
//		{ 
//			strMessage.Format(_T("\n%s : ������룺%d �������壺%s"),errorInfo.m_strErrorFileName,errorInfo.m_nErrorCode,errorInfo.m_strErrorCodeInfo);
//		}
//		else
//		{
//			strMessage.Format(_T("\n%s : ������룺%d ������ţ�%s �������壺%s" ),errorInfo.m_strErrorFileName,errorInfo.m_nErrorCode,errorInfo.m_strErrorSymbol,errorInfo.m_strErrorCodeInfo);
//		}
//
//		OutPutMessage(strMessage);
//	}
//}
//
//
