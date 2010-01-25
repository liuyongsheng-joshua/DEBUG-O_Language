#pragma once

#include "./Controls/TreePropSheet/ResizablePage.h"
#include "./Controls/TreePropSheet/TreePropSheetUtil.hpp"
#include "afxcmn.h"

// CDlgAddNewProject �Ի���

#define LIST_ITEM_INDEX_PROJECT_WIN32_WINDOWS   0
#define LIST_ITEM_INDEX_PROJECT_WIN32_CONSOLE   1
#define LIST_ITEM_INDEX_PROJECT_WIN32_DLL       2
#define LIST_ITEM_INDEX_PROJECT_WIN32_LIB       3

class CDlgAddNewProject 
: public CResizablePage,
  public TreePropSheet::CWhiteBackgroundProvider
{
	DECLARE_DYNAMIC(CDlgAddNewProject)

public:
	CDlgAddNewProject();
	virtual ~CDlgAddNewProject();

// �Ի�������
	enum { IDD = IDD_DLG_NEW_PROJECT };

protected:

	CListCtrl   m_listctrlProject;
	CImageList  m_ilProjectList;

	//����
public:
	void SetBeginNewItemType(int nNewItemType);
	int  GetAddNewItemType();
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
};
