// SolutionTree.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "SolutionTree.h"
#include "FileView.h"

#include "./Common/Global.h"
#include "UserWmMsg.h"

// CSolutionTree

CSolutionTree::CSolutionTree()
{
	m_hCurItem = NULL;
	m_strBeforeChangeItemText.Empty();
}

CSolutionTree::~CSolutionTree()
{
	
}

BEGIN_MESSAGE_MAP(CSolutionTree, CXTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_BEGINLABELEDIT, OnBeginLabelEdit)
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndLabelEdit)	
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBegindrag)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnTvnItemexpanded)		
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnNMDblclk)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnTvnSelchanged)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONUP()	
END_MESSAGE_MAP()


// CSolutionTree ��Ϣ�������

void CSolutionTree::OnBeginLabelEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;

	CEdit *pEdit = GetEditControl();

	COLFileNode* pOLFileNode = GetItemNode(pTVDispInfo->item.hItem);
	if(pOLFileNode != NULL)
	{
		//����Ƿ�����
		if(pOLFileNode->IsSolutionNode())
		{
			pEdit->SetWindowText(pOLFileNode->m_strName);
		}
	}

	pEdit->GetWindowText(m_strBeforeChangeItemText);

	CXTreeCtrl::OnBeginLabelEdit(pNMHDR,pResult);
}

