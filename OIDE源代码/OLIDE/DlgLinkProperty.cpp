// DlgLinkOption.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgLinkProperty.h"


// CDlgLinkProperty �Ի���

IMPLEMENT_DYNAMIC(CDlgLinkProperty, CResizablePage)

CDlgLinkProperty::CDlgLinkProperty()
	: CResizablePage(CDlgLinkProperty::IDD)
{
	SetTabIcon(IDI_OPTION_LINK );
}

CDlgLinkProperty::~CDlgLinkProperty()
{
}

void CDlgLinkProperty::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLinkProperty, CResizablePage)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgLinkProperty ��Ϣ�������

TCHAR* g_pchLinkSubSystemOption[] = 
{
	_T("����̨����(/SUBSYSTEM:CONSOLE)"),
	_T("WINDOWS����(/SUBSYSTEM:WINDOWS)"),
};

TCHAR* g_pchLinkProgrammTypeOption[] = 
{
	_T("���г���(.EXE)"),
	_T("��̬���ӿ�(.DLL)"),
	_T("���ļ�(.LIB)"),
};

BOOL CDlgLinkProperty::OnInitDialog()
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
		
		//���ô���Ŀ¼
		CMFCPropertyGridProperty* pPropertyCodeDir = new CMFCPropertyGridProperty(_T("����Ŀ¼"));
		pPropertyCodeDir->AddSubItem(new CMFCPropertyGridFileProperty(_T("����Ŀ¼"), m_strCodeDir,0,_T("��������Ҫ����Ĵ���Ŀ¼")));
		pPropertyCodeDir->AddSubItem(new CMFCPropertyGridFileProperty(_T("��ԴĿ¼"), m_strResourceDir,0,_T("��������Ҫ�������ԴĿ¼")));
		m_wndPropertyGrid.AddProperty(pPropertyCodeDir);

		//�����������ɵĳ�������
		int nLinkProgrammTypeOptionCount = sizeof(g_pchLinkProgrammTypeOption)/sizeof(g_pchLinkProgrammTypeOption[0]);
		if(m_nLinkProgrammType<0 || m_nLinkProgrammType>nLinkProgrammTypeOptionCount)
		{
			m_nLinkProgrammType = 0;
		}
		CMFCPropertyGridProperty* pPropertyProgrammType = new CMFCPropertyGridProperty(_T("��������"));
		CMFCPropertyGridProperty* pPropertyProgrammTypeItem = new CMFCPropertyGridProperty(_T("���ɳ�������"), g_pchLinkSubSystemOption[m_nLinkSubSystem], _T("���ó������ɳ�������Ϊִ�г���(.EXE)����̬���ӿ�(.DLL)�����ļ�(.LIB)"));
		for(int i=0;i<nLinkProgrammTypeOptionCount;++i)
		{
			pPropertyProgrammTypeItem->AddOption(g_pchLinkProgrammTypeOption[i]);
		}
		pPropertyProgrammTypeItem->AllowEdit(FALSE);
		pPropertyProgrammTypeItem->SetValue(g_pchLinkProgrammTypeOption[m_nLinkProgrammType]);

		pPropertyProgrammType->AddSubItem(pPropertyProgrammTypeItem);
		m_wndPropertyGrid.AddProperty(pPropertyProgrammType);

		//������ϵͳ
		int nLinkSubSystemOptionCount = sizeof(g_pchLinkSubSystemOption)/sizeof(g_pchLinkSubSystemOption[0]);
		if(m_nLinkSubSystem<0 || m_nLinkSubSystem>nLinkSubSystemOptionCount)
		{
			m_nLinkSubSystem = 0;
		}
		CMFCPropertyGridProperty* pPropertySubSystem = new CMFCPropertyGridProperty(_T("ϵͳ����"));
		CMFCPropertyGridProperty* pPropertySubSystemItem = new CMFCPropertyGridProperty(_T("�����ļ�����ϵͳ"), g_pchLinkSubSystemOption[m_nLinkSubSystem], _T("���ó�����������:/SUBSYSTEM:CONSOLE���ɿ���̨���� /SUBSYSTEM:WINDOWS����WINDOWS����"));
		for(int i=0;i<nLinkSubSystemOptionCount;++i)
		{
			pPropertySubSystemItem->AddOption(g_pchLinkSubSystemOption[i]);
		}
		pPropertySubSystemItem->AllowEdit(FALSE);
		pPropertySubSystemItem->SetValue(g_pchLinkSubSystemOption[m_nLinkSubSystem]);

		pPropertySubSystem->AddSubItem(pPropertySubSystemItem);
		m_wndPropertyGrid.AddProperty(pPropertySubSystem);
		
		//���õ��԰����
		CMFCPropertyGridProperty* pPropertyOutputDebug = new CMFCPropertyGridProperty(_T("���԰����"));		
		pPropertyOutputDebug->AddSubItem(new CMFCPropertyGridFileProperty(_T("�м��ļ�Ŀ¼"), m_strDebugMiddleFileDir,0,_T("������������ɵ��м��ļ���Ŀ¼")));
		pPropertyOutputDebug->AddSubItem(new CMFCPropertyGridProperty(_T("�����ļ���"), (_variant_t)m_strDebugExeFileName, _T("����ִ���ļ���·������")));
		m_wndPropertyGrid.AddProperty(pPropertyOutputDebug);

		//���ô��������
		CMFCPropertyGridProperty* pPropertyOutputRelease = new CMFCPropertyGridProperty(_T("���������"));		
		pPropertyOutputRelease->AddSubItem(new CMFCPropertyGridFileProperty(_T("�м��ļ�Ŀ¼"), m_strReleaseMiddleFileDir,0,_T("������������ɵ��м��ļ���Ŀ¼")));
		pPropertyOutputRelease->AddSubItem(new CMFCPropertyGridProperty(_T("�����ļ���"), (_variant_t)m_strReleaseExeFileName, _T("����ִ���ļ���·������")));
		m_wndPropertyGrid.AddProperty(pPropertyOutputRelease);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgLinkProperty::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		m_wndPropertyGrid.MoveWindow(0,0,cx,cy);
	}
}

