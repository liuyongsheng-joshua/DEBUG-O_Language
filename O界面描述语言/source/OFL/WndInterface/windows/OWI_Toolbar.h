
#ifndef _OWI_TOOLBAR_H_
#define _OWI_TOOLBAR_H_

#include "../../ExportDefine.h"
#include <Windows.h>


//////////////////////////////////////////////////////////////////////////
//ToolbarButton

OFL_API int _stdcall ToolbarButton_GetIndex(void* pToolbarButton);
OFL_API int _stdcall ToolbarButton_GetId(void* pToolbarButton);
OFL_API void _stdcall ToolbarButton_SetImage(void* pToolbarButton,int image);
OFL_API int _stdcall ToolbarButton_GetImage(void* pToolbarButton);
OFL_API void _stdcall ToolbarButton_SetText(void* pToolbarButton,char* text);
OFL_API char* _stdcall ToolbarButton_GetText(void* pToolbarButton);
OFL_API void _stdcall ToolbarButton_SetEnabled(void* pToolbarButton,bool enable);
OFL_API bool _stdcall ToolbarButton_GetEnabled(void* pToolbarButton);
OFL_API void _stdcall ToolbarButton_SetVisible(void* pToolbarButton,bool visible);
OFL_API bool _stdcall ToolbarButton_GetVisible(void* pToolbarButton);
OFL_API void _stdcall ToolbarButton_SetChecked(void* pToolbarButton,bool check);
OFL_API bool _stdcall ToolbarButton_GetChecked(void* pToolbarButton);
OFL_API void _stdcall ToolbarButton_SetPressed(void* pToolbarButton,bool press);
OFL_API bool _stdcall ToolbarButton_GetPressed(void* pToolbarButton);
OFL_API void _stdcall ToolbarButton_SetHilited(void* pToolbarButton,bool high);
OFL_API bool _stdcall ToolbarButton_GetHilited(void* pToolbarButton);
OFL_API void _stdcall ToolbarButton_SetTipText(void* pToolbarButton,char* text);	
OFL_API char* _stdcall ToolbarButton_GetTipText(void* pToolbarButton);
OFL_API void _stdcall ToolbarButton_SetMenu(void* pToolbarButton,void* menu); 
OFL_API void _stdcall ToolbarButton_SetData(void* pToolbarButton,void* data);
OFL_API void _stdcall ToolbarButton_GetRect(void* pToolbarButton,RECT& rc);
OFL_API void* _stdcall ToolbarButton_GetData(void* pToolbarButton); 
OFL_API void* _stdcall ToolbarButton_GetMenu(void* pToolbarButton);
OFL_API void* _stdcall ToolbarButton_GetOwner(void* pToolbarButton);

//////////////////////////////////////////////////////////////////////////
//Toolbar

OFL_API int _stdcall Toolbar_GetButtonCount(void* pToolbar);
OFL_API void _stdcall Toolbar_SetButtonSize(void* pToolbar,const SIZE& size);
OFL_API void _stdcall Toolbar_SetBitmapSize(void* pToolbar,const SIZE& size);
OFL_API void _stdcall Toolbar_SetHotItem(void* pToolbar,int index);
OFL_API int _stdcall Toolbar_GetHotItem(void* pToolbar);			 
OFL_API void _stdcall Toolbar_SetPadding(void* pToolbar,const SIZE& size);
OFL_API void _stdcall Toolbar_SetRowCount(void* pToolbar,int rows);
OFL_API int _stdcall Toolbar_GetRowCount(void* pToolbar);		  
OFL_API void _stdcall Toolbar_SetToolTip(void* pToolbar,HWND tips);
OFL_API void _stdcall Toolbar_SetIndent(void* pToolbar,int indent);
OFL_API void _stdcall Toolbar_GetButtonSize(void* pToolbar,SIZE& size);
OFL_API void _stdcall Toolbar_GetBitmapSize(void* pToolbar,SIZE& size);
OFL_API void _stdcall Toolbar_GetPadding(void* pToolbar,SIZE& size);
OFL_API HWND _stdcall Toolbar_GetToolTip(void* pToolbar);	
OFL_API void _stdcall Toolbar_SetImageList(void* pToolbar,void* imageList);	    
OFL_API void _stdcall Toolbar_SetHotImageList(void* pToolbar,void* imageList);   
OFL_API void _stdcall Toolbar_SetDisabledImageList(void* pToolbar,void* imageList);
OFL_API void* _stdcall Toolbar_GetImageList(void* pToolbar);
OFL_API void* _stdcall Toolbar_GetHotImageList(void* pToolbar);
OFL_API void* _stdcall Toolbar_GetDisabledImageList(void* pToolbar);  
OFL_API void* _stdcall Toolbar_GetButton(void* pToolbar,int index);	