void CSolutionTree::OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;

	if(pTVDispInfo->item.pszText == NULL)
	{
		*pResult = TRUE;
		return;
	}

	CString strMsg;
	//�ж����ƺϷ���
	CString strCurItemText = pTVDispInfo->item.pszText;
	if(strCurItemText.IsEmpty())
	{
		*pResult = FALSE;
		return;
	}

	if( strCurItemText.Find('<')  > -1     || strCurItemText.Find('>') > -1     || 
		strCurItemText.Find(_T('\\')) > -1 || strCurItemText.Find(_T('/')) > -1 ||
		strCurItemText.Find('*')  > -1     || strCurItemText.Find('?') > -1     || 
		strCurItemText.Find(':')  > -1     || strCurItemText.Find('"') > -1     || strCurItemText.Find('|') > -1)
	{		
		strMsg.Format(_T("���Ʋ��ܰ���(\\ / > < * ? : \" |)�ַ�"));
		AfxMessageBox(strMsg);
		
		*pResult = FALSE;

		EditLabel(pTVDispInfo->item.hItem);
		return;
	}

	//�õ��������
	COLFileNode* pOLFileNode = GetItemNode(pTVDispInfo->item.hItem);
	
	//�����ļ����ļ�����
	if(pOLFileNode->IsFloderNode() || pOLFileNode->IsFileNode())
	{
		//�������û�иı�
		if(m_strBeforeChangeItemText == pTVDispInfo->item.pszText)
			return;
		
		CString strOtherItemName;
		//�ж��ļ����Ƿ�����
		HTREEITEM hTreeItemTemp = GetChildItem(GetParentItem(pTVDispInfo->item.hItem));
		while(hTreeItemTemp)
		{
			if(hTreeItemTemp == pTVDispInfo->item.hItem)
			{
				hTreeItemTemp = GetNextItem(hTreeItemTemp,TVGN_NEXT);
				continue;
			}
			
			COLFileNode* pOLFileNodeTemp = GetItemNode(hTreeItemTemp);
			strOtherItemName = pOLFileNodeTemp->m_strName;
			strCurItemText.MakeLower();
			strOtherItemName.MakeLower();
			if( (strOtherItemName == strCurItemText) && 
				((pOLFileNode->IsFloderNode() && pOLFileNodeTemp->IsFloderNode()) || (pOLFileNode->IsFileNode() && pOLFileNodeTemp->IsFileNode())))
			{				
				strMsg.Format(_T("%s�������Ѿ���ʹ�ã���ʹ����������"),pTVDispInfo->item.pszText);
				AfxMessageBox(strMsg);
				*pResult = FALSE;

				EditLabel(pTVDispInfo->item.hItem);
				return;
			}

			hTreeItemTemp = GetNextItem(hTreeItemTemp,TVGN_NEXT);
		}

		CString strNewPath = GetPathFromPathName(pOLFileNode->m_strPathName) + pTVDispInfo->item.pszText;
		if(FileRename(pOLFileNode->m_strPathName,strNewPath))
		{
			//�����ļ�������
			pOLFileNode->m_strName = pTVDispInfo->item.pszText;
			pOLFileNode->m_strPathName = strNewPath;
		}		
	}
	//���Ĺ�����
	else if(pOLFileNode->IsProjectNode())
	{
		//�������û�иı�
		if(m_strBeforeChangeItemText == pTVDispInfo->item.pszText)
			return;

		//�жϹ����Ƿ�����
		HTREEITEM hTreeItemTemp = GetChildItem(GetParentItem(pTVDispInfo->item.hItem));
		while(hTreeItemTemp)
		{
			if(hTreeItemTemp == pTVDispInfo->item.hItem)
			{
				hTreeItemTemp = GetNextItem(hTreeItemTemp,TVGN_NEXT);
				continue;
			}

			COLFileNode* pOLFileNodeTemp = GetItemNode(hTreeItemTemp);
			if( (pOLFileNodeTemp != NULL) && 
				(pOLFileNodeTemp->IsProjectNode()) &&
				(pOLFileNodeTemp->m_strName  == pTVDispInfo->item.pszText))
			{				
				strMsg.Format(_T("%s �����Ѿ����ڣ���ʹ��������������"),pTVDispInfo->item.pszText);
				AfxMessageBox(strMsg);
				*pResult = FALSE;

				EditLabel(pTVDispInfo->item.hItem);
				return;
			}

			hTreeItemTemp = GetNextItem(hTreeItemTemp,TVGN_NEXT);
		}	

		//���ù�������
		pOLFileNode->m_strName = pTVDispInfo->item.pszText;

		//���湤�̽������		
		SaveProjectTreeNode(pTVDispInfo->item.hItem);
	}
	//���ķ�����
	else if(pOLFileNode->IsSolutionNode())
	{
		//�������û�иı�
		if(m_strBeforeChangeItemText != pTVDispInfo->item.pszText)
		{			
			//�жϷ�������
			HTREEITEM hTreeItemTemp = GetChildItem(GetParentItem(pTVDispInfo->item.hItem));
			while(hTreeItemTemp)
			{
				if(hTreeItemTemp == pTVDispInfo->item.hItem)
				{
					hTreeItemTemp = GetNextItem(hTreeItemTemp,TVGN_NEXT);
					continue;
				}

				COLFileNode* pOLFileNodeTemp = GetItemNode(hTreeItemTemp);
				if( (pOLFileNodeTemp != NULL) && 
					(pOLFileNodeTemp->IsSolutionNode()) &&
					(pOLFileNodeTemp->m_strName  == pTVDispInfo->item.pszText))
				{					
					strMsg.Format(_T("%s �����Ѿ����ڣ���ʹ��������������"),pTVDispInfo->item.pszText);
					AfxMessageBox(strMsg);
					*pResult = FALSE;

					EditLabel(pTVDispInfo->item.hItem);
					return;
				}

				hTreeItemTemp = GetNextItem(hTreeItemTemp,TVGN_NEXT);
			}

			//���÷�������
			pOLFileNode->m_strName = pTVDispInfo->item.pszText;
		}
				
		strMsg.Format(_T("�������-\"%s\""),pTVDispInfo->item.pszText);
#ifdef _UNICODE
		wcscpy_s(pTVDispInfo->item.pszText,pTVDispInfo->item.cchTextMax,strMsg);
#else
		strcpy_s(pTVDispInfo->item.pszText,pTVDispInfo->item.cchTextMax,strMsg);
#endif	

		//���淽���������
		((CFileView*)GetParent())->SaveSolutionTreeNode();
	}	

	CXTreeCtrl::OnEndLabelEdit(pNMHDR,pResult);
}

