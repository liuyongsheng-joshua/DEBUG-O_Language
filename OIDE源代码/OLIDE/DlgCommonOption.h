#pragma once

#include "./Controls/TreePropSheet/ResizablePage.h"
#include "./Controls/TreePropSheet/TreePropSheetUtil.hpp"

// CDlgCommonOption �Ի���

class CDlgCommonOption 
: public CResizablePage,
  public TreePropSheet::CWhiteBackgroundProvider
{
	DECLARE_DYNAMIC(CDlgCommonOption)

public:
	CDlgCommonOption();   // ��׼���캯��
	virtual ~CDlgCommonOption();

// �Ի�������
	enum { IDD = IDD_DLG_COMMON_OPTION };

	CMFCPropertyGridCtrl m_wndPropertyGrid;

	//����ѡ��
	BOOL m_bUpdateEveryTime;
	
	
public:

	void GetOption();
	BOOL IsModify(){ return m_wndPropertyGrid.IsMarkModifiedProperties();};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
