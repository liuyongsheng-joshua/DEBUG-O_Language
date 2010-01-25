
#include "stdafx.h"
#include "StdioFileEx.h"
#include "../../Common/UnicodeCovert.h"

CStdioFileEx::CStdioFileEx()
{

}

CStdioFileEx::~CStdioFileEx()
{

}

#ifdef _UNICODE

void CStdioFileEx::Str2Unicode(CString &str)
{
	char *szBuf = new char[str.GetLength()+1];

	for (int i = 0 ; i < str.GetLength()+1; i++)
	{
		szBuf[i] = str.GetAt(i); //�����ʾ "wchar_t"ת����"char"�����ܶ�ʧ���� �������
	}
	CharToUnicode(szBuf , &str);

	delete []szBuf;
}
#endif

//��ȡһ�У����chIgnoreLineStarChar��Ϊ0,����˵���chIgnoreLineStarChar��ʼ����
BOOL CStdioFileEx::ReadStringEx(CString& strText,BOOL bIgnoreEmptyLine,TCHAR chIgnoreLineStarChar)
{
	BOOL bResult = ReadString(strText);
	if(!bResult)return FALSE;

#ifdef _UNICODE
	Str2Unicode(strText);
#endif

	//���Կ���
	if(bIgnoreEmptyLine)
	{
		strText.Trim();
		if(strText.IsEmpty())
		{
			return ReadStringEx(strText,bIgnoreEmptyLine,chIgnoreLineStarChar);
		}
	}

	if(chIgnoreLineStarChar>0 && (!strText.IsEmpty()) && (strText[0] == chIgnoreLineStarChar))
	{
		return ReadStringEx(strText,bIgnoreEmptyLine,chIgnoreLineStarChar);
	}

	return TRUE;
}