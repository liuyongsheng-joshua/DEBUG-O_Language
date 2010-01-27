#ifndef _O_FACE_LANGUAGE_H_
#define _O_FACE_LANGUAGE_H_

#include "ExportDefine.h"

//��Ĭ�����ֽ��г�ʼ�� nLanguageType < 0ʱ�������������� 
//nLanguageType == 0 ʱʹ��Ĭ�������ļ����г�ʼ��
OFL_API bool _stdcall  OFDefaultInit(int nLanguageType);
OFL_API bool _stdcall  OFLoadDefaultLanguage(int nLanguageType); //����Ĭ����������
OFL_API bool _stdcall  OFInit(char* pchAppDir,char* pchLanguageFile); //ʹ��ָ���������ļ����г�ʼ��
OFL_API void _stdcall  OFClear(); //�������������
OFL_API bool _stdcall  OFAddFunction(char* pchFunctionName,void* pfun); //��Ӻ���
OFL_API bool _stdcall  OFParse(char* pchScriptFileName,int nShowError); //���������ļ�
//�����ַ���pchFileName���ַ������ڵ��ļ������ǿ�����,nRelativeLine�ַ������ļ��е�����ʼ��,������ʾ�����к�
OFL_API bool _stdcall  OFParseString(char* pchScriptString,char* pchFileName,int nShowError,int nRelativeLine,bool bNoSearchFunction); 
OFL_API char* _stdcall OFGetParseText();
OFL_API void _stdcall  OFFreeMem(char* p);

OFL_API void* _stdcall OFShowMainWnd(char* pchWndName); //��ʾ������,������ʾ��������Ϣѭ��
OFL_API void* _stdcall OFShowWnd(char* pchWndName,void* pParentWnd); //��ʾһ�㴰��,pParentWndΪ������ָ��
OFL_API void* _stdcall OFGetControl(char* pchControlName); //ʹ����������ȡ�ؼ�(��������)

#define AddInterfaceFunction(fun_name) OFAddFunction(#fun_name,fun_name);

//�ؼ��ӿ�
#include "./WndInterface/WndInterface.h"

#endif //_O_FACE_LANGUAGE_H_