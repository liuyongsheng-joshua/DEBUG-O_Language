// DlgEditOption.cpp : 实现文件
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgOasmEditOption.h"


// CDlgOasmEditOption 对话框

IMPLEMENT_DYNAMIC(CDlgOasmEditOption, CResizablePage)

CDlgOasmEditOption::CDlgOasmEditOption()
	: CResizablePage(CDlgOasmEditOption::IDD)
{
	SetTabIcon(IDI_OPTION_EDITOR);
}

CDlgOasmEditOption::~CDlgOasmEditOption()
{
}

void CDlgOasmEditOption::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgOasmEditOption, CResizablePage)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgOasmEditOption 消息处理程序

BOOL CDlgOasmEditOption::OnInitDialog()
{
	CResizablePage::OnInitDialog();

	// TODO:  在此添加额外的初始化

	if(m_wndPropertyGrid.GetSafeHwnd() == 0)
	{
		if (!m_wndPropertyGrid.Create(WS_VISIBLE | WS_CHILD, CRect(0, 0, 0, 0), this, 2))
		{
			TRACE0("未能创建属性网格\n");
			return FALSE;      // 未能创建
		}
		m_wndPropertyGrid.SetOwner(this);

		m_wndPropertyGrid.EnableHeaderCtrl(FALSE);
		m_wndPropertyGrid.EnableDescriptionArea();
		m_wndPropertyGrid.SetVSDotNetLook();
		m_wndPropertyGrid.MarkModifiedProperties();

		//设置输入提示路径
		CMFCPropertyGridProperty* pPropertyHintFile = new CMFCPropertyGridProperty(_T("编辑配置文件"));
		static TCHAR BASED_CODE szFilter[] = _T("提示文件(*.ohc)|*.ohc|所有文件(*.*)|*.*||");
		CMFCPropertyGridFileProperty* pPropertySyntaxWordFileName= new CMFCPropertyGridFileProperty(_T("语法字文件"), TRUE, _T(""), _T("ohc"), 0, szFilter, _T("语法字配置文件"));
		pPropertySyntaxWordFileName->SetValue(COleVariant(m_strOASMSyntaxWordFileName));
		pPropertyHintFile->AddSubItem(pPropertySyntaxWordFileName);
		CMFCPropertyGridFileProperty* pPropertySelectionListFile = new CMFCPropertyGridFileProperty(_T("选择列表文件"), TRUE, _T(""), _T("ohc"), 0, szFilter, _T("选择列表配置文件"));
		pPropertySelectionListFile->SetValue(COleVariant(m_strSelectionListFileName));
		pPropertyHintFile->AddSubItem(pPropertySelectionListFile);
		pPropertyHintFile->AddSubItem(new CMFCPropertyGridFileProperty(_T("模板文件目录"), m_strOASMTempletDir,0,_T("代码模板文件所在的目录")));
		CMFCPropertyGridFileProperty* pPropertyAutoCompleteFile = new CMFCPropertyGridFileProperty(_T("输入提示文件"), TRUE, _T(""), _T("ohc"), 0, szFilter, _T("输入自动完成提示配置文件"));
		pPropertyAutoCompleteFile->SetValue(COleVariant(m_strOASMAutoCompleteFileName));
		pPropertyHintFile->AddSubItem(pPropertyAutoCompleteFile);
		CMFCPropertyGridFileProperty* pPropertyTipFile = new CMFCPropertyGridFileProperty(_T("提示信息文件"), TRUE, _T(""), _T("ohc"), 0, szFilter, _T("提示信息配置文件"));
		pPropertyTipFile->SetValue(COleVariant(m_strOASMTipFileName));
		pPropertyHintFile->AddSubItem(pPropertyTipFile);

		m_wndPropertyGrid.AddProperty(pPropertyHintFile);

		COLORREF colorDefaultBackGround = ::GetSysColor(COLOR_WINDOW);
		COLORREF colorDefaultText = ::GetSysColor(COLOR_WINDOWTEXT);

		//设置语法颜色	
		CMFCPropertyGridProperty* pPropertySyntaxHighLight = new CMFCPropertyGridProperty(_T("语法着色"));
		CMFCPropertyGridColorProperty* pPropColor = NULL;
		#define SyntaxHighLightAddSubItem(name,color,default_color,description)  \
		pPropColor = new CMFCPropertyGridColorProperty(name, color, NULL, description); \
		pPropColor->EnableOtherButton(_T("其他...")); \
		pPropColor->EnableAutomaticButton(_T("默认"), default_color); \
		pPropertySyntaxHighLight->AddSubItem(pPropColor);

		SyntaxHighLightAddSubItem((_T("背景颜色")),       m_colorBackGround,    (colorDefaultBackGround),(_T("默认的背景颜色")));
		SyntaxHighLightAddSubItem((_T("文本颜色")),       m_colorText,          (colorDefaultText),      (_T("默认的文本颜色")));
		SyntaxHighLightAddSubItem((_T("注释行颜色")),     m_colorCommentLine,   (RGB(0x00, 0x80, 0x00)), (_T("注释行的文本颜色")));
		SyntaxHighLightAddSubItem((_T("注释块颜色")),     m_colorCommentBlock,  (RGB(0x00, 0x80, 0x00)), (_T("注释块的文本颜色")));
		SyntaxHighLightAddSubItem((_T("引用文颜色")),     m_colorIncludeText,   (RGB(0x00, 0x80, 0xFF)), (_T("引用文的文本颜色")));
		SyntaxHighLightAddSubItem((_T("引用库颜色")),     m_colorIncludeLib,    (RGB(0x00, 0x80, 0xFF)), (_T("引用库的文本颜色")));
		SyntaxHighLightAddSubItem((_T("数据段标记颜色")), m_colorSegmentData,   (RGB(0xBB, 0x00, 0x40)), (_T("数据段标记符号的颜色")));
		SyntaxHighLightAddSubItem((_T("只读段标记颜色")), m_colorSegmentRData,  (RGB(0xBB, 0x00, 0x40)), (_T("只读段标记符号的颜色")));
		SyntaxHighLightAddSubItem((_T("预留段标记颜色")), m_colorSegmentBSS,    (RGB(0xBB, 0x00, 0x40)), (_T("预留段标记符号的颜色")));
		SyntaxHighLightAddSubItem((_T("外部段标记颜色")), m_colorSegmentExtern, (RGB(0xBB, 0x00, 0x40)), (_T("外部段标记符号的颜色")));
		SyntaxHighLightAddSubItem((_T("代码段标记颜色")), m_colorSegmentCode,   (RGB(0xBB, 0x00, 0x40)), (_T("代码段标记符号的颜色")));
		SyntaxHighLightAddSubItem((_T("数字颜色")),       m_colorDigital,       (RGB(0x00, 0x80, 0x80)), (_T("数字字符的颜色")));
		SyntaxHighLightAddSubItem((_T("指令颜色")),       m_colorInstruction,   (RGB(0x83, 0x07, 0xF6)), (_T("指令字符的颜色")));
		SyntaxHighLightAddSubItem((_T("浮点指令颜色")),   m_colorFInstruction,  (RGB(0x83, 0x07, 0xF6)), (_T("浮点指令字符的颜色")));
		SyntaxHighLightAddSubItem((_T("寄存器颜色")),     m_colorRegister,      (RGB(0x0F, 0xAC, 0xA6)), (_T("寄存器字符的颜色")));
		SyntaxHighLightAddSubItem((_T("单字符颜色")),     m_colorChar,          (RGB(0xC0, 0x20, 0x00)), (_T("单字符的颜色")));
		SyntaxHighLightAddSubItem((_T("字符串颜色")),     m_colorString,        (RGB(0xC0, 0x20, 0x00)), (_T("字符串的颜色")));
		SyntaxHighLightAddSubItem((_T("定义字颜色")),     m_colorDefineWord,    (RGB(0x25, 0x09, 0xF3)), (_T("定义字的颜色")));
		SyntaxHighLightAddSubItem((_T("宏标识符颜色")),   m_colorMacro,         (RGB(0x80, 0x00, 0x39)), (_T("宏标识符的颜色")));
		SyntaxHighLightAddSubItem((_T("文本操作符颜色")), m_colorOperatorTxt,   (RGB(0x80, 0x80, 0x00)), (_T("文本操作符的颜色")));
		SyntaxHighLightAddSubItem((_T("操作符颜色")),     m_colorOperator,      (RGB(0x80, 0x80, 0x00)), (_T("操作符的颜色")));
		
		#undef SyntaxHighLightAddSubItem
		m_wndPropertyGrid.AddProperty(pPropertySyntaxHighLight);

		//字体
		CMFCPropertyGridProperty* pPropertyFont = new CMFCPropertyGridProperty(_T("字体"));		
		pPropertyFont->AddSubItem(new CMFCPropertyGridFontProperty(_T("文本字体"), m_lfTextFont, CF_EFFECTS | CF_SCREENFONTS, _T("指定文本字体")));
		m_wndPropertyGrid.AddProperty(pPropertyFont);

		//左边附加栏
		CMFCPropertyGridProperty* pPropertyExtraColumn = new CMFCPropertyGridProperty(_T("附加栏"));
		pPropertyExtraColumn->AddSubItem(new CMFCPropertyGridProperty(_T("显示行号"), (_variant_t)(m_bShowLineNumber?true:false), _T("显示行号")));
		pPropertyExtraColumn->AddSubItem(new CMFCPropertyGridProperty(_T("显示书签"), (_variant_t)(m_bShowBookMarker?true:false), _T("显示书签栏")));
		pPropertyExtraColumn->AddSubItem(new CMFCPropertyGridProperty(_T("显示折叠"), (_variant_t)(m_bShowFold?true:false), _T("显示折叠栏")));
		m_wndPropertyGrid.AddProperty(pPropertyExtraColumn);

		//保存
		CMFCPropertyGridProperty* pPropertySave = new CMFCPropertyGridProperty(_T("保存"));
		pPropertySave->AddSubItem(new CMFCPropertyGridProperty(_T("自动保存"), (_variant_t)(m_bAutoSave?true:false), _T("文档被修改后10秒自动保存")));
		m_wndPropertyGrid.AddProperty(pPropertySave);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDlgOasmEditOption::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码

	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		m_wndPropertyGrid.MoveWindow(0,0,cx,cy);
	}
}

