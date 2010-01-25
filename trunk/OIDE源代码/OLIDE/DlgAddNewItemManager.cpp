// DlgAddNewItemManager.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgAddNewItemManager.h"
#include "./Common/Global.h"
#include ".\dlgaddnewitemmanager.h"

// CDlgAddNewItemManager �Ի���

IMPLEMENT_DYNAMIC(CDlgAddNewItemManager, CResizableDialog)
CDlgAddNewItemManager::CDlgAddNewItemManager(CWnd* pParent /*=NULL*/)
	: CResizableDialog(CDlgAddNewItemManager::IDD, pParent)
	, m_strItemPath(_T(""))
	, m_strItemName(_T(""))
	, m_strItemFileName(_T(""))
{
	m_nAddItemType = NEW_ITEM_TYPE_NULL;
	m_bBrowsePath = TRUE;
}

CDlgAddNewItemManager::~CDlgAddNewItemManager()
{
}

void CDlgAddNewItemManager::DoDataExchange(CDataExchange* pDX)
{
	CResizableDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_ITEM_PATH, m_strItemPath);
	DDX_Text(pDX, IDC_EDIT_ITEM_NAME, m_strItemName);
	DDX_Control(pDX, IDC_COMBO_ITEM_PATH, m_comboxItemPath);
}


BEGIN_MESSAGE_MAP(CDlgAddNewItemManager, CResizableDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_GET_PATH, OnBnClickedButtonGetPath)
END_MESSAGE_MAP()


// CDlgAddNewItemManager ��Ϣ�������

bool CDlgAddNewItemManager::RegisterSheet(UINT nID, CPropertySheet& rSheet)
{
	CWnd* pWnd = GetDlgItem( nID );
	if( !pWnd )
	{
		ASSERT( FALSE );
		return false;
	}

	rSheet.Create( this, WS_CHILD | WS_VISIBLE , 0 );

	if( 0 != rSheet.GetPageCount() )
	{
		rSheet.ModifyStyleEx( 0, WS_EX_CONTROLPARENT );
		rSheet.ModifyStyle( 0, WS_TABSTOP );

		//CRect rcSheet;
		//pWnd->GetWindowRect( &rcSheet );
		//ScreenToClient( &rcSheet );
		//		rSheet.SetWindowPos( NULL, rcSheet.left, rcSheet.top, 0, 0, SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE );
		//rSheet.SetWindowPos( NULL, 0, 0, 0, 0, SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE );

		CRect rect;
		//GetClientRect( &rect );
		GetDlgItem( nID )->GetWindowRect( rect );
		ScreenToClient( rect );
		rect.right += 5;
		rSheet.MoveWindow(rect);
	}

	return true;
}

BOOL CDlgAddNewItemManager::OnInitDialog()
{
	CResizableDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//���ҳ
	m_sheetItem.AddPage( &m_pageNewSolution );	
	m_sheetItem.AddPage( &m_pageNewProject );
	m_sheetItem.AddPage( &m_pageNewFile);
	
	m_pageNewSolution.SetHasWhiteBackground(true);
	m_pageNewProject.SetHasWhiteBackground(true);
	m_pageNewFile.SetHasWhiteBackground(true);

	m_sheetItem.SetTreeViewMode( TRUE, TRUE, TRUE );
	m_sheetItem.SetIsResizable( true );
	RegisterSheet( IDC_TREE_PROP_ADD_ITEM_RECT, m_sheetItem );		
	
	// ���ÿؼ�ê��
	AddAnchor( m_sheetItem, TOP_LEFT, BOTTOM_RIGHT );

	AddAnchor( IDC_STATIC_ITEM_NAME,BOTTOM_LEFT );
	AddAnchor( IDC_STATIC_ITEM_PATH,BOTTOM_LEFT );
	AddAnchor( IDC_EDIT_ITEM_NAME,BOTTOM_LEFT, BOTTOM_RIGHT );
	AddAnchor( IDC_COMBO_ITEM_PATH, BOTTOM_LEFT,BOTTOM_RIGHT );
	AddAnchor( IDC_BUTTON_GET_PATH, BOTTOM_RIGHT );

	AddAnchor( IDOK, BOTTOM_RIGHT );
	AddAnchor( IDCANCEL, BOTTOM_RIGHT );

	//�������
	if(m_bBrowsePath == FALSE)
	{
		m_comboxItemPath.EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_GET_PATH)->EnableWindow(FALSE);
	}
	else
	{
		m_comboxItemPath.SetMaxHistoryItems(50);
		m_comboxItemPath.SetDropSize(20);
		m_comboxItemPath.SetCheckAccess(TRUE);
		m_comboxItemPath.LoadHistory(_T("FolderHistory"), _T("Folder"));
	}	

	if(m_strItemPath.IsEmpty() && (m_comboxItemPath.GetCount() > 0))
	{		
		CString strTemp;
		m_comboxItemPath.GetLBText(0, strTemp);
		m_comboxItemPath.SetWindowText(strTemp);
		UpdateData(TRUE);
	}	

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

