// Dialog2.cpp : implementation file
//

#include "stdafx.h"
#include "Draw1.h"
#include "Dialog2.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog2 dialog


CDialog2::CDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog2)
	m_p1 = 0.5;
	m_p2 = 0.0;
	m_p3 = 0.0;
	m_p4 = 0.0;
	//}}AFX_DATA_INIT
}


void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog2)
	DDX_Text(pDX, IDC_EDIT_P1, m_p1);
	DDX_Text(pDX, IDC_EDIT_P2, m_p2);
	DDX_Text(pDX, IDC_EDIT_P3, m_p3);
	DDX_Text(pDX, IDC_EDIT_P4, m_p4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog2, CDialog)
	//{{AFX_MSG_MAP(CDialog2)
	ON_BN_CLICKED(IDC_PICTURE02, OnPicture02)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_DRAW_AGAIN2, OnDrawAgain2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog2 message handlers



void CDialog2::OnPicture02() 
{
	// TODO: Add your control notification handler code here
	CRect rect;
    CWnd* pWnd = GetDlgItem(IDC_PICTURE02);
    pWnd->GetClientRect(&rect);
	CClientDC dc(pWnd);		//这是获取图片框的指针
    //CClientDC dc(this);  //这是获取整个对话框的指针
	
//*************************************
	//坐标系   
	dc.FillSolidRect(rect,RGB(255,255,255));   //设置为白色背景
	dc.SetMapMode(MM_LOMETRIC);      //设置映射模式
	dc.SetWindowOrg(0,0);                //设置屏幕窗口原点
	dc.SetViewportOrg(CPoint(rect.right/2,rect.bottom/2)); //设置视口原点
	CPen pen1(PS_DOT,1,RGB(100,100,100));  //创建笔，并调整坐标颜色
	CPen *pOldPen = dc.SelectObject(&pen1);  //更改笔并保存旧的笔
	for(int i=-900;i<=900;i+=50) 
	{
		dc.MoveTo (i,500); 
		dc.LineTo (i,-500); 
	}
	for(int j=-500;j<=500;j+=50) 
	{
		dc.MoveTo (-900,j); 
		dc.LineTo (900,j); 
	}
	dc.TextOut (10,500,'y');     //标记y轴   在(10,500)处输出'y'
	dc.TextOut (870,0,'x');      //标记x轴  
	dc.TextOut (0,0,'0');        //标记坐标原点  
	dc.TextOut (-8,510,'^');  
	dc.TextOut (900,25,'>');  
	CPen pen(PS_SOLID,1,RGB(0,0,0));//创建笔，并调整坐标颜色  
	pOldPen = dc.SelectObject(&pen);//更改笔并保存旧的笔  
	dc.MoveTo (-900,0);    //横坐标  
	dc.LineTo (900,0);     
	dc.MoveTo (0,-500);    //纵坐标  
	dc.LineTo (0,500);	

	//抛物线1
	//y^2=2px
	if(m_p1!=0)
	{
		double x=0,y=0; 
    	BOOL IsFirstNode = TRUE;
    	for(double jj=-10;jj<=10;jj+=0.1)
    		for(double ii=-20;ii<=20;ii+=0.1)
    		{		//乘以4是为了放大一点，看起来舒服
    			if((jj*jj)+(ii-4*m_p1)*(ii-4*m_p1)-(ii+4*m_p1)*(ii+4*m_p1)<=0.1 &&
					fabs((jj*jj)+(ii-4*m_p1)*(ii-4*m_p1)-(ii+4*m_p1)*(ii+4*m_p1))<=0.1)				
    			{
        				x = ii;				
        				y = jj;
					if(x>=-18 && x<=18)
					{
        				if(IsFirstNode)  //判断是否为第一个点
        				{
        					dc.MoveTo(50*x,50*y);   
        					IsFirstNode = FALSE;
        				}		
        				dc.LineTo(50*x,50*y);   
        				dc.MoveTo(50*x,50*y);  
					}
 
    			}
    		}
/*    	for(jj=-10;jj<=10;jj+=0.1)//画x=-p/2竖线
    	{
    		dc.MoveTo(-4*50,0);
    		dc.LineTo(-4*50,50*jj);
    	}    */
	}//if(m_p1==1)
	
	//抛物线2
	//y^2=-2px
	if(m_p2!=0)
	{
		double x=0,y=0; 
    	BOOL IsFirstNode = TRUE;
    	for(double jj=-10;jj<=10;jj+=0.1)
    		for(double ii=-20;ii<=20;ii+=0.1)
    		{		
    			if((jj*jj)+(ii*m_p2+4)*(ii*m_p2+4)-(ii*m_p2-4)*(ii*m_p2-4)<=0.1 &&
					fabs((jj*jj)+(ii*m_p2+4)*(ii*m_p2+4)-(ii*m_p2-4)*(ii*m_p2-4))<=0.1)				
    			{
    				x = ii;				
    				y = jj;
					if(x>=-18 && x<=18)
					{
        				if(IsFirstNode)  //判断是否为第一个点
        				{
        					dc.MoveTo(50*x,50*y);   
        					IsFirstNode = FALSE;
        				}		
        				dc.LineTo(50*x,50*y);   
        				dc.MoveTo(50*x,50*y);   
					}
    			}
    		}
/*    	for(jj=-10;jj<=10;jj+=0.1)//画x=p/2竖线
    	{
    		dc.MoveTo(4*50,0);
    		dc.LineTo(4*50,50*jj);
    	}    */
	}//if(m_p2==1)

	//抛物线3
	//x^2=2py
	if(m_p3!=0)
	{
		double x=0,y=0; 
    	BOOL IsFirstNode = TRUE;
    	for(double ii=-20;ii<=20;ii+=0.1)
    		for(double j=-10;j<=10;j+=0.1){		
    			if((ii*ii)+(j*m_p3-4)*(j*m_p3-4)-(j*m_p3+4)*(j*m_p3+4)<=0.1 &&
					fabs((ii*ii)+(j*m_p3-4)*(j*m_p3-4)-(j*m_p3+4)*(j*m_p3+4))<=0.1)				
    			{    
    				x = ii;				
    				y = j;
					if(x>=-18 && x<=18)
					{
        				if(IsFirstNode)  //判断是否为第一个点
        				{
        					dc.MoveTo(50*x,50*y);   
        					IsFirstNode = FALSE;
        				}		
        				dc.LineTo(50*x,50*y);   
        				dc.MoveTo(50*x,50*y);   	
					}
    			}
    		}
/*    	for(ii=-10;ii<=10;ii+=0.1)//画y=-p/2竖线
    	{
    		dc.MoveTo(0,-4*50);
    		dc.LineTo(50*ii,-4*50);
    	}    */
	}//if(m_p3==1)


	//抛物线4
	//x^2=-2py
	if(m_p4!=0)
	{
		double x=0,y=0; 
    	BOOL IsFirstNode = TRUE;
    	for(double ii=-20;ii<=20;ii+=0.1)
    		for(double j=-10;j<=10;j+=0.1){		
    			if((ii*ii)+(j*m_p4+4)*(j*m_p4+4)-(j*m_p4-4)*(j*m_p4-4)<=0.1 &&
					fabs((ii*ii)+(j*m_p4+4)*(j*m_p4+4)-(j*m_p4-4)*(j*m_p4-4))<=0.1)				
    			{
    
    				x = ii;				
    				y = j;
    				if(IsFirstNode)  //判断是否为第一个点
    				{
    					dc.MoveTo(50*x,50*y);   
    					IsFirstNode = FALSE;
    				}		
    				dc.LineTo(50*x,50*y);   
    				dc.MoveTo(50*x,50*y);   
    			}
    		}
 /*   	for(ii=-10;ii<=10;ii+=0.1)//画y=p/2竖线
    	{
    		dc.MoveTo(0,4*50);
    		dc.LineTo(50*ii,4*50);
    	}    */
	}//if(m_p4==1)

}


void CDialog2::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	MoveWindow(320,120,700,400);
	OnPicture02();
	// Do not call CDialog::OnPaint() for painting messages
}

void CDialog2::OnDrawAgain2() 
{
	// TODO: Add your control notification handler code here
	// 将各控件中的数据保存到相应的变量   
    UpdateData(TRUE);   
	OnPicture02();
	Invalidate(0);
    // 根据各变量的值更新相应的控件。 
    UpdateData(FALSE);
}

BOOL CDialog2::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
		//按回车，等于按“重画”
    if(pMsg->message == WM_KEYDOWN) 
     {
      if(pMsg->wParam == VK_RETURN)//当按下键为回车键时
      {
       OnDrawAgain2();//调用“重画”按钮函数
       return TRUE;
      }
     }	
	return CDialog::PreTranslateMessage(pMsg);
}
