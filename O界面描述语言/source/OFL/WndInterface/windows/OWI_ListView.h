
#ifndef _OWI_LISTVIEW_H_
#define _OWI_LISTVIEW_H_

#include "../../ExportDefine.h"
#include <Windows.h>

//////////////////////////////////////////////////////////////////////////
//ListItem
OFL_API int _stdcall ListItem_GetIndex(void* pListItem);
OFL_API void _stdcall ListItem_SetText(void* pListItem,int subindex,char* string);
OFL_API char* _stdcall ListItem_GetText(void* pListItem,int subindex);
OFL_API void _stdcall ListItem_SetImage(void* pListItem,int subindex,int image);
OFL_API int _stdcall ListItem_GetImage(void* pListItem,int subindex);
OFL_API void _stdcall ListItem_SetStateImage(void* pListItem,int subindex,int image);
OFL_API int _stdcall ListItem_GetStateImage(void* pListItem,int subindex);
OFL_API void _stdcall ListItem_SetOverlayImage(void* pListItem,int subindex,int image);
OFL_API int _stdcall ListItem_GetOverlayImage(void* pListItem,int subindex);   
OFL_API void _stdcall ListItem_SetGroup(void* pListItem,void* pListGroup);
OFL_API void _stdcall ListItem_SetIndent(void* pListItem,int indent);
OFL_API int _stdcall ListItem_GetIndent(void* pListItem);
OFL_API void _stdcall ListItem_SetChecked(void* pListItem,bool check);
OFL_API bool _stdcall ListItem_GetChecked(void* pListItem);
OFL_API void _stdcall ListItem_SetSelected(void* pListItem,bool select);
OFL_API bool _stdcall ListItem_IsSelected(void* pListItem);
OFL_API void _stdcall ListItem_SetCut(void* pListItem,bool cut);
OFL_API bool _stdcall ListItem_IsCut(void* pListItem); 
OFL_API void _stdcall ListItem_SetFocused(void* pListItem,bool focus);
OFL_API bool _stdcall ListItem_GetFocused(void* pListItem);
OFL_API void _stdcall ListItem_SetDropHilited(void* pListItem,bool hilite);
OFL_API bool _stdcall ListItem_GetDropHilited(void* pListItem);
OFL_API void _stdcall ListItem_SetTextColor(void* pListItem,int subindex,unsigned int color);
OFL_API unsigned int _stdcall ListItem_GetTextColor(void* pListItem,int subindex);
OFL_API void _stdcall ListItem_SetTextBackColor(void* pListItem,int subindex,unsigned int color);
OFL_API unsigned int _stdcall ListItem_GetTextBackColor(void* pListItem,int color);
OFL_API void _stdcall ListItem_GetRect(void* pListItem,RECT& rc);
OFL_API void _stdcall ListItem_GetSubRect(void* pListItem,int subIndex,RECT& rc);
OFL_API void _stdcall ListItem_SetData(void* pListItem,void* data);
OFL_API void* _stdcall ListItem_GetData(void* pListItem);
OFL_API void _stdcall ListItem_SetPosition(void* pListItem,const POINT& p);
OFL_API void _stdcall ListItem_GetPosition(void* pListItem,POINT& p);
OFL_API void* _stdcall ListItem_GetGroup(void* pListItem);
OFL_API void* _stdcall ListItem_GetOwner(void* pListItem);

//////////////////////////////////////////////////////////////////////////
//ListColumn
OFL_API int _stdcall ListColumn_GetIndex(void* pListColumn);
OFL_API void _stdcall ListColumn_SetText(void* pListColumn,char* name);
OFL_API char* _stdcall ListColumn_GetText(void* pListColumn);
OFL_API void _stdcall ListColumn_SetFormat(void* pListColumn,int format);
OFL_API int _stdcall ListColumn_GetFormat(void* pListColumn);
OFL_API void _stdcall ListColumn_SetWidth(void* pListColumn,int width);
OFL_API int _stdcall ListColumn_GetWidth(void* pListColumn);
OFL_API void _stdcall ListColumn_SetImage(void* pListColumn,int image);
OFL_API int _stdcall ListColumn_GetImage(void* pListColumn);
OFL_API void _stdcall ListColumn_SetOrder(void* pListColumn,int order);
OFL_API int _stdcall ListColumn_GetOrder(void* pListColumn);   
OFL_API void* _stdcall ListColumn_GetOwner(void* pListColumn);

