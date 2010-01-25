
#ifndef _OWI_SPIN_H_
#define _OWI_SPIN_H_

#include "../../ExportDefine.h"

OFL_API void _stdcall Spin_SetPosition(void* pSpin,int pos);
OFL_API int _stdcall Spin_GetPosition(void* pSpin);
OFL_API void _stdcall Spin_SetBase(void* pSpin,int base);
OFL_API int _stdcall Spin_GetBase(void* pSpin);
OFL_API void _stdcall Spin_SetBuddy(void* pSpin,void* buddy);
OFL_API void* _stdcall Spin_GetBuddy(void* pSpin);

//���ÿؼ�����С�������ڷ�Χ
OFL_API void _stdcall Spin_SetRange(void* pSpin,int min, int max);
//��ȡ�ؼ�����С���ڷ�Χ
OFL_API int _stdcall Spin_GetRangeMin(void* pSpin);
//��ȡ�ؼ��������ڷ�Χ
OFL_API int _stdcall Spin_GetRangeMax(void* pSpin);	
//��ȡ�ؼ�����С�������ڷ�Χ
OFL_API void _stdcall Spin_GetRange(void* pSpin,int& min, int& max);

OFL_API void _stdcall Spin_DestroyControl(void* pSpin);	
OFL_API char* _stdcall Spin_GetClass(void* pSpin);
OFL_API void _stdcall Spin_SetCaption(void* pSpin,char* string);
OFL_API char* _stdcall Spin_GetCaption(void* pSpin);

#endif //_OWI_SPIN_H_