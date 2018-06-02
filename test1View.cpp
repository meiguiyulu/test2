// test1View.cpp : implementation of the CTest1View class
//

#include "stdafx.h"
#include "test1.h"

#include "test1Doc.h"
#include "test1View.h"

#include "inputdlg.h"
#include "math.h"
#include "CLine.h"

#include "ALine.h"
#include "P3.h"

#include "Vector.h"
#include "ZBuffer.h"
#include "Transform.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define PI 3.1415926
#define Round(d) int(floor(d+0.5))
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest1View

IMPLEMENT_DYNCREATE(CTest1View, CView)

BEGIN_MESSAGE_MAP(CTest1View, CView)
	//{{AFX_MSG_MAP(CTest1View)
	ON_COMMAND(IDM_zdsf, Onzdsf)
	ON_COMMAND(IDM_DrawPic, OnDrawPic)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_Fill, OnDrawColor)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(IDM_ANT, OnAnt)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_COMMAND(IDM_Rotate, OnRotate)
	ON_COMMAND(IDM_OnePoint, OnOnePoint)
	ON_COMMAND(IDM_DoublePoint, OnDoublePoint)
	ON_COMMAND(IDM_ThreePoint, OnThreePoint)
	ON_WM_KEYDOWN()
	ON_COMMAND(IDM_OnePointStar, OnOnePointStar)
	ON_COMMAND(IDM_DoublePointStar, OnDoublePointStar)
	ON_COMMAND(IDM_ThreePointStar, OnThreePointStar)
	ON_COMMAND(IDM_RotateFIveStars, OnRotateFIveStars)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest1View construction/destruction

CTest1View::CTest1View()
{
	// TODO: add construction code here

}

CTest1View::~CTest1View()
{
}

BOOL CTest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest1View drawing

void CTest1View::OnDraw(CDC* pDC)
{
	CTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	/*CALine *line=new CALine;
	line->MoveTo(pDC,CP2(200,200));
	line->LineTo(pDC,CP2(800,400));
	delete line;
	ReleaseDC(pDC);*/

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest1View printing

BOOL CTest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest1View diagnostics

#ifdef _DEBUG
void CTest1View::AssertValid() const
{
	CView::AssertValid();
}

void CTest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest1Doc* CTest1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest1Doc)));
	return (CTest1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest1View message handlers

void CTest1View::Onzdsf() 
{
	// TODO: Add your command handler code here
	CInputDlg  dlg;
	if (IDOK==dlg.DoModal())
	{
		n=dlg.m_n;
		r=dlg.m_r;
	}
	else
		return;
	RedrawWindow();
	p=new CP2[n];
	Diamond();
	delete []p;
	
}

void CTest1View::Diamond()
{
	CDC *pDC=GetDC();
	CRect rect;
	GetClientRect(&rect);


	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,1,RGB(0,0,255));
	pOldPen=pDC->SelectObject(&NewPen);
	
	CCLine *line=new CCLine;
	double Alpha,Theta;
	Theta=2*PI/n;
	Alpha=PI/2-Theta;

	for(int i=0;i<n;i++)
	{
		p[i].x=r*cos(i*Theta+Alpha);//计算各个顶点坐标
		p[i].y=r*sin(i*Theta+Alpha);
		p[i].c=CRGB(0,1,1);
	}
	for( i=n/2;i<n;i++)
	{
		p[i].x=r*cos(i*Theta+Alpha);//计算各个顶点坐标
		p[i].y=r*sin(i*Theta+Alpha);
		p[i].c=CRGB(1,1,0);
	}
	for( i=0;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			line->MoveTo(pDC,p[i]);
			line->LineTo(pDC,p[j]);
			//MidPointLine(p[i],p[j]);
		}
	}
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
	ReleaseDC(pDC);
}


