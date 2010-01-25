
#include "OWI_Slider.h"
#include "../../CreateWnd/windows/OFControl.h"

OFL_API void _stdcall Slider_SetLineSize(void* pSlider,int line)
{
	((WinTrackbar*)pSlider)->SetLineSize(line);
}

OFL_API int _stdcall Slider_GetLineSize(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetLineSize();
}

OFL_API void _stdcall Slider_SetPageSize(void* pSlider,int page)
{
	((WinTrackbar*)pSlider)->SetPageSize(page);
}

OFL_API int _stdcall Slider_GetPageSize(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetPageSize();
}

OFL_API void _stdcall Slider_SetPosition(void* pSlider,int pos)
{
	((WinTrackbar*)pSlider)->SetPosition(pos);
}

OFL_API int _stdcall Slider_GetPosition(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetPosition();
}

OFL_API void _stdcall Slider_SetRangeMin(void* pSlider,int min)
{
	((WinTrackbar*)pSlider)->SetRangeMin(min);
}

OFL_API int _stdcall Slider_GetRangeMin(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetRangeMin();
}

OFL_API void _stdcall Slider_SetRangeMax(void* pSlider,int max)
{
	((WinTrackbar*)pSlider)->SetRangeMax(max);
}

OFL_API int _stdcall Slider_GetRangeMax(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetRangeMax();
}

OFL_API void _stdcall Slider_SetSelectStart(void* pSlider,int start)
{
	((WinTrackbar*)pSlider)->SetSelectStart(start);
}

OFL_API int _stdcall Slider_GetSelectStart(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetSelectStart();
}

OFL_API void _stdcall Slider_SetSelectEnd(void* pSlider,int end)
{
	((WinTrackbar*)pSlider)->SetSelectEnd(end);
}

OFL_API int _stdcall Slider_GetSelectEnd(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetSelectEnd();
}

OFL_API void _stdcall Slider_SetSliderSize(void* pSlider,int size)
{
	((WinTrackbar*)pSlider)->SetSliderSize(size);
}

OFL_API int _stdcall Slider_GetSliderSize(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetSliderSize();
}

OFL_API int _stdcall Slider_GetTickCount(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetTickCount();
}

OFL_API void _stdcall Slider_SetTickFrequency(void* pSlider,int freq)
{
	((WinTrackbar*)pSlider)->SetTickFrequency(freq);
}

OFL_API void _stdcall Slider_SetToolTip(void* pSlider,HWND tip)
{
	((WinTrackbar*)pSlider)->SetToolTip(tip);
}

OFL_API void _stdcall Slider_SetToolTipSide(void* pSlider,int edge)
{
	((WinTrackbar*)pSlider)->SetToolTipSide((EdgeType)edge);
}

OFL_API void _stdcall Slider_GetSliderRect(void* pSlider,RECT& rc)
{
	Rect rect = ((WinTrackbar*)pSlider)->GetSliderRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}

OFL_API void _stdcall Slider_GetChannelRect(void* pSlider,RECT& rc)
{
	Rect rect = ((WinTrackbar*)pSlider)->GetChannelRect();
	rc.left = rect.mLeft;
	rc.top = rect.mTop;
	rc.right = rect.mRight;
	rc.bottom = rect.mBottom;	
}

OFL_API HWND _stdcall Slider_GetToolTip(void* pSlider)
{
	return ((WinTrackbar*)pSlider)->GetToolTip();
}


//����Trackbar���߼�λ�õ���Ч��Χ(�ؼ�����֮��ͨ��Ӧ�����ô˺����������Լ�����Ч��Χ)
OFL_API void _stdcall Slider_SetRange(void* pSlider,int min,int max)
{
	((WinTrackbar*)pSlider)->SetRange(min,max);
}

//ѡ��Trackbar��Χ�ڵ�ĳһ�Σ�ʹ֮������ʾ(Trackbar��mCanSelect������Ϊtrue)
OFL_API void _stdcall Slider_SetSelect(void* pSlider,int min,int max)
{
	((WinTrackbar*)pSlider)->SetSelect(min,max);
}

//�����ǰ���õĸ���ѡ���
OFL_API void _stdcall Slider_ClearSelect(void* pSlider)
{
	((WinTrackbar*)pSlider)->ClearSelect();
}

//��ָ�����߼�λ����ʾһ��Tick(ϵͳ�Զ�����һ�������һ��Tick���˺���ֻ�ɴ����м�λ�õ�Tick)
OFL_API void _stdcall Slider_SetTick(void* pSlider,int logicPos)
{
	((WinTrackbar*)pSlider)->SetTick(logicPos);
}

//����ĳ��Tick���߼�λ��(�߼�λ�ñ�����SetRange()���趨�ķ�Χ)									 
OFL_API int _stdcall Slider_GetTick(void* pSlider,int tick)
{
	return ((WinTrackbar*)pSlider)->GetTick(tick);
}

//�����β֮�������Tick(��������ؼ��Զ������ĵ�һ�������һ��Tick)
OFL_API void _stdcall Slider_ClearAllTick(void* pSlider)
{
	((WinTrackbar*)pSlider)->ClearAllTick();
}


OFL_API void _stdcall Slider_DestroyControl(void* pSlider)
{
	((WinTrackbar*)pSlider)->DestroyControl();
}

OFL_API char* _stdcall Slider_GetClass(void* pSlider)
{
	return (char*)((WinTrackbar*)pSlider)->GetClass();
}

OFL_API void _stdcall Slider_SetCaption(void* pSlider,char* string)
{
	((WinTrackbar*)pSlider)->SetCaption(string);
}

OFL_API char* _stdcall Slider_GetCaption(void* pSlider)
{
	return (char*)((WinTrackbar*)pSlider)->GetCaption();
}

OFL_API void _stdcall Slider_RedrawControl(void* pSlider,bool redraw)
{
	((WinTrackbar*)pSlider)->RedrawControl(redraw);
}
