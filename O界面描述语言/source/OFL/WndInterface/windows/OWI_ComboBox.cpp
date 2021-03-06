
#include "OWI_ComboBox.h"
#include "../../CreateWnd/windows/OFControl.h"

OFL_API int _stdcall ComboBox_GetCount(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->GetCount();
}

OFL_API int _stdcall ComboBox_GetItemHeight(void* pComboBox,int index)
{
	return ((WinComboBox*)pComboBox)->GetItemHeight(index);
}

OFL_API void _stdcall ComboBox_SetItemHeight(void* pComboBox,int index, int height)
{
	((WinComboBox*)pComboBox)->SetItemHeight(index,height);
}

OFL_API void _stdcall ComboBox_SetSelect(void* pComboBox,int index)
{
	((WinComboBox*)pComboBox)->SetSelect(index);
}

OFL_API int _stdcall ComboBox_GetSelect(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->GetSelect();
}

OFL_API void _stdcall ComboBox_SetSelectStart(void* pComboBox,int start)
{
	((WinComboBox*)pComboBox)->SetSelectStart(start);
}

OFL_API int _stdcall ComboBox_GetSelectStart(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->GetSelectStart();
}

OFL_API void _stdcall ComboBox_SetSelectEnd(void* pComboBox,int end)
{
	((WinComboBox*)pComboBox)->SetSelectEnd(end);
}

OFL_API int _stdcall ComboBox_GetSelectEnd(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->GetSelectEnd();
}

OFL_API void _stdcall ComboBox_SetTopIndex(void* pComboBox,int index)
{
	((WinComboBox*)pComboBox)->SetTopIndex(index);
}

OFL_API int _stdcall ComboBox_GetTopIndex(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->GetTopIndex();
}

OFL_API void _stdcall ComboBox_SetTextLimit(void* pComboBox,int length)
{
	((WinComboBox*)pComboBox)->SetTextLimit(length);
}

OFL_API int _stdcall ComboBox_GetItemTextLength(void* pComboBox,int index)
{
	return ((WinComboBox*)pComboBox)->GetItemTextLength(index);
}

OFL_API void _stdcall ComboBox_ShowDropdownList(void* pComboBox,bool show)
{
	((WinComboBox*)pComboBox)->ShowDropdownList(show);
}

OFL_API bool _stdcall ComboBox_IsDropdownListVisible(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->IsDropdownListVisible();
}

OFL_API int _stdcall ComboBox_GetDropdownListWidth(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->GetDropdownListWidth();
}

OFL_API void _stdcall ComboBox_SetDropdownListWidth(void* pComboBox,int width)
{
	((WinComboBox*)pComboBox)->SetDropdownListWidth(width);
}

OFL_API void _stdcall ComboBox_GetDropdownListRect(void* pComboBox,RECT& rc)
{
	Rect rect = ((WinComboBox*)pComboBox)->GetDropdownListRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}

OFL_API void _stdcall ComboBox_SetScrollWidth(void* pComboBox,int width)
{
	((WinComboBox*)pComboBox)->SetScrollWidth(width);
}

OFL_API int _stdcall ComboBox_GetScrollWidth(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->GetScrollWidth();
}

OFL_API void _stdcall ComboBox_SetExtendedUI(void* pComboBox,bool eui)
{
	((WinComboBox*)pComboBox)->SetExtendedUI(eui);
}

OFL_API bool _stdcall ComboBox_GetExtendedUI(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->GetExtendedUI();
}

OFL_API void _stdcall ComboBox_SetLocale(void* pComboBox,DWORD locale)
{
	((WinComboBox*)pComboBox)->SetLocale(locale);
}

OFL_API void _stdcall ComboBox_SetItemData(void* pComboBox,int index,void* data)
{
	((WinComboBox*)pComboBox)->SetItemData(index,data);
}

OFL_API void* _stdcall ComboBox_GetItemData(void* pComboBox,int index)
{
	return ((WinComboBox*)pComboBox)->GetItemData(index);
}

OFL_API DWORD _stdcall ComboBox_GetLocale(void* pComboBox)
{
	return ((WinComboBox*)pComboBox)->GetLocale();
}


//??ComboBox????????????????????????Item
OFL_API int _stdcall ComboBox_InsertItem(void* pComboBox,char* string,int index)
{
	return ((WinComboBox*)pComboBox)->InsertItem(string,index);
}

//??ComboBox??????????????????Item
OFL_API int _stdcall ComboBox_AddItem(void* pComboBox,char* string)
{
	return ((WinComboBox*)pComboBox)->AddItem(string);
}

//??????????Item
OFL_API bool _stdcall ComboBox_DeleteItem(void* pComboBox,int index)
{
	return ((WinComboBox*)pComboBox)->DeleteItem(index);
}

//????????Item
OFL_API void _stdcall ComboBox_DeleteAllItems(void* pComboBox)
{
	((WinComboBox*)pComboBox)->DeleteAllItems();
}

//????????Item??????
OFL_API char* _stdcall ComboBox_GetItemText(void* pComboBox,int index)
{
	return  (char*)((WinComboBox*)pComboBox)->GetItemText(index);
}

//??????????????????????????????string(??????????????????)????????????????????
OFL_API int _stdcall ComboBox_FindItem(void* pComboBox,char* string)
{
	return ((WinComboBox*)pComboBox)->FindItem(string);
}

//????????????????????string(??????????????????)??????????????????????????????-1
OFL_API int _stdcall ComboBox_FindItemExact(void* pComboBox,char* string)
{
	return ((WinComboBox*)pComboBox)->FindItemExact(string);
}

//??????????????string??Item????????????Item??????????????????????????????-1
OFL_API int _stdcall ComboBox_SelectString(void* pComboBox,char* string)
{
	return ((WinComboBox*)pComboBox)->SelectString(string);
}

//??????????SimpleStyle??TextStyle??ComboBox??????????????????????????????????
//??start??-1????????????????????????????????????end??-1??????????????????????????????????
OFL_API void _stdcall ComboBox_SetEditSelect(void* pComboBox,int start, int end)
{
	((WinComboBox*)pComboBox)->SetEditSelect(start,end);
}

OFL_API void _stdcall ComboBox_DestroyControl(void* pComboBox)
{
	((WinComboBox*)pComboBox)->DestroyControl();
}

OFL_API char* _stdcall ComboBox_GetClass(void* pComboBox)
{
	return (char*)((WinComboBox*)pComboBox)->GetClass();
}

OFL_API void _stdcall ComboBox_SetCaption(void* pComboBox,char* string)
{
	((WinComboBox*)pComboBox)->SetCaption(string);
}

OFL_API char* _stdcall ComboBox_GetCaption(void* pComboBox)
{
	return (char*)((WinComboBox*)pComboBox)->GetCaption();
}
