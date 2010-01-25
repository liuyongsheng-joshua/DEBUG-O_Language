#pragma once

#include "./Controls/TreePropSheet/ResizablePage.h"
#include "./Controls/TreePropSheet/TreePropSheetUtil.hpp"

// CDlgOMLOption �Ի���

class CDlgOMLOption 
: public CResizablePage,
  public TreePropSheet::CWhiteBackgroundProvider
{
	DECLARE_DYNAMIC(CDlgOMLOption)

public:
	CDlgOMLOption();   // ��׼���캯��
	virtual ~CDlgOMLOption();

// �Ի�������
	enum { IDD = IDD_DLG_OML_OPTION };

	CMFCPropertyGridCtrl m_wndPropertyGrid;

	//���ѡ��
	CString m_strOMLPath;
	CString m_strOMLLanguagePath;
	
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
