
#include "stdafx.h"
#include "SystemOption.h"
#include ".\olxmlfile.h"

CSystemOption::CSystemOption()
{
	
}

CSystemOption::~CSystemOption()
{
	
}

void CSystemOption::LoadDefault()
{
	//����ѡ��
	m_bUpdateEveryTime = TRUE;

	//�м�����ѡ��
	m_strOMLPath = _T("./oml/OML.exe");
	m_strOMLLanguagePath = _T("./oml/language/default.oic");

	//���ѡ��
	m_strOasmPath = _T("./oasm/OASM.exe");
	m_strOasmLanguagePath = _T("./oasm/language/default.oic");
	
	//����ѡ��
	m_strLinkerFileName = "./oasm/link.exe";
	
	//��ǰ����汾����(���԰�򴿾���)
	m_bIsDebug = true;   //Ĭ�����ɵ��԰�

	//OASM�༭��ѡ��
	m_strOASMSyntaxWordFileName = _T("./oasm/config/syntax_word.ohc");	
	m_strOASMSelectionListFileName = _T("./oasm/config/oasm.ohc");
	m_strOASMTempletDir = _T("./oasm/Template/");	
	m_strOASMAutoCompleteFileName = _T("./oasm/config/auto_complete.ohc");
	m_strOASMTipFileName = _T("./oasm/config/tip.ohc");

	m_colorOASMBackGround   = ::GetSysColor(COLOR_WINDOW);
	m_colorOASMText         = ::GetSysColor(COLOR_WINDOWTEXT);
	m_colorOASMCommentLine  = (RGB(0x00, 0x80, 0x00));
	m_colorOASMCommentBlock = (RGB(0x00, 0x80, 0x00));
	m_colorOASMIncludeText  = (RGB(0x00, 0x80, 0xFF));
	m_colorOASMIncludeLib   = (RGB(0x00, 0x80, 0xFF));
	m_colorOASMSegmentData  = (RGB(0xBB, 0x00, 0x40));
	m_colorOASMSegmentRData = (RGB(0xBB, 0x00, 0x40));
	m_colorOASMSegmentBSS   = (RGB(0xBB, 0x00, 0x40));
	m_colorOASMSegmentExtern= (RGB(0xBB, 0x00, 0x40));
	m_colorOASMSegmentCode  = (RGB(0xBB, 0x00, 0x40));
	m_colorOASMDigital      = (RGB(0x00, 0x80, 0x80));
	m_colorOASMInstruction  = (RGB(0x83, 0x07, 0xF6));
	m_colorOASMFInstruction = (RGB(0x83, 0x07, 0xF6));
	m_colorOASMRegister     = (RGB(0x0F, 0xAC, 0xA6));
	m_colorOASMChar         = (RGB(0xC0, 0x20, 0x00));
	m_colorOASMString       = (RGB(0xC0, 0x20, 0x00));
	m_colorOASMDefineWord   = (RGB(0x25, 0x09, 0xF3));
	m_colorOASMMacro        = (RGB(0x80, 0x00, 0x39));
	m_colorOASMOperatorTxt  = (RGB(0x80, 0x80, 0x00));
	m_colorOASMOperator     = (RGB(0x80, 0x80, 0x00));
	CFont* fontOASM = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	fontOASM->GetLogFont(&m_lfOASMTextFont);		
	lstrcpy(m_lfOASMTextFont.lfFaceName, _T("����"));
	m_bOASMShowLineNumber = TRUE;
	m_bOASMShowBookMarker = TRUE;
	m_bOASMShowFold = TRUE;
	m_bOASMAutoSave = FALSE;

	//OML�༭��ѡ��
	m_strOMLSyntaxWordFileName = _T("./oml/config/syntax_word.ohc");
	m_strOMLSelectionListFileName = _T("./oml/config/oml.ohc");
	m_strOMLTempletDir = _T("./oml/Template/");	
	m_strOMLAutoCompleteFileName = _T("./oml/config/auto_complete.ohc");
	m_strOMLTipFileName = _T("./oml/config/tip.ohc");

	m_colorOMLBackGround   = ::GetSysColor(COLOR_WINDOW);
	m_colorOMLText         = ::GetSysColor(COLOR_WINDOWTEXT);
	m_colorOMLCommentLine  = (RGB(0x00, 0x80, 0x00));
	m_colorOMLCommentBlock = (RGB(0x00, 0x80, 0x00));
	m_colorOMLDigital      = (RGB(0x00, 0x80, 0x80));
	m_colorOMLChar         = (RGB(0xC0, 0x20, 0x00));
	m_colorOMLString       = (RGB(0xC0, 0x20, 0x00));
	m_colorOMLKeyWord      = (RGB(0x25, 0x09, 0xF3));
	m_colorOMLMacro        = (RGB(0x80, 0x00, 0x39));	
	m_colorOMLOperator     = (RGB(0x80, 0x80, 0x00));
	CFont* fontOML = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	fontOML->GetLogFont(&m_lfOMLTextFont);		
	lstrcpy(m_lfOMLTextFont.lfFaceName, _T("����"));
	m_bOMLShowLineNumber = TRUE;
	m_bOMLShowBookMarker = TRUE;
	m_bOMLShowFold = TRUE;
	m_bOMLAutoSave = FALSE;

	//�����ѡ��
	m_strDoasmPath = _T("./oasm/DOASM.exe");
	m_strDoasmLanguagePath = _T("./oasm/language/chinese.oic");
}

