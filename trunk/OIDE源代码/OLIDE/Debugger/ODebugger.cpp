
#include "stdafx.h"
#include "ODebugger.h"

CODebugger::CODebugger()
{
	m_chFileName[0] = 0;
	m_uiProcessID = 0;	// ��ǰ�����Խ��̵�ID
	m_uiThreadID = 0;   // ���߳�ID
	m_hProcess = NULL;	// ���̾��
	m_hThread = NULL;	// ���߳̾��
	
	m_bActive = false;	// �״̬
	m_ulCurBreakPointAddr = 0;
	
	fbpfunc=NULL;
	bpfunc=NULL;
	exitfunc=NULL;
	unhfunc=NULL;

	SetDebugPrivilege(GetCurrentProcess());
	InitBlackmagic();
}

CODebugger::~CODebugger()
{
	Exorcism();
}

bool CODebugger::load(TCHAR *filename) 
{
	return load(filename,NULL);
}

bool CODebugger::load(TCHAR *filename,TCHAR *commandline) 
{
	PROCESS_INFORMATION		pi;
	STARTUPINFO				si;
	
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	if(!CreateProcess(filename , // �ļ���
		commandline,             // ������
		NULL,             // Process handle not inheritable. 
		NULL,             // Thread handle not inheritable. 
		FALSE,            // Set handle inheritance to FALSE. 
		DEBUG_ONLY_THIS_PROCESS, // ���̵���ģʽ, ���������ӽ���
		NULL,             // Use parent's environment block. 
		NULL,             // Use parent's starting directory. 
		&si,              // Pointer to STARTUPINFO structure.
		&pi )             // Pointer to PROCESS_INFORMATION structure.
		) 
	{
		return false;
	} 

	//
	// CreateProcess worked
	//
	m_uiThreadID = pi.dwThreadId;
	m_hThread = pi.hThread;	
	m_uiProcessID = pi.dwProcessId;
	m_hProcess = pi.hProcess;
	
	m_bActive = true;

#ifdef _UNICODE
	wcscpy(m_chFileName,filename);
#else
	strcpy(m_chFileName,filename);
#endif	

	m_debuggerThread.ClearList();
	m_singleStepList.ClearList();

	return true;
}

void CODebugger::TerminateDebug()
{
	if(IsDebuging())
	{
		SetStopDebug();

		//ǿ����ֹ�����ԵĽ���
		TerminateProcess(m_hProcess,0);
	}
}

bool CODebugger::DebugProcessIsRuning()
{
	DWORD dwProcessCode;
	::GetExitCodeProcess(m_hProcess,&dwProcessCode);
	if(dwProcessCode == STILL_ACTIVE)
		return true;

	return false;
}

bool CODebugger::IsDebuging()
{
	if(!DebugProcessIsRuning())
	{
		m_bActive = false;
	}

	return m_bActive;
}

bool CODebugger::run(unsigned int msec)
{
	DEBUG_EVENT	deDebugEvent;	//�����¼���Ϣ
	bool bResult = true;

	// �ȴ������¼�
	if(m_bActive && WaitForDebugEvent(&deDebugEvent, msec)) 
	{
		//��������¼�
		switch(deDebugEvent.dwDebugEventCode)
		{ 
			//�����쳣�¼�
		case EXCEPTION_DEBUG_EVENT:
			{
				bResult = OnDebugException(deDebugEvent);
				break;
			}

			//�����߳�
		case CREATE_THREAD_DEBUG_EVENT: 	
			{
				AddThread(deDebugEvent.dwThreadId,
					deDebugEvent.u.CreateThread.hThread,
					(DWORD)deDebugEvent.u.CreateThread.lpStartAddress,
					(DWORD)deDebugEvent.u.CreateThread.lpThreadLocalBase);

				// call overloady
				D_CreateThread(&deDebugEvent);

				break;
			}

			//��������
		case CREATE_PROCESS_DEBUG_EVENT:
			{
				//m_hProcess = deDebugEvent.u.CreateProcessInfo.hProcess;
				//m_hThread = deDebugEvent.u.CreateProcessInfo.hThread;				

				//�����߳���ӵ��߳�����
				DEBUGGER_THREAD* pDebuggerThread = AddThread(deDebugEvent.dwThreadId,deDebugEvent.u.CreateProcessInfo.hThread,0,0);
				pDebuggerThread->m_bIsMainThread = true;

				// call overloady
				D_CreateProcess(&deDebugEvent);

				// �رս����ļ����
				if(deDebugEvent.u.CreateProcessInfo.hFile)
				{
					CloseHandle(deDebugEvent.u.CreateProcessInfo.hFile);
				}

				break;
			}

			//�����߳�
		case EXIT_THREAD_DEBUG_EVENT: 		
			{
				RemoveThread(deDebugEvent.dwThreadId);

				// call overloady
				D_ExitThread(&deDebugEvent);

				break;
			}			

			//��������
		case EXIT_PROCESS_DEBUG_EVENT:	
			{
				if(exitfunc != NULL) 
				{					
					(*exitfunc)(&deDebugEvent);
				}				

				// call overloady
				D_ExitProcess(&deDebugEvent);

				break;
			}			

			//����DLL
		case LOAD_DLL_DEBUG_EVENT: 		
			{				
				break;
			}			

			//ж��DLL
		case UNLOAD_DLL_DEBUG_EVENT: 		
			break;

			//��������ַ���
		case OUTPUT_DEBUG_STRING_EVENT: 
			{
				// call overloady
				D_OutputDebugString(&deDebugEvent);

				break;
			}
		default:
			{
				bResult = false;
			}
		}

		DWORD dwContinueStatus;
		dwContinueStatus = bResult?DBG_CONTINUE:DBG_EXCEPTION_NOT_HANDLED;
		ContinueDebugEvent(deDebugEvent.dwProcessId, deDebugEvent.dwThreadId,dwContinueStatus);
	}
	else
	{
		return false;
	}

	return true;
}

