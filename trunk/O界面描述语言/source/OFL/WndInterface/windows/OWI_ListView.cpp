
#include "OWI_ListView.h"
#include "../../CreateWnd/windows/OFControl.h"

//////////////////////////////////////////////////////////////////////////
//ListItem
OFL_API int _stdcall ListItem_GetIndex(void* pListItem)
{
	return ((ListItem*)pListItem)->GetIndex();
}

OFL_API void _stdcall ListItem_SetText(void* pListItem,int subindex,char* string)
{
	((ListItem*)pListItem)->SetText(subindex,string);
}

OFL_API char* _stdcall ListItem_GetText(void* pListItem,int subindex)
{
	return (char*)((ListItem*)pListItem)->GetText(subindex);
}

OFL_API void _stdcall ListItem_SetImage(void* pListItem,int subindex,int image)
{
	((ListItem*)pListItem)->SetImage(subindex,image);
}

OFL_API int _stdcall ListItem_GetImage(void* pListItem,int subindex)
{
	return ((ListItem*)pListItem)->GetImage(subindex);
}

OFL_API void _stdcall ListItem_SetStateImage(void* pListItem,int subindex,int image)
{
	((ListItem*)pListItem)->SetStateImage(subindex,image);
}

OFL_API int _stdcall ListItem_GetStateImage(void* pListItem,int subindex)
{
	return ((ListItem*)pListItem)->GetStateImage(subindex);
}

OFL_API void _stdcall ListItem_SetOverlayImage(void* pListItem,int subindex,int image)
{
	((ListItem*)pListItem)->SetOverlayImage(subindex,image);
}

OFL_API int _stdcall ListItem_GetOverlayImage(void* pListItem,int subindex)
{
	return ((ListItem*)pListItem)->GetOverlayImage(subindex);
}

OFL_API void _stdcall ListItem_SetGroup(void* pListItem,void* pListGroup)
{
	((ListItem*)pListItem)->SetGroup((ListGroup*)pListGroup);
}

OFL_API void _stdcall ListItem_SetIndent(void* pListItem,int indent)
{
	((ListItem*)pListItem)->SetIndent(indent);
}

OFL_API int _stdcall ListItem_GetIndent(void* pListItem)
{
	return ((ListItem*)pListItem)->GetIndent();
}

OFL_API void _stdcall ListItem_SetChecked(void* pListItem,bool check)
{
	((ListItem*)pListItem)->SetChecked(check);
}

OFL_API bool _stdcall ListItem_GetChecked(void* pListItem)
{
	return ((ListItem*)pListItem)->GetChecked();
}

OFL_API void _stdcall ListItem_SetSelected(void* pListItem,bool select)
{
	((ListItem*)pListItem)->SetSelected(select);
}

OFL_API bool _stdcall ListItem_IsSelected(void* pListItem)
{
	return ((ListItem*)pListItem)->IsSelected();
}

OFL_API void _stdcall ListItem_SetCut(void* pListItem,bool cut)
{
	((ListItem*)pListItem)->SetCut(cut);
}

OFL_API bool _stdcall ListItem_IsCut(void* pListItem)
{
	return ((ListItem*)pListItem)->IsCut();
}

OFL_API void _stdcall ListItem_SetFocused(void* pListItem,bool focus)
{
	((ListItem*)pListItem)->SetFocused(focus);
}

OFL_API bool _stdcall ListItem_GetFocused(void* pListItem)
{
	return ((ListItem*)pListItem)->GetFocused();
}

OFL_API void _stdcall ListItem_SetDropHilited(void* pListItem,bool hilite)
{
	((ListItem*)pListItem)->SetDropHilited(hilite);
}

OFL_API bool _stdcall ListItem_GetDropHilited(void* pListItem)
{
	return ((ListItem*)pListItem)->GetDropHilited();
}

OFL_API void _stdcall ListItem_SetTextColor(void* pListItem,int subindex,unsigned int color)
{
	((ListItem*)pListItem)->SetTextColor(subindex,color);
}

