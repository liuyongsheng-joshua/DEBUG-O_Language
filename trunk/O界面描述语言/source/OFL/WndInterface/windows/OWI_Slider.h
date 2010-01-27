
#ifndef _OWI_SLIDER_H_
#define _OWI_SLIDER_H_

#include "../../ExportDefine.h"
#include <Windows.h>

OFL_API void _stdcall Slider_SetLineSize(void* pSlider,int line);
OFL_API int _stdcall Slider_GetLineSize(void* pSlider);
OFL_API void _stdcall Slider_SetPageSize(void* pSlider,int page);
OFL_API int _stdcall Slider_GetPageSize(void* pSlider);
OFL_API void _stdcall Slider_SetPosition(void* pSlider,int pos);
OFL_API int _stdcall Slider_GetPosition(void* pSlider);
OFL_API void _stdcall Slider_SetRangeMin(void* pSlider,int min);
OFL_API int _stdcall Slider_GetRangeMin(void* pSlider);
OFL_API void _stdcall Slider_SetRangeMax(void* pSlider,int max);
OFL_API int _stdcall Slider_GetRangeMax(void* pSlider);
OFL_API void _stdcall Slider_SetSelectStart(void* pSlider,int start);
OFL_API int _stdcall Slider_GetSelectStart(void* pSlider);
OFL_API void _stdcall Slider_SetSelectEnd(void* pSlider,int end);
OFL_API int _stdcall Slider_GetSelectEnd(void* pSlider);
OFL_API void _stdcall Slider_SetSliderSize(void* pSlider,int size);
OFL_API int _stdcall Slider_GetSliderSize(void* pSlider);
OFL_API int _stdcall Slider_GetTickCount(void* pSlider);
OFL_API void _stdcall Slider_SetTickFrequency(void* pSlider,int freq);
OFL_API void _stdcall Slider_SetToolTip(void* pSlider,HWND tip);
OFL_API void _stdcall Slider_SetToolTipSide(void* pSlider,int edge);
OFL_API void _stdcall Slider_GetSliderRect(void* pSlider,RECT& rc);
OFL_API void _stdcall Slider_GetChannelRect(void* pSlider,RECT& rc);
OFL_API HWND _stdcall Slider_GetToolTip(void* pSlider);

//����Trackbar���߼�λ�õ���Ч��Χ(�ؼ�����֮��ͨ��Ӧ�����ô˺����������Լ�����Ч��Χ)
OFL_API void _stdcall Slider_SetRange(void* pSlider,int min,int max);
//ѡ��Trackbar��Χ�ڵ�ĳһ�Σ�ʹ֮������ʾ(Trackbar��mCanSelect������Ϊtrue)
OFL_API void _stdcall Slider_SetSelect(void* pSlider,int min,int max);
//�����ǰ���õĸ���ѡ���
OFL_API void _stdcall Slider_ClearSelect(void* pSlider);
//��ָ�����߼�λ����ʾһ��Tick(ϵͳ�Զ�����һ�������һ��Tick���˺���ֻ�ɴ����м�λ�õ�Tick)
OFL_API void _stdcall Slider_SetTick(void* pSlider,int logicPos);
//����ĳ��Tick���߼�λ��(�߼�λ�ñ�����SetRange()���趨�ķ�Χ)									 
OFL_API int _stdcall Slider_GetTick(void* pSlider,int tick);
//�����β֮�������Tick(��������ؼ��Զ������ĵ�һ�������һ��Tick)
OFL_API void _stdcall Slider_ClearAllTick(void* pSlider);

OFL_API void _stdcall Slider_DestroyControl(void* pSlider);
OFL_API char* _stdcall Slider_GetClass(void* pSlider);
OFL_API void _stdcall Slider_SetCaption(void* pSlider,char* string);
OFL_API char* _stdcall Slider_GetCaption(void* pSlider); 
OFL_API void _stdcall Slider_RedrawControl(void* pSlider,bool redraw);

#endif //_OWI_SLIDER_H_