#include "StdAfx.h"
#include ".\olxmlfile.h"
#include <string>
#include <sstream>
#include "../Common/UnicodeCovert.h"

COLXMLFile::COLXMLFile(void)
{
}

COLXMLFile::~COLXMLFile(void)
{
}

void COLXMLFile::StrToChar(const CString& strData,char* pchData,int nLength)
{
#ifdef _UNICODE
	UnicodeToChar(strData,pchData,nLength);
#else
	strcpy(pchData,strData);
#endif

}

void COLXMLFile::IntToChar(int iData,char* pchData,int nLength)
{
	_itoa_s(iData,pchData,nLength,10);
}

bool COLXMLFile::CreateOLanguageFile(const char* pchFileName,int nType,bool bSave)
{
	m_xmlDoc.Clear();

	m_xmlDoc.SetValue(pchFileName);

	//�����ļ�ͷ
	m_xmlDoc.Parse(OLXMLKey_OLanguageHead);

	//����O�����ļ����
	TiXmlElement xmlElementTemp(OLXMLKey_OLanguageFile);
	m_xmlDoc.InsertEndChild(xmlElementTemp)->ToElement()->SetAttribute(OLXMLKey_FileType,nType);

	if(bSave)
	{
		return SaveFile();
	}

	return true;
}

//��O�����ļ�
int COLXMLFile::OpenOLanguageFile(const char* pchFileName)
{
	m_xmlDoc.Clear();

	//��O�����ļ�
	bool bLoadFile = m_xmlDoc.LoadFile(pchFileName);
	if ( m_xmlDoc.Error() && m_xmlDoc.ErrorId() == TiXmlBase::TIXML_ERROR_OPENING_FILE ) 
	{		
		return -1;
	}

	//����O�����ļ�
	if(!bLoadFile)
	{		
		return -1;
	}

	//�ж��ļ��Ϸ���
	if(GetOLanguageFileElement() == NULL)
	{		
		return -1;
	}

	return GetType();
}

TiXmlDocument* COLXMLFile::GetXMLDoc()
{
	return &m_xmlDoc;
}

TiXmlElement* COLXMLFile::GetOLanguageFileElement()
{
	return GetXMLDoc()->FirstChildElement(OLXMLKey_OLanguageFile);
}

void COLXMLFile::SetType(int nType)
{
	//���ͱ�����ڵ���0
	assert(nType >= 0);

	TiXmlElement* pXmlElementOLanguageFile = GetOLanguageFileElement();
	assert(pXmlElementOLanguageFile);

	pXmlElementOLanguageFile->SetAttribute(OLXMLKey_FileType,nType);
}

int COLXMLFile::GetType()
{
	TiXmlElement* pXmlElementOLanguageFile = GetOLanguageFileElement();
	assert(pXmlElementOLanguageFile);
	
	return GetXmlElementAttributeValue(pXmlElementOLanguageFile,OLXMLKey_FileType);
}

bool COLXMLFile::SaveFile()
{
	return m_xmlDoc.SaveFile();
}

//����ID
int COLXMLFile::GetXmlElementAttributeValue(TiXmlElement* pXmlElement,const char* pchAttributeName)
{
	assert(pXmlElement);

	//����ID����
	TiXmlAttribute* pXmlAttribute = NULL;
	pXmlAttribute = pXmlElement->FirstAttribute();
	while(pXmlAttribute != NULL)
	{
		if(strcmp(pXmlAttribute->Name(),pchAttributeName) == 0)
		{
			return pXmlAttribute->IntValue();
		}

		pXmlAttribute = pXmlAttribute->Next();
	}

	return 0;
}
