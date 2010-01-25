// DlgEditOption.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OLIDE.h"
#include "DlgOasmEditOption.h"


// CDlgOasmEditOption �Ի���

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


// CDlgOasmEditOption ��Ϣ�������

BOOL CDlgOasmEditOption::OnInitDialog()
{
	CResizablePage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	if(m_wndPropertyGrid.GetSafeHwnd() == 0)
	{
		if (!m_wndPropertyGrid.Create(WS_VISIBLE | WS_CHILD, CRect(0, 0, 0, 0), this, 2))
		{
			TRACE0("δ�ܴ�����������\n");
			return FALSE;      // δ�ܴ���
		}
		m_wndPropertyGrid.SetOwner(this);

		m_wndPropertyGrid.EnableHeaderCtrl(FALSE);
		m_wndPropertyGrid.EnableDescriptionArea();
		m_wndPropertyGrid.SetVSDotNetLook();
		m_wndPropertyGrid.MarkModifiedProperties();

		//����������ʾ·��
		CMFCPropertyGridProperty* pPropertyHintFile = new CMFCPropertyGridProperty(_T("�༭�����ļ�"));
		static TCHAR BASED_CODE szFilter[] = _T("��ʾ�ļ�(*.ohc)|*.ohc|�����ļ�(*.*)|*.*||");
		CMFCPropertyGridFileProperty* pPropertySyntaxWordFileName= new CMFCPropertyGridFileProperty(_T("�﷨���ļ�"), TRUE, _T(""), _T("ohc"), 0, szFilter, _T("�﷨�������ļ�"));
		pPropertySyntaxWordFileName->SetValue(COleVariant(m_strOASMSyntaxWordFileName));
		pPropertyHintFile->AddSubItem(pPropertySyntaxWordFileName);
		CMFCPropertyGridFileProperty* pPropertySelectionListFile = new CMFCPropertyGridFileProperty(_T("ѡ���б��ļ�"), TRUE, _T(""), _T("ohc"), 0, szFilter, _T("ѡ���б������ļ�"));
		pPropertySelectionListFile->SetValue(COleVariant(m_strSelectionListFileName));
		pPropertyHintFile->AddSubItem(pPropertySelectionListFile);
		pPropertyHintFile->AddSubItem(new CMFCPropertyGridFileProperty(_T("ģ���ļ�Ŀ¼"), m_strOASMTempletDir,0,_T("����ģ���ļ����ڵ�Ŀ¼")));
		CMFCPropertyGridFileProperty* pPropertyAutoCompleteFile = new CMFCPropertyGridFileProperty(_T("������ʾ�ļ�"), TRUE, _T(""), _T("ohc"), 0, szFilter, _T("�����Զ������ʾ�����ļ�"));
		pPropertyAutoCompleteFile->SetValue(COleVariant(m_strOASMAutoCompleteFileName));
		pPropertyHintFile->AddSubItem(pPropertyAutoCompleteFile);
		CMFCPropertyGridFileProperty* pPropertyTipFile = new CMFCPropertyGridFileProperty(_T("��ʾ��Ϣ�ļ�"), TRUE, _T(""), _T("ohc"), 0, szFilter, _T("��ʾ��Ϣ�����ļ�"));
		pPropertyTipFile->SetValue(COleVariant(m_strOASMTipFileName));
		pPropertyHintFile->AddSubItem(pPropertyTipFile);

		m_wndPropertyGrid.AddProperty(pPropertyHintFile);

		COLORREF colorDefaultBackGround = ::GetSysColor(COLOR_WINDOW);
		COLORREF colorDefaultText = ::GetSysColor(COLOR_WINDOWTEXT);

		//�����﷨��ɫ	
		CMFCPropertyGridProperty* pPropertySyntaxHighLight = new CMFCPropertyGridProperty(_T("�﷨��ɫ"));
		CMFCPropertyGridColorProperty* pPropColor = NULL;
		#define SyntaxHighLightAddSubItem(name,color,default_color,description)  \
		pPropColor = new CMFCPropertyGridColorProperty(name, color, NULL, description); \
		pPropColor->EnableOtherButton(_T("����...")); \
		pPropColor->EnableAutomaticButton(_T("Ĭ��"), default_color); \
		pPropertySyntaxHighLight->AddSubItem(pPropColor);

		SyntaxHighLightAddSubItem((_T("������ɫ")),       m_colorBackGround,    (colorDefaultBackGround),(_T("Ĭ�ϵı�����ɫ")));
		SyntaxHighLightAddSubItem((_T("�ı���ɫ")),       m_colorText,          (colorDefaultText),      (_T("Ĭ�ϵ��ı���ɫ")));
		SyntaxHighLightAddSubItem((_T("ע������ɫ")),     m_colorCommentLine,   (RGB(0x00, 0x80, 0x00)), (_T("ע���е��ı���ɫ")));
		SyntaxHighLightAddSubItem((_T("ע�Ϳ���ɫ")),     m_colorCommentBlock,  (RGB(0x00, 0x80, 0x00)), (_T("ע�Ϳ���ı���ɫ")));
		SyntaxHighLightAddSubItem((_T("��������ɫ")),     m_colorIncludeText,   (RGB(0x00, 0x80, 0xFF)), (_T("�����ĵ��ı���ɫ")));
		SyntaxHighLightAddSubItem((_T("���ÿ���ɫ")),     m_colorIncludeLib,    (RGB(0x00, 0x80, 0xFF)), (_T("���ÿ���ı���ɫ")));
		SyntaxHighLightAddSubItem((_T("���ݶα����ɫ")), m_colorSegmentData,   (RGB(0xBB, 0x00, 0x40)), (_T("���ݶα�Ƿ��ŵ���ɫ")));
		SyntaxHighLightAddSubItem((_T("ֻ���α����ɫ")), m_colorSegmentRData,  (RGB(0xBB, 0x00, 0x40)), (_T("ֻ���α�Ƿ��ŵ���ɫ")));
		SyntaxHighLightAddSubItem((_T("Ԥ���α����ɫ")), m_colorSegmentBSS,    (RGB(0xBB, 0x00, 0x40)), (_T("Ԥ���α�Ƿ��ŵ���ɫ")));
		SyntaxHighLightAddSubItem((_T("�ⲿ�α����ɫ")), m_colorSegmentExtern, (RGB(0xBB, 0x00, 0x40)), (_T("�ⲿ�α�Ƿ��ŵ���ɫ")));
		SyntaxHighLightAddSubItem((_T("����α����ɫ")), m_colorSegmentCode,   (RGB(0xBB, 0x00, 0x40)), (_T("����α�Ƿ��ŵ���ɫ")));
		SyntaxHighLightAddSubItem((_T("������ɫ")),       m_colorDigital,       (RGB(0x00, 0x80, 0x80)), (_T("�����ַ�����ɫ")));
		SyntaxHighLightAddSubItem((_T("ָ����ɫ")),       m_colorInstruction,   (RGB(0x83, 0x07, 0xF6)), (_T("ָ���ַ�����ɫ")));
		SyntaxHighLightAddSubItem((_T("����ָ����ɫ")),   m_colorFInstruction,  (RGB(0x83, 0x07, 0xF6)), (_T("����ָ���ַ�����ɫ")));
		SyntaxHighLightAddSubItem((_T("�Ĵ�����ɫ")),     m_colorRegister,      (RGB(0x0F, 0xAC, 0xA6)), (_T("�Ĵ����ַ�����ɫ")));
		SyntaxHighLightAddSubItem((_T("���ַ���ɫ")),     m_colorChar,          (RGB(0xC0, 0x20, 0x00)), (_T("���ַ�����ɫ")));
		SyntaxHighLightAddSubItem((_T("�ַ�����ɫ")),     m_colorString,        (RGB(0xC0, 0x20, 0x00)), (_T("�ַ�������ɫ")));
		SyntaxHighLightAddSubItem((_T("��������ɫ")),     m_colorDefineWord,    (RGB(0x25, 0x09, 0xF3)), (_T("�����ֵ���ɫ")));
		SyntaxHighLightAddSubItem((_T("���ʶ����ɫ")),   m_colorMacro,         (RGB(0x80, 0x00, 0x39)), (_T("���ʶ������ɫ")));
		SyntaxHighLightAddSubItem((_T("�ı���������ɫ")), m_colorOperatorTxt,   (RGB(0x80, 0x80, 0x00)), (_T("�ı�����������ɫ")));
		SyntaxHighLightAddSubItem((_T("��������ɫ")),     m_colorOperator,      (RGB(0x80, 0x80, 0x00)), (_T("����������ɫ")));
		
		#undef SyntaxHighLightAddSubItem
		m_wndPropertyGrid.AddProperty(pPropertySyntaxHighLight);

		//����
		CMFCPropertyGridProperty* pPropertyFont = new CMFCPropertyGridProperty(_T("����"));		
		pPropertyFont->AddSubItem(new CMFCPropertyGridFontProperty(_T("�ı�����"), m_lfTextFont, CF_EFFECTS | CF_SCREENFONTS, _T("ָ���ı�����")));
		m_wndPropertyGrid.AddProperty(pPropertyFont);

		//��߸�����
		CMFCPropertyGridProperty* pPropertyExtraColumn = new CMFCPropertyGridProperty(_T("������"));
		pPropertyExtraColumn->AddSubItem(new CMFCPropertyGridProperty(_T("��ʾ�к�"), (_variant_t)(m_bShowLineNumber?true:false), _T("��ʾ�к�")));
		pPropertyExtraColumn->AddSubItem(new CMFCPropertyGridProperty(_T("��ʾ��ǩ"), (_variant_t)(m_bShowBookMarker?true:false), _T("��ʾ��ǩ��")));
		pPropertyExtraColumn->AddSubItem(new CMFCPropertyGridProperty(_T("��ʾ�۵�"), (_variant_t)(m_bShowFold?true:false), _T("��ʾ�۵���")));
		m_wndPropertyGrid.AddProperty(pPropertyExtraColumn);

		//����
		CMFCPropertyGridProperty* pPropertySave = new CMFCPropertyGridProperty(_T("����"));
		pPropertySave->AddSubItem(new CMFCPropertyGridProperty(_T("�Զ�����"), (_variant_t)(m_bAutoSave?true:false), _T("�ĵ����޸ĺ�10���Զ�����")));
		m_wndPropertyGrid.AddProperty(pPropertySave);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgOasmEditOption::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

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

		//����
		CMFCPropertyGridProperty* pPropertyFont = m_wndPropertyGrid.GetProperty(2);
		CMFCPropertyGridFontProperty* pPropertyFontTtem = (CMFCPropertyGridFontProperty*)pPropertyFont->GetSubItem(0);
		m_lfTextFont = *pPropertyFontTtem->GetLogFont();

		//��߸�����
		CMFCPropertyGridProperty* pPropertyExtraColumn = m_wndPropertyGrid.GetProperty(3);
		m_bShowLineNumber = (_variant_t)pPropertyExtraColumn->GetSubItem(0)->GetValue();
		m_bShowBookMarker = (_variant_t)pPropertyExtraColumn->GetSubItem(1)->GetValue();
		m_bShowFold = (_variant_t)pPropertyExtraColumn->GetSubItem(2)->GetValue();

		//��߸�����
		CMFCPropertyGridProperty* pPropertySave = m_wndPropertyGrid.GetProperty(4);
		m_bAutoSave = (_variant_t)pPropertySave->GetSubItem(0)->GetValue();
	}
}

