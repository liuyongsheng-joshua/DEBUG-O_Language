
#include "OWI_Progress.h"
#include "../../CreateWnd/windows/OFControl.h"

OFL_API void _stdcall Progress_SetStart(void* pProgress,int start)
{
	((WinProgress*)pProgress)->SetStart(start);
}

OFL_API int _stdcall Progress_GetStart(void* pProgress)
{
	return ((WinProgress*)pProgress)->GetStart();
}

OFL_API void _stdcall Progress_SetEnd(void* pProgress,int end)
{
	((WinProgress*)pProgress)->SetEnd(end);
}

OFL_API int _stdcall Progress_GetEnd(void* pProgress)
{
	return ((WinProgress*)pProgress)->GetEnd();
}

OFL_API void _stdcall Progress_SetPosition(void* pProgress,int pos)
{
	((WinProgress*)pProgress)->SetPosition(pos);
}

OFL_API int _stdcall Progress_GetPosition(void* pProgress)
{
	return ((WinProgress*)pProgress)->GetPosition();
}

OFL_API void _stdcall Progress_SetStepDelta(void* pProgress,int step)
{
	((WinProgress*)pProgress)->SetStepDelta(step);
}

OFL_API void _stdcall Progress_SetColor(void* pProgress,unsigned int color)
{
	((WinProgress*)pProgress)->SetColor(color);
}

OFL_API unsigned int _stdcall Progress_GetColor(void* pProgress)
{
	return ((WinProgress*)pProgress)->GetColor();
}

OFL_API void _stdcall Progress_SetBackColor(void* pProgress,unsigned int color)
{
	((WinProgress*)pProgress)->SetBackColor(color);
}

OFL_API unsigned int _stdcall Progress_GetBackColor(void* pProgress)
{
	return ((WinProgress*)pProgress)->GetBackColor();
}


//���ý�������Χ����ʼλ�úͽ���λ��
OFL_API void _stdcall Progress_SetRange(void* pProgress,int start,int end)
{
	((WinProgress*)pProgress)->SetRange(start,end);
}

//��ȡ��������Χ����ʼλ�úͽ���λ��
OFL_API bool _stdcall Progress_GetRange(void* pProgress,int& start,int& end)
{
	return ((WinProgress*)pProgress)->GetRange(start,end);
}

//���ý�������λ������������λ�ñ仯���µ�λ�õ��ھ�λ�ü��ϴ�����delta
OFL_API void _stdcall Progress_AdvancePosition(void* pProgress,int delta)
{
	((WinProgress*)pProgress)->AdvancePosition(delta);
}

//��ǰλ����ǰ��������������ֵȡ������ǰmStepDelta���趨
OFL_API void _stdcall Progress_StepPosition(void* pProgress)
{
	((WinProgress*)pProgress)->StepPosition();
}


OFL_API void _stdcall Progress_DestroyControl(void* pProgress)
{
	((WinProgress*)pProgress)->DestroyControl();
}

OFL_API char* _stdcall Progress_GetClass(void* pProgress)
{
	return (char*)((WinProgress*)pProgress)->GetClass();
}

OFL_API bool _stdcall Progress_IsProgress(void* pProgress)
{
	return ((WinProgress*)pProgress)->IsProgress();
}

OFL_API void _stdcall Progress_SetCaption(void* pProgress,char* string)
{
	((WinProgress*)pProgress)->SetCaption(string);
}

OFL_API char* _stdcall Progress_GetCaption(void* pProgress)
{
	return (char*)((WinProgress*)pProgress)->GetCaption();
}
