// MemWatchPane.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "MemWatchPane.h"


// CMemWatchPane

IMPLEMENT_DYNAMIC(CMemWatchPane, CDockablePane)

CMemWatchPane::CMemWatchPane()
{

}

CMemWatchPane::~CMemWatchPane()
{
}


BEGIN_MESSAGE_MAP(CMemWatchPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CMemWatchPane ��Ϣ�������



int CMemWatchPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	m_wndMemWatch.Create(IDD_MEM_WATCH_WND,this);
	m_wndMemWatch.ShowWindow(SW_SHOW);

	return 0;
}

void CMemWatchPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if(m_wndMemWatch.GetSafeHwnd())
	{
		m_wndMemWatch.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);		
	}	
}
