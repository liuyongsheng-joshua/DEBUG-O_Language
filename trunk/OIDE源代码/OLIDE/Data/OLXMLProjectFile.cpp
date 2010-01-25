#include "StdAfx.h"
#include ".\olxmlprojectfile.h"
#include ".\OLXMLKeyFile.h"
#include ".\olxmlfile.h"
#include <string>
#include <sstream>
#include "../Common/UnicodeCovert.h"

COLXMLProjectFile::COLXMLProjectFile(void)
{
}

COLXMLProjectFile::~COLXMLProjectFile(void)
{
}

bool COLXMLProjectFile::CreateProjectFile(const char* pchFileName,bool bSave)
{
	COLXMLFile OLXMLFile;

	OLXMLFile.CreateOLanguageFile(pchFileName,OFT_PROJECT,false);

	if(bSave)
	{
		return OLXMLFile.SaveFile();
	}

	return true;
}

bool COLXMLProjectFile::WriteProjectProperty(const char* pchFileName,COLProjectProperty* pProjectProperty)
{
	assert(pProjectProperty);

    COLXMLFile OLXMLFile;

	//�򿪹����ĵ�
	if(OLXMLFile.OpenOLanguageFile(pchFileName) != OFT_PROJECT)
		return false;

	//���ù������Խ��
	TiXmlElement xmlElementProperty("");
	xmlElementProperty.SetValue(OLXMLKey_ProjectProperty);

	TiXmlText xmlText("");
	TiXmlElement xmlElement("");
	TiXmlElement* pXmlElement = NULL;

	//����������
	xmlElement.SetValue(OLXMLKey_ProjectPropertyLinker);
	pXmlElement = xmlElementProperty.InsertEndChild(xmlElement)->ToElement();

	//���ô���Ŀ¼
	xmlText.SetValue(pProjectProperty->m_chCodeDir);
	xmlElement.SetValue(OLXMLKey_ProjectPropertyCodeDir);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);

	//������ԴĿ¼
	xmlText.SetValue(pProjectProperty->m_chResourceDir);
	xmlElement.SetValue(OLXMLKey_ProjectPropertyResourceDir);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);	

	std::string strTemp;
		
	//���ó�������
	std::ostringstream format_string1;
	format_string1 << pProjectProperty->m_nProgramType;
	strTemp = format_string1.str();
	xmlText.SetValue(strTemp.c_str());
	xmlElement.SetValue(OLXMLKey_ProjectPropertyProgramType);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);

	//������ϵͳ
	//������ת��Ϊ�ַ���	
	std::ostringstream format_string2;
	format_string2 << pProjectProperty->m_nLinkSubSystem;
	strTemp = format_string2.str();
	xmlText.SetValue(strTemp.c_str());
	xmlElement.SetValue(OLXMLKey_ProjectPropertySubSystem);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);

	//���õ��԰��м��ļ����Ŀ¼
	xmlText.SetValue(pProjectProperty->m_chDebugMiddleOutPutPath);
	xmlElement.SetValue(OLXMLKey_ProjectPropertyDebugMiddleOutPutPath);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);

	//���õ��԰�ִ���ļ�·��
	xmlText.SetValue(pProjectProperty->m_chDebugOutPutFileName);
	xmlElement.SetValue(OLXMLKey_ProjectPropertyDebugOutPutFileName);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);	

	//���ô������м��ļ����Ŀ¼
	xmlText.SetValue(pProjectProperty->m_chReleaseMiddleOutPutPath);
	xmlElement.SetValue(OLXMLKey_ProjectPropertyReleaseMiddleOutPutPath);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);

	//���ô�����ִ���ļ�·��
	xmlText.SetValue(pProjectProperty->m_chReleaseOutPutFileName);
	xmlElement.SetValue(OLXMLKey_ProjectPropertyReleaseOutPutFileName);
	pXmlElement->InsertEndChild(xmlElement)->InsertEndChild(xmlText);	

	//�������ɼ�¼
	xmlElement.SetValue(OLXMLKey_ProjectPropertyBuildRecord);
	TiXmlElement* pXmlElementBuildRecord = xmlElementProperty.InsertEndChild(xmlElement)->ToElement();

	char chTemp[MAX_PATH];
	int nRecordCount = pProjectProperty->m_pProjectBuildRecord->GetCount();
	for(int i=0;i<nRecordCount;++i)
	{
		xmlElement.SetValue(OLXMLKey_ProjectPropertyBuildRecordItem);
		TiXmlElement* pXmlElementBuildRecordItem = pXmlElementBuildRecord->InsertEndChild(xmlElement)->ToElement();

		CString strFileName,strFileTime,strObjFileTime;
		pProjectProperty->m_pProjectBuildRecord->GetAt(i,strFileName,strFileTime,strObjFileTime);

		//���������ļ���
		CopyStr(chTemp,MAX_PATH,strFileName);
		xmlText.SetValue(chTemp);
		xmlElement.SetValue(OLXMLKey_ProjectPropertyBuildFileName);
		pXmlElementBuildRecordItem->InsertEndChild(xmlElement)->InsertEndChild(xmlText);

		//���������ļ�ʱ��
		CopyStr(chTemp,MAX_PATH,strFileTime);
		xmlText.SetValue(chTemp);
		xmlElement.SetValue(OLXMLKey_ProjectPropertyBuildFileTime);
		pXmlElementBuildRecordItem->InsertEndChild(xmlElement)->InsertEndChild(xmlText);

		//��������Ŀ���ļ�ʱ��
		CopyStr(chTemp,MAX_PATH,strObjFileTime);
		xmlText.SetValue(chTemp);
		xmlElement.SetValue(OLXMLKey_ProjectPropertyBuildObjFileTime);
		pXmlElementBuildRecordItem->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	}	

	//���湤���ĵ���Ϣ
	TiXmlElement* pxmlElementOLanguageFile = OLXMLFile.GetOLanguageFileElement();

	//���ù�������
	TiXmlElement* pxmlElementTemp = pxmlElementOLanguageFile->FirstChildElement(OLXMLKey_ProjectName);
	xmlText.SetValue(pProjectProperty->m_chProjectName);
	if(pxmlElementTemp)
	{
		pxmlElementTemp->Clear();
		pxmlElementTemp->InsertEndChild(xmlText);
	}
	else
	{
		xmlElement.SetValue(OLXMLKey_ProjectName);
		pxmlElementOLanguageFile->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	}
	
	pxmlElementTemp = pxmlElementOLanguageFile->FirstChildElement(xmlElementProperty.Value());
	if(pxmlElementTemp != NULL)
	{
		pxmlElementOLanguageFile->RemoveChild(pxmlElementTemp);
	}

	pxmlElementOLanguageFile->InsertEndChild(xmlElementProperty);

	return OLXMLFile.SaveFile();
}

