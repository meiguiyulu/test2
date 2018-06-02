// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__8BB8622B_F2C7_4CCE_8FD3_61DF782CC6E4__INCLUDED_)
#define AFX_P2_H__8BB8622B_F2C7_4CCE_8FD3_61DF782CC6E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RGB.h"

class CP2  
{
public:
	CP2();
	virtual ~CP2();
	CP2(double,double);
	CP2(double,double,CRGB);
public:
	double x;
	double y;
	double w;
	CRGB   c;
};


#endif // !defined(AFX_P2_H__8BB8622B_F2C7_4CCE_8FD3_61DF782CC6E4__INCLUDED_)
