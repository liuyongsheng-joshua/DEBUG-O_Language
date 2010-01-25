#pragma once

//O���Դ���XML�ļ����ݵĸ���

#include "./tinyxml/tinyxml.h"
#include ".\OLXMLKeyFile.h"

class COLXMLFile
{
public:
	COLXMLFile(void);
	~COLXMLFile(void);

private:

	TiXmlDocument m_xmlDoc;	

public:

	bool CreateOLanguageFile(const char* pchFileName,int nType,bool bSave = true);
	int  OpenOLanguageFile(const char* pchFileName);

	TiXmlDocument* GetXMLDoc();
	TiXmlElement* GetOLanguageFileElement();
	void SetType(int nType);
	int GetType();

	bool SaveFile();

	//�õ�XML�������ֵ
	static int GetXmlElementAttributeValue(TiXmlElement* pXmlElement,const char* pchAttributeName);

	static void StrToChar(const CString& strData,char* pchData,int nLength);
	static void IntToChar(int iData,char* pchData,int nLength);
};
