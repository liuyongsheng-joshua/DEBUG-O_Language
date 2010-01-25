
#include "stdafx.h"
#include "OLIDE.h"
#include "OTracer.h"
#include "OLIDEView.h"

CBreakPointList g_sysBreakPointList;	

DEBUGGER_CPU_CONTEXT g_debugger_cpu_context;

DEBUGGER_CPU_CONTEXT* GetGlobalDebuggerCPUContext()
{
	return &g_debugger_cpu_context;
};

CBreakPointList* COTracer::GetSysBreakPointList()
{ 
	return &g_sysBreakPointList; 
}

COTracer::COTracer()
{
	m_pWndOwner = NULL; 	
	m_chDebugFileName[0] = 0;	
	m_hCurBreakPointThread = NULL; 
	m_bLoadAllLineBreakPoint = FALSE;
}

COTracer::~COTracer()
{
	
}

bool COTracer::BeginDebug(TCHAR* pchDebugFileName)
{
	wcscpy(m_chDebugFileName,pchDebugFileName);

	//��ȡPE�ļ��еĵ�������
	if(!m_readDebugData.Read(m_chDebugFileName))
	{
		::MessageBox(NULL,_T("��ȡ������Ϣʧ��,�޷��Գ�����е���,���������ɵ��԰����"),_T("���Ծ���"),MB_OK|MB_ICONWARNING);

		return false;
	}

	if(load(m_chDebugFileName))
	{
		ReSetAllBreakPoint();

		return true;	
	}

	return false;
}

void COTracer::DebugEnd()
{
	//���Խ�������
	
	CloseHandle(m_hThread);	
	m_hThread = 0;
	m_uiThreadID = 0;
	CloseHandle(m_hProcess);	
	m_hProcess = 0;
	m_uiProcessID = 0;

	if(m_hSuspendWnd)
	{
		::SendMessage(m_hSuspendWnd,WM_DEBUGGER_END,NULL,NULL);
	}
	
	::SendMessage(m_pWndOwner->GetSafeHwnd(),WM_DEBUGGER_END,NULL,NULL);

	//����ϵ��б�
	m_breakPointListUser.ClearList();
	GetSysBreakPointList()->ClearList();
}

int COTracer::DoMessage(MSG& msg)
{
	switch(msg.message)
	{	
		//��ֹ������Ϣ
	case WM_DEBUGGER_TERMINATE:
		{
			//��ֹ�����Խ���
			TerminateDebug();

			return -1;
		}
		//��������
	case WM_DEBUGGER_CONTINUE_FLOOD:
		{
			RestoreAllSingleLineBreakPoint();
			ResumeBreakpoint();

			break;
		}
		//�������е���
	case WM_DEBUGGER_CONTINUE_SINGLE_LINE:
		{
			InstallAllSingleLineBreakPoint();
			ResumeBreakpoint();

			break;
		}
		//ɾ�����жϵ�
	case WM_DEBUGGER_REMOVEALLBREAKPOINT:
		{
			RemoveAllBreakPoint();
			
			break;
		}
		//���ļ��������ڵ�������װ�ϵ�
	case WM_DEBUGGER_INSTALLBREAKPOINTFROMFILE:
		{
			DEBUGGER_BREAKPOINT* pBP = (DEBUGGER_BREAKPOINT*)msg.wParam;
			pBP->m_nLine = InstallBreakPointFromFile(CString(pBP->m_tchFileName),pBP->m_nLine,pBP->m_bInstalled);
			break;
		}
		//��ȡ�ڴ�
	case WM_DEBUGGER_READ_MEMORY:
		{
			DEBUGGER_READ_WRITE_MEMORY* p_drm = (DEBUGGER_READ_WRITE_MEMORY*)msg.wParam;			
			if(!ReadProcessMemory(m_hProcess,(LPCVOID)p_drm->m_nAddr,p_drm->m_pReadBuffer,p_drm->m_nLength,&p_drm->m_stReadOrWriteLength))
			{
				p_drm->m_stReadOrWriteLength = 0;
			}			

			break;
		}
		//д���ڴ�
	case WM_DEBUGGER_WRITE_MEMORY:
		{
			DEBUGGER_READ_WRITE_MEMORY* p_drm = (DEBUGGER_READ_WRITE_MEMORY*)msg.wParam;			

			DWORD oldprot, oldprot2;

			//
			// Make the page in question writable 
			//
			if ( ! VirtualProtectEx(
				m_hProcess,
				(LPVOID)p_drm->m_nAddr,
				p_drm->m_nLength,
				PAGE_READWRITE,
				&oldprot) )
			{
				break;
			}

			if(!WriteProcessMemory(m_hProcess,(LPVOID)p_drm->m_nAddr,p_drm->m_pReadBuffer,p_drm->m_nLength,&p_drm->m_stReadOrWriteLength))
			{
				p_drm->m_stReadOrWriteLength = 0;
			}

			//
			// restore original permissions
			//
			if ( ! VirtualProtectEx(
				m_hProcess,
				(LPVOID)p_drm->m_nAddr,
				p_drm->m_nLength,
				oldprot,
				&oldprot2) )
			{
				break;
			}

			//lParam���������Ƿ�Ϊ�����
			if(msg.lParam == TRUE)
			{
				FlushInstructionCache(m_hProcess,NULL,0);	
			}			

			break;
		}
	}

	return 0;
}

