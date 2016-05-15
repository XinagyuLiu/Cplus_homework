// Dialog1.cpp : implementation file
//

#include "stdafx.h"
#include "Draw1.h"
#include "Dialog1.h"
#include <math.h>
#define PI 3.141592653

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog1 dialog

double cot(double number)
{  //自定义余切函数
	return 1.0/tan(number);
}
struct Node
{
	double f[4],a[4],fai[4];
	int func; //1,2,3,4
	//分别对应sin,cos,tan,cot
	//func为0时，表示所有函数的参数为0
};
Node ForSave[10]//;={0}

void CDialog1::Save()
{
	FILE *fp;     
    fp=fopen("my.dat","wb");
    //fwrite(&ForSave,sizeof(ForSave),1,fp);     // 写1个结构
    for (int i=0;i<10;i++) fwrite(&ForSave[i],sizeof(ForSave),1,fp);    //  写10个结构
    fclose(fp);
}
void CDialog1::Open()
{
	FILE *fp;     
    fp=fopen("my.dat","rb");
    //fread(&ForSave,sizeof(ForSave),1,fp);     // 读1个结构
    for (int i=0;i<10;i++) fread(&ForSave[i],sizeof(ForSave),1,fp);    //  读 10个结构
    fclose(fp);
}

int function=0;
CDialog1::CDialog1(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog1)
	m_f = 0.0;
	m_a = 0.0;
	m_fai = 0.0;
	m_yici_a = 0.0;
	m_yici_b = 0.0;
	m_zhishu_a = 0.0;
	//}}AFX_DATA_INIT
}


void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog1)
	DDX_Text(pDX, IDC_EDIT1, m_f);
	DDX_Text(pDX, IDC_EDIT2, m_a);
	DDX_Text(pDX, IDC_EDIT3, m_fai);
	DDX_Text(pDX, IDC_EDIT_a, m_yici_a);
	DDX_Text(pDX, IDC_EDIT_b, m_yici_b);
	DDX_Text(pDX, IDC_EDIT_ZHISHU_a, m_zhishu_a);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog1, CDialog)
	//{{AFX_MSG_MAP(CDialog1)
	ON_BN_CLICKED(IDC_PICTURE01, OnPicture01)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_DRAW_AGAIN, OnDrawAgain)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_DRAW_YICI, OnDrawYici)
	ON_BN_CLICKED(IDC_DRAW_AGAIN_COS, OnDrawAgainCos)
	ON_BN_CLICKED(IDC_DRAW_AGAIN_TAN, OnDrawAgainTan)
	ON_BN_CLICKED(IDC_DRAW_AGAIN_COT, OnDrawAgainCot)
	ON_BN_CLICKED(IDC_DRAW_ZHISHU, OnDrawZhishu)
	ON_BN_CLICKED(IDC_SAVE_ALL_NODES, OnSaveAllNodes)
	ON_BN_CLICKED(IDC_CLEAR_ALL_NODES, OnClearAllNodes)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_OPEN2, OnOpen2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog1 message handlers