void CDlgOasmEditOption::GetOption()
{
	if(m_wndPropertyGrid.GetSafeHwnd())
	{
		CMFCPropertyGridProperty* pPropertyHintFile = m_wndPropertyGrid.GetProperty(0);
		m_strOASMSyntaxWordFileName = (CString)pPropertyHintFile->GetSubItem(0)->GetValue();
		m_strSelectionListFileName = (CString)pPropertyHintFile->GetSubItem(1)->GetValue();
		m_strOASMTempletDir = (CString)pPropertyHintFile->GetSubItem(2)->GetValue();		
		m_strOASMAutoCompleteFileName = (CString)pPropertyHintFile->GetSubItem(3)->GetValue();
		m_strOASMTipFileName = (CString)pPropertyHintFile->GetSubItem(4)->GetValue();

		CMFCPropertyGridProperty* pPropertySyntaxHighLight = m_wndPropertyGrid.GetProperty(1);
		CMFCPropertyGridColorProperty* pPropColor = 0;
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(0);
		m_colorBackGround = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(1);
		m_colorText = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(2);
		m_colorCommentLine = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(3);
		m_colorCommentBlock = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(4);
		m_colorIncludeText = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(5);
		m_colorIncludeLib = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(6);
		m_colorSegmentData = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(7);
		m_colorSegmentRData = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(8);
		m_colorSegmentBSS = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(9);
		m_colorSegmentExtern = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(10);
		m_colorSegmentCode = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(11);
		m_colorDigital = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(12);
		m_colorInstruction = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(13);
		m_colorFInstruction = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(14);
		m_colorRegister = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(15);
		m_colorChar = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(16);
		m_colorString = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(17);
		m_colorDefineWord = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(18);
		m_colorMacro = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(19);
		m_colorOperatorTxt = pPropColor->GetColor();
		pPropColor = (CMFCPropertyGridColorProperty*)pPropertySyntaxHighLight->GetSubItem(20);
		m_colorOperator = pPropColor->GetColor();

		//字体
		CMFCPropertyGridProperty* pPropertyFont = m_wndPropertyGrid.GetProperty(2);
		CMFCPropertyGridFontProperty* pPropertyFontTtem = (CMFCPropertyGridFontProperty*)pPropertyFont->GetSubItem(0);
		m_lfTextFont = *pPropertyFontTtem->GetLogFont();

		//左边附加栏
		CMFCPropertyGridProperty* pPropertyExtraColumn = m_wndPropertyGrid.GetProperty(3);
		m_bShowLineNumber = (_variant_t)pPropertyExtraColumn->GetSubItem(0)->GetValue();
		m_bShowBookMarker = (_variant_t)pPropertyExtraColumn->GetSubItem(1)->GetValue();
		m_bShowFold = (_variant_t)pPropertyExtraColumn->GetSubItem(2)->GetValue();

		//左边附加栏
		CMFCPropertyGridProperty* pPropertySave = m_wndPropertyGrid.GetProperty(4);
		m_bAutoSave = (_variant_t)pPropertySave->GetSubItem(0)->GetValue();
	}
}