OFL_API unsigned int _stdcall ListItem_GetTextColor(void* pListItem,int subindex)
{
	return ((ListItem*)pListItem)->GetTextColor(subindex);
}

OFL_API void _stdcall ListItem_SetTextBackColor(void* pListItem,int subindex,unsigned int color)
{
	((ListItem*)pListItem)->SetTextBackColor(subindex,color);
}

OFL_API unsigned int _stdcall ListItem_GetTextBackColor(void* pListItem,int color)
{
	return ((ListItem*)pListItem)->GetTextBackColor(color);
}

OFL_API void _stdcall ListItem_GetRect(void* pListItem,RECT& rc)
{
	Rect rect = ((ListItem*)pListItem)->GetRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}

OFL_API void _stdcall ListItem_GetSubRect(void* pListItem,int subIndex,RECT& rc)
{
	Rect rect = ((ListItem*)pListItem)->GetSubRect(subIndex);
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}

OFL_API void _stdcall ListItem_SetData(void* pListItem,void* data)
{
	((ListItem*)pListItem)->SetData(data);
}

OFL_API void* _stdcall ListItem_GetData(void* pListItem)
{
	return ((ListItem*)pListItem)->GetData();
}

OFL_API void _stdcall ListItem_SetPosition(void* pListItem,const POINT& p)
{
	Point point;
	point.x = p.x;
	point.y = p.y;
	((ListItem*)pListItem)->SetPosition(point);
}

OFL_API void _stdcall ListItem_GetPosition(void* pListItem,POINT& p)
{
	Point point = ((ListItem*)pListItem)->GetPosition();
	p.x = point.x;
	p.y = point.y;
}

OFL_API void* _stdcall ListItem_GetGroup(void* pListItem)
{
	return ((ListItem*)pListItem)->GetGroup();
}

OFL_API void* _stdcall ListItem_GetOwner(void* pListItem)
{
	return ((ListItem*)pListItem)->GetOwner();
}

//////////////////////////////////////////////////////////////////////////
//ListColumn

OFL_API int _stdcall ListColumn_GetIndex(void* pListColumn)
{
	return ((ListColumn*)pListColumn)->GetIndex();
}

OFL_API void _stdcall ListColumn_SetText(void* pListColumn,char* name)
{
	((ListColumn*)pListColumn)->SetText(name);
}

OFL_API char* _stdcall ListColumn_GetText(void* pListColumn)
{
	return (char*)((ListColumn*)pListColumn)->GetText();
}

OFL_API void _stdcall ListColumn_SetFormat(void* pListColumn,int format)
{
	((ListColumn*)pListColumn)->SetFormat(format);
}

OFL_API int _stdcall ListColumn_GetFormat(void* pListColumn)
{
	return ((ListColumn*)pListColumn)->GetFormat();
}

OFL_API void _stdcall ListColumn_SetWidth(void* pListColumn,int width)
{
	((ListColumn*)pListColumn)->SetWidth(width);
}

OFL_API int _stdcall ListColumn_GetWidth(void* pListColumn)
{
	return ((ListColumn*)pListColumn)->GetWidth();
}

OFL_API void _stdcall ListColumn_SetImage(void* pListColumn,int image)
{
	((ListColumn*)pListColumn)->SetImage(image);
}

OFL_API int _stdcall ListColumn_GetImage(void* pListColumn)
{
	return ((ListColumn*)pListColumn)->GetImage();
}

OFL_API void _stdcall ListColumn_SetOrder(void* pListColumn,int order)
{
	((ListColumn*)pListColumn)->SetOrder(order);
}

OFL_API int _stdcall ListColumn_GetOrder(void* pListColumn)
{
	return ((ListColumn*)pListColumn)->GetOrder();
}

OFL_API void* _stdcall ListColumn_GetOwner(void* pListColumn)
{
	return ((ListColumn*)pListColumn)->GetOwner();
}

//////////////////////////////////////////////////////////////////////////
//ListGroup

OFL_API int _stdcall ListGroup_GetId(void* pListGroup)
{
	return ((ListGroup*)pListGroup)->GetId();
}

