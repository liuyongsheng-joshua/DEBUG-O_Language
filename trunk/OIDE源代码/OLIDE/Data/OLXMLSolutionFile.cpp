#include "StdAfx.h"
#include ".\olxmlsolutionfile.h"
#include ".\olxmlfile.h"
#include ".\OLXMLKeyFile.h"

COLXMLSolutionFile::COLXMLSolutionFile(void)
{

}

COLXMLSolutionFile::~COLXMLSolutionFile(void)
{
}

bool COLXMLSolutionFile::CreateSolutionFile(const char* pchFileName,bool bSave)
{
	COLXMLFile OLXMLFile;

	OLXMLFile.CreateOLanguageFile(pchFileName,OFT_SOLUTION,false);

	if(bSave)
	{
		return OLXMLFile.SaveFile();
	}

	return true;
}

bool COLXMLSolutionFile::WriteSolution(const char* pchFileName,COLXMLSolution* pOLXMLSolution)
{
	assert(pOLXMLSolution);

	COLXMLFile OLXMLFile;

	//�򿪹����ĵ�
	if(OLXMLFile.OpenOLanguageFile(pchFileName) != OFT_SOLUTION)
		return false;

	TiXmlElement* pxmlElementOLanguageFile = OLXMLFile.GetOLanguageFileElement();

	TiXmlElement xmlElement("");
	TiXmlText xmlText("");

	//���÷�������
	TiXmlElement* pxmlElementSolutionName = pxmlElementOLanguageFile->FirstChildElement(OLXMLKey_SolutionName);
	xmlText.SetValue(pOLXMLSolution->m_chSolutionName);
	if(pxmlElementSolutionName)
	{
		pxmlElementSolutionName->Clear();
		pxmlElementSolutionName->InsertEndChild(xmlText);
	}
	else
	{
		xmlElement.SetValue(OLXMLKey_SolutionName);
		pxmlElementOLanguageFile->InsertEndChild(xmlElement)->InsertEndChild(xmlText);
	}
    
	//�õ������ļ����
	TiXmlElement* pxmlProjectFileElement = pxmlElementOLanguageFile->FirstChildElement(OLXMLKey_ProjectFile);	
	//���û�й����ļ���㣬����һ�������ļ����
	if(pxmlProjectFileElement == NULL)
	{
		TiXmlElement xmlProjectFileElement(OLXMLKey_ProjectFile);
		pxmlProjectFileElement = pxmlElementOLanguageFile->InsertEndChild(xmlProjectFileElement)->ToElement();
	}

	//���ù��̽��

	pxmlProjectFileElement->Clear();

	TiXmlElement xmlProjectElement(OLXMLKey_Project);
	TiXmlElement* pxmlElement = NULL;

	COLProjectFileProperty* pProjectFileProperty = NULL;
	std::list<COLProjectFileProperty>::iterator itProjectFileProperty;
	for(itProjectFileProperty = pOLXMLSolution->m_listProjectFile.begin();itProjectFileProperty != pOLXMLSolution->m_listProjectFile.end();++itProjectFileProperty)
	{
		pProjectFileProperty = &(*itProjectFileProperty);

		//�ڷ����ļ��б��湤��
		xmlProjectElement.Clear();

		////���ù�������
		//xmlElement.SetValue(OLXMLKey_ProjectName);
		//pxmlElement = xmlProjectElement.InsertEndChild(xmlElement)->ToElement();
		//xmlText.SetValue(pProjectFileProperty->m_strProjectName.c_str());
		//pxmlElement->InsertEndChild(xmlText);

		//���ù���·��
		xmlElement.SetValue(OLXMLKey_ProjectPath);
		pxmlElement = xmlProjectElement.InsertEndChild(xmlElement)->ToElement();
		xmlText.SetValue(pProjectFileProperty->m_chProjectFileName);
		pxmlElement->InsertEndChild(xmlText);
		
		//���������չ��״̬���
		xmlElement.SetValue(OLXMLKey_ProjectTreeNodeExpandState);
		pxmlElement = xmlProjectElement.InsertEndChild(xmlElement)->ToElement();
		if(pProjectFileProperty->m_bIsExpand)
		{
			xmlText.SetValue("1");
		}
		else
		{
			xmlText.SetValue("0");
		}
		pxmlElement->InsertEndChild(xmlText);
		
		//��ӹ��̽��
		pxmlProjectFileElement->InsertEndChild(xmlProjectElement);
	}

	return OLXMLFile.SaveFile();
}

