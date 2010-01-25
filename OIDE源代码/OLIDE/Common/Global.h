
#ifndef _OL_IDE_GLOBAL_H_
#define _OL_IDE_GLOBAL_H_

//�Զ�����Ϣ


//���������������
enum NEW_ITEM_TYPE
{
	NEW_ITEM_TYPE_NULL                    =    NULL,
	NEW_ITEM_TYPE_SOLUCTION               =    100,
	NEW_ITEM_TYPE_PROJECT_WIN32_WINDOWS   =    101,
	NEW_ITEM_TYPE_PROJECT_WIN32_CONSOLE   =    102,
	NEW_ITEM_TYPE_PROJECT_WIN32_DLL       =    103,
	NEW_ITEM_TYPE_PROJECT_WIN32_LIB       =    104,
	NEW_ITEM_TYPE_PROJECT_OML_CODE_FILE   =    105,
	NEW_ITEM_TYPE_PROJECT_OML_HEAD_FILE   =    106,
	NEW_ITEM_TYPE_PROJECT_OASM_CODE_FILE  =    107,
	NEW_ITEM_TYPE_PROJECT_OASM_HEAD_FILE  =    108,
};


//������붨��
const int ERROR_OVS_MANAGER_OLANGUAGE_FILE_OPEN_FILE_NAME_EMPTY                               = -10000;  //��O�����ļ�ʱ�ļ���Ϊ��
const int ERROR_OVS_MANAGER_OLANGUAGE_FILE_OPEN_OPEN_FILE_FAIL                                = -10001;  //��O�����ļ�ʱ���ļ�ʧ��
const int ERROR_OVS_MANAGER_OLANGUAGE_FILE_OPEN_LOAD_XML_FILE_FAIL                            = -10002;  //��O�����ļ�ʱ����XML�ļ�ʧ��
const int ERROR_OVS_MANAGER_OLANGUAGE_FILE_OPEN_OLANGUAGE_FILE_INVALID                        = -10003;  //��O�����ļ�ʱO�����ļ��Ƿ�
const int ERROR_OVS_MANAGER_OLANGUAGE_FILE_ADD_PROJECT_TO_SOLUTION_GET_RELATIVE_PATH_FAIL     = -10004;  //��ӹ��̵�����ʱ�õ������ļ�����ڷ����ļ������·��ʧ��
const int ERROR_OVS_MANAGER_OLANGUAGE_FILE_ADD_OBJECT_FILE_TO_PROJECT_GET_RELATIVE_PATH_FAIL  = -10005;  //��Ӷ����ļ�������ʱ�õ������ļ�����ڹ����ļ������·��ʧ��
const int ERROR_OVS_MANAGER_OLANGUAGE_FILE_GET_OBJECT_FROM_SOLUTION_GET_ABSOLUTE_PATH_FAIL    = -10006;  //�ӷ����ļ��еõ�����ʱ������ڷ����ļ����Ĺ����ļ���ת���ɾ��Թ����ļ���ʱʧ��
const int ERROR_OVS_MANAGER_OLANGUAGE_FILE_GET_FILE_FROM_PROJECT_GET_ABSOLUTE_PATH_FAIL       = -10007;  //�ӹ����ļ��еõ��ļ�ʱ������ڹ����ļ������ļ���ת���ɾ����ļ���ʱʧ��

//ȫ�ֺ���

bool FileExist(const TCHAR* pchFileName,bool bDirectory=false);
bool GetRelativePath(const CString& strFirstPath,CString& strSecondPath);
bool GetAbsolutePath(const CString& strFirstFileName,CString& strSecondFileName);
bool IsRelativePath(const CString& strPath);
//CString GetTitleFromPathName(const CString& strPathName);
CString GetPathFromPathName(const CString& strPathName);
CString GetFileExternName(const CString& strFileName);
CString GetFileNameFromPathName(const CString& strPathName,BOOL bContainExtendName=TRUE);
void CreateDepthDirectory(const CString& strDirectory);
bool FileRename(const TCHAR* pchOldName, const TCHAR* pchNewName);
BOOL DeleteFolderOrFile(LPCTSTR pszPath, BOOL bDelete/*=FALSE*/);
int  CopyFloderOrFile(LPCTSTR lpszPathFrom,LPCTSTR lpszPathTo,BOOL bMove = FALSE);

int  GetOSVersion(void);

#endif //_OL_IDE_GLOBAL_H_