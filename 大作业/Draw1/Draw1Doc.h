// Draw1Doc.h : interface of the CDraw1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAW1DOC_H__25B19B01_25E1_4D7B_8626_BE1CB35C1057__INCLUDED_)
#define AFX_DRAW1DOC_H__25B19B01_25E1_4D7B_8626_BE1CB35C1057__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDraw1Doc : public CDocument
{
protected: // create from serialization only
	CDraw1Doc();
	DECLARE_DYNCREATE(CDraw1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDraw1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDraw1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDraw1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAW1DOC_H__25B19B01_25E1_4D7B_8626_BE1CB35C1057__INCLUDED_)
