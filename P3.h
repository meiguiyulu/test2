// P3.h: interface for the CP3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P3_H__8CE969F2_CB3F_4EE6_B3EB_DAF54C9B17FA__INCLUDED_)
#define AFX_P3_H__8CE969F2_CB3F_4EE6_B3EB_DAF54C9B17FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"

class CP3:public CP2  
{
public:
	CP3();
	virtual ~CP3();
	CP3(double,double,double,double);

public:
	double z;

};

#endif // !defined(AFX_P3_H__8CE969F2_CB3F_4EE6_B3EB_DAF54C9B17FA__INCLUDED_)
