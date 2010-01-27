
#include "OWI_TreeView.h"
#include "../../CreateWnd/windows/OFControl.h"

//////////////////////////////////////////////////////////////////////////
//TreeItem
OFL_API char* _stdcall TreeItem_GetText(void* pTreeItem)
{
	return (char*)((TreeItem*)pTreeItem)->GetText();
}

OFL_API void _stdcall TreeItem_SetText(void* pTreeItem,char* string)
{
	((TreeItem*)pTreeItem)->SetText(string);
}

OFL_API bool _stdcall TreeItem_IsExpanded(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->IsExpanded();
}

OFL_API void _stdcall TreeItem_Expand(void* pTreeItem,bool expand)
{
	((TreeItem*)pTreeItem)->Expand(expand);
}

OFL_API bool _stdcall TreeItem_GetChecked(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetChecked();
}

OFL_API void _stdcall TreeItem_SetChecked(void* pTreeItem,bool check)
{
	((TreeItem*)pTreeItem)->SetChecked(check);
}

OFL_API bool _stdcall TreeItem_IsSelected(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->IsSelected();
}

OFL_API void _stdcall TreeItem_SetSelected(void* pTreeItem,bool select)
{
	((TreeItem*)pTreeItem)->SetSelected(select);
}

OFL_API bool _stdcall TreeItem_HasButton(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->HasButton();
}

OFL_API void _stdcall TreeItem_ShowButton(void* pTreeItem,bool showbtn)
{
	((TreeItem*)pTreeItem)->ShowButton(showbtn);
}

OFL_API bool _stdcall TreeItem_IsCut(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->IsCut();
}

OFL_API void _stdcall TreeItem_SetCut(void* pTreeItem,bool cut)
{
	((TreeItem*)pTreeItem)->SetCut(cut);
}

OFL_API bool _stdcall TreeItem_IsBold(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->IsBold();
}

OFL_API void _stdcall TreeItem_SetBold(void* pTreeItem,bool blod)
{
	((TreeItem*)pTreeItem)->SetBold(blod);
}

OFL_API void _stdcall TreeItem_SetDropHilited(void* pTreeItem,bool hilit)
{
	((TreeItem*)pTreeItem)->SetDropHilited(hilit);
}

OFL_API bool _stdcall TreeItem_GetDropHilited(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetDropHilited();
}

OFL_API unsigned int _stdcall TreeItem_GetTextColor(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetTextColor();
}

OFL_API void _stdcall TreeItem_SetTextColor(void* pTreeItem,unsigned int color)
{
	((TreeItem*)pTreeItem)->SetTextColor(color);
}

OFL_API unsigned int _stdcall TreeItem_GetTextBackColor(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetTextBackColor();
}

OFL_API void _stdcall TreeItem_SetTextBackColor(void* pTreeItem,unsigned int color)
{
	((TreeItem*)pTreeItem)->SetTextBackColor(color);
}

OFL_API int _stdcall TreeItem_GetImage(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetImage();
}

OFL_API void _stdcall TreeItem_SetImage(void* pTreeItem,int image)
{
	((TreeItem*)pTreeItem)->SetImage(image);
}

OFL_API int _stdcall TreeItem_GetSelectedImage(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetSelectedImage();
}

OFL_API void _stdcall TreeItem_SetSelectedImage(void* pTreeItem,int image)
{
	((TreeItem*)pTreeItem)->SetSelectedImage(image);
}

OFL_API int _stdcall TreeItem_GetStateImage(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetStateImage();
}

OFL_API void _stdcall TreeItem_SetStateImage(void* pTreeItem,int image)
{
	((TreeItem*)pTreeItem)->SetStateImage(image);
}

OFL_API int _stdcall TreeItem_GetOverlayImage(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetOverlayImage();
}

OFL_API void _stdcall TreeItem_SetOverlayImage(void* pTreeItem,int image)
{
	((TreeItem*)pTreeItem)->SetOverlayImage(image);
}

