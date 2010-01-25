
//����O����XML�ļ�����ʹ�õ��Ľ�㽡����

#ifndef _OL_XML_KEYFILE_H_
#define _OL_XML_KEYFILE_H_


//O�����ļ�����
enum OLANGUAGE_FILE_TYPE
{
	OFT_UNKNOW,
	OFT_SOLUTION,
	OFT_PROJECT,
	OFT_SYSTEM_OPTION,        //ϵͳѡ��
	OFT_BUILD_PROJECT_RECORD  //���빤�̼�¼
};

static const char*  OLXMLKey_OLanguageHead                    = "<?xml version=\"1.0\" encoding=\"GB2312\"?>";
static const char*  OLXMLKey_OLanguageFile                    = "O�����ļ�";
static const char*  OLXMLKey_FileType                         = "TYPE";

//�����빤��
static const char*  OLXMLKey_SolutionName                     = "��������";
static const char*  OLXMLKey_ProjectFile                      = "�����ļ�";
static const char*  OLXMLKey_Project                          = "����";
static const char*  OLXMLKey_ProjectName                      = "��������";
static const char*  OLXMLKey_ProjectPath                      = "����·��";
static const char*  OLXMLKey_ProjectTreeNodeExpandState       = "���������չ��״̬";
static const char*  OLXMLKey_ProjectIncludeFile               = "���̰����ļ�";
static const char*  OLXMLKey_ProjectChildFile                 = "�������ļ�";
static const char*  OLXMLKey_ProjectChildFileType             = "�������ļ�����";
static const char*  OLXMLKey_ProjectChildFilePath             = "�������ļ�·��";
static const char*  OLXMLKey_ProjectProperty                  = "��������";
static const char*  OLXMLKey_ProjectPropertyLinker            = "������";
static const char*  OLXMLKey_ProjectPropertyCodeDir           = "����Ŀ¼";
static const char*  OLXMLKey_ProjectPropertyResourceDir       = "��ԴĿ¼";
static const char*  OLXMLKey_ProjectPropertyProgramType       = "��������";
static const char*  OLXMLKey_ProjectPropertySubSystem         = "��ϵͳ";
static const char*  OLXMLKey_ProjectPropertyOutPutPath        = "���Ŀ¼";
static const char*  OLXMLKey_ProjectPropertyDebugMiddleOutPutPath    = "�����м��ļ����Ŀ¼";
static const char*  OLXMLKey_ProjectPropertyDebugOutPutFileName      = "����ִ���ļ�·��";
static const char*  OLXMLKey_ProjectPropertyReleaseMiddleOutPutPath  = "�����м��ļ����Ŀ¼";
static const char*  OLXMLKey_ProjectPropertyReleaseOutPutFileName    = "����ִ���ļ�·��";
static const char*  OLXMLKey_ProjectPropertyBuildRecord            = "���ɼ�¼";
static const char*  OLXMLKey_ProjectPropertyBuildRecordItem        = "���ɼ�¼��";
static const char*  OLXMLKey_ProjectPropertyBuildFileName          = "�����ļ���";
static const char*  OLXMLKey_ProjectPropertyBuildFileTime          = "�����ļ�ʱ��";
static const char*  OLXMLKey_ProjectPropertyBuildObjFileTime       = "����Ŀ���ļ�ʱ��";
static const char*  OLXMLKey_TreeNodeExpandState              = "�����չ��״̬";

