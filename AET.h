// AET.h: interface for the CAET class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AET_H__C681517A_680E_4762_A966_7930CED4A743__INCLUDED_)
#define AFX_AET_H__C681517A_680E_4762_A966_7930CED4A743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Pi2.h"

class CAET  
{
public:
	CAET();
	virtual ~CAET();
public:
	double  x;//当前扫描线与有效边交点的x坐标
	int     yMax;//边的最大y值
	double  k;//斜率的倒数(x的增量)
	CPi2    ps;//边的起点
	CPi2    pe;//边的终点
	CAET   *pNext;
};

#endif // !defined(AFX_AET_H__C681517A_680E_4762_A966_7930CED4A743__INCLUDED_)
