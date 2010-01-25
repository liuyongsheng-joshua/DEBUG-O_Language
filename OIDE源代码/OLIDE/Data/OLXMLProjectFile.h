#pragma once

//����O���Թ���XML�ļ�

#include ".\OLXMLProjectData.h"

class COLXMLProjectFile
{
public:
	COLXMLProjectFile(void);
	~COLXMLProjectFile(void);

	static bool CreateProjectFile(const char* pchFileName,bool bSave);
	static bool WriteProjectProperty(const char* pchFileName,COLProjectProperty* pProjectProperty);
	static bool ReadProjectProperty(const char* pchFileName,COLProjectProperty* pProjectProperty);
};
