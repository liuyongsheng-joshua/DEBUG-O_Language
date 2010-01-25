
#ifndef _OWI_LISTBOX_H_
#define _OWI_LISTBOX_H_

#include "../../ExportDefine.h"
#include <Windows.h>

OFL_API void _stdcall ListBox_SetSelect(void* pListBox,int index);
OFL_API int _stdcall ListBox_GetSelect(void* pListBox);
OFL_API bool _stdcall ListBox_IsSelected(void* pListBox,int index);
OFL_API int _stdcall ListBox_GetSelectCount(void* pListBox);
OFL_API char* _stdcall ListBox_GetItemText(void* pListBox,int index);  
OFL_API int _stdcall ListBox_GetItemCount(void* pListBox); 
OFL_API void _stdcall ListBox_SetTextColor(void* pListBox,unsigned int color);
OFL_API unsigned int _stdcall ListBox_GetTextColor(void* pListBox);
OFL_API void _stdcall ListBox_SetAnchorItem(void* pListBox,int index);
OFL_API int _stdcall ListBox_GetAnchorItem(void* pListBox);
OFL_API void _stdcall ListBox_SetCaretItem(void* pListBox,int index);
OFL_API int _stdcall ListBox_GetCaretItem(void* pListBox);
OFL_API void _stdcall ListBox_SetScrollWidth(void* pListBox,int width);
OFL_API int _stdcall ListBox_GetScrollWidth(void* pListBox);
OFL_API void _stdcall ListBox_SetTopIndex(void* pListBox,int index);
OFL_API int _stdcall ListBox_GetTopIndex(void* pListBox);
OFL_API void _stdcall ListBox_SetColumnWidth(void* pListBox,int width);	 
OFL_API void _stdcall ListBox_SetItemHeight(void* pListBox,int index, int height);
OFL_API int _stdcall ListBox_GetItemHeight(void* pListBox,int index);
OFL_API void _stdcall ListBox_GetItemRect(void* pListBox,int index,RECT& rc);
OFL_API void _stdcall ListBox_SetItemData(void* pListBox,int index,void* pData);
OFL_API void _stdcall ListBox_SetLocale(void* pListBox,DWORD locale);  
OFL_API void* _stdcall ListBox_GetItemData(void* pListBox,int index);
OFL_API DWORD _stdcall ListBox_GetLocale(void* pListBox); 

//��ָ����Item����֮ǰ����һ���µ�Item������ؼ����������ܣ����¼��һ����ָ��λ�ò��룬
//ϵͳ���������
OFL_API int _stdcall ListBox_InsertItem(void* pListBox,char* string,int index);
//��β��׷��һ���µ�Item�����������¼���������������������򷵻�-1�����ؼ���������Item
//��һ��׷�ӵ�β��
OFL_API int _stdcall ListBox_AddItem(void* pListBox,char* string);
//ɾ��ָ����Item
OFL_API void _stdcall ListBox_DeleteItem(void* pListBox,int index);
//ɾ�����е�Item
OFL_API void _stdcall ListBox_DeleteAllItems(void* pListBox);
//�ҵ��ı���string��ʼ�ĵ�һ��Item����������������Ϊindex��item��ʼ���ԣ�ֱ��β�������Ҳ���ƥ���
//��Ӷ�����ʼ����������ֱ������Ϊindex֮ǰItem��Ĭ��-1��ʾ�ӵ�һ��Item��ʼ����������ʧ�ܣ�����-1
OFL_API int _stdcall ListBox_FindItem(void* pListBox,char* string, int index = -1);
//�ҵ��ı�����Ϊstring�ĵ�һ��Item��ע�������������Ǵ�Сд���еġ�index�ĺ����Լ�����ֵ�ĺ���ɲο�
//FindItem()��ע��˵��
OFL_API int _stdcall ListBox_FindItemExact(void* pListBox,char* string, int index = -1);
//���ڵ�ѡ����ListBox��ѡ���ı���string��ʼ�ĵ�һ��Item��index�ĺ�����ο�FindItem()��ע��˵������
//��ֵ˵���˱�ѡ�е�Item������ֵΪ-1����û���ҵ�ƥ�������ҵ�����Чƥ�䣬�ؼ����������ʹ֮�ɼ���ƥ
//������Ǵ�Сд�޹صġ�
OFL_API int _stdcall ListBox_SelectString(void* pListBox,char* string, int index = -1);
//���ڶ�ѡ����ListBox����selectΪtrue��ѡ������Ϊindex��Item����selectΪfalse�����Item��ȡ��ѡ��
OFL_API void _stdcall ListBox_SelectSingle(void* pListBox,int index, bool select);
//���ڶ�ѡ����ListBox����selectΪtrue��ѡ������Item����selectΪfalse������Item��ȡ��ѡ��
OFL_API void _stdcall ListBox_SelectAll(void* pListBox,bool select); 
//���ڶ�ѡ����ListBox���˺���������и���ѡ���item��������buffer�����У�numberָ�������Ԫ����Ŀ
//��������ʵ����䵽�����е�Ԫ����Ŀ		 
OFL_API int _stdcall ListBox_GetSelectArray(void* pListBox,int number,int* buffer);	
//���ڶ�ѡ����ListBox��ѡ��һ��������Χ��first��last��Item������ֵָ�������Ƿ�ɹ�
OFL_API bool _stdcall ListBox_SelectRange(void* pListBox,int first,int last);
//���ڶ�ѡ����ListBox��ȡ����ѡ�е�һ�鷶Χ��first��last��Item������ֵָ�������Ƿ�ɹ�
OFL_API bool _stdcall ListBox_CancelRange(void* pListBox,int first,int last);		
//��ȡ������(x,y)�����Item�����������ListBox�Ŀͻ���ԭ��
OFL_API int _stdcall ListBox_GetNearestItem(void* pListBox,int x,int y);
//��ȡ����(x,y)֮�µ�Item�����������ListBox�Ŀͻ���ԭ��
OFL_API int _stdcall ListBox_GetItemFromPoint(void* pListBox,int x,int y);  

OFL_API void _stdcall ListBox_DestroyControl(void* pListBox);	 
OFL_API char* _stdcall ListBox_GetClass(void* pListBox);
OFL_API char* _stdcall ListBox_GetCaption(void* pListBox);
OFL_API void _stdcall ListBox_SetCaption(void* pListBox,char* string);

#endif //_OWI_LISTBOX_H_