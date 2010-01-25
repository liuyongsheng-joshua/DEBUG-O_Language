
#include "stdafx.h"
#include "mainfrm.h"
#include "FileView.h"
#include "Resource.h"
#include "OLIDE.h"
#include "DlgAddNewItemManager.h"
#include "./Common/Global.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileView

CFileView::CFileView()
{
}

CFileView::~CFileView()
{
}

BEGIN_MESSAGE_MAP(CFileView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_PROPERTIES, OnProperties)	
	ON_COMMAND(ID_OPEN_WITH, OnFileOpenWith)
	ON_COMMAND(ID_DUMMY_COMPILE, OnDummyCompile)	
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_NEW_SOLUTION, &CFileView::OnNewSolution)
	ON_COMMAND(ID_CLOSE_SOLUTION, &CFileView::OnCloseSolution)
	ON_COMMAND(ID_NEW_PROJECT, &CFileView::OnNewProject)	
	ON_COMMAND(ID_ADD_PROJECT, &CFileView::OnAddProject)
	ON_COMMAND(ID_REMOVE_PROJECT, &CFileView::OnRemoveProject)
	ON_WM_DESTROY()
	ON_COMMAND(ID_DELETE_FILE, &CFileView::OnDeleteFile)
	ON_COMMAND(ID_ADD_FLODER, &CFileView::OnAddFloder)
	ON_COMMAND(ID_OPEN_CUR_FLODER, &CFileView::OnOpenCurFloder)
	ON_COMMAND(ID_RENAME, &CFileView::OnReName)
	ON_COMMAND(ID_NEW_IN_PROJECT_FILE, &CFileView::OnNewInProjectFile)
	ON_COMMAND(ID_OPEN_IN_PROJECT_FILE, &CFileView::OnOpenInProjectFile)
	ON_COMMAND(ID_REFRESH, &CFileView::OnRefresh)	
	ON_COMMAND(ID_BUILD_CUR_PROJECT, &CFileView::OnBuildCurProject)
	ON_COMMAND(ID_REBUILD_CUR_PROJECT, &CFileView::OnReBuildCurProject)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar ��Ϣ�������

int CFileView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();
	
	// ������ͼ:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS | TVS_EDITLABELS;

	if (!m_wndSolutionTree.Create(dwViewStyle, rectDummy, this, 4))
	{
		TRACE0("δ�ܴ����ļ���ͼ\n");
		return -1;      // δ�ܴ���
	}

	CBitmap bm;	
	if (!m_FileViewImages.Create(16,16,TRUE | ILC_COLOR24,8,0))
		return 0;

	bm.LoadBitmap(IDB_SOLUTION_TREE);
	m_FileViewImages.Add(&bm,(CBitmap*)NULL);
	bm.Detach();	

	// ������ͼͼ��:
	//m_FileViewImages.Create(IDB_FILE_VIEW, 16, 0, RGB(255, 0, 255));
	m_wndSolutionTree.SetImageList(&m_FileViewImages, TVSIL_NORMAL);

	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_EXPLORER);
	m_wndToolBar.LoadToolBar(IDR_EXPLORER, 0, 0, TRUE /* ������*/);

	OnChangeVisualStyle();

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	m_wndToolBar.SetOwner(this);

	// �������ͨ���˿ؼ�·�ɣ�������ͨ�������·��:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);	
	
	AdjustLayout();

	return 0;
}

