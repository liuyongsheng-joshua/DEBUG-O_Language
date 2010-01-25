
#ifndef _SYSTEM_OPTION_H_
#define _SYSTEM_OPTION_H_

class CSystemOption
{
public:
	CSystemOption();
	~CSystemOption();

	//����ѡ��
	bool m_bUpdateEveryTime;

	//�м�����ѡ��
	CString m_strOMLPath;
	CString m_strOMLLanguagePath;

	//���ѡ��
	CString m_strOasmPath;
	CString m_strOasmLanguagePath;	

	//����ѡ��
	CString m_strLinkerFileName;
	
	//��ǰ����汾����(���԰�򴿾���)
	bool m_bIsDebug;

	//OASM�༭��ѡ��
	CString m_strOASMSyntaxWordFileName;	
	CString m_strOASMSelectionListFileName;
	CString m_strOASMTempletDir;	
	CString m_strOASMAutoCompleteFileName;
	CString m_strOASMTipFileName;
	COLORREF m_colorOASMBackGround;
	COLORREF m_colorOASMText;
	COLORREF m_colorOASMCommentLine;
	COLORREF m_colorOASMCommentBlock;
	COLORREF m_colorOASMIncludeText;
	COLORREF m_colorOASMIncludeLib;
	COLORREF m_colorOASMSegmentData;
	COLORREF m_colorOASMSegmentRData;
	COLORREF m_colorOASMSegmentBSS;
	COLORREF m_colorOASMSegmentExtern;
	COLORREF m_colorOASMSegmentCode;
	COLORREF m_colorOASMDigital;
	COLORREF m_colorOASMInstruction;
	COLORREF m_colorOASMFInstruction;
	COLORREF m_colorOASMRegister;
	COLORREF m_colorOASMChar;
	COLORREF m_colorOASMString;
	COLORREF m_colorOASMDefineWord;
	COLORREF m_colorOASMMacro;
	COLORREF m_colorOASMOperatorTxt;
	COLORREF m_colorOASMOperator;
	LOGFONT m_lfOASMTextFont;
	char m_pchOASMFontName[LF_FACESIZE];
	BOOL m_bOASMShowLineNumber;
	BOOL m_bOASMShowBookMarker;
	BOOL m_bOASMShowFold;	
	BOOL m_bOASMAutoSave;

	//OML�༭��ѡ��
	CString m_strOMLSyntaxWordFileName;
	CString m_strOMLSelectionListFileName;
	CString m_strOMLTempletDir;	
	CString m_strOMLAutoCompleteFileName;
	CString m_strOMLTipFileName;
	COLORREF m_colorOMLBackGround;
	COLORREF m_colorOMLText;
	COLORREF m_colorOMLCommentLine;
	COLORREF m_colorOMLCommentBlock;
	COLORREF m_colorOMLDigital;
	COLORREF m_colorOMLChar;
	COLORREF m_colorOMLString;
	COLORREF m_colorOMLKeyWord;
	COLORREF m_colorOMLMacro;
	COLORREF m_colorOMLOperator;
	LOGFONT m_lfOMLTextFont;
	char m_pchOMLFontName[LF_FACESIZE];
	BOOL m_bOMLShowLineNumber;
	BOOL m_bOMLShowBookMarker;
	BOOL m_bOMLShowFold;
	BOOL m_bOMLAutoSave;

	//�����ѡ��
	CString m_strDoasmPath;
	CString m_strDoasmLanguagePath;

	void LoadDefault();
	void Load(const CString& strOptionFileName);
	BOOL Save(const CString& strOptionFileName);
};

#endif  //_SYSTEM_OPTION_H_