void CTest1View::MidPointLine(CP2 p1, CP2 p2)//中点算法
{
	CDC *pDC=GetDC();
	CP2 point;
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//改变原点
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);

	if (p2.x<p1.x)
	{
		point=p1;
		p1=p2;
		p2=point;
	}
	int dx=p2.x-p1.x;// delat x
	int dy=p2.y-p1.y;// delat y

	int d,d1,d2;
	float k;
	int y=p1.y;
	int x=p1.x;
	if(dx==0)
	{
		do
		{
			pDC->SetPixel(x,y,RGB(0,0,255));
			y++;
		}while(y<=p2.y);
	}
	else
		k=dy/(float)dx;

     if(k>=0&&k<=1)
	 {
	    d=dx-2*dy;
		d1=-2*dy;
		d2=-2*(dy-dx);
		do
		{
			pDC->SetPixel(x,y,RGB(0,0,255));
			if(d>0)
				d=d+d1;
			else
			{
				d=d+d2;
				y++;
			}
			x++;
		}while(x<p2.x);
	 }
	 else if(k>1)
	 {
		d=2*dx-dy;
		d1=2*dx-2*dy;
		d2=2*dx;
		do
		{
			pDC->SetPixel(x,y,RGB(0,0,255));
			if(d>0)
			{
				d=d+d1;
				x++;
			}
			else
			{
				d=d+d2;
			}
			y++;
		}while(y<p2.y);
	 }
	 else if(k<-1)
	 {
		 d=-2*dx-dy;
		 d1=-2*dx;
		 d2=2*(-dx-dy);
		 do
		 {
			pDC->SetPixel(x,y,RGB(0,0,255));
			if(d>0)
				d=d+d1;
			else
			{
				d=d+d2;
				x++;
			}
			y--;
		 }while(y>p2.y);
	 }
	 else
	 {
		 d=-2*dy-dx;
		 d1=-2*dy-2*dx;
		 d2=-2*dy;
		 do
		 {
			 pDC->SetPixel(x,y,RGB(0,0,255));
			 if(d>0)
			 {
				 d=d+d1;
				 y--;
			 }
			 else
			 {
				 d=d+d2;
			 }
			 x++;
		 }while(x<p2.x);
	 }

}

void CTest1View::OnDrawPic() //绘制多边形、闭合框
{
	// TODO: Add your command handler code here
	flag = true;
	count = 0;
	
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//显示DC自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);

	ReleaseDC(pDC);

	Invalidate(TRUE);
	UpdateWindow();//立即刷新
}

void CTest1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CDC *pDC = GetDC();

	if (flag == true && count < 7)
	{
		PolyPoint[count].x = point.x;
		PolyPoint[count].y = point.y;
		count++;
	}	
	
	if (PolyFlag == true)
	{
		CRect rect;
		GetClientRect(&rect);
		pDC->SetMapMode(MM_ANISOTROPIC);//显示DC自定义坐标系
		pDC->SetWindowExt(rect.Width(),rect.Height());
		pDC->SetViewportExt(rect.Width(),-rect.Height());
		pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);

		Invalidate(TRUE);
		UpdateWindow();//立即刷新
		R = R - 100;
		InitParameter();
		DrawObject(pDC);
	}
	ReleaseDC(pDC);

	CView::OnLButtonDown(nFlags, point);
}

void CTest1View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDC *pDC = GetDC();

	if (flag == true)
	{
		pDC->MoveTo(PolyPoint[0].x,PolyPoint[0].y);
		for (int i = 0;i<count;i++)
		{
			pDC->LineTo(PolyPoint[i].x,PolyPoint[i].y);
		}
		pDC->LineTo(PolyPoint[0].x,PolyPoint[0].y);
	}

	if (PolyFlag == true)
	{
		CRect rect;
		GetClientRect(&rect);
		pDC->SetMapMode(MM_ANISOTROPIC);//显示DC自定义坐标系
		pDC->SetWindowExt(rect.Width(),rect.Height());
		pDC->SetViewportExt(rect.Width(),-rect.Height());
		pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
		
		Invalidate(TRUE);
		UpdateWindow();//立即刷新
		R = R + 100;
		InitParameter();
		DrawObject(pDC);
	}
	
	ReleaseDC(pDC);
	
	CView::OnRButtonDown(nFlags, point);
}


void CTest1View::OnDrawColor() 
{
	// TODO: Add your command handler code here
	CColorDialog ccd(GetClr,CC_SOLIDCOLOR);
	if (IDOK == ccd.DoModal())
	{
		GetClr = ccd.GetColor();
	}
	else
		return;
	if (IDOK == MessageBox("请在空心字体内双击鼠标左键!","提示",MB_OKCANCEL))
	{
		bFill = true;
	}
	else
		return;
	//InvalidateRect(false);	
}

void CTest1View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetClr = RGB(255,0,0);
	bFill = false;
	ReadStarPoint();
	ReadStarFace();	
	tran.SetMat(StarPoint,12);//
	InitParameter();

}

void CTest1View::Push(CP2 point)
{
	pTop=new CStackNode;
	pTop->PiexlPoint=point;
	pTop->pNext=pHead->pNext;
	pHead->pNext=pTop;
}

void CTest1View::Pop(CP2 &point)
{
	if (pHead->pNext!=NULL)
	{
		pTop = pHead->pNext;
		pHead->pNext = pTop->pNext;
		point = pTop->PiexlPoint;
		delete pTop;
	}
}

