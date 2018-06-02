// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__4E734614_050F_4B11_AB73_405B18FA14EE__INCLUDED_)
#define AFX_VECTOR_H__4E734614_050F_4B11_AB73_405B18FA14EE__INCLUDED_
#include "P3.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P3.h"
#include "Pi3.h"

class CVector  
{
public:
	CVector();	
	virtual ~CVector();
	CVector(double x,double y,double z);
	CVector(const CP3 &);
	CVector(const CPi3 &);
	CVector(const CP3 &,const CP3 &);
	CVector(const CPi3 &,const CPi3 &);	
	double Mag();//矢量的模
	CVector Normalize();//单位矢量
	friend CVector operator +(const CVector &,const CVector &);//运算符重载
	friend CVector operator -(const CVector &,const CVector &);
	friend CVector operator *(const CVector &,double);
	friend CVector operator *(double,const CVector &);
	friend CVector operator /(const CVector &,double);
	friend CVector operator+=(CVector &,CVector &);
	friend CVector operator-=(CVector &,CVector &);
	friend CVector operator*=(CVector &,CVector &);
	friend CVector operator/=(CVector &,double);
	friend double  Dot(const CVector &,const CVector &);  //矢量点积
	friend CVector Cross(const CVector &,const CVector &);//矢量叉积
public:
	double x,y,z;//公有数据成员，方便外部访问
};

#endif // !defined(AFX_VECTOR_H__4E734614_050F_4B11_AB73_405B18FA14EE__INCLUDED_)