COLFileNode* CSolutionTree::GetSolutionNode()
{
	HTREEITEM hRootItem = GetRootItem();
	if(hRootItem != NULL)
	{
		return GetItemNode(hRootItem);
	}

	return NULL;
}

HTREEITEM CSolutionTree::GetFirstProject()
{
	COLFileNode* pOLFileNodeSolution = GetSolutionNode();
	if(pOLFileNodeSolution)
	{
		return GetChildItem(pOLFileNodeSolution->m_hItemTree);
	}

	return NULL;
}	

//ͨ�����̵��ļ�·�����õ��������ڵ���
HTREEITEM CSolutionTree::GetProjectItemFromProjectFileName(const CString& strProjectFileName)
{
	COLFileNode* pOLFileNode = GetSolutionNode();
	if(pOLFileNode)
	{		
		HTREEITEM hItemProject = GetChildItem(pOLFileNode->m_hItemTree);
		while(hItemProject)
		{
			pOLFileNode = GetItemNode(hItemProject);
			if((pOLFileNode) && (pOLFileNode->IsProjectNode()) && (pOLFileNode->m_strPathName == strProjectFileName))
			{
				return pOLFileNode->m_hItemTree;
			}

			hItemProject = GetNextItem(hItemProject,TVGN_NEXT);
		}
	}

	return NULL;
}


//ͨ���ļ������ļ�����Ŀ�õ����ڵĹ���
HTREEITEM CSolutionTree::GetProjectItemFromChildItem(HTREEITEM hTreeItem)
{
	if(hTreeItem == NULL)
		return NULL;

	COLFileNode* pOLFileNode = GetItemNode(hTreeItem);
	if(pOLFileNode->IsSolutionNode())
		return NULL;

	while(pOLFileNode)
	{
		if(pOLFileNode->IsProjectNode())
		{
			return pOLFileNode->m_hItemTree;
		}

		pOLFileNode = GetItemNode(GetParentItem(pOLFileNode->m_hItemTree));
	}

	return NULL;
}

COLFileNode* CSolutionTree::GetItemNode(HTREEITEM hTreeItem)
{
	if(hTreeItem != NULL)
	{
		return (COLFileNode*)GetItemData(hTreeItem);
	}

	return NULL;
}

void CSolutionTree::DeleteItem(HTREEITEM hTreeItem)
{
	COLFileNode* pOLFileNode = GetItemNode(hTreeItem);
	if(pOLFileNode == NULL)
		return;

	if(pOLFileNode->IsProjectNode())
	{
		CProjectProperty* pProjectProperty = (CProjectProperty*)pOLFileNode->m_pProperty;		
		pProjectProperty->DeleteBuildRecord();

		m_hCurItem = GetFirstProject();
		if(m_hCurItem)
		{
			SelectItem(m_hCurItem);
		}		
	}

	delete pOLFileNode;
	SetItemData(hTreeItem,0);

	CTreeCtrl::DeleteItem(hTreeItem);
}

//��ӷ���
HTREEITEM CSolutionTree::InsertSolution(const TCHAR* pchSolutionFileName,const TCHAR* pchSolutionName)
{
	//��������Ѿ��������˳�
	COLFileNode* pOLFileNodeSolution = GetSolutionNode();
	if((pOLFileNodeSolution) && (pOLFileNodeSolution->m_strPathName == pchSolutionFileName))
	{
		SelectItem(pOLFileNodeSolution->m_hItemTree);
		return pOLFileNodeSolution->m_hItemTree;
	}

	//��ӷ������
	HTREEITEM hTreeItemTemp;
	CString strTemp;
	strTemp.Format(_T("�������-\"%s\""),pchSolutionName);
	hTreeItemTemp = InsertItem(strTemp);
	if(hTreeItemTemp == NULL)
		return NULL;

	SelectItem(hTreeItemTemp);
	SetFocus();

	COLFileNode* pOLFileNode = new COLFileNode();
	pOLFileNode->m_enumType = COLFileNode::ONT_SOLUTION;	
	pOLFileNode->m_strPathName = pchSolutionFileName;
	pOLFileNode->m_hItemTree = hTreeItemTemp;
	pOLFileNode->m_strName = pchSolutionName;
	SetItemData(hTreeItemTemp,(DWORD_PTR)pOLFileNode);

	return hTreeItemTemp;
}