//������Ч��ַ����ϵ�λ��
void COTracer::ReSetAllBreakPoint()
{
	CBreakPointList* pSysBreakPointList = GetSysBreakPointList();

	m_breakPointListUser.ClearList();
	for(pSysBreakPointList->GetFirstElement();!pSysBreakPointList->isEnd();pSysBreakPointList->GetNextElement())
	{
		DEBUGGER_BREAKPOINT* pDbp = pSysBreakPointList->GetCurBreakPoint();
		::SendMessage(m_pWndOwner->GetSafeHwnd(),WM_DEBUGGER_DELETEBREAKPOINT,(WPARAM)pDbp,NULL);

		DEBUG_DATA_ITEM_LINE* p_debug_data_item_line = m_readDebugData.GetMatchLineItem(pDbp->m_tchFileName,pDbp->m_nLine,false);
		if(p_debug_data_item_line)
		{
			DEBUGGER_BREAKPOINT bp;
			wcscpy(bp.m_tchFileName,pDbp->m_tchFileName);
			bp.m_nLine = p_debug_data_item_line->m_lLine;
			bp.m_uiAddress = p_debug_data_item_line->m_ulAddr;
			bp.m_bInstalled = false;
			bp.m_bIsSingleLineBP = false;			
			InstallBreakPoint(bp);

			::SendMessage(m_pWndOwner->GetSafeHwnd(),WM_DEBUGGER_SETBREAKPOINT,(WPARAM)&bp,NULL);
		}
		else
		{
			//���öϵ���Ч					
		}
	}
}

int COTracer::InstallBreakPointFromFile(const CString& strFileName,int nLine,BOOL bInstall)
{
	//���ڴ��ڵ���״̬
	if(IsDebuging())
	{
		bool bMatchLine = bInstall?false:true;//�����ɾ���ϵ��Ҫ��ȷƥ����
		DEBUG_DATA_ITEM_LINE* p_debug_data_item_line = m_readDebugData.GetMatchLineItem((LPTSTR)(LPCTSTR)strFileName,nLine,bMatchLine);
		if(p_debug_data_item_line)
		{
			if(bInstall)
			{
				DEBUGGER_BREAKPOINT bp;
				bp.m_nLine = nLine;
				wcscpy(bp.m_tchFileName,(LPTSTR)(LPCTSTR)strFileName);
				bp.m_uiAddress = p_debug_data_item_line->m_ulAddr;
				bp.m_bInstalled = false;
				bp.m_bIsSingleLineBP = false;	
				InstallBreakPoint(bp);
			}
			else
			{			
				RemoveBreakPoint(p_debug_data_item_line->m_ulAddr);
			}

			return p_debug_data_item_line->m_lLine;
		}
	}
	//û���ڵ���״̬
	else
	{
		return -1;
	}

	return -2;
}

BOOL COTracer::GetDebuggerBPInfo(unsigned long ulAddr,DEBUGGER_BREAKPOINT* pBP)
{		
	DEBUG_DATA_ITEM_LINE* p_debug_data_item_line = m_readDebugData.GetMatchAddrItem(ulAddr);
	if(p_debug_data_item_line)
	{
		CString strFileName = m_readDebugData.m_strarrSourceFileNameList.GetAt(p_debug_data_item_line->m_usFileIndex);		

		pBP->m_nLine = p_debug_data_item_line->m_lLine;
		wcscpy(pBP->m_tchFileName,(LPTSTR)(LPCTSTR)strFileName);
		pBP->m_uiAddress = p_debug_data_item_line->m_ulAddr;

		return TRUE;
	}

	return FALSE;
}

