
#include "OWI_Toolbar.h"
#include "../../CreateWnd/windows/OFControl.h"

//////////////////////////////////////////////////////////////////////////
//ToolbarButton

OFL_API int _stdcall ToolbarButton_GetIndex(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetIndex();
}

OFL_API int _stdcall ToolbarButton_GetId(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetId();
}

OFL_API void _stdcall ToolbarButton_SetImage(void* pToolbarButton,int image)
{
	((ToolbarButton*)pToolbarButton)->SetImage(image);
}

OFL_API int _stdcall ToolbarButton_GetImage(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetImage();
}

OFL_API void _stdcall ToolbarButton_SetText(void* pToolbarButton,char* text)
{
	((ToolbarButton*)pToolbarButton)->SetText(text);
}

OFL_API char* _stdcall ToolbarButton_GetText(void* pToolbarButton)
{
	return (char*)((ToolbarButton*)pToolbarButton)->GetText();
}

OFL_API void _stdcall ToolbarButton_SetEnabled(void* pToolbarButton,bool enable)
{
	((ToolbarButton*)pToolbarButton)->SetEnabled(enable);
}

OFL_API bool _stdcall ToolbarButton_GetEnabled(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetEnabled();
}

OFL_API void _stdcall ToolbarButton_SetVisible(void* pToolbarButton,bool visible)
{
	((ToolbarButton*)pToolbarButton)->SetVisible(visible);
}

OFL_API bool _stdcall ToolbarButton_GetVisible(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetVisible();
}

OFL_API void _stdcall ToolbarButton_SetChecked(void* pToolbarButton,bool check)
{
	((ToolbarButton*)pToolbarButton)->SetChecked(check);
}

OFL_API bool _stdcall ToolbarButton_GetChecked(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetChecked();
}

OFL_API void _stdcall ToolbarButton_SetPressed(void* pToolbarButton,bool press)
{
	((ToolbarButton*)pToolbarButton)->SetPressed(press);
}

OFL_API bool _stdcall ToolbarButton_GetPressed(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetPressed();
}

OFL_API void _stdcall ToolbarButton_SetHilited(void* pToolbarButton,bool high)
{
	((ToolbarButton*)pToolbarButton)->SetHilited(high);
}

OFL_API bool _stdcall ToolbarButton_GetHilited(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetHilited();
}

OFL_API void _stdcall ToolbarButton_SetTipText(void* pToolbarButton,char* text)
{
	((ToolbarButton*)pToolbarButton)->SetTipText(text);
}

OFL_API char* _stdcall ToolbarButton_GetTipText(void* pToolbarButton)
{
	return (char*)((ToolbarButton*)pToolbarButton)->GetTipText();
}

OFL_API void _stdcall ToolbarButton_SetMenu(void* pToolbarButton,void* menu)
{
	((ToolbarButton*)pToolbarButton)->SetMenu((WinMenu*)menu);
}

OFL_API void _stdcall ToolbarButton_SetData(void* pToolbarButton,void* data)
{
	((ToolbarButton*)pToolbarButton)->SetData(data);
}

OFL_API void _stdcall ToolbarButton_GetRect(void* pToolbarButton,RECT& rc)
{
	Rect rect = ((ToolbarButton*)pToolbarButton)->GetRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}

OFL_API void* _stdcall ToolbarButton_GetData(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetData();
}

OFL_API void* _stdcall ToolbarButton_GetMenu(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetMenu();
}

OFL_API void* _stdcall ToolbarButton_GetOwner(void* pToolbarButton)
{
	return ((ToolbarButton*)pToolbarButton)->GetOwner();
}


//////////////////////////////////////////////////////////////////////////
//Toolbar

OFL_API int _stdcall Toolbar_GetButtonCount(void* pToolbar)
{
	return ((WinToolbar*)pToolbar)->GetButtonCount();
}

OFL_API void _stdcall Toolbar_SetButtonSize(void* pToolbar,const SIZE& size)
{
	Size sz;
	sz.mWidth = size.cx;
	sz.mHeight = size.cy;
	((WinToolbar*)pToolbar)->SetButtonSize(sz);
}

OFL_API void _stdcall Toolbar_SetBitmapSize(void* pToolbar,const SIZE& size)
{
	Size sz;
	sz.mWidth = size.cx;
	sz.mHeight = size.cy;
	((WinToolbar*)pToolbar)->SetBitmapSize(sz);
}

