
// OLIDEDoc.h : COLIDEDoc ��Ľӿ�
//


#pragma once

#include "./Controls/scintilla/ScintillaDocView.h"

class COLIDEDoc : public CScintillaDoc
{
protected: // �������л�����
	COLIDEDoc();
	DECLARE_DYNCREATE(COLIDEDoc)

// ����
public:

// ����
public:

// ��д
public:
	
// ʵ��
public:
	virtual ~COLIDEDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


