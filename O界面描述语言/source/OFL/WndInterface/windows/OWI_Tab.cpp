
#include "OWI_Tab.h"
#include "../../CreateWnd/windows/OFControl.h"

//////////////////////////////////////////////////////////////////////////
//TabPage
OFL_API int _stdcall TabPage_GetIndex(void* pTabPage)
{
	return ((TabPage*)pTabPage)->GetIndex();
}

OFL_API void _stdcall TabPage_SetText(void* pTabPage,char* text)
{
	((TabPage*)pTabPage)->SetText(text);
}

OFL_API char* _stdcall TabPage_GetText(void* pTabPage)
{
	return (char*)((TabPage*)pTabPage)->GetText();
}

OFL_API void _stdcall TabPage_SetImage(void* pTabPage,int index)
{
	((TabPage*)pTabPage)->SetImage(index);
}

OFL_API int _stdcall TabPage_GetImage(void* pTabPage)
{
	return ((TabPage*)pTabPage)->GetImage();
}

OFL_API void _stdcall TabPage_SetPressed(void* pTabPage,bool pressed)
{
	((TabPage*)pTabPage)->SetPressed(pressed);
}

OFL_API bool _stdcall TabPage_IsPressed(void* pTabPage)
{
	return ((TabPage*)pTabPage)->IsPressed();
}

OFL_API void _stdcall TabPage_SetHilited(void* pTabPage,bool high)
{
	((TabPage*)pTabPage)->SetHilited(high);
}

OFL_API bool _stdcall TabPage_GetHilited(void* pTabPage)
{
	return ((TabPage*)pTabPage)->GetHilited();
}

OFL_API void _stdcall TabPage_GetRect(void* pTabPage,RECT& rc)
{
	Rect rect = ((TabPage*)pTabPage)->GetRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}

OFL_API void* _stdcall TabPage_GetParent(void* pTabPage)
{
	return ((TabPage*)pTabPage)->GetParent();
}


OFL_API void* _stdcall TabPage_GetOwner(void* pTabPage)
{
	return ((TabPage*)pTabPage)->GetOwner();
}

OFL_API bool _stdcall TabPage_IsClientEmpty(void* pTabPage)
{
	return ((TabPage*)pTabPage)->IsClientEmpty();
}

OFL_API void _stdcall TabPage_AddControl(void* pTabPage,void* control)
{
	((TabPage*)pTabPage)->AddControl((WinControl*)control);
}

OFL_API void _stdcall TabPage_RemoveControl(void* pTabPage,void* control)
{
	((TabPage*)pTabPage)->RemoveControl((WinControl*)control);
}

//////////////////////////////////////////////////////////////////////////
//Tab
OFL_API int _stdcall Tab_GetRowCount(void* pTab)
{
	return ((WinTab*)pTab)->GetRowCount();
}

OFL_API int _stdcall Tab_GetPageCount(void* pTab)
{
	return ((WinTab*)pTab)->GetPageCount();
}

OFL_API void _stdcall Tab_SetTabSize(void* pTab,const SIZE& size)
{
	Size sz;
	sz.mWidth = size.cx;
	sz.mHeight = size.cy;
	((WinTab*)pTab)->SetTabSize(sz);
}

OFL_API void _stdcall Tab_SetToolTip(void* pTab,HWND tip)
{
	((WinTab*)pTab)->SetToolTip(tip);
}

OFL_API void _stdcall Tab_SetMinTabWidth(void* pTab,int width)
{
	((WinTab*)pTab)->SetMinTabWidth(width);
}

OFL_API void _stdcall Tab_SelectPage(void* pTab,void* page)
{
	((WinTab*)pTab)->SelectPage((TabPage*)page);
}

OFL_API void _stdcall Tab_SelectPageIndex(void* pTab,int index)
{
	((WinTab*)pTab)->SelectPage(index);
}

OFL_API void _stdcall Tab_SetFocusPage(void* pTab,void* page)
{
	((WinTab*)pTab)->SetFocusPage((TabPage*)page);
}

OFL_API void _stdcall Tab_SetFocusPageIndex(void* pTab,int index)
{
	((WinTab*)pTab)->SetFocusPage(index);
}