// �жϴ������
BOOL CODebugger::OnDebugException(DEBUG_EVENT& deDebugEvent)
{
	unsigned long ulAddress = (unsigned long)deDebugEvent.u.Exception.ExceptionRecord.ExceptionAddress;

	//�����쳣
	switch (deDebugEvent.u.Exception.ExceptionRecord.ExceptionCode) 
	{ 
		//�ϵ��쳣
	case EXCEPTION_BREAKPOINT:
		{			
			//�����ϵ��쳣�ĵ�ַ			
			DEBUGGER_BREAKPOINT* pBreakPoint = m_breakPointListUser.Search(ulAddress); //�����ϵ�
			if(pBreakPoint == NULL) //�ϵ㲻�ڶϵ��б���
			{
				break;
			}

			m_ulCurBreakPointAddr = ulAddress;

			//�ϵ㷢��
			E_Breakpoint(&deDebugEvent);
			if(bpfunc != NULL)
			{
				(*bpfunc)(&deDebugEvent);
			}

			//�õ��߳�
			HANDLE hThread = m_debuggerThread.Search(deDebugEvent.dwThreadId)->m_hThread;

			CONTEXT ct;
			//�õ��߳�������
			ct.ContextFlags = CONTEXT_FULL;
			if(hThread && GetThreadContext(hThread, &ct))
			{
				//��ԭ���Ĵ���д��
				RestoreBreakPoint(pBreakPoint);
				
				//��ͣ���������̣߳���֤����ִ�в��������߳��ж�
				SuspendAllThread(hThread);

				//Eipָ���1��ָ��ԭ����������д�
				ct.Eip--;

				//���õ�������
				ct.EFlags |= EFLAGS_TRAP;

				//��ӵ���ִ��
				if(pBreakPoint->m_bIsSingleLineBP == false)
				{
					DEBUGGER_SINGLE_STEP singleStep;
					singleStep.m_uiAddress = ulAddress;
					singleStep.m_uiThreadID = deDebugEvent.dwThreadId;
					m_singleStepList.Add(singleStep);
				}
				
				//�����̵߳���������Ϣ
				SetThreadContext(hThread, &ct);

				return true;
			}
			
			break;
		}

		//�����쳣
	case EXCEPTION_SINGLE_STEP:
		{
			E_SingleStep(&deDebugEvent);

			//�õ������ϵ��ָ��
			DEBUGGER_SINGLE_STEP* pSingleStep = NULL;
			pSingleStep = m_singleStepList.SearchThread(deDebugEvent.dwThreadId);
			if(pSingleStep)
			{
				//�������öϵ�
				DEBUGGER_BREAKPOINT* pDbp = m_breakPointListUser.Search(pSingleStep->m_uiAddress);
				if(pDbp && (pDbp->m_bIsSingleLineBP == false))
				{
					SetBreakPoint(pDbp);
				}

				m_singleStepList.RemoveData(pSingleStep);

				ResumeAllThread(deDebugEvent.dwThreadId);
			}

			break;
		}

		//
		//������쳣�¼�������,��Ĭ�ϴ���
		//

		//Υ�����
	case EXCEPTION_ACCESS_VIOLATION:
		{
			E_AccessViolation(&deDebugEvent);
			if (deDebugEvent.u.Exception.dwFirstChance) 
			{
				if(unhfunc != NULL)
				{
					(*unhfunc)(&deDebugEvent); 
				}
				else
				{
					default_unhandled(&deDebugEvent);
				}
			}

			break;
		}

	case EXCEPTION_PRIV_INSTRUCTION: 				
		{
			if ((deDebugEvent.u.Exception.dwFirstChance == 0) || 
				(deDebugEvent.u.Exception.ExceptionRecord.ExceptionFlags == EXCEPTION_NONCONTINUABLE) ) 
			{						
				if(unhfunc != NULL)
				{
					(*unhfunc)(&deDebugEvent); 
				}
				else
				{
					default_unhandled(&deDebugEvent);
				}
			}

			break;
		}

		/*
		case EXCEPTION_DATATYPE_MISALIGNMENT: 	
		//��Ctrl+C ��
		case DBG_CONTROL_C:
		case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
		case EXCEPTION_ILLEGAL_INSTRUCTION:
		case EXCEPTION_IN_PAGE_ERROR:
		case EXCEPTION_INT_DIVIDE_BY_ZERO:
		case EXCEPTION_INT_OVERFLOW:			
		case EXCEPTION_STACK_OVERFLOW:
		*/
	default:
		{
			if(deDebugEvent.u.Exception.dwFirstChance == 0) 
			{				
				if(unhfunc != NULL)
				{
					(*unhfunc)(&deDebugEvent); 
				}
				else
				{
					default_unhandled(&deDebugEvent);
				}
			}
			
			return FALSE;
		}
	} 

	return TRUE;
}

