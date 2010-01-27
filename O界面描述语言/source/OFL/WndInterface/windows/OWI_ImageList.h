
#ifndef _OWI_IMAGELIST_H_
#define _OWI_IMAGELIST_H_

#include "../../ExportDefine.h"
#include <Windows.h>
#include <CommCtrl.h>

//bool CreateImageList(ImageBitType type,bool useMask,int width,int height);
//bool CreateLargeImageList(ImageBitType type,bool useMask);
//bool CreateSmallImageList(ImageBitType type,bool useMask);
//void DestroyImageList();

OFL_API int _stdcall OImageList_GetImageCount(void* pImageList);   
OFL_API int _stdcall OImageList_GetImageWidth(void* pImageList);
OFL_API int _stdcall OImageList_GetImageHeight(void* pImageList);   
OFL_API void _stdcall OImageList_SetBackColor(void* pImageList,unsigned int color);
OFL_API unsigned int _stdcall OImageList_GetBackColor(void* pImageList); 
OFL_API HIMAGELIST _stdcall OImageList_GetHandle(void* pImageList);

//��λͼ�ļ����߿�ִ���ļ���װ��λͼ																	 
OFL_API bool _stdcall OImageList_AddImageFromFile(void* pImageList,char* image);
OFL_API bool _stdcall OImageList_AddImageFromFileMask(void* pImageList,char* image,char* maskImage);
OFL_API bool _stdcall OImageList_AddImageFromResource(void* pImageList,char* image,char* maskImage = NULL);
OFL_API bool _stdcall OImageList_AddImageFromResourceMask(void* pImageList,HMODULE module,char* image,char* maskImage = NULL);

//��ͼ���ļ����߿�ִ���ļ���װ��ͼ��
OFL_API bool _stdcall OImageList_AddIconFromFile(void* pImageList,char* icon);
OFL_API bool _stdcall OImageList_AddIconFromResourceName(void* pImageList,char* icon);
OFL_API bool _stdcall OImageList_AddIconFromResourceID(void* pImageList,int icon);
OFL_API bool _stdcall OImageList_AddIconFromModuleResourceName(void* pImageList,HMODULE module,char* icon);
OFL_API bool _stdcall OImageList_AddIconFromModuleResourceID(void* pImageList,HMODULE module,int icon);

//�ӹ���ļ����߿�ִ���ļ���װ�ع��
OFL_API bool _stdcall OImageList_AddCursorFromFile(void* pImageList,char* cursor);
OFL_API bool _stdcall OImageList_AddCursorFromResourceName(void* pImageList,char* cursor);
OFL_API bool _stdcall OImageList_AddCursorFromResourceID(void* pImageList,int cursor);
OFL_API bool _stdcall OImageList_AddCursorFromModuleResourceName(void* pImageList,HMODULE module,char* cursor);
OFL_API bool _stdcall OImageList_AddCursorFromModuleResourceID(void* pImageList,HMODULE module,int cursor);
//��ImageList��׷��һ��ͼ��(ImageListά��ͼ�����ĸ�����������ͼ����ͨ������LoadIcon�õ�����ͼ�겻�ص����������ͷ�)
OFL_API int _stdcall OImageList_AddIcon(void* pImageList,HICON icon);
OFL_API bool _stdcall OImageList_RemoveImage(void* pImageList,int index);
OFL_API bool _stdcall OImageList_RemoveAll(void* pImageList);
//��ȡλ��Ϊindex��ͼ�꣬����֮������Ҫ����DestroyIcon������
OFL_API HICON _stdcall OImageList_CreateIcon(void* pImageList,int index);
//����ָ����ͼ��Ϊ����ͼ�ꡣ���磬����ָ������Ϊ45��ͼ��Ϊ����ͼ�꣬��������һ����ţ�������
//������WinListView��WinTreeView��item����ͼ��ʱ���õ�
OFL_API int _stdcall OImageList_SetOverlay(void* pImageList,int image);
OFL_API int _stdcall OImageList_GetLastOverlay(void* pImageList);

#endif //_OWI_IMAGELIST_H_