OFL_API void _stdcall ListGroup_SetFormat(void* pListGroup,unsigned int format)
{
	((ListGroup*)pListGroup)->SetFormat(format);
}

OFL_API unsigned int _stdcall ListGroup_GetFormat(void* pListGroup)
{
	return ((ListGroup*)pListGroup)->GetFormat();
}

OFL_API void _stdcall ListGroup_SetPosition(void* pListGroup,int pos)
{
	((ListGroup*)pListGroup)->SetPosition(pos);
}

OFL_API void _stdcall ListGroup_SetHeader(void* pListGroup,wchar_t* name)
{
	((ListGroup*)pListGroup)->SetHeader(name);
}

OFL_API void _stdcall ListGroup_SetFooter(void* pListGroup,wchar_t* name)
{
	((ListGroup*)pListGroup)->SetFooter(name);
}

OFL_API wchar_t* _stdcall ListGroup_GetHeader(void* pListGroup)
{
	return (wchar_t*)((ListGroup*)pListGroup)->GetHeader();
}

OFL_API wchar_t* _stdcall ListGroup_GetFooter(void* pListGroup)
{
	return (wchar_t*)((ListGroup*)pListGroup)->GetFooter();
}

OFL_API void* _stdcall ListGroup_GetOwner(void* pListGroup)
{
	return ((ListGroup*)pListGroup)->GetOwner();
}

//////////////////////////////////////////////////////////////////////////
//ListView

OFL_API void _stdcall OListView_SetToolTip(void* pListView,HWND hToolTip)
{
	((WinListView*)pListView)->SetToolTip(hToolTip);
}

OFL_API int _stdcall OListView_GetColumnCount(void* pListView)
{
	return ((WinListView*)pListView)->GetColumnCount();
}

OFL_API int _stdcall OListView_GetItemCount(void* pListView)
{
	return ((WinListView*)pListView)->GetItemCount();
}

OFL_API int _stdcall OListView_GetSelectedItemCount(void* pListView)
{
	return ((WinListView*)pListView)->GetSelectedItemCount();
}

OFL_API void _stdcall OListView_SetTextColor(void* pListView,unsigned int color)
{
	((WinListView*)pListView)->SetTextColor(color);
}

OFL_API unsigned int _stdcall OListView_GetTextColor(void* pListView)
{
	return ((WinListView*)pListView)->GetTextColor();
}

OFL_API void _stdcall OListView_SetTextBackColor(void* pListView,unsigned int color)
{
	((WinListView*)pListView)->SetTextBackColor(color);
}

OFL_API unsigned int _stdcall OListView_GetTextBackColor(void* pListView)
{
	return ((WinListView*)pListView)->GetTextBackColor();
}

OFL_API void _stdcall OListView_SetWorkAreaCount(void* pListView,int count)
{
	((WinListView*)pListView)->SetWorkAreaCount(count);
}

OFL_API int _stdcall OListView_GetWorkAreaCount(void* pListView)
{
	return ((WinListView*)pListView)->GetWorkAreaCount();
}

OFL_API int _stdcall OListView_GetTopIndex(void* pListView)
{
	return ((WinListView*)pListView)->GetTopIndex();
}

OFL_API void _stdcall OListView_SetHoverTime(void* pListView,unsigned int time)
{
	((WinListView*)pListView)->SetHoverTime(time);
}

OFL_API unsigned int _stdcall OListView_GetHoverTime(void* pListView)
{
	return ((WinListView*)pListView)->GetHoverTime();
}

OFL_API void _stdcall OListView_SetSelectionMark(void* pListView,int mark)
{
	((WinListView*)pListView)->SetSelectionMark(mark);
}

OFL_API int _stdcall OListView_GetSelectionMark(void* pListView)
{
	return ((WinListView*)pListView)->GetSelectionMark();
}

OFL_API void _stdcall OListView_SetHotItem(void* pListView,int item)
{
	((WinListView*)pListView)->SetHotItem(item);
}