//����ָ����쳣
bool CODebugger::SetSingleStep(HANDLE hThread)
{
	CONTEXT ct;
	//�õ��߳�������
	ct.ContextFlags = CONTEXT_FULL;
	if(hThread && GetThreadContext(hThread, &ct))
	{
		//��ͣ���������̣߳���֤����ִ�в��������߳��ж�
		SuspendAllThread(hThread);

		//���õ�������
		ct.EFlags |= EFLAGS_TRAP;
		
		//�����̵߳���������Ϣ
		SetThreadContext(hThread, &ct);

		return true;
	}

	return false;
}

DEBUGGER_THREAD* CODebugger::AddThread(DWORD threadID, HANDLE ht, DWORD lpStartAddress, DWORD lpThreadLocalBase) 
{
	DEBUGGER_THREAD	debuggerThread;
	DEBUGGER_CPU	cpu;

	debuggerThread.m_uiThreadID = threadID;
	debuggerThread.m_hThread = ht;
	debuggerThread.m_uiStartAddress = (DWORD)lpStartAddress;
	debuggerThread.m_uiThreadLocalBase = (DWORD)lpThreadLocalBase;

	ReadThreadBasicInformation(debuggerThread.m_hThread, &(debuggerThread.m_tbiBasics));
	ReadTEB(debuggerThread.m_hThread);	
	GetCPUContext(debuggerThread.m_hThread,&cpu);
	debuggerThread.m_uiStackP = cpu.ESP;
	
	return m_debuggerThread.Add(debuggerThread);
}

void CODebugger::RemoveThread(DWORD threadID) 
{
	DEBUGGER_THREAD* pDebuggerThread = m_debuggerThread.Search(threadID);
	if(pDebuggerThread)
	{
		m_debuggerThread.RemoveData(pDebuggerThread);
	}
}

void CODebugger::default_unhandled(DEBUG_EVENT *d) 
{
	
}

// ��ͣ�����߳�
void CODebugger::SuspendAllThread(DWORD dwThreadId)
{	
	DEBUGGER_THREAD* pDebuggerThread = NULL;
	for(m_debuggerThread.GetFirstElement();!m_debuggerThread.isEnd();m_debuggerThread.GetNextElement())	
	{
		pDebuggerThread = m_debuggerThread.GetCurDebuggerThread();
		// �����������е��̶߳���ͣ
		if (pDebuggerThread->m_uiThreadID != dwThreadId)
		{
			::SuspendThread(pDebuggerThread->m_hThread);
		}
	}
}

