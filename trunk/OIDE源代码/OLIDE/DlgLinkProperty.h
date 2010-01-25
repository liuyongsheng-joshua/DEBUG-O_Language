#pragma once

#include "./Controls/TreePropSheet/ResizablePage.h"
#include "./Controls/TreePropSheet/TreePropSheetUtil.hpp"

// CDlgLinkProperty �Ի���

class CDlgLinkProperty 
: public CResizablePage,
  public TreePropSheet::CWhiteBackgroundProvider
{
	DECLARE_DYNAMIC(CDlgLinkProperty)

public:
	CDlgLinkProperty();   // ��׼���캯��
	virtual ~CDlgLinkProperty();

// �Ի�������
	enum { IDD = IDD_DLG_LINK_PROPERTY };

	CMFCPropertyGridCtrl m_wndPropertyGrid;

	//����ѡ��	
	CString m_strCodeDir;
	CString m_strResourceDir;
	int m_nLinkProgrammType;
	int m_nLinkSubSystem;	
	CString m_strDebugMiddleFileDir;
	CString m_strDebugExeFileName;
	CString m_strReleaseMiddleFileDir;
	CString m_strReleaseExeFileName;

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