void CTest1View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if(flag == true)
	{
		Seed=CP2(point.x-rect.Width()/2,rect.Height()/2-point.y);//选择种子位置
		CDC *pDC=GetDC();
		FillPolygon(pDC);
		Invalidate(FALSE);
	}
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CTest1View::FillPolygon(CDC *pDC)
{
	COLORREF BoundaryClr=RGB(0,0,0);
	BOOL bSpanFill;
	pHead=new CStackNode;
	pHead->pNext=NULL;
	Push(Seed);
	int x,y,x0=Round(Seed.x),y0=Round(Seed.y);
	
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//改变原点
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);

	x=x0-1;
	while(pDC->GetPixel(x,y0)!=BoundaryClr && pDC->GetPixel(x,y0)!=GetClr)//左方判断
	{
		x--;
		if(x<=-rect.Width()/2)
		{
			MessageBox("种子在图形左侧","警告");
			return;
		}
	}
	y=y0+1;
	while(pDC->GetPixel(x0,y)!=BoundaryClr && pDC->GetPixel(x0,y)!=GetClr)//上方判断
	{
		y++;
		if(y>=rect.Height()/2)
		{
			MessageBox("种子在图形上册","警告");
			return;
		}
	}
	x=x0+1;
	while(pDC->GetPixel(x,y0)!=BoundaryClr && pDC->GetPixel(x,y0)!=GetClr)//右方判断
	{
		x++;
		if(x>=rect.Width()/2)
		{
			MessageBox("种子在图形右侧","警告");		
			return;
		}
	}
	y=y0-1;
	while(pDC->GetPixel(x0,y)!=BoundaryClr && pDC->GetPixel(x0,y)!=GetClr)//下方判断
	{
		y--;
		if(y<=-rect.Height()/2)
		{
			MessageBox("种子在图形下册","警告");
			return;
		}
	}
	
	double xleft,xright;
	CP2 PopPoint,PointTemp;

	while (pHead->pNext!=NULL)
	{
		Pop(PopPoint);
		if (pDC->GetPixel(Round(PopPoint.x),Round(PopPoint.y))==GetClr)
			continue;
		PointTemp = PopPoint;
		while(pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=BoundaryClr && pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=GetClr)
		{
			pDC->SetPixelV(Round(PointTemp.x),Round(PointTemp.y),GetClr);
			PointTemp.x++;
		}
		xright=PointTemp.x-1;
		PointTemp.x=PopPoint.x-1;
		while(pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=BoundaryClr && pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=GetClr)
		{
			pDC->SetPixelV(Round(PointTemp.x),Round(PointTemp.y),GetClr);
			PointTemp.x--;
		}
		xleft=PointTemp.x+1;

		//处理上一条扫描线
		PointTemp.x=xleft;
		PointTemp.y=PointTemp.y+1;
		while(PointTemp.x<xright)
		{
			bSpanFill=FALSE;
			while(pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=BoundaryClr && pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=GetClr)
			{
				bSpanFill=TRUE;
				PointTemp.x++;
			}
			if(bSpanFill)
			{
				if(PointTemp.x==xright && pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=BoundaryClr && pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=GetClr)
					PopPoint=PointTemp;
				else
				{
					PopPoint.x=PointTemp.x-1;
					PopPoint.y=PointTemp.y;
				}
				Push(PopPoint);
				bSpanFill=FALSE;
			}
			while((pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))==BoundaryClr && PointTemp.x<xright) || (pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))==GetClr && PointTemp.x<xright))
				PointTemp.x++;
		}
		//处理下一条扫描线
		PointTemp.x=xleft;
		PointTemp.y=PointTemp.y-2;
		while(PointTemp.x<xright)
		{
			bSpanFill=FALSE;
			while(pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=BoundaryClr && pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=GetClr)
			{
				bSpanFill=TRUE;
				PointTemp.x++;
			}
			if(bSpanFill)
			{
				if(PointTemp.x==xright && pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=BoundaryClr && pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))!=GetClr)
					PopPoint=PointTemp;
				else
				{
					PopPoint.x=PointTemp.x-1;
					PopPoint.y=PointTemp.y;
				}
				Push(PopPoint);
				bSpanFill=FALSE;
			}
			while((pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))==BoundaryClr && PointTemp.x<xright) || (pDC->GetPixel(Round(PointTemp.x),Round(PointTemp.y))==GetClr && PointTemp.x<xright))
				PointTemp.x++;
		}
	}
	delete pHead;
	pHead=NULL;
}

