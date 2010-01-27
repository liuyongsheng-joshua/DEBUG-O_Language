
#include "OWI_ImageList.h"
#include "../../CreateWnd/windows/OFControl.h"

OFL_API int _stdcall OImageList_GetImageCount(void* pImageList)
{
	return ((WinImageList*)pImageList)->GetImageCount();
}

OFL_API int _stdcall OImageList_GetImageWidth(void* pImageList)
{
	return ((WinImageList*)pImageList)->GetImageWidth();
}

OFL_API int _stdcall OImageList_GetImageHeight(void* pImageList)
{
	return ((WinImageList*)pImageList)->GetImageHeight();
}

OFL_API void _stdcall OImageList_SetBackColor(void* pImageList,unsigned int color)
{
	((WinImageList*)pImageList)->SetBackColor(color);
}

OFL_API unsigned int _stdcall OImageList_GetBackColor(void* pImageList)
{
	return ((WinImageList*)pImageList)->GetBackColor();
}

OFL_API HIMAGELIST _stdcall OImageList_GetHandle(void* pImageList)
{
	return ((WinImageList*)pImageList)->GetHandle();
}


//��λͼ�ļ����߿�ִ���ļ���װ��λͼ																	 
OFL_API bool _stdcall OImageList_AddImageFromFile(void* pImageList,char* image)
{
	return ((WinImageList*)pImageList)->AddImageFromFile(image);
}

OFL_API bool _stdcall OImageList_AddImageFromFileMask(void* pImageList,char* image,char* maskImage)
{
	return ((WinImageList*)pImageList)->AddImageFromFile(image,maskImage);
}

OFL_API bool _stdcall OImageList_AddImageFromResource(void* pImageList,char* image,char* maskImage)
{
	return ((WinImageList*)pImageList)->AddImageFromResource(image,maskImage);
}

OFL_API bool _stdcall OImageList_AddImageFromResourceMask(void* pImageList,HMODULE module,char* image,char* maskImage)
{
	return ((WinImageList*)pImageList)->AddImageFromResource(module,image,maskImage);
}


//��ͼ���ļ����߿�ִ���ļ���װ��ͼ��
OFL_API bool _stdcall OImageList_AddIconFromFile(void* pImageList,char* icon)
{
	return ((WinImageList*)pImageList)->AddIconFromFile(icon);
}

OFL_API bool _stdcall OImageList_AddIconFromResourceName(void* pImageList,char* icon)
{
	return ((WinImageList*)pImageList)->AddIconFromResource(icon);
}

OFL_API bool _stdcall OImageList_AddIconFromResourceID(void* pImageList,int icon)
{
	return ((WinImageList*)pImageList)->AddIconFromResource(icon);
}

OFL_API bool _stdcall OImageList_AddIconFromModuleResourceName(void* pImageList,HMODULE module,char* icon)
{
	return ((WinImageList*)pImageList)->AddIconFromResource(module,icon);
}

OFL_API bool _stdcall OImageList_AddIconFromModuleResourceID(void* pImageList,HMODULE module,int icon)
{
	return ((WinImageList*)pImageList)->AddIconFromResource(module,icon);
}


//�ӹ���ļ����߿�ִ���ļ���װ�ع��
OFL_API bool _stdcall OImageList_AddCursorFromFile(void* pImageList,char* cursor)
{
	return ((WinImageList*)pImageList)->AddCursorFromFile(cursor);
}

OFL_API bool _stdcall OImageList_AddCursorFromResourceName(void* pImageList,char* cursor)
{
	return ((WinImageList*)pImageList)->AddCursorFromResource(cursor);
}

OFL_API bool _stdcall OImageList_AddCursorFromResourceID(void* pImageList,int cursor)
{
	return ((WinImageList*)pImageList)->AddCursorFromResource(cursor);
}

OFL_API bool _stdcall OImageList_AddCursorFromModuleResourceName(void* pImageList,HMODULE module,char* cursor)
{
	return ((WinImageList*)pImageList)->AddCursorFromResource(module,cursor);
}

OFL_API bool _stdcall OImageList_AddCursorFromModuleResourceID(void* pImageList,HMODULE module,int cursor)
{
	return ((WinImageList*)pImageList)->AddCursorFromResource(module,cursor);
}

//��ImageList��׷��һ��ͼ��(ImageListά��ͼ�����ĸ�����������ͼ����ͨ������LoadIcon�õ�����ͼ�겻�ص����������ͷ�)
OFL_API int _stdcall OImageList_AddIcon(void* pImageList,HICON icon)
{
	return ((WinImageList*)pImageList)->AddIcon(icon);
}

OFL_API bool _stdcall OImageList_RemoveImage(void* pImageList,int index)
{
	return ((WinImageList*)pImageList)->RemoveImage(index);
}

OFL_API bool _stdcall OImageList_RemoveAll(void* pImageList)
{
	return ((WinImageList*)pImageList)->RemoveAll();
}

//��ȡλ��Ϊindex��ͼ�꣬����֮������Ҫ����DestroyIcon������
OFL_API HICON _stdcall OImageList_CreateIcon(void* pImageList,int index)
{
	return ((WinImageList*)pImageList)->CreateIcon(index);
}

//����ָ����ͼ��Ϊ����ͼ�ꡣ���磬����ָ������Ϊ45��ͼ��Ϊ����ͼ�꣬��������һ����ţ�������
//������WinListView��WinTreeView��item����ͼ��ʱ���õ�
OFL_API int _stdcall OImageList_SetOverlay(void* pImageList,int image)
{
	return ((WinImageList*)pImageList)->SetOverlay(image);
}

OFL_API int _stdcall OImageList_GetLastOverlay(void* pImageList)
{
	return ((WinImageList*)pImageList)->GetLastOverlay();
}