void CSystemOption::Load(const CString& strOptionFileName)
{
	#define MAX_NAME_LEN 256
	char chText[MAX_NAME_LEN];

	COLXMLFile xmlFile;
	xmlFile.StrToChar(strOptionFileName,chText,MAX_NAME_LEN);
	if(xmlFile.OpenOLanguageFile(chText) != OFT_SYSTEM_OPTION)
	{
		//�����ѡ���ļ�������ʹ��Ĭ��ѡ��
		LoadDefault();	

		return;
	}

	TiXmlElement* pxmlElementOLanguageFile = xmlFile.GetOLanguageFileElement();

	//�õ�ϵͳѡ��XML���
	TiXmlElement* pxmlSystemOptionNode = pxmlElementOLanguageFile->FirstChildElement(OLXMLKey_SystemOption);
	if(pxmlSystemOptionNode == NULL)
		return;

	TiXmlElement *pXmlElement,*pXmlElementTemp;

	//�õ�����ѡ��
	pXmlElement = pxmlSystemOptionNode->FirstChildElement(OLXMLKey_SystemOptionCommon);	
	if(pXmlElement)
	{	
		//����
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionUpdate);
		if(pXmlElementTemp != NULL)
		{
			m_bUpdateEveryTime = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionUpdateEveryTime);			
		}
	}

	//�õ��м����Ա�������Ϣ
	pXmlElement = pxmlSystemOptionNode->FirstChildElement(OLXMLKey_SystemOptionOMLCompiler);	
	if(pXmlElement)
	{		
		//�м����Ա�����·��
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLCompilerPath);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOMLPath = chText;
		}

		//�м����������ļ�·��
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLLanguagePath);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOMLLanguagePath = chText;
		}		
	}

	//�õ��������Ϣ
	pXmlElement = pxmlSystemOptionNode->FirstChildElement(OLXMLKey_SystemOptionAssembler);	
	if(pXmlElement)
	{		
		//�����·��
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionAssemblerPath);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOasmPath = chText;
		}

		//����·��
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionLanguagePath);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOasmLanguagePath = chText;
		}		
	}

	//�õ���������Ϣ
	pXmlElement = pxmlSystemOptionNode->FirstChildElement(OLXMLKey_SystemOptionLinker);	
	if(pXmlElement)
	{
		//������·��
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionLinkerPath);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strLinkerFileName = chText;
		}		
	}

	//�õ�OASM�༭����Ϣ
	pXmlElement = pxmlSystemOptionNode->FirstChildElement(OLXMLKey_SystemOptionOASMEditor);	
	if(pXmlElement)
	{
		//OASM�﷨���ļ���
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOASMEditorSyntaxWordFileName);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOASMSyntaxWordFileName = chText;
		}

		//ѡ����ļ���
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOASMEditorSelectionListFileName);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOASMSelectionListFileName = chText;
		}

		//ģ��Ŀ¼
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOASMEditorTemplateDir);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOASMTempletDir = chText;
		}		

		//�Զ������ʾ�����ļ���
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOASMEditorAutoCompleteFileName);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOASMAutoCompleteFileName = chText;
		}

		//�ַ���ʾ�����ļ���
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOASMEditorTipFileName);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOASMTipFileName = chText;
		}

		//�﷨��ɫ
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOASMEditorSyntaxColor);
		if(pXmlElementTemp != NULL)
		{
			m_colorOASMBackGround   = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorBackGround);
			m_colorOASMText         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorText);
			m_colorOASMCommentLine  = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorCommentLine);
			m_colorOASMCommentBlock = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorCommentBlock);
			m_colorOASMIncludeText  = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorIncludeText);
			m_colorOASMIncludeLib   = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorIncludeLib);
			m_colorOASMSegmentData  = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentData);
			m_colorOASMSegmentRData = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentRData);
			m_colorOASMSegmentBSS   = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentBSS);
			m_colorOASMSegmentExtern= xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentExtern);
			m_colorOASMSegmentCode  = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentCode);
			m_colorOASMDigital      = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorDigital);
			m_colorOASMInstruction  = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorInstruction);
			m_colorOASMFInstruction = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorFInstruction);
			m_colorOASMRegister     = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorRegister);
			m_colorOASMChar         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorChar);
			m_colorOASMString       = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorString);
			m_colorOASMDefineWord   = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorDefineWord);
			m_colorOASMMacro        = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorMacro);
			m_colorOASMOperatorTxt  = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorOperatorTxt);
			m_colorOASMOperator     = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorSyntaxColorOperator);
		}

		//����
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOASMEditorTextFont);
		if(pXmlElementTemp != NULL)
		{			
			m_lfOASMTextFont.lfHeight         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfHeight); 
			m_lfOASMTextFont.lfWidth          = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfWidth); 
			m_lfOASMTextFont.lfEscapement     = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfEscapement); 
			m_lfOASMTextFont.lfOrientation    = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfOrientation); 
			m_lfOASMTextFont.lfWeight         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfWeight);  
			m_lfOASMTextFont.lfItalic         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfItalic);
			m_lfOASMTextFont.lfUnderline      = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfUnderline);  
			m_lfOASMTextFont.lfStrikeOut      = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfStrikeOut);  
			m_lfOASMTextFont.lfCharSet        = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfCharSet); 
			m_lfOASMTextFont.lfOutPrecision   = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfOutPrecision);
			m_lfOASMTextFont.lfClipPrecision  = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfClipPrecision); 
			m_lfOASMTextFont.lfQuality        = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfQuality); 
			m_lfOASMTextFont.lfPitchAndFamily = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorTextFontlfPitchAndFamily); 			

			if((!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
			{
				strcpy(m_pchOASMFontName,pXmlElementTemp->FirstChild()->Value());

				#ifdef _UNICODE
				CString strTemp;
				strTemp = m_pchOASMFontName;
				wcscpy(m_lfOASMTextFont.lfFaceName,strTemp);
				#else
				strcpy(m_lfOASMTextFont.lfFaceName,m_pchOASMFontName);
				#endif
			}
		}

		//������
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOASMEditorExtraColumn);
		if(pXmlElementTemp != NULL)
		{
			m_bOASMShowLineNumber = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorExtraColumnLineNumber);
			m_bOASMShowBookMarker = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorExtraColumnBookMarker);
			m_bOASMShowFold       = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMEditorExtraColumnFold);
		}		

		//����ѡ��
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOASMSave);
		if(pXmlElementTemp != NULL)
		{
			m_bOASMAutoSave = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOASMAutoSave);			
		}		
	}

	//�õ�OML�༭����Ϣ
	pXmlElement = pxmlSystemOptionNode->FirstChildElement(OLXMLKey_SystemOptionOMLEditor);	
	if(pXmlElement)
	{

		//OML�﷨���ļ���
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLEditorSyntaxWordFileName);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOMLSyntaxWordFileName = chText;
		}

		//ѡ����ļ���
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLEditorSelectionListFileName);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOMLSelectionListFileName = chText;
		}

		//ģ��Ŀ¼
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLEditorTemplateDir);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOMLTempletDir = chText;
		}
		
		//�Զ������ʾ�����ļ���
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLEditorAutoCompleteFileName);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOMLAutoCompleteFileName = chText;
		}

		//�ַ���ʾ�����ļ���
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLEditorTipFileName);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strOMLTipFileName = chText;
		}

		//�﷨��ɫ
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLEditorSyntaxColor);
		if(pXmlElementTemp != NULL)
		{
			m_colorOMLBackGround   = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorBackGround);
			m_colorOMLText         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorText);
			m_colorOMLCommentLine  = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorCommentLine);
			m_colorOMLCommentBlock = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorCommentBlock);
			m_colorOMLDigital      = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorDigital);
			m_colorOMLChar         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorChar);
			m_colorOMLString       = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorString);
			m_colorOMLKeyWord      = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorKeyWord);
			m_colorOMLMacro        = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorMacro);
			m_colorOMLOperator     = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorSyntaxColorOperator);
		}

		//����
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLEditorTextFont);
		if(pXmlElementTemp != NULL)
		{			
			m_lfOMLTextFont.lfHeight         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfHeight); 
			m_lfOMLTextFont.lfWidth          = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfWidth); 
			m_lfOMLTextFont.lfEscapement     = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfEscapement); 
			m_lfOMLTextFont.lfOrientation    = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfOrientation); 
			m_lfOMLTextFont.lfWeight         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfWeight);  
			m_lfOMLTextFont.lfItalic         = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfItalic);
			m_lfOMLTextFont.lfUnderline      = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfUnderline);  
			m_lfOMLTextFont.lfStrikeOut      = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfStrikeOut);  
			m_lfOMLTextFont.lfCharSet        = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfCharSet); 
			m_lfOMLTextFont.lfOutPrecision   = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfOutPrecision);
			m_lfOMLTextFont.lfClipPrecision  = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfClipPrecision); 
			m_lfOMLTextFont.lfQuality        = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfQuality); 
			m_lfOMLTextFont.lfPitchAndFamily = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorTextFontlfPitchAndFamily); 			

			if((!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
			{
				strcpy(m_pchOMLFontName,pXmlElementTemp->FirstChild()->Value());

                #ifdef _UNICODE
				CString strTemp;
				strTemp = m_pchOMLFontName;
				wcscpy(m_lfOMLTextFont.lfFaceName,strTemp);
                #else
				strcpy(m_lfOMLTextFont.lfFaceName,m_pchOMLFontName);
                #endif
			}
		}

		//������
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLEditorExtraColumn);
		if(pXmlElementTemp != NULL)
		{
			m_bOMLShowLineNumber = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorExtraColumnLineNumber);
			m_bOMLShowBookMarker = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorExtraColumnBookMarker);
			m_bOMLShowFold       = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLEditorExtraColumnFold);
		}		

		//����
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionOMLSave);
		if(pXmlElementTemp != NULL)
		{
			m_bOMLAutoSave = xmlFile.GetXmlElementAttributeValue(pXmlElementTemp,OLXMLKey_SystemOptionOMLAutoSave);
		}	
	}

	//�õ����������Ϣ
	pXmlElement = pxmlSystemOptionNode->FirstChildElement(OLXMLKey_SystemOptionDisassembler);	
	if(pXmlElement)
	{		
		//�������·��
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionDiaassemblerPath);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strDoasmPath = chText;
		}

		//���������·��
		pXmlElementTemp = pXmlElement->FirstChildElement(OLXMLKey_SystemOptionDosmLanguagePath);
		if((pXmlElementTemp != NULL) && (!pXmlElementTemp->NoChildren()) && (pXmlElementTemp->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(chText,pXmlElementTemp->FirstChild()->Value());
			m_strDoasmLanguagePath = chText;
		}		
	}

	#undef MAX_NAME_LEN
}