void COTracer::InstallAllSingleLineBreakPoint()
{
	if(m_bLoadAllLineBreakPoint)
	{
		CODebugger::InstallAllSingleLineBreakPoint();

		return;
	}
	
	DEBUG_DATA_ITEM_LINE* p_debug_data_item_line = 0;
	for(m_readDebugData.m_debugDataItemLine.GetFirstElement();!m_readDebugData.m_debugDataItemLine.isEnd();
		m_readDebugData.m_debugDataItemLine.GetNextElement())
	{
		p_debug_data_item_line = m_readDebugData.m_debugDataItemLine.GetCurDebugDataItemLine();

		if(p_debug_data_item_line->m_ulAddr != GetCurBreakPointAddr())
		{
			DEBUGGER_BREAKPOINT* p_debugger_breakpoint = m_breakPointListUser.Search(p_debug_data_item_line->m_ulAddr);
			if(p_debugger_breakpoint == 0)
			{
				CString strFileName = m_readDebugData.m_strarrSourceFileNameList.GetAt(p_debug_data_item_line->m_usFileIndex);
				DEBUGGER_BREAKPOINT bp;
				bp.m_nLine = p_debug_data_item_line->m_lLine;
				wcscpy(bp.m_tchFileName,(LPTSTR)(LPCTSTR)strFileName);
				bp.m_uiAddress = p_debug_data_item_line->m_ulAddr;
				bp.m_bInstalled = false;
				bp.m_bIsSingleLineBP = true;
				InstallBreakPoint(bp,true);
			}			
		}
	}

	m_bLoadAllLineBreakPoint = TRUE;
}

void COTracer::RestoreAllSingleLineBreakPoint()
{	
	if(m_bLoadAllLineBreakPoint)
	{
		CODebugger::RestoreAllSingleLineBreakPoint();		
	}
}

void COTracer::ResumeBreakpoint()
{
	//�ָ���ǰ�����Ե��߳�
	if(m_hCurBreakPointThread)
	{
		if(m_hSuspendWnd)
		{
			::SendMessage(m_hSuspendWnd,WM_DEBUGGER_CONTINUE,NULL,NULL);
			m_hSuspendWnd = 0;
		}		

		::ResumeThread(m_hCurBreakPointThread);
		m_hCurBreakPointThread = NULL;
	}
}

BOOL COTracer::E_Breakpoint(DEBUG_EVENT* pDebugEvent)
{
	//��ͣ��ǰ�����Ե��߳�
	DEBUGGER_THREAD* p_cur_debugger_thread = m_debuggerThread.Search(pDebugEvent->dwThreadId);
	m_hCurBreakPointThread = p_cur_debugger_thread->m_hThread;	
	::SuspendThread(m_hCurBreakPointThread);

	unsigned long ulAddress = (unsigned long)pDebugEvent->u.Exception.ExceptionRecord.ExceptionAddress;
	DEBUGGER_BREAKPOINT bp;	
	if(GetDebuggerBPInfo(ulAddress,&bp))
	{
		CWnd* pWnd = SearchWnd(bp.m_tchFileName);
		if(pWnd)
		{
			m_hSuspendWnd = pWnd->GetSafeHwnd();
			::SendMessage(m_hSuspendWnd,WM_DEBUGGER_MOVE_TO,bp.m_nLine,NULL);
		}
	}	

	//����CPU����	
	DEBUGGER_CPU_CONTEXT* p_debugger_cpu_context = GetGlobalDebuggerCPUContext();
	GetCPUContext(m_hCurBreakPointThread,&p_debugger_cpu_context->m_debug_cpu);
	p_debugger_cpu_context->m_hCurThread = m_hCurBreakPointThread;
	p_debugger_cpu_context->m_uiStackP = p_cur_debugger_thread->m_uiStackP;
	p_debugger_cpu_context->m_uiDataSegmentAddr = m_readDebugData.m_uiDataSegmentAddr;
	p_debugger_cpu_context->m_uiDataSegmentLength = m_readDebugData.m_uiDataSegmentLength;
	::PostMessage(m_pWndOwner->GetSafeHwnd(),WM_DEBUGGER_SHOW_CPU_DATA,(WPARAM)p_debugger_cpu_context,NULL);

	return TRUE;
}

BOOL COTracer::E_SingleStep(DEBUG_EVENT *pDebugEvent)
{
	return FALSE;
}

BOOL COTracer::E_AccessViolation(DEBUG_EVENT *d)
{
	return FALSE; 
}

BOOL COTracer::E_DatatypeMisallignment(DEBUG_EVENT *d)
{
	return FALSE; 
}

CWnd* COTracer::SearchWnd(const CString& strFileName)
{	
	CDocument* pDoc = theApp.GetDocument(strFileName);
	if(pDoc == NULL)
	{
		::SendMessage(GetWndOwner()->GetSafeHwnd(),WM_OPEN_DOCUMENT,(WPARAM)((LPTSTR)(LPCTSTR)strFileName),NULL);
		pDoc = theApp.GetDocument(strFileName);
	}

	if(pDoc)
	{
		POSITION pos1 = pDoc->GetFirstViewPosition();
		while(pos1)
		{
			CView* pView = pDoc->GetNextView(pos1);		
			if(pView->IsKindOf(RUNTIME_CLASS(COLIDEView)))
			{
				return pView;
			}
		}
	}	

	return NULL;
}

//���Խ��̽���
BOOL COTracer::D_ExitProcess(DEBUG_EVENT *pDebugEvent)
{
	return TRUE;
}