void CODebugger::SuspendAllThread(HANDLE hThread)
{
	DEBUGGER_THREAD* pDebuggerThread = NULL;
	for(m_debuggerThread.GetFirstElement();!m_debuggerThread.isEnd();m_debuggerThread.GetNextElement())	
	{
		pDebuggerThread = m_debuggerThread.GetCurDebuggerThread();
		// �����������е��̶߳���ͣ
		if (pDebuggerThread->m_hThread != hThread)
		{
			::SuspendThread(pDebuggerThread->m_hThread);
		}
	}
}

//  �ָ������߳�
void CODebugger::ResumeAllThread(DWORD dwThreadId)
{
	DEBUGGER_THREAD* pDebuggerThread = NULL;
	for(m_debuggerThread.GetFirstElement();!m_debuggerThread.isEnd();m_debuggerThread.GetNextElement())	
	{
		pDebuggerThread = m_debuggerThread.GetCurDebuggerThread();
		// �����������е��̶߳��ָ�
		if (pDebuggerThread->m_uiThreadID != dwThreadId)
		{
			::ResumeThread(pDebuggerThread->m_hThread);
		}
	}
}

bool CODebugger::ReadTEB(HANDLE th) 
{	
	bool	rv = false;
	DWORD	dwLength = 0;

	DEBUGGER_THREAD* pDebuggerThread = NULL;
	pDebuggerThread = m_debuggerThread.Search(th);
	if(pDebuggerThread != NULL)
	{
		rv = ReadProcessMemory(
			m_hProcess,
			pDebuggerThread->m_tbiBasics.TebBaseAddress,
			&pDebuggerThread->m_ThreadEnvironmentBlock,
			sizeof(TEB),
			&dwLength);
	}

	return rv;
}

bool CODebugger::SetBreakPoint(DEBUGGER_BREAKPOINT *bp)
{
	DWORD	oldprot, oldprot2;
	BYTE	ccByte = 0xCC;

	//
	// Make the page in question writable 
	//
	if ( ! VirtualProtectEx(
		m_hProcess,
		(LPVOID)bp->m_uiAddress,
		sizeof(BYTE),
		PAGE_EXECUTE_READWRITE,
		&oldprot) )
	{			
		return false;
	}

	//
	// Read original opcode
	//
	if (!ReadProcessMemory(
		m_hProcess,
		(LPCVOID)bp->m_uiAddress,
		&(bp->m_ucOriginalData),
		sizeof(BYTE),
		NULL) )
	{
		return false;
	}

	//
	// replace with 0xCC
	//
	if (!WriteProcessMemory(
		m_hProcess,
		(LPVOID)bp->m_uiAddress,
		&ccByte,
		sizeof(ccByte),
		NULL) )
	{
			
		return false;
	}

	//
	// restore original permissions
	//
	if ( ! VirtualProtectEx(
		m_hProcess,
		(LPVOID)bp->m_uiAddress,
		sizeof(BYTE),
		oldprot,
		&oldprot2) )
	{
		return false;
	}

	FlushInstructionCache(m_hProcess,NULL,0);

	bp->m_bInstalled = true;

	return true;
}


bool CODebugger::RestoreBreakPoint(DEBUGGER_BREAKPOINT *bp) 
{
	DWORD						oldprot, oldprot2;

	//
	// Make the page in question writable 
	//
	if ( ! VirtualProtectEx(
		m_hProcess,
		(LPVOID)bp->m_uiAddress,
		sizeof(BYTE),
		PAGE_EXECUTE_READWRITE,
		&oldprot) )
	{
		return false;
	}

	//
	// replace with original byte
	//
	if (!WriteProcessMemory(
		m_hProcess,
		(LPVOID)bp->m_uiAddress,
		&(bp->m_ucOriginalData),
		sizeof(bp->m_ucOriginalData),
		NULL) )
	{
		return false;
	}

	//
	// restore original permissions
	//
	if ( ! VirtualProtectEx(
		m_hProcess,
		(LPVOID)bp->m_uiAddress,
		sizeof(BYTE),
		oldprot,
		&oldprot2) )
	{
		return false;
	}

	FlushInstructionCache(m_hProcess,NULL,0);	

	bp->m_bInstalled = false;

	return true;
}