//ϵͳѡ��
static const char*  OLXMLKey_SystemOption                     = "ϵͳѡ��";
static const char*  OLXMLKey_SystemOptionCommon               = "������";
static const char*  OLXMLKey_SystemOptionUpdate               = "����";
static const char*  OLXMLKey_SystemOptionUpdateEveryTime      = "ÿ����������";
static const char*  OLXMLKey_SystemOptionAssembler            = "�����";
static const char*  OLXMLKey_SystemOptionAssemblerPath        = "�����·��";
static const char*  OLXMLKey_SystemOptionLanguagePath         = "����·��";
static const char*  OLXMLKey_SystemOptionLinker               = "������";
static const char*  OLXMLKey_SystemOptionLinkerPath           = "������·��";
static const char*  OLXMLKey_SystemOptionOASMEditor               = "OASM�༭��";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxWordFileName = "OASM�﷨���ļ���";
static const char*  OLXMLKey_SystemOptionOASMEditorSelectionListFileName = "OASMѡ���б���ļ���";
static const char*  OLXMLKey_SystemOptionOASMEditorTemplateDir = "OASMģ��Ŀ¼";
static const char*  OLXMLKey_SystemOptionOASMEditorAutoCompleteFileName = "OASM�Զ���������ļ���";
static const char*  OLXMLKey_SystemOptionOASMEditorTipFileName    = "OASM��ʾ�����ļ���";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColor    = "OASM�﷨��ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorBackGround = "OASM������ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorText = "OASM�ı���ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorCommentLine = "OASMע������ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorCommentBlock = "OASMע�Ϳ���ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorIncludeText = "OASM��������ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorIncludeLib = "OASM���ÿ���ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentData = "OASM���ݶα����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentRData = "OASMֻ���α����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentBSS = "OASMԤ���α����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentExtern = "OASM�ⲿ�α����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorSegmentCode = "OASM����α����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorDigital = "OASM������ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorInstruction = "OASMָ����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorFInstruction = "OASM����ָ����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorRegister = "OASM�Ĵ�����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorChar = "OASM���ַ���ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorString = "OASM�ַ�����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorDefineWord = "OASM���嶨��ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorMacro = "OASM���ʶ����ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorOperatorTxt = "OASM�ı���������ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorSyntaxColorOperator = "OASM��������ɫ";
static const char*  OLXMLKey_SystemOptionOASMEditorTextFont        = "OASM�ı�����";
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfHeight = "OASMlfHeight"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfWidth = "OASMlfWidth" ;
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfEscapement = "OASMlfEscapement"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfOrientation = "OASMlfOrientation"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfWeight = "OASMlfWeight"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfItalic = "OASMItalic"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfUnderline = "OASMlfUnderline"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfStrikeOut = "OASMlfStrikeOut"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfCharSet = "OASMlfCharSet"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfOutPrecision = "OASMlfOutPrecision"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfClipPrecision = "OASMlfClipPrecision"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfQuality = "OASMlfQuality"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfPitchAndFamily = "OASMlfPitchAndFamily"; 
static const char*  OLXMLKey_SystemOptionOASMEditorTextFontlfFaceName = "OASMlfFaceName"; 
static const char*  OLXMLKey_SystemOptionOASMEditorExtraColumn        = "OASM������";
static const char*  OLXMLKey_SystemOptionOASMEditorExtraColumnLineNumber  = "OASM�к�";
static const char*  OLXMLKey_SystemOptionOASMEditorExtraColumnBookMarker  = "OASM��ǩ";
static const char*  OLXMLKey_SystemOptionOASMEditorExtraColumnFold  = "OASM�۵�";
static const char*  OLXMLKey_SystemOptionOASMSave  = "OASM����";
static const char*  OLXMLKey_SystemOptionOASMAutoSave  = "OASM�Զ�����";

static const char*  OLXMLKey_SystemOptionOMLEditor               = "OML�༭��";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxWordFileName = "OML�﷨���ļ���";
static const char*  OLXMLKey_SystemOptionOMLEditorSelectionListFileName = "OMLѡ���б���ļ���";
static const char*  OLXMLKey_SystemOptionOMLEditorTemplateDir = "OMLģ��Ŀ¼";
static const char*  OLXMLKey_SystemOptionOMLEditorAutoCompleteFileName = "OML�Զ���������ļ���";
static const char*  OLXMLKey_SystemOptionOMLEditorTipFileName    = "OML��ʾ�����ļ���";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColor    = "OML�﷨��ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorBackGround = "OML������ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorText = "OML�ı���ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorCommentLine = "OMLע������ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorCommentBlock = "OMLע�Ϳ���ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorDigital = "OML������ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorChar = "OML���ַ���ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorString = "OML�ַ�����ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorKeyWord = "OML�ؼ�����ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorMacro = "OML���ʶ����ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorSyntaxColorOperator = "OML��������ɫ";
static const char*  OLXMLKey_SystemOptionOMLEditorTextFont        = "OML�ı�����";
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfHeight = "OMLlfHeight"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfWidth = "OMLlfWidth" ;
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfEscapement = "OMLlfEscapement"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfOrientation = "OMLlfOrientation"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfWeight = "OMLlfWeight"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfItalic = "OMLItalic"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfUnderline = "OMLlfUnderline"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfStrikeOut = "OMLlfStrikeOut"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfCharSet = "OMLlfCharSet"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfOutPrecision = "OMLlfOutPrecision"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfClipPrecision = "OMLlfClipPrecision"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfQuality = "OMLlfQuality"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfPitchAndFamily = "OMLlfPitchAndFamily"; 
static const char*  OLXMLKey_SystemOptionOMLEditorTextFontlfFaceName = "OMLlfFaceName"; 
static const char*  OLXMLKey_SystemOptionOMLEditorExtraColumn        = "OML������";
static const char*  OLXMLKey_SystemOptionOMLEditorExtraColumnLineNumber  = "OML�к�";
static const char*  OLXMLKey_SystemOptionOMLEditorExtraColumnBookMarker  = "OML��ǩ";
static const char*  OLXMLKey_SystemOptionOMLEditorExtraColumnFold  = "OML�۵�";
static const char*  OLXMLKey_SystemOptionOMLSave  = "OML����";
static const char*  OLXMLKey_SystemOptionOMLAutoSave  = "OML�Զ�����";

static const char*  OLXMLKey_SystemOptionDisassembler            = "�����";
static const char*  OLXMLKey_SystemOptionDiaassemblerPath        = "�������·��";
static const char*  OLXMLKey_SystemOptionDosmLanguagePath        = "���������·��";

//�м�����
static const char*  OLXMLKey_SystemOptionOMLCompiler             = "�м����Ա�����";
static const char*  OLXMLKey_SystemOptionOMLCompilerPath         = "�м����Ա�����·��";
static const char*  OLXMLKey_SystemOptionOMLLanguagePath         = "�м����������ļ�·��";


#endif //_OL_XML_KEYFILE_H_