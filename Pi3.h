// Pi3.h: interface for the CPi3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PI3_H__8E206102_2989_4A27_8EF4_B63763E27155__INCLUDED_)
#define AFX_PI3_H__8E206102_2989_4A27_8EF4_B63763E27155__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Pi2.h"

class CPi3:public CPi2  
{
public:
	CPi3();
	virtual ~CPi3();
	CPi3(double,int,double);
	double z;
};

#endif // !defined(AFX_PI3_H__8E206102_2989_4A27_8EF4_B63763E27155__INCLUDED_)