bool COLXMLProjectFile::ReadProjectProperty(const char* pchFileName,COLProjectProperty* pProjectProperty)
{
	assert(pProjectProperty);

	COLXMLFile OLXMLFile;

	if(OLXMLFile.OpenOLanguageFile(pchFileName) != OFT_PROJECT)
		return false;

	TiXmlElement* pxmlElementOLanguageFile = OLXMLFile.GetOLanguageFileElement();

	//�õ���������
	TiXmlElement* pxmlElementProjectName = pxmlElementOLanguageFile->FirstChildElement(OLXMLKey_ProjectName);
	if(pxmlElementProjectName && (!pxmlElementProjectName->NoChildren()) && (pxmlElementProjectName->FirstChild()->Type() == TiXmlNode::TEXT))
	{
		strcpy(pProjectProperty->m_chProjectName,pxmlElementProjectName->FirstChild()->Value());
	}

	//�õ��������Խ��
	TiXmlElement* pxmlElementProperty = NULL;
	pxmlElementProperty = pxmlElementOLanguageFile->FirstChildElement(OLXMLKey_ProjectProperty);
	if(pxmlElementProperty == NULL)
		return false;

	//�õ����������
	TiXmlElement* pxmlElementLinker = pxmlElementProperty->FirstChildElement(OLXMLKey_ProjectPropertyLinker);
	if(pxmlElementLinker)
	{
		TiXmlElement* pxmlElement = NULL;

		//�õ�����Ŀ¼
		pxmlElement = pxmlElementLinker->FirstChildElement(OLXMLKey_ProjectPropertyCodeDir);
		if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
		{
			strcpy(pProjectProperty->m_chCodeDir, pxmlElement->FirstChild()->Value());
		}

		//�õ���ԴĿ¼
		pxmlElement = pxmlElementLinker->FirstChildElement(OLXMLKey_ProjectPropertyResourceDir);
		if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
		{
			strcpy(pProjectProperty->m_chResourceDir, pxmlElement->FirstChild()->Value());
		}		

		//�õ���������
		pxmlElement = pxmlElementLinker->FirstChildElement(OLXMLKey_ProjectPropertyProgramType);
		if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
		{
			pProjectProperty->m_nProgramType = atoi(pxmlElement->FirstChild()->Value());
		}

		//�õ���ϵͳ
		pxmlElement = pxmlElementLinker->FirstChildElement(OLXMLKey_ProjectPropertySubSystem);
		if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
		{
			pProjectProperty->m_nLinkSubSystem = atoi(pxmlElement->FirstChild()->Value());
		}
		
		//�õ����԰��м��ļ����·��
		pxmlElement = pxmlElementLinker->FirstChildElement(OLXMLKey_ProjectPropertyDebugMiddleOutPutPath);
		if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
		{
			strcpy(pProjectProperty->m_chDebugMiddleOutPutPath, pxmlElement->FirstChild()->Value());
		}
		//�õ����԰������ļ�·��
		pxmlElement = pxmlElementLinker->FirstChildElement(OLXMLKey_ProjectPropertyDebugOutPutFileName);
		if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
		{
			strcpy(pProjectProperty->m_chDebugOutPutFileName, pxmlElement->FirstChild()->Value());
		}		

		//�õ��������м��ļ����·��
		pxmlElement = pxmlElementLinker->FirstChildElement(OLXMLKey_ProjectPropertyReleaseMiddleOutPutPath);
		if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
		{
			strcpy(pProjectProperty->m_chReleaseMiddleOutPutPath, pxmlElement->FirstChild()->Value());
		}
		//�õ������������ļ�·��
		pxmlElement = pxmlElementLinker->FirstChildElement(OLXMLKey_ProjectPropertyReleaseOutPutFileName);
		if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
		{
			strcpy(pProjectProperty->m_chReleaseOutPutFileName, pxmlElement->FirstChild()->Value());
		}	
	}

	//�õ����ɼ�¼
	TiXmlElement* pxmlElementBuildRecord = pxmlElementProperty->FirstChildElement(OLXMLKey_ProjectPropertyBuildRecord);
	if(pxmlElementBuildRecord)
	{
		TiXmlElement* pxmlElementBuildRecordItem = pxmlElementBuildRecord->FirstChildElement(OLXMLKey_ProjectPropertyBuildRecordItem);
		while(pxmlElementBuildRecordItem)
		{
			TiXmlElement* pxmlElement = 0;
			CString strFileName,strFileTime,strObjFileTime;
			
			//�õ��ļ���
			pxmlElement = pxmlElementBuildRecordItem->FirstChildElement(OLXMLKey_ProjectPropertyBuildFileName);
			if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
			{
				strFileName = pxmlElement->FirstChild()->Value();				
			}

			//�õ��ļ�ʱ��
			pxmlElement = pxmlElementBuildRecordItem->FirstChildElement(OLXMLKey_ProjectPropertyBuildFileTime);
			if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
			{
				strFileTime = pxmlElement->FirstChild()->Value();				
			}

			//�õ�Ŀ���ļ�ʱ��
			pxmlElement = pxmlElementBuildRecordItem->FirstChildElement(OLXMLKey_ProjectPropertyBuildObjFileTime);
			if(pxmlElement && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::TEXT))
			{
				strObjFileTime = pxmlElement->FirstChild()->Value();
			}

			pProjectProperty->m_pProjectBuildRecord->AddRecord(strFileName,strFileTime,strObjFileTime);

			pxmlElementBuildRecordItem = pxmlElementBuildRecordItem->NextSiblingElement(OLXMLKey_ProjectPropertyBuildRecordItem);
		}		
	}

	return true;
}
