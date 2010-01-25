
#include "stdafx.h"
#include "Doasm.h"
#include "RunCommand.h"

bool CDoasm::DoDoasm(const CString& strDOASMPath,const CString& strPeFileName,const CString& strLanguageFileName,CString& strDoasmFileName)
{	
	//�жϻ����
	if(strDOASMPath.IsEmpty())
	{
		MainWndOutputMsg(_T("δָ���������·��\n"));
		return false;
	}

	//�жϻ�����Ƿ����
	if(!FileExist(strDOASMPath))
	{
		MainWndOutputMsg(_T("������� \"%s\" ������\n"),strDOASMPath);
		return false;
	}
	CString strDOASMTempPath;
	strDOASMTempPath = GetShortPath(strDOASMPath);

	if(strDoasmFileName.IsEmpty())
	{
		int nDotPos = strPeFileName.ReverseFind(_T('.'));
		strDoasmFileName = (nDotPos<0)?strPeFileName:strPeFileName.Left(nDotPos);		
		strDoasmFileName += _T(".doa");
	}	

	//ɾ��ԭ�е�Ŀ���ļ�
	DeleteFile(strDoasmFileName);

	//��ϲ���
	CString strParam,strTemp;

	//����Դ�ļ�
	strParam += _T(" --in-pe-file ");
	strTemp = strPeFileName;
	AddPathSYH(strTemp);
	strParam += strTemp;

	//���������ļ�
	strParam += _T(" --in-language-file ");
	strTemp = strLanguageFileName;
	AddPathSYH(strTemp);
	strParam += strTemp;

	//����Ŀ���ļ�
	if(!strDoasmFileName.IsEmpty())
	{
		strParam += _T(" --out-doasm-file ");
		strTemp = strDoasmFileName;
		AddPathSYH(strTemp);
		strParam += strTemp;
	}	

	TCHAR cmdLine[MAX_COMMAND_LINE];
	memset(cmdLine,0,MAX_COMMAND_LINE);
	wsprintf(cmdLine,_T("%s %s"),strDOASMTempPath,strParam);

	MainWndOutputMsg(_T("���ڷ���� \"%s\" �ļ�...\n"),strPeFileName);

	DWORD ddResult = RunCommand(cmdLine,RCT_DOASM);

	//���û������Ŀ���ļ��������󷵻�
	if(!FileExist(strDoasmFileName))
	{
		return false;
	}

	return (ddResult==0);
}