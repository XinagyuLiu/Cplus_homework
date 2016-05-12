// Draw1View.cpp : implementation of the CDraw1View class
//

#include "stdafx.h"
#include "Draw1.h"

#include "Draw1Doc.h"
#include "Draw1View.h"
#include "Dialog1.h"  //Ϊ��ʹ�����Ի����ģ̬
#include "Dialog2.h" 

#include <math.h>
#define PI 3.1415926
#define SEGMENT 500

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
	ON_COMMAND(ID_CURVE, OnCurve)
	ON_UPDATE_COMMAND_UI(ID_CURVE, OnUpdateCurve)
	ON_COMMAND(ID_SHANGXING, OnShangxing)
	ON_UPDATE_COMMAND_UI(ID_SHANGXING, OnUpdateShangxing)
	ON_COMMAND(ID_RETkongxin, OnRETkongxin)
	ON_UPDATE_COMMAND_UI(ID_RETkongxin, OnUpdateRETkongxin)
	ON_COMMAND(ID_RETshixin, OnRETshixin)
	ON_UPDATE_COMMAND_UI(ID_RETshixin, OnUpdateRETshixin)
	ON_COMMAND(ID_EllipseKong, OnEllipseKong)
	ON_UPDATE_COMMAND_UI(ID_EllipseKong, OnUpdateEllipseKong)
	ON_COMMAND(ID_EllipseShi, OnEllipseShi)
	ON_UPDATE_COMMAND_UI(ID_EllipseShi, OnUpdateEllipseShi)
	ON_COMMAND(IDD_DIALOG_SIN, OnDialogSin)
	ON_COMMAND(IDD_DIALOG_PARA, OnDialogPara)
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
	shape = 1;
	function = 0;
	m_pDialog1 = NULL; //��ʼ��ָ��
}

CDraw1View::~CDraw1View()
{
	if (m_pDialog1 != NULL)   
    {   
        // ɾ����ģ̬�Ի������   
        delete m_pDialog1;   
    } 
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
	shape = 1; //ѡ��ֱ�ߣ�����shapeΪ1
}

BOOL CDraw1View::click_fCol = FALSE;
void CDraw1View::OnPaint() 
{
/*  */
	CPaintDC dc(this); // device context for painting
	
	CPen pen;  //���廭��
	CBrush brush;  //���廭ˢ
	if(click_fCol == FALSE)
	{
		m_fColor = RGB(255,255,255); //��ʼ����ˢΪ��ɫ
	}
	pen.CreatePen(PS_SOLID,w,m_nColor); //��������
	brush.CreateSolidBrush(m_fColor);   //������ˢ
	dc.SelectObject(&pen);
	dc.SelectObject(&brush);    //��ȡ��ˢ
	//---------��ʼ������ͼ��--------------
	   CRect rect;
       GetClientRect(&rect);
/*	   if(function == 1)
	{
       
       int nWidth = rect.Width()/2;
       int nHeight = rect.Height()/2;
       CPoint aPoint[SEGMENT];
       for (int i=0; i<SEGMENT; i++)
       {
         aPoint[i].x = (i * nWidth) / SEGMENT;
         aPoint[i].y = (int) ((nHeight / 2) * (1 - (sin((2*PI*i)/SEGMENT))));
       }
       dc.Polyline(aPoint,SEGMENT);
	}*/
	if(shape==1) 
	{
		dc.MoveTo(opoint.x,opoint.y);
		dc.LineTo(cpoint.x,cpoint.y);
	}
	if(shape==2)    
		dc.Rectangle(opoint.x,opoint.y,cpoint.x,cpoint.y); //���ƾ���   
	if(shape==21)
	{
		dc.SelectStockObject(NULL_BRUSH);
		dc.Rectangle(opoint.x,opoint.y,cpoint.x,cpoint.y); //���ƿ��ľ���;����������ͼ��
	}
	if(shape==3||shape==31)
	{
		if(shape==31)
			dc.SelectStockObject(NULL_BRUSH);
		dc.Ellipse(opoint.x,opoint.y,cpoint.x,cpoint.y);   //������Բ
	}
	// TODO: Add your message handler code here
	
	// Do not call CView::OnPaint() for painting messages
}

void CDraw1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_Down = TRUE;  //��갴��
	SetCapture();  //��ȡ����
	opoint = point;
	ReleaseCapture(); //�ͷ�����
	CView::OnLButtonDown(nFlags, point);
}