OFL_API int _stdcall OListView_GetHotItem(void* pListView)
{
	return ((WinListView*)pListView)->GetHotItem();
}

OFL_API int _stdcall OListView_GetCountPerPage(void* pListView)
{
	return ((WinListView*)pListView)->GetCountPerPage();
}

OFL_API void _stdcall OListView_SetGroupEnabled(void* pListView,bool enable)
{
	((WinListView*)pListView)->SetGroupEnabled(enable);
}

OFL_API bool _stdcall OListView_IsGroupEnabled(void* pListView)
{
	return ((WinListView*)pListView)->IsGroupEnabled();
}

OFL_API int _stdcall OListView_GetGroupCount(void* pListView)
{
	return ((WinListView*)pListView)->GetGroupCount();
}

OFL_API void _stdcall OListView_SetInsertMark(void* pListView,int mark)
{
	((WinListView*)pListView)->SetInsertMark(mark);
}

OFL_API int _stdcall OListView_GetInsertMark(void* pListView)
{
	return ((WinListView*)pListView)->GetInsertMark();
}

OFL_API void _stdcall OListView_SetInsertMarkColor(void* pListView,unsigned int color)
{
	((WinListView*)pListView)->SetInsertMarkColor(color);
}

OFL_API unsigned int _stdcall OListView_GetInsertMarkColor(void* pListView)
{
	return ((WinListView*)pListView)->GetInsertMarkColor();
}

OFL_API void _stdcall OListView_SetOutlineColor(void* pListView,unsigned int color)
{
	((WinListView*)pListView)->SetOutlineColor(color);
}

OFL_API unsigned int _stdcall OListView_GetOutlineColor(void* pListView)
{
	return ((WinListView*)pListView)->GetOutlineColor();
}

OFL_API void _stdcall OListView_SetSelectedColumn(void* pListView,unsigned int column)
{
	((WinListView*)pListView)->SetSelectedColumn(column);
}

OFL_API unsigned int _stdcall OListView_GetSelectedColumn(void* pListView)
{
	return ((WinListView*)pListView)->GetSelectedColumn();
}

OFL_API void _stdcall OListView_SetWorkArea(void* pListView,int index,const RECT& rc)
{
	Rect rect;
	rect.mLeft = rc.left;
	rect.mTop = rc.top;
	rect.mRight = rc.right;
	rect.mBottom = rc.bottom;	
	((WinListView*)pListView)->SetWorkArea(index,rect);	
}

OFL_API void _stdcall OListView_SetHotCursor(void* pListView,HCURSOR hCursor)
{
	((WinListView*)pListView)->SetHotCursor(hCursor);
}

OFL_API void _stdcall OListView_SetViewMode(void* pListView,int mode)
{
	((WinListView*)pListView)->SetViewMode((ListViewMode)mode);
}

OFL_API void _stdcall OListView_GetWorkArea(void* pListView,int index,RECT& rc)
{
	Rect rect = ((WinListView*)pListView)->GetWorkArea();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;
}

OFL_API void _stdcall OListView_GetViewRect(void* pListView,RECT& rc)
{
	Rect rect = ((WinListView*)pListView)->GetViewRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;
}

OFL_API void _stdcall OListView_GetInsertMarkRect(void* pListView,RECT& rc)
{
	Rect rect = ((WinListView*)pListView)->GetInsertMarkRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;
}

OFL_API HWND _stdcall OListView_GetToolTip(void* pListView)
{
	return ((WinListView*)pListView)->GetToolTip();
}

OFL_API HWND _stdcall OListView_GetHeader(void* pListView)
{
	return ((WinListView*)pListView)->GetHeader();
}

OFL_API HWND _stdcall OListView_GetEditControl(void* pListView)
{
	return ((WinListView*)pListView)->GetEditControl();
}

OFL_API void _stdcall OListView_GetOrigin(void* pListView,POINT& p)
{
	Point pt = ((WinListView*)pListView)->GetOrigin();
	p.x = pt.x;
	p.y = pt.y;
}