INT_PTR CDlgAddNewItemManager::DoModal()
{
	// TODO: �ڴ����ר�ô����/����û���

	return CResizableDialog::DoModal();
}

void CDlgAddNewItemManager::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CResizableDialog::OnShowWindow(bShow, nStatus);

	// TODO: �ڴ˴������Ϣ����������

	SetBeginActivePage();		
}

void CDlgAddNewItemManager::SetBeginActivePage()
{
	switch(m_nAddItemType)
	{
	case NEW_ITEM_TYPE_SOLUCTION:
		m_sheetItem.SetActivePage(NEW_ITEM_PAGE_INDEX_SOLUTION);		
		break;
	case NEW_ITEM_TYPE_PROJECT_WIN32_WINDOWS:
	case NEW_ITEM_TYPE_PROJECT_WIN32_CONSOLE:
	case NEW_ITEM_TYPE_PROJECT_WIN32_DLL:
	case NEW_ITEM_TYPE_PROJECT_WIN32_LIB:
		m_sheetItem.SetActivePage(NEW_ITEM_PAGE_INDEX_PROJECT);		
		break;
	case NEW_ITEM_TYPE_PROJECT_OML_CODE_FILE:
	case NEW_ITEM_TYPE_PROJECT_OML_HEAD_FILE:
	case NEW_ITEM_TYPE_PROJECT_OASM_CODE_FILE:
	case NEW_ITEM_TYPE_PROJECT_OASM_HEAD_FILE:
		m_sheetItem.SetActivePage(NEW_ITEM_PAGE_INDEX_FILE);		
		break;
	default:
		break;
	}

	m_pageNewFile.SetBeginNewItemType(m_nAddItemType);
}

void CDlgAddNewItemManager::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	int nActivePageIndex = m_sheetItem.GetActiveIndex();
	switch(nActivePageIndex)
	{
	case NEW_ITEM_PAGE_INDEX_SOLUTION:
		m_nAddItemType = m_pageNewSolution.GetAddNewItemType();
		break;
	case NEW_ITEM_PAGE_INDEX_PROJECT:
		m_nAddItemType = m_pageNewProject.GetAddNewItemType();
		break;
	case NEW_ITEM_PAGE_INDEX_FILE:
		m_nAddItemType = m_pageNewFile.GetAddNewItemType();
		break;
	default:
		m_nAddItemType = NEW_ITEM_TYPE_NULL;
		break;
	}

	if(!InitNewItem())
		return;

	CString strFolder = _T("");
	m_comboxItemPath.GetWindowText(strFolder);
	/*if (_taccess(strFolder, 00) == -1)
	{
		CString strMessage = _T("");
		strMessage.Format(_T("The folder '%s' isn't accessible."), strFolder);
		AfxMessageBox(strMessage);
		return;
	}*/
	m_comboxItemPath.SaveHistory(TRUE);

	//�ɹ�����OK
	OnOK();
}

//��ʼ���½���Ŀ
bool CDlgAddNewItemManager::InitNewItem()
{
	bool bResult = false;

	switch(m_nAddItemType)
	{
	case NEW_ITEM_TYPE_SOLUCTION:
		bResult = InitNewSolution();
		break;
	case NEW_ITEM_TYPE_PROJECT_WIN32_WINDOWS:
	case NEW_ITEM_TYPE_PROJECT_WIN32_CONSOLE:
	case NEW_ITEM_TYPE_PROJECT_WIN32_DLL:
	case NEW_ITEM_TYPE_PROJECT_WIN32_LIB:
		bResult = InitNewProject();
		break;
	case NEW_ITEM_TYPE_PROJECT_OML_CODE_FILE:
	case NEW_ITEM_TYPE_PROJECT_OML_HEAD_FILE:		
	case NEW_ITEM_TYPE_PROJECT_OASM_CODE_FILE:
	case NEW_ITEM_TYPE_PROJECT_OASM_HEAD_FILE:
		bResult = InitNewProjectFile(m_nAddItemType);
		break;
	default:
		break;
	}

	return bResult;
}

