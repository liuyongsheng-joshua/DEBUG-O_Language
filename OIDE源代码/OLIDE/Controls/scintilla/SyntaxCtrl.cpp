// SyntaxCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SyntaxCtrl.h"

// CSyntaxCtrl

IMPLEMENT_DYNAMIC(CSyntaxCtrl, CScintillaCtrl)

CSyntaxCtrl::CSyntaxCtrl()
{
	
}

CSyntaxCtrl::~CSyntaxCtrl()
{
}


BEGIN_MESSAGE_MAP(CSyntaxCtrl, CScintillaCtrl)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()	
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()	
	ON_WM_HELPINFO()
END_MESSAGE_MAP()



// CSyntaxCtrl ��Ϣ�������

void CSyntaxCtrl::OnRButtonDown(UINT nFlags, CPoint point)
{
	GetParent()->SendMessage(WM_RBUTTONDOWN,(WPARAM)nFlags,MAKELPARAM(point.x,point.y));
}

void CSyntaxCtrl::OnRButtonUp(UINT nFlags, CPoint point)
{
	GetParent()->SendMessage(WM_RBUTTONUP,(WPARAM)nFlags,MAKELPARAM(point.x,point.y));
}

void CSyntaxCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	switch(nChar)
	{	
	case VK_RETURN:	//����ǻس�		
	case VK_TAB:    //TAB��	
		{
			//�����SHIFT
			if(GetKeyState(VK_SHIFT)&0x8000)
				break;

			GetParent()->SendMessage(WM_CHAR,(WPARAM)nChar,MAKELPARAM(nRepCnt,nFlags));			
			return;
		}		
	}

	CScintillaCtrl::OnChar(nChar, nRepCnt, nFlags);

	//Back��
	if(nChar == VK_BACK)
	{
		GetParent()->SendMessage(WM_CHAR,(WPARAM)nChar,MAKELPARAM(nRepCnt,nFlags));	
	}
}

void CSyntaxCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ	

	switch(nChar)
	{
	case VK_RETURN:	//����ǻس�
	case VK_TAB:    //TAB��	
		return;
	}

	CScintillaCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSyntaxCtrl::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	switch(nChar)
	{	
	case VK_RETURN:	//����ǻس�
	case VK_TAB:    //TAB��	
		return;
	}

	CScintillaCtrl::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CSyntaxCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	GetParent()->SendMessage(WM_LBUTTONDOWN,(WPARAM)nFlags,MAKELPARAM(point.x,point.y));

	CScintillaCtrl::OnLButtonDown(nFlags, point);
}

void CSyntaxCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	GetParent()->SendMessage(WM_LBUTTONUP,(WPARAM)nFlags,MAKELPARAM(point.x,point.y));

	CScintillaCtrl::OnLButtonUp(nFlags, point);
}

BOOL CSyntaxCtrl::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CScintillaCtrl::OnHelpInfo(pHelpInfo);
}

int CSyntaxCtrl::GetCurrentLine() 
{
	int line = LineFromPosition (GetCurrentPos());
	return line;
}