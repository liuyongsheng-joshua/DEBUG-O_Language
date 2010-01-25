
#include "stdafx.h"
#include "OCodeBuild.h"
#include "RunCommand.h"

bool COCodeBuild::OML_BuildCode(const CString& strOMLPath,const CString& strSourceFileName,const CString& strLanguageFileName,CString& strObjFileName,bool bIsDebug)
{
	return OASM_BuildCode(strOMLPath,strSourceFileName,strLanguageFileName,strObjFileName,bIsDebug);
}

bool COCodeBuild::OASM_BuildCode(const CString& strOASMPath,const CString& strSourceFileName,const CString& strLanguageFileName,CString& strObjFileName,bool bIsDebug)
{	
	//������
	if(strOASMPath.IsEmpty())
	{
		MainWndOutputMsg(_T("δָ��������·��\n"));
		return false;
	}

	//�жϻ�����Ƿ����
	if(!FileExist(strOASMPath))
	{
		MainWndOutputMsg(_T("������ \"%s\" ������\n"),strOASMPath);
		return false;
	}
	CString strOASMTempPath;
	strOASMTempPath = GetShortPath(strOASMPath);

	if(strObjFileName.IsEmpty())
	{
		int nDotPos = strSourceFileName.ReverseFind(_T('.'));
		strObjFileName = (nDotPos<0)?strSourceFileName:strSourceFileName.Left(nDotPos);		
		strObjFileName += _T(".obj");
	}	

	//ɾ��ԭ�е�Ŀ���ļ�
	DeleteFile(strObjFileName);

	//��ϲ���
	CString strParam,strTemp;

	//����Դ�ļ�
	strParam += _T(" --in-source-file ");
	strTemp = strSourceFileName;
	AddPathSYH(strTemp);
	strParam += strTemp;

	//���������ļ�
	strParam += _T(" --in-language-file ");
	strTemp = strLanguageFileName;
	AddPathSYH(strTemp);
	strParam += strTemp;

	//����Ŀ���ļ�
	if(!strObjFileName.IsEmpty())
	{
		strParam += _T(" --out-obj-file ");
		strTemp = strObjFileName;
		AddPathSYH(strTemp);
		strParam += strTemp;
	}	

	//����ǵ��԰汾
	if(bIsDebug)
	{
		strParam += _T(" --debug");
	}

	TCHAR cmdLine[MAX_COMMAND_LINE];
	memset(cmdLine,0,MAX_COMMAND_LINE);
	wsprintf(cmdLine,_T("%s %s"),strOASMTempPath,strParam);

	DWORD ddResult = RunCommand(cmdLine,RCT_BUILD_CODE);
	
	//���û������Ŀ���ļ��������󷵻�
	if(!FileExist(strObjFileName))
	{
		return false;
	}

	return (ddResult==0);
}

