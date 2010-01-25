#pragma once

#include "../../OLangue/syserrorattr.h"

//������ӿ�
typedef int (* GETERRORCOUNT)();
typedef void (* CLEARERRORTABLE)();
typedef SYS_ERROR_POSITION (* GETFIRSTSYSERROR)();
typedef SYS_ERROR_POSITION (* GETENDSYSERROR)();
typedef void (* GETSYSERRORATTR)(SYS_ERROR_POSITION&,int&,char*,char*,char*,char*,char*);


//CErrorInfo��
class CErrorInfo
{
	//�๹��
public:
	CErrorInfo();
	~CErrorInfo();

	//������
	int     m_nErrorCode;
	CString m_strErrorCodeInfo;
	CString m_strErrorSymbol;
	CString m_strErrorOwner;
	CString m_strErrorFileName;
	CString m_strConflictOwner;
};

class CErrorTableOper
{
public:
	CErrorTableOper(void);
	~CErrorTableOper(void);

public:

	//������
	static int  GetErrorCount();
	static void ClearErrorTable();
	static SYS_ERROR_POSITION GetFirstSysError();
	static SYS_ERROR_POSITION GetEndSysError();
	static void GetSysErrorAttr(SYS_ERROR_POSITION& posSysError,CErrorInfo& errorInfo);
};