void CDialog1::OnPicture01() 
{
	// TODO: Add your control notification handler code here
	CRect rect;
    CWnd* pWnd = GetDlgItem(IDC_PICTURE01);
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


//------------------------------------
    if(function==-1){
    	//一次函数
    	double x=0,y=0;  
    	BOOL IsFirstNode = TRUE; 
    	for(double p=-25*3.14;p<=25*3.14;p+=0.01)    //计算点的同时画线  
    	{
    		x = p; 
    		y = m_yici_a*p + m_yici_b;
    		if(x>=-18 && x<=18 && y>=-10 && y<=10)
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
    if(function==5){
    	//指数函数
    	double x=0,y=0;  
    	BOOL IsFirstNode = TRUE; 
    	for(double p=-25*3.14;p<=25*3.14;p+=0.01)    //计算点的同时画线  
    	{
    		x = p; 
    		y = pow(m_zhishu_a,x);
    		if(x>=-18 && x<=18 && y>=-10 && y<=10)
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
    if(function==1){
    	//三角函数y=sin(x)
    	double x=0,y=0;  
    	BOOL IsFirstNode = TRUE;
    	//dc.MoveTo (0,0);   
    	for(double p=-25*3.14;p<=25*3.14;p+=0.01)    //计算点的同时画线  
    	{ 
    		x = p;
    		y = m_a*sin(m_f*(x+m_fai));
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
    if(function==2){
    	//三角函数y=cos(x)
    	double x=0,y=0;  
    	BOOL IsFirstNode = TRUE;
    	//dc.MoveTo (0,0);   
    	for(double p=-25*3.14;p<=25*3.14;p+=0.01)    //计算点的同时画线  
    	{ 
    		x = p;
    		y = m_a*cos(m_f*(x+m_fai));
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
    if(function==3){
    	//三角函数y=tan(x)
		//终于对了，看起来简单，做起来复杂
    	double x=0,y=0;  
    	BOOL IsFirstNode = TRUE;
		for(int k=-10;k<=10;k++)
		{
			for(double p=(k-0.5)*PI/m_f-m_fai;p<=(k+0.5)*PI/m_f-m_fai;p+=0.01)
        	{ 
        		x = p;
        		y = m_a*tan(m_f*(x+m_fai));
        		if(x>=-18 && x<=18 && y>=-10 && y<=10)
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
			IsFirstNode = TRUE; //重置IsFirstNode
		}
	}
    if(function==4){
    	//三角函数y=cot(x)
    	double x=0,y=0;  
    	BOOL IsFirstNode = TRUE;
		for(int k=-10;k<=10;k++)
		{
			for(double p=(k)*PI/m_f-m_fai;p<=(k+1)*PI/m_f-m_fai;p+=0.01)
        	{ 
        		x = p;
        		y = m_a*cot(m_f*(x+m_fai));
        		if(x>=-18 && x<=18 && y>=-10 && y<=10)
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
			IsFirstNode = TRUE; //重置IsFirstNode
		}
	}
}

void CDialog1::OnPaint() 
{	
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
	MoveWindow(320,120,775,550);
	OnPicture01();

}

void CDialog1::OnDrawAgain() 
{  //原来为“重画”按钮，后来改为“画正弦”
	// TODO: Add your control notification handler code here
	
	// 将各控件中的数据保存到相应的变量   
    UpdateData(TRUE);   
	function = 1;
	OnPicture01();
	Invalidate(0);
    // 根据各变量的值更新相应的控件。 
    UpdateData(FALSE);   
}
/**/
HBRUSH CDialog1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	//似乎这段程序不起作用
	// TODO: Change any attributes of the DC here
	if (nCtlColor==CTLCOLOR_STATIC)
	{
		pDC-> SetTextColor(RGB(0,0,0)); //字体颜色
		pDC-> SetBkMode(TRANSPARENT);// 背景透明
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CDialog1::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	//按回车，等于按“画正弦”
    if(pMsg->message == WM_KEYDOWN) 
     {
      if(pMsg->wParam == VK_RETURN)//当按下键为回车键时
      {
       OnDrawAgainTan();//调用“正切”按钮函数
       return TRUE;
      }
     }	
	return CDialog::PreTranslateMessage(pMsg);
}

void CDialog1::OnDrawYici() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   
	function = -1;
	OnPicture01();
	Invalidate(0);
    UpdateData(FALSE);  	
}

void CDialog1::OnDrawAgainCos() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   
	function = 2;
	OnPicture01();
	Invalidate(0);
    UpdateData(FALSE); 	
}

void CDialog1::OnDrawAgainTan() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   
	function = 3;
	OnPicture01();
	Invalidate(0);
    UpdateData(FALSE); 		
}

void CDialog1::OnDrawAgainCot() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   
	function = 4;
	OnPicture01();
	Invalidate(0);
    UpdateData(FALSE); 		
}

void CDialog1::OnDrawZhishu() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   
	function = 5;
	OnPicture01();
	Invalidate(0);
    UpdateData(FALSE); 		
}

int s = 1,k;
void CDialog1::OnSaveAllNodes() 
{
	// TODO: Add your control notification handler code here
	k = s-1;
	CString str;
	s++;
    GetDlgItem(IDC_NOTES)->GetWindowText(str);
	str.Format("点击保存后，保存为第%d个函数",s);
    GetDlgItem(IDC_NOTES)->SetWindowText(str);	
	UpdateData(TRUE);	//这不能少，很关键，不容易察觉错误
	if(function==1)
	{   //保存sin(x)参数
	 	ForSave[k].f[0] = m_f;
		ForSave[k].a[0] = m_a;
		ForSave[k].fai[0] = m_fai;
		ForSave[k].func = 1;
	}
	if(function==2)
	{   //保存cos(x)参数
	 	ForSave[k].f[0] = m_f;
		ForSave[k].a[0] = m_a;
		ForSave[k].fai[0] = m_fai;
		ForSave[k].func = 2;
	}
	if(function==3)
	{   //保存tan(x)参数
	 	ForSave[k].f[0] = m_f;
		ForSave[k].a[0] = m_a;
		ForSave[k].fai[0] = m_fai;
		ForSave[k].func = 3;
	}
	if(function==4)
	{   //保存cot(x)参数
	 	ForSave[k].f[0] = m_f;
		ForSave[k].a[0] = m_a;
		ForSave[k].fai[0] = m_fai;
		ForSave[k].func = 4;
	}
	Save();	
}

void CDialog1::OnClearAllNodes() 
{
	// TODO: Add your control notification handler code here
	for(int i=0;i<10;i++)
		for(int j=0;j<4;j++)
		{
			ForSave[k].f[0] = 0;
			ForSave[k].a[0] = 0;
			ForSave[k].fai[0] = 0;
			ForSave[i].func=0; 
		}
	m_f = 0;
	m_a = 0;
	m_fai = 0;
	UpdateData(FALSE);
	Save(); //不写它，没起到作用
	s = 1;
	GetDlgItem(IDC_NOTES)->SetWindowText("点击保存后，保存为第1个函数");
	GetDlgItem(IDC_HANSHU_TISHI)->SetWindowText("*****");	
}

void CDialog1::OnOpen() 
{
	// TODO: Add your control notification handler code here
	Open();
 	m_f = ForSave[0].f[0];
	m_a = ForSave[0].a[0];
	m_fai = ForSave[0].fai[0];
    UpdateData(FALSE);	
	if(ForSave[0].func == 1)
		GetDlgItem(IDC_HANSHU_TISHI)->SetWindowText("现在打开的函数类型为：y=sin(x)");
	if(ForSave[0].func == 2)
		GetDlgItem(IDC_HANSHU_TISHI)->SetWindowText("现在打开的函数类型为：y=cos(x)");
	if(ForSave[0].func == 3)
		GetDlgItem(IDC_HANSHU_TISHI)->SetWindowText("现在打开的函数类型为：y=tan(x)");
	if(ForSave[0].func == 4)
		GetDlgItem(IDC_HANSHU_TISHI)->SetWindowText("现在打开的函数类型为：y=cot(x)");/**/
}

void CDialog1::OnOpen2() 
{
	// TODO: Add your control notification handler code here
	Open();
 	m_f = ForSave[1].f[0];
	m_a = ForSave[1].a[0];
	m_fai = ForSave[1].fai[0];
    UpdateData(FALSE);		
	if(ForSave[1].func == 1)
		GetDlgItem(IDC_HANSHU_TISHI)->SetWindowText("现在打开的函数类型为：y=sin(x)");
	if(ForSave[1].func == 2)
		GetDlgItem(IDC_HANSHU_TISHI)->SetWindowText("现在打开的函数类型为：y=cos(x)");
	if(ForSave[1].func == 3)
		GetDlgItem(IDC_HANSHU_TISHI)->SetWindowText("现在打开的函数类型为：y=tan(x)");
	if(ForSave[1].func == 4)
		GetDlgItem(IDC_HANSHU_TISHI)->SetWindowText("现在打开的函数类型为：y=cot(x)");	
}
