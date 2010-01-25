
#ifndef _DOASM_DLL_H_
#define _DOASM_DLL_H_


// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DOASMDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DOASMDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DOASMDLL_EXPORTS
#define DOASMDLL_API extern "C"__declspec(dllexport)
#else
#define DOASMDLL_API extern "C" __declspec(dllimport)
#endif


DOASMDLL_API int   doi_LoadLanguageFile(char* pchLanguageFile);
DOASMDLL_API int   doi_GetLanguageType();
DOASMDLL_API void  doi_DoasmInit(unsigned char* puchCode,unsigned int uiLength,unsigned int ui_image_base);
DOASMDLL_API unsigned int doi_GetDoasmDataCurPos();
DOASMDLL_API void doi_GetDoasmExternAddr(unsigned int& unExternAddr,int& nExternAddrType);
DOASMDLL_API void doi_SetDoasmExternAddr(unsigned int unExternAddr,int nExternAddrType);

DOASMDLL_API int   doi_DoasmBegin(char* pchLanguageFile,unsigned char* puchCode,unsigned int uiLength,unsigned int ui_image_base);
DOASMDLL_API void  doi_DoasmData(char* pchInsnText);
DOASMDLL_API bool  doi_isEnd();


#endif //_DOASM_DLL_H_