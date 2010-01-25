
#ifndef _OWI_COMBOBOX_H_
#define _OWI_COMBOBOX_H_

#include "../../ExportDefine.h"
#include <Windows.h>

OFL_API int _stdcall ComboBox_GetCount(void* pComboBox);
OFL_API int _stdcall ComboBox_GetItemHeight(void* pComboBox,int index); 
OFL_API void _stdcall ComboBox_SetItemHeight(void* pComboBox,int index, int height);	
OFL_API void _stdcall ComboBox_SetSelect(void* pComboBox,int index);
OFL_API int _stdcall ComboBox_GetSelect(void* pComboBox);   
OFL_API void _stdcall ComboBox_SetSelectStart(void* pComboBox,int start);  
OFL_API int _stdcall ComboBox_GetSelectStart(void* pComboBox);   
OFL_API void _stdcall ComboBox_SetSelectEnd(void* pComboBox,int end);  
OFL_API int _stdcall ComboBox_GetSelectEnd(void* pComboBox);	
OFL_API void _stdcall ComboBox_SetTopIndex(void* pComboBox,int index);
OFL_API int _stdcall ComboBox_GetTopIndex(void* pComboBox);
OFL_API void _stdcall ComboBox_SetTextLimit(void* pComboBox,int length);
OFL_API int _stdcall ComboBox_GetItemTextLength(void* pComboBox,int index);	 	   
OFL_API void _stdcall ComboBox_ShowDropdownList(void* pComboBox,bool show);
OFL_API bool _stdcall ComboBox_IsDropdownListVisible(void* pComboBox);	 
OFL_API int _stdcall ComboBox_GetDropdownListWidth(void* pComboBox);
OFL_API void _stdcall ComboBox_SetDropdownListWidth(void* pComboBox,int width); 
OFL_API void _stdcall ComboBox_GetDropdownListRect(void* pComboBox,RECT& rc);
OFL_API void _stdcall ComboBox_SetScrollWidth(void* pComboBox,int width);
OFL_API int _stdcall ComboBox_GetScrollWidth(void* pComboBox);
OFL_API void _stdcall ComboBox_SetExtendedUI(void* pComboBox,bool eui);
OFL_API bool _stdcall ComboBox_GetExtendedUI(void* pComboBox);
OFL_API void _stdcall ComboBox_SetLocale(void* pComboBox,DWORD locale);
OFL_API void _stdcall ComboBox_SetItemData(void* pComboBox,int index,void* data);
OFL_API void* _stdcall ComboBox_GetItemData(void* pComboBox,int index);  
OFL_API DWORD _stdcall ComboBox_GetLocale(void* pComboBox);

//��ComboBox�б���ָ����λ�ò���һ��Item
OFL_API int _stdcall ComboBox_InsertItem(void* pComboBox,char* string,int index);
//��ComboBox�б��β��׷��һ��Item
OFL_API int _stdcall ComboBox_AddItem(void* pComboBox,char* string);
//ɾ��ָ����Item
OFL_API bool _stdcall ComboBox_DeleteItem(void* pComboBox,int index);
//ɾ������Item
OFL_API void _stdcall ComboBox_DeleteAllItems(void* pComboBox);
//��ȡָ��Item���ı�
OFL_API char* _stdcall ComboBox_GetItemText(void* pComboBox,int index);
//���ĳһ��ӵ�һ���ַ���ʼƥ��string(ע�⣺��Сд������)������������������
OFL_API int _stdcall ComboBox_FindItem(void* pComboBox,char* string);	   
//���ĳһ����ȫ��ͬ��string(ע�⣺��Сд������)����������һ������������򷵻�-1
OFL_API int _stdcall ComboBox_FindItemExact(void* pComboBox,char* string);
//ѡ����ʼ�ı�Ϊstring��Item�����ر�ѡ��Item�����������޷����ƥ�䣬�򷵻�-1
OFL_API int _stdcall ComboBox_SelectString(void* pComboBox,char* string);
//���ڷ��ΪSimpleStyle��TextStyle��ComboBox��������༭�ؼ����ı���ѡ��Χ��
//��startΪ-1���������ѡ���ı��ĸ���ѡ��״̬����endΪ-1����༭�ؼ��������ı����ᱻѡ�С�
OFL_API void _stdcall ComboBox_SetEditSelect(void* pComboBox,int start, int end); 

OFL_API void _stdcall ComboBox_DestroyControl(void* pComboBox);
OFL_API char* _stdcall ComboBox_GetClass(void* pComboBox);
OFL_API void _stdcall ComboBox_SetCaption(void* pComboBox,char* string);
OFL_API char* _stdcall ComboBox_GetCaption(void* pComboBox); 


#endif //_OWI_COMBOBOX_H_