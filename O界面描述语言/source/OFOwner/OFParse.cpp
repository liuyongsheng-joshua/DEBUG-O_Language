
#include "stdafx.h"
#include "OFParse.h"

#include "../ofl/OFL.h"
#include "InterFaceFun.h"

#ifdef _DEBUG
#pragma comment(lib,"../debug/OFL.lib") 
#else
#pragma comment(lib,"../release/OFL.lib") 
#endif

//����¼�������
void AddInterFaceFun()
{	
	AddInterfaceFunction(��ܴ��ڹر�);	
	AddInterfaceFunction(��ܴ��ڴ���);	
	AddInterfaceFunction(��ܴ��ڲ˵�����);

	AddInterfaceFunction(���ڶԻ���_�ر�);	
}

bool Parse(char* pchFileName)
{
	//ϵͳ��ʼ��
	if(!OFDefaultInit(-1))
		return false;

	//��ӽӿں���
	AddInterFaceFun();

	//����������룬�����������д������ô�����ʾ����
	if(OFParse(pchFileName,1))
	{
		//��ʾ������
		//OFShowMainWnd("������");
		OFShowMainWnd("��ܴ���");
	}

	//���򼴽��˳�������Ҫ���б�Ҫ��������
	OFClear();

	return true;
}

