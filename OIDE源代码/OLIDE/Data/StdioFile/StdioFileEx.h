
#ifndef _STDIO_FILE_EX_H_
#define _STDIO_FILE_EX_H_

class CStdioFileEx : public CStdioFile
{
public:
	CStdioFileEx();
	~CStdioFileEx();

private:

	void Str2Unicode(CString &str);

public:

	//��ȡһ�У����chIgnoreLineStarChar��Ϊ0,����˵���chIgnoreLineStarChar��ʼ����
	BOOL ReadStringEx(CString& strText,BOOL bIgnoreEmptyLine = FALSE,TCHAR chIgnoreLineStarChar = 0);
};

#endif //_STDIO_FILE_EX_H_