void CTest1View::OnAnt() //绘制反走样
{
	// TODO: Add your command handler code here
	AntFlag = TRUE;
	CDC *pDC = GetDC();
	
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width(),-rect.Height());
	
	CALine *line =  new CALine;

	sp1 = CP2(-300,300);
	sp2 = CP2(-120,80);

	line->MoveTo(pDC,sp1);
	line->LineTo(pDC,sp2);

	A[0][0] = sp1.x; A[0][1] = sp1.y; A[0][2] = 1;
	A[1][0] = sp2.x; A[1][1] = sp2.y; A[1][2] = 1;
	A[2][0] = 0;     A[2][1] = 0;     A[2][2] = 1;

	SetTimer(1,800,NULL);

	//point = Rolate(p1,p2);
}

void CTest1View::matrix_mul(float A[][3], float B[][3], float C[][3], int m, int p, int n)
{
	int i,j,k;
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			C[i][j]=0;
			for(k=0;k<n;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
	
}

void CTest1View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CDC *pDC = GetDC();
	switch (nIDEvent)
	{
	case 1://反走样直线
		DoubleBuffer();
		break;
	case 2://正方体旋转
		DoubleBufferThree();
		break;
	case 3://五角星旋转
		DoubleBufferStar(pDC);
		break;
	}

	ReleaseDC(pDC);
	CView::OnTimer(nIDEvent);
}

void CTest1View::DoubleBuffer()
{
	Invalidate(TRUE);
	UpdateWindow();//立即刷新
	
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width(),-rect.Height()); 	
	CALine *line =  new CALine;
	
	int s,t;
	if (sp1.x<=0 && sp1.y>0)//第二象限
	{
		t = 10;
		s = 10;
	}
	else if (sp1.x>0 && sp1.y >= 0)//第一象限
	{
		t =10;
		s = -10;
	}
	else if (sp1.x>=0 && sp1.y<0)//第四象限
	{
		t = -10;
		s = -10;
	}
	else if (sp1.x<0 && sp1.y<=0)//第三象限
	{
		t = -10;
		s = 10;
	}
	
	float a[3][3] = {1,0,0,0,1,0,t,s,1};//平移矩阵
	float b[3][3] = {0.985,-0.174,0,0.174,0.985,0,0,0,1};//旋转矩阵
	float C[3][3],D[3][3];
	
	matrix_mul(A,b,C,3,3,3);
	matrix_mul(C,a,D,3,3,3);

	CDC demen;
	CBitmap	bmp; //内存中承载临时图象的位图

	demen.CreateCompatibleDC(pDC);//依附窗口DC创建兼容内存DC
	//创建兼容位图(必须用pDC创建，否则画出的图形变成黑色)
	bmp.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
	CBitmap *pOldBit=demen.SelectObject(&bmp);//按原来背景填充客户区，不然会是黑色
    demen.FillSolidRect(rect,RGB(255,255,255));



	line->MoveTo(pDC,D[0][0],D[0][1]);
	line->LineTo(pDC,D[1][0],D[1][1]);

/*	demen.MoveTo(D[0][0],D[0][1]);
	demen.LineTo(D[1][0],D[1][0]);*/
	
	A[0][0] = D[0][0]; A[0][1] = D[0][1];
	A[1][0] = D[1][0]; A[1][1] = D[1][1];

	pDC->BitBlt(-rect.Width(),rect.Height(),rect.Width(),rect.Height(),&demen,0,0,SRCCOPY);
	
	
	demen.DeleteDC();
	bmp.DeleteObject();	
	delete line;
	ReleaseDC(pDC);
}

BOOL CTest1View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	//return true;
	return CView::OnEraseBkgnd(pDC);
}

void CTest1View::ReadPoint()//旋转正方体点表
{
	double a = 150;
	p3[0].x=-a;p3[0].y=-a;p3[0].z=-a;p3[0].c=CRGB(0,1,1);
	p3[1].x=+a;p3[1].y=-a;p3[1].z=-a;p3[1].c=CRGB(0,0.5,1);
	p3[2].x=+a;p3[2].y=+a;p3[2].z=-a;p3[2].c=CRGB(0,1,1);
	p3[3].x=-a;p3[3].y=+a;p3[3].z=-a;p3[3].c=CRGB(1,0.5,1);
	p3[4].x=-a;p3[4].y=-a;p3[4].z=+a;p3[4].c=CRGB(0,0.5,0.3);
	p3[5].x=+a;p3[5].y=-a;p3[5].z=+a;p3[5].c=CRGB(0,0.2,1);
	p3[6].x=+a;p3[6].y=+a;p3[6].z=+a;p3[6].c=CRGB(0.6,1,1);
	p3[7].x=-a;p3[7].y=+a;p3[7].z=+a;p3[7].c=CRGB(0.4,1,1);
}

