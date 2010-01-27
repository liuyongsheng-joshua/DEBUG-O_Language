
#include "OWI_Menu.h"
#include "../../CreateWnd/windows/OFControl.h"

//////////////////////////////////////////////////////////////////////////
//MenuItem
OFL_API unsigned short _stdcall MenuItem_GetId(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetId();
}

OFL_API void _stdcall MenuItem_SetText(void* pMenuItem,char* text)
{
	((MenuItem*)pMenuItem)->SetText(text);
}

OFL_API char* _stdcall MenuItem_GetText(void* pMenuItem)
{
	return (char*)((MenuItem*)pMenuItem)->GetText();
}

OFL_API void _stdcall MenuItem_SetChecked(void* pMenuItem,bool check)
{
	((MenuItem*)pMenuItem)->SetChecked(check);
}

OFL_API bool _stdcall MenuItem_GetChecked(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetChecked();
}

OFL_API bool _stdcall MenuItem_GetRadio(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetRadio();
}

OFL_API void _stdcall MenuItem_SetEnabled(void* pMenuItem,bool enable)
{
	((MenuItem*)pMenuItem)->SetEnabled(enable);
}

OFL_API bool _stdcall MenuItem_GetEnabled(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetEnabled();
}

OFL_API void _stdcall MenuItem_SetDefault(void* pMenuItem,bool df)
{
	((MenuItem*)pMenuItem)->SetDefault(df);
}

OFL_API bool _stdcall MenuItem_GetDefault(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetDefault();
}

OFL_API void _stdcall MenuItem_SetSelected(void* pMenuItem,bool select)
{
	((MenuItem*)pMenuItem)->SetSelected(select);
}

OFL_API bool _stdcall MenuItem_GetSelected(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetSelected();
}

OFL_API void _stdcall MenuItem_SetSeparator(void* pMenuItem,bool sp)
{
	((MenuItem*)pMenuItem)->SetSeparator(sp);
}

OFL_API bool _stdcall MenuItem_IsSeparator(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->IsSeparator();
}

OFL_API void _stdcall MenuItem_SetImage(void* pMenuItem,int image)
{
	((MenuItem*)pMenuItem)->SetImage(image);
}

OFL_API int _stdcall MenuItem_GetImage(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetImage();
}

OFL_API void _stdcall MenuItem_SetTextColor(void* pMenuItem,unsigned int color)
{
	((MenuItem*)pMenuItem)->SetTextColor(color);
}

OFL_API unsigned int _stdcall MenuItem_GetTextColor(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetTextColor();
}

OFL_API void _stdcall MenuItem_SetSelectColor(void* pMenuItem,unsigned int color)
{
	((MenuItem*)pMenuItem)->SetSelectColor(color);
}

OFL_API unsigned int _stdcall MenuItem_GetSelectColor(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetSelectColor();
}

OFL_API void _stdcall MenuItem_SetFlat(void* pMenuItem,bool flat)
{
	((MenuItem*)pMenuItem)->SetFlat(flat);
}

OFL_API bool _stdcall MenuItem_GetFlat(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetFlat();
}

OFL_API bool _stdcall MenuItem_IsMenuBarItem(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->IsMenuBarItem();
}

OFL_API void* _stdcall MenuItem_GetOwner(void* pMenuItem)
{
	return ((MenuItem*)pMenuItem)->GetOwner();
}

//////////////////////////////////////////////////////////////////////////
//Menu

OFL_API unsigned short _stdcall Menu_GetId(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetId();
}

OFL_API void _stdcall Menu_SetFlat(void* pMenu,bool flat)
{
	((WinMenu*)pMenu)->SetFlat(flat);
}

OFL_API bool _stdcall Menu_GetFlat(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetFlat();
}

OFL_API void _stdcall Menu_SetText(void* pMenu,char* string)
{
	((WinMenu*)pMenu)->SetText(string);
}

OFL_API char* _stdcall Menu_GetText(void* pMenu)
{
	return (char*)((WinMenu*)pMenu)->GetText();
}

OFL_API void _stdcall Menu_SetImage(void* pMenu,int image)
{
	((WinMenu*)pMenu)->SetImage(image);
}

OFL_API int _stdcall Menu_GetImage(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetImage();
}

OFL_API int _stdcall Menu_GetSubMenuCount(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetSubMenuCount();
}

OFL_API int _stdcall Menu_GetMenuItemCount(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetMenuItemCount();
}

OFL_API void _stdcall Menu_SetSelected(void* pMenu,bool select)
{
	((WinMenu*)pMenu)->SetSelected(select);
}

OFL_API bool _stdcall Menu_GetSelected(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetSelected();
}

