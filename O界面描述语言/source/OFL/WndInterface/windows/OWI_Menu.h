
#ifndef _OWI_MENU_H_
#define _OWI_MENU_H_

#include "../../ExportDefine.h"
#include <Windows.h>

//////////////////////////////////////////////////////////////////////////
//MenuItem
OFL_API unsigned short _stdcall MenuItem_GetId(void* pMenuItem);
OFL_API void _stdcall MenuItem_SetText(void* pMenuItem,char* text);
OFL_API char* _stdcall MenuItem_GetText(void* pMenuItem);
OFL_API void _stdcall MenuItem_SetChecked(void* pMenuItem,bool check);
OFL_API bool _stdcall MenuItem_GetChecked(void* pMenuItem);
OFL_API bool _stdcall MenuItem_GetRadio(void* pMenuItem);
OFL_API void _stdcall MenuItem_SetEnabled(void* pMenuItem,bool enable);
OFL_API bool _stdcall MenuItem_GetEnabled(void* pMenuItem);
OFL_API void _stdcall MenuItem_SetDefault(void* pMenuItem,bool df);
OFL_API bool _stdcall MenuItem_GetDefault(void* pMenuItem);
OFL_API void _stdcall MenuItem_SetSelected(void* pMenuItem,bool select);
OFL_API bool _stdcall MenuItem_GetSelected(void* pMenuItem);
OFL_API void _stdcall MenuItem_SetSeparator(void* pMenuItem,bool sp);
OFL_API bool _stdcall MenuItem_IsSeparator(void* pMenuItem);
OFL_API void _stdcall MenuItem_SetImage(void* pMenuItem,int image);
OFL_API int _stdcall MenuItem_GetImage(void* pMenuItem);
OFL_API void _stdcall MenuItem_SetTextColor(void* pMenuItem,unsigned int color);
OFL_API unsigned int _stdcall MenuItem_GetTextColor(void* pMenuItem);
OFL_API void _stdcall MenuItem_SetSelectColor(void* pMenuItem,unsigned int color);
OFL_API unsigned int _stdcall MenuItem_GetSelectColor(void* pMenuItem); 
OFL_API void _stdcall MenuItem_SetFlat(void* pMenuItem,bool flat);
OFL_API bool _stdcall MenuItem_GetFlat(void* pMenuItem);
OFL_API bool _stdcall MenuItem_IsMenuBarItem(void* pMenuItem);
OFL_API void* _stdcall MenuItem_GetOwner(void* pMenuItem); 

//////////////////////////////////////////////////////////////////////////
//Menu
OFL_API unsigned short _stdcall Menu_GetId(void* pMenu);
OFL_API void _stdcall Menu_SetFlat(void* pMenu,bool flat);  
OFL_API bool _stdcall Menu_GetFlat(void* pMenu);
OFL_API void _stdcall Menu_SetText(void* pMenu,char* string);	 
OFL_API char* _stdcall Menu_GetText(void* pMenu);	
OFL_API void _stdcall Menu_SetImage(void* pMenu,int image);
OFL_API int _stdcall Menu_GetImage(void* pMenu);
OFL_API int _stdcall Menu_GetSubMenuCount(void* pMenu);	
OFL_API int _stdcall Menu_GetMenuItemCount(void* pMenu); 
OFL_API void _stdcall Menu_SetSelected(void* pMenu,bool select);
OFL_API bool _stdcall Menu_GetSelected(void* pMenu);
OFL_API void _stdcall Menu_SetTextColor(void* pMenu,unsigned int color);
OFL_API unsigned int _stdcall Menu_GetTextColor(void* pMenu);
OFL_API void _stdcall Menu_SetSelectColor(void* pMenu,unsigned int color);
OFL_API unsigned int _stdcall Menu_GetSelectColor(void* pMenu);   	
OFL_API void _stdcall Menu_SetMainMenu(void* pMenu,bool main);
OFL_API bool _stdcall Menu_IsMainMenu(void* pMenu);
OFL_API bool _stdcall Menu_IsMenuBarItem(void* pMenu);
OFL_API void _stdcall Menu_SetImageList(void* pMenu,void* imagelist);
OFL_API void* _stdcall Menu_GetSubMenu(void* pMenu,int submenu);
OFL_API void* _stdcall Menu_GetSelectedSubMenu(void* pMenu);
OFL_API void* _stdcall Menu_GetRootMenu(void* pMenu);	
OFL_API void* _stdcall Menu_GetParentMenu(void* pMenu);
OFL_API void* _stdcall Menu_GetSelectedMenuItem(void* pMenu);
OFL_API void* _stdcall Menu_GetMenuItem(void* pMenu,int item);  
OFL_API void* _stdcall Menu_GetImageList(void* pMenu);  

