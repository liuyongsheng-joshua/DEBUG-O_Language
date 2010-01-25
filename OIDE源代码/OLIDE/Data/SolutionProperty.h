
#ifndef _SOLUTION_PROPERTY_H_
#define _SOLUTION_PROPERTY_H_


#pragma once

#include "./OLXMLProjectData.h"

//��������
class CSolutionProperty
{
public:
	CSolutionProperty(void);
	~CSolutionProperty(void);
};


//��������
class CProjectProperty
{
public:

	CProjectProperty();
	~CProjectProperty();

public:

	enum PROGRAM_TYPE
	{		
		PT_EXE,
		PT_DLL,
		PT_LIB,
		PT_DRIVER,
	};

	CString m_strProjectName;
	CString m_strProjectFilePath;

	CString m_strCodeDir;     //����Ŀ¼
	CString m_strResourceDir; //��ԴĿ¼
	int m_nProgramType;       //�������ͣ�EXE DLL
	int m_nLinkSubSystem;     //������ϵͳ ����̨ ���ڳ���
	CString m_strDebugMiddleOutPutPath;
	CString m_strDebugOutPutFileName;	
	CString m_strReleaseMiddleOutPutPath;
	CString m_strReleaseOutPutFileName;	
	CString m_strDefFileName;

	COLProjectBuildRecord* m_pProjectBuildRecord;
	
private:

	CString m_strProjectFlag;

public:

	void     SetDefaultProjectProperty(const CString& strProjectPath,const CString& strProjectName,int nProjectType);
	CString& GetProjectFlag(){ return m_strProjectFlag; };	
	CString  GetProjectAbsolutePathCodeDir();
	CString  GetProjectAbsolutePathResourceDir();
	CString  GetProjectAbsolutePathMiddleOutPut(bool bDebug);
	CString  GetProjectAbsolutePathOutPutFileName(bool bDebug);
	void     DeleteBuildRecord();
	
private:

	CString GetProjectAbsolutePath(const CString& strPath);

};

#endif //_SOLUTION_PROPERTY_H_