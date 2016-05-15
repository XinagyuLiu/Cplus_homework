#if !defined(AFX_DIALOG1_H__47102CDF_AB56_4B02_BAD0_3BBA8197359A__INCLUDED_)
#define AFX_DIALOG1_H__47102CDF_AB56_4B02_BAD0_3BBA8197359A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog1 dialog

class CDialog1 : public CDialog
{
// Construction
public:
	CDialog1(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CDialog1)
	enum { IDD = IDD_DIALOG_SIN };
	double	m_f;  //实际上应该为m_w，角频率
	double	m_a;
	double	m_fai;
	double	m_yici_a;
	double	m_yici_b;
	double	m_zhishu_a;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog1)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void Save();
	void Open();
	//void Function1();
	// Generated message map functions
	//{{AFX_MSG(CDialog1)
	afx_msg void OnPicture01();
	afx_msg void OnPaint();
	afx_msg void OnDrawAgain();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDrawYici();
	afx_msg void OnDrawAgainCos();
	afx_msg void OnDrawAgainTan();
	afx_msg void OnDrawAgainCot();
	afx_msg void OnDrawZhishu();
	afx_msg void OnSaveAllNodes();
	afx_msg void OnClearAllNodes();
	afx_msg void OnOpen();
	afx_msg void OnOpen2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG1_H__47102CDF_AB56_4B02_BAD0_3BBA8197359A__INCLUDED_)