OFL_API void _stdcall Toolbar_SetHotItem(void* pToolbar,int index)
{
	((WinToolbar*)pToolbar)->SetHotItem(index);
}

OFL_API int _stdcall Toolbar_GetHotItem(void* pToolbar)
{
	return ((WinToolbar*)pToolbar)->GetHotItem();
}

OFL_API void _stdcall Toolbar_SetPadding(void* pToolbar,const SIZE& size)
{
	Size sz;
	sz.mWidth = size.cx;
	sz.mHeight = size.cy;
	((WinToolbar*)pToolbar)->SetPadding(sz);
}

OFL_API void _stdcall Toolbar_SetRowCount(void* pToolbar,int rows)
{
	((WinToolbar*)pToolbar)->SetRowCount(rows);
}

OFL_API int _stdcall Toolbar_GetRowCount(void* pToolbar)
{
	return ((WinToolbar*)pToolbar)->GetRowCount();
}

OFL_API void _stdcall Toolbar_SetToolTip(void* pToolbar,HWND tips)
{
	((WinToolbar*)pToolbar)->SetToolTip(tips);
}

OFL_API void _stdcall Toolbar_SetIndent(void* pToolbar,int indent)
{
	((WinToolbar*)pToolbar)->SetIndent(indent);
}

OFL_API void _stdcall Toolbar_GetButtonSize(void* pToolbar,SIZE& size)
{
	Size sz = ((WinToolbar*)pToolbar)->GetButtonSize();
	size.cx = sz.mWidth;
	size.cy = sz.mHeight;
}

OFL_API void _stdcall Toolbar_GetBitmapSize(void* pToolbar,SIZE& size)
{
	Size sz = ((WinToolbar*)pToolbar)->GetBitmapSize();
	size.cx = sz.mWidth;
	size.cy = sz.mHeight;
}

OFL_API void _stdcall Toolbar_GetPadding(void* pToolbar,SIZE& size)
{
	Size sz = ((WinToolbar*)pToolbar)->GetPadding();
	size.cx = sz.mWidth;
	size.cy = sz.mHeight;
}

OFL_API HWND _stdcall Toolbar_GetToolTip(void* pToolbar)
{
	return ((WinToolbar*)pToolbar)->GetToolTip();
}

OFL_API void _stdcall Toolbar_SetImageList(void* pToolbar,void* imageList)
{
	((WinToolbar*)pToolbar)->SetImageList((WinImageList*)imageList);
}

OFL_API void _stdcall Toolbar_SetHotImageList(void* pToolbar,void* imageList)
{
	((WinToolbar*)pToolbar)->SetHotImageList((WinImageList*)imageList);
}

OFL_API void _stdcall Toolbar_SetDisabledImageList(void* pToolbar,void* imageList)
{
	((WinToolbar*)pToolbar)->SetDisabledImageList((WinImageList*)imageList);
}

OFL_API void* _stdcall Toolbar_GetImageList(void* pToolbar)
{
	return ((WinToolbar*)pToolbar)->GetImageList();
}

OFL_API void* _stdcall Toolbar_GetHotImageList(void* pToolbar)
{
	return ((WinToolbar*)pToolbar)->GetHotImageList();
}

OFL_API void* _stdcall Toolbar_GetDisabledImageList(void* pToolbar)
{
	return ((WinToolbar*)pToolbar)->GetDisabledImageList();
}

OFL_API void* _stdcall Toolbar_GetButton(void* pToolbar,int index)
{
	return ((WinToolbar*)pToolbar)->GetButton(index);
}


//����4������Ϊ��ť���뺯����ע������밴ť��id�����뱾�������е�������ťid�ظ���Ҳ��Ҫ�������������а�ťid�ظ���
//��λ��index֮ǰ����һ����ͨ��ť���û�����ָ����ť��id��showTextָ���Ƿ���ʾ�ı������˲�������������ʾ��ͼƬ�·�
//�Ĺ�������Ч��
OFL_API void* _stdcall Toolbar_InsertButton(void* pToolbar,int index, int id, bool showText)
{
	return ((WinToolbar*)pToolbar)->InsertButton(index,id,showText);
}

//��λ��index֮ǰ����һ��Checkʽ��ť���û��������ְ�ť�������ְ���״̬���ٰ�һ�£��ָֻ�ԭ״��
//���group����Ϊtrue�������ڵ�Checkʽ��ť����һ�飬��״̬���⣬������ֻ��һ���ܱ���ѹ��״̬��
OFL_API void* _stdcall Toolbar_InsertCheck(void* pToolbar,bool group, int index, int id, bool showText)
{
	return ((WinToolbar*)pToolbar)->InsertCheck(group,index,id,showText);
}

