// DlgAddNewFile.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgAddNewFile.h"
#include ".\dlgaddnewfile.h"
#include "./Common/Global.h"


// CDlgAddNewFile �Ի���

IMPLEMENT_DYNAMIC(CDlgAddNewFile, CResizablePage)
CDlgAddNewFile::CDlgAddNewFile()
	: CResizablePage(CDlgAddNewFile::IDD)
{
	m_psp.dwFlags &= (~PSP_HASHELP);
	m_psp.dwFlags |= PSP_USEHICON;
	HICON hIconTab = AfxGetApp()->LoadIcon( IDI_FILE);
	m_psp.hIcon = hIconTab;
}

CDlgAddNewFile::~CDlgAddNewFile()
{
}

void CDlgAddNewFile::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FILE, m_listctrlFile);
}


BEGIN_MESSAGE_MAP(CDlgAddNewFile, CResizablePage)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgAddNewFile ��Ϣ�������

BOOL CDlgAddNewFile::OnInitDialog()
{
	CResizablePage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//�����ô��ڴ�С�ķ���������IDC_LIST1�ؼ�
	((CListCtrl*)GetDlgItem(IDC_LIST1))->MoveWindow(0,0,1,1);

	CBitmap bm;	
	if (!m_ilFileList.Create(18,18,TRUE | ILC_COLOR24,8,0))
		return FALSE;

	bm.LoadBitmap(IDB_BITMAP_ADD_NEW_ITEM);    
	m_ilFileList.Add(&bm,(CBitmap*)NULL);
	bm.Detach();

	m_listctrlFile.SetImageList( &m_ilFileList, LVSIL_NORMAL);
		
	m_listctrlFile.InsertItem(m_listctrlFile.GetItemCount(),_T("O�м������ļ�"),6);
	m_listctrlFile.InsertItem(m_listctrlFile.GetItemCount(),_T("O�м�����ͷ�ļ�"),5);
	m_listctrlFile.InsertItem(m_listctrlFile.GetItemCount(),_T("O����ļ�"),3);
	m_listctrlFile.InsertItem(m_listctrlFile.GetItemCount(),_T("O���ͷ�ļ�"),4);

	AddAnchor(IDC_LIST_FILE, TOP_LEFT, BOTTOM_RIGHT);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HBRUSH CDlgAddNewFile::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void CDlgAddNewFile::SetBeginNewItemType(int nNewItemType)
{
	int nItemIndex = -1;
	switch(nNewItemType)
	{
	case NEW_ITEM_TYPE_PROJECT_OML_CODE_FILE:
		nItemIndex = LIST_ITEM_INDEX_PROJECT_OML_CODE_FILE;
		break;
	case NEW_ITEM_TYPE_PROJECT_OML_HEAD_FILE:
		nItemIndex = LIST_ITEM_INDEX_PROJECT_OML_HEAD_FILE;
		break;
	case NEW_ITEM_TYPE_PROJECT_OASM_CODE_FILE:
		nItemIndex = LIST_ITEM_INDEX_PROJECT_OASM_CODE_FILE;
		break;
	case NEW_ITEM_TYPE_PROJECT_OASM_HEAD_FILE:
		nItemIndex = LIST_ITEM_INDEX_PROJECT_OASM_HEAD_FILE;
		break;
	default:
		break;
	}

	if(nItemIndex < 0)
		return;

	UINT flag = LVIS_SELECTED|LVIS_FOCUSED;
	m_listctrlFile.SetItemState(nItemIndex,flag,flag);
	m_listctrlFile.SetFocus();
}

int CDlgAddNewFile::GetAddNewItemType()
{
	int nCurSelIndex = m_listctrlFile.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED);
	//����ļ�
	switch(nCurSelIndex)
	{
	case LIST_ITEM_INDEX_PROJECT_OML_CODE_FILE:
		return NEW_ITEM_TYPE_PROJECT_OML_CODE_FILE;
	case LIST_ITEM_INDEX_PROJECT_OML_HEAD_FILE:
		return NEW_ITEM_TYPE_PROJECT_OML_HEAD_FILE;
	case LIST_ITEM_INDEX_PROJECT_OASM_CODE_FILE:
		return NEW_ITEM_TYPE_PROJECT_OASM_CODE_FILE;
	case LIST_ITEM_INDEX_PROJECT_OASM_HEAD_FILE:
		return NEW_ITEM_TYPE_PROJECT_OASM_HEAD_FILE;
	}
	
	return NEW_ITEM_TYPE_NULL;
}
