#pragma once

#include "./Controls/TreePropSheet/ResizablePage.h"
#include "./Controls/TreePropSheet/TreePropSheetUtil.hpp"

// CDlgOasmOption �Ի���

class CDlgOasmOption 
: public CResizablePage,
  public TreePropSheet::CWhiteBackgroundProvider
{
	DECLARE_DYNAMIC(CDlgOasmOption)

public:
	CDlgOasmOption();   // ��׼���캯��
	virtual ~CDlgOasmOption();

// �Ի�������
	enum { IDD = IDD_DLG_OASM_OPTION };

	CMFCPropertyGridCtrl m_wndPropertyGrid;

	//���ѡ��
	CString m_strOasmPath;
	CString m_strOasmLanguagePath;
	
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
