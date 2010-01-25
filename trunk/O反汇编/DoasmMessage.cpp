
#include "DoasmMessage.h"
#include "./DoasmDll.h"

struct DOASM_MESSAGE_INFO
{
	int   m_nMsgCode;
	char* m_pMessage;
};

DOASM_MESSAGE_INFO doasm_msg_info_chinese[] = 
{
	DOASM_MSG_NULL,                             "",	
	DOASM_MSG_PE_FILE_NOT_EXIST,                "\n%s �ļ�������!",
	DOASM_MSG_PE_FILE_INVALID,                  "\n%s ����32λPE�ļ�!",
	DOASM_MSG_LOAD_PE_FILE_FAILD,               "\n���� %s �ļ�ʧ��!",
	DOASM_MSG_LOAD_LANGUAGE_FILE_FAILD,         "\n%s ���������ļ�ʧ��!",
	DOASM_MSG_OPEN_DOASM_FILE_FAILD,            "\n%s �򿪷�����ļ�(.doa)ʧ��!",
	DOASM_MSG_DOASM_FILE_INFO,                  "������ļ�:%s \n���ص�ַ:%08X  ��ڵ�ַ:%08X\n",
	DOASM_MSG_SEGMENT_INFO_TITLE,               "\n  �λ�����Ϣ,�θ���:%04X",
	DOASM_MSG_SEGMENT_NAME,                     "\n    ������:%s  ",
	DOASM_MSG_SEGMENT_INFO,                     "���ص�ַ:%08X  �ļ�λ��:%08X  �δ�С:%08X  ����ֵ:%08X",
	DOASM_MSG_CODE_SEGMENT,                     "\n\n----- �����(%s) [�ļ�λ��:%08X  �δ�С:%08X] -------\n",
	DOASM_MSG_NO_EXECUTE_SEGMENT,               "\n\nû���ҵ���ִ�ж�!",
	DOASM_MSG_ENTRY_POINT,                      ">>>������� ���򽫴����￪ʼִ��>>>\n",
	DOASM_MSG_ALL_ZERO_DATA,                    "ȫ0����\n",
	DOASM_MSG_NOT_INSTRUCTION_DATA,             "�ַ� '%s'  //��ָ������",
	DOASM_MSG_UNKNOW_INSTRUCTION_DATA,          "�ֽ� '%02X'  //��ָ������",
	DOASM_MSG_LANGUAGE_INTER_CODE_INVALID,      "\n�������� (0x%08X) ��Ч!",
};

DOASM_MESSAGE_INFO doasm_msg_info_english[] = 
{
	DOASM_MSG_NULL,                             "",	
	DOASM_MSG_PE_FILE_NOT_EXIST,                "\n%s File Not Exist!",
	DOASM_MSG_PE_FILE_INVALID,                  "\n%s Not Bit32 PE File!",
	DOASM_MSG_LOAD_PE_FILE_FAILD,               "\nLoad %s File Faild!",
	DOASM_MSG_LOAD_LANGUAGE_FILE_FAILD,         "\n%s Load Language File Faild!",
	DOASM_MSG_OPEN_DOASM_FILE_FAILD,            "\n%s Open Doasm File(.doa) Faild!",
	DOASM_MSG_DOASM_FILE_INFO,                  "Disassembly of File:%s \nImagebase:%08X  Entry Point:%08X\n",
	DOASM_MSG_SEGMENT_INFO_TITLE,               "\n  Segment Information,Number of Segment:%04X",
	DOASM_MSG_SEGMENT_NAME,                     "\n    Name:%s  ",
	DOASM_MSG_SEGMENT_INFO,                     "RVA:%08X  Offset:%08X  Size:%08X  Flags:%08X",
	DOASM_MSG_CODE_SEGMENT,                     "\n\n----- Code Segment(%s) [Segment Offset:%08X  Segment Size:%08X] -------\n",
	DOASM_MSG_NO_EXECUTE_SEGMENT,               "\n\nNo Execute Segment!",
	DOASM_MSG_ENTRY_POINT,                      ">>>Program Entry Point>>>\n",
	DOASM_MSG_ALL_ZERO_DATA,                    "Byte 0 Dup(0)\n",
	DOASM_MSG_NOT_INSTRUCTION_DATA,             "Char '%s'  //Not Instruction Data",
	DOASM_MSG_UNKNOW_INSTRUCTION_DATA,          "Byte '%02X'  //Not Instruction Data",	
	DOASM_MSG_LANGUAGE_INTER_CODE_INVALID,      "\nLanguage Code (0x%08X) Invalid!",
};

char* GetDoasmMessageInfo(int nMsgCode)
{	
	DOASM_MESSAGE_INFO* p_msg_info = doasm_msg_info_chinese;
	int nMessageCount = sizeof(doasm_msg_info_chinese)/sizeof(doasm_msg_info_chinese[0]);

	switch(doi_GetLanguageType())
	{
	case DLT_ENGLISH:           p_msg_info = doasm_msg_info_english;break;
	case DLT_SIMPLE_CHINESE:    p_msg_info = doasm_msg_info_chinese;break;
	}
	
	for(int i=0;i<nMessageCount;++i)
	{
		if(p_msg_info[i].m_nMsgCode == nMsgCode)
			return p_msg_info[i].m_pMessage;
	}

	return 0;
}