//��ʼ���½��������
bool CDlgAddNewItemManager::InitNewSolution()
{
	CString strTemp;

	if(m_strItemName.IsEmpty())
	{
		strTemp = _T("�������Ʋ���Ϊ��");
		AfxMessageBox(strTemp);
		GetDlgItem(IDC_EDIT_ITEM_NAME)->SetFocus();
		return false;
	}

	if(m_strItemPath.IsEmpty())
	{
		strTemp = _T("�����ļ�·������Ϊ��");
		AfxMessageBox(strTemp);
		GetDlgItem(IDC_COMBO_ITEM_PATH)->SetFocus();
		return false;
	}

	//�����ļ���
	CString strSolutionFileName;
	strSolutionFileName = m_strItemPath;
	if(strSolutionFileName.Right(1) != _T('\\'))
	{
		strSolutionFileName += _T('\\');
	}
	strSolutionFileName += m_strItemName;
	//�ж��ļ����Ƿ���ڣ�����������򴴽��ļ���
	if(!FileExist(strSolutionFileName,true))
	{
		if(!::CreateDirectory(strSolutionFileName,NULL))
		{
			strTemp = strSolutionFileName + _T(" �ļ��д���ʧ��");
			AfxMessageBox(strTemp);
			GetDlgItem(IDC_COMBO_ITEM_PATH)->SetFocus();
			return false;
		}
	}

	//���ɽ��������
	strSolutionFileName += _T('\\');
	strSolutionFileName += m_strItemName;
	strSolutionFileName += _T(".osl");
	//�ж��ļ��Ƿ���ڣ������������ʾ����
	if(FileExist(strSolutionFileName))
	{
		strTemp =  strSolutionFileName + _T(" �����Ѿ����ڣ����������뷽�����ƣ�");
		AfxMessageBox(strTemp);
		GetDlgItem(IDC_EDIT_ITEM_NAME)->SetFocus();
		return false;
	}

	m_strItemFileName = strSolutionFileName;

	return true;
}

//��ʼ���½�����
bool CDlgAddNewItemManager::InitNewProject()
{
	CString strTemp;

	if(m_strItemName.IsEmpty())
	{
		strTemp = _T("�������Ʋ���Ϊ��");
		AfxMessageBox(strTemp);
		GetDlgItem(IDC_EDIT_ITEM_NAME)->SetFocus();
		return false;
	}

	if(m_strItemPath.IsEmpty())
	{
		strTemp = _T("�����ļ�·������Ϊ��");
		AfxMessageBox(strTemp);
		GetDlgItem(IDC_COMBO_ITEM_PATH)->SetFocus();
		return false;
	}

	//�����ļ���
	CString strProjectFileName;
	strProjectFileName = m_strItemPath;
	if(strProjectFileName.Right(1) != _T('\\'))
	{
		strProjectFileName += _T('\\');
	}
	strProjectFileName += m_strItemName;
	//�ж��ļ����Ƿ���ڣ�����������򴴽��ļ���
	if(!FileExist(strProjectFileName,true))
	{
		if(!::CreateDirectory(strProjectFileName,NULL))
		{
			strTemp = strProjectFileName + _T(" �ļ��д���ʧ��");
			AfxMessageBox(strTemp);
			GetDlgItem(IDC_COMBO_ITEM_PATH)->SetFocus();
			return false;
		}
	}

	//���ɹ�����
	strProjectFileName += _T('\\');	
	CString strProjectFloder = strProjectFileName;
	strProjectFileName += m_strItemName;	
	strProjectFileName += _T(".opr");
	//�ж��ļ��Ƿ���ڣ������������ʾ����
	if(FileExist(strProjectFileName))
	{
		strTemp =  strProjectFileName + _T(" �����Ѿ����ڣ����������빤�����ƣ�");
		AfxMessageBox(strTemp);
		GetDlgItem(IDC_EDIT_ITEM_NAME)->SetFocus();
		return false;
	}
	m_strItemFileName = strProjectFileName;

	//�������������ļ���	
	::CreateDirectory(strProjectFloder + _T("����"),NULL);
	::CreateDirectory(strProjectFloder + _T("��Դ"),NULL);
	::CreateDirectory(strProjectFloder + _T("����"),NULL);
	::CreateDirectory(strProjectFloder + _T("���"),NULL);
	
	return true;
}

