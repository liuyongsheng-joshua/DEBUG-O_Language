
// OLIDEDoc.cpp : COLIDEDoc ���ʵ��
//

#include "stdafx.h"
#include "OLIDE.h"

#include "OLIDEDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COLIDEDoc

IMPLEMENT_DYNCREATE(COLIDEDoc, CScintillaDoc)

BEGIN_MESSAGE_MAP(COLIDEDoc, CScintillaDoc)
END_MESSAGE_MAP()


// COLIDEDoc ����/����

COLIDEDoc::COLIDEDoc()
{
	// TODO: �ڴ����һ���Թ������

}

COLIDEDoc::~COLIDEDoc()
{
}


// COLIDEDoc ���

#ifdef _DEBUG
void COLIDEDoc::AssertValid() const
{
	CScintillaDoc::AssertValid();
}

void COLIDEDoc::Dump(CDumpContext& dc) const
{
	CScintillaDoc::Dump(dc);
}
#endif //_DEBUG


// COLIDEDoc ����
