
#include "OWI_ListBox.h"
#include "../../CreateWnd/windows/OFControl.h"

OFL_API void _stdcall ListBox_SetSelect(void* pListBox,int index)
{
	((WinListBox*)pListBox)->SetSelect(index);
}

OFL_API int _stdcall ListBox_GetSelect(void* pListBox)
{
	return ((WinListBox*)pListBox)->GetSelect();
}

OFL_API bool _stdcall ListBox_IsSelected(void* pListBox,int index)
{
	return ((WinListBox*)pListBox)->IsSelected(index);
}

OFL_API int _stdcall ListBox_GetSelectCount(void* pListBox)
{
	return ((WinListBox*)pListBox)->GetSelectCount();
}

OFL_API char* _stdcall ListBox_GetItemText(void* pListBox,int index)
{
	return (char*)((WinListBox*)pListBox)->GetItemText(index);
}

OFL_API int _stdcall ListBox_GetItemCount(void* pListBox)
{
	return ((WinListBox*)pListBox)->GetItemCount();
}

OFL_API void _stdcall ListBox_SetTextColor(void* pListBox,unsigned int color)
{
	((WinListBox*)pListBox)->SetTextColor(color);
}

OFL_API unsigned int _stdcall ListBox_GetTextColor(void* pListBox)
{
	return ((WinListBox*)pListBox)->GetTextColor();
}

OFL_API void _stdcall ListBox_SetAnchorItem(void* pListBox,int index)
{
	((WinListBox*)pListBox)->SetAnchorItem(index);
}

OFL_API int _stdcall ListBox_GetAnchorItem(void* pListBox)
{
	return ((WinListBox*)pListBox)->GetAnchorItem();
}

OFL_API void _stdcall ListBox_SetCaretItem(void* pListBox,int index)
{
	((WinListBox*)pListBox)->SetCaretItem(index);
}

OFL_API int _stdcall ListBox_GetCaretItem(void* pListBox)
{
	return ((WinListBox*)pListBox)->GetCaretItem();
}

OFL_API void _stdcall ListBox_SetScrollWidth(void* pListBox,int width)
{
	((WinListBox*)pListBox)->SetScrollWidth(width);
}

OFL_API int _stdcall ListBox_GetScrollWidth(void* pListBox)
{
	return ((WinListBox*)pListBox)->GetScrollWidth();
}

OFL_API void _stdcall ListBox_SetTopIndex(void* pListBox,int index)
{
	((WinListBox*)pListBox)->SetTopIndex(index);
}

OFL_API int _stdcall ListBox_GetTopIndex(void* pListBox)
{
	return ((WinListBox*)pListBox)->GetTopIndex();
}

OFL_API void _stdcall ListBox_SetColumnWidth(void* pListBox,int width)
{
	((WinListBox*)pListBox)->SetColumnWidth(width);
}

OFL_API void _stdcall ListBox_SetItemHeight(void* pListBox,int index, int height)
{
	((WinListBox*)pListBox)->SetItemHeight(index,height);
}

OFL_API int _stdcall ListBox_GetItemHeight(void* pListBox,int index)
{
	return ((WinListBox*)pListBox)->GetItemHeight(index);
}

OFL_API void _stdcall ListBox_GetItemRect(void* pListBox,int index,RECT& rc)
{
	Rect rect = ((WinListBox*)pListBox)->GetItemRect(index);
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;
}

OFL_API void _stdcall ListBox_SetItemData(void* pListBox,int index,void* pData)
{
	((WinListBox*)pListBox)->SetItemData(index,pData);
}

OFL_API void _stdcall ListBox_SetLocale(void* pListBox,DWORD locale)
{
	((WinListBox*)pListBox)->SetLocale(locale);
}

OFL_API void* _stdcall ListBox_GetItemData(void* pListBox,int index)
{
	return ((WinListBox*)pListBox)->GetItemData(index);
}

OFL_API DWORD _stdcall ListBox_GetLocale(void* pListBox)
{
	return ((WinListBox*)pListBox)->GetLocale();
}


//????????Item????????????????????Item??????????????????????????????????????????????????????
//??????????????
OFL_API int _stdcall ListBox_InsertItem(void* pListBox,char* string,int index)
{
	return ((WinListBox*)pListBox)->InsertItem(string,index);
}

//??????????????????Item??????????????????????????????????????????-1????????????????????Item
//????????????????
OFL_API int _stdcall ListBox_AddItem(void* pListBox,char* string)
{
	return ((WinListBox*)pListBox)->AddItem(string);
}

//??????????Item
OFL_API void _stdcall ListBox_DeleteItem(void* pListBox,int index)
{
	((WinListBox*)pListBox)->DeleteItem(index);
}

//??????????Item
OFL_API void _stdcall ListBox_DeleteAllItems(void* pListBox)
{
	((WinListBox*)pListBox)->DeleteAllItems();
}

//??????????string????????????Item??????????????????index??item????????????????????????????????????
//????????????????????????????????index????Item??????-1????????????Item????????????????????????-1
OFL_API int _stdcall ListBox_FindItem(void* pListBox,char* string, int index)
{
	return ((WinListBox*)pListBox)->FindItem(string,index);
}

//??????????????string????????Item????????????????????????????????index????????????????????????????
//FindItem()??????????
OFL_API int _stdcall ListBox_FindItemExact(void* pListBox,char* string, int index)
{
	return ((WinListBox*)pListBox)->FindItemExact(string,index);
}

//??????????????ListBox????????????string????????????Item??index????????????FindItem()??????????????
//??????????????????Item??????????-1??????????????????????????????????????????????????????????????????
//??????????????????????
OFL_API int _stdcall ListBox_SelectString(void* pListBox,char* string, int index)
{
	return  ((WinListBox*)pListBox)->SelectString(string,index);
}

//??????????????ListBox????select??true????????????index??Item????select??false??????Item??????????
OFL_API void _stdcall ListBox_SelectSingle(void* pListBox,int index, bool select)
{
	((WinListBox*)pListBox)->SelectSingle(index,select);
}

//??????????????ListBox????select??true??????????Item????select??false??????Item??????????
OFL_API void _stdcall ListBox_SelectAll(void* pListBox,bool select)
{
	((WinListBox*)pListBox)->SelectAll(select);
}

//??????????????ListBox??????????????????????????item????????buffer????????number??????????????????
//??????????????????????????????????		 
OFL_API int _stdcall ListBox_GetSelectArray(void* pListBox,int number,int* buffer)
{
	return ((WinListBox*)pListBox)->GetSelectArray(number,buffer);
}

//??????????????ListBox????????????????????first??last??Item????????????????????????
OFL_API bool _stdcall ListBox_SelectRange(void* pListBox,int first,int last)
{
	return ((WinListBox*)pListBox)->SelectRange(first,last);
}

//??????????????ListBox????????????????????????first??last??Item????????????????????????
OFL_API bool _stdcall ListBox_CancelRange(void* pListBox,int first,int last)
{
	return ((WinListBox*)pListBox)->CancelRange(first,last);
}

//??????????(x,y)??????Item????????????ListBox????????????
OFL_API int _stdcall ListBox_GetNearestItem(void* pListBox,int x,int y)
{
	return ((WinListBox*)pListBox)->GetNearestItem(x,y);
}

//????????(x,y)??????Item????????????ListBox????????????
OFL_API int _stdcall ListBox_GetItemFromPoint(void* pListBox,int x,int y)
{
	return ((WinListBox*)pListBox)->GetItemFromPoint(x,y);
}


OFL_API void _stdcall ListBox_DestroyControl(void* pListBox)
{
	((WinListBox*)pListBox)->DestroyControl();
}

OFL_API char* _stdcall ListBox_GetClass(void* pListBox)
{
	return (char*)((WinListBox*)pListBox)->GetClass();
}

OFL_API char* _stdcall ListBox_GetCaption(void* pListBox)
{
	return (char*)((WinListBox*)pListBox)->GetCaption();
}

OFL_API void _stdcall ListBox_SetCaption(void* pListBox,char* string)
{
	((WinListBox*)pListBox)->SetCaption(string);
}