void CDlgLinkProperty::GetOption()
{
	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		//���ô���Ŀ¼		
		CMFCPropertyGridProperty* pPropertyCodeDir = m_wndPropertyGrid.GetProperty(0);
		m_strCodeDir = (CString)pPropertyCodeDir->GetSubItem(0)->GetValue();
		m_strResourceDir = (CString)pPropertyCodeDir->GetSubItem(1)->GetValue();
		
		//���ó�������
		CMFCPropertyGridProperty* pPropertyProgrammType = m_wndPropertyGrid.GetProperty(1);
		CMFCPropertyGridProperty* pPropertyProgrammTypeItem = pPropertyProgrammType->GetSubItem(0);
		m_nLinkProgrammType = 0;
		CString strProgrammTypeItemName = (CString)pPropertyProgrammTypeItem->GetValue();
		int nLinkProgrammTypeOptionCount = sizeof(g_pchLinkProgrammTypeOption)/sizeof(g_pchLinkProgrammTypeOption[0]);		
		for(int i=0;i<nLinkProgrammTypeOptionCount;++i)
		{
			if(strProgrammTypeItemName == g_pchLinkProgrammTypeOption[i])
			{
				m_nLinkProgrammType = i;
				break;
			}
		}

		//������ϵͳ
		CMFCPropertyGridProperty* pPropertySubSystem = m_wndPropertyGrid.GetProperty(2);
		CMFCPropertyGridProperty* pPropertySubSystemItem = pPropertySubSystem->GetSubItem(0);
		m_nLinkSubSystem = 0;
		CString strSubSystemItemName = (CString)pPropertySubSystemItem->GetValue();
		int nLinkSubSystemOptionCount = sizeof(g_pchLinkSubSystemOption)/sizeof(g_pchLinkSubSystemOption[0]);		
		for(int i=0;i<nLinkSubSystemOptionCount;++i)
		{
			if(strSubSystemItemName == g_pchLinkSubSystemOption[i])
			{
				m_nLinkSubSystem = i;
				break;
			}
		}		

		//���õ��԰����
		CMFCPropertyGridProperty* pPropertyOutputDebug = m_wndPropertyGrid.GetProperty(3);
		m_strDebugMiddleFileDir = (CString)pPropertyOutputDebug->GetSubItem(0)->GetValue();
		m_strDebugExeFileName = (CString)pPropertyOutputDebug->GetSubItem(1)->GetValue();

		//���ô��������
		CMFCPropertyGridProperty* pPropertyOutputRelease = m_wndPropertyGrid.GetProperty(4);
		m_strReleaseMiddleFileDir = (CString)pPropertyOutputRelease->GetSubItem(0)->GetValue();
		m_strReleaseExeFileName = (CString)pPropertyOutputRelease->GetSubItem(1)->GetValue();
	}
}