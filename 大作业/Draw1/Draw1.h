// Draw1.h : main header file for the DRAW1 application
//

#if !defined(AFX_DRAW1_H__D430F33A_C714_4E8F_8D45_ABC794A9822B__INCLUDED_)
#define AFX_DRAW1_H__D430F33A_C714_4E8F_8D45_ABC794A9822B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDraw1App:
// See Draw1.cpp for the implementation of this class
//

class CDraw1App : public CWinApp
{
public:
	CDraw1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDraw1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDraw1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAW1_H__D430F33A_C714_4E8F_8D45_ABC794A9822B__INCLUDED_)