//////////////////////////////////////////////////////////////////////////
//ListGroup
OFL_API int _stdcall ListGroup_GetId(void* pListGroup);
OFL_API void _stdcall ListGroup_SetFormat(void* pListGroup,unsigned int format);
OFL_API unsigned int _stdcall ListGroup_GetFormat(void* pListGroup);
OFL_API void _stdcall ListGroup_SetPosition(void* pListGroup,int pos);
OFL_API void _stdcall ListGroup_SetHeader(void* pListGroup,wchar_t* name);
OFL_API void _stdcall ListGroup_SetFooter(void* pListGroup,wchar_t* name);	
OFL_API wchar_t* _stdcall ListGroup_GetHeader(void* pListGroup);	  
OFL_API wchar_t* _stdcall ListGroup_GetFooter(void* pListGroup);
OFL_API void* _stdcall ListGroup_GetOwner(void* pListGroup);

//////////////////////////////////////////////////////////////////////////
//ListView

OFL_API void _stdcall OListView_SetToolTip(void* pListView,HWND hToolTip);
OFL_API int _stdcall OListView_GetColumnCount(void* pListView);
OFL_API int _stdcall OListView_GetItemCount(void* pListView);
OFL_API int _stdcall OListView_GetSelectedItemCount(void* pListView);
OFL_API void _stdcall OListView_SetTextColor(void* pListView,unsigned int color);
OFL_API unsigned int _stdcall OListView_GetTextColor(void* pListView);	
OFL_API void _stdcall OListView_SetTextBackColor(void* pListView,unsigned int color);
OFL_API unsigned int _stdcall OListView_GetTextBackColor(void* pListView);
OFL_API void _stdcall OListView_SetWorkAreaCount(void* pListView,int count);
OFL_API int _stdcall OListView_GetWorkAreaCount(void* pListView); 
OFL_API int _stdcall OListView_GetTopIndex(void* pListView);
OFL_API void _stdcall OListView_SetHoverTime(void* pListView,unsigned int time);
OFL_API unsigned int _stdcall OListView_GetHoverTime(void* pListView);
OFL_API void _stdcall OListView_SetSelectionMark(void* pListView,int mark);
OFL_API int _stdcall OListView_GetSelectionMark(void* pListView);
OFL_API void _stdcall OListView_SetHotItem(void* pListView,int item);
OFL_API int _stdcall OListView_GetHotItem(void* pListView);
OFL_API int _stdcall OListView_GetCountPerPage(void* pListView);
OFL_API void _stdcall OListView_SetGroupEnabled(void* pListView,bool enable); 
OFL_API bool _stdcall OListView_IsGroupEnabled(void* pListView);
OFL_API int _stdcall OListView_GetGroupCount(void* pListView);
OFL_API void _stdcall OListView_SetInsertMark(void* pListView,int mark);
OFL_API int _stdcall OListView_GetInsertMark(void* pListView);
OFL_API void _stdcall OListView_SetInsertMarkColor(void* pListView,unsigned int color);
OFL_API unsigned int _stdcall OListView_GetInsertMarkColor(void* pListView);	
OFL_API void _stdcall OListView_SetOutlineColor(void* pListView,unsigned int color);
OFL_API unsigned int _stdcall OListView_GetOutlineColor(void* pListView);
OFL_API void _stdcall OListView_SetSelectedColumn(void* pListView,unsigned int column);
OFL_API unsigned int _stdcall OListView_GetSelectedColumn(void* pListView); 
OFL_API void _stdcall OListView_SetWorkArea(void* pListView,int index,const RECT& rc);
OFL_API void _stdcall OListView_SetHotCursor(void* pListView,HCURSOR hCursor);
OFL_API void _stdcall OListView_SetViewMode(void* pListView,int mode);
OFL_API void _stdcall OListView_GetWorkArea(void* pListView,int index,RECT& rc);	
OFL_API void _stdcall OListView_GetViewRect(void* pListView,RECT& rc);
OFL_API void _stdcall OListView_GetInsertMarkRect(void* pListView,RECT& rc);   
OFL_API HWND _stdcall OListView_GetToolTip(void* pListView);
OFL_API HWND _stdcall OListView_GetHeader(void* pListView);  
OFL_API HWND _stdcall OListView_GetEditControl(void* pListView);	
OFL_API void _stdcall OListView_GetOrigin(void* pListView,POINT& p);	 
OFL_API HCURSOR _stdcall OListView_GetHotCursor(void* pListView);	
OFL_API void* _stdcall OListView_GetItem(void* pListView,int index);  
OFL_API void* _stdcall OListView_GetGroup(void* pListView,int index);	 
OFL_API void* _stdcall OListView_GetColumn(void* pListView,int index); 
OFL_API int _stdcall OListView_GetViewMode(void* pListView);	