void CFileView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CFileView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CTreeCtrl* pWndTree = (CTreeCtrl*) &m_wndSolutionTree;
	ASSERT_VALID(pWndTree);

	if (pWnd != pWndTree)
	{
		CDockablePane::OnContextMenu(pWnd, point);
		return;
	}

	if (point != CPoint(-1, -1))
	{
		// ѡ���ѵ�������:
		CPoint ptTree = point;
		pWndTree->ScreenToClient(&ptTree);

		UINT flags = 0;
		HTREEITEM hTreeItem = pWndTree->HitTest(ptTree, &flags);
		if (hTreeItem != NULL)
		{
			pWndTree->SelectItem(hTreeItem);
		}
	}
	
	COLFileNode* pOLFileNode = m_wndSolutionTree.GetCurItemNode();
	if(pOLFileNode != NULL)
	{
		int nMenuID = 0;
		switch(pOLFileNode->m_enumType)
		{
		case COLFileNode::ONT_SOLUTION:
			nMenuID = IDR_POPUP_SOLUTION;
			break;
		case COLFileNode::ONT_PROJECT:
			nMenuID = IDR_POPUP_PROJECT;
			break;
		case COLFileNode::ONT_FLODER:
			nMenuID = IDR_POPUP_FLODER;
			break;
		case COLFileNode::ONT_FILE:
			nMenuID = IDR_POPUP_FILE;
			break;
		default:
			ASSERT(FALSE);
			break;
		}
		pWndTree->SetFocus();
		theApp.GetContextMenuManager()->ShowPopupMenu(nMenuID, point.x, point.y, this, TRUE);
	}	
}

void CFileView::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndSolutionTree.SetWindowPos(NULL, rectClient.left + 1, rectClient.top + cyTlb + 1, rectClient.Width() - 2, rectClient.Height() - cyTlb - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}

void CFileView::OnProperties()
{
	COLFileNode* pOLFileNode = m_wndSolutionTree.GetCurItemNode();
	if(pOLFileNode == NULL)
		return;

	if(pOLFileNode->IsProjectNode())
	{
		SetProjectProperty((CProjectProperty*)pOLFileNode->m_pProperty,pOLFileNode->m_strPathName);
	}	
}

void CFileView::OnFileOpenWith()
{
	// TODO: �ڴ˴���������������
}

void CFileView::OnDummyCompile()
{
	// TODO: �ڴ˴���������������
}

void CFileView::OnPaint()
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������

	CRect rectTree;
	m_wndSolutionTree.GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}

void CFileView::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	m_wndSolutionTree.SetFocus();
}

void CFileView::OnChangeVisualStyle()
{
	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_EXPLORER_24 : IDR_EXPLORER, 0, 0, TRUE /* ���� */);

	m_FileViewImages.DeleteImageList();

	/*UINT uiBmpId = theApp.m_bHiColorIcons ? IDB_FILE_VIEW_24 : IDB_FILE_VIEW;

	CBitmap bmp;
	if (!bmp.LoadBitmap(uiBmpId))
	{
		TRACE(_T("�޷�����λͼ: %x\n"), uiBmpId);
		ASSERT(FALSE);
		return;
	}

	BITMAP bmpObj;
	bmp.GetBitmap(&bmpObj);

	UINT nFlags = ILC_MASK;

	nFlags |= (theApp.m_bHiColorIcons) ? ILC_COLOR24 : ILC_COLOR4;

	m_FileViewImages.Create(16, bmpObj.bmHeight, nFlags, 0, 0);
	m_FileViewImages.Add(&bmp, RGB(255, 0, 255));*/

	CBitmap bm;	
	if (!m_FileViewImages.Create(16,16,TRUE | ILC_COLOR24,8,0))
		return ;

	bm.LoadBitmap(IDB_SOLUTION_TREE);
	m_FileViewImages.Add(&bm,(CBitmap*)NULL);
	bm.Detach();

	m_wndSolutionTree.SetImageList(&m_FileViewImages, TVSIL_NORMAL);
}


