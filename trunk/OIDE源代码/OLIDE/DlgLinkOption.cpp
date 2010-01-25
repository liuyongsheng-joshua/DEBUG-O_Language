// DlgLinkOption.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgLinkOption.h"


// CDlgLinkOption �Ի���

IMPLEMENT_DYNAMIC(CDlgLinkOption, CResizablePage)

CDlgLinkOption::CDlgLinkOption()
	: CResizablePage(CDlgLinkOption::IDD)
{
	SetTabIcon(IDI_OPTION_LINK );
}

CDlgLinkOption::~CDlgLinkOption()
{
}

void CDlgLinkOption::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLinkOption, CResizablePage)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgLinkOption ��Ϣ�������

BOOL CDlgLinkOption::OnInitDialog()
{
	CResizablePage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	if(m_wndPropertyGrid.GetSafeHwnd() == 0)
	{
		if (!m_wndPropertyGrid.Create(WS_VISIBLE | WS_CHILD, CRect(0, 0, 0, 0), this, 2))
		{
			TRACE0("δ�ܴ�����������\n");
			return FALSE;      // δ�ܴ���
		}
		m_wndPropertyGrid.SetOwner(this);

		m_wndPropertyGrid.EnableHeaderCtrl(FALSE);
		m_wndPropertyGrid.EnableDescriptionArea();
		m_wndPropertyGrid.SetVSDotNetLook();
		m_wndPropertyGrid.MarkModifiedProperties();

		//����������·��
		CMFCPropertyGridProperty* pPropertyLink = new CMFCPropertyGridProperty(_T("������"));
		static TCHAR BASED_CODE szFilter[] = _T("���ӳ���(*.exe)|*.exe|�����ļ�(*.*)|*.*||");
		CMFCPropertyGridFileProperty* pPropertyLinkFile = new CMFCPropertyGridFileProperty(_T("���ӳ���"), TRUE, _T(""), _T("exe"), 0, szFilter, _T("������Ӧ�ó���"));
		pPropertyLinkFile->SetValue(COleVariant(m_strLinkerFileName));
		pPropertyLink->AddSubItem(pPropertyLinkFile);
		m_wndPropertyGrid.AddProperty(pPropertyLink);		
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgLinkOption::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		m_wndPropertyGrid.MoveWindow(0,0,cx,cy);
	}
}

void CDlgLinkOption::GetOption()
{
	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		//����������·��
		CMFCPropertyGridProperty* pPropertyLink = m_wndPropertyGrid.GetProperty(0);
		CMFCPropertyGridFileProperty* pPropertyLinkFile = (CMFCPropertyGridFileProperty*)pPropertyLink->GetSubItem(0);
		m_strLinkerFileName = (CString)pPropertyLinkFile->GetValue();		
	}
}