bool COLXMLSolutionFile::ReadSolution(const char* pchFileName,COLXMLSolution* pOLXMLSolution)
{
	assert(pOLXMLSolution);

	COLXMLFile OLXMLFile;

	//�򿪹����ĵ�
	if(OLXMLFile.OpenOLanguageFile(pchFileName) != OFT_SOLUTION)
		return false;

	TiXmlElement* pxmlElementOLanguageFile = OLXMLFile.GetOLanguageFileElement();

	//�õ���������
	TiXmlElement* pxmlElementSolutionName = pxmlElementOLanguageFile->FirstChildElement(OLXMLKey_SolutionName);
	if((pxmlElementSolutionName != NULL) && (!pxmlElementSolutionName->NoChildren()) && (pxmlElementSolutionName->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
	{
		strcpy(pOLXMLSolution->m_chSolutionName,pxmlElementSolutionName->FirstChild()->Value());
	}

	//�õ������ļ����
	TiXmlElement* pxmlProjectFileElement = pxmlElementOLanguageFile->FirstChildElement(OLXMLKey_ProjectFile);
	if(pxmlProjectFileElement == NULL)
		return false;

	TiXmlElement* pxmlProjectElement = pxmlProjectFileElement->FirstChildElement(OLXMLKey_Project);
	while(pxmlProjectElement)
	{
		COLProjectFileProperty projectFileProperty;
		TiXmlElement* pxmlElement = NULL;

		////�õ�������
		//pxmlElement = pxmlProjectElement->FirstChildElement(OLXMLKey_ProjectName);
		//if(pxmlElement)
		//{
		//	projectFileProperty.m_strProjectName = pxmlElement->FirstChild()->Value();
		//}

		//�õ�����·��
		pxmlElement = pxmlProjectElement->FirstChildElement(OLXMLKey_ProjectPath);
		if((pxmlElement != NULL) && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			strcpy(projectFileProperty.m_chProjectFileName,pxmlElement->FirstChild()->Value());
		}

		//�õ����������״̬
		pxmlElement = pxmlProjectElement->FirstChildElement(OLXMLKey_ProjectTreeNodeExpandState);
		if((pxmlElement != NULL) && (!pxmlElement->NoChildren()) && (pxmlElement->FirstChild()->Type() == TiXmlNode::NodeType::TEXT))
		{
			if(strcmp(pxmlElement->FirstChild()->Value(),"0") == 0)
			{
				projectFileProperty.m_bIsExpand = false;
			}
			else
			{
				projectFileProperty.m_bIsExpand = true;
			}
		}

		//�������ļ�������ӵ������ļ��б�
		pOLXMLSolution->m_listProjectFile.push_back(projectFileProperty);

		//�õ���һ�����̽��
		pxmlProjectElement = pxmlProjectElement->NextSiblingElement(OLXMLKey_Project);
	}

	return true;
}

char* COLXMLSolutionFile::GetSolutionName(COLXMLSolution* pOLXMLSolution)
{
	assert(pOLXMLSolution);

	return pOLXMLSolution->m_chSolutionName;
}

void COLXMLSolutionFile::SetSolutionName(COLXMLSolution* pOLXMLSolution,const char* pchSolutionName)
{
	assert(pOLXMLSolution);

	strcpy(pOLXMLSolution->m_chSolutionName,pchSolutionName);
}

bool COLXMLSolutionFile::PopFrontProjectFileProperty(COLXMLSolution* pOLXMLSolution,COLProjectFileProperty* pProjectFileProperty)
{
	assert(pOLXMLSolution);
	assert(pProjectFileProperty);

	if(pOLXMLSolution->m_listProjectFile.empty())
		return false;

	*pProjectFileProperty = *pOLXMLSolution->m_listProjectFile.begin();
	pOLXMLSolution->m_listProjectFile.pop_front();

	return true;
}

void COLXMLSolutionFile::PushBackProjectFileProperty(COLXMLSolution* pOLXMLSolution,COLProjectFileProperty* pProjectFileProperty)
{
	assert(pOLXMLSolution);
	assert(pProjectFileProperty);

	pOLXMLSolution->m_listProjectFile.push_back(*pProjectFileProperty);
}

COLXMLSolution* COLXMLSolutionFile::CreateSolutionData()
{
	COLXMLSolution* pOLXMLSolution = new COLXMLSolution();
	return pOLXMLSolution;
}

void COLXMLSolutionFile::DestorySolutionData(COLXMLSolution* pOLXMLSolution)
{
	delete pOLXMLSolution;
}