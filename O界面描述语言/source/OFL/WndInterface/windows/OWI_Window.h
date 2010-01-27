
#ifndef _OWI_WINDOW_H_
#define _OWI_WINDOW_H_

#include "../../ExportDefine.h"
#include <Windows.h>

OFL_API void _stdcall Wnd_SetMaximized(void* pWnd,bool max);
OFL_API bool _stdcall Wnd_IsMaximized(void* pWnd);
OFL_API void _stdcall Wnd_SetMinimized(void* pWnd,bool min);
OFL_API bool _stdcall Wnd_IsMinimized(void* pWnd);	 
OFL_API void _stdcall Wnd_SetTopmost(void* pWnd,bool topmost);
OFL_API bool _stdcall Wnd_GetTopmost(void* pWnd);
OFL_API void _stdcall Wnd_SetSmallIcon(void* pWnd,HICON icon);
OFL_API void _stdcall Wnd_SetBigIcon(void* pWnd,HICON icon);  
OFL_API HICON _stdcall Wnd_GetSmallIcon(void* pWnd);
OFL_API HICON _stdcall Wnd_GetBigIcon(void* pWnd);

//�رղ�����������ں��������Ӵ���
OFL_API void _stdcall Wnd_Close(void* pWnd); 
//���ô��ڵ�λ�����С
OFL_API void _stdcall Wnd_MoveWindow(void* pWnd,int x,int y,int width,int height);
//��󻯴���
OFL_API void _stdcall Wnd_Maximize(void* pWnd);
//��С������
OFL_API void _stdcall Wnd_Minimize(void* pWnd);
//��ԭ�Ѿ���󻯻���С���Ĵ���
OFL_API void _stdcall Wnd_Restore(void* pWnd);

#endif //_OWI_WINDOW_H_