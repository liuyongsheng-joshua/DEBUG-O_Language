#pragma once

#include "./Controls/TreePropSheet/ResizablePage.h"
#include "./Controls/TreePropSheet/TreePropSheetUtil.hpp"

// CDlgDoasmOption �Ի���

class CDlgDoasmOption 
: public CResizablePage,
  public TreePropSheet::CWhiteBackgroundProvider
{
	DECLARE_DYNAMIC(CDlgDoasmOption)

public:
	CDlgDoasmOption();   // ��׼���캯��
	virtual ~CDlgDoasmOption();

// �Ի�������
	enum { IDD = IDD_DLG_DOASM_OPTION };

	CMFCPropertyGridCtrl m_wndPropertyGrid;

	//�����ѡ��
	CString m_strDoasmPath;
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