void CTest1View::ReadFace()//旋转正方体面表
{
	F3[0].SetNum(4);F3[0].vI[0]=4;F3[0].vI[1]=5;F3[0].vI[2]=6;F3[0].vI[3]=7;
	F3[1].SetNum(4);F3[1].vI[0]=0;F3[1].vI[1]=3;F3[1].vI[2]=2;F3[1].vI[3]=1;
	F3[2].SetNum(4);F3[2].vI[0]=0;F3[2].vI[1]=4;F3[2].vI[2]=7;F3[2].vI[3]=3;
	F3[3].SetNum(4);F3[3].vI[0]=1;F3[3].vI[1]=2;F3[3].vI[2]=6;F3[3].vI[3]=5;
	F3[4].SetNum(4);F3[4].vI[0]=2;F3[4].vI[1]=3;F3[4].vI[2]=7;F3[4].vI[3]=6;
	F3[5].SetNum(4);F3[5].vI[0]=0;F3[5].vI[1]=1;F3[5].vI[2]=5;F3[5].vI[3]=4;
}

void CTest1View::OnRotate() 
{
	// TODO: Add your command handler code here
	Invalidate(TRUE);
	UpdateWindow();//立即刷新

	if (AntFlag)
	{
		KillTimer(1);
		AntFlag = FALSE;
	}
	if (Theta==0 && Phi==0)
	{ 
		Theta = 0;
		Phi = 90;
		R = 1000;
		d = 900;
		ReadPoint();
		ReadFace();
	}
	RotateFlag = TRUE;//正方体在旋转
	PolyFlag = TRUE;

	SetTimer(2,1000,NULL);
}

void CTest1View::DrawObject(CDC *pDC)//绘制线框模型
{
	for (int nFace=0;nFace<6;nFace++)
	{
		CVector ViewVector(p3[F3[nFace].vI[0]],ViewPoint);
		ViewVector = ViewVector.Normalize();
		F3[nFace].SetFaceNormal(p3[F3[nFace].vI[0]],p3[F3[nFace].vI[1]],p3[F3[nFace].vI[2]]);
		F3[nFace].fNormal.Normalize();
		if (Dot(ViewVector,F3[nFace].fNormal)>=0)
		{
			CP2 t;
			CCLine *line = new CCLine;
			for (int nVertex=0;nVertex<F3[nFace].vN;nVertex++)
			{
				PerProject(p3[F3[nFace].vI[nVertex]]);
				if (nVertex==0)
				{
					line->MoveTo(pDC,ScreenP);
					t = ScreenP;
				}
				else
				{
					line->LineTo(pDC,ScreenP);
					line->MoveTo(pDC,ScreenP);
				}
			}
			line->LineTo(pDC,t);
			delete line;
		}
	}
}

	void CTest1View::InitParameter()//透视变换参数初始化
{
	k[1] = sin(PI*Theta/180);
	k[2] = sin(PI*Phi/180);
	k[3] = cos(PI*Theta/180);
	k[4] = cos(PI*Phi/180);
	k[5] = k[2] * k[3];
	k[6] = k[2] * k[1];
	k[7] = k[4] * k[3];
	k[8] = k[4] * k[1];
	ViewPoint.x=R*k[6];
	ViewPoint.y=R*k[4];
	ViewPoint.z=R*k[5];
/*	CString str;
	str.Format("%d",Theta);
	MessageBox(str);*/
}


void CTest1View::OnOnePoint() //一点透视
{
	// TODO: Add your command handler code her
	if (AntFlag)//反走样直线在旋转
	{
		KillTimer(1);
		AntFlag = FALSE;
	}
	if (RotateFlag)//正方体在旋转
	{
		KillTimer(2);
		RotateFlag = FALSE;
	}

	PolyFlag = true;
	
	Invalidate(TRUE);
	UpdateWindow();

	Theta = 0;
	Phi = 90;
	R = 1000;
	d = 900;
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width(),-rect.Height()); 

	ReadPoint();
	ReadFace();
	InitParameter();
	DrawObject(pDC);

	ReleaseDC(pDC);
}

void CTest1View::PerProject(CP3 pp)//透视变换
{
	CP3 ViewP;
	ViewP.x=k[3]*pp.x-k[1]*pp.z;//观察坐标系三维坐标
	ViewP.y=-k[8]*pp.x+k[2]*pp.y-k[7]*pp.z;
	ViewP.z=-k[6]*pp.x-k[4]*pp.y-k[5]*pp.z+R;
	ViewP.c=pp.c;
    ScreenP.x=d*ViewP.x/ViewP.z;//屏幕坐标系二维坐标
	ScreenP.y=d*ViewP.y/ViewP.z;
	ScreenP.c=ViewP.c;
}

