// DlgOMLOption.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgOMLOption.h"


// CDlgOMLOption �Ի���

IMPLEMENT_DYNAMIC(CDlgOMLOption, CResizablePage)

CDlgOMLOption::CDlgOMLOption()
	: CResizablePage(CDlgOMLOption::IDD)
{
	SetTabIcon(IDI_OPTION_OASM);
}

CDlgOMLOption::~CDlgOMLOption()
{
}

void CDlgOMLOption::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgOMLOption, CResizablePage)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgOMLOption ��Ϣ�������

BOOL CDlgOMLOption::OnInitDialog()
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

		//���û����·��
		CMFCPropertyGridProperty* pPropertyOML = new CMFCPropertyGridProperty(_T("O�м�����"));
		static TCHAR BASED_CODE szFilter[] = _T("O�м����Ա�����(*.exe)|*.exe|�����ļ�(*.*)|*.*||");
		CMFCPropertyGridFileProperty* pPropertyOMLFile = new CMFCPropertyGridFileProperty(_T("O�м����Ա������"), TRUE, _T(""), _T("exe"), 0, szFilter, _T("O�м����Ա���Ӧ�ó���"));
		pPropertyOMLFile->SetValue(COleVariant(m_strOMLPath));
		pPropertyOML->AddSubItem(pPropertyOMLFile);		
		m_wndPropertyGrid.AddProperty(pPropertyOML);

		//���������ļ�·��
		CMFCPropertyGridProperty* pPropertyLanguage = new CMFCPropertyGridProperty(_T("�����ļ�"));
		static TCHAR BASED_CODE szFilterLanguage[] = _T("O�м����������ļ�(*.oic)|*.oic|�����ļ�(*.*)|*.*||");
		CMFCPropertyGridFileProperty* pPropertyLanguageFile = new CMFCPropertyGridFileProperty(_T("O�м����������ļ�"), TRUE, _T(""), _T("exe"), 0, szFilterLanguage, _T("O�м����������ļ�"));
		pPropertyLanguageFile->SetValue(COleVariant(m_strOMLLanguagePath));
		pPropertyLanguage->AddSubItem(pPropertyLanguageFile);
		m_wndPropertyGrid.AddProperty(pPropertyLanguage);		
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgOMLOption::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		m_wndPropertyGrid.MoveWindow(0,0,cx,cy);
	}
}

void CDlgOMLOption::GetOption()
{
	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		CMFCPropertyGridProperty* pPropertyOML = m_wndPropertyGrid.GetProperty(0);
		CMFCPropertyGridFileProperty* pPropertyOMLFile = (CMFCPropertyGridFileProperty*)pPropertyOML->GetSubItem(0);
		m_strOMLPath = (CString)pPropertyOMLFile->GetValue();

		CMFCPropertyGridProperty* pPropertyLanguage = m_wndPropertyGrid.GetProperty(1);
		CMFCPropertyGridFileProperty* pPropertyLanguageFile = (CMFCPropertyGridFileProperty*)pPropertyLanguage->GetSubItem(0);
		m_strOMLLanguagePath = (CString)pPropertyLanguageFile->GetValue();		
	}	
}