
#include "stdafx.h"
#include "DebugThread.h"
#include "OTracer.h"
#include "MainFrm.h"

int g_nSynchroSignal = 0;  //ͬ���ź���

void CreateSynchroSignal()
{
	g_nSynchroSignal = 1;
}

void ClearSynchroSignal()
{
	g_nSynchroSignal = 0;
}

void WaitSynchroSignal()
{
	//ֻҪ�źŴ��ھ�һֱ�ȴ�
	while(g_nSynchroSignal)
	{
		MSG msg;
		if(PeekMessage(&msg,0,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);  
			DispatchMessage(&msg);   
		}
	}
}

void SendThreadMessage(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	CreateSynchroSignal();
	::PostThreadMessage(idThread,Msg,wParam,lParam);
	WaitSynchroSignal();
}

DWORD WINAPI DebugThread( LPVOID lpParam ) 
{
	CMainFrame* pMainFrame = (CMainFrame*)lpParam;

	int nResult = -1; //С��0��ʾ����ʧ��

	COTracer debugTracer;
	debugTracer.SetWndOwner(pMainFrame);

	CString strExeFileName;
	if(pMainFrame->GetCurProjectPropertyExeFileName(strExeFileName))
	{					
		if(debugTracer.BeginDebug((LPTSTR)(LPCTSTR)strExeFileName))
		{
			MSG msg;
			while(debugTracer.IsDebuging())
			{
				if(::PeekMessage(&msg,0,0,0,PM_REMOVE) && (msg.message > 0))
				{
					int nMsg = debugTracer.DoMessage(msg);

					//��Ϣ������������ͬ���ź�
					ClearSynchroSignal();

					//�����Ϣ�����������С��0��ʾ������������
					if(nMsg < 0)
					{
						nResult = 1;
						break;
					}
				}

				debugTracer.run(100);
			}
		}
	}
	
	debugTracer.DebugEnd();

	return nResult;
}
