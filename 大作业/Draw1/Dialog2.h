#if !defined(AFX_DIALOG2_H__8D95049E_C08F_4F10_8E93_383E452C19F5__INCLUDED_)
#define AFX_DIALOG2_H__8D95049E_C08F_4F10_8E93_383E452C19F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog2 dialog

class CDialog2 : public CDialog
{
// Construction
public:
	CDialog2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog2)
	enum { IDD = IDD_DIALOG_PARA };
	double	m_p1;
	double	m_p2;
	double	m_p3;
	double	m_p4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog2)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog2)
	afx_msg void OnPicture02();
	afx_msg void OnPaint();
	afx_msg void OnDrawAgain2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG2_H__8D95049E_C08F_4F10_8E93_383E452C19F5__INCLUDED_)
