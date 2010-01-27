
#ifndef _OWI_EDIT_H_
#define _OWI_EDIT_H_

#include "../../ExportDefine.h"
#include <Windows.h>

OFL_API void _stdcall Edit_SetText(void* pEdit,char* string);
OFL_API char* _stdcall Edit_GetText(void* pEdit);
OFL_API void _stdcall Edit_SetTextColor(void* pEdit,unsigned int color);
OFL_API unsigned int _stdcall Edit_GetTextColor(void* pEdit);
OFL_API int _stdcall Edit_GetCharCount(void* pEdit);
OFL_API int _stdcall Edit_GetLineCount(void* pEdit);
OFL_API int _stdcall Edit_GetTopLine(void* pEdit);
OFL_API void _stdcall Edit_SetLimitText(void* pEdit,int limit);
OFL_API int _stdcall Edit_GetLimitText(void* pEdit);			
OFL_API void _stdcall Edit_SetLeftMargin(void* pEdit,int margin);
OFL_API int _stdcall Edit_GetLeftMargin(void* pEdit);
OFL_API void _stdcall Edit_SetRightMargin(void* pEdit,int margin);
OFL_API int _stdcall Edit_GetRightMargin(void* pEdit);
OFL_API void _stdcall Edit_SetModifyFlag(void* pEdit,bool modify);							  
OFL_API bool _stdcall Edit_GetModifyFlag(void* pEdit);	
OFL_API void _stdcall Edit_SetPassword(void* pEdit,char pw);
OFL_API char _stdcall Edit_GetPassword(void* pEdit);
OFL_API void _stdcall Edit_SetSelectStart(void* pEdit,int start); 
OFL_API int _stdcall Edit_GetSelectStart(void* pEdit);
OFL_API void _stdcall Edit_SetSelectEnd(void* pEdit,int end); 
OFL_API int _stdcall Edit_GetSelectEnd(void* pEdit);
OFL_API void _stdcall Edit_SetReadOnly(void* pEdit,bool readonly);
OFL_API bool _stdcall Edit_GetReadOnly(void* pEdit);	
OFL_API void _stdcall Edit_SetFormatRect(void* pEdit,const RECT& rc);
OFL_API void _stdcall Edit_GetFormatRect(void* pEdit,RECT& rc);

