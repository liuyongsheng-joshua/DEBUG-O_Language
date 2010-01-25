
#include "stdafx.h"
#include "Global.h"

//bool FileExist(const TCHAR* pchFileName,bool bDirectory)
//
//  Ŀ��: �ж��ļ��Ƿ����
//
//  ע��: ʹ��ATL�ַ�����Ϊ��������Ҫ�жϵ��ļ���
//        ͨ�������ļ������ж��ļ��Ƿ����
//        �˺���ͬʱ�����ж�Ŀ¼�Ƿ����
//        �ڶ�������bool bDirectoryΪtrueʱ�ж�ΪĿ¼
//        bool bDirectory����Ĭ��Ϊfalse
//
bool FileExist(const TCHAR* pchFileName,bool bDirectory)
{
	bool bExist = false;
	WIN32_FIND_DATA fd; 
	HANDLE hFind = FindFirstFile(pchFileName, &fd);

	do 
	{
		if (hFind == INVALID_HANDLE_VALUE) 
			break;

		//�ж�Ŀ¼
		if(bDirectory)
		{
			if(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				bExist = true;
			}

			break;
		}

		bExist = true;

	}while(false);
	

	FindClose(hFind);

	return bExist;
}

//�õ��ڶ����ļ�������һ��·�������·�����õ��Ľ�������ڵڶ���·����
bool GetRelativePath(const CString& strFirstFileName,CString& strSecondFileName)
{
	if(FileExist(strSecondFileName,true))
	{
		if(strSecondFileName.Right(1) != _T('\\'))
			strSecondFileName += _T('\\');
	}

	CString strLowFirstFileName = strFirstFileName;
	CString strLowSecondFileName =  strSecondFileName;
	strLowFirstFileName.MakeLower();
	strLowSecondFileName.MakeLower();

	int nPos = 0;
	CString strTemp=_T("");
	CString strSamePath=_T("");
	while(true)
	{	
		nPos = strLowSecondFileName.Find(_T('\\'));
		if(nPos < 0)
			break;

		strSamePath += strLowSecondFileName.Left(nPos+1);
		strLowSecondFileName = strLowSecondFileName.Right(strLowSecondFileName.GetLength()-nPos-1);
		if(strLowFirstFileName.Find(strSamePath) != 0)
			break;

		strTemp = strSamePath;
	}

	if(strTemp.IsEmpty())
		return false;

	CString strFirstFilePath = strLowFirstFileName.Left(strLowFirstFileName.ReverseFind(_T('\\'))+1);
	if(strTemp == strFirstFilePath)
	{
		nPos = strFirstFilePath.GetLength();
		strTemp = ".\\";
		strTemp += strSecondFileName.Right(strSecondFileName.GetLength()-nPos);
		strSecondFileName = strTemp;
		return true;
	}

	strSecondFileName = strSecondFileName.Right(strSecondFileName.GetLength()-strTemp.GetLength());
	strFirstFilePath = strFirstFilePath.Right(strFirstFilePath.GetLength()-strTemp.GetLength());
	strTemp.Empty();
	while(true)
	{
		nPos = strFirstFilePath.ReverseFind(_T('\\'));
		if(nPos < 0)
			break;

		strTemp += "..\\";
		strFirstFilePath = strFirstFilePath.Left(nPos);
	}

	strTemp += strSecondFileName;
	strSecondFileName = strTemp;

	return true;
}

//�õ��ڶ����ļ�������һ��·���ľ���·�����õ��Ľ�������ڵڶ���·����
bool GetAbsolutePath(const CString& strFirstFileName,CString& strSecondFileName)
{
	int nPos = strFirstFileName.ReverseFind(_T('\\'));
	if(nPos < 0)return false;

	CString strFirstFileNameTemp = strFirstFileName.Left(nPos);
	if(strSecondFileName.Left(2) == ".\\")
	{
		strSecondFileName = strSecondFileName.Right(strSecondFileName.GetLength()-1);
		strFirstFileNameTemp += strSecondFileName;
		strSecondFileName = strFirstFileNameTemp;
		return true;
	}

	if(strSecondFileName.Left(3) != "..\\")
		return false;

	while(strSecondFileName.Left(3) == "..\\")
	{
		nPos = strFirstFileNameTemp.ReverseFind(_T('\\'));
		if(nPos < 0)return false;
		strFirstFileNameTemp = strFirstFileNameTemp.Left(nPos);
		strSecondFileName = strSecondFileName.Right(strSecondFileName.GetLength()-3);		
	}

	strFirstFileNameTemp += _T('\\');
	strFirstFileNameTemp += strSecondFileName;
	strSecondFileName = strFirstFileNameTemp;

	return true;
}

