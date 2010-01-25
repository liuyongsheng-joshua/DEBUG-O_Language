
// OLIDE.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "OLIDE.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "OLIDEDoc.h"
#include "OLIDEView.h"
#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COLIDEApp

BEGIN_MESSAGE_MAP(COLIDEApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &COLIDEApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	
END_MESSAGE_MAP()


// COLIDEApp ����

COLIDEApp::COLIDEApp()
{

	m_bHiColorIcons = TRUE;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��	
}

// Ψһ��һ�� COLIDEApp ����

COLIDEApp theApp;


// COLIDEApp ��ʼ��

BOOL COLIDEApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	//Load the scintilla dll
	m_hSciDLL = LoadLibrary(_T("SciLexer.dll"));
	if (m_hSciDLL == NULL)
	{ 
		AfxMessageBox(_T("Scintilla �Ķ�̬���ӿ�û�а�װ,������SciLexer.dll�ŵ�����ͬһĿ¼��"));
		return FALSE;
	}

	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_OLIDETYPE,
		RUNTIME_CLASS(COLIDEDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(COLIDEView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// ������ MDI ��ܴ���
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� MDI Ӧ�ó����У���Ӧ������ m_pMainWnd ֮����������
	m_pMainWnd->DragAcceptFiles(TRUE);
	
	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	CString strExternName = cmdInfo.m_strFileName.Right(4);
	strExternName.MakeLower();
	if(strExternName == _T(".osl"))
	{		
		pMainFrame->OpenSolution(cmdInfo.m_strFileName);
	}
	else if(strExternName == _T(".opr"))
	{
		AfxMessageBox(_T("����ֱ�Ӵ򿪹���,��򿪹������ڵķ����ļ�"));
	}
	else
	{
		if((strExternName == _T(".omp")) || (strExternName == _T(".omh")) || 
			(strExternName == _T(".oam")) || (strExternName == _T(".oah")))
		{						
		}
		else
		{
			//������뿪ʼ�ʹ�һ�����ĵ��������һ�д���
			cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
		}

		// ��������������ָ����������
		// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
		if (!ProcessShellCommand(cmdInfo))
			return FALSE;
	}	

	// �������ѳ�ʼ���������ʾ����������и���	
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();	

	SetCurVersion(1,0,0,5);

	//����°汾
	if(pMainFrame->m_systemOption.m_bUpdateEveryTime)
	{
		CheckNewVersion();
	}

	return TRUE;
}

CDocument* COLIDEApp::GetDocument(const CString& strPath)
{
	POSITION pos1 = GetFirstDocTemplatePosition();
	while (pos1)
	{
		CDocTemplate* ptempl = (CDocTemplate*)GetNextDocTemplate(pos1);
		POSITION pos2 = ptempl->GetFirstDocPosition();
		while (pos2) 
		{
			CDocument *pDoc;
			if ((pDoc=ptempl->GetNextDoc(pos2)) != NULL)
			{
				if(pDoc->GetPathName() == strPath)
					return pDoc;
			}
		}
	}

	return NULL;
}

void COLIDEApp::SaveDocument(const CString& strPathName,BOOL bIsFloder)
{
	POSITION pos1 = GetFirstDocTemplatePosition();
	while (pos1)
	{
		CDocTemplate* ptempl = (CDocTemplate*)GetNextDocTemplate(pos1);
		POSITION pos2 = ptempl->GetFirstDocPosition();
		CString strPathNameTemp;
		CDocument* pDocTemp;
		while (pos2) 
		{		
			pDocTemp = ptempl->GetNextDoc(pos2);
			strPathNameTemp = pDocTemp->GetPathName();
			//������ļ���
			if(bIsFloder)
			{
				if(strPathNameTemp.Find(strPathName) == 0)
				{
					if(pDocTemp->IsKindOf(RUNTIME_CLASS(COLIDEDoc)))
					{
						((COLIDEDoc*)pDocTemp)->DoFileSave();
					}
					else
					{
						pDocTemp->DoFileSave();
					}
				}
			}
			//�������ļ�
			else
			{
				if(strPathNameTemp == strPathName)
				{
					if(pDocTemp->IsKindOf(RUNTIME_CLASS(COLIDEDoc)))
					{
						((COLIDEDoc*)pDocTemp)->DoFileSave();
					}
					else
					{
						pDocTemp->DoFileSave();
					}
					break;
				}
			}						
		}
	}
}

void COLIDEApp::CloseDocument(const CString& strPathName,BOOL bIsFloder)
{
	POSITION pos1 = GetFirstDocTemplatePosition();
	while (pos1)
	{
		CDocTemplate* ptempl = (CDocTemplate*)GetNextDocTemplate(pos1);
		POSITION pos2 = ptempl->GetFirstDocPosition();
		CString strPathNameTemp;
		CDocument* pDocTemp;
		while (pos2) 
		{		
			pDocTemp = ptempl->GetNextDoc(pos2);
			strPathNameTemp = pDocTemp->GetPathName();
			//������ļ���
			if(bIsFloder)
			{
				if(strPathNameTemp.Find(strPathName) == 0)
				{
					if(pDocTemp->IsKindOf(RUNTIME_CLASS(COLIDEDoc)))
					{
						((COLIDEDoc*)pDocTemp)->OnCloseDocument();
					}
					else
					{
						pDocTemp->OnCloseDocument();
					}
				}
			}
			//�������ļ�
			else
			{
				if(strPathNameTemp == strPathName)
				{
					if(pDocTemp->IsKindOf(RUNTIME_CLASS(COLIDEDoc)))
					{
						((COLIDEDoc*)pDocTemp)->OnCloseDocument();
					}
					else
					{
						pDocTemp->OnCloseDocument();
					}
					break;
				}
			}						
		}
	}
}


// COLIDEApp �Զ������/���淽��

void COLIDEApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;

	bNameValid = strName.LoadString(IDS_OASM_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_OASM_EDIT);
	bNameValid = strName.LoadString(IDS_OML_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_OML_EDIT);

	bNameValid = strName.LoadString(IDS_SOLUTION);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_SOLUTION);
	bNameValid = strName.LoadString(IDS_PROJECT);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_PROJECT);
	bNameValid = strName.LoadString(IDS_FLODER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_FLODER);
	bNameValid = strName.LoadString(IDS_FILE);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_FILE);	
}

