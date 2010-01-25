// CPUWatchPane.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "CPUWatchPane.h"


// CCPUWatchPane

IMPLEMENT_DYNAMIC(CCPUWatchPane, CDockablePane)

CCPUWatchPane::CCPUWatchPane()
{

}

CCPUWatchPane::~CCPUWatchPane()
{
}


BEGIN_MESSAGE_MAP(CCPUWatchPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CCPUWatchPane ��Ϣ�������


int CCPUWatchPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	m_wndCPUWatch.Create(IDD_CPU_WATCH_WND,this);
	m_wndCPUWatch.ShowWindow(SW_SHOW);

	return 0;
}

void CCPUWatchPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if(m_wndCPUWatch.GetSafeHwnd())
	{
		m_wndCPUWatch.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
		//m_wndCPUWatch.MoveWindow(0,0,cx,cy);
	}	
}