bool IsRelativePath(const CString& strPath)
{
	if((strPath.Left(2) == _T(".\\")) || (strPath.Left(3) == _T("..\\")))
		return true;

	return false;
}

//CString GetTitleFromPathName(const CString& strPathName)
//{
//	CString strTemp = strPathName;
//
//	int index1 = strTemp.ReverseFind( _T('\\') );
//	int index2 = strTemp.ReverseFind( _T('.') );
//
//	if( index2 > -1 && index2 > index1 )
//		strTemp = strTemp.Left(index2);
//
//	return strTemp;
//}

CString GetPathFromPathName(const CString& strPathName)
{
	CString strTemp = strPathName;

	int index1 = strTemp.ReverseFind( _T('\\') );

	if( index1 > -1)
		strTemp = strTemp.Left(index1+1);

	return strTemp;
}

//�õ��ļ���չ��
CString GetFileExternName(const CString& strFileName)
{
	CString strFileExternName;
	int nPos = strFileName.ReverseFind(_T('.'));
	if(nPos >= 0)
	{
		strFileExternName = strFileName.Right(strFileName.GetLength()-nPos-1);
	}

	return strFileExternName;
}

CString GetFileNameFromPathName(const CString& strPathName,BOOL bContainExtendName)
{
	CString strTemp = strPathName;

	int index1 = strTemp.ReverseFind( _T('\\') );

	if( index1 > -1)
	{
		strTemp = strTemp.Right(strTemp.GetLength() - index1-1);

		//�����������չ��
		if(!bContainExtendName)
		{
			strTemp = strTemp.Left(strTemp.ReverseFind(_T('.')));
		}
	}

	return strTemp;
}

//�������Ŀ¼
void CreateDepthDirectory(const CString& strDirectory)
{
	//���Ŀ¼�Ѿ��������˳�
	if(FileExist(strDirectory,true))
		return;

	int nPos = strDirectory.Find(_T('\\'));
	
	CString strTemp;
	while(true)
	{
		nPos++;
		nPos = strDirectory.Find(_T('\\'),nPos);
		if(nPos < 0)break;

		strTemp = strDirectory.Left(nPos);

		if(!FileExist(strTemp,true))
		{
			if(!CreateDirectory(strTemp,NULL))
			{
				break;
			}
		}
	}
}

bool FileRename(const TCHAR* pchOldName, const TCHAR* pchNewName)
{
	try
	{
		CFile::Rename(pchOldName, pchNewName);
	}
	catch(CFileException* pEx )
	{
		CString strMsg;
		strMsg.Format(_T("�����ļ��� %s ʧ��"),pchOldName);
		AfxMessageBox(strMsg);
		//#ifdef _DEBUG
		//	afxDump << "�����ļ� " << pOldName << " ʧ��, cause = "
		//			<< e->m_cause << "\n";
		//#endif
		pEx->Delete();

		return false;
	}

	return true;
}

/***************ɾ���ļ�������վ��*******************
pszPath  : ��ɾ����ȫ·���ļ���
bDelete  : TRUE ɾ�������Ƶ�����վ��FALSE:�Ƶ�����վ
����    : TRUE ɾ���ɹ�     FALSE ɾ��ʧ��
/******************************************************/