bool CODebugger::InstallBreakPoint(DEBUGGER_BREAKPOINT& bp,bool bNoSearch)
{
	DEBUGGER_BREAKPOINT* p_debugger_breakpoint = 0;
	if(bNoSearch)
	{
		//���һ���¶ϵ�
		p_debugger_breakpoint = m_breakPointListUser.Add(bp);
	}
	else
	{
		p_debugger_breakpoint = m_breakPointListUser.Search(bp.m_uiAddress);
		if(p_debugger_breakpoint)
		{
			p_debugger_breakpoint->m_bIsSingleLineBP = bp.m_bIsSingleLineBP;

			//�ϵ��Ѿ�����װ
			if(p_debugger_breakpoint->m_bInstalled)
			{
				return true;	
			}
		}
		else
		{
			//û���ҵ�ָ����ַ�Ķϵ�����һ���ϵ�
			p_debugger_breakpoint = m_breakPointListUser.Add(bp);
		}	
	}	

	return SetBreakPoint(p_debugger_breakpoint);
}

bool CODebugger::DisableBreakPoint(DWORD addr)
{
	DEBUGGER_BREAKPOINT* pDebuggerBreakpoint = NULL; 
	pDebuggerBreakpoint = m_breakPointListUser.Search(addr);

	if(pDebuggerBreakpoint == NULL) 
	{	
		return false;
	}

	return RestoreBreakPoint(pDebuggerBreakpoint);
}

bool CODebugger::RemoveBreakPoint(DWORD addr)
{
	DEBUGGER_BREAKPOINT* pDebuggerBreakpoint = NULL;
	pDebuggerBreakpoint = m_breakPointListUser.Search(addr);

	if(pDebuggerBreakpoint == NULL)
	{
		return false;
	}

	if(pDebuggerBreakpoint->m_bInstalled)
	{
		RestoreBreakPoint(pDebuggerBreakpoint);
	}	

	m_breakPointListUser.RemoveData(pDebuggerBreakpoint);

	return true;
}

void CODebugger::InstallAllSingleLineBreakPoint()
{
	DEBUGGER_BREAKPOINT* p_debugger_breakpoint = 0;
	for(m_breakPointListUser.GetFirstElement();!m_breakPointListUser.isEnd();m_breakPointListUser.GetNextElement())
	{
		p_debugger_breakpoint = m_breakPointListUser.GetCurBreakPoint();
		if( (p_debugger_breakpoint->m_bIsSingleLineBP)    && 
			(p_debugger_breakpoint->m_bInstalled == false) && 
			(p_debugger_breakpoint->m_uiAddress != GetCurBreakPointAddr()))
		{
			SetBreakPoint(p_debugger_breakpoint);
		}
	}
}

void CODebugger::RestoreAllSingleLineBreakPoint()
{
	DEBUGGER_BREAKPOINT* p_debugger_breakpoint = 0;
	for(m_breakPointListUser.GetFirstElement();!m_breakPointListUser.isEnd();m_breakPointListUser.GetNextElement())
	{
		p_debugger_breakpoint = m_breakPointListUser.GetCurBreakPoint();
		if((p_debugger_breakpoint->m_bIsSingleLineBP) && (p_debugger_breakpoint->m_bInstalled))
		{
			RestoreBreakPoint(p_debugger_breakpoint);
		}		
	}
}

void CODebugger::RemoveAllBreakPoint()
{
	m_breakPointListUser.ClearList();
}

bool CODebugger::SetEIP(HANDLE hThread,unsigned int uiNewEIP) 
{
	CONTEXT	ctx;

	ctx.ContextFlags = CONTEXT_CONTROL;
	if(!GetThreadContext(hThread, &ctx)) 
	{		
		return false;
	}

	ctx.Eip = uiNewEIP;

	if(!SetThreadContext(hThread, &ctx)) 
	{		
		return false;
	}

	return true;
}

