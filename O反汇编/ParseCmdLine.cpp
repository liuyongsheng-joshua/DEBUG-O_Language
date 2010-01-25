
#include "ParseCmdLine.h"

CParseCmdLine::CParseCmdLine()
{
	m_pAnyOption = 0;
}

CParseCmdLine::~CParseCmdLine()
{
	if(m_pAnyOption)
	{
		delete m_pAnyOption;
		m_pAnyOption = 0;
	}
}

int CParseCmdLine::parse_cmdline(int argc, char* argv[],CCmdLineOption& cmdLineOption)
{
	//�õ���ǰ����Ŀ¼
	strcpy_s(cmdLineOption.m_chCurExeDir,256,argv[0]);
	int i = 0,n = 0;
	while(cmdLineOption.m_chCurExeDir[i] != 0)
	{
		if(cmdLineOption.m_chCurExeDir[i] == '\\')
		{
			n = i;
		}
		++i;
	}
	cmdLineOption.m_chCurExeDir[n] = 0;

	//////////////////////////////////////////////////////////////////////////
	//��ʼ�����н���

	if(m_pAnyOption == 0)
	{
		m_pAnyOption = new AnyOption();
		if(m_pAnyOption == 0)
			return -1;
	}	

	//����������˵��
	m_pAnyOption->addUsage(" O�����������˵����");
	m_pAnyOption->addUsage( " -?  -h  --help                 ��ʾ��������" );
	m_pAnyOption->addUsage( " -p  --in-pe-file        ��ѡ   ����Ҫ������PE��ʽ�ļ�  ��:c:\\source\\sample.exe" );
	m_pAnyOption->addUsage( " -l  --in-language-file  ��ѡ   ����O���������ļ�  ��:c:\\source\\chinese.oic");
	m_pAnyOption->addUsage( " -d  --out-doasm-file    ��ѡ   ������������ɵ��ļ� ��:c:\\source\\sample.doa");

	char* pchHelp = "help";
	char chHelp = 'h';
	char chQuestion = '?';
	char* pchInPeFile = "in-pe-file";
	char chInPeFile = 'p';
	char* pchInLanguageFile = "in-language-file";
	char chInLanguageFile = 'l';
	char* pchOutDoasmFile = "out-doasm-file";
	char chOutDoasmFile = 'd';

	//��Ӳ���ѡ��
	m_pAnyOption->setFlag(chQuestion);
	m_pAnyOption->setFlag(pchHelp, chHelp);	
	m_pAnyOption->setOption(pchInPeFile,chInPeFile);
	m_pAnyOption->setOption(pchInLanguageFile,chInLanguageFile);
	m_pAnyOption->setOption(pchOutDoasmFile,chOutDoasmFile);

	//����������
	m_pAnyOption->processCommandArgs( argc, argv );

	//���û�в���
	if(!m_pAnyOption->hasOptions())
	{ 
		m_pAnyOption->printUsage();
		return 0;
	}

	/* ��ò��� */

	//��ð���
	if( m_pAnyOption->getFlag( chQuestion ) || m_pAnyOption->getFlag( chHelp ) || m_pAnyOption->getFlag( pchHelp ) ) 
	{
		m_pAnyOption->printUsage();
		return 0;
	}

	//���Դ�����ļ�
	if((m_pAnyOption->getValue(pchInPeFile) != 0) || (m_pAnyOption->getValue(chInPeFile) != 0))
	{
		cmdLineOption.m_pchPeFile = m_pAnyOption->getValue(chInPeFile);			
	}

	//��������ļ�
	if((m_pAnyOption->getValue(pchInLanguageFile) != 0) || (m_pAnyOption->getValue(chInLanguageFile) != 0))
	{
		cmdLineOption.m_pchLanguageFile = m_pAnyOption->getValue(chInLanguageFile);			
	}

	//������Ŀ���ļ�
	if((m_pAnyOption->getValue(pchOutDoasmFile) != 0) || (m_pAnyOption->getValue(chOutDoasmFile) != 0))
	{
		cmdLineOption.m_pchDoasmFile = m_pAnyOption->getValue(chOutDoasmFile);
	}

	int iResult = 1;
	if(cmdLineOption.m_pchPeFile == 0)
	{
		printf("����û��Ҫ������PE�ļ�\n");
		iResult = -3;
	}

	if(cmdLineOption.m_pchLanguageFile == 0)
	{
		printf("����û�������ļ�\n");
		iResult = -4;
	}

	if(iResult > 0)
	{
		//���û������ļ������Դ�ļ��õ�Ĭ������ļ�
		if(cmdLineOption.m_pchDoasmFile == 0)
		{
			cmdLineOption.get_default_doasm_file();
		}
	}

	return iResult;
}