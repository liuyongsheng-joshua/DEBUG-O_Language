
#include "stdafx.h"
#include "OLIDE.h"
#include "AboutDlg.h"


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	long lVersion1,lVersion2,lVersion3,lVersion4;
	theApp.GetCurVersion(lVersion1,lVersion2,lVersion3,lVersion4);

	CString strVersion;
	strVersion.Format(_T("O���Կ�������  %d.%d.%d.%d ���԰�\r\n\r\n"),lVersion1,lVersion2,lVersion3,lVersion4);

	m_strText = strVersion;	
	m_strText += 
		_T("��ӭʹ��O�����м������׼�\r\n\r\n")
		//_T("�밴����������ַ������ı�����\r\n\r\n")
		_T("������ҳ��www.olanguage.org\r\n\r\n")
		_T("�������䣺olanguage@163.com\r\n\r\n")		
		//_T("���뿪����www.scover.cn/bbs/thread.php?fid=102\r\n\r\n")
		_T("����������������ʹ�õ���Դ������ResEdit�ͺ�̨������polink��Ϊ������\r\n")
		_T("����������ResEdit���ص�ַΪ http://www.resedit.net/\r\n")		
		_T("����������polink���ص�ַΪ www.smorgasbordet.com/pellesc/index.htm\r\n")
		_T("������������Ȩ��ԭ��������\r\n\r\n")
		_T("��Ȩ����(C) 2008-2009 O���Կ����� ��������Ȩ��");
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
}

