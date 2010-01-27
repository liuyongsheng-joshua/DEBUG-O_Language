
#include "OWI_Edit.h"
#include "../../CreateWnd/windows/OFControl.h"

OFL_API void _stdcall Edit_SetText(void* pEdit,char* string)
{
	((WinEdit*)pEdit)->SetText(string);
}

OFL_API char* _stdcall Edit_GetText(void* pEdit)
{
	return (char*)((WinEdit*)pEdit)->GetText();
}

OFL_API void _stdcall Edit_SetTextColor(void* pEdit,unsigned int color)
{
	((WinEdit*)pEdit)->SetTextColor(color);
}

OFL_API unsigned int _stdcall Edit_GetTextColor(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetTextColor();
}

OFL_API int _stdcall Edit_GetCharCount(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetCharCount();
}

OFL_API int _stdcall Edit_GetLineCount(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetLineCount();
}

OFL_API int _stdcall Edit_GetTopLine(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetTopLine();
}

OFL_API void _stdcall Edit_SetLimitText(void* pEdit,int limit)
{
	((WinEdit*)pEdit)->SetLimitText(limit);
}

OFL_API int _stdcall Edit_GetLimitText(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetLimitText();
}

OFL_API void _stdcall Edit_SetLeftMargin(void* pEdit,int margin)
{
	((WinEdit*)pEdit)->SetLeftMargin(margin);
}

OFL_API int _stdcall Edit_GetLeftMargin(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetLeftMargin();
}

OFL_API void _stdcall Edit_SetRightMargin(void* pEdit,int margin)
{
	((WinEdit*)pEdit)->SetRightMargin(margin);
}

OFL_API int _stdcall Edit_GetRightMargin(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetRightMargin();
}

OFL_API void _stdcall Edit_SetModifyFlag(void* pEdit,bool modify)
{
	((WinEdit*)pEdit)->SetModifyFlag(modify);
}

OFL_API bool _stdcall Edit_GetModifyFlag(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetModifyFlag();
}

OFL_API void _stdcall Edit_SetPassword(void* pEdit,char pw)
{
	((WinEdit*)pEdit)->SetPassword(pw);
}

OFL_API char _stdcall Edit_GetPassword(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetPassword();
}

OFL_API void _stdcall Edit_SetSelectStart(void* pEdit,int start)
{
	((WinEdit*)pEdit)->SetSelectStart(start);
}

OFL_API int _stdcall Edit_GetSelectStart(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetSelectStart();
}

OFL_API void _stdcall Edit_SetSelectEnd(void* pEdit,int end)
{
	((WinEdit*)pEdit)->SetSelectEnd(end);
}

OFL_API int _stdcall Edit_GetSelectEnd(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetSelectEnd();
}

OFL_API void _stdcall Edit_SetReadOnly(void* pEdit,bool readonly)
{
	((WinEdit*)pEdit)->SetReadOnly(readonly);
}

OFL_API bool _stdcall Edit_GetReadOnly(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetReadOnly();
}

OFL_API void _stdcall Edit_SetFormatRect(void* pEdit,const RECT& rc)
{
	Rect rect;
	rect.mLeft = rc.left;
	rect.mRight = rc.right;
	rect.mTop = rc.top;
	rect.mBottom = rc.bottom;
	((WinEdit*)pEdit)->SetFormatRect(rect);
}

OFL_API void _stdcall Edit_GetFormatRect(void* pEdit,RECT& rc)
{
	Rect rect;
	rect = ((WinEdit*)pEdit)->GetFormatRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}


//���������������Ƿ���ڿ��Գ����Ķ���������ֵָ�������������Ƿ���ڿ��Գ����Ķ���
OFL_API bool _stdcall Edit_CanUndo(void* pEdit)
{
	return ((WinEdit*)pEdit)->CanUndo();
}

//������һ�β���
OFL_API bool _stdcall Edit_Undo(void* pEdit)
{
	return ((WinEdit*)pEdit)->Undo();
}

//��ճ�������(���û�����SetCaption()��SetMemHandle()Ҳ���Զ������������)
OFL_API void _stdcall Edit_ResetUndoBuffer(void* pEdit)
{
	((WinEdit*)pEdit)->ResetUndoBuffer();
}

//������ǰ��ѡ����ı���������
OFL_API void _stdcall Edit_Copy(void* pEdit)
{
	((WinEdit*)pEdit)->Copy();
}

//���е�ǰ��ѡ����ı���������
OFL_API void _stdcall Edit_Cut(void* pEdit)
{
	((WinEdit*)pEdit)->Cut();
}

//�����ǰ��ѡ����ı��������������ݸ��Ƶ���������
OFL_API void _stdcall Edit_Clear(void* pEdit)
{
	((WinEdit*)pEdit)->Clear();
}

//ճ���������е����ݵ��ؼ��ĵ�ǰ���λ��
OFL_API void _stdcall Edit_Paste(void* pEdit)
{
	((WinEdit*)pEdit)->Paste();
}

//��ȡ��ӽ�ָ������(����ڿؼ��ͻ���)���ַ�����, line���淵���ַ��������ڵ�������
OFL_API int _stdcall Edit_GetCharFromPoint(void* pEdit,const POINT& p, /*Out*/int* line)
{
	Point point;
	point.x = p.x;
	point.y = p.y;
	return ((WinEdit*)pEdit)->GetCharFromPoint(point,line);
}

//��ȡָ���ַ������ڿؼ��ͻ�����λ������(���Ҫ��ȡ���ַ�Ϊ�ֽ�����򷵻ش���β�ַ�֮���"���ַ�"����)
OFL_API void _stdcall Edit_GetPointFromChar(void* pEdit,int index,POINT& p)
{
	Point point;
	point = ((WinEdit*)pEdit)->GetPointFromChar(index);
	p.x = point.x;
	p.y = point.y;
}

