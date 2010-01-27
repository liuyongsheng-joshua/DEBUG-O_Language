
#include "OWI_Window.h"
#include "../../CreateWnd/windows/EventWnd.h"

OFL_API void _stdcall Wnd_SetMaximized(void* pWnd,bool max)
{
	((CEventWnd*)pWnd)->SetMaximized(max);
}

OFL_API bool _stdcall Wnd_IsMaximized(void* pWnd)
{
	return ((CEventWnd*)pWnd)->IsMaximized();
}

OFL_API void _stdcall Wnd_SetMinimized(void* pWnd,bool min)
{
	((CEventWnd*)pWnd)->SetMinimized(min);
}

OFL_API bool _stdcall Wnd_IsMinimized(void* pWnd)
{
	return ((CEventWnd*)pWnd)->IsMinimized();
}

OFL_API void _stdcall Wnd_SetTopmost(void* pWnd,bool topmost)
{
	((CEventWnd*)pWnd)->SetTopmost(topmost);
}

OFL_API bool _stdcall Wnd_GetTopmost(void* pWnd)
{
	return ((CEventWnd*)pWnd)->GetTopmost();
}

OFL_API void _stdcall Wnd_SetSmallIcon(void* pWnd,HICON icon)
{
	((CEventWnd*)pWnd)->SetSmallIcon(icon);
}

OFL_API void _stdcall Wnd_SetBigIcon(void* pWnd,HICON icon)
{
	((CEventWnd*)pWnd)->SetBigIcon(icon);
}

OFL_API HICON _stdcall Wnd_GetSmallIcon(void* pWnd)
{
	return ((CEventWnd*)pWnd)->GetSmallIcon();
}

OFL_API HICON _stdcall Wnd_GetBigIcon(void* pWnd)
{
	return ((CEventWnd*)pWnd)->GetBigIcon();
}

//�رղ�����������ں��������Ӵ���
OFL_API void _stdcall Wnd_Close(void* pWnd)
{
	((CEventWnd*)pWnd)->Close();
}

//���ô��ڵ�λ�����С
OFL_API void _stdcall Wnd_MoveWindow(void* pWnd,int x,int y,int width,int height)
{
	((CEventWnd*)pWnd)->MoveWindow(x,y,width,height);
}

//��󻯴���
OFL_API void _stdcall Wnd_Maximize(void* pWnd)
{
	((CEventWnd*)pWnd)->Maximize();
}

//��С������
OFL_API void _stdcall Wnd_Minimize(void* pWnd)
{
	((CEventWnd*)pWnd)->Minimize();
}

//��ԭ�Ѿ���󻯻���С���Ĵ���
OFL_API void _stdcall Wnd_Restore(void* pWnd)
{
	((CEventWnd*)pWnd)->Restore();
}

