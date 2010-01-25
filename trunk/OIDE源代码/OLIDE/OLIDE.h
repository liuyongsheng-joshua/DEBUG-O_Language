
// OLIDE.h : OLIDE Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// COLIDEApp:
// �йش����ʵ�֣������ OLIDE.cpp
//

class COLIDEApp : public CWinAppEx
{
public:
	COLIDEApp();

private:

	long m_lVersion1;
	long m_lVersion2;
	long m_lVersion3;
	long m_lVersion4;

	BOOL ReadVersionInfo(CString& strVersion);

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	HINSTANCE m_hSciDLL;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	void CheckNewVersion();
	void SetCurVersion(long lVersion1,long lVersion2,long lVersion3,long lVersion4);
	void GetCurVersion(long& lVersion1,long& lVersion2,long& lVersion3,long& lVersion4);

	CDocument* GetDocument(const CString& strPath);
	void SaveDocument(const CString& strPathName,BOOL bIsFloder = FALSE);
	void CloseDocument(const CString& strPathName,BOOL bIsFloder = FALSE);
	
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();	
};

extern COLIDEApp theApp;
