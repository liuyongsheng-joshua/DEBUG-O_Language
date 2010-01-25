
#ifndef _OWI_TREEVIEW_H_
#define _OWI_TREEVIEW_H_

#include "../../ExportDefine.h"
#include <Windows.h>
#include <CommCtrl.h>


//////////////////////////////////////////////////////////////////////////
//TreeItem
OFL_API char* _stdcall TreeItem_GetText(void* pTreeItem);			
OFL_API void _stdcall TreeItem_SetText(void* pTreeItem,char* string);
OFL_API bool _stdcall TreeItem_IsExpanded(void* pTreeItem);
OFL_API void _stdcall TreeItem_Expand(void* pTreeItem,bool expand);   
OFL_API bool _stdcall TreeItem_GetChecked(void* pTreeItem);
OFL_API void _stdcall TreeItem_SetChecked(void* pTreeItem,bool check); 
OFL_API bool _stdcall TreeItem_IsSelected(void* pTreeItem);
OFL_API void _stdcall TreeItem_SetSelected(void* pTreeItem,bool select);   
OFL_API bool _stdcall TreeItem_HasButton(void* pTreeItem);
OFL_API void _stdcall TreeItem_ShowButton(void* pTreeItem,bool showbtn);
OFL_API bool _stdcall TreeItem_IsCut(void* pTreeItem);
OFL_API void _stdcall TreeItem_SetCut(void* pTreeItem,bool cut);   
OFL_API bool _stdcall TreeItem_IsBold(void* pTreeItem);    
OFL_API void _stdcall TreeItem_SetBold(void* pTreeItem,bool blod);
OFL_API void _stdcall TreeItem_SetDropHilited(void* pTreeItem,bool hilit);
OFL_API bool _stdcall TreeItem_GetDropHilited(void* pTreeItem);
OFL_API unsigned int _stdcall TreeItem_GetTextColor(void* pTreeItem);
OFL_API void _stdcall TreeItem_SetTextColor(void* pTreeItem,unsigned int color);	  
OFL_API unsigned int _stdcall TreeItem_GetTextBackColor(void* pTreeItem); 
OFL_API void _stdcall TreeItem_SetTextBackColor(void* pTreeItem,unsigned int color);   
OFL_API int _stdcall TreeItem_GetImage(void* pTreeItem);
OFL_API void _stdcall TreeItem_SetImage(void* pTreeItem,int image);		 
OFL_API int _stdcall TreeItem_GetSelectedImage(void* pTreeItem);
OFL_API void _stdcall TreeItem_SetSelectedImage(void* pTreeItem,int image);
OFL_API int _stdcall TreeItem_GetStateImage(void* pTreeItem);
OFL_API void _stdcall TreeItem_SetStateImage(void* pTreeItem,int image);	 
OFL_API int _stdcall TreeItem_GetOverlayImage(void* pTreeItem);	
OFL_API void _stdcall TreeItem_SetOverlayImage(void* pTreeItem,int image);
OFL_API void _stdcall TreeItem_SetData(void* pTreeItem,void* data);
OFL_API void _stdcall TreeItem_GetRect(void* pTreeItem,RECT& rc);
OFL_API void* _stdcall TreeItem_GetData(void* pTreeItem);
OFL_API void* _stdcall TreeItem_GetParentItem(void* pTreeItem);   
OFL_API void* _stdcall TreeItem_GetPrevItem(void* pTreeItem);
OFL_API void* _stdcall TreeItem_GetNextItem(void* pTreeItem);
OFL_API void* _stdcall TreeItem_GetFirstChildItem(void* pTreeItem);
OFL_API HTREEITEM _stdcall TreeItem_GetHandle(void* pTreeItem);

