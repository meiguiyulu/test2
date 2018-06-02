// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__7F47FCAD_2A42_4BD7_AE01_C3E439666D46__INCLUDED_)
#define AFX_RGB_H__7F47FCAD_2A42_4BD7_AE01_C3E439666D46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB  
{
public:
	CRGB();
	CRGB(double,double,double);
	virtual ~CRGB();
	friend CRGB operator+(const CRGB &,const CRGB &);//���������
	friend CRGB operator-(const CRGB &,const CRGB &);
	friend CRGB operator*(const CRGB &,const CRGB &);
	friend CRGB operator*(const CRGB &,double);
	friend CRGB operator*(double,const CRGB &);
	friend CRGB operator/(const CRGB &,double);
	friend CRGB operator+=(CRGB &,CRGB &);
	friend CRGB operator-=(CRGB &,CRGB &);
	friend CRGB operator*=(CRGB &,CRGB &);
	friend CRGB operator/=(CRGB &,double);
	void   Normalize();	//��һ����[0,1]����
public:
	double red;//��ɫ����
	double green;//��ɫ����
	double blue;//��ɫ����
};

#endif // !defined(AFX_RGB_H__7F47FCAD_2A42_4BD7_AE01_C3E439666D46__INCLUDED_)