OFL_API void _stdcall TreeItem_SetData(void* pTreeItem,void* data)
{
	((TreeItem*)pTreeItem)->SetData(data);
}

OFL_API void _stdcall TreeItem_GetRect(void* pTreeItem,RECT& rc)
{
	Rect rect = ((TreeItem*)pTreeItem)->GetRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}

OFL_API void* _stdcall TreeItem_GetData(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetData();
}

OFL_API void* _stdcall TreeItem_GetParentItem(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetParentItem();
}

OFL_API void* _stdcall TreeItem_GetPrevItem(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetPrevItem();
}

OFL_API void* _stdcall TreeItem_GetNextItem(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetNextItem();
}

OFL_API void* _stdcall TreeItem_GetFirstChildItem(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetFirstChildItem();
}

OFL_API HTREEITEM _stdcall TreeItem_GetHandle(void* pTreeItem)
{
	return ((TreeItem*)pTreeItem)->GetHandle();
}


//////////////////////////////////////////////////////////////////////////
//TreeView
OFL_API void _stdcall OTreeView_SetTextColor(void* pTreeView,unsigned int color)
{
	((WinTreeView*)pTreeView)->SetTextColor(color);
}

OFL_API unsigned int _stdcall OTreeView_GetTextColor(void* pTreeView)
{
	return ((WinTreeView*)pTreeView)->GetTextColor();
}

OFL_API void _stdcall OTreeView_SetLineColor(void* pTreeView,unsigned int color)
{
	((WinTreeView*)pTreeView)->SetLineColor(color);
}

OFL_API unsigned int _stdcall OTreeView_GetLineColor(void* pTreeView)
{
	return ((WinTreeView*)pTreeView)->GetLineColor();
}

OFL_API void _stdcall OTreeView_SetItemIndent(void* pTreeView,int indent)
{
	((WinTreeView*)pTreeView)->SetItemIndent(indent);
}

OFL_API int _stdcall OTreeView_GetItemIndent(void* pTreeView)
{
	return ((WinTreeView*)pTreeView)->GetItemIndent();
}

OFL_API void _stdcall OTreeView_SetItemHeight(void* pTreeView,int height)
{
	((WinTreeView*)pTreeView)->SetItemHeight(height);
}

OFL_API int _stdcall OTreeView_GetItemHeight(void* pTreeView)
{
	return ((WinTreeView*)pTreeView)->GetItemHeight();
}

OFL_API void _stdcall OTreeView_SetToolTip(void* pTreeView,HWND tip)
{
	((WinTreeView*)pTreeView)->SetToolTip(tip);
}

OFL_API HWND _stdcall OTreeView_GetToolTip(void* pTreeView)
{
	return ((WinTreeView*)pTreeView)->GetToolTip();
}

OFL_API HWND _stdcall OTreeView_GetEditControl(void* pTreeView)
{
	return ((WinTreeView*)pTreeView)->GetEditControl();
}

OFL_API void* _stdcall OTreeView_GetTopItem(void* pTreeView)
{
	return ((WinTreeView*)pTreeView)->GetTopItem();
}

OFL_API void* _stdcall OTreeView_GetRootItem(void* pTreeView)
{
	return ((WinTreeView*)pTreeView)->GetRootItem();
}

OFL_API void* _stdcall OTreeView_GetSelectedItem(void* pTreeView)
{
	return ((WinTreeView*)pTreeView)->GetSelectedItem();
}


//����ImageList���ɷ�Ϊ��ʾ״̬ͼ���õ�ImageList����ʾ����ͼ���õ�ImageList����
OFL_API void _stdcall OTreeView_SetImageList(void* pTreeView,int type,void* imageList)
{
	((WinTreeView*)pTreeView)->SetImageList((ImageListType)type,(WinImageList*)imageList);
}

//��ȡָ�����͵�ImageList
OFL_API void* _stdcall OTreeView_GetImageList(void* pTreeView,int type)
{
	return ((WinTreeView*)pTreeView)->GetImageList((ImageListType)type);
}

