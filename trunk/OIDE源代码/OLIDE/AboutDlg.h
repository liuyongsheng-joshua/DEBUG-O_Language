
#ifndef _ABOUT_DLG_H_ 
#define _ABOUT_DLG_H_ 

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

#include "resource.h"       // ������

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strText;
};

#endif //_ABOUT_DLG_H_ 