bool CODebugger::GetCPUContext(HANDLE hhThread, DEBUGGER_CPU *cpu)
{
	CONTEXT		ctx;

	ctx.ContextFlags = CONTEXT_FULL;
	if (!GetThreadContext(hhThread, &ctx)) 
	{
		return false;
	}

	cpu->EAX = ctx.Eax;
	cpu->ECX = ctx.Ecx;
	cpu->EDX = ctx.Edx;
	cpu->EBX = ctx.Ebx;
	cpu->ESI = ctx.Esi;
	cpu->EDI = ctx.Edi;
	cpu->EBP = ctx.Ebp;
	cpu->ESP = ctx.Esp;
	cpu->EIP = ctx.Eip;
	cpu->CS = ctx.SegCs;
	cpu->DS = ctx.SegDs;
	cpu->ES = ctx.SegEs;
	cpu->FS = ctx.SegFs;
	cpu->GS = ctx.SegGs;
	cpu->SS = ctx.SegSs;
	cpu->EFlags = ctx.EFlags;

	memcpy(cpu->ST0,&ctx.FloatSave.RegisterArea[00],10);
	memcpy(cpu->ST1,&ctx.FloatSave.RegisterArea[10],10);
	memcpy(cpu->ST2,&ctx.FloatSave.RegisterArea[20],10);
	memcpy(cpu->ST3,&ctx.FloatSave.RegisterArea[30],10);
	memcpy(cpu->ST4,&ctx.FloatSave.RegisterArea[40],10);
	memcpy(cpu->ST5,&ctx.FloatSave.RegisterArea[50],10);
	memcpy(cpu->ST6,&ctx.FloatSave.RegisterArea[60],10);
	memcpy(cpu->ST7,&ctx.FloatSave.RegisterArea[70],10);
	
	/*cpu->XMM1 = ctx.Xmm1;
	cpu->XMM2 = ctx.Xmm2;
	cpu->XMM3 = ctx.Xmm3;
	cpu->XMM4 = ctx.Xmm4;
	cpu->XMM5 = ctx.Xmm5;
	cpu->XMM6 = ctx.Xmm6;
	cpu->XMM7 = ctx.Xmm7;*/

	return true;
}


bool CODebugger::SetCPUContext(HANDLE hhThread, DEBUGGER_CPU* cpu) 
{
	CONTEXT		ctx;

	ctx.Eax = cpu->EAX;
	ctx.Ecx = cpu->ECX;
	ctx.Edx = cpu->EDX;
	ctx.Ebx = cpu->EBX;
	ctx.Esi = cpu->ESI;
	ctx.Edi = cpu->EDI;
	ctx.Ebp = cpu->EBP;
	ctx.Esp = cpu->ESP;
	ctx.Eip = cpu->EIP;
	ctx.SegCs = cpu->CS;
	ctx.SegDs = cpu->DS;
	ctx.SegEs = cpu->ES;
	ctx.SegFs = cpu->FS;
	ctx.SegGs = cpu->GS;
	ctx.SegSs = cpu->SS;
	ctx.EFlags = cpu->EFlags;

	memcpy(&ctx.FloatSave.RegisterArea[00],cpu->ST0,10);
	memcpy(&ctx.FloatSave.RegisterArea[10],cpu->ST1,10);
	memcpy(&ctx.FloatSave.RegisterArea[20],cpu->ST2,10);
	memcpy(&ctx.FloatSave.RegisterArea[30],cpu->ST3,10);
	memcpy(&ctx.FloatSave.RegisterArea[40],cpu->ST4,10);
	memcpy(&ctx.FloatSave.RegisterArea[50],cpu->ST5,10);
	memcpy(&ctx.FloatSave.RegisterArea[60],cpu->ST6,10);
	memcpy(&ctx.FloatSave.RegisterArea[70],cpu->ST7,10);

	/*ctx.Xmm0 = cpu->XMM0;
	ctx.Xmm1 = cpu->XMM1;
	ctx.Xmm2 = cpu->XMM2;
	ctx.Xmm3 = cpu->XMM3;
	ctx.Xmm4 = cpu->XMM4;
	ctx.Xmm5 = cpu->XMM5;
	ctx.Xmm6 = cpu->XMM6;
	ctx.Xmm7 = cpu->XMM7;*/

	ctx.ContextFlags = CONTEXT_FULL;
	if (!SetThreadContext(hhThread, &ctx)) 
	{		
		return false;
	}
	
	return true;
}

// Function to set priviledges stolen from Dan Kurc by Halvar, 
// in turn stolen from him by FX
bool CODebugger::SetDebugPrivilege( HANDLE hProcess ) 
{
	LUID luid ;
	TOKEN_PRIVILEGES privs ;
	HANDLE hToken = NULL ;
	DWORD dwBufLen = 0 ;
	char buf[1024] ;

	ZeroMemory( &luid,sizeof(luid) ) ;

	if(!LookupPrivilegeValue( NULL, SE_DEBUG_NAME, &luid ))
		return false ;

	privs.PrivilegeCount = 1 ;
	privs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED ;
	memcpy( &privs.Privileges[0].Luid, &luid, sizeof(privs.Privileges[0].Luid )
		) ;


	if(!OpenProcessToken( hProcess, TOKEN_ALL_ACCESS,&hToken))
		return false ;

	if(!AdjustTokenPrivileges( hToken, FALSE, &privs,
		sizeof(buf),(PTOKEN_PRIVILEGES)buf, &dwBufLen ) )
		return false ;

	return true ;
}