OFL_API HCURSOR _stdcall OListView_GetHotCursor(void* pListView)
{
	return ((WinListView*)pListView)->GetHotCursor();
}

OFL_API void* _stdcall OListView_GetItem(void* pListView,int index)
{
	return ((WinListView*)pListView)->GetItem(index);
}

OFL_API void* _stdcall OListView_GetGroup(void* pListView,int index)
{
	return ((WinListView*)pListView)->GetGroup(index);
}

OFL_API void* _stdcall OListView_GetColumn(void* pListView,int index)
{
	return ((WinListView*)pListView)->GetColumn(index);
}

OFL_API int _stdcall OListView_GetViewMode(void* pListView)
{
	return ((WinListView*)pListView)->GetViewMode();
}


//׷��һ�У�Ĭ�ϸ�ʽΪ����룬�п�Ϊ50�����أ������ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_AddColumn(void* pListView)
{
	return ((WinListView*)pListView)->AddColumn();
}

//׷��һ�У�Ĭ�ϸ�ʽΪ����룬widthΪ�п�textΪ���ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_AddColumnText(void* pListView,int width,char* text)
{
	return ((WinListView*)pListView)->AddColumn(width,text);
}

//׷��һ�У�formatΪ������ʽ��widthΪ�п�textΪ���ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_AddColumnFormat(void* pListView,int format,int width,char* text)
{
	return ((WinListView*)pListView)->AddColumn(format,width,text);
}

//������indexǰ����һ�У�Ĭ������룬�п�50�����أ������ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_InsertColumn(void* pListView,int index)
{
	return ((WinListView*)pListView)->InsertColumn(index);
}

//������indexǰ����һ�У�Ĭ�������������������ָ���п�����ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_InsertColumnText(void* pListView,int index,int width,char* text)
{
	return ((WinListView*)pListView)->InsertColumn(index,width,text);
}

//������indexǰ����һ�У�formatΪ�����ʽ��widthΪ�п�textΪ���ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_InsertColumnFormat(void* pListView,int index,int format,int width,char* text)
{
	return ((WinListView*)pListView)->InsertColumn(index,format,width,text);
}

//ɾ������Ϊindex����(ע�⣺��һ�в���ɾ�������뱣��)������ֵ����ɾ�������Ƿ�ɹ�
OFL_API bool _stdcall OListView_DeleteColumn(void* pListView,int index)
{
	return ((WinListView*)pListView)->DeleteColumn(index);
}

//ɾ��������
OFL_API void _stdcall OListView_DeleteAllColumns(void* pListView)
{
	((WinListView*)pListView)->DeleteAllColumns();
}

//����ImageList��ListView�������ð���3��ImageList���ֱ�Ϊ��ͼ��ģʽ����ʹ�õ�ImageList��Сͼ��ģʽ
//����ʹ�õ�ImageList��������ʾ״̬��ImageList��
OFL_API void _stdcall OListView_SetImageList(void* pListView,int type,void* imagelist)
{
	((WinListView*)pListView)->SetImageList((ImageListType)type,(WinImageList*)imagelist);
}

//��ȡ��Ӧ��ImageList
OFL_API void* _stdcall OListView_GetImageList(void* pListView,int type)
{
	return ((WinListView*)pListView)->GetImageList((ImageListType)type);
}

//׷��һ���µ�Item�������¼ӵ�ListItem������ؼ�����ĳ����������˺�����һ�����ڿؼ�β��ִ��׷�ӣ����ܿ�����ĳ��λ��
//ִ�в������������ֵ�ĺ�����ο������InsertItem()ע�͡�
OFL_API void* _stdcall OListView_AddItem(void* pListView)
{
	return ((WinListView*)pListView)->AddItem();
}

//�ڵ�index������ǰ����һ���µ�Item��ע�⣺����ֵListItem�ĳ�ԱmIndexֻ����ʱ���塣����Ժ��û��ڴ�ListItem֮ǰ��ӻ�
//ɾ��������ListItem�����ListItem��mIndex��ʧЧ���û�Ӧ����������UpdateItemIndexˢ����mIndexֵ������ؼ���������
//����������һ��������ָ��Item֮ǰ��
OFL_API void* _stdcall OListView_InsertItem(void* pListView,int index)
{
	return ((WinListView*)pListView)->InsertItem(index);
}

