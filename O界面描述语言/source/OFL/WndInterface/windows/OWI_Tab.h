
#ifndef _OWI_TAB_H_
#define _OWI_TAB_H_

#include "../../ExportDefine.h"
#include <Windows.h>

//////////////////////////////////////////////////////////////////////////
//TabPage
OFL_API int _stdcall TabPage_GetIndex(void* pTabPage);
OFL_API void _stdcall TabPage_SetText(void* pTabPage,char* text);
OFL_API char* _stdcall TabPage_GetText(void* pTabPage);
OFL_API void _stdcall TabPage_SetImage(void* pTabPage,int index);
OFL_API int _stdcall TabPage_GetImage(void* pTabPage);
OFL_API void _stdcall TabPage_SetPressed(void* pTabPage,bool pressed);
OFL_API bool _stdcall TabPage_IsPressed(void* pTabPage);
OFL_API void _stdcall TabPage_SetHilited(void* pTabPage,bool high);
OFL_API bool _stdcall TabPage_GetHilited(void* pTabPage);
OFL_API void _stdcall TabPage_GetRect(void* pTabPage,RECT& rc);
OFL_API void* _stdcall TabPage_GetParent(void* pTabPage);

OFL_API void* _stdcall TabPage_GetOwner(void* pTabPage);
OFL_API bool _stdcall TabPage_IsClientEmpty(void* pTabPage);
OFL_API void _stdcall TabPage_AddControl(void* pTabPage,void* control);	
OFL_API void _stdcall TabPage_RemoveControl(void* pTabPage,void* control);

//////////////////////////////////////////////////////////////////////////
//Tab
OFL_API int _stdcall Tab_GetRowCount(void* pTab);	
OFL_API int _stdcall Tab_GetPageCount(void* pTab); 
OFL_API void _stdcall Tab_SetTabSize(void* pTab,const SIZE& size);
OFL_API void _stdcall Tab_SetToolTip(void* pTab,HWND tip);
OFL_API void _stdcall Tab_SetMinTabWidth(void* pTab,int width);	
OFL_API void _stdcall Tab_SelectPage(void* pTab,void* page);
OFL_API void _stdcall Tab_SelectPageIndex(void* pTab,int index);
OFL_API void _stdcall Tab_SetFocusPage(void* pTab,void* page);
OFL_API void _stdcall Tab_SetFocusPageIndex(void* pTab,int index);
OFL_API void _stdcall Tab_SetImageList(void* pTab,void* imageList);
OFL_API void _stdcall Tab_GetTabSize(void* pTab,SIZE& size);
OFL_API void _stdcall Tab_GetViewRect(void* pTab,RECT& rc);
OFL_API HWND _stdcall Tab_GetToolTip(void* pTab);	 
OFL_API void* _stdcall Tab_GetFocusPage(void* pTab); 
OFL_API void* _stdcall Tab_GetSelectedPage(void* pTab); 
OFL_API void* _stdcall Tab_GetPage(void* pTab,int index);
OFL_API void* _stdcall Tab_GetImageList(void* pTab);

//��indexλ��ǰ������ҳ
OFL_API void* _stdcall Tab_InsertPage(void* pTab,int index);
//���һ���µ�Page
OFL_API void* _stdcall Tab_AddPage(void* pTab);
//ɾ��һ��Page
OFL_API bool _stdcall Tab_DeletePage(void* pTab,void* page);
//ɾ��һ��Page
OFL_API bool _stdcall Tab_DeletePageIndex(void* pTab,int index);
//ɾ������Page
OFL_API void _stdcall Tab_DeleteAllPage(void* pTab);   
//����ÿһ��Tab��ˮƽ����ʹ�ֱ����ı������(���������ָͼ����ı���Tab�߽�����ؾ���)
OFL_API void _stdcall Tab_SetTabMargin(void* pTab,int horz,int vert);
//���ڰ�ť����Tab�ؼ���ȡ���κΰ�ť��ѹ��״̬
OFL_API void _stdcall Tab_ResetButtons(void* pTab);
//����/��ȡTab��Ե����ť�ı���ͼ��֮��ľ���
OFL_API void _stdcall Tab_SetPadding(void* pTab,int dx,int dy);
//��ȡ�ͻ�����p֮�µ��Ǹ�Tab����p֮�²���Tab�򷵻�NULL
OFL_API void* _stdcall Tab_IsOnTab(void* pTab,const POINT& p);

OFL_API void _stdcall Tab_DestroyControl(void* pTab);
OFL_API char* _stdcall Tab_GetClass(void* pTab);			
OFL_API void _stdcall Tab_SetCaption(void* pTab,char* string);
OFL_API char* _stdcall Tab_GetCaption(void* pTab);
OFL_API void _stdcall Tab_Hide(void* pTab);
OFL_API void _stdcall Tab_Show(void* pTab); 

#endif //_OWI_TAB_H_