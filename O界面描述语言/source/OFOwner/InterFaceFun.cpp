
#include "stdafx.h"
#include "InterFaceFun.h"
#include "../ofl/OFL.h"

//���е��¼������������밴���¸�ʽ����
//int _stdcall ������(void*,WPARAM,LPARAM)

int _stdcall InterFaceFun(void* pWnd,WPARAM wParam, LPARAM lParam)
{
	::MessageBox(0,"�������Բ���","OFL",0);

	return 0;
}

int _stdcall �����ڹر�(void* pWnd,WPARAM wParam, LPARAM lParam)
{
	::PostQuitMessage(0);

	return 0;
}

int _stdcall �����ڴ���(void* pWnd,WPARAM wParam, LPARAM lParam)
{	
	void* pControl =  OFGetControl("������.��һ��.TreeView1");

	return 0;
}

int _stdcall �˵�����(void* pWnd,WPARAM wParam, LPARAM lParam)
{	
	//wParam�ǲ˵���ָ��
	//lParam�ǲ˵�����ָ��

	char* pchMenuText = MenuItem_GetText((void*)lParam);
	char chText[256];
	wsprintf(chText,"�����˲˵�:%s",pchMenuText);
	::MessageBox(0,chText,"OFL",0);

	return 0;
}