void CFileView::AddNewItem(TCHAR* pchPath,TCHAR* pchName,int nNewItemType,BOOL bBrowsePath)
{
	CDlgAddNewItemManager dlgAddNewItemManager;
	dlgAddNewItemManager.SetAddNewItem(nNewItemType,pchPath,pchName,bBrowsePath);

	if(dlgAddNewItemManager.DoModal() != IDOK)
		return;

	int nAddNewItemType = dlgAddNewItemManager.GetAddNewItemType();
	switch(nAddNewItemType)
	{
		//��ӽ������
	case NEW_ITEM_TYPE_SOLUCTION:
		AddNewSolution(dlgAddNewItemManager.m_strItemFileName,dlgAddNewItemManager.m_strItemName);
		break;
		//��ӹ���
	case NEW_ITEM_TYPE_PROJECT_WIN32_WINDOWS:
	case NEW_ITEM_TYPE_PROJECT_WIN32_CONSOLE:
	case NEW_ITEM_TYPE_PROJECT_WIN32_DLL:
	case NEW_ITEM_TYPE_PROJECT_WIN32_LIB:
		AddNewProject(dlgAddNewItemManager.m_strItemFileName,dlgAddNewItemManager.m_strItemName,nAddNewItemType);
		break;
		//����м����Դ����ļ�
	case NEW_ITEM_TYPE_PROJECT_OML_CODE_FILE:
		AddNewInProjectFile(dlgAddNewItemManager.m_strItemFileName,dlgAddNewItemManager.m_strItemName,"//O�м����Դ����ļ�\n");
		break;
		//����м�����ͷ�ļ�
	case NEW_ITEM_TYPE_PROJECT_OML_HEAD_FILE:		
		AddNewInProjectFile(dlgAddNewItemManager.m_strItemFileName,dlgAddNewItemManager.m_strItemName,"//O�м�����ͷ�ļ�\n");
		break;
		//��ӻ���ļ�
	case NEW_ITEM_TYPE_PROJECT_OASM_CODE_FILE:
		AddNewInProjectFile(dlgAddNewItemManager.m_strItemFileName,dlgAddNewItemManager.m_strItemName,"//O����ļ�\n");
		break;
		//��ӻ��ͷ�ļ�
	case NEW_ITEM_TYPE_PROJECT_OASM_HEAD_FILE:		
		AddNewInProjectFile(dlgAddNewItemManager.m_strItemFileName,dlgAddNewItemManager.m_strItemName,"//O���ͷ�ļ�\n");
		break;
	default:
		break;
	}
}

void CFileView::OnNewSolution()
{
	// TODO: �ڴ���������������

	if(HasSolution())
		return;

	AddNewItem(NULL,_T("Ĭ�Ϸ���"),NEW_ITEM_TYPE_SOLUCTION);
}

void CFileView::OnNewProject()
{
	// TODO: �ڴ���������������

	COLFileNode* pOLFileNode = m_wndSolutionTree.GetCurItemNode();
	if(pOLFileNode == NULL)
		return;

	//������Ƿ��������˳�
	if(!pOLFileNode->IsSolutionNode())
		return;

	CString strProjectPath = pOLFileNode->m_strPathName;
	strProjectPath = strProjectPath.Left(strProjectPath.ReverseFind(_T('\\'))+1);
	AddNewItem((LPTSTR)(LPCTSTR)strProjectPath,_T("Ĭ�Ϲ���"),NEW_ITEM_TYPE_PROJECT_WIN32_WINDOWS);

	OnRefresh();
	m_wndSolutionTree.Expand( m_wndSolutionTree.GetCurItem(),TVE_EXPAND );
}


#include "./SolutionTree.h"
#include "./OLanguage/OLSolutionFile.h"
#include "./OLanguage/OLProjectFile.h"
#include "./OLanguage/OLFile.h"
#include "./Common/Global.h"
#include "./Common/UnicodeCovert.h"
#include "./DlgProjectProperty.h"

void CFileView::AddNewSolution(CString& strSolutionFilePath,CString& strSolutionName)
{
	COLSolutionFile OLSolutionFile;
	char chName[MAX_PATH];
	CopyStr(chName,MAX_PATH,strSolutionFilePath);
	if(!OLSolutionFile.CreateSolutionFile(chName,true))
	{
		CString strTemp;
		strTemp = strSolutionFilePath + _T("��������ʧ��");
		AfxMessageBox(strTemp);
		return ;
	}

	InsertSolutionNode(strSolutionFilePath,strSolutionName);
}