//����4������Ϊ��ť���뺯����ע������밴ť��id�����뱾�������е�������ťid�ظ���Ҳ��Ҫ�������������а�ťid�ظ���
//��λ��index֮ǰ����һ����ͨ��ť���û�����ָ����ť��id��showTextָ���Ƿ���ʾ�ı������˲�������������ʾ��ͼƬ�·�
//�Ĺ�������Ч��
OFL_API void* _stdcall Toolbar_InsertButton(void* pToolbar,int index, int id, bool showText=true);//
//��λ��index֮ǰ����һ��Checkʽ��ť���û��������ְ�ť�������ְ���״̬���ٰ�һ�£��ָֻ�ԭ״��
//���group����Ϊtrue�������ڵ�Checkʽ��ť����һ�飬��״̬���⣬������ֻ��һ���ܱ���ѹ��״̬��
OFL_API void* _stdcall Toolbar_InsertCheck(void* pToolbar,bool group, int index, int id, bool showText=true);
//��λ��index֮ǰ����һ������ʽ��ť�����ְ�ť�Ҳ���һ��С��ͷ�����wholeΪfalse����ť������С��ͷ
//������һ�𣬷����Ƿֿ��ġ�
OFL_API void* _stdcall Toolbar_InsertDropdown(void* pToolbar,bool whole, int index, int id, bool showText=true);
//��λ��index֮ǰ����һ���ָť(���ַָťʵ������һ�ֱȽ�խ�Ļ��)
OFL_API void* _stdcall Toolbar_InsertSeperator(void* pToolbar,int index);		
//�ڹ�����β��׷��һ��Button��ť������������ο�InsertButton()��ע��
OFL_API void* _stdcall Toolbar_AddButton(void* pToolbar,int id, bool showText = true);
//�ڹ�����β��׷��һ��Check��ť������������ο�InsertCheck()��ע��
OFL_API void* _stdcall Toolbar_AddCheck(void* pToolbar,bool group, int id, bool showText=true);
//�ڹ�����β��׷��һ��Dropdown��ť������������ο�InsertDropdown()��ע��
OFL_API void* _stdcall Toolbar_AddDropdown(void* pToolbar,bool whole, int id, bool showText=true);
//�ڹ�����β��׷��һ��Seperator��ť
OFL_API void* _stdcall Toolbar_AddSeperator(void* pToolbar);
//ɾ��ָ�������İ�ť
OFL_API void _stdcall Toolbar_DeleteButton(void* pToolbar,int index);
//ɾ�����а�ť
OFL_API void _stdcall Toolbar_DeleteAllButtons(void* pToolbar);
//��һ����ť��iFromλ���ƶ���iToλ��
OFL_API void _stdcall Toolbar_MoveButton(void* pToolbar,int iFrom,int iTo);
//���µ����������ĳߴ�(ͨ�����û��ı��˰�ť��С��ťͼ���Сʱ��Ҫ���ô˺���)
OFL_API void _stdcall Toolbar_Resize(void* pToolbar);
//����һ������Ϊp(����ڹ��߿ͻ���ԭ��)�ĵ��Ƿ���һ����Separator�İ�ť֮��
OFL_API void* _stdcall Toolbar_IsOnButton(void* pToolbar,const POINT& p);
//�ҵ�ָ��id�İ�ť�����Ҳ���������NULL
OFL_API void* _stdcall Toolbar_FindButton(void* pToolbar,int id);

OFL_API void _stdcall Toolbar_DestroyControl(void* pToolbar);	   
OFL_API char* _stdcall Toolbar_GetClass(void* pToolbar);
OFL_API void _stdcall Toolbar_SetCaption(void* pToolbar,char* string);
OFL_API char* _stdcall Toolbar_GetCaption(void* pToolbar);

#endif //_OWI_TOOLBAR_H_