BOOL DeleteFolderOrFile(LPCTSTR pszPath, BOOL bDelete/*=FALSE*/)
{
	SHFILEOPSTRUCT  shDelFile;
	memset(&shDelFile,0,sizeof(SHFILEOPSTRUCT));
	shDelFile.fFlags |= FOF_SILENT;      // ����ʾ����
	shDelFile.fFlags |= FOF_NOERRORUI;     //�����������Ϣ
	shDelFile.fFlags |= FOF_NOCONFIRMATION;    //ֱ��ɾ����������ȷ��
	// ����·����һ����˫NULL������string������
	TCHAR buf[_MAX_PATH + 1];
	_tcscpy(buf, pszPath);   // ����·��
	buf[_tcslen(buf)+1]=0;   // ��ĩβ������NULL

	// ����SHFILEOPSTRUCT�Ĳ���Ϊɾ����׼��
	shDelFile.wFunc = FO_DELETE;       // ִ�еĲ���
	shDelFile.pFrom = buf;         // �����Ķ���Ҳ����Ŀ¼
	shDelFile.pTo = NULL;          // ��������ΪNULL
	if (bDelete) //���ݴ��ݵ�bDelete����ȷ���Ƿ�ɾ��������վ
	{   
		shDelFile.fFlags &= ~FOF_ALLOWUNDO;    //ֱ��ɾ�������������վ
	}
	else
	{          
		shDelFile.fFlags |= FOF_ALLOWUNDO;    //ɾ��������վ
	}
	return SHFileOperation(&shDelFile);    //ɾ��
}

int CopyFloderOrFile(LPCTSTR lpszPathFrom,LPCTSTR lpszPathTo,BOOL bMove)
{
	SHFILEOPSTRUCT FileOp;
	FileOp.fFlags = FOF_SILENT /*| FOF_NOCONFIRMATION | FOF_NOCONFIRMMKDIR*/;
	FileOp.hNameMappings = NULL;
	FileOp.hwnd = NULL;
	FileOp.lpszProgressTitle = NULL;
	FileOp.pFrom = lpszPathFrom;
	FileOp.pTo = lpszPathTo;	
	FileOp.wFunc = bMove?FO_MOVE:FO_COPY;	
	return SHFileOperation(&FileOp);
}

//   ������ϵͳ�İ汾��  
//   �汾���޷�ȷ��   0  
//   Windows   98   =   1  
//   Windows   98   SE   =   2  
//   Windows   Me   =   3  
//   Windows   NT   =   4  
//   Windows   2000   =   5  
//   Windows   XP/.Net   Server   =   6  
int  GetOSVersion(void)  
{  
	OSVERSIONINFO   osver;  
	osver.dwOSVersionInfoSize   =   sizeof(OSVERSIONINFO);  
	GetVersionEx(&osver);  
	int nOSVersion   =   0;  
	if   (osver.dwPlatformId   ==   VER_PLATFORM_WIN32_WINDOWS)  
	{  
		//   ����ϵͳ�İ汾��   Windows   95,   Windows   98,Windows   98   SE   or   Windows   Me.  
		if   (osver.dwMinorVersion   ==   10)  
		{  
			if   ((osver.dwBuildNumber   &   0xFFFF)   ==   1998)  
			{  
				//   ����ϵͳ�İ汾��   Windows   98  
				nOSVersion   =   1;  
			}  
			else  
			{  
				if   ((osver.dwBuildNumber   &   0xFFFF)   ==   2222)  
				{  
					//   ����ϵͳ�İ汾��   Windows   98   SE  
					nOSVersion   =   2;  
				}  
			}  
		}  
		else  
		{  
			if   ((osver.dwMinorVersion   ==   90)   &&   ((osver.dwBuildNumber   &   0xFFFF)   ==   3000))  
			{  
				//   ����ϵͳ�İ汾��   Windows   Me  
				nOSVersion   =   3;  
			}  
		}  
	}  
	else  
	{  
		if   (osver.dwPlatformId   ==   VER_PLATFORM_WIN32_NT)  
		{  
			//   ����ϵͳ�İ汾��   Windows   NT   3.51,   Windows   NT   4.0,   Windows   2000,   Windows   XP,   or   Windows   .NET   Server.  
			if   (osver.dwMajorVersion   <=   4)  
			{  
				//   ����ϵͳ�İ汾��   Windows   NT  
				nOSVersion   =   4;  
			}  
			else  
			{  
				if   (osver.dwMinorVersion   ==   0)  
				{  
					//   ����ϵͳ�İ汾��   Windows   2000  
					nOSVersion   =   5;  
				}  
				else  
				{  
					//   ����ϵͳ�İ汾��   Windows   XP  
					nOSVersion   =   6;  
				}  
			}  
		}  
	}  

	return nOSVersion;
}   