//�򿪷���
bool CFileView::OpenSolution(const CString& strSolutionFileName)
{
	COLFileNode* pOLFileNode = m_wndSolutionTree.GetSolutionNode();
	if(pOLFileNode != NULL)
	{
		//�жϱ������Ƿ��Ѿ���
		if(pOLFileNode->m_strPathName == strSolutionFileName)
		{
			m_wndSolutionTree.SelectItem(pOLFileNode->m_hItemTree);
			return true;
		}
		else
		{
			CloseSolution();
		}		
	}

	//��ȡ�����ļ�
	COLSolutionFile OLSolutionFile;
	char chName[MAX_PATH];
	CopyStr(chName,MAX_PATH,strSolutionFileName);
	if(OLSolutionFile.ReadSolution(chName))
	{
		//��ӷ������
		HTREEITEM hSolutionTreeItem = InsertSolutionNode(strSolutionFileName,OLSolutionFile.GetSolutionName());
		if(hSolutionTreeItem == NULL)
			return false;

		//��ȡ���еĹ����ļ�
		CString strProjectFileName;
		COLProjectFileProperty projectFileProperty;
		while(OLSolutionFile.PopFrontProjectFileProperty(&projectFileProperty))
		{
			strProjectFileName = projectFileProperty.m_chProjectFileName;
			GetAbsolutePath(strSolutionFileName,strProjectFileName);

			//�򿪹����ļ�
			OpenProjectTreeNode(strProjectFileName,projectFileProperty.m_bIsExpand);
		}
	}

	return true;
}

void CFileView::OnCloseSolution()
{
	//�õ���ǰ�������
	COLFileNode* pOLFileNode = m_wndSolutionTree.GetSolutionNode();
	if(pOLFileNode)
	{
		//���淽��
		SaveSolutionTreeNode();

		//�رշ���
		CloseSolution();
	}	
}

void CFileView::CloseSolution()
{
	m_wndSolutionTree.CloseSolution();
}

HTREEITEM CFileView::InsertSolutionNode(const TCHAR* pchSolutionFileName,const TCHAR* pchSolutionName)
{	
	return m_wndSolutionTree.InsertSolution(pchSolutionFileName,pchSolutionName);
}

//��������ת����XML��㲢���浽�����ļ���
void CFileView::SaveSolutionTreeNode()
{
	COLFileNode* pOLFileNode = m_wndSolutionTree.GetSolutionNode();
	if(pOLFileNode == NULL)
		return;

	CString strSolutionPath = pOLFileNode->m_strPathName;

	COLSolutionFile OLSolutionFile;
	char chName[MAX_PATH];
	CopyStr(chName,MAX_PATH,pOLFileNode->m_strName);
	OLSolutionFile.SetSolutionName(chName);

	//�������еĹ����ļ�
	COLProjectFileProperty projectFileProperty;
	pOLFileNode = m_wndSolutionTree.GetItemNode(m_wndSolutionTree.GetChildItem(pOLFileNode->m_hItemTree));
	while(pOLFileNode)
	{
		if((pOLFileNode != NULL) && (pOLFileNode->IsProjectNode()))
		{
			//���ù���·��
			CString strTemp = pOLFileNode->m_strPathName;
			GetRelativePath(strSolutionPath,strTemp);
			CopyStr(projectFileProperty.m_chProjectFileName,MAX_PATH,strTemp);

			//���������չ��״̬���
			projectFileProperty.m_bIsExpand = 
			   ( TVIS_EXPANDED | TVIS_EXPANDPARTIAL) &	m_wndSolutionTree.GetItemState( pOLFileNode->m_hItemTree, TVIS_EXPANDED | TVIS_EXPANDPARTIAL )?true:false;

			//��ӹ��̽��
			OLSolutionFile.PushBackProjectFileProperty(&projectFileProperty);
		}

		pOLFileNode = m_wndSolutionTree.GetItemNode(m_wndSolutionTree.GetNextItem(pOLFileNode->m_hItemTree,TVGN_NEXT));
	}

	CopyStr(chName,MAX_PATH,strSolutionPath);
	OLSolutionFile.WriteSolution(chName);
}

