// Draw1View.h : interface of the CDraw1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAW1VIEW_H__21E30932_FEF4_4691_99CC_5BF12ED099AE__INCLUDED_)
#define AFX_DRAW1VIEW_H__21E30932_FEF4_4691_99CC_5BF12ED099AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Dialog1.h"  //为了使弹出对话框非模态
#include "Dialog2.h"

class CDraw1View : public CView
{
protected: // create from serialization only
	CDraw1View();
	DECLARE_DYNCREATE(CDraw1View)

public:
	COLORREF m_nColor;
	COLORREF m_fColor;
	static BOOL click_fCol;
	CPoint cpoint;
	CPoint opoint;
	BOOL m_Down;
	int w;  //线宽
    int shape; //图形种类
	int function; //函数种类

private:
	CDialog1  *m_pDialog1;
	CDialog2  *m_pDialog2;

// Attributes
public:
	CDraw1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDraw1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDraw1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDraw1View)
	afx_msg void OnLine();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnColor();
	afx_msg void OnRect();
	afx_msg void OnEllipse();
	afx_msg void OnW1();
	afx_msg void OnW2();
	afx_msg void OnW3();
	afx_msg void OnW4();
	afx_msg void OnW5();
	afx_msg void OnFillcolor();
	afx_msg void OnUpdateLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateW1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateW2(CCmdUI* pCmdUI);
	afx_msg void OnUpdateW3(CCmdUI* pCmdUI);
	afx_msg void OnUpdateW4(CCmdUI* pCmdUI);
	afx_msg void OnUpdateW5(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEllipse(CCmdUI* pCmdUI);
	afx_msg void OnCurve();
	afx_msg void OnUpdateCurve(CCmdUI* pCmdUI);
	afx_msg void OnShangxing();
	afx_msg void OnUpdateShangxing(CCmdUI* pCmdUI);
	afx_msg void OnRETkongxin();
	afx_msg void OnUpdateRETkongxin(CCmdUI* pCmdUI);
	afx_msg void OnRETshixin();
	afx_msg void OnUpdateRETshixin(CCmdUI* pCmdUI);
	afx_msg void OnEllipseKong();
	afx_msg void OnUpdateEllipseKong(CCmdUI* pCmdUI);
	afx_msg void OnEllipseShi();
	afx_msg void OnUpdateEllipseShi(CCmdUI* pCmdUI);
	afx_msg void OnDialogSin();
	afx_msg void OnDialogPara();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Draw1View.cpp
inline CDraw1Doc* CDraw1View::GetDocument()
   { return (CDraw1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAW1VIEW_H__21E30932_FEF4_4691_99CC_5BF12ED099AE__INCLUDED_)
