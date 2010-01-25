#pragma once

#include "./Controls/TreePropSheet/ResizablePage.h"
#include "./Controls/TreePropSheet/TreePropSheetUtil.hpp"

// CDlgLinkOption �Ի���

class CDlgLinkOption 
: public CResizablePage,
  public TreePropSheet::CWhiteBackgroundProvider
{
	DECLARE_DYNAMIC(CDlgLinkOption)

public:
	CDlgLinkOption();   // ��׼���캯��
	virtual ~CDlgLinkOption();

// �Ի�������
	enum { IDD = IDD_DLG_LINK_OPTION };

	CMFCPropertyGridCtrl m_wndPropertyGrid;

	//����ѡ��
	CString m_strLinkerFileName;
	
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