void CFileView::AddNewProject(CString& strProjectFilePath,CString& strProjectName,int nProjectType)
{
	COLProjectFile OLProjectFile;
	char chName[MAX_PATH];
	CopyStr(chName,MAX_PATH,strProjectFilePath);
	if(!OLProjectFile.CreateProjectFile(chName,true))
	{
		CString strTemp;
		strTemp = strProjectFilePath + _T("���̴���ʧ��");
		AfxMessageBox(strTemp);
		return ;
	}	

	//��ӹ��̽��
	HTREEITEM hProjectTreeItem = InsertProjectNode(strProjectFilePath,strProjectName);

	//���ù��̵�Ĭ������
	CProjectProperty projectProperty;	
	projectProperty.SetDefaultProjectProperty(strProjectFilePath,strProjectName,nProjectType);

	m_wndSolutionTree.SetProjectProperty(hProjectTreeItem,projectProperty);

	//���淽������
	SaveProjectProperty(&projectProperty,strProjectFilePath);

	//�����̱��浽����
	SaveSolutionTreeNode();
}

void CFileView::OpenProjectTreeNode(const TCHAR* pchFileName,BOOL bIsExpand)
{
	COLProjectFile OLProjectFile;
	COLProjectProperty OLProjectProperty;	
	OLProjectProperty.m_pProjectBuildRecord = new COLProjectBuildRecord();

	char chName[MAX_PATH];
	CopyStr(chName,MAX_PATH,pchFileName);
	if(OLProjectFile.ReadProjectProperty(chName,&OLProjectProperty))
	{		
		CString strProjectName;
		strProjectName = OLProjectProperty.m_chProjectName;
		//��ӹ��̽��		
		HTREEITEM hProjectTreeItem = InsertProjectNode(pchFileName,strProjectName);
		if(hProjectTreeItem == NULL)
		{
			delete OLProjectProperty.m_pProjectBuildRecord;

			return;		
		}

		//���ù�������
		CProjectProperty projectProperty;
		projectProperty.m_strCodeDir                   = OLProjectProperty.m_chCodeDir;
		projectProperty.m_strResourceDir               = OLProjectProperty.m_chResourceDir;
		projectProperty.m_nProgramType                 = OLProjectProperty.m_nProgramType;		
		projectProperty.m_nLinkSubSystem               = OLProjectProperty.m_nLinkSubSystem;
		projectProperty.m_strDebugMiddleOutPutPath     = OLProjectProperty.m_chDebugMiddleOutPutPath;		
		projectProperty.m_strDebugOutPutFileName       = OLProjectProperty.m_chDebugOutPutFileName;		
		projectProperty.m_strReleaseMiddleOutPutPath   = OLProjectProperty.m_chReleaseMiddleOutPutPath;		
		projectProperty.m_strReleaseOutPutFileName     = OLProjectProperty.m_chReleaseOutPutFileName;		
		projectProperty.m_strProjectFilePath           = pchFileName;
		projectProperty.m_strProjectName               = OLProjectProperty.m_chProjectName;
		projectProperty.m_pProjectBuildRecord          = OLProjectProperty.m_pProjectBuildRecord;

		m_wndSolutionTree.SetProjectProperty(hProjectTreeItem,projectProperty);
		
		LoadProjectFile(hProjectTreeItem,pchFileName);

		if(bIsExpand)
		{
			m_wndSolutionTree.Expand(hProjectTreeItem,TVE_EXPAND);
		}		
	}
}

HTREEITEM CFileView::InsertProjectNode(const TCHAR* pchProjectFilePath,const TCHAR* pchProjectName)
{	
	return m_wndSolutionTree.InsertProject(pchProjectFilePath,pchProjectName);	
}

