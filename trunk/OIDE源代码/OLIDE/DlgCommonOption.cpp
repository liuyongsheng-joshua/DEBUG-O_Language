// DlgOasmOption.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgCommonOption.h"


// CDlgCommonOption �Ի���

IMPLEMENT_DYNAMIC(CDlgCommonOption, CResizablePage)

CDlgCommonOption::CDlgCommonOption()
	: CResizablePage(CDlgCommonOption::IDD)
{
	SetTabIcon(IDI_OPTION_COMMON);
}

CDlgCommonOption::~CDlgCommonOption()
{
}

void CDlgCommonOption::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCommonOption, CResizablePage)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgCommonOption ��Ϣ�������

BOOL CDlgCommonOption::OnInitDialog()
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

		//������������
		CMFCPropertyGridProperty* pGroupUpdate = new CMFCPropertyGridProperty(_T("��������"));
		pGroupUpdate->AddSubItem(new CMFCPropertyGridProperty(_T("ÿ����������°汾"), (_variant_t)(m_bUpdateEveryTime?true:false), _T("����ÿ�����������ӵ��������°汾�����°汾����ʾ������")));
		m_wndPropertyGrid.AddProperty(pGroupUpdate);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgCommonOption::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		m_wndPropertyGrid.MoveWindow(0,0,cx,cy);
	}
}

void CDlgCommonOption::GetOption()
{
	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		//��������
		CMFCPropertyGridProperty* pPropertyUpdateType = m_wndPropertyGrid.GetProperty(0);
		m_bUpdateEveryTime = (_variant_t)pPropertyUpdateType->GetSubItem(0)->GetValue();
	}	
}