//����ָ���е�һ���ַ�����������б�ų�������Ч��Χ��������-1���������-1�����ȡ��ǰ�е����ַ�����
OFL_API int _stdcall Edit_GetFirstCharFromLine(void* pEdit,int index)
{
	return ((WinEdit*)pEdit)->GetFirstCharFromLine(index);
}

//����ָ�����ַ��������ڵ���
OFL_API int _stdcall Edit_GetLineFromChar(void* pEdit,int index)
{
	return ((WinEdit*)pEdit)->GetLineFromChar(index);
}

//��ȡ��ǰ��(��û��ѡ���ı�����ǰ��ָ��������У�������ָѡ���ı�һ���ַ�������)
OFL_API int _stdcall Edit_GetCurrentLine(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetCurrentLine();
}

//����ָ���ַ����������е��ַ���(ע�⣺�������س�������β��;�����������������Ч��Χ����������0)
OFL_API int _stdcall Edit_GetLineLengthFromChar(void* pEdit,int index)
{
	return ((WinEdit*)pEdit)->GetLineLengthFromChar(index);
}

//��ָ����ĳһ���п�����buffer��ָ���Ļ�����(����������ֹ��)��bufferSizeָ����buffer�Ĵ�С������ʵ�ʿ������ֽ���
OFL_API int _stdcall Edit_CopyLine(void* pEdit,int line, char* buffer, unsigned short bufferSize)
{
	return ((WinEdit*)pEdit)->CopyLine(line,buffer,bufferSize);
}

//ѡ��ָ����Χ���ı������������ֱ�ָ��ѡ��λ�õ���ʼ���������
OFL_API void _stdcall Edit_SelectText(void* pEdit,int start,int end)
{
	((WinEdit*)pEdit)->SelectText(start,end);
}

//��ȡ��ǰ��ѡ���ı�����ֹ��Χ(����������ΪNULL),start���汻ѡ�ı����ַ�������end���汻ѡ�ı�β�ַ�֮���һ���ַ�������
OFL_API void _stdcall Edit_GetSelectRange(void* pEdit,int* start, int* end)
{
	((WinEdit*)pEdit)->GetSelectRange(start,end);
}

//ѡ�������ı�
OFL_API void _stdcall Edit_SelectAllText(void* pEdit)
{
	((WinEdit*)pEdit)->SelectAllText();
}

//ȡ��ѡ��
OFL_API void _stdcall Edit_CancelSelect(void* pEdit)
{
	((WinEdit*)pEdit)->CancelSelect();
}

//��ָ�����ı��滻����ѡ����ı�,undoָ���Ƿ��Ժ���Գ���(��������ڱ�ѡ����ı�����������false)
OFL_API bool _stdcall Edit_ReplaceText(void* pEdit,char* string, bool undo)
{
	return ((WinEdit*)pEdit)->ReplaceText(string,undo);
}

//ɾ����ѡ����ı�
OFL_API bool _stdcall Edit_DeleteSelect(void* pEdit,bool undo)
{
	return ((WinEdit*)pEdit)->DeleteSelect(undo);
}

//����ؼ�û���ı���ѡ��ִ�д˺����ڹ�괦����ָ�����ı�
OFL_API bool _stdcall Edit_InsertText(void* pEdit,char* string, bool undo)
{
	return ((WinEdit*)pEdit)->InsertText(string,undo);
}

//���ڶ��б༭�ؼ�����ȡ��ֱ��������ץȡ��(Thumb)�ڹ������е�λ��
OFL_API int _stdcall Edit_GetVertThumb(void* pEdit)
{
	return ((WinEdit*)pEdit)->GetVertThumb();
}

//�����ؼ���ʹ����˸Caret���ɼ�
OFL_API void _stdcall Edit_ScrollCaret(void* pEdit)
{
	((WinEdit*)pEdit)->ScrollCaret();
}

//���ڶ��б༭�ؼ�����ˮƽ����ʹ�ֱ����ֱ����horz��vert
OFL_API void _stdcall Edit_ScrollText(void* pEdit,int horz,int vert)
{
	((WinEdit*)pEdit)->ScrollText(horz,vert);
}

//���ڶ��б༭�ؼ����ڴ�ֱ��������ı�
OFL_API void _stdcall Edit_VertScroll(void* pEdit,int param)
{
	((WinEdit*)pEdit)->VertScroll((EditScrollType)param);
}

//���ڶ��б༭�ؼ�������Tab�ַ��ڿؼ���ռ�ݵ��ַ����(Ĭ��8�ַ���),redraw�����˲����Ƿ�ʹ�ؼ�������ʾ�ı�(Ĭ�ϲ�������ʾ)
OFL_API void _stdcall Edit_SetTabSpace(void* pEdit,unsigned int space, bool redraw)
{
	((WinEdit*)pEdit)->SetTabSpace(space,redraw);
}


OFL_API void _stdcall Edit_DestroyControl(void* pEdit)
{
	((WinEdit*)pEdit)->DestroyControl();
}

OFL_API char* _stdcall Edit_GetClass(void* pEdit)
{
	return (char*)((WinEdit*)pEdit)->GetClass();
}

OFL_API void _stdcall Edit_SetCaption(void* pEdit,char* string)
{
	((WinEdit*)pEdit)->SetCaption(string);
}

OFL_API char* _stdcall Edit_GetCaption(void* pEdit)
{
	return (char*)((WinEdit*)pEdit)->GetCaption();
}

