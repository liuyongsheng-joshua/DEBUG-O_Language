
#ifndef _OWI_REBAR_H_
#define _OWI_REBAR_H_

#include "../../ExportDefine.h"
#include <Windows.h>

//////////////////////////////////////////////////////////////////////////
//RebarBand
OFL_API unsigned int _stdcall RebarBand_GetId(void* pRebarBand);
OFL_API int _stdcall RebarBand_GetIndex(void* pRebarBand);
OFL_API void _stdcall RebarBand_SetText(void* pRebarBand,char* text);
OFL_API char* _stdcall RebarBand_GetText(void* pRebarBand);
OFL_API void _stdcall RebarBand_SetImage(void* pRebarBand,int index);
OFL_API int _stdcall RebarBand_GetImage(void* pRebarBand); 
OFL_API void _stdcall RebarBand_SetWidth(void* pRebarBand,int width);
OFL_API int _stdcall RebarBand_GetWidth(void* pRebarBand);   
OFL_API void _stdcall RebarBand_SetVisible(void* pRebarBand,bool visible);
OFL_API bool _stdcall RebarBand_GetVisible(void* pRebarBand);   
OFL_API bool _stdcall RebarBand_HasChevron(void* pRebarBand); 
OFL_API void _stdcall RebarBand_SetTextColor(void* pRebarBand,unsigned int color);
OFL_API unsigned int _stdcall RebarBand_GetTextColor(void* pRebarBand);
OFL_API void _stdcall RebarBand_SetBackColor(void* pRebarBand,unsigned int color);
OFL_API unsigned int _stdcall RebarBand_GetBackColor(void* pRebarBand);
OFL_API void _stdcall RebarBand_SetLeftMargin(void* pRebarBand,int margin);
OFL_API int _stdcall RebarBand_GetLeftMargin(void* pRebarBand); 
OFL_API void _stdcall RebarBand_SetChevronLimit(void* pRebarBand,int limit);
OFL_API int _stdcall RebarBand_GetChevronLimit(void* pRebarBand);
OFL_API void _stdcall RebarBand_SetMinChildWidth(void* pRebarBand,int width);
OFL_API int _stdcall RebarBand_GetMinChildWidth(void* pRebarBand);
OFL_API void _stdcall RebarBand_SetMinHeight(void* pRebarBand,int height);
OFL_API int _stdcall RebarBand_GetMinHeight(void* pRebarBand);		
OFL_API void _stdcall RebarBand_GetRect(void* pRebarBand,RECT& rc);
OFL_API void _stdcall RebarBand_SetBackBitmap(void* pRebarBand,HBITMAP bitmap);
OFL_API HBITMAP _stdcall RebarBand_GetBackBitmap(void* pRebarBand);	 
OFL_API void* _stdcall RebarBand_GetParent(void* pRebarBand);
OFL_API void* _stdcall RebarBand_GetChild(void* pRebarBand);	

OFL_API void* _stdcall RebarBand_GetOwner(void* pRebarBand);
OFL_API bool _stdcall RebarBand_IsClientEmpty(void* pRebarBand);
OFL_API void _stdcall RebarBand_AddControl(void* pRebarBand,void* pControl);
OFL_API void _stdcall RebarBand_RemoveControl(void* pRebarBand,void* pControl);

OFL_API void _stdcall RebarBand_SetColor(void* pRebarBand,unsigned int foreColor,unsigned int backColor);
OFL_API void _stdcall RebarBand_GetColor(void* pRebarBand,unsigned int& foreColor,unsigned int& backColor);	
OFL_API void _stdcall RebarBand_SetMinChildSize(void* pRebarBand,int minWidth,int minHeight);
OFL_API void _stdcall RebarBand_GetMinChildSize(void* pRebarBand,int& minWidth,int& minHeight);

//////////////////////////////////////////////////////////////////////////
//Rebar
OFL_API int _stdcall Rebar_GetBandCount(void* pRebar);
OFL_API int _stdcall Rebar_GetRowCount(void* pRebar);
OFL_API int _stdcall Rebar_GetRowHeight(void* pRebar,int index);
OFL_API void _stdcall Rebar_SetTextColor(void* pRebar,unsigned int color);
OFL_API unsigned int _stdcall Rebar_GetTextColor(void* pRebar);
OFL_API void _stdcall Rebar_GetBandRect(void* pRebar,int pos,RECT& rc); 
OFL_API void _stdcall Rebar_SetImageList(void* pRebar,void* imageList);
OFL_API void* _stdcall Rebar_GetBand(void* pRebar,int index);	 
OFL_API void* _stdcall Rebar_GetImageList(void* pRebar);

//????????Band??????1????Band????????????2????Band????????????????3????????????Band??????????????????4????????Band????????????????
OFL_API void* _stdcall Rebar_AddBand(void* pRebar,int width=50,int height=10,bool newLine=true,bool fixedSize=false);
//????????index??Band????????????????Band????????????????AddBand()??????????
OFL_API void* _stdcall Rebar_InsertBand(void* pRebar,int index,int width=50,int height=10,bool newLine=true,bool fixedSize=false);
//??????????band??Band
OFL_API void _stdcall Rebar_DeleteBand(void* pRebar,void* band);
//??????????index??Band
OFL_API void _stdcall Rebar_DeleteBandIndex(void* pRebar,int index);
//??????????Band
OFL_API void _stdcall Rebar_DeleteAllBand(void* pRebar);
//????????????????????????index??Band????????????????????(??????Band????????????????/??????Band)
OFL_API void _stdcall Rebar_MaximizeBand(void* pRebar,int index);
//????????????????????????index??Band
OFL_API void _stdcall Rebar_MinimizeBand(void* pRebar,int index);
//??????????????????????iFrom??Band????????????????iTo
OFL_API void _stdcall Rebar_MoveBand(void* pRebar,int iFrom, int iTo);
//??????????????????????index??Band??????????
OFL_API void _stdcall Rebar_PushChevron(void* pRebar,int index);
//??????????????????????????index??Band????????????????????
OFL_API void _stdcall Rebar_BeginDrag(void* pRebar,int index);
//????????????????????????????(x,y)
OFL_API void _stdcall Rebar_DragMove(void* pRebar,int x, int y);
//????????????
OFL_API void _stdcall Rebar_EndDrag(void* pRebar);
//??????????Band??????????p(????????????????????)????
OFL_API void* _stdcall Rebar_IsOnBand(void* pRebar,const POINT& p);

OFL_API void _stdcall Rebar_DestroyControl(void* pRebar);
OFL_API char* _stdcall Rebar_GetClass(void* pRebar);
OFL_API void _stdcall Rebar_SetCaption(void* pRebar,char* string);
OFL_API char* _stdcall Rebar_GetCaption(void* pRebar);
OFL_API void _stdcall Rebar_Move(void* pRebar,int dx,int dy);
OFL_API void _stdcall Rebar_SetSize(void* pRebar,int width,int height);
OFL_API void _stdcall Rebar_SetPositionSize(void* pRebar,int left,int top,int width,int height);
OFL_API void _stdcall Rebar_RedrawControl(void* pRebar,bool redraw);

#endif //_OWI_REBAR_H_