// DlgOasmOption.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgOasmOption.h"


// CDlgOasmOption �Ի���

IMPLEMENT_DYNAMIC(CDlgOasmOption, CResizablePage)

CDlgOasmOption::CDlgOasmOption()
	: CResizablePage(CDlgOasmOption::IDD)
{
	SetTabIcon(IDI_OPTION_OASM);
}

CDlgOasmOption::~CDlgOasmOption()
{
}

void CDlgOasmOption::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgOasmOption, CResizablePage)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgOasmOption ��Ϣ�������

BOOL CDlgOasmOption::OnInitDialog()
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
		CMFCPropertyGridProperty* pPropertyOasm = new CMFCPropertyGridProperty(_T("�����"));
		static TCHAR BASED_CODE szFilter[] = _T("O������(*.exe)|*.exe|�����ļ�(*.*)|*.*||");
		CMFCPropertyGridFileProperty* pPropertyOasmFile = new CMFCPropertyGridFileProperty(_T("O������"), TRUE, _T(""), _T("exe"), 0, szFilter, _T("O������Ӧ�ó���"));
		pPropertyOasmFile->SetValue(COleVariant(m_strOasmPath));
		pPropertyOasm->AddSubItem(pPropertyOasmFile);		
		m_wndPropertyGrid.AddProperty(pPropertyOasm);

		//���������ļ�·��
		CMFCPropertyGridProperty* pPropertyLanguage = new CMFCPropertyGridProperty(_T("�����ļ�"));
		static TCHAR BASED_CODE szFilterLanguage[] = _T("O��������ļ�(*.oic)|*.oic|�����ļ�(*.*)|*.*||");
		CMFCPropertyGridFileProperty* pPropertyLanguageFile = new CMFCPropertyGridFileProperty(_T("O��������ļ�"), TRUE, _T(""), _T("exe"), 0, szFilterLanguage, _T("O������������ļ�"));
		pPropertyLanguageFile->SetValue(COleVariant(m_strOasmLanguagePath));
		pPropertyLanguage->AddSubItem(pPropertyLanguageFile);
		m_wndPropertyGrid.AddProperty(pPropertyLanguage);		
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgOasmOption::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		m_wndPropertyGrid.MoveWindow(0,0,cx,cy);
	}
}

void CDlgOasmOption::GetOption()
{
	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		CMFCPropertyGridProperty* pPropertyOasm = m_wndPropertyGrid.GetProperty(0);
		CMFCPropertyGridFileProperty* pPropertyOasmFile = (CMFCPropertyGridFileProperty*)pPropertyOasm->GetSubItem(0);
		m_strOasmPath = (CString)pPropertyOasmFile->GetValue();

		CMFCPropertyGridProperty* pPropertyLanguage = m_wndPropertyGrid.GetProperty(1);
		CMFCPropertyGridFileProperty* pPropertyLanguageFile = (CMFCPropertyGridFileProperty*)pPropertyLanguage->GetSubItem(0);
		m_strOasmLanguagePath = (CString)pPropertyLanguageFile->GetValue();		
	}	
}