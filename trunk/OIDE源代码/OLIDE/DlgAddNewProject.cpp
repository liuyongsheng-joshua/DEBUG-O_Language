// DlgAddNewProject.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgAddNewProject.h"
#include ".\dlgaddnewproject.h"
#include "./Common/Global.h"


// CDlgAddNewProject �Ի���

IMPLEMENT_DYNAMIC(CDlgAddNewProject, CResizablePage)
CDlgAddNewProject::CDlgAddNewProject()
	: CResizablePage(CDlgAddNewProject::IDD)
{
	m_psp.dwFlags &= (~PSP_HASHELP);
	m_psp.dwFlags |= PSP_USEHICON;
	HICON hIconTab = AfxGetApp()->LoadIcon( IDI_PROJECT );
	m_psp.hIcon = hIconTab;
}

CDlgAddNewProject::~CDlgAddNewProject()
{
}

void CDlgAddNewProject::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_PROJECT, m_listctrlProject);
}


BEGIN_MESSAGE_MAP(CDlgAddNewProject, CResizablePage)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgAddNewProject ��Ϣ�������

BOOL CDlgAddNewProject::OnInitDialog()
{
	CResizablePage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//�����ô��ڴ�С�ķ���������IDC_LIST1�ؼ�
	((CListCtrl*)GetDlgItem(IDC_LIST1))->MoveWindow(0,0,1,1);

	CBitmap bm;	
	if (!m_ilProjectList.Create(18,18,TRUE | ILC_COLOR24,8,0))
		return FALSE;

	bm.LoadBitmap(IDB_BITMAP_ADD_NEW_ITEM);    
	m_ilProjectList.Add(&bm,(CBitmap*)NULL);
	bm.Detach();

	m_listctrlProject.SetImageList( &m_ilProjectList, LVSIL_NORMAL);

	m_listctrlProject.InsertItem(m_listctrlProject.GetItemCount(),_T("Win32 Ӧ�ó���"),1);
	m_listctrlProject.InsertItem(m_listctrlProject.GetItemCount(),_T("Win32 ����̨����"),1);
	m_listctrlProject.InsertItem(m_listctrlProject.GetItemCount(),_T("Win32 ��̬���ӿ�"),1);
	//m_listctrlProject.InsertItem(m_listctrlProject.GetItemCount(),_T("Win32 ��̬��"),1);
	
	AddAnchor(IDC_LIST_PROJECT, TOP_LEFT, BOTTOM_RIGHT);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HBRUSH CDlgAddNewProject::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = __super::OnCtlColor(pDC, pWnd, nCtlColor);

	//// TODO:  �ڴ˸��� DC ���κ�����

	//// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	//return hbr;

	if( HasWhiteBackground() )
	{
		pDC->SetBkMode(TRANSPARENT);
		return ::GetSysColorBrush( COLOR_WINDOW );
	}

	return  CResizablePage::OnCtlColor(pDC, pWnd, nCtlColor);
}

void CDlgAddNewProject::SetBeginNewItemType(int nNewItemType)
{
	int nItemIndex = -1;
	switch(nNewItemType)
	{
	case NEW_ITEM_TYPE_PROJECT_WIN32_WINDOWS:
		nItemIndex = LIST_ITEM_INDEX_PROJECT_WIN32_WINDOWS;
		break;
	case NEW_ITEM_TYPE_PROJECT_WIN32_CONSOLE:
		nItemIndex = LIST_ITEM_INDEX_PROJECT_WIN32_CONSOLE;
		break;
	case NEW_ITEM_TYPE_PROJECT_WIN32_DLL:
		nItemIndex = LIST_ITEM_INDEX_PROJECT_WIN32_DLL;
		break;
	case NEW_ITEM_TYPE_PROJECT_WIN32_LIB:
		nItemIndex = LIST_ITEM_INDEX_PROJECT_WIN32_LIB;
		break;
	default:
		break;
	}

	if(nItemIndex < 0)
		return;

	UINT flag = LVIS_SELECTED|LVIS_FOCUSED;
	m_listctrlProject.SetItemState(nItemIndex,flag,flag);
	m_listctrlProject.SetFocus();
}

int CDlgAddNewProject::GetAddNewItemType()
{
	int nCurSelIndex = m_listctrlProject.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED);
	//��ӹ���
	switch(nCurSelIndex)
	{
	case LIST_ITEM_INDEX_PROJECT_WIN32_WINDOWS:
		return NEW_ITEM_TYPE_PROJECT_WIN32_WINDOWS;
	case LIST_ITEM_INDEX_PROJECT_WIN32_CONSOLE:
		return NEW_ITEM_TYPE_PROJECT_WIN32_CONSOLE;
	case LIST_ITEM_INDEX_PROJECT_WIN32_DLL:
		return NEW_ITEM_TYPE_PROJECT_WIN32_DLL;
	case LIST_ITEM_INDEX_PROJECT_WIN32_LIB:
		return NEW_ITEM_TYPE_PROJECT_WIN32_LIB;
	}

	return NEW_ITEM_TYPE_NULL;
}