void CFileView::SaveProjectProperty(CProjectProperty* pProjectProperty,const CString& strProjectFileName)
{
	ASSERT(pProjectProperty);

	COLProjectProperty OLProjectProperty;	
	CopyStr(OLProjectProperty.m_chCodeDir,MAX_PATH,pProjectProperty->m_strCodeDir);	
	CopyStr(OLProjectProperty.m_chResourceDir,MAX_PATH,pProjectProperty->m_strResourceDir);	
	CopyStr(OLProjectProperty.m_chDebugMiddleOutPutPath,MAX_PATH,pProjectProperty->m_strDebugMiddleOutPutPath);	
	CopyStr(OLProjectProperty.m_chDebugOutPutFileName,MAX_PATH,pProjectProperty->m_strDebugOutPutFileName); 
	CopyStr(OLProjectProperty.m_chReleaseMiddleOutPutPath,MAX_PATH,pProjectProperty->m_strReleaseMiddleOutPutPath);	
	CopyStr(OLProjectProperty.m_chReleaseOutPutFileName,MAX_PATH,pProjectProperty->m_strReleaseOutPutFileName); 
	CopyStr(OLProjectProperty.m_chProjectName,MAX_PATH,pProjectProperty->m_strProjectName); 	
	OLProjectProperty.m_nProgramType = pProjectProperty->m_nProgramType; 
	OLProjectProperty.m_nLinkSubSystem = pProjectProperty->m_nLinkSubSystem; 
	OLProjectProperty.m_pProjectBuildRecord = pProjectProperty->m_pProjectBuildRecord;

	//���湤������
	COLProjectFile OLProjectFile;
	char chName[MAX_PATH];
	CopyStr(chName,MAX_PATH,strProjectFileName);
	OLProjectFile.WriteProjectProperty(chName,&OLProjectProperty);
}

//��������ת����XML��㲢���浽�����ļ���
void CFileView::SaveProjectTreeNode(HTREEITEM hProjectTreeItem)
{
	CProjectProperty* pProjectProperty  = m_wndSolutionTree.GetProjectProperty(hProjectTreeItem);
	if(pProjectProperty)
	{
		SaveProjectProperty(pProjectProperty,pProjectProperty->m_strProjectFilePath);
	}
}

//���ù�������
void CFileView::SetProjectProperty(CProjectProperty* pProjectProperty,const CString& strProjectFileName)
{
	ASSERT(pProjectProperty);

	CDlgProjectProperty dlgProjectProperty;
	dlgProjectProperty.m_dlgLinkProperty.m_strCodeDir = pProjectProperty->m_strCodeDir;
	dlgProjectProperty.m_dlgLinkProperty.m_strResourceDir = pProjectProperty->m_strResourceDir;
	dlgProjectProperty.m_dlgLinkProperty.m_nLinkProgrammType = pProjectProperty->m_nProgramType;
	dlgProjectProperty.m_dlgLinkProperty.m_nLinkSubSystem = pProjectProperty->m_nLinkSubSystem;	
	dlgProjectProperty.m_dlgLinkProperty.m_strDebugMiddleFileDir = pProjectProperty->m_strDebugMiddleOutPutPath;
	dlgProjectProperty.m_dlgLinkProperty.m_strDebugExeFileName = pProjectProperty->m_strDebugOutPutFileName;
	dlgProjectProperty.m_dlgLinkProperty.m_strReleaseMiddleFileDir = pProjectProperty->m_strReleaseMiddleOutPutPath;
	dlgProjectProperty.m_dlgLinkProperty.m_strReleaseExeFileName = pProjectProperty->m_strReleaseOutPutFileName;

	if(dlgProjectProperty.DoModal() == IDOK)
	{
		pProjectProperty->m_strCodeDir = dlgProjectProperty.m_dlgLinkProperty.m_strCodeDir;
		pProjectProperty->m_strResourceDir = dlgProjectProperty.m_dlgLinkProperty.m_strResourceDir;
		pProjectProperty->m_nProgramType = dlgProjectProperty.m_dlgLinkProperty.m_nLinkProgrammType;
		pProjectProperty->m_nLinkSubSystem = dlgProjectProperty.m_dlgLinkProperty.m_nLinkSubSystem;	
		pProjectProperty->m_strDebugMiddleOutPutPath = dlgProjectProperty.m_dlgLinkProperty.m_strDebugMiddleFileDir;
		pProjectProperty->m_strDebugOutPutFileName = dlgProjectProperty.m_dlgLinkProperty.m_strDebugExeFileName;
		pProjectProperty->m_strReleaseMiddleOutPutPath = dlgProjectProperty.m_dlgLinkProperty.m_strReleaseMiddleFileDir;
		pProjectProperty->m_strReleaseOutPutFileName = dlgProjectProperty.m_dlgLinkProperty.m_strReleaseExeFileName;

		SaveProjectProperty(pProjectProperty,strProjectFileName);
	}
}