void CDraw1View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_Down = FALSE;
	Invalidate(0); //ˢ�¡�û��������䲻�ܻ�ͼ

	CView::OnLButtonUp(nFlags, point);
}

void CDraw1View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_Down)
		cpoint = point;
	
if(shape ==4||shape == 5){
	Invalidate(0);
	CPaintDC dc(this);
	CPen pen;  //���廭��
	pen.CreatePen(PS_SOLID,w,m_nColor); //��������
	dc.SelectObject(&pen);
	if (m_Down==TRUE && shape==4)
    {
        dc.MoveTo(opoint);
        dc.LineTo(point);
        opoint = point ;  //ÿ�ζ��������
    }
	else if (m_Down==TRUE && shape==5)
	{//������
		dc.MoveTo(opoint);
        dc.LineTo(point);
	}
}


	CView::OnMouseMove(nFlags, point);
}

void CDraw1View::OnColor() 
{
	// TODO: Add your command handler code here
	CColorDialog Color; // ������ɫ�Ի���
	if(Color.DoModal() == IDOK) // ����û����OK��ť 
		m_nColor=Color.GetColor(); // ������ɫ,����ɫ����m_nColor
}

void CDraw1View::OnRect() 
{
	// TODO: Add your command handler code here
	shape = 21; 
}

void CDraw1View::OnEllipse() 
{
	// TODO: Add your command handler code here
	shape = 31; 
}

void CDraw1View::OnW1() 
{
	// TODO: Add your command handler code here
	w = 1; //�߿�Ϊ1
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
	{
		click_fCol = TRUE;
		m_fColor=FillColor.GetColor();
	}
}

void CDraw1View::OnUpdateLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==1); 
}

void CDraw1View::OnUpdateW1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(w==1);  //���߿�Ϊ1ʱ����ѡ��ǰ����Բ��
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
	pCmdUI->SetCheck(shape==2||shape==21); 
}

void CDraw1View::OnUpdateEllipse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==3||shape==31); 
}

void CDraw1View::OnCurve() 
{
	// TODO: Add your command handler code here
	shape = 4;
}

void CDraw1View::OnUpdateCurve(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==4); 
}

void CDraw1View::OnShangxing() 
{
	// TODO: Add your command handler code here
	shape = 5;
}

void CDraw1View::OnUpdateShangxing(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==5); 
}

void CDraw1View::OnRETkongxin() 
{
	// TODO: Add your command handler code here
	shape = 21; 
}

void CDraw1View::OnUpdateRETkongxin(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==21); 
}

void CDraw1View::OnRETshixin() 
{
	// TODO: Add your command handler code here
	shape = 2; 
}

void CDraw1View::OnUpdateRETshixin(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==2); 
}

void CDraw1View::OnEllipseKong() 
{
	// TODO: Add your command handler code here
	shape = 31; 
}

void CDraw1View::OnUpdateEllipseKong(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==31); 
}

void CDraw1View::OnEllipseShi() 
{
	// TODO: Add your command handler code here
	shape = 3; 
}

void CDraw1View::OnUpdateEllipseShi(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(shape==3); 
}


void CDraw1View::OnDialogSin() 
{
	// TODO: Add your command handler code here
	//CDialog1 dialog1;  //ģ̬�Ի���
	//dialog1.DoModal();
	if (m_pDialog1 == NULL)   
    {   
        // ������ģ̬�Ի���ʵ��   
        m_pDialog1 = new CDialog1();   
        m_pDialog1->Create(IDD_DIALOG_SIN, this);   
    }   
    // ��ʾ��ģ̬�Ի���   
    m_pDialog1->ShowWindow(SW_SHOW);   
}

void CDraw1View::OnDialogPara() 
{
	// TODO: Add your command handler code here
	//CDialog2 dialog2;  //ģ̬�Ի���
	//dialog2.DoModal();
	if (m_pDialog2 == NULL)   
    {   
        // ������ģ̬�Ի���ʵ��   
        m_pDialog2 = new CDialog2();   
        m_pDialog2->Create(IDD_DIALOG_PARA, this);   
    }   
    // ��ʾ��ģ̬�Ի���   
    m_pDialog2->ShowWindow(SW_SHOW);   
}