void CTest1View::OnDoublePoint() //二点透视
{
	// TODO: Add your command handler code here
	if (AntFlag)//反走样直线在旋转
	{
		KillTimer(1);
		AntFlag = FALSE;
	}
	if (RotateFlag)//正方体在旋转
	{
		KillTimer(2);
		RotateFlag = FALSE;
	}
	PolyFlag = true;
	
	Invalidate(TRUE);
	UpdateWindow();

	Theta = 30;
	Phi = 90;
	R = 1000;
	d = 900;

	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width(),-rect.Height()); 

	ReadPoint();
	ReadFace();
	InitParameter();
	DrawObject(pDC);

	ReleaseDC(pDC);
}

void CTest1View::OnThreePoint() //三点透视
{
	// TODO: Add your command handler code here
	if (AntFlag)//反走样直线在旋转
	{
		KillTimer(1);
		AntFlag = FALSE;
	}
	if (RotateFlag)//正方体在旋转
	{
		KillTimer(2);
		RotateFlag = FALSE;
	}

	PolyFlag = true;
	
	Invalidate(TRUE);
	UpdateWindow();
	Theta = 45;
	Phi = 45;
	R = 1000;
	d = 900;
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width(),-rect.Height()); 
	ReadPoint();
	ReadFace();
	InitParameter();
	DrawObject(pDC);

	ReleaseDC(pDC);
}

void CTest1View::DoubleBufferThree()//正方体的双缓冲
{
	Invalidate(TRUE);
	UpdateWindow();

	CDC *pDC = GetDC(); 
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);

	Theta = Theta - 5;
	Phi = Phi - 5;
	InitParameter();

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap NewBitmap,*pOldBitmap;
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
	pOldBitmap=memDC.SelectObject(&NewBitmap);

	memDC.FillSolidRect(rect,pDC->GetBkColor());
	memDC.SetMapMode(MM_ANISOTROPIC);
	memDC.SetWindowExt(rect.Width(),rect.Height());
	memDC.SetViewportExt(rect.Width(),-rect.Height());
	memDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
	
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2); 
	DrawObject(&memDC);
		
	pDC->BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);

	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	NewBitmap.DeleteObject();
	
	ReleaseDC(pDC);
}

void CTest1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width(),-rect.Height()); 

	if (PolyFlag == true)//正方体
	{
		switch(nChar)
		{
		case VK_UP:
			Invalidate(TRUE);
			UpdateWindow();

			Phi = Phi -5;
			InitParameter();
			DrawObject(pDC);
			break;
		case VK_DOWN:
			Invalidate(TRUE);
			UpdateWindow();

			Phi = Phi + 5;
			InitParameter();
			DrawObject(pDC);
			break;
		case VK_LEFT:
			Invalidate(TRUE);
			UpdateWindow();

			Theta = Theta - 5;
			InitParameter();
			DrawObject(pDC);
			break;
		case VK_RIGHT:
			Invalidate(TRUE);
			UpdateWindow();

			Theta = Theta + 5;
			InitParameter();
			DrawObject(pDC);
			break;
		}
	}
	if (StarFlag == true)//五角星
	{
		switch(nChar)
		{
		case VK_UP:
			Invalidate(TRUE);
			UpdateWindow();
			
			StarPhi = StarPhi -5;
			InitParameterStar();
			DrawStarObject(pDC);
			break;
		case VK_DOWN:
			Invalidate(TRUE);
			UpdateWindow();
			
			StarPhi = StarPhi + 5;
			InitParameter();
			DrawStarObject(pDC);
			break;
		case VK_LEFT:
			Invalidate(TRUE);
			UpdateWindow();
			
			StarTheta = StarTheta - 5;
			InitParameterStar();
			DrawStarObject(pDC);
			break;
		case VK_RIGHT:
			Invalidate(TRUE);
			UpdateWindow();
			
			StarTheta = StarTheta + 5;
			InitParameterStar();
			DrawStarObject(pDC);
			break;
		}
	}
	ReleaseDC(pDC);
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CTest1View::ReadStarPoint()//五角星顶点表
{
	int RR,rr,s;
	double jiao = 36*PI/180;
	rr=120;
	RR=rr*(1+2*cos(jiao));
	for(s=0;s<10;s++)
	{
		if(s%2==0)
		{
			StarPoint[s].x=RR*sin(s*jiao);
			StarPoint[s].y=RR*cos(s*jiao);
			StarPoint[s].z=0;
			StarPoint[s].c=CRGB(0,1,0);
			
		}
		else if(s%2==1)
		{
			StarPoint[s].x=rr*sin(s*jiao);
			StarPoint[s].y=rr*cos(s*jiao);
			StarPoint[s].z=0;	
			StarPoint[s].c=CRGB(0,1,0);
		}
	}
	StarPoint[10].z=rr;
	StarPoint[10].x=0;
	StarPoint[10].y=0;
	StarPoint[10].c=CRGB(1,0,0);
	StarPoint[11].z=-rr;
	StarPoint[11].x=0;
	StarPoint[11].y=0;
	StarPoint[11].c=CRGB(1,0,0);
}