//////////////////////////////////////////////////////////////////////////
//TreeView
OFL_API void _stdcall OTreeView_SetTextColor(void* pTreeView,unsigned int color);
OFL_API unsigned int _stdcall OTreeView_GetTextColor(void* pTreeView);
OFL_API void _stdcall OTreeView_SetLineColor(void* pTreeView,unsigned int color);
OFL_API unsigned int _stdcall OTreeView_GetLineColor(void* pTreeView);
OFL_API void _stdcall OTreeView_SetItemIndent(void* pTreeView,int indent);
OFL_API int _stdcall OTreeView_GetItemIndent(void* pTreeView);
OFL_API void _stdcall OTreeView_SetItemHeight(void* pTreeView,int height);
OFL_API int _stdcall OTreeView_GetItemHeight(void* pTreeView);
OFL_API void _stdcall OTreeView_SetToolTip(void* pTreeView,HWND tip);
OFL_API HWND _stdcall OTreeView_GetToolTip(void* pTreeView);
OFL_API HWND _stdcall OTreeView_GetEditControl(void* pTreeView);
OFL_API void* _stdcall OTreeView_GetTopItem(void* pTreeView);	 
OFL_API void* _stdcall OTreeView_GetRootItem(void* pTreeView); 
OFL_API void* _stdcall OTreeView_GetSelectedItem(void* pTreeView); 

//����ImageList���ɷ�Ϊ��ʾ״̬ͼ���õ�ImageList����ʾ����ͼ���õ�ImageList����
OFL_API void _stdcall OTreeView_SetImageList(void* pTreeView,int type,void* imageList);
//��ȡָ�����͵�ImageList
OFL_API void* _stdcall OTreeView_GetImageList(void* pTreeView,int type);	
//��ָ�����ֵ�Item֮�����һ���µ�Item��after��ΪNULL�����һ����Item������������һ����Item
OFL_API void* _stdcall OTreeView_InsertSibling(void* pTreeView,void* after);
//��ָ���ĸ�Item֮��׷��һ���µ���Item��parent��������ΪNULL
OFL_API void* _stdcall OTreeView_InsertChild(void* pTreeView,void* parent);
//ɾ��ָ����Item
OFL_API void _stdcall OTreeView_DeleteItem(void* pTreeView,void* item);
//ɾ�����е�Item
OFL_API void _stdcall OTreeView_DeleteAllItems(void* pTreeView); 
//��ȡָ�������Item
OFL_API void* _stdcall OTreeView_GetItem(void* pTreeView,HTREEITEM item);   
//��������ڿؼ��ͻ���ԭ�������x,y����������֮�µ�Item
OFL_API void* _stdcall OTreeView_TestPoint(void* pTreeView,int x,int y);
//ȷ��ָ����Item���ӣ������������Զ���������ʹ֮����
OFL_API void _stdcall OTreeView_EnsureVisible(void* pTreeView,void* item);
//��ʼ�༭ĳ��Item������ֵ˵���Ƿ�ȷʵ�����˱༭ģʽ(Ҫ��ؼ���TreeViewDesc::mCanEdit���)
OFL_API bool _stdcall OTreeView_BeginEdit(void* pTreeView,void* item);
//�����༭ģʽ���û���������Ч
OFL_API void _stdcall OTreeView_EndEdit(void* pTreeView);
//ȡ���༭ģʽ���û������뱻������Item���ı�����
OFL_API void _stdcall OTreeView_CancelEdit(void* pTreeView);

OFL_API void _stdcall OTreeView_DestroyControl(void* pTreeView);
OFL_API char* _stdcall OTreeView_GetClass(void* pTreeView);
OFL_API void _stdcall OTreeView_SetCaption(void* pTreeView,char* string);
OFL_API char* _stdcall OTreeView_GetCaption(void* pTreeView);
OFL_API void _stdcall OTreeView_Move(void* pTreeView,int dx,int dy);
OFL_API void _stdcall OTreeView_SetSize(void* pTreeView,int width,int height);
OFL_API void _stdcall OTreeView_SetPositionSize(void* pTreeView,int letf,int top,int width,int height);

#endif //_OWI_TREEVIEW_H_