//���������������Ƿ���ڿ��Գ����Ķ���������ֵָ�������������Ƿ���ڿ��Գ����Ķ���
OFL_API bool _stdcall Edit_CanUndo(void* pEdit);
//������һ�β���
OFL_API bool _stdcall Edit_Undo(void* pEdit);
//��ճ�������(���û�����SetCaption()��SetMemHandle()Ҳ���Զ������������)
OFL_API void _stdcall Edit_ResetUndoBuffer(void* pEdit);
//������ǰ��ѡ����ı���������
OFL_API void _stdcall Edit_Copy(void* pEdit);
//���е�ǰ��ѡ����ı���������
OFL_API void _stdcall Edit_Cut(void* pEdit);
//�����ǰ��ѡ����ı��������������ݸ��Ƶ���������
OFL_API void _stdcall Edit_Clear(void* pEdit);
//ճ���������е����ݵ��ؼ��ĵ�ǰ���λ��
OFL_API void _stdcall Edit_Paste(void* pEdit);
//��ȡ��ӽ�ָ������(����ڿؼ��ͻ���)���ַ�����, line���淵���ַ��������ڵ�������
OFL_API int _stdcall Edit_GetCharFromPoint(void* pEdit,const POINT& p, /*Out*/int* line = NULL);
//��ȡָ���ַ������ڿؼ��ͻ�����λ������(���Ҫ��ȡ���ַ�Ϊ�ֽ�����򷵻ش���β�ַ�֮���"���ַ�"����)
OFL_API void _stdcall Edit_GetPointFromChar(void* pEdit,int index,POINT& p); 
//����ָ���е�һ���ַ�����������б�ų�������Ч��Χ��������-1���������-1�����ȡ��ǰ�е����ַ�����
OFL_API int _stdcall Edit_GetFirstCharFromLine(void* pEdit,int index);   
//����ָ�����ַ��������ڵ���
OFL_API int _stdcall Edit_GetLineFromChar(void* pEdit,int index);
//��ȡ��ǰ��(��û��ѡ���ı�����ǰ��ָ��������У�������ָѡ���ı�һ���ַ�������)
OFL_API int _stdcall Edit_GetCurrentLine(void* pEdit);
//����ָ���ַ����������е��ַ���(ע�⣺�������س�������β��;�����������������Ч��Χ����������0)
OFL_API int _stdcall Edit_GetLineLengthFromChar(void* pEdit,int index);
//��ָ����ĳһ���п�����buffer��ָ���Ļ�����(����������ֹ��)��bufferSizeָ����buffer�Ĵ�С������ʵ�ʿ������ֽ���
OFL_API int _stdcall Edit_CopyLine(void* pEdit,int line, char* buffer, unsigned short bufferSize);
//ѡ��ָ����Χ���ı������������ֱ�ָ��ѡ��λ�õ���ʼ���������
OFL_API void _stdcall Edit_SelectText(void* pEdit,int start,int end);
//��ȡ��ǰ��ѡ���ı�����ֹ��Χ(����������ΪNULL),start���汻ѡ�ı����ַ�������end���汻ѡ�ı�β�ַ�֮���һ���ַ�������
OFL_API void _stdcall Edit_GetSelectRange(void* pEdit,int* start, int* end);
//ѡ�������ı�
OFL_API void _stdcall Edit_SelectAllText(void* pEdit);
//ȡ��ѡ��
OFL_API void _stdcall Edit_CancelSelect(void* pEdit);
//��ָ�����ı��滻����ѡ����ı�,undoָ���Ƿ��Ժ���Գ���(��������ڱ�ѡ����ı�����������false)
OFL_API bool _stdcall Edit_ReplaceText(void* pEdit,char* string, bool undo);
//ɾ����ѡ����ı�
OFL_API bool _stdcall Edit_DeleteSelect(void* pEdit,bool undo);
//����ؼ�û���ı���ѡ��ִ�д˺����ڹ�괦����ָ�����ı�
OFL_API bool _stdcall Edit_InsertText(void* pEdit,char* string, bool undo); 
//���ڶ��б༭�ؼ�����ȡ��ֱ��������ץȡ��(Thumb)�ڹ������е�λ��
OFL_API int _stdcall Edit_GetVertThumb(void* pEdit);	
//�����ؼ���ʹ����˸Caret���ɼ�
OFL_API void _stdcall Edit_ScrollCaret(void* pEdit);
//���ڶ��б༭�ؼ�����ˮƽ����ʹ�ֱ����ֱ����horz��vert
OFL_API void _stdcall Edit_ScrollText(void* pEdit,int horz,int vert);
//���ڶ��б༭�ؼ����ڴ�ֱ��������ı�
OFL_API void _stdcall Edit_VertScroll(void* pEdit,int param);
//���ڶ��б༭�ؼ�������Tab�ַ��ڿؼ���ռ�ݵ��ַ����(Ĭ��8�ַ���),redraw�����˲����Ƿ�ʹ�ؼ�������ʾ�ı�(Ĭ�ϲ�������ʾ)
OFL_API void _stdcall Edit_SetTabSpace(void* pEdit,unsigned int space, bool redraw);

OFL_API void _stdcall Edit_DestroyControl(void* pEdit);
OFL_API char* _stdcall Edit_GetClass(void* pEdit);
OFL_API void _stdcall Edit_SetCaption(void* pEdit,char* string);
OFL_API char* _stdcall Edit_GetCaption(void* pEdit);  

#endif //_OWI_EDIT_H_