//��ӹ���
HTREEITEM CSolutionTree::InsertProject(const TCHAR* pchProjectFilePath,const TCHAR* pchProjectName)
{
	COLFileNode* pOLFileNode = GetSolutionNode();
	if(pOLFileNode == NULL)
		return NULL;

	//��ӹ����ӽ��
	HTREEITEM hTreeItemTemp = InsertItem(pchProjectName,1,1,pOLFileNode->m_hItemTree);
	if(hTreeItemTemp == NULL)
		return NULL;

	SelectItem(hTreeItemTemp);
	SetFocus();

	COLFileNode* pOLFileNodeProject = new COLFileNode();
	pOLFileNodeProject->m_enumType = COLFileNode::ONT_PROJECT;	
	pOLFileNodeProject->m_strPathName = pchProjectFilePath;
	if(pOLFileNodeProject->m_strPathName.Right(1) == _T('\\'))
	{
		pOLFileNodeProject->m_strPathName.Delete(pOLFileNodeProject->m_strPathName.GetLength()-1);
	}
	pOLFileNodeProject->m_strName = pchProjectName;
	pOLFileNodeProject->m_hItemTree = hTreeItemTemp;
	SetItemData(hTreeItemTemp,(DWORD_PTR)pOLFileNodeProject);

	return hTreeItemTemp;
}

//���ù�������
void CSolutionTree::SetProjectProperty(HTREEITEM hProjectTreeItem,CProjectProperty& projectProperty)
{
	CProjectProperty* pProjectProperty = new CProjectProperty();
	*pProjectProperty = projectProperty;

	GetItemNode(hProjectTreeItem)->m_pProperty = (void*)pProjectProperty;
}

//�õ���������
CProjectProperty* CSolutionTree::GetProjectProperty(HTREEITEM hTreeItemProject)
{
	COLFileNode* pOLFileNode = GetItemNode(hTreeItemProject);
	if((pOLFileNode == NULL) || (!pOLFileNode->IsProjectNode()))
		return NULL;

	return (CProjectProperty*)pOLFileNode->m_pProperty;
}

CProjectProperty* CSolutionTree::GetCurProjectProperty()
{
	COLFileNode* pOLFileNode = GetCurItemNode();
	HTREEITEM hProjectItem = NULL;
	if(pOLFileNode->IsProjectNode())
	{
		hProjectItem = pOLFileNode->m_hItemTree;
	}
	else if(pOLFileNode->IsFloderNode() || pOLFileNode->IsFileNode())
	{
		hProjectItem = GetProjectItemFromChildItem(pOLFileNode->m_hItemTree);
	}
	else
	{
		return NULL;
	}

	return GetProjectProperty(hProjectItem);
}