void CFileView::AddNewInProjectFile(CString& strFilePath,CString& strFileName,char* lpText)
{
	HANDLE hFile = ::CreateFile(strFilePath,GENERIC_WRITE|GENERIC_READ,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	if(hFile != NULL)
	{
		if(lpText)
		{
			DWORD ddWrite;
			::WriteFile(hFile,lpText,strlen(lpText),&ddWrite,NULL);
		}
		
		CloseHandle(hFile);

		m_wndSolutionTree.InsertFile(m_wndSolutionTree.GetCurItem(),strFileName,strFilePath,TRUE);
		
		//���ļ�
		OnOpenInProjectFile();
	}
}

void CFileView::OnAddProject()
{
	// TODO: �ڴ���������������

	COLFileNode* pOLFileNode = m_wndSolutionTree.GetCurItemNode();
	if((pOLFileNode == NULL) || (!pOLFileNode->IsSolutionNode()))
		return;

	//�򿪶Ի���
	TCHAR szFilters[]= _T("O���Թ��� (*.opr)|*.opr||");
	CFileDialog fileDlg(TRUE, _T("my"), _T("*.opr"), OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, szFilters, this);

	CString strSolutionPath = pOLFileNode->m_strPathName;
	strSolutionPath = strSolutionPath.Left(strSolutionPath.ReverseFind(_T('\\')));
	fileDlg.m_ofn.lpstrInitialDir = strSolutionPath;
	fileDlg.m_ofn.lpstrTitle = _T("��ӹ���");
	if( fileDlg.DoModal() != IDOK)
		return;

	CString strProjectFileName = fileDlg.GetPathName();

	//�жϹ����Ƿ��Ѿ��ڷ����д�
	HTREEITEM hProjectItem = m_wndSolutionTree.GetProjectItemFromProjectFileName(strProjectFileName);
	if(hProjectItem != NULL)
	{
		m_wndSolutionTree.SelectItem(hProjectItem);
		return;
	}

	OpenProjectTreeNode(strProjectFileName,TRUE);

	//�����̱��浽����
	SaveSolutionTreeNode();
}

void CFileView::OnRemoveProject()
{
	// TODO: �ڴ���������������

	COLFileNode* pOLFileNode = m_wndSolutionTree.GetCurItemNode();
	if(pOLFileNode == NULL)
		return;

	//������ǹ��̾��˳�
	if(!pOLFileNode->IsProjectNode())
		return;

	m_wndSolutionTree.DeleteItem(m_wndSolutionTree.GetCurItem());

	SaveSolutionTreeNode();	
}

void CFileView::OnDestroy()
{
	SaveSolutionTreeNode();
	m_wndSolutionTree.SaveAllProject();

	CDockablePane::OnDestroy();	
}

void CFileView::OnDeleteFile()
{
	// TODO: �ڴ���������������

	//ɾ���ļ����ļ���
	m_wndSolutionTree.DeleteFloadOrFile(m_wndSolutionTree.GetCurItem());
}

void CFileView::OnAddFloder()
{
	// TODO: �ڴ���������������

	m_wndSolutionTree.AddProjectFloder();
}

void CFileView::OnOpenCurFloder()
{
	COLFileNode* pOLFileNode = m_wndSolutionTree.GetCurItemNode();
	//���ļ��н��
	if((pOLFileNode) && (pOLFileNode->IsFloderNode()))
	{
		ShellExecute(NULL,NULL,pOLFileNode->m_strPathName,NULL,NULL,SW_SHOW);
	}
}

void CFileView::OnReName()
{
	m_wndSolutionTree.EditLabel(m_wndSolutionTree.GetCurItem());
}

void CFileView::OnNewInProjectFile()
{
	// TODO: �ڴ���������������

	COLFileNode* pOLFileNode = m_wndSolutionTree.GetCurItemNode();
	if(pOLFileNode == NULL)
		return;

	//����ǹ��̻��ļ��н��
	if(pOLFileNode->IsProjectNode() || pOLFileNode->IsFloderNode())
	{
		AddNewItem((LPTSTR)(LPCTSTR)pOLFileNode->m_strPathName,_T("�����ļ�"),NEW_ITEM_TYPE_PROJECT_OML_CODE_FILE,FALSE);
	}
}

void CFileView::LoadProjectFile(HTREEITEM hProjectItem,const CString& strProjectPath)
{	
	ASSERT(hProjectItem);

	//�����ļ�
	BrowseFile(strProjectPath.Left(strProjectPath.ReverseFind(_T('\\'))),hProjectItem,TRUE);
}

void CFileView::BrowseFile(const CString& strDir,HTREEITEM hTreeParent,BOOL bIsProjectDir)
{
	CFileFind ff;
	CString szDir = strDir;

	if(szDir.Right(1) != _T("\\"))
	{
		szDir += _T("\\");
	}
	szDir += _T("*.*");
	
	BOOL res = ff.FindFile(szDir);
	while( res )
	{
		res = ff.FindNextFile();
		if(ff.IsDots())continue;

		if(ff.IsDirectory())
		{
			HTREEITEM hSubItem = m_wndSolutionTree.InsertFloder(hTreeParent,ff.GetFileName(),FALSE,FALSE);
			BrowseFile(ff.GetFilePath(),hSubItem,FALSE);

			continue;
		}

		//������ļ�
		if(!ff.IsDirectory())
		{		
			//����ǹ����ļ�
			if(bIsProjectDir && (GetFileExternName(ff.GetFilePath()) == _T("opr")))
			{				
				continue;
			}

			m_wndSolutionTree.InsertFile(hTreeParent,ff.GetFileName(),ff.GetFilePath());
		}
	}
	ff.Close();
}

void CFileView::OnRefresh()
{
	// TODO: �ڴ���������������

	COLFileNode* pOLFileNode = m_wndSolutionTree.GetCurItemNode();
	if(pOLFileNode == NULL)
		return;

	if(pOLFileNode->IsProjectNode())
	{
		m_wndSolutionTree.DelChild(pOLFileNode->m_hItemTree);
		LoadProjectFile(pOLFileNode->m_hItemTree,pOLFileNode->m_strPathName);
	}
	else if(pOLFileNode->IsFloderNode())
	{
		m_wndSolutionTree.DelChild(pOLFileNode->m_hItemTree);
		BrowseFile(pOLFileNode->m_strPathName,pOLFileNode->m_hItemTree,FALSE);
	}
}

BOOL CFileView::PreTranslateMessage(MSG* pMsg)
{
	// If edit control is visible in tree view control, when you send a
	// WM_KEYDOWN message to the edit control it will dismiss the edit
	// control. When the ENTER key was sent to the edit control, the
	// parent window of the tree view control is responsible for updating
	// the item's label in TVN_ENDLABELEDIT notification code.
	if (pMsg->message == WM_KEYDOWN &&
		pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		CEdit* edit = m_wndSolutionTree.GetEditControl();
		if (edit)
		{
			edit->SendMessage(WM_KEYDOWN, pMsg->wParam, pMsg->lParam);
			return TRUE;
		}
	}
	
	return CDockablePane::PreTranslateMessage(pMsg);
}

void CFileView::OnOpenInProjectFile()
{
	// TODO: �ڴ���������������
	
	m_wndSolutionTree.OpenProjectFile(m_wndSolutionTree.GetCurItem());
}


void CFileView::OnBuildCurProject()
{
	// TODO: �ڴ���������������

	::SendMessage(AfxGetMainWnd()->GetSafeHwnd(),WM_COMMAND,ID_BUILD_AND_LINK,NULL);
}

void CFileView::OnReBuildCurProject()
{
	// TODO: �ڴ���������������

	::SendMessage(AfxGetMainWnd()->GetSafeHwnd(),WM_COMMAND,ID_REBUILD_AND_LINK,NULL);
}