//ɾ��ָ����Item
OFL_API bool _stdcall OListView_DeleteItem(void* pListView,void* item)
{
	return ((WinListView*)pListView)->DeleteItem((ListItem*)item);
}

//ɾ��ָ��������Item
OFL_API bool _stdcall OListView_DeleteItemIndex(void* pListView,int index)
{
	return ((WinListView*)pListView)->DeleteItem(index);
}

//ɾ�����е�Item
OFL_API void _stdcall OListView_DeleteAllItems(void* pListView)
{
	((WinListView*)pListView)->DeleteAllItems();
}

//��ȡItem�ڿؼ��е�����
OFL_API int _stdcall OListView_GetItemIndex(void* pListView,void* item)
{
	return ((WinListView*)pListView)->GetItemIndex((ListItem*)item);
}

//�������ı�ƥ��text��Item��exactָ���ı��Ƿ�Ҫ��ȷƥ�䣺true��Ҫ���ı���ȫ��ͬ��falseֻҪ��Item�ı���text��ʼ������������
//��Сд���еġ��ҵ�����Ҫ���Item�򷵻���ָ�룬���򷵻�NULL
OFL_API void* _stdcall OListView_FindItem(void* pListView,char* text, bool exact)
{
	return ((WinListView*)pListView)->FindItem(text,exact);
}

//�ڴ�ͼ���Сͼ��ģʽ����direction�����ҵ���p��(��Կؼ��ͻ���ԭ��)�����Item�������ΪVK_LEFT��VK_RIGHT��VK_UP��VK_DOWN
OFL_API void* _stdcall OListView_FindNearestItem(void* pListView,const POINT& p,unsigned int direction)
{
	Point pt;
	pt.x = p.x;
	pt.y = p.y;
	return ((WinListView*)pListView)->FindNearestItem(pt,direction);
}

//��ʼ�༭ָ����Item���ؼ�������пɱ༭���(ListViewDesc::mCanEdit������Ϊtrue)����ʱ�ᴴ��һ��Edit�ؼ���
//���ı�ΪItem���ı�������ȫ������ѡ�С�����ֵָ���Ƿ�ȷʵ��ʾ��Edit�ؼ���
OFL_API bool _stdcall OListView_BeginEdit(void* pListView,int index)
{
	return ((WinListView*)pListView)->BeginEdit(index);
}

//���ĳ��Item�����ڱ༭״̬���˺�����ȡ����༭״̬���༭�ؼ��Զ����ز�����(XP)
OFL_API void _stdcall OListView_CancelEdit(void* pListView)
{
	((WinListView*)pListView)->CancelEdit();
}

//�ڴ�ͼ��ģʽ�����°������е�Item��ȷ�����룬����alignָ�����뷽ʽ(��ο�ö������ListItemAlign{})
OFL_API void _stdcall OListView_Arrange(void* pListView,int align)
{
	((WinListView*)pListView)->Arrange(align);
}

//ȷ��ָ����Item���ӣ��������ӣ������ListViewʹ֮����
OFL_API void _stdcall OListView_EnsureVisible(void* pListView,int index)
{
	((WinListView*)pListView)->EnsureVisible(index);
}

//�����ͻ����е����ݣ��������ֱ�ָ��ˮƽ�ʹ�ֱ������������(���ؼ�ģʽΪReport��ֻ�ܴ�ֱ��������dy���Զ������������)
OFL_API void _stdcall OListView_Scroll(void* pListView,int dx, int dy)
{
	((WinListView*)pListView)->Scroll(dx,dy);
}

//������Iconģʽ��ͼ��֮��ļ����ע��cx��cy�������ͼ��Ŀ�ߣ���Ȼ�ᵼ��ͼ����ص���������Ϊ-1����ָ�Ĭ��ֵ
OFL_API void _stdcall OListView_SetIconSpacing(void* pListView,int cx,int cy)
{
	((WinListView*)pListView)->SetIconSpacing(cx,cy);
}