//����ļ�����
HTREEITEM CSolutionTree::InsertFloder(HTREEITEM hTreeItem,const TCHAR* pchFloderName,BOOL bCreateDirectory,BOOL bSelected)
{
	COLFileNode* pOLFileNode = GetItemNode(hTreeItem);
	if(pOLFileNode == NULL)
		return NULL;

	CString strFloderPath;	
	if(pOLFileNode->IsProjectNode())
	{		
		strFloderPath = GetPathFromPathName(pOLFileNode->m_strPathName);
	}
	else if(pOLFileNode->IsFloderNode())
	{		
		strFloderPath = pOLFileNode->m_strPathName + _T('\\');
	}
	else 
	{
		return NULL;
	}

	//�õ������ļ��е�itemλ��
	HTREEITEM hItemAfter = GetChildItem(hTreeItem);
	COLFileNode* pOLFileNodeTemp = GetItemNode(hItemAfter);
	if(pOLFileNodeTemp && pOLFileNodeTemp->IsFloderNode())
	{		
		HTREEITEM hItemPre = hItemAfter;
		while(TRUE)
		{
			hItemAfter = GetNextItem(hItemPre,TVGN_NEXT);
			pOLFileNodeTemp = GetItemNode(hItemAfter);
			if((pOLFileNodeTemp == NULL) || (!pOLFileNodeTemp->IsFloderNode()))
			{
				hItemAfter = hItemPre;
				break;
			}

			hItemPre = hItemAfter;
		}
	}
	else
	{		
		hItemAfter = TVI_FIRST;
	}

	//��ӹ����ӽ��
	HTREEITEM hTreeItemTemp = InsertItem(pchFloderName,2,2,hTreeItem,hItemAfter);
	if(hTreeItemTemp == NULL)
		return NULL;

	if(bSelected)
	{
		SelectItem(hTreeItemTemp);
		SetFocus();
	}
	
	pOLFileNode = new COLFileNode();	
	pOLFileNode->m_enumType = COLFileNode::ONT_FLODER;
	pOLFileNode->m_strName = pchFloderName;
	pOLFileNode->m_hItemTree = hTreeItemTemp;		
	pOLFileNode->m_strPathName = strFloderPath + pchFloderName;
	SetItemData(hTreeItemTemp,(DWORD_PTR)pOLFileNode);

	if(bCreateDirectory)
	{
		::CreateDirectory(pOLFileNode->m_strPathName,NULL);	
	}

	return hTreeItemTemp;
}

//����ļ�
HTREEITEM CSolutionTree::InsertFile(HTREEITEM hTreeItemParent,const CString& strFileName,const CString& strFilePath,BOOL bSelected)
{
	COLFileNode* pOLFileNodeParent = GetItemNode(hTreeItemParent);
	if(pOLFileNodeParent == NULL)
		return NULL;	
	
	//�õ�ͼ��
	SHFILEINFO sfi;
	ZeroMemory(&sfi,sizeof(SHFILEINFO));
	::SHGetFileInfo(strFilePath,0,&sfi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON|SHGFI_LARGEICON);
	CImageList* pImageList = GetImageList(TVSIL_NORMAL);
	pImageList->SetBkColor(RGB(255,255,255)); //���ñ���ɫΪ��ɫ
	int nImageIndex = pImageList->Add(sfi.hIcon);

	//����ļ��ӽ��
	HTREEITEM hTreeItemTemp = InsertItem(strFileName,nImageIndex,nImageIndex,hTreeItemParent);
	if(hTreeItemTemp == NULL)
		return NULL;

	if(bSelected)
	{
		SelectItem(hTreeItemTemp);
		SetFocus();
	}	

	COLFileNode* pOLFileNodeFile = new COLFileNode();
	pOLFileNodeFile->m_enumType = COLFileNode::ONT_FILE;
	pOLFileNodeFile->m_strPathName = strFilePath;
	pOLFileNodeFile->m_strName = strFileName;
	pOLFileNodeFile->m_hItemTree = hTreeItemTemp;
	SetItemData(hTreeItemTemp,(DWORD_PTR)pOLFileNodeFile);

	return hTreeItemTemp;
}

void CSolutionTree::AddProjectFloder()
{
	CString strFloderName = _T("�½��ļ���0");
	CString strTemp = _T("");
	int nIndex = 0;
	HTREEITEM hItemParent = m_hCurItem;

	//�ж��ļ����Ƿ�����
	HTREEITEM hTreeItemTemp = GetChildItem(hItemParent);
	HTREEITEM hFistChildItem = hTreeItemTemp;
	while(hTreeItemTemp)
	{
		COLFileNode* pOLFileNode = GetItemNode(hTreeItemTemp);

		if( (pOLFileNode != NULL) && (pOLFileNode->IsFloderNode()) &&
			(pOLFileNode->m_strName == strFloderName))
		{
			nIndex ++;
			strFloderName = strFloderName.Left(strFloderName.GetLength()-1);
			strTemp.Format(_T("%d"),nIndex);
			strFloderName += strTemp;
			hTreeItemTemp = hFistChildItem;		
		}

		hTreeItemTemp = GetNextItem(hTreeItemTemp,TVGN_NEXT);
	}

	hTreeItemTemp = InsertFloder(hItemParent,strFloderName,TRUE,TRUE);
	if(hTreeItemTemp)
	{
		EditLabel(hTreeItemTemp);
	}	
}

