// DOASM.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "DOASM.h"
#include "ParseCmdLine.h"
#include "DoasmPeFile.h"

int main(int argc, char* argv[])
{
	CCmdLineOption cmdLineOption;

	//�����н���
	CParseCmdLine parseCmdLine;
	if(parseCmdLine.parse_cmdline(argc,argv,cmdLineOption) <= 0) //С��0��ʾ�����д��󣬵���0��ʾ��������а�����Ϣ
	{
		//return -DOASM_MSG_COMMAND_LINE_ERROR;
		return -1;
	}

	////����ʱʹ��
	//parseCmdLine.parse_cmdline(argc,argv,cmdLineOption);
	////cmdLineOption.m_pchLanguageFile = "F:\\Myprogram\\OL\\OL\\release\\oasm\\language\\english.oic";
	//cmdLineOption.m_pchLanguageFile = "F:\\Myprogram\\OL\\OL\\release\\oasm\\language\\chinese.oic";
	//cmdLineOption.m_pchPeFile = "f:\\��һ�����ڳ���.exe";
	//if(cmdLineOption.m_pchDoasmFile == 0)cmdLineOption.get_default_doasm_file();

	int nRetCode = 0;

	//����DoasmDLL�������з����
	nRetCode = DoasmPeFile(cmdLineOption.m_pchPeFile,cmdLineOption.m_pchLanguageFile,cmdLineOption.m_pchDoasmFile);
	
	return nRetCode;
}

