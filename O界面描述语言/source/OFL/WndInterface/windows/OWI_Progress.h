
#ifndef _OWI_PROGRESS_H_
#define _OWI_PROGRESS_H_

#include "../../ExportDefine.h"

OFL_API void _stdcall Progress_SetStart(void* pProgress,int start);
OFL_API int _stdcall Progress_GetStart(void* pProgress);
OFL_API void _stdcall Progress_SetEnd(void* pProgress,int end);
OFL_API int _stdcall Progress_GetEnd(void* pProgress);	   
OFL_API void _stdcall Progress_SetPosition(void* pProgress,int pos);
OFL_API int _stdcall Progress_GetPosition(void* pProgress);	 
OFL_API void _stdcall Progress_SetStepDelta(void* pProgress,int step);
OFL_API void _stdcall Progress_SetColor(void* pProgress,unsigned int color);
OFL_API unsigned int _stdcall Progress_GetColor(void* pProgress);
OFL_API void _stdcall Progress_SetBackColor(void* pProgress,unsigned int color);
OFL_API unsigned int _stdcall Progress_GetBackColor(void* pProgress);

//���ý�������Χ����ʼλ�úͽ���λ��
OFL_API void _stdcall Progress_SetRange(void* pProgress,int start,int end);
//��ȡ��������Χ����ʼλ�úͽ���λ��
OFL_API bool _stdcall Progress_GetRange(void* pProgress,int& start,int& end);
//���ý�������λ������������λ�ñ仯���µ�λ�õ��ھ�λ�ü��ϴ�����delta
OFL_API void _stdcall Progress_AdvancePosition(void* pProgress,int delta);
//��ǰλ����ǰ��������������ֵȡ������ǰmStepDelta���趨
OFL_API void _stdcall Progress_StepPosition(void* pProgress);	

OFL_API void _stdcall Progress_DestroyControl(void* pProgress);
OFL_API char* _stdcall Progress_GetClass(void* pProgress);
OFL_API bool _stdcall Progress_IsProgress(void* pProgress);
OFL_API void _stdcall Progress_SetCaption(void* pProgress,char* string);
OFL_API char* _stdcall Progress_GetCaption(void* pProgress);

#endif //_OWI_PROGRESS_H_