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
	CClientDC dc(pWnd);		//���ǻ�ȡͼƬ���ָ��
    //CClientDC dc(this);  //���ǻ�ȡ�����Ի����ָ��
	
//*************************************
	//����ϵ   
	dc.FillSolidRect(rect,RGB(255,255,255));   //����Ϊ��ɫ����
	dc.SetMapMode(MM_LOMETRIC);      //����ӳ��ģʽ
	dc.SetWindowOrg(0,0);                //������Ļ����ԭ��
	dc.SetViewportOrg(CPoint(rect.right/2,rect.bottom/2)); //�����ӿ�ԭ��
	CPen pen1(PS_DOT,1,RGB(100,100,100));  //�����ʣ�������������ɫ
	CPen *pOldPen = dc.SelectObject(&pen1);  //���ıʲ�����ɵı�
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
	dc.TextOut (10,500,'y');     //���y��   ��(10,500)�����'y'
	dc.TextOut (870,0,'x');      //���x��  
	dc.TextOut (0,0,'0');        //�������ԭ��  
	dc.TextOut (-8,510,'^');  
	dc.TextOut (900,25,'>');  
	CPen pen(PS_SOLID,1,RGB(0,0,0));//�����ʣ�������������ɫ  
	pOldPen = dc.SelectObject(&pen);//���ıʲ�����ɵı�  
	dc.MoveTo (-900,0);    //������  
	dc.LineTo (900,0);     
	dc.MoveTo (0,-500);    //������  
	dc.LineTo (0,500);	

	//������1
	//y^2=2px
	if(m_p1!=0)
	{
		double x=0,y=0; 
    	BOOL IsFirstNode = TRUE;
    	for(double jj=-10;jj<=10;jj+=0.1)
    		for(double ii=-20;ii<=20;ii+=0.1)
    		{		//����4��Ϊ�˷Ŵ�һ�㣬���������
    			if((jj*jj)+(ii-4*m_p1)*(ii-4*m_p1)-(ii+4*m_p1)*(ii+4*m_p1)<=0.1 &&
					fabs((jj*jj)+(ii-4*m_p1)*(ii-4*m_p1)-(ii+4*m_p1)*(ii+4*m_p1))<=0.1)				
    			{
        				x = ii;				
        				y = jj;
					if(x>=-18 && x<=18)
					{
        				if(IsFirstNode)  //�ж��Ƿ�Ϊ��һ����
        				{
        					dc.MoveTo(50*x,50*y);   
        					IsFirstNode = FALSE;
        				}		
        				dc.LineTo(50*x,50*y);   
        				dc.MoveTo(50*x,50*y);  
					}
 
    			}
    		}
/*    	for(jj=-10;jj<=10;jj+=0.1)//��x=-p/2����
    	{
    		dc.MoveTo(-4*50,0);
    		dc.LineTo(-4*50,50*jj);
    	}    */
	}//if(m_p1==1)
	
	//������2
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
        				if(IsFirstNode)  //�ж��Ƿ�Ϊ��һ����
        				{
        					dc.MoveTo(50*x,50*y);   
        					IsFirstNode = FALSE;
        				}		
        				dc.LineTo(50*x,50*y);   
        				dc.MoveTo(50*x,50*y);   
					}
    			}
    		}
/*    	for(jj=-10;jj<=10;jj+=0.1)//��x=p/2����
    	{
    		dc.MoveTo(4*50,0);
    		dc.LineTo(4*50,50*jj);
    	}    */
	}//if(m_p2==1)

	//������3
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
        				if(IsFirstNode)  //�ж��Ƿ�Ϊ��һ����
        				{
        					dc.MoveTo(50*x,50*y);   
        					IsFirstNode = FALSE;
        				}		
        				dc.LineTo(50*x,50*y);   
        				dc.MoveTo(50*x,50*y);   	
					}
    			}
    		}
/*    	for(ii=-10;ii<=10;ii+=0.1)//��y=-p/2����
    	{
    		dc.MoveTo(0,-4*50);
    		dc.LineTo(50*ii,-4*50);
    	}    */
	}//if(m_p3==1)


	//������4
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
    				if(IsFirstNode)  //�ж��Ƿ�Ϊ��һ����
    				{
    					dc.MoveTo(50*x,50*y);   
    					IsFirstNode = FALSE;
    				}		
    				dc.LineTo(50*x,50*y);   
    				dc.MoveTo(50*x,50*y);   
    			}
    		}
 /*   	for(ii=-10;ii<=10;ii+=0.1)//��y=p/2����
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
	// �����ؼ��е����ݱ��浽��Ӧ�ı���   
    UpdateData(TRUE);   
	OnPicture02();
	Invalidate(0);
    // ���ݸ�������ֵ������Ӧ�Ŀؼ��� 
    UpdateData(FALSE);
}

BOOL CDialog2::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
		//���س������ڰ����ػ���
    if(pMsg->message == WM_KEYDOWN) 
     {
      if(pMsg->wParam == VK_RETURN)//�����¼�Ϊ�س���ʱ
      {
       OnDrawAgain2();//���á��ػ�����ť����
       return TRUE;
      }
     }	
	return CDialog::PreTranslateMessage(pMsg);
}
