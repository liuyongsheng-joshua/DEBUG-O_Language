
#include "stdafx.h"
#include "InterFaceFun.h"
#include "../ofl/OFL.h"

//���е��¼������������밴���¸�ʽ����
//int _stdcall ������(void*,WPARAM,LPARAM)

int _stdcall ��ܴ��ڹر�(void* pWnd,WPARAM wParam, LPARAM lParam)
{
	int nResult = ::MessageBox(Ctrl_GetHandle(pWnd),"�����Ҫ�˳���?","��ܴ���",MB_YESNO);
	if(nResult == IDNO)
	{
		return false; //����false,���ڽ����ᱻ�ر�
	}

	return true; 
}

int _stdcall ��ܴ��ڴ���(void* pWnd,WPARAM wParam, LPARAM lParam)
{	
	void* pRightUpEdit =  OFGetControl("��ܴ���.��һ��.�������.���ϱ༭��");
	if(pRightUpEdit)
	{		
		Edit_InsertText(pRightUpEdit,"\r\n���Ǵ��ڴ���ʱ���ӵ�����:)",true);
	}

	return 0;
}

int _stdcall ��ܴ��ڲ˵�����(void* pWnd,WPARAM wParam, LPARAM lParam)
{
	//wParam�ǲ˵���ָ��
	//lParam�ǲ˵�����ָ��

	unsigned short usID = MenuItem_GetId((void*)lParam);
	if(usID == 204) //�˳��˵�
	{
		void* pMainWnd = OFGetControl("��ܴ���");
		if(pMainWnd)
		{
			SendMessage(Ctrl_GetHandle(pMainWnd),WM_CLOSE,0,0);
		}		
	}
	else if(usID == 401) //���ڲ˵�
	{
		void* pMainWnd = OFGetControl("��ܴ���");
		if(pMainWnd)
		{
			//��ʾ���ڴ���
			OFShowWnd("���ڶԻ���",pMainWnd);
		}		
	}
	else
	{
		char* pchMenuText = MenuItem_GetText((void*)lParam);
		char chText[256];
		wsprintf(chText,"�����˲˵�:%s",pchMenuText);
		::MessageBox(0,chText,"OFL",0);
	}	

	return 0;
}

int _stdcall ���ڶԻ���_�ر�(void* pWnd,WPARAM wParam, LPARAM lParam)
{
	HWND hButton = Ctrl_GetHandle(pWnd);
	::SendMessage(::GetParent(hButton),WM_CLOSE,0,0); //�򸸴��ڷ��͹ر���Ϣ

	return 0;
}