OFL_API void _stdcall Tab_SetImageList(void* pTab,void* imageList)
{
	((WinTab*)pTab)->SetImageList((WinImageList*)imageList);
}

OFL_API void _stdcall Tab_GetTabSize(void* pTab,SIZE& size)
{
	Size sz = ((WinTab*)pTab)->GetTabSize();
	size.cx = sz.mWidth;
	size.cy = sz.mHeight;
}

OFL_API void _stdcall Tab_GetViewRect(void* pTab,RECT& rc)
{
	Rect rect = ((WinTab*)pTab)->GetViewRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}

OFL_API HWND _stdcall Tab_GetToolTip(void* pTab)
{
	return ((WinTab*)pTab)->GetToolTip();
}

OFL_API void* _stdcall Tab_GetFocusPage(void* pTab)
{
	return ((WinTab*)pTab)->GetFocusPage();
}

OFL_API void* _stdcall Tab_GetSelectedPage(void* pTab)
{
	return ((WinTab*)pTab)->GetSelectedPage();
}

OFL_API void* _stdcall Tab_GetPage(void* pTab,int index)
{
	return ((WinTab*)pTab)->GetPage(index);
}

OFL_API void* _stdcall Tab_GetImageList(void* pTab)
{
	return ((WinTab*)pTab)->GetImageList();
}


//��indexλ��ǰ������ҳ
OFL_API void* _stdcall Tab_InsertPage(void* pTab,int index)
{
	return ((WinTab*)pTab)->InsertPage(index);
}

//���һ���µ�Page
OFL_API void* _stdcall Tab_AddPage(void* pTab)
{
	return ((WinTab*)pTab)->AddPage();
}

//ɾ��һ��Page
OFL_API bool _stdcall Tab_DeletePage(void* pTab,void* page)
{
	return ((WinTab*)pTab)->DeletePage((TabPage*)page);
}

//ɾ��һ��Page
OFL_API bool _stdcall Tab_DeletePageIndex(void* pTab,int index)
{
	return ((WinTab*)pTab)->DeletePage(index);
}

//ɾ������Page
OFL_API void _stdcall Tab_DeleteAllPage(void* pTab)
{
	((WinTab*)pTab)->DeleteAllPage();
}

//����ÿһ��Tab��ˮƽ����ʹ�ֱ����ı������(���������ָͼ����ı���Tab�߽�����ؾ���)
OFL_API void _stdcall Tab_SetTabMargin(void* pTab,int horz,int vert)
{
	((WinTab*)pTab)->SetTabMargin(horz,vert);
}

//���ڰ�ť����Tab�ؼ���ȡ���κΰ�ť��ѹ��״̬
OFL_API void _stdcall Tab_ResetButtons(void* pTab)
{
	((WinTab*)pTab)->ResetButtons();
}

//����/��ȡTab��Ե����ť�ı���ͼ��֮��ľ���
OFL_API void _stdcall Tab_SetPadding(void* pTab,int dx,int dy)
{
	((WinTab*)pTab)->SetPadding(dx,dy);
}

//��ȡ�ͻ�����p֮�µ��Ǹ�Tab����p֮�²���Tab�򷵻�NULL
OFL_API void* _stdcall Tab_IsOnTab(void* pTab,const POINT& p)
{
	Point pt;
	pt.x = p.x;
	pt.y = p.y;
	return ((WinTab*)pTab)->IsOnTab(pt);
}


OFL_API void _stdcall Tab_DestroyControl(void* pTab)
{
	((WinTab*)pTab)->DestroyControl();
}

OFL_API char* _stdcall Tab_GetClass(void* pTab)
{
	return (char*)((WinTab*)pTab)->GetClass();
}

OFL_API void _stdcall Tab_SetCaption(void* pTab,char* string)
{
	((WinTab*)pTab)->SetCaption(string);
}

OFL_API char* _stdcall Tab_GetCaption(void* pTab)
{
	return (char*)((WinTab*)pTab)->GetCaption();
}

OFL_API void _stdcall Tab_Hide(void* pTab)
{
	((WinTab*)pTab)->Hide();
}

OFL_API void _stdcall Tab_Show(void* pTab)
{
	((WinTab*)pTab)->Show();
}