//��λ��index֮ǰ����һ������ʽ��ť�����ְ�ť�Ҳ���һ��С��ͷ�����wholeΪfalse����ť������С��ͷ
//������һ�𣬷����Ƿֿ��ġ�
OFL_API void* _stdcall Toolbar_InsertDropdown(void* pToolbar,bool whole, int index, int id, bool showText)
{
	return ((WinToolbar*)pToolbar)->InsertDropdown(whole,index,id,showText);
}

//��λ��index֮ǰ����һ���ָť(���ַָťʵ������һ�ֱȽ�խ�Ļ��)
OFL_API void* _stdcall Toolbar_InsertSeperator(void* pToolbar,int index)
{
	return ((WinToolbar*)pToolbar)->InsertSeperator(index);
}
		
//�ڹ�����β��׷��һ��Button��ť������������ο�InsertButton()��ע��
OFL_API void* _stdcall Toolbar_AddButton(void* pToolbar,int id, bool showText)
{
	return  ((WinToolbar*)pToolbar)->AddButton(id,showText);
}

//�ڹ�����β��׷��һ��Check��ť������������ο�InsertCheck()��ע��
OFL_API void* _stdcall Toolbar_AddCheck(void* pToolbar,bool group, int id, bool showText)
{
	return ((WinToolbar*)pToolbar)->AddCheck(group,id,showText);
}

//�ڹ�����β��׷��һ��Dropdown��ť������������ο�InsertDropdown()��ע��
OFL_API void* _stdcall Toolbar_AddDropdown(void* pToolbar,bool whole, int id, bool showText)
{
	return ((WinToolbar*)pToolbar)->AddDropdown(whole,id,showText);
}

//�ڹ�����β��׷��һ��Seperator��ť
OFL_API void* _stdcall Toolbar_AddSeperator(void* pToolbar)
{
	return ((WinToolbar*)pToolbar)->AddSeperator();
}

//ɾ��ָ�������İ�ť
OFL_API void _stdcall Toolbar_DeleteButton(void* pToolbar,int index)
{
	((WinToolbar*)pToolbar)->DeleteButton(index);
}

//ɾ�����а�ť
OFL_API void _stdcall Toolbar_DeleteAllButtons(void* pToolbar)
{
	((WinToolbar*)pToolbar)->DeleteAllButtons();
}

//��һ����ť��iFromλ���ƶ���iToλ��
OFL_API void _stdcall Toolbar_MoveButton(void* pToolbar,int iFrom,int iTo)
{
	((WinToolbar*)pToolbar)->MoveButton(iFrom,iTo);
}

//���µ����������ĳߴ�(ͨ�����û��ı��˰�ť��С��ťͼ���Сʱ��Ҫ���ô˺���)
OFL_API void _stdcall Toolbar_Resize(void* pToolbar)
{
	((WinToolbar*)pToolbar)->Resize();
}

//����һ������Ϊp(����ڹ��߿ͻ���ԭ��)�ĵ��Ƿ���һ����Separator�İ�ť֮��
OFL_API void* _stdcall Toolbar_IsOnButton(void* pToolbar,const POINT& p)
{
	Point pt;
	pt.x = p.x;
	pt.y = p.y;
	return ((WinToolbar*)pToolbar)->IsOnButton(pt);
}

//�ҵ�ָ��id�İ�ť�����Ҳ���������NULL
OFL_API void* _stdcall Toolbar_FindButton(void* pToolbar,int id)
{
	return ((WinToolbar*)pToolbar)->FindButton(id);
}


OFL_API void _stdcall Toolbar_DestroyControl(void* pToolbar)
{
	((WinToolbar*)pToolbar)->DestroyControl();
}

OFL_API char* _stdcall Toolbar_GetClass(void* pToolbar)
{
	return (char*)((WinToolbar*)pToolbar)->GetClass();
}

OFL_API void _stdcall Toolbar_SetCaption(void* pToolbar,char* string)
{
	((WinToolbar*)pToolbar)->SetCaption(string);
}

OFL_API char* _stdcall Toolbar_GetCaption(void* pToolbar)
{
	return (char*)((WinToolbar*)pToolbar)->GetCaption();
}
