
#ifndef _SYNTAX_WORD_LIST_H_
#define _SYNTAX_WORD_LIST_H_

////����ķ����ַ����ǰ�˳��ģ��벻Ҫ����ַ�λ��
//static const TCHAR g_oasmWordListSymbol[] = 
//{
//	_T("�� ��  �� ")                             //ע��
//	_T("�� �� �� �� �� �� ")                     //���� ����
//	_T("��  �� �� ��  ")                         //���ַ�(��)
//	_T("�� �� �� �� �� �� �� �� �� �� �� ��  �� �� �� �� ")   //��
//};
//
////CPUָ��
//static const TCHAR g_oasmWordListCPUInsns[] = 
//{
//	_T("�Ӻ�A���� ����A���� �˺�A���� ����A���� ")
//	_T("�������ȼ��� �������߽� λ��ɨ�赽 λ��ɨ�赽 ")
//	_T("�ֽڽ��� λ���� λ������ λ������0 λ������1 ")    
//	_T("�������ˢ�� �õ�CPU��ʶ �Ӻ�ʮ���� ����ʮ���� ������ջ֡ ")
//	_T("��Ч���ڻ��� TLB�����Ч װ�����Ȩ�� ���Ӽ��ز��� ")
//	_T("ѭ�� ���ѭ�� Ϊ��ѭ�� ����ѭ�� ����ѭ�� ")
//	_T("���ضν��� ���Ӽ��ر������ ���� ����ʱ��ʾ�ƶ��� ���ӵȴ� ")
//	_T("Ԥ��NTA Ԥ��NT0 Ԥ��NT1 Ԥ��NT2 ")
//	_T("��ר��ģʽ�Ĵ��� ��ִ�м��Ӽ��� ")
//	_T("��ʱ������� ��ʱ���������CPU��ʶ ")
//	_T("�ָ�ϵͳģʽ ��ɨ�� ����������� ����ȫ�� ")
//	_T("���� �쳣CPU ")
//	_T("��֤�� ��֤д ��д����Ч���ڻ��� дר��ģʽ�Ĵ��� ��λ�� ")	
//};
//
////FPUָ��
//static const TCHAR g_oasmWordListFPUInsns[] = 
//{
//	_T("��ո���Ĵ�����־ ����������쳣 ���㲻�������쳣 ")
//	_T("�Ƚϼ��ر�־ �Ƚϼ��ر�־��ջ ���ȼ��ر�־  ���ȼ��ر�־��ջ ")
//	_T("�����ͷ� �������ʼ�� ���㲻����ʼ�� ������ؿ����� ")
//	_T("������ػ��� ����ָ�״̬ �����鱣��״̬ ���㲻��鱣��״̬ ")
//	_T("�����鱣������� ���㲻��鱣������� �����鱣�滷�� ")
//	_T("���㲻��鱣�滷�� �����鱣��״̬�� ���㲻��鱣��״̬�� ")
//	_T("������ ����X�ָ� ����X���� ����ֽ� ")
//};
//
////�Ĵ���
//static const TCHAR g_oasmWordListRegister[] = 
//{
//	_T("�ۼӵ�  �ۼӸ�  �ۼ�16  �ۼ�32 ")
//	_T("������  ������  ����16  ����32 ")
//	_T("������  ������  ����16  ����32 ")
//	_T("���ݵ�  ���ݸ�  ����16  ����32 ")
//	_T("��ַ16  ��ַ32  ջַ16  ջַ32 ")
//	_T("Դַ16  Դַ32  ��ַ16  ��ַ32 ")
//	_T("����  ���  ջ��  ����  ־�� ȫ�� ")
//	_T("��0 ��1 ��2 ��3 ��4 ��5 ��6 ��7 ")
//	_T("��0 ��1 ��2 ��3 ��4 ��5 ��6 ��7 ")
//	_T("��0 ��1 ��2 ��3 ��4 ��5 ��6 ��7 ")
//	_T("ý0 ý1 ý2 ý3 ý4 ý5 ý6 ý7 ")
//	_T("��0 ��1 ��2 ��3 ��4 ��5 ��6 ��7 ")
//	_T("��0 ��2 ��3 ��4 ")
//};
//
////������
//static const TCHAR g_oasmWordListOperator[] = 
//{
//	_T("+ - �� �� �� =  !  ? & | ^ %  ~  ")
//	_T("[ ] < > { } ( ) ")
//	_T("�� ��  �� �� �� �� �� �� �K �I �� �� �� �� �L �J �� �� �� �� �� �� ")
//	_T("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �E �� �� �� ")
//	_T("�� �h �l �� ")
//	_T("�� �� �� �S �R ")
//	_T("�� �� �� ")
//};

class CSyntaxWordList
{
public:

	CSyntaxWordList();
	~CSyntaxWordList();

	CString m_strOasmWordListSymbol;
	CString m_strOasmWordListCPUInsns;
	CString m_strOasmWordListFPUInsns;
	CString m_strOasmWordListRegister;
	CString m_strOasmWordListDefineWord;
	CString m_strOasmWordListMacro;
	CString m_strOasmWordListOperatorTxt;
	CString m_strOasmWordListOperator;

	CString m_strOMLWordListCommentSymbol;
	CString m_strOMLWordListKeyword;
	CString m_strOMLWordListOperator;
	CString m_strOMLWordListMacroTxt;	

	BOOL LoadOASMSyntaxWord(const CString& strSyntaxWordFileName);
	BOOL LoadOMLSyntaxWord(const CString& strSyntaxWordFileName);
};

#endif //_SYNTAX_WORD_LIST_H_

            
         
