
#ifndef _OWI_CONTROL_H_
#define _OWI_CONTROL_H_

#include "../../ExportDefine.h"
#include <Windows.h>

OFL_API HWND  _stdcall Ctrl_GetHandle(void* pCtrl);

OFL_API void  _stdcall Ctrl_GetClientRect(void* pCtrl,RECT& rc);

//���Լ�������Ļ��ǰ������ס������������(���ı�����Z����)
OFL_API void  _stdcall Ctrl_BringToTop(void* pCtrl);
//���Լ�������Ļ���(���������λ�õ�ף�����ര�ڸ�ס)
OFL_API void  _stdcall Ctrl_BringToBottom(void* pCtrl);
//���ô��ڵĽ���
OFL_API void  _stdcall Ctrl_SetFocus(void* pCtrl);

OFL_API void  _stdcall Ctrl_SetCaption(void* pCtrl,char* pchCaption);
OFL_API char* _stdcall Ctrl_GetCaption(void* pCtrl);
OFL_API void  _stdcall Ctrl_Show(void* pCtrl);
OFL_API void  _stdcall Ctrl_Hide(void* pCtrl);
OFL_API void  _stdcall Ctrl_Enable(void* pCtrl,bool bEnable);
OFL_API bool  _stdcall Ctrl_IsEnabled(void* pCtrl);
OFL_API bool  _stdcall Ctrl_IsVisible(void* pCtrl);   	
OFL_API void  _stdcall Ctrl_Move(void* pCtrl,int dx,int dy);
OFL_API void  _stdcall Ctrl_SetSize(void* pCtrl,int width,int height);
OFL_API void  _stdcall Ctrl_SetPositionSize(void* pCtrl,int nLeft,int nRight,int nWidth,int nHeight);
OFL_API void  _stdcall Ctrl_Align(void* pCtrl,unsigned int edge);

#endif //_OWI_CONTROL_H_