void CTest1View::ReadStarFace()//五角星面表
{
	int j;
	for(j=0;j<10;j++)
	{
		StarFace[j].SetNum(3);
		StarFace[j].vI[0]=10;
		StarFace[j].vI[1]=j;
		StarFace[j].vI[2]=(j+1)%10;
	}
	for(j=0;j<10;j++)
	{
		StarFace[j+10].SetNum(3);
		StarFace[j+10].vI[0]=11;
		StarFace[j+10].vI[1]=(j+1)%10;
		StarFace[j+10].vI[2]=j;
	}
}

void CTest1View::DrawStarObject(CDC *pDC)//五角星线框模型
{
	CPi3 Point[4];//透视投影后面的二维顶点数组
	CZBuffer *zbuf=new CZBuffer;//申请内存
	zbuf->InitDeepBuffer(800,800,1000);//初始化深度缓存器
	for(int nFace=0;nFace<20;nFace++)//面循环
	{
		for(int nVertex=0;nVertex<StarFace[nFace].vN;nVertex++)//顶点循环
		{
			PerProjectStar(StarPoint[StarFace[nFace].vI[nVertex]]);//透视投影
			Point[nVertex]=StarScreenP;
			Point[nVertex].c=StarPoint[StarFace[nFace].vI[nVertex]].c;
		}
		zbuf->SetPoint(Point,3);//设置顶点
		zbuf->CreateBucket();//建立桶表
		zbuf->CreateEdge();//建立边表
		zbuf->Gouraud(pDC);//填充四边形
		zbuf->ClearMemory();//内存清理
	}
	delete zbuf;//释放内存
}

void CTest1View::DrawStarPlane(CP3 p1, CP3 p2, CP3 p3)//填充平面
{
	CCLine *line = new CCLine;
	CDC *pDC = GetDC();
	CP3 ppoint1,ppoint2;
	double deltaY,deltaX,k;

	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);

	if (p2.y < p3.y)
	{
		ppoint1 = p2;
		p2 = p3;
		p3 = ppoint1;
	}
	else if (p2.y == p3.y)
	{
		ppoint2 = p2;
		for(;ppoint2.x<p3.x;ppoint2.x++)
		{
			line->MoveTo(pDC,p1);
			line->LineTo(pDC,ppoint2);
		}
	}
	ppoint2 = p3;
	deltaY = p2.y - p3.y;
	deltaX = p2.x - p3.x;
	k = deltaY/deltaX;
	if (k>0)
	{
		for (;ppoint2.y<=p2.y;)
		{
			line->MoveTo(pDC,p1);
			line->LineTo(pDC,ppoint2);
			ppoint2.x = ppoint2.x + 1;
			ppoint2.y = ppoint2.y + k;
		}
	}
	else if(k<0)
	{
		for (;ppoint2.y<=p2.y;)
		{
			line->MoveTo(pDC,p1);
			line->LineTo(pDC,ppoint2);
			ppoint2.x = ppoint2.x - 1;
			ppoint2.y = ppoint2.y - k;
		}
	}

	ReleaseDC(pDC);
	delete line;
}

void CTest1View::DoubleBufferStar(CDC *pDC)//五角星的双缓冲
{
	Invalidate(TRUE);
	UpdateWindow();

	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);

	Alpha=5;
	Beta=5;
	tran.RotateX(Alpha);
	tran.RotateY(Beta);

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap NewBitmap,*pOldBitmap;
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
	pOldBitmap=memDC.SelectObject(&NewBitmap);
	memDC.FillSolidRect(rect,pDC->GetBkColor());
	memDC.SetMapMode(MM_ANISOTROPIC);
	memDC.SetWindowExt(rect.Width(),rect.Height());
	memDC.SetViewportExt(rect.Width(),-rect.Height());
	memDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	DrawStarObject(&memDC);
	pDC->BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);
	memDC.SelectObject(pOldBitmap);
	NewBitmap.DeleteObject();
}

