// OFOwner.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "OFOwner.h"
#include "OFParse.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{

#ifdef _DEBUG
	Parse("F:\\Myprogram\\OL\\OFL\\Release\\����\\��ܴ���.txt");
	//Parse("F:\\Myprogram\\OL\\OFL\\Debug\\����\\��������ʾ��.txt");
#else
	//Parse("����\\��������ʾ��.txt");
	Parse("����\\��ܴ���.txt");
#endif

	return 0;
}

