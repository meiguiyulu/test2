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
	void ReadStarPoint();//����Ƕ����
	
	bool StarFlag;//�Ƿ��ڽ�������ǵ�͸��ͶӰ
	bool FlagRotateStar;//�ж�������Ƿ�����ת
	CTransform tran;//�任����
	double Alpha,Beta;//x������ת����,y������ת�½�
	double StarR,StarTheta,StarPhi;//�ӵ����û�����ϵ�е�������
	double Stard;//�Ӿ�
	double Near,Far;//Զ��������
	double Stark[9];//���㳣��
	CP3 StarViewPoint;//�ӵ�������
	CPi3 StarScreenP;//��Ļ����ϵ����ά�����
	CFace StarFace[20];//�������
	CP3 StarPoint[12];//����Ƕ���




	void DoubleBufferThree();
	void PerProject(CP3 pp);
	int Theta,Phi;
	void InitParameter();
	void DrawObject(CDC *pDC);
	void ReadFace();
	void ReadPoint();
	CP3 p3[8];//��ת�����嶥������
	CP3 ViewPoint;//�ӵ�������
	double k[9],R,d;//���㳣��,dΪ�Ӿ�,RΪ�Ӿ�
	CP2 ScreenP;//��Ļ����ϵ�Ķ�ά�����
	CFace F3[6];//��ת�������������
	BOOL RotateFlag;//�ж��Ƿ���ö�ʱ����������ת
	bool PolyFlag;//�ж��Ƿ������������ת����ز���

	void DoubleBuffer();
	BOOL AntFlag;
	CP2 sp1,sp2;//��������һ��ֱ�ߵ������յ�
	float A[3][3];

	void matrix_mul(float A[][3], float B[][3], float C[][3], int m, int p, int n);
	CRect rect;
	void FillPolygon(CDC *pDC);
	void Pop(CP2 &point);
	void Push(CP2 point);
	COLORREF GetClr;
	CStackNode *pHead;
	CStackNode *pTop;
	CP2 Seed;//����
	int count;//����������Ĵ���
	CP2 PolyPoint[7];//����εĶ���
	bool flag,bFill; //�ж����ĵ���¼��Ƿ����, �Ƿ����

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
