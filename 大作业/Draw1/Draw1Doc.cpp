// Draw1Doc.cpp : implementation of the CDraw1Doc class
//

#include "stdafx.h"
#include "Draw1.h"

#include "Draw1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDraw1Doc

IMPLEMENT_DYNCREATE(CDraw1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDraw1Doc, CDocument)
	//{{AFX_MSG_MAP(CDraw1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDraw1Doc construction/destruction

CDraw1Doc::CDraw1Doc()
{
	// TODO: add one-time construction code here

}
CDraw1Doc::~CDraw1Doc()
{
}

BOOL CDraw1Doc::OnNewDocument()
{
	SetTitle("»­Í¼¹¤¾ß");
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDraw1Doc serialization

void CDraw1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDraw1Doc diagnostics

#ifdef _DEBUG
void CDraw1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDraw1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDraw1Doc commands