OFL_API void _stdcall Menu_SetTextColor(void* pMenu,unsigned int color)
{
	((WinMenu*)pMenu)->SetTextColor(color);
}

OFL_API unsigned int _stdcall Menu_GetTextColor(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetTextColor();
}

OFL_API void _stdcall Menu_SetSelectColor(void* pMenu,unsigned int color)
{
	((WinMenu*)pMenu)->SetSelectColor(color);
}

OFL_API unsigned int _stdcall Menu_GetSelectColor(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetSelectColor();
}

OFL_API void _stdcall Menu_SetMainMenu(void* pMenu,bool main)
{
	((WinMenu*)pMenu)->SetMainMenu(main);
}

OFL_API bool _stdcall Menu_IsMainMenu(void* pMenu)
{
	return ((WinMenu*)pMenu)->IsMainMenu();
}

OFL_API bool _stdcall Menu_IsMenuBarItem(void* pMenu)
{
	return ((WinMenu*)pMenu)->IsMenuBarItem();
}

OFL_API void _stdcall Menu_SetImageList(void* pMenu,void* imagelist)
{
	((WinMenu*)pMenu)->SetImageList((WinImageList*)imagelist);
}

OFL_API void* _stdcall Menu_GetSubMenu(void* pMenu,int submenu)
{
	return ((WinMenu*)pMenu)->GetSubMenu(submenu);
}

OFL_API void* _stdcall Menu_GetSelectedSubMenu(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetSelectedSubMenu();
}

OFL_API void* _stdcall Menu_GetRootMenu(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetRootMenu();
}

OFL_API void* _stdcall Menu_GetParentMenu(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetParentMenu();
}

OFL_API void* _stdcall Menu_GetSelectedMenuItem(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetSelectedMenuItem();
}

OFL_API void* _stdcall Menu_GetMenuItem(void* pMenu,int item)
{
	return ((WinMenu*)pMenu)->GetMenuItem(item);
}

OFL_API void* _stdcall Menu_GetImageList(void* pMenu)
{
	return ((WinMenu*)pMenu)->GetImageList();
}


//����Ļ����(x,y)λ�õ�������˵�����notifyΪfalse������ֵΪ�û�ѡ��Ĳ˵������notify��Ϊtrue����˵�����ͨ����Ϣ֪ͨ�û�
OFL_API unsigned int _stdcall Menu_PopupMenu(void* pMenu,int x,int y,bool notify)
{
	return ((WinMenu*)pMenu)->PopupMenu(x,y,notify);
}

//���һ����ʶΪid�Ĳ˵���¼����Ƿ�Ϊ�Ի���ȡ���ڰ����˵��Ƿ�Ϊ�Ի���
OFL_API void* _stdcall Menu_AddMenuItem(void* pMenu,unsigned short id)
{
	return ((WinMenu*)pMenu)->AddMenuItem(id);
}
	
//�ڴ˲˵���׷��һ���ָ���
OFL_API void* _stdcall Menu_AddSeparator(void* pMenu)
{
	return ((WinMenu*)pMenu)->AddSeparator();
}

//��itemǰ���һ����ʶΪid�Ĳ˵���¼����Ƿ�Ϊ�Ի���ȡ���ڰ����˵��Ƿ�Ϊ�Ի���
OFL_API void* _stdcall Menu_InsertMenuItem(void* pMenu,unsigned short id,void* item)
{
	return ((WinMenu*)pMenu)->InsertMenuItem(id,(MenuItem*)item);
}

//��itemǰ���һ���ָ���
OFL_API void* _stdcall Menu_InsertSeparator(void* pMenu,void* item)
{
	return ((WinMenu*)pMenu)->InsertSeparator((MenuItem*)item);
}

//��menuǰ���һ����ʶΪid�Ĳ˵���¼����Ƿ�Ϊ�Ի���ȡ���ڰ����˵��Ƿ�Ϊ�Ի���
OFL_API void* _stdcall Menu_InsertMenuItemBeforeMenu(void* pMenu,unsigned short id,void* menu)
{
	return ((WinMenu*)pMenu)->InsertMenuItem(id,(WinMenu*)menu);
}

//��menuǰ���һ���ָ���
OFL_API void* _stdcall Menu_InsertSeparatorBeforeMenu(void* pMenu,void* menu)
{
	return ((WinMenu*)pMenu)->InsertSeparator((WinMenu*)menu);
}

//׷��һ���Ӳ˵�
OFL_API void* _stdcall Menu_AddSubMenu(void* pMenu)
{
	return ((WinMenu*)pMenu)->AddSubMenu();
}