//����Ŀ���ļ�
bool COCodeBuild::LinkObjFile(const CString& strLinkerPath,const CString& strObjFile,CString& strExeFileName,const CString& strOtherLinkParam,bool bIsDLL)
{
	//�ж�������
	if(strLinkerPath.IsEmpty())
	{
		MainWndOutputMsg(_T("δָ��������·��\n"));
		return false;
	}

	//�ж��������Ƿ����
	if(!FileExist(strLinkerPath))
	{
		MainWndOutputMsg(_T("������ \"%s\" ������\n"),strLinkerPath);
		return false;
	}
	CString strLinkerTempPath;
	strLinkerTempPath = GetShortPath(strLinkerPath);

	//�ж�Ҫ���ӵ�Ŀ���ļ��Ƿ����
	if(!FileExist(strObjFile))
	{
		MainWndOutputMsg(_T("Ŀ���ļ� \"%s\" ������\n"),strObjFile);
		return false;
	}

	CString strOtherLinkParamTemp;
	//���������DLL�ļ������DLL���Ӳ���
	if(bIsDLL)
	{ 
		strOtherLinkParamTemp += _T(" /DLL");
		//��ȡ.def�ļ�·��
		CString strDefFile = strObjFile;
		strDefFile = GetTitleFromPathName(strDefFile);
		strDefFile += _T(".DEF");
		if(FileExist(strDefFile))
		{
			AddPathSYH(strDefFile);
			strOtherLinkParamTemp += _T(" /DEF:");
			strOtherLinkParamTemp += strDefFile;
		}

		//��������ִ���ļ�·��
		if(strExeFileName.IsEmpty())
		{	
			strExeFileName = strObjFile;
			strExeFileName = GetTitleFromPathName(strExeFileName);
			strExeFileName += _T(".dll");
		}
	}
	else
	{
		//��������ִ���ļ�·��
		if(strExeFileName.IsEmpty())
		{			
			strExeFileName = strObjFile;
			strExeFileName = GetTitleFromPathName(strExeFileName);
			strExeFileName += _T(".exe");
		}
	}

	strOtherLinkParamTemp += strOtherLinkParam;	

	//ɾ��ԭ�е�EXE�ļ�
	if(!DeleteFile(strExeFileName))
	{
		DWORD ddError = GetLastError();
		//����Ǿܾ�����
		if(ddError == 5)
		{
			MainWndOutputMsg(_T("%s �ļ��ܾ�д��\n"),strExeFileName);
			return false;
		}
	}

	CString strTempObjFile,strTempResource,strTempExeFileName;

	//Ŀ���ļ�·��
	//strTempObjFile = strObjFile;
	//AddPathSYH(strTempObjFile);
	strTempObjFile = GetShortPath(strObjFile);

	//��Դ�ļ�·��
	strTempResource = strObjFile;
	strTempResource = GetTitleFromPathName(strTempResource);
	strTempResource += _T(".RES");

	if(!FileExist(strTempResource))
	{
		strTempResource.Empty();
	}
	else
	{
		AddPathSYH(strTempResource);
		//strTempResource = GetShortPath(strTempResource);		
	}

	//���ִ���ļ�·��
	strTempExeFileName = strExeFileName;
	AddPathSYH(strTempExeFileName);
	//strTempExeFileName = GetShortPath(strExeFileName);

	int nLength = 10 + strLinkerTempPath.GetLength() + strTempObjFile.GetLength() + 
		strTempResource.GetLength() + strTempExeFileName.GetLength() + strOtherLinkParamTemp.GetLength();

	if(nLength > MAX_COMMAND_LINE)
	{
		MainWndOutputMsg(_T("���Ӳ���̫������������Ӳ���\n"));
		return false;
	}

	MainWndOutputMsg(_T("�������� %s Ŀ���ļ�...\n"),strObjFile);

	TCHAR cmdLine[MAX_COMMAND_LINE];
	wsprintf(cmdLine,_T("%s %s %s /OUT:%s %s"),strLinkerTempPath,strTempObjFile,strTempResource,strTempExeFileName,strOtherLinkParamTemp); 

	RunCommand(cmdLine,RCT_LINK_OBJ);
	
	//�ж�ִ���ļ��Ƿ����
	if(!FileExist(strExeFileName))
	{	
		strExeFileName.Empty();

		MainWndOutputMsg(_T("��������ʧ��\n"));
		return false;
	}

	MainWndOutputMsg(_T("���� %s ִ���ļ�\n"),strExeFileName);

	return true;
}

void COCodeBuild::GetObjAndResFile(const CString& strDir,CString& strObj,CString& strRes)
{
	CFileFind ff;
	CString szDir = strDir;

	if (szDir.Right(1) != _T("\\"))
	{
		szDir += _T("\\");
	}
	szDir += _T("*.*");

	bool bResult = false;
	BOOL res = ff.FindFile(szDir);
	while (res)
	{
		res = ff.FindNextFile();
		if (ff.IsDots() || ff.IsDirectory())continue;

		//�������ļ�
		CString strFilePath = ff.GetFilePath();
		CString strFileName = ff.GetFileName();
		CString strExternName = strFileName;
		int nPos = strExternName.ReverseFind(_T('.'));
		if (nPos < 0)continue;

		strExternName = strExternName.Right(strExternName.GetLength()-nPos-1);
		strExternName.MakeLower();
		//Ŀ���ļ�
		if(strExternName == _T("obj"))
		{
			strObj += strFileName;
			strObj += _T(' ');
		}
		//��Դ�ļ�
		else if(strExternName == _T("res"))
		{	
			strRes += strFileName;
			strRes += _T(' ');
		}
	}

	ff.Close();	
}