void CSolutionTree::SaveAllProject()
{
	HTREEITEM hSolutionItemTemp = GetRootItem();
	while(hSolutionItemTemp)
	{
		HTREEITEM hProjectItemTemp = GetChildItem(hSolutionItemTemp);
		while(hProjectItemTemp)
		{
			COLFileNode* pOLFileNode = GetItemNode(hProjectItemTemp);
			if((pOLFileNode != NULL) && (pOLFileNode->IsProjectNode()))
			{
				//���湤�̽������
				SaveProjectTreeNode(pOLFileNode->m_hItemTree);
			}

			hProjectItemTemp = GetNextItem(hProjectItemTemp,TVGN_NEXT);
		}

		hSolutionItemTemp = GetNextItem(hSolutionItemTemp,TVGN_NEXT);
	}
}

void CSolutionTree::SaveProjectTreeNode(HTREEITEM hProjectTreeItem)
{
	((CFileView*)GetParent())->SaveProjectTreeNode(hProjectTreeItem);
}

void CSolutionTree::OnTvnItemexpanded(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	//�����ļ���չ��ͼ��
	COLFileNode* pOLFileNode = GetItemNode(pNMTreeView->itemNew.hItem);
	if((pOLFileNode != NULL) && (pOLFileNode->IsFloderNode()))
	{
		//չ��
		if(pNMTreeView->action == 2)
		{
			SetItemImage(pNMTreeView->itemNew.hItem,3,3);				
		}
		else 
		{
			SetItemImage(pNMTreeView->itemNew.hItem,2,2);
		}			
	}
}

//˫�����ļ�
void CSolutionTree::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	OpenProjectFile(m_hCurItem);
}

void CSolutionTree::OpenProjectFile(HTREEITEM hItemFile)
{
	COLFileNode* pOLFileNode = GetItemNode(hItemFile);
	if(pOLFileNode == NULL || !pOLFileNode->IsFileNode())
		return;

	CString strExternName = GetFileExternName(pOLFileNode->m_strPathName);
	if( strExternName == _T("omp") || strExternName == _T("omh") || 
		strExternName == _T("oam") || strExternName == _T("oah") || 
		strExternName == _T("o")   || strExternName == _T("oat") || strExternName == _T("doa"))
	{
		//theApp.OpenDocumentFile(pOLFileNode->m_strPathName);
		::SendMessage(AfxGetMainWnd()->GetSafeHwnd(),WM_OPEN_DOCUMENT,(WPARAM)(LPCTSTR)pOLFileNode->m_strPathName,NULL);
	}
	else
	{
		::ShellExecute(NULL,_T("open"),pOLFileNode->m_strPathName,NULL,NULL,SW_SHOW);	
	}
}

//�رշ���
void CSolutionTree::CloseSolution()
{
	//�ж��Ƿ�Ϊ�������
	COLFileNode* pOLFileNodeSolution = GetSolutionNode();
	if(pOLFileNodeSolution == NULL)
		return;
	
	COLFileNode* pOLFileNodeProject = NULL;
	HTREEITEM hProjectItemTemp = GetChildItem(pOLFileNodeSolution->m_hItemTree);
	while(hProjectItemTemp)
	{
		pOLFileNodeProject = GetItemNode(hProjectItemTemp);
		ASSERT(pOLFileNodeProject);

		//�ر��ĵ�
		theApp.CloseDocument(GetPathFromPathName(pOLFileNodeProject->m_strPathName),TRUE);
		DelChild(hProjectItemTemp);

		hProjectItemTemp = GetNextItem(hProjectItemTemp,TVGN_NEXT);
	}

	DeleteItem(pOLFileNodeSolution->m_hItemTree);
}

void CSolutionTree::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	m_hCurItem = pNMTreeView->itemNew.hItem;
}