//��ʼ���½������ļ�
bool CDlgAddNewItemManager::InitNewProjectFile(int nFileType)
{
	CString strTemp;

	if(m_strItemName.IsEmpty())
	{
		strTemp = _T("�ļ����Ʋ���Ϊ��");
		AfxMessageBox(strTemp);
		GetDlgItem(IDC_EDIT_ITEM_NAME)->SetFocus();
		return false;
	}

	if(m_strItemPath.IsEmpty())
	{
		strTemp = _T("�ļ�·������Ϊ��");
		AfxMessageBox(strTemp);
		GetDlgItem(IDC_COMBO_ITEM_PATH)->SetFocus();
		return false;
	}

	CString strExtName;
	switch(nFileType)
	{
	case NEW_ITEM_TYPE_PROJECT_OML_CODE_FILE:
		strExtName =  _T(".omp");
		break;
	case NEW_ITEM_TYPE_PROJECT_OML_HEAD_FILE:
		strExtName =  _T(".omh");
		break;
	case NEW_ITEM_TYPE_PROJECT_OASM_CODE_FILE:
		strExtName =  _T(".oam");
		break;
	case NEW_ITEM_TYPE_PROJECT_OASM_HEAD_FILE:
		strExtName =  _T(".oah");
		break;
	}
		
	//�����ļ���
	CString strObjectFileName;
	strObjectFileName = m_strItemPath;
	if(strObjectFileName.Right(1) != _T('\\'))
	{
		strObjectFileName += _T('\\');
	}

	if(m_strItemName.Right(4) != strExtName)
	{
		m_strItemName += strExtName;
		UpdateData(FALSE);
	}
	strObjectFileName += m_strItemName;

	//�ж��ļ��Ƿ���ڣ������������ʾ����
	if(FileExist(strObjectFileName))
	{
		strTemp =  strObjectFileName + _T(" �ļ��Ѿ����ڣ������������ļ����ƣ�");
		AfxMessageBox(strTemp);
		GetDlgItem(IDC_EDIT_ITEM_NAME)->SetFocus();
		return false;
	}

	m_strItemFileName = strObjectFileName;

	return true;
}

void CDlgAddNewItemManager::SetAddNewItem(int nAddItemType,TCHAR* pchPath,TCHAR* pchName,BOOL bBrowsePath)
{
	m_nAddItemType = nAddItemType;
	if(pchPath != NULL)
	{
		m_strItemPath = pchPath;		
	}
	if(pchName != NULL)
	{
		m_strItemName = pchName;
	}	

	m_bBrowsePath = bBrowsePath;
}

int CDlgAddNewItemManager::GetAddNewItemType()
{
	return m_nAddItemType;
}


void CDlgAddNewItemManager::OnBnClickedButtonGetPath()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//int nOsVersion = GetOSVersion();

	CXFolderDialog dlg(m_strItemPath);
	/*dlg.SetOsVersion((CXFolderDialog::XFILEDIALOG_OS_VERSION) 0);
	CXFolderDialog::XFILEDIALOG_OS_VERSION eVer = dlg.GetOsVersion();
	ASSERT(eVer == nOsVersion);*/
	// set initial list view mode
	int nListViewMode = 0;

	//if (IsXP())
	//{
	//	nListViewMode = m_XpModes[m_nListViewModeIndex].nMode;
	//}
	//else if (IsVista())
	//{
	//	nListViewMode = m_VistaModes[m_nListViewModeIndex].nMode;
	//}
	//else
	//{
	//	nListViewMode = -1;		// no persistence on other OS
	//	dlg.EnableRegistry(FALSE);
	//}

	//if ((nListViewMode == 0) && m_bUseRegistry)
	dlg.EnableRegistry(TRUE);

	dlg.SetViewMode(0);

	dlg.SetTitle(_T("ѡ��Ŀ¼"));	// defaults to "Select Folder"
	if (dlg.DoModal() != IDOK)
		return ;

	m_strItemPath = dlg.GetPath();
	m_comboxItemPath.SetWindowText(m_strItemPath);
}