//����Ŀ��·��
bool COCodeBuild::LinkObjPath(const CString& strLinkerPath,const CString& strObjPath,CString& strExeFileName,const CString& strOtherLinkParam,bool bIsDLL,LPCTSTR pstrDefFileName)
{
	//����ļ�������Ϊ��
	ASSERT(!strExeFileName.IsEmpty());

	//�ж�������
	if(strLinkerPath.IsEmpty())
	{
		MainWndOutputMsg(_T("δָ��������·��\n"));
		return false;
	}

	//�ж��������Ƿ����
	if(!FileExist(strLinkerPath))
	{
		MainWndOutputMsg(_T("������ \"%s\" ������\n"),strLinkerPath);
		return false;
	}
	CString strLinkerTempPath;
	strLinkerTempPath = GetShortPath(strLinkerPath);

	//�ж�Ҫ���ӵ�Ŀ��Ŀ¼�Ƿ����
	CString strObjPathTemp = strObjPath;
	if(strObjPathTemp.Right(1) == _T("\\"))
	{
		strObjPathTemp.Delete(strObjPathTemp.GetLength()-1);
	}
	if(!FileExist(strObjPathTemp,true))
	{
		MainWndOutputMsg(_T("Ŀ¼ \"%s\" ������\n"),strObjPathTemp);
		return false;
	}

	CString strOtherLinkParamTemp;
	//���������DLL�ļ������DLL���Ӳ���
	if(bIsDLL)
	{ 
		strOtherLinkParamTemp += _T(" /DLL");

		CString strDefFileList = pstrDefFileName;
		CString strDefFile;
		while(!strDefFileList.IsEmpty())
		{
			int nPos = strDefFileList.Find(_T('\n')); //���def�ļ��ûس����ָ�
			strDefFile = strDefFileList.Left(nPos);

			AddPathSYH(strDefFile);
			strOtherLinkParamTemp += _T(" /DEF:");
			strOtherLinkParamTemp += strDefFile;
			
			strDefFileList = strDefFileList.Right(strDefFileList.GetLength()-nPos-1);
		}		
	}

	strOtherLinkParamTemp += strOtherLinkParam;	

	//ɾ��ԭ�е�EXE�ļ�
	if(!DeleteFile(strExeFileName))
	{
		DWORD ddError = GetLastError();
		//����Ǿܾ�����
		if(ddError == 5)
		{
			MainWndOutputMsg(_T("%s �ļ��ܾ�д��\n"),strExeFileName);
			return false;
		}
	}

	CString strTempExeFileName;
	//���ִ���ļ�·��
	strTempExeFileName = strExeFileName;
	AddPathSYH(strTempExeFileName);
	//strTempExeFileName = GetShortPath(strExeFileName);

	CString strObjFile,strResFile;
	GetObjAndResFile(strObjPath,strObjFile,strResFile);

	int nLength = 8 + strLinkerTempPath.GetLength() + strObjFile.GetLength() + strResFile.GetLength() +
		strTempExeFileName.GetLength() + strOtherLinkParamTemp.GetLength();

	if(nLength > MAX_COMMAND_LINE)
	{
		MainWndOutputMsg(_T("���Ӳ���̫������������Ӳ���\n"));
		return false;
	}

	MainWndOutputMsg(_T("��������...\n"));

	::SetCurrentDirectory(strObjPath);
	TCHAR cmdLine[MAX_COMMAND_LINE];
	wsprintf(cmdLine,_T("%s %s %s /OUT:%s %s"),strLinkerTempPath,strObjFile,strResFile,strTempExeFileName,strOtherLinkParamTemp); 
	RunCommand(cmdLine,RCT_LINK_OBJ);

	//�ж�ִ���ļ��Ƿ����
	if(!FileExist(strExeFileName))
	{	
		strExeFileName.Empty();

		MainWndOutputMsg(_T("��������ʧ��\n"));
		return false;
	}

	//MainWndOutputMsg(_T("���� %s ִ���ļ�\n"),strExeFileName);

	return true;
}

//������Դ�ļ�
bool COCodeBuild::CompileResourceFile(const CString& strRcExePath,const CString& strResourceFile,LPCTSTR pstrOutputResFileName)
{
	//�����ж�Ҫ�������Դ�ļ��Ƿ����
	if(!FileExist(strResourceFile))
	{
		MainWndOutputMsg(_T("û�� %s ��Դ�ļ���������Դ����\n"),strResourceFile);
		return false;
	}

	//��Դ������·��
	if(strRcExePath.IsEmpty())
	{
		MainWndOutputMsg(_T("δָ����Դ������·��\n"));
		return false;
	}

	//��Դ�������Ƿ����
	if(!FileExist(strRcExePath))
	{
		MainWndOutputMsg(_T("��Դ������ \"%s\" ������\n"),strRcExePath);
		return false;
	}
	CString strRcExeTempPath;
	strRcExeTempPath = GetShortPath(strRcExePath);	

	//MainWndOutputMsg(_T("���ڱ��� %s ��Դ�ļ�...\n"),strResourceFile);

	CString strResourceTempFile;
	strResourceTempFile = strResourceFile;
	AddPathSYH(strResourceTempFile);
	//strResourceTempFile = GetShortPath(strResourceFile);	

	CString strOutputResFileName = pstrOutputResFileName;

	TCHAR cmdLine[MAX_COMMAND_LINE];
	if(strOutputResFileName.IsEmpty())
	{
		strOutputResFileName = GetTitleFromPathName(strResourceFile);
		strOutputResFileName += _T(".res");
	}

	::DeleteFile(strOutputResFileName);

	CString strOutputResFileNameTemp = strOutputResFileName;
	AddPathSYH(strOutputResFileNameTemp);
	wsprintf(cmdLine,_T("%s -convert %s %s"),strRcExeTempPath,strResourceTempFile,strOutputResFileNameTemp);
		
	RunCommand(cmdLine,RCT_COMPILE_RES);
	
	//�ж��Ƿ�������Դ�ļ�
	if(!FileExist(strOutputResFileName))
	{
		MainWndOutputMsg(_T("���� %s ��Դ�ļ�ʧ��\n"),strOutputResFileName);
		return false;
	}

	//MainWndOutputMsg(_T("���� %s ��Դ�ļ�\n"),strOutputResFileName);	

	return true;
}

