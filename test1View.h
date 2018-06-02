// test1View.h : interface of the CTest1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST1VIEW_H__57FEBFB8_0879_4999_8C27_9A1762A9AE15__INCLUDED_)
#define AFX_TEST1VIEW_H__57FEBFB8_0879_4999_8C27_9A1762A9AE15__INCLUDED_

#include "P2.h"	// Added by ClassView
#include "P3.h"
#include "Face.h"
#include "StackNode.h"
#include "Transform.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest1View : public CView
{
protected: // create from serialization only
	CTest1View();
	DECLARE_DYNCREATE(CTest1View)

// Attributes
public:
	CTest1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void PerProjectStar(CP3 P);
	void InitParameterStar();
	void DoubleBufferStar(CDC *pDC);
	void DrawStarPlane(CP3 p1,CP3 p2,CP3 p3);
	void DrawStarObject(CDC *pDC);
	void ReadStarFace();
	void ReadStarPoint();//五角星顶点表
	
	bool StarFlag;//是否在进行五角星的透视投影
	bool FlagRotateStar;//判断五角星是否在旋转
	CTransform tran;//变换对象
	double Alpha,Beta;//x方向旋转α角,y方向旋转β角
	double StarR,StarTheta,StarPhi;//视点在用户坐标系中的球坐标
	double Stard;//视距
	double Near,Far;//远近剪切面
	double Stark[9];//运算常量
	CP3 StarViewPoint;//视点球坐标
	CPi3 StarScreenP;//屏幕坐标系的三维坐标点
	CFace StarFace[20];//五角星面
	CP3 StarPoint[12];//五角星顶点




	void DoubleBufferThree();
	void PerProject(CP3 pp);
	int Theta,Phi;
	void InitParameter();
	void DrawObject(CDC *pDC);
	void ReadFace();
	void ReadPoint();
	CP3 p3[8];//旋转正方体顶点坐标
	CP3 ViewPoint;//视点球坐标
	double k[9],R,d;//运算常量,d为视距,R为视径
	CP2 ScreenP;//屏幕坐标系的二维坐标点
	CFace F3[6];//旋转正方体的六个面
	BOOL RotateFlag;//判断是否调用定时器来进行旋转
	bool PolyFlag;//判断是否进行正方体旋转的相关操作

	void DoubleBuffer();
	BOOL AntFlag;
	CP2 sp1,sp2;//反走样第一条直线的起点跟终点
	float A[3][3];

	void matrix_mul(float A[][3], float B[][3], float C[][3], int m, int p, int n);
	CRect rect;
	void FillPolygon(CDC *pDC);
	void Pop(CP2 &point);
	void Push(CP2 point);
	COLORREF GetClr;
	CStackNode *pHead;
	CStackNode *pTop;
	CP2 Seed;//种子
	int count;//鼠标左键点击的次数
	CP2 PolyPoint[7];//多边形的顶点
	bool flag,bFill; //判断鼠标的点击事件是否可用, 是否填充

	void MidPointLine(CP2 p1,CP2 p2);
	void Diamond();
	virtual ~CTest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	double r;
	int n;
	CP2 *p;
	//{{AFX_MSG(CTest1View)
	afx_msg void Onzdsf();
	afx_msg void OnDrawPic();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawColor();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnAnt();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnRotate();
	afx_msg void OnOnePoint();
	afx_msg void OnDoublePoint();
	afx_msg void OnThreePoint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnOnePointStar();
	afx_msg void OnDoublePointStar();
	afx_msg void OnThreePointStar();
	afx_msg void OnRotateFIveStars();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test1View.cpp
inline CTest1Doc* CTest1View::GetDocument()
   { return (CTest1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1VIEW_H__57FEBFB8_0879_4999_8C27_9A1762A9AE15__INCLUDED_)
