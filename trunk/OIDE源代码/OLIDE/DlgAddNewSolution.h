#pragma once


#include "./Controls/TreePropSheet/ResizablePage.h"
#include "./Controls/TreePropSheet/TreePropSheetUtil.hpp"
#include "afxcmn.h"
//#include "afxcmn.h"

// CDlgAddNewSolution �Ի���

#define LIST_ITEM_INDEX_SOLUTION  0


class CDlgAddNewSolution 
: public CResizablePage,
  public TreePropSheet::CWhiteBackgroundProvider
{
	DECLARE_DYNAMIC(CDlgAddNewSolution)

public:
	CDlgAddNewSolution();   // ��׼���캯��
	virtual ~CDlgAddNewSolution();

// �Ի�������
	enum { IDD = IDD_DLG_NEW_SOLUTION };

protected:

	CListCtrl   m_listctrlSolution;
	CImageList  m_ilSolutionList;
public:

	void SetBeginNewItemType(int nNewItemType);
	int  GetAddNewItemType();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	
};