//����Ļ����(x,y)λ�õ�������˵�����notifyΪfalse������ֵΪ�û�ѡ��Ĳ˵������notify��Ϊtrue����˵�����ͨ����Ϣ֪ͨ�û�
OFL_API unsigned int _stdcall Menu_PopupMenu(void* pMenu,int x,int y,bool notify=true); 
//���һ����ʶΪid�Ĳ˵���¼����Ƿ�Ϊ�Ի���ȡ���ڰ����˵��Ƿ�Ϊ�Ի���
OFL_API void* _stdcall Menu_AddMenuItem(void* pMenu,unsigned short id);	
//�ڴ˲˵���׷��һ���ָ���
OFL_API void* _stdcall Menu_AddSeparator(void* pMenu);
//��itemǰ���һ����ʶΪid�Ĳ˵���¼����Ƿ�Ϊ�Ի���ȡ���ڰ����˵��Ƿ�Ϊ�Ի���
OFL_API void* _stdcall Menu_InsertMenuItem(void* pMenu,unsigned short id,void* item);
//��itemǰ���һ���ָ���
OFL_API void* _stdcall Menu_InsertSeparator(void* pMenu,void* item);
//��menuǰ���һ����ʶΪid�Ĳ˵���¼����Ƿ�Ϊ�Ի���ȡ���ڰ����˵��Ƿ�Ϊ�Ի���
OFL_API void* _stdcall Menu_InsertMenuItemBeforeMenu(void* pMenu,unsigned short id,void* menu);
//��menuǰ���һ���ָ���
OFL_API void* _stdcall Menu_InsertSeparatorBeforeMenu(void* pMenu,void* menu);
//׷��һ���Ӳ˵�
OFL_API void* _stdcall Menu_AddSubMenu(void* pMenu);			 
//��itemǰ����һ���Ӳ˵�����itemΪNULL��׷���Ӳ˵�
OFL_API void* _stdcall Menu_InsertSubMenu(void* pMenu,void* item);
//��menuǰ����һ���Ӳ˵�����menuΪNULL��׷���Ӳ˵�
OFL_API void* _stdcall Menu_InsertSubMenuBeforeMenu(void* pMenu,void* menu);
//������ָ��Ϊitem�Ĳ˵���
OFL_API void _stdcall Menu_DestroyMenuItem(void* pMenu,void* item);
//������IdΪindex�Ĳ˵���
OFL_API void _stdcall Menu_DestroyMenuItemIndex(void* pMenu,int index);
//������ָ��ΪMenu���Ӳ˵�
OFL_API void _stdcall Menu_DestroySubMenu(void* pMenu,void* menu);
//������IdΪindex���Ӳ˵�
OFL_API void _stdcall Menu_DestroySubMenuIndex(void* pMenu,int index);
//ɾ�ղ˵��е��������ݣ�������������
OFL_API void _stdcall Menu_DestroyAll(void* pMenu);
//������Id�ҵ���Ӧ���Ӳ˵�
OFL_API void* _stdcall Menu_FindSubMenuID(void* pMenu,unsigned short id);
//���������ҵ���Ӧ���Ӳ˵�
OFL_API void* _stdcall Menu_FindSubMenu(void* pMenu,HMENU menu);
//������Id�ҵ���Ӧ�Ĳ˵���
OFL_API void* _stdcall Menu_FindMenuItem(void* pMenu,unsigned short id);

OFL_API void _stdcall Menu_DestroyControl(void* pMenu);
OFL_API char* _stdcall Menu_GetClass(void* pMenu);
OFL_API void _stdcall Menu_Show(void* pMenu);
OFL_API void _stdcall Menu_Hide(void* pMenu);
OFL_API void _stdcall Menu_Enable(void* pMenu,bool enable);
OFL_API bool _stdcall Menu_IsEnabled(void* pMenu);
OFL_API bool _stdcall Menu_IsVisible(void* pMenu);  
OFL_API void _stdcall Menu_SetCaption(void* pMenu,char* string);
OFL_API char* _stdcall Menu_GetCaption(void* pMenu);
OFL_API void _stdcall Menu_Move(void* pMenu,int dx,int dy);
OFL_API void _stdcall Menu_SetSize(void* pMenu,int width,int height);
OFL_API void _stdcall Menu_SetPositionSize(void* pMenu,int left,int top,int width,int height);
OFL_API void _stdcall Menu_Align(void* pMenu,unsigned int align);
OFL_API void _stdcall Menu_RedrawControl(void* pMenu,bool redraw);

#endif //_OWI_MENU_H_