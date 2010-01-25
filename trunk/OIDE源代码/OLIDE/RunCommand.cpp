
#include "stdafx.h"
#include "RunCommand.h"
#include "MainFrm.h"
#include "./Common/Common.h"

#ifndef MainWndOutputMsg
#define MainWndOutputMsg ((CMainFrame*)AfxGetMainWnd())->OutPutMsg
#endif

CString GetTitleFromPathName(const CString& strPathName)
{
	CString strTemp = strPathName;

	int index1 = strTemp.ReverseFind( _T('\\') );
	int index2 = strTemp.ReverseFind( _T('.') );

	if( index2 > -1 && index2 > index1 )
		strTemp = strTemp.Left(index2);

	return strTemp;
}

CString GetShortPath(const CString& strLongFileName) //��������·����ת��Ϊ��·����
{ 
	TCHAR strBuffer[_MAX_PATH]; 

	GetShortPathName(strLongFileName,strBuffer,_MAX_PATH); 

	CString strTemp(strBuffer);

	return strTemp; 
} 

//ִ��CMD����
DWORD RunCommand(TCHAR* pchCmdLine,int nCommandType,bool bHideWnd)
{
	SECURITY_ATTRIBUTES sa;
	HANDLE hRead,hWrite;

	//�����ܵ�
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (!CreatePipe(&hRead,&hWrite,&sa,0)) 
	{
		return -1;
	} 

	//�����ӽ���
	STARTUPINFO si;
	PROCESS_INFORMATION pi; 
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si); 
	si.hStdError = hWrite;
	si.hStdOutput = hWrite;
	if(bHideWnd)si.wShowWindow = SW_HIDE; //���ش���
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	if (!CreateProcess(NULL,pchCmdLine,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi)) 
	{			
		return -1;
	}

	//�ر�д�ܵ����
	CloseHandle(hWrite);

	//��ȡ�ܵ�����ֱ���ӳ������
	char buffer[4097] = {0};
	DWORD bytesRead;
	CString strMessage;	
	while(true) 
	{
		//�ӳ�80����
		DelayNop(80);

		if((ReadFile(hRead,buffer,4096,&bytesRead,NULL) == NULL) || (bytesRead == 0))
			break;

		buffer[bytesRead] = 0;

#ifdef _UNICODE
		strMessage = buffer; //UNICODE�汾���Ǳ���ģ����Զ�ת���ɿ��ַ�
		MainWndOutputMsg(_T("%s"),strMessage);
#else
		MainWndOutputMsg(_T("%s"),buffer);
#endif
	}

	//��ó��򷵻�ֵ
	DWORD   dwExitCode = 0;
	GetExitCodeProcess(pi.hProcess,&dwExitCode);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return dwExitCode;
}

void RunProgramme(const CString& strProgrammeName)
{
	if(!FileExist(strProgrammeName))
	{
		MainWndOutputMsg(_T("��������ʧ�ܣ����� %s ������\n"),strProgrammeName);
		return ;
	}

	MainWndOutputMsg(_T("�������� %s ����\n"),strProgrammeName);

	STARTUPINFO si={sizeof(si)};
	si.dwFlags =STARTF_USESHOWWINDOW;
	si.wShowWindow = (unsigned short)SW_SHOW;
	PROCESS_INFORMATION pi={0};

	CreateProcess(strProgrammeName,NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

//���·��˫����
void AddPathSYH(CString& strPath)
{
	CString strTemp;
	strTemp = _T('"');
	strTemp += strPath;
	strTemp += _T('"');

	strPath = strTemp;
}

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