//��itemǰ����һ���Ӳ˵�����itemΪNULL��׷���Ӳ˵�
OFL_API void* _stdcall Menu_InsertSubMenu(void* pMenu,void* item)
{
	return ((WinMenu*)pMenu)->InsertSubMenu((MenuItem*)item);
}

//��menuǰ����һ���Ӳ˵�����menuΪNULL��׷���Ӳ˵�
OFL_API void* _stdcall Menu_InsertSubMenuBeforeMenu(void* pMenu,void* menu)
{
	return ((WinMenu*)pMenu)->InsertSubMenu((WinMenu*)menu);
}

//������ָ��Ϊitem�Ĳ˵���
OFL_API void _stdcall Menu_DestroyMenuItem(void* pMenu,void* item)
{
	((WinMenu*)pMenu)->DestroyMenuItem((MenuItem*)item);
}

//������IdΪindex�Ĳ˵���
OFL_API void _stdcall Menu_DestroyMenuItemIndex(void* pMenu,int index)
{
	((WinMenu*)pMenu)->DestroyMenuItem(index);
}

//������ָ��ΪMenu���Ӳ˵�
OFL_API void _stdcall Menu_DestroySubMenu(void* pMenu,void* menu)
{
	((WinMenu*)pMenu)->DestroySubMenu((WinMenu*)menu);
}

//������IdΪindex���Ӳ˵�
OFL_API void _stdcall Menu_DestroySubMenuIndex(void* pMenu,int index)
{
	((WinMenu*)pMenu)->DestroySubMenu(index);
}

//ɾ�ղ˵��е��������ݣ�������������
OFL_API void _stdcall Menu_DestroyAll(void* pMenu)
{
	((WinMenu*)pMenu)->DestroyAll();
}

//������Id�ҵ���Ӧ���Ӳ˵�
OFL_API void* _stdcall Menu_FindSubMenuID(void* pMenu,unsigned short id)
{
	return ((WinMenu*)pMenu)->FindSubMenu(id);
}

//���������ҵ���Ӧ���Ӳ˵�
OFL_API void* _stdcall Menu_FindSubMenu(void* pMenu,HMENU menu)
{
	return ((WinMenu*)pMenu)->FindSubMenu(menu);
}

//������Id�ҵ���Ӧ�Ĳ˵���
OFL_API void* _stdcall Menu_FindMenuItem(void* pMenu,unsigned short id)
{
	return ((WinMenu*)pMenu)->FindMenuItem(id);
}


OFL_API void _stdcall Menu_DestroyControl(void* pMenu)
{
	((WinMenu*)pMenu)->DestroyControl();
}

OFL_API char* _stdcall Menu_GetClass(void* pMenu)
{
	return (char*)((WinMenu*)pMenu)->GetClass();
}

OFL_API void _stdcall Menu_Show(void* pMenu)
{
	((WinMenu*)pMenu)->Show();
}

OFL_API void _stdcall Menu_Hide(void* pMenu)
{
	((WinMenu*)pMenu)->Hide();
}

OFL_API void _stdcall Menu_Enable(void* pMenu,bool enable)
{
	((WinMenu*)pMenu)->Enable(enable);
}

OFL_API bool _stdcall Menu_IsEnabled(void* pMenu)
{
	return ((WinMenu*)pMenu)->IsEnabled();
}

OFL_API bool _stdcall Menu_IsVisible(void* pMenu)
{
	return ((WinMenu*)pMenu)->IsVisible();
}

OFL_API void _stdcall Menu_SetCaption(void* pMenu,char* string)
{
	((WinMenu*)pMenu)->SetCaption(string);
}

OFL_API char* _stdcall Menu_GetCaption(void* pMenu)
{
	return (char*)((WinMenu*)pMenu)->GetCaption();
}

OFL_API void _stdcall Menu_Move(void* pMenu,int dx,int dy)
{
	((WinMenu*)pMenu)->Move(dx,dy);
}

OFL_API void _stdcall Menu_SetSize(void* pMenu,int width,int height)
{
	((WinMenu*)pMenu)->SetSize(width,height);
}

OFL_API void _stdcall Menu_SetPositionSize(void* pMenu,int left,int top,int width,int height)
{
	((WinMenu*)pMenu)->SetPositionSize(left,top,width,height);
}

OFL_API void _stdcall Menu_Align(void* pMenu,unsigned int align)
{
	((WinMenu*)pMenu)->Align(align);
}

OFL_API void _stdcall Menu_RedrawControl(void* pMenu,bool redraw)
{
	((WinMenu*)pMenu)->RedrawControl(redraw);
}