void COLIDEApp::LoadCustomState()
{
}

void COLIDEApp::SaveCustomState()
{
}

// COLIDEApp ��Ϣ�������

int COLIDEApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���

	//Free up the Scintilla DLL
	if (m_hSciDLL)
	{
		FreeLibrary(m_hSciDLL);
		m_hSciDLL = NULL;
	}

	return CWinAppEx::ExitInstance();
}

// �������жԻ����Ӧ�ó�������
void COLIDEApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void COLIDEApp::SetCurVersion(long lVersion1,long lVersion2,long lVersion3,long lVersion4)
{
	m_lVersion1 = lVersion1;
	m_lVersion2 = lVersion2;
	m_lVersion3 = lVersion3;
	m_lVersion4 = lVersion4;
}

void COLIDEApp::GetCurVersion(long& lVersion1,long& lVersion2,long& lVersion3,long& lVersion4)
{
	lVersion1 = m_lVersion1;
	lVersion2 = m_lVersion2;
	lVersion3 = m_lVersion3;
	lVersion4 = m_lVersion4;
}

#include<wininet.h>  
#pragma comment(lib,"wininet.lib")  

void COLIDEApp::CheckNewVersion()
{
	CString strVersion;
	if(!ReadVersionInfo(strVersion))
		return;

	CString strVersion1,strVersion2,strVersion3,strVersion4;	

	int nPos = 0;
	nPos = strVersion.Find(_T('.'));
	strVersion1 = strVersion.Left(nPos);
	strVersion = strVersion.Right(strVersion.GetLength() - nPos - 1);

	nPos = strVersion.Find(_T('.'));
	strVersion2 = strVersion.Left(nPos);
	strVersion = strVersion.Right(strVersion.GetLength() - nPos - 1);

	nPos = strVersion.Find(_T('.'));
	strVersion3 = strVersion.Left(nPos);
	strVersion4 = strVersion.Right(strVersion.GetLength() - nPos - 1);	

	long lVersion1,lVersion2,lVersion3,lVersion4;
#ifdef _UNICODE
	lVersion1 = wcstol(strVersion1,0,10);
	lVersion2 = wcstol(strVersion2,0,10);
	lVersion3 = wcstol(strVersion3,0,10);
	lVersion4 = wcstol(strVersion4,0,10);
#else
	lVersion1 = strtol(strVersion1,0,10);
	lVersion2 = strtol(strVersion2,0,10);
	lVersion3 = strtol(strVersion3,0,10);
	lVersion4 = strtol(strVersion4,0,10);
#endif

	if( (lVersion1 > m_lVersion1) || 
		(lVersion2 > m_lVersion2) || 
		(lVersion3 > m_lVersion3) || 
		(lVersion4 > m_lVersion4))
	{
		CString strNewVersion;
		if(IDYES == ::MessageBox(NULL,_T("�����°汾���Ƿ������ҳ�棿"),_T("O��������"),MB_YESNO | MB_ICONQUESTION ))
		{
			ShellExecute(NULL,_T("open"),_T("http://www.olanguage.org/download/"),NULL,NULL,SW_SHOWNORMAL);
		}
	}
	else
	{
		::MessageBox(NULL,_T("��ǰ�汾�Ѿ������°���!"),_T("O��������"),0);
	}
}

BOOL COLIDEApp::ReadVersionInfo(CString& strVersion)
{	
	BOOL bResult = FALSE;
	CString strUpdateFile = _T("http://www.olanguage.org/download/update.txt");

	HINTERNET hSession  =  InternetOpen(_T("ol") , INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if(hSession  !=  NULL)
	{
		HINTERNET handle2  =  InternetOpenUrl(hSession,strUpdateFile, NULL,  0 , INTERNET_FLAG_DONT_CACHE,  0 );
		if(handle2  !=  NULL)
		{			
			char chTemp[1024];
			DWORD dwRead;
			InternetReadFile(handle2,chTemp,1023,&dwRead);
			if(dwRead > 0)
			{
				chTemp[dwRead] = 0;
				strVersion = chTemp;
				bResult = TRUE;
			}
			InternetCloseHandle(handle2);
			handle2 = NULL;
		}
		InternetCloseHandle(hSession);
		hSession = NULL;
	}

	return bResult;
} 