BOOL CSystemOption::Save(const CString& strOptionFileName)
{
	#define MAX_NAME_LEN 256
	char chText[MAX_NAME_LEN];
	
	COLXMLFile xmlFile;
	xmlFile.StrToChar(strOptionFileName,chText,MAX_NAME_LEN);
    if(xmlFile.OpenOLanguageFile(chText) != OFT_SYSTEM_OPTION)
	{
		if(!xmlFile.CreateOLanguageFile(chText,OFT_SYSTEM_OPTION,true))
			return FALSE;

		if(xmlFile.OpenOLanguageFile(chText) != OFT_SYSTEM_OPTION)		
			return FALSE;
	}	

	TiXmlElement* pxmlElementOLanguageFile = xmlFile.GetOLanguageFileElement();
	TiXmlElement* pxmlSystemOptionNode = pxmlElementOLanguageFile->FirstChildElement(OLXMLKey_SystemOption);
	if(pxmlSystemOptionNode)
	{
		pxmlElementOLanguageFile->RemoveChild(pxmlSystemOptionNode);
	}

	//����ϵͳѡ���XML���
	TiXmlElement xmlSystemOptionNode("");
	xmlSystemOptionNode.SetValue(OLXMLKey_SystemOption);
	
	TiXmlElement xmlElement("");
	TiXmlText    xmlText("");
	TiXmlElement* pXmlElement;	

	//����ѡ��
	xmlElement.SetValue(OLXMLKey_SystemOptionCommon);
	pXmlElement = (TiXmlElement*)xmlSystemOptionNode.InsertEndChild(xmlElement);
	//ÿ����������
	xmlElement.SetValue(OLXMLKey_SystemOptionUpdate);
	TiXmlElement* pXmlElementUpdateEveryTime = pXmlElement->InsertEndChild(xmlElement)->ToElement();
	if(pXmlElementUpdateEveryTime)
	{
		pXmlElementUpdateEveryTime->SetAttribute(OLXMLKey_SystemOptionUpdateEveryTime,m_bUpdateEveryTime);		
	}

	//���û������Ϣ
	xmlElement.SetValue(OLXMLKey_SystemOptionAssembler);
	pXmlElement = (TiXmlElement*)xmlSystemOptionNode.InsertEndChild(xmlElement);
	//�����·��
	xmlElement.SetValue(OLXMLKey_SystemOptionAssemblerPath);
	xmlFile.StrToChar(m_strOasmPath,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	//����·��
	xmlElement.SetValue(OLXMLKey_SystemOptionLanguagePath);
	xmlFile.StrToChar(m_strOasmLanguagePath,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	
	//�����м����Ա�������Ϣ
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLCompiler);
	pXmlElement = (TiXmlElement*)xmlSystemOptionNode.InsertEndChild(xmlElement);
	//�м����Ա�����·��
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLCompilerPath);
	xmlFile.StrToChar(m_strOMLPath,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	//�м����������ļ�·��
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLLanguagePath);
	xmlFile.StrToChar(m_strOMLLanguagePath,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);

	//������������Ϣ
	xmlElement.SetValue(OLXMLKey_SystemOptionLinker);
	pXmlElement = (TiXmlElement*)xmlSystemOptionNode.InsertEndChild(xmlElement);
	//������·��
	xmlElement.SetValue(OLXMLKey_SystemOptionLinkerPath);
	xmlFile.StrToChar(m_strLinkerFileName,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);	

	//����OASM�༭����Ϣ
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMEditor);
	pXmlElement = (TiXmlElement*)xmlSystemOptionNode.InsertEndChild(xmlElement);
	//�﷨���ļ���
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMEditorSyntaxWordFileName);
	xmlFile.StrToChar(m_strOASMSyntaxWordFileName,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);	
	//ѡ���б���ļ���
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMEditorSelectionListFileName);
	xmlFile.StrToChar(m_strOASMSelectionListFileName,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	//ģ��Ŀ¼
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMEditorTemplateDir);
	xmlFile.StrToChar(m_strOASMTempletDir,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);	
	//�Զ������ʾ�����ļ���
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMEditorAutoCompleteFileName);
	xmlFile.StrToChar(m_strOASMAutoCompleteFileName,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	//�ַ���ʾ�����ļ���
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMEditorTipFileName);
	xmlFile.StrToChar(m_strOASMTipFileName,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	
	//�﷨��ɫ
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMEditorSyntaxColor);
	TiXmlElement* pXmlElementOASMSyntaxColor = pXmlElement->InsertEndChild(xmlElement)->ToElement();
	if(pXmlElementOASMSyntaxColor)
	{
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorBackGround,m_colorOASMBackGround);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorText,m_colorOASMText);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorCommentLine,m_colorOASMCommentLine);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorCommentBlock,m_colorOASMCommentBlock);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorIncludeText,m_colorOASMIncludeText);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorIncludeLib,m_colorOASMIncludeLib);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentData,m_colorOASMSegmentData);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentRData,m_colorOASMSegmentRData);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentBSS,m_colorOASMSegmentBSS);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentExtern,m_colorOASMSegmentExtern);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentCode,m_colorOASMSegmentCode);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorDigital,m_colorOASMDigital);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorInstruction,m_colorOASMInstruction);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorFInstruction,m_colorOASMFInstruction);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorRegister,m_colorOASMRegister);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorChar,m_colorOASMChar);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorString,m_colorOASMString);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorDefineWord,m_colorOASMDefineWord);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorMacro,m_colorOASMMacro);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorOperatorTxt,m_colorOASMOperatorTxt);
		pXmlElementOASMSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOASMEditorSyntaxColorOperator,m_colorOASMOperator);
	}	

	//�ı�����
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMEditorTextFont);
	TiXmlElement* pXmlElementOASMTextFont = pXmlElement->InsertEndChild(xmlElement)->ToElement();
	if(pXmlElementOASMTextFont)
	{
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfHeight,m_lfOASMTextFont.lfHeight);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfWidth,m_lfOASMTextFont.lfWidth);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfEscapement,m_lfOASMTextFont.lfEscapement);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfOrientation,m_lfOASMTextFont.lfOrientation);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfWeight,m_lfOASMTextFont.lfWeight);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfItalic,m_lfOASMTextFont.lfItalic);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfUnderline,m_lfOASMTextFont.lfUnderline);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfStrikeOut,m_lfOASMTextFont.lfStrikeOut);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfCharSet,m_lfOASMTextFont.lfCharSet);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfOutPrecision,m_lfOASMTextFont.lfOutPrecision);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfClipPrecision,m_lfOASMTextFont.lfClipPrecision);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfQuality,m_lfOASMTextFont.lfQuality);
		pXmlElementOASMTextFont->SetAttribute(OLXMLKey_SystemOptionOASMEditorTextFontlfPitchAndFamily,m_lfOASMTextFont.lfPitchAndFamily);
	
		xmlFile.StrToChar(m_lfOASMTextFont.lfFaceName,m_pchOASMFontName,LF_FACESIZE);
		xmlText.SetValue(m_pchOASMFontName);
		pXmlElementOASMTextFont->InsertEndChild(xmlText);	 
	}

	//������
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMEditorExtraColumn);
	TiXmlElement* pXmlElementOASMExtraColumn = pXmlElement->InsertEndChild(xmlElement)->ToElement();
	if(pXmlElementOASMExtraColumn)
	{
		pXmlElementOASMExtraColumn->SetAttribute(OLXMLKey_SystemOptionOASMEditorExtraColumnLineNumber,m_bOASMShowLineNumber);
		pXmlElementOASMExtraColumn->SetAttribute(OLXMLKey_SystemOptionOASMEditorExtraColumnBookMarker,m_bOASMShowBookMarker);
		pXmlElementOASMExtraColumn->SetAttribute(OLXMLKey_SystemOptionOASMEditorExtraColumnFold,m_bOASMShowFold);
	}

	//����ѡ��
	xmlElement.SetValue(OLXMLKey_SystemOptionOASMSave);
	TiXmlElement* pXmlElementOASMSave = pXmlElement->InsertEndChild(xmlElement)->ToElement();
	if(pXmlElementOASMSave)
	{
		pXmlElementOASMSave->SetAttribute(OLXMLKey_SystemOptionOASMAutoSave,m_bOASMAutoSave);
	}		

	//����OML�༭����Ϣ
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLEditor);
	pXmlElement = (TiXmlElement*)xmlSystemOptionNode.InsertEndChild(xmlElement);
	//�﷨���ļ���
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLEditorSyntaxWordFileName);
	xmlFile.StrToChar(m_strOMLSyntaxWordFileName,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	//ѡ���б���ļ���
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLEditorSelectionListFileName);
	xmlFile.StrToChar(m_strOMLSelectionListFileName,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	//ģ��Ŀ¼
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLEditorTemplateDir);
	xmlFile.StrToChar(m_strOMLTempletDir,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);	
	//�Զ������ʾ�����ļ���
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLEditorAutoCompleteFileName);
	xmlFile.StrToChar(m_strOMLAutoCompleteFileName,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	//�ַ���ʾ�����ļ���
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLEditorTipFileName);
	xmlFile.StrToChar(m_strOMLTipFileName,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);

	//�﷨��ɫ
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLEditorSyntaxColor);
	TiXmlElement* pXmlElementOMLSyntaxColor = pXmlElement->InsertEndChild(xmlElement)->ToElement();
	if(pXmlElementOMLSyntaxColor)
	{
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorBackGround,m_colorOMLBackGround);
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorText,m_colorOMLText);
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorCommentLine,m_colorOMLCommentLine);
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorCommentBlock,m_colorOMLCommentBlock);
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorDigital,m_colorOMLDigital);
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorChar,m_colorOMLChar);
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorString,m_colorOMLString);
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorKeyWord,m_colorOMLKeyWord);
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorMacro,m_colorOMLMacro);
		pXmlElementOMLSyntaxColor->SetAttribute(OLXMLKey_SystemOptionOMLEditorSyntaxColorOperator,m_colorOMLOperator);
	}	

	//�ı�����
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLEditorTextFont);
	TiXmlElement* pXmlElementOMLTextFont = pXmlElement->InsertEndChild(xmlElement)->ToElement();
	if(pXmlElementOMLTextFont)
	{
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfHeight,m_lfOMLTextFont.lfHeight);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfWidth,m_lfOMLTextFont.lfWidth);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfEscapement,m_lfOMLTextFont.lfEscapement);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfOrientation,m_lfOMLTextFont.lfOrientation);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfWeight,m_lfOMLTextFont.lfWeight);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfItalic,m_lfOMLTextFont.lfItalic);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfUnderline,m_lfOMLTextFont.lfUnderline);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfStrikeOut,m_lfOMLTextFont.lfStrikeOut);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfCharSet,m_lfOMLTextFont.lfCharSet);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfOutPrecision,m_lfOMLTextFont.lfOutPrecision);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfClipPrecision,m_lfOMLTextFont.lfClipPrecision);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfQuality,m_lfOMLTextFont.lfQuality);
		pXmlElementOMLTextFont->SetAttribute(OLXMLKey_SystemOptionOMLEditorTextFontlfPitchAndFamily,m_lfOMLTextFont.lfPitchAndFamily);

		xmlFile.StrToChar(m_lfOMLTextFont.lfFaceName,m_pchOMLFontName,LF_FACESIZE);
		xmlText.SetValue(m_pchOMLFontName);
		pXmlElementOMLTextFont->InsertEndChild(xmlText);	 
	}

	//������
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLEditorExtraColumn);
	TiXmlElement* pXmlElementOMLExtraColumn = pXmlElement->InsertEndChild(xmlElement)->ToElement();
	if(pXmlElementOMLExtraColumn)
	{
		pXmlElementOMLExtraColumn->SetAttribute(OLXMLKey_SystemOptionOMLEditorExtraColumnLineNumber,m_bOMLShowLineNumber);
		pXmlElementOMLExtraColumn->SetAttribute(OLXMLKey_SystemOptionOMLEditorExtraColumnBookMarker,m_bOMLShowBookMarker);
		pXmlElementOMLExtraColumn->SetAttribute(OLXMLKey_SystemOptionOMLEditorExtraColumnFold,m_bOMLShowFold);
	}

	//����ѡ��
	xmlElement.SetValue(OLXMLKey_SystemOptionOMLSave);
	TiXmlElement* pXmlElementOMLSave = pXmlElement->InsertEndChild(xmlElement)->ToElement();
	if(pXmlElementOMLSave)
	{
		pXmlElementOMLSave->SetAttribute(OLXMLKey_SystemOptionOMLAutoSave,m_bOMLAutoSave);
	}	

	//���÷��������Ϣ
	xmlElement.SetValue(OLXMLKey_SystemOptionDisassembler);
	pXmlElement = (TiXmlElement*)xmlSystemOptionNode.InsertEndChild(xmlElement);
	//�������·��
	xmlElement.SetValue(OLXMLKey_SystemOptionDiaassemblerPath);
	xmlFile.StrToChar(m_strDoasmPath,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	//���������·��
	xmlElement.SetValue(OLXMLKey_SystemOptionDosmLanguagePath);
	xmlFile.StrToChar(m_strDoasmLanguagePath,chText,MAX_NAME_LEN);
	xmlText.SetValue(chText);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);


	pxmlElementOLanguageFile->InsertEndChild(xmlSystemOptionNode);

	#undef MAX_NAME_LEN

	return xmlFile.SaveFile();
}