void CSolutionTree::DeleteFloadOrFile(HTREEITEM hItem)
{
	COLFileNode* pOLFileNode = GetItemNode(hItem);
	if(pOLFileNode == NULL)
		return;

	if(pOLFileNode->IsFloderNode() || pOLFileNode->IsFileNode())
	{
		int nMessage = MessageBox(_T("Ҫ����ɾ���ļ���ѡ���ɾ��������վ?"),_T("ɾ������"),MB_YESNOCANCEL|MB_ICONQUESTION);
		//����ɾ��
		if(IDYES == nMessage)
		{	
			if(pOLFileNode->IsFloderNode())
			{
				//�ر��ĵ�
				theApp.CloseDocument(pOLFileNode->m_strPathName,TRUE);
				//ɾ��Ŀ¼
				if(::RemoveDirectory(pOLFileNode->m_strPathName))
				{
					DelChild(pOLFileNode->m_hItemTree);
					DeleteItem(pOLFileNode->m_hItemTree);	
				}
				else
				{
					//ɾ��Ŀ¼ʧ�ܣ���ˢ��Ŀ¼
					::SendMessage(GetParent()->GetSafeHwnd(),WM_COMMAND,ID_REFRESH,NULL);
				}
			}
			else
			{
				//�ر��ĵ�
				theApp.CloseDocument(pOLFileNode->m_strPathName);
				//ɾ���ļ�
				if(::DeleteFile(pOLFileNode->m_strPathName))
				{
					//ɾ��������
					DeleteItem(pOLFileNode->m_hItemTree);
				}
			}
		}
		//ɾ��������վ
		else if(IDNO == nMessage)
		{
			if(pOLFileNode->IsFloderNode())
			{
				DelChild(pOLFileNode->m_hItemTree);
			}

			DeleteFolderOrFile(pOLFileNode->m_strPathName,FALSE);
			DeleteItem(pOLFileNode->m_hItemTree);	
		}
	}
}

void CSolutionTree::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if(nChar == VK_F2)
	{
		EditLabel(m_hCurItem);
	}
	/*else if(nChar == VK_F5)
	{
		::SendMessage(GetParent()->GetSafeHwnd(),WM_COMMAND,ID_REFRESH,NULL);
	}*/
	//ɾ����
	else if(nChar == VK_DELETE)
	{	
		DeleteFloadOrFile(m_hCurItem);
	}

	CXTreeCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

//�ݹ�ɾ������
void CSolutionTree::DelChild(HTREEITEM hItem)
{	
	HTREEITEM hItemNext = NULL;
	HTREEITEM hItemTemp = GetChildItem(hItem);
	while(hItemTemp)
	{
		if(ItemHasChildren(hItemTemp))
		{	
			DelChild(hItemTemp);
		}
	
		hItemNext = GetNextItem(hItemTemp,TVGN_NEXT);

		DeleteItem(hItemTemp);

		hItemTemp = hItemNext;
	}
}

void CSolutionTree::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	COLFileNode* pOLFileNode = GetItemNode(pNMTreeView->itemNew.hItem);
	//�϶�����Ŀ�����ļ��л����ļ���ֱ�ӷ���
	if(pOLFileNode != NULL && !pOLFileNode->IsFloderNode() && !pOLFileNode->IsFileNode())
	{		
		*pResult = 0;
		return;
	}

	CXTreeCtrl::OnBegindrag(pNMHDR, pResult);
}

