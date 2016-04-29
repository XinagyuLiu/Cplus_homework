// Draw1View.cpp : implementation of the CDraw1View class
//

#include "stdafx.h"
#include "Draw1.h"

#include "Draw1Doc.h"
#include "Draw1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDraw1View

IMPLEMENT_DYNCREATE(CDraw1View, CView)

BEGIN_MESSAGE_MAP(CDraw1View, CView)
	//{{AFX_MSG_MAP(CDraw1View)
	ON_COMMAND(ID_LINE, OnLine)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_COLOR, OnColor)
	ON_COMMAND(ID_RECT, OnRect)
	ON_COMMAND(ID_ELLIPSE, OnEllipse)
	ON_COMMAND(ID_W1, OnW1)
	ON_COMMAND(ID_W2, OnW2)
	ON_COMMAND(ID_W3, OnW3)
	ON_COMMAND(ID_W4, OnW4)
	ON_COMMAND(ID_W5, OnW5)
	ON_COMMAND(ID_FILLCOLOR, OnFillcolor)
	ON_UPDATE_COMMAND_UI(ID_LINE, OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_W1, OnUpdateW1)
	ON_UPDATE_COMMAND_UI(ID_W2, OnUpdateW2)
	ON_UPDATE_COMMAND_UI(ID_W3, OnUpdateW3)
	ON_UPDATE_COMMAND_UI(ID_W4, OnUpdateW4)
	ON_UPDATE_COMMAND_UI(ID_W5, OnUpdateW5)
	ON_UPDATE_COMMAND_UI(ID_RECT, OnUpdateRect)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE, OnUpdateEllipse)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDraw1View construction/destruction

CDraw1View::CDraw1View()
{
	// TODO: add construction code here
	w = 1;
	shape = 0;
}

CDraw1View::~CDraw1View()
{
}

BOOL CDraw1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDraw1View drawing

void CDraw1View::OnDraw(CDC* pDC)
{
	CDraw1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDraw1View printing

BOOL CDraw1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDraw1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDraw1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDraw1View diagnostics

#ifdef _DEBUG
void CDraw1View::AssertValid() const
{
	CView::AssertValid();
}

void CDraw1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDraw1Doc* CDraw1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDraw1Doc)));
	return (CDraw1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDraw1View message handlers

void CDraw1View::OnLine() 
{
	// TODO: Add your command handler code here
	shape = 1; //选择直线，则令shape为1
}

void CDraw1View::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CPen pen;  //定义画笔
	CBrush brush;  //定义画刷
	pen.CreatePen(PS_SOLID,w,m_nColor); //创建画笔
	brush.CreateSolidBrush(m_fColor);   //创建画刷
	dc.SelectObject(&pen);
	dc.SelectObject(&brush);    //获取画刷
	if(shape==1) 
	{
		dc.MoveTo(opoint.x,opoint.y);
		dc.LineTo(cpoint.x,cpoint.y);
	}
	if(shape==2)    
		dc.Rectangle(opoint.x,opoint.y,cpoint.x,cpoint.y); //绘制矩形   
	if(shape==3)    
		dc.Ellipse(opoint.x,opoint.y,cpoint.x,cpoint.y);   //绘制椭圆
	// TODO: Add your message handler code here
	
	// Do not call CView::OnPaint() for painting messages
}

void CDraw1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_Down = TRUE;  //鼠标按下
	SetCapture();  //获取坐标
	opoint = point;
	ReleaseCapture(); //释放坐标
	CView::OnLButtonDown(nFlags, point);
}

void CDraw1View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_Down = FALSE;
	Invalidate(0); //刷新。没有这条语句不能画图
	CView::OnLButtonUp(nFlags, point);
}

void CDraw1View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_Down)
		cpoint = point;
	CView::OnMouseMove(nFlags, point);
}

void CDraw1View::OnColor() 
{
	// TODO: Add your command handler code here
	CColorDialog Color; // 创建颜色对话框
	if(Color.DoModal() == IDOK) // 如果用户点击OK按钮 
		m_nColor=Color.GetColor(); // 更改颜色,把颜色赋到m_nColor
}

void CDraw1View::OnRect() 
{
	// TODO: Add your command handler code here
	shape = 2; 
}

void CDraw1View::OnEllipse() 
{
	// TODO: Add your command handler code here
	shape = 3; 
}

void CDraw1View::OnW1() 
{
	// TODO: Add your command handler code here
	w = 1; //线宽为1
}

void CDraw1View::OnW2() 
{
	// TODO: Add your command handler code here
	w = 2;
}

void CDraw1View::OnW3() 
{
	// TODO: Add your command handler code here
	w = 3;
}

void CDraw1View::OnW4() 
{
	// TODO: Add your command handler code here
	w = 4;
}

void CDraw1View::OnW5() 
{
	// TODO: Add your command handler code here
	w = 5;
}

void CDraw1View::OnFillcolor() 
{
	// TODO: Add your command handler code here
	CColorDialog FillColor; 
	if(FillColor.DoModal() == IDOK) 
		m_fColor=FillColor.GetColor();
}

void CDraw1View::OnUpdateLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==1); 
}

void CDraw1View::OnUpdateW1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(w==1);  //当线宽为1时，此选项前标有圆点
}

void CDraw1View::OnUpdateW2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(w==2);
}

void CDraw1View::OnUpdateW3(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(w==3);
}

void CDraw1View::OnUpdateW4(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(w==4);
}

void CDraw1View::OnUpdateW5(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(w==5);
}

void CDraw1View::OnUpdateRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==2); 
}

void CDraw1View::OnUpdateEllipse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==3); 
}