//׷��һ�У�Ĭ�ϸ�ʽΪ����룬�п�Ϊ50�����أ������ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_AddColumn(void* pListView);
//׷��һ�У�Ĭ�ϸ�ʽΪ����룬widthΪ�п�textΪ���ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_AddColumnText(void* pListView,int width,char* text);
//׷��һ�У�formatΪ������ʽ��widthΪ�п�textΪ���ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_AddColumnFormat(void* pListView,int format,int width,char* text);
//������indexǰ����һ�У�Ĭ������룬�п�50�����أ������ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_InsertColumn(void* pListView,int index);
//������indexǰ����һ�У�Ĭ�������������������ָ���п�����ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_InsertColumnText(void* pListView,int index,int width,char* text);
//������indexǰ����һ�У�formatΪ�����ʽ��widthΪ�п�textΪ���ı��������ɹ�����һ���нṹ�����򷵻�NULL
OFL_API void* _stdcall OListView_InsertColumnFormat(void* pListView,int index,int format,int width,char* text);
//ɾ������Ϊindex����(ע�⣺��һ�в���ɾ�������뱣��)������ֵ����ɾ�������Ƿ�ɹ�
OFL_API bool _stdcall OListView_DeleteColumn(void* pListView,int index); 
//ɾ��������
OFL_API void _stdcall OListView_DeleteAllColumns(void* pListView);
//����ImageList��ListView�������ð���3��ImageList���ֱ�Ϊ��ͼ��ģʽ����ʹ�õ�ImageList��Сͼ��ģʽ
//����ʹ�õ�ImageList��������ʾ״̬��ImageList��
OFL_API void _stdcall OListView_SetImageList(void* pListView,int type,void* imagelist);
//��ȡ��Ӧ��ImageList
OFL_API void* _stdcall OListView_GetImageList(void* pListView,int type);
//׷��һ���µ�Item�������¼ӵ�ListItem������ؼ�����ĳ����������˺�����һ�����ڿؼ�β��ִ��׷�ӣ����ܿ�����ĳ��λ��
//ִ�в������������ֵ�ĺ�����ο������InsertItem()ע�͡�
OFL_API void* _stdcall OListView_AddItem(void* pListView);
//�ڵ�index������ǰ����һ���µ�Item��ע�⣺����ֵListItem�ĳ�ԱmIndexֻ����ʱ���塣����Ժ��û��ڴ�ListItem֮ǰ��ӻ�
//ɾ��������ListItem�����ListItem��mIndex��ʧЧ���û�Ӧ����������UpdateItemIndexˢ����mIndexֵ������ؼ���������
//����������һ��������ָ��Item֮ǰ��
OFL_API void* _stdcall OListView_InsertItem(void* pListView,int index);
//ɾ��ָ����Item
OFL_API bool _stdcall OListView_DeleteItem(void* pListView,void* item);
//ɾ��ָ��������Item
OFL_API bool _stdcall OListView_DeleteItemIndex(void* pListView,int index);
//ɾ�����е�Item
OFL_API void _stdcall OListView_DeleteAllItems(void* pListView);
//��ȡItem�ڿؼ��е�����
OFL_API int _stdcall OListView_GetItemIndex(void* pListView,void* item);
//�������ı�ƥ��text��Item��exactָ���ı��Ƿ�Ҫ��ȷƥ�䣺true��Ҫ���ı���ȫ��ͬ��falseֻҪ��Item�ı���text��ʼ������������
//��Сд���еġ��ҵ�����Ҫ���Item�򷵻���ָ�룬���򷵻�NULL
OFL_API void* _stdcall OListView_FindItem(void* pListView,char* text, bool exact);
//�ڴ�ͼ���Сͼ��ģʽ����direction�����ҵ���p��(��Կؼ��ͻ���ԭ��)�����Item�������ΪVK_LEFT��VK_RIGHT��VK_UP��VK_DOWN
OFL_API void* _stdcall OListView_FindNearestItem(void* pListView,const POINT& p,unsigned int direction);
//��ʼ�༭ָ����Item���ؼ�������пɱ༭���(ListViewDesc::mCanEdit������Ϊtrue)����ʱ�ᴴ��һ��Edit�ؼ���
//���ı�ΪItem���ı�������ȫ������ѡ�С�����ֵָ���Ƿ�ȷʵ��ʾ��Edit�ؼ���
OFL_API bool _stdcall OListView_BeginEdit(void* pListView,int index);
//���ĳ��Item�����ڱ༭״̬���˺�����ȡ����༭״̬���༭�ؼ��Զ����ز�����(XP)
OFL_API void _stdcall OListView_CancelEdit(void* pListView);
//�ڴ�ͼ��ģʽ�����°������е�Item��ȷ�����룬����alignָ�����뷽ʽ(��ο�ö������ListItemAlign{})
OFL_API void _stdcall OListView_Arrange(void* pListView,int align);
//ȷ��ָ����Item���ӣ��������ӣ������ListViewʹ֮����
OFL_API void _stdcall OListView_EnsureVisible(void* pListView,int index);
//�����ͻ����е����ݣ��������ֱ�ָ��ˮƽ�ʹ�ֱ������������(���ؼ�ģʽΪReport��ֻ�ܴ�ֱ��������dy���Զ������������)
OFL_API void _stdcall OListView_Scroll(void* pListView,int dx, int dy);
//������Iconģʽ��ͼ��֮��ļ����ע��cx��cy�������ͼ��Ŀ�ߣ���Ȼ�ᵼ��ͼ����ص���������Ϊ-1����ָ�Ĭ��ֵ
OFL_API void _stdcall OListView_SetIconSpacing(void* pListView,int cx,int cy);
//��ȡItem֮��ļ�࣬����Ϊtrueָ����Сͼ��ģʽ�µ�Item��࣬�������ͼ��ģʽ�µ�Item���
OFL_API unsigned int _stdcall OListView_GetItemSpacing(void* pListView,bool smallIcon);
//�����ڿؼ���ǰ�������ı������ؿ��
OFL_API int _stdcall OListView_GetStringWidth(void* pListView,char* text);
//����ָ������֮�µ�Item(p�����ؼ��ͻ���ԭ��)
OFL_API void* _stdcall OListView_IsOnItem(void* pListView,const POINT& p);
//����һ�����Ƿ���Itemͼ��֮�ϣ�p����Կؼ��ͻ���ԭ������꣬����Item(�����겻��һ��Item���򷵻�NULL)
OFL_API void* _stdcall OListView_IsOnIcon(void* pListView,const POINT& p,/*Out*/int* subItem = NULL);   
//����һ�����Ƿ���Item״̬ͼ��֮�ϣ���������ͬIsOnIcon()˵��
OFL_API void* _stdcall OListView_IsOnStateIcon(void* pListView,const POINT& p,/*Out*/int* subItem = NULL); 
//����һ�����Ƿ���Item��ǩ�ı�֮�ϣ���������ͬIsOnIcon()˵��
OFL_API void* _stdcall OListView_IsOnLabel(void* pListView,const POINT& p,/*Out*/int* subItem = NULL);  
//׷��һ�����飬����ֵָ�����¼ӵ��飬�û��Ժ����ͨ���˷���ֵ�ٿ���ĸ�������(Vista)
OFL_API void* _stdcall OListView_AddGroup(void* pListView);
//��ȡ��ӦID����(Vista)
OFL_API void* _stdcall OListView_GetGroupById(void* pListView,int id);
//ɾ��ָ�����飬����ֵָ�������Ƿ�ɹ�(Vista)
OFL_API bool _stdcall OListView_DeleteGroup(void* pListView,void* group);
//ɾ�����е���(Vista)
OFL_API void _stdcall OListView_DeleteAllGroups(void* pListView);	

OFL_API void _stdcall OListView_DestroyControl(void* pListView);
OFL_API char* _stdcall OListView_GetClass(void* pListView);
OFL_API void _stdcall OListView_SetCaption(void* pListView,char* string);
OFL_API char* _stdcall OListView_GetCaption(void* pListView);
OFL_API void _stdcall OListView_RedrawControl(void* pListView,bool redraw);

#endif //_OWI_LISTVIEW_H_