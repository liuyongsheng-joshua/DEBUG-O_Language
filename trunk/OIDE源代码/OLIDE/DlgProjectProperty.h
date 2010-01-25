#pragma once

#include "./Controls/TreePropSheet/ResizableDialog.h"
#include "./Controls/TreePropSheet/TreePropSheetEx.h"
#include "./Controls/TreePropSheet/TreePropSheetSplitter.h"
#include "./Controls/TreePropSheet/TreePropSheetBordered.h"

#include "./Data/SolutionProperty.h"
#include "DlgLinkProperty.h"

// CDlgProjectProperty �Ի���

class CDlgProjectProperty : public CResizableDialog
{
	DECLARE_DYNAMIC(CDlgProjectProperty)

public:
	CDlgProjectProperty(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgProjectProperty();

// �Ի�������
	enum { IDD = IDD_DLG_SYSTEM_OPTION };

private:

	TreePropSheet::CTreePropSheetEx m_sheetItem;	

public:

	CDlgLinkProperty m_dlgLinkProperty;	

private:

	bool RegisterSheet(UINT nID, CPropertySheet& rSheet);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual INT_PTR DoModal();
	afx_msg void OnBnClickedOk();
};
