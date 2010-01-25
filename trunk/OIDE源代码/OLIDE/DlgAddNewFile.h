#pragma once

#include "./Controls/TreePropSheet/ResizablePage.h"
#include "./Controls/TreePropSheet/TreePropSheetUtil.hpp"
#include "afxcmn.h"

// CDlgAddNewFile �Ի���

enum LIST_ITEM_INDEX_TYPE
{
	LIST_ITEM_INDEX_PROJECT_OML_CODE_FILE,
	LIST_ITEM_INDEX_PROJECT_OML_HEAD_FILE,
	LIST_ITEM_INDEX_PROJECT_OASM_CODE_FILE,
	LIST_ITEM_INDEX_PROJECT_OASM_HEAD_FILE,
};


class CDlgAddNewFile 
: public CResizablePage,
  public TreePropSheet::CWhiteBackgroundProvider
{
	DECLARE_DYNAMIC(CDlgAddNewFile)

public:
	CDlgAddNewFile();
	virtual ~CDlgAddNewFile();

// �Ի�������
	enum { IDD = IDD_DLG_NEW_FILE };

protected:

	CListCtrl   m_listctrlFile;
	CImageList  m_ilFileList;

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
