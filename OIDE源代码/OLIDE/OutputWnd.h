
#pragma once

/////////////////////////////////////////////////////////////////////////////
// COutputList ����

class COutputList : public CListBox
{
// ����
public:
	COutputList();

// ʵ��
public:
	virtual ~COutputList();

protected:
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditCopy();
	afx_msg void OnEditClear();
	afx_msg void OnViewOutput();

	DECLARE_MESSAGE_MAP()
};

#include "./Controls/RichEdit/RichEdit.h"

class COutputBuild : public CRichEdit
{
	// ����
public:
	COutputBuild();

	void Clear();

	// ʵ��
public:
	virtual ~COutputBuild();

protected:
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditCopy();
	afx_msg void OnEditClear();
	afx_msg void OnViewOutput();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()
};

class COutputWnd : public CDockablePane
{
// ����
public:
	COutputWnd();

// ����
protected:
	CFont m_Font;
	
	COutputBuild m_wndOutputPaneBuild;

protected:	
	void AdjustHorzScroll(CListBox& wndListBox);

public:

	void Clear();
	void InsertText(const CString& strMsg);	

	COutputBuild* GetOutputBuildWnd(){ return &m_wndOutputPaneBuild;}

	void SetBackgroundColor(COLORREF colorBackGround)
	{
		m_wndOutputPaneBuild.SetBackgroundColor(FALSE,colorBackGround);
	}

// ʵ��
public:
	virtual ~COutputWnd();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()
};