//��ָ�����ֵ�Item֮�����һ���µ�Item��after��ΪNULL�����һ����Item������������һ����Item
OFL_API void* _stdcall OTreeView_InsertSibling(void* pTreeView,void* after)
{
	return ((WinTreeView*)pTreeView)->InsertSibling((TreeItem*)after);
}

//��ָ���ĸ�Item֮��׷��һ���µ���Item��parent��������ΪNULL
OFL_API void* _stdcall OTreeView_InsertChild(void* pTreeView,void* parent)
{
	return ((WinTreeView*)pTreeView)->InsertChild((TreeItem*)parent);
}

//ɾ��ָ����Item
OFL_API void _stdcall OTreeView_DeleteItem(void* pTreeView,void* item)
{
	((WinTreeView*)pTreeView)->DeleteItem((TreeItem*)item);
}

//ɾ�����е�Item
OFL_API void _stdcall OTreeView_DeleteAllItems(void* pTreeView)
{
	((WinTreeView*)pTreeView)->DeleteAllItems();
}

//��ȡָ�������Item
OFL_API void* _stdcall OTreeView_GetItem(void* pTreeView,HTREEITEM item)
{
	return ((WinTreeView*)pTreeView)->GetItem(item);
}

//��������ڿؼ��ͻ���ԭ�������x,y����������֮�µ�Item
OFL_API void* _stdcall OTreeView_TestPoint(void* pTreeView,int x,int y)
{
	return ((WinTreeView*)pTreeView)->TestPoint(x,y);
}

//ȷ��ָ����Item���ӣ������������Զ���������ʹ֮����
OFL_API void _stdcall OTreeView_EnsureVisible(void* pTreeView,void* item)
{
	((WinTreeView*)pTreeView)->EnsureVisible((TreeItem*)item);
}

//��ʼ�༭ĳ��Item������ֵ˵���Ƿ�ȷʵ�����˱༭ģʽ(Ҫ��ؼ���TreeViewDesc::mCanEdit���)
OFL_API bool _stdcall OTreeView_BeginEdit(void* pTreeView,void* item)
{
	return ((WinTreeView*)pTreeView)->BeginEdit((TreeItem*)item);
}

//�����༭ģʽ���û���������Ч
OFL_API void _stdcall OTreeView_EndEdit(void* pTreeView)
{
	((WinTreeView*)pTreeView)->EndEdit();
}

//ȡ���༭ģʽ���û������뱻������Item���ı�����
OFL_API void _stdcall OTreeView_CancelEdit(void* pTreeView)
{
	((WinTreeView*)pTreeView)->CancelEdit();
}


OFL_API void _stdcall OTreeView_DestroyControl(void* pTreeView)
{
	((WinTreeView*)pTreeView)->DestroyControl();
}

OFL_API char* _stdcall OTreeView_GetClass(void* pTreeView)
{
	return (char*)((WinTreeView*)pTreeView)->GetClass();
}

OFL_API void _stdcall OTreeView_SetCaption(void* pTreeView,char* string)
{
	((WinTreeView*)pTreeView)->SetCaption(string);
}

OFL_API char* _stdcall OTreeView_GetCaption(void* pTreeView)
{
	return (char*)((WinTreeView*)pTreeView)->GetCaption();
}

OFL_API void _stdcall OTreeView_Move(void* pTreeView,int dx,int dy)
{
	((WinTreeView*)pTreeView)->Move(dx,dy);
}

OFL_API void _stdcall OTreeView_SetSize(void* pTreeView,int width,int height)
{
	((WinTreeView*)pTreeView)->SetSize(width,height);
}

OFL_API void _stdcall OTreeView_SetPositionSize(void* pTreeView,int letf,int top,int width,int height)
{
	((WinTreeView*)pTreeView)->SetPositionSize(letf,top,width,height);
}