void CSolutionTree::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//û���϶�ֱ�ӷ���
	if(m_bDragging == FALSE)
	{
		CXTreeCtrl::OnLButtonUp(nFlags, point);
		return;
	}
	
	COLFileNode* pOLFileNodeD = GetItemNode(m_hItemDragD);
	//����ϵ���Ŀ�겻�ǹ��̻����ļ��н����ֱ�ӷ���
	if(!pOLFileNodeD->IsFloderNode() && !pOLFileNodeD->IsProjectNode())
	{
		SetCancelDrag(TRUE);
		CXTreeCtrl::OnLButtonUp(nFlags, point);
		return;
	}

	COLFileNode* pOLFileNodeS = GetItemNode(m_hItemDragS);
	if(pOLFileNodeS->m_strPathName[0] != pOLFileNodeD->m_strPathName[0])
	{
		AfxMessageBox(_T("�����ڲ�ͬ������֮���ƶ��ļ�!"));

		SetCancelDrag(TRUE);
		CXTreeCtrl::OnLButtonUp(nFlags, point);
		return;
	}

	HTREEITEM hItemParentS = GetParentItem(m_hItemDragS);

	//����϶�����
	CXTreeCtrl::OnLButtonUp(nFlags, point);
	
	COLFileNode* pOLFileNodeCur = GetItemNode(m_hCurItem);
	pOLFileNodeCur->m_hItemTree = m_hCurItem;
	HTREEITEM hCurItemParent = GetParentItem(m_hCurItem);
	//����϶�����Ŀλ���иı�
	if(hCurItemParent != hItemParentS)
	{
		CString strOtherItemName;
		CString strItemTextCur = pOLFileNodeCur->m_strName;
		//�ж��ļ����Ƿ�����
		HTREEITEM hTreeItemTemp = GetChildItem(hCurItemParent);
		while(hTreeItemTemp)
		{
			if(hTreeItemTemp == m_hCurItem)
			{
				hTreeItemTemp = GetNextItem(hTreeItemTemp,TVGN_NEXT);
				continue;
			}

			COLFileNode* pOLFileNodeTemp = GetItemNode(hTreeItemTemp);
			strOtherItemName = pOLFileNodeTemp->m_strName;
			strItemTextCur.MakeLower();
			strOtherItemName.MakeLower();
			//��������г�ͻ�����ĵ�ǰ��Ŀ����
			if( (strOtherItemName == strItemTextCur) && 
				((pOLFileNodeCur->IsFloderNode() && pOLFileNodeTemp->IsFloderNode()) || (pOLFileNodeCur->IsFileNode() && pOLFileNodeTemp->IsFileNode())))
			{
				strItemTextCur = _T("����_") + pOLFileNodeCur->m_strName;
				pOLFileNodeCur->m_strName = strItemTextCur;
				SetItemText(pOLFileNodeCur->m_hItemTree,strItemTextCur);

				hTreeItemTemp = GetChildItem(hCurItemParent);
				continue;
			}

			hTreeItemTemp = GetNextItem(hTreeItemTemp,TVGN_NEXT);
		}

		//�ƶ��ļ����ļ��е��µ�λ��
		CString strOldPath = pOLFileNodeCur->m_strPathName;
		COLFileNode* pOLFileNodeParent = GetItemNode(GetParentItem(m_hCurItem));
		CString strNewPath;
		if(pOLFileNodeParent->IsProjectNode())
		{
			strNewPath = GetPathFromPathName(pOLFileNodeParent->m_strPathName);			
		}
		else if(pOLFileNodeParent->IsFloderNode())
		{
			strNewPath = pOLFileNodeParent->m_strPathName;
			strNewPath += _T('\\');
		}
		else
		{
			ASSERT(FALSE);
		}
		strNewPath += pOLFileNodeCur->m_strName;		
		if(::MoveFile(strOldPath,strNewPath))
		{
			pOLFileNodeCur->m_strPathName = strNewPath;
			if(pOLFileNodeCur->IsFloderNode())
			{
				SelectItem(GetParentItem(m_hCurItem));
				::SendMessage(GetParent()->GetSafeHwnd(),WM_COMMAND,ID_REFRESH,NULL);
			}
		}
		//�ƶ��ļ��д���
		else
		{			
			CString strMsg;
			if(GetLastError() == 0x20)
			{
				strMsg = _T("�ļ����ڱ�ʹ�ã�");
			}
			strMsg += _T("�ƶ��ļ�ʧ��!");
			AfxMessageBox(strMsg);
			
			SelectItem(GetProjectItemFromChildItem(m_hCurItem));
			::SendMessage(GetParent()->GetSafeHwnd(),WM_COMMAND,ID_REFRESH,NULL);
		}
	}
}