void CTest1View::InitParameterStar()
{
	Stark[1]=sin(PI*StarTheta/180);
	Stark[2]=sin(PI*StarPhi/180);
	Stark[3]=cos(PI*StarTheta/180);
	Stark[4]=cos(PI*StarPhi/180);
	Stark[5]=Stark[2]*Stark[3];
	Stark[6]=Stark[2]*Stark[1];
	Stark[7]=Stark[4]*Stark[3];
	Stark[8]=Stark[4]*Stark[1];
	StarViewPoint.x=StarR*Stark[6];//用户坐标系的视点球坐标
	StarViewPoint.y=StarR*Stark[4];
	StarViewPoint.z=StarR*Stark[5];
}

void CTest1View::PerProjectStar(CP3 P)
{
	CP3 ViewP;
	ViewP.x= Stark[3]*P.x-Stark[1]*P.z;//观察坐标系三维坐标
	ViewP.y=-Stark[8]*P.x+Stark[2]*P.y-Stark[7]*P.z;
	ViewP.z=-Stark[6]*P.x-Stark[4]*P.y-Stark[5]*P.z+StarR;
	StarScreenP.x=Stard*ViewP.x/ViewP.z;//屏幕坐标系三维坐标
	StarScreenP.y=Round(Stard*ViewP.y/ViewP.z);
	StarScreenP.z=Far*(1-Near/ViewP.z)/(Far-Near);
}

void CTest1View::OnOnePointStar() 
{
	// TODO: Add your command handler code here
	if (AntFlag)//反走样直线在旋转
	{
		KillTimer(1);
		AntFlag = FALSE;
	}
	if (RotateFlag)//正方体在旋转
	{
		KillTimer(2);
		RotateFlag = FALSE;
	}
	if (FlagRotateStar == true)//五角星在旋转
	{
		KillTimer(3);
		FlagRotateStar = false;
	}

	StarFlag = true;
	Invalidate(TRUE);
	UpdateWindow();
	StarR=1000.0,Stard=800.0,StarPhi=90.0,StarTheta=0.0;//视点位于正前方
	Near=800.0,Far=1200.0;//近剪切面与远剪切面
	Alpha=0.0;Beta=0.0;	
	CDC *pDC = GetDC();
	StarPhi = 90;
	StarTheta = 0;
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width(),-rect.Height()); 
	ReadStarPoint();
	ReadStarFace();
	InitParameterStar();
	DrawStarObject(pDC);
	
	ReleaseDC(pDC);
}

void CTest1View::OnDoublePointStar() 
{
	// TODO: Add your command handler code here
	if (AntFlag)//反走样直线在旋转
	{
		KillTimer(1);
		AntFlag = FALSE;
	}
	if (RotateFlag)//正方体在旋转
	{
		KillTimer(2);
		RotateFlag = FALSE;
	}
	if (FlagRotateStar == true)//五角星在旋转
	{
		KillTimer(3);
		FlagRotateStar = false;
	}

	StarFlag = true;
	Invalidate(TRUE);
	UpdateWindow();
	StarR=1000.0,Stard=800.0,StarPhi=90.0,StarTheta=0.0;//视点位于正前方
	Near=800.0,Far=1200.0;//近剪切面与远剪切面
	Alpha=0.0;Beta=0.0;	
	CDC *pDC = GetDC();
	StarPhi = 90;
	StarTheta = 30;
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width(),-rect.Height()); 
	ReadStarPoint();
	ReadStarFace();
	InitParameterStar();
	DrawStarObject(pDC);
	
	ReleaseDC(pDC);
}

void CTest1View::OnThreePointStar() 
{
	// TODO: Add your command handler code here
	if (AntFlag)//反走样直线在旋转
	{
		KillTimer(1);
		AntFlag = FALSE;
	}
	if (RotateFlag)//正方体在旋转
	{
		KillTimer(2);
		RotateFlag = FALSE;
	}
	if (FlagRotateStar == true)//五角星在旋转
	{
		KillTimer(3);
		FlagRotateStar = false;
	}

	StarFlag = true;
	Invalidate(TRUE);
	UpdateWindow();
	StarR=1000.0,Stard=800.0,StarPhi=90.0,StarTheta=0.0;//视点位于正前方
	Near=800.0,Far=1200.0;//近剪切面与远剪切面
	Alpha=0.0;Beta=0.0;	
	CDC *pDC = GetDC();
	StarPhi = 45;
	StarTheta = 45;
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width(),-rect.Height()); 
	ReadStarPoint();
	ReadStarFace();
	InitParameterStar();
	DrawStarObject(pDC);
	
	ReleaseDC(pDC);
}

void CTest1View::OnRotateFIveStars() //旋转五角星
{
	// TODO: Add your command handler code here
	FlagRotateStar = true;//在旋转
	StarFlag = false;//不进行键盘控制
	SetTimer(3,1500,NULL);
}