//��ȡItem֮��ļ�࣬����Ϊtrueָ����Сͼ��ģʽ�µ�Item��࣬�������ͼ��ģʽ�µ�Item���
OFL_API unsigned int _stdcall OListView_GetItemSpacing(void* pListView,bool smallIcon)
{
	return ((WinListView*)pListView)->GetItemSpacing(smallIcon);
}

//�����ڿؼ���ǰ�������ı������ؿ��
OFL_API int _stdcall OListView_GetStringWidth(void* pListView,char* text)
{
	return ((WinListView*)pListView)->GetStringWidth(text);
}

//����ָ������֮�µ�Item(p�����ؼ��ͻ���ԭ��)
OFL_API void* _stdcall OListView_IsOnItem(void* pListView,const POINT& p)
{
	Point pt;
	pt.x = p.x;
	pt.y = p.y;
	return ((WinListView*)pListView)->IsOnItem(pt);
}

//����һ�����Ƿ���Itemͼ��֮�ϣ�p����Կؼ��ͻ���ԭ������꣬����Item(�����겻��һ��Item���򷵻�NULL)
OFL_API void* _stdcall OListView_IsOnIcon(void* pListView,const POINT& p,/*Out*/int* subItem)
{
	Point pt;
	pt.x = p.x;
	pt.y = p.y;
	return ((WinListView*)pListView)->IsOnIcon(pt,subItem);
}

//����һ�����Ƿ���Item״̬ͼ��֮�ϣ���������ͬIsOnIcon()˵��
OFL_API void* _stdcall OListView_IsOnStateIcon(void* pListView,const POINT& p,/*Out*/int* subItem)
{
	Point pt;
	pt.x = p.x;
	pt.y = p.y;
	return ((WinListView*)pListView)->IsOnStateIcon(pt,subItem);
}

//����һ�����Ƿ���Item��ǩ�ı�֮�ϣ���������ͬIsOnIcon()˵��
OFL_API void* _stdcall OListView_IsOnLabel(void* pListView,const POINT& p,/*Out*/int* subItem)
{
	Point pt;
	pt.x = p.x;
	pt.y = p.y;
	return ((WinListView*)pListView)->IsOnLabel(pt,subItem);
}

//׷��һ�����飬����ֵָ�����¼ӵ��飬�û��Ժ����ͨ���˷���ֵ�ٿ���ĸ�������(Vista)
OFL_API void* _stdcall OListView_AddGroup(void* pListView)
{
	return ((WinListView*)pListView)->AddGroup();
}

//��ȡ��ӦID����(Vista)
OFL_API void* _stdcall OListView_GetGroupById(void* pListView,int id)
{
	return ((WinListView*)pListView)->GetGroupById(id);
}

//ɾ��ָ�����飬����ֵָ�������Ƿ�ɹ�(Vista)
OFL_API bool _stdcall OListView_DeleteGroup(void* pListView,void* group)
{
	return ((WinListView*)pListView)->DeleteGroup((ListGroup*)group);
}

//ɾ�����е���(Vista)
OFL_API void _stdcall OListView_DeleteAllGroups(void* pListView)
{
	((WinListView*)pListView)->DeleteAllGroups();
}


OFL_API void _stdcall OListView_DestroyControl(void* pListView)
{
	((WinListView*)pListView)->DestroyControl();
}

OFL_API char* _stdcall OListView_GetClass(void* pListView)
{
	return (char*)((WinListView*)pListView)->GetClass();
}

OFL_API void _stdcall OListView_SetCaption(void* pListView,char* string)
{
	((WinListView*)pListView)->SetCaption(string);
}

OFL_API char* _stdcall OListView_GetCaption(void* pListView)
{
	return (char*)((WinListView*)pListView)->GetCaption();
}

OFL_API void _stdcall OListView_RedrawControl(void* pListView,bool redraw)
{
	((WinListView*)pListView)->RedrawControl(redraw);
}
