// CLIne.h: interface for the CCLIne class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLINE_H__FE7C9427_DCB7_441C_BC03_5B2E996C9016__INCLUDED_)
#define AFX_CLINE_H__FE7C9427_DCB7_441C_BC03_5B2E996C9016__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"

class CCLine  
{
public:
	CCLine();
	virtual ~CCLine();
	void MoveTo(CDC *,CP2);
	void MoveTo(CDC *,double,double,CRGB);
	void LineTo(CDC *,CP2);
	void LineTo(CDC *,double,double,CRGB);
	CRGB Interpolation(double,double,double,CRGB,CRGB);
public:
	CP2 P0;
	CP2 P1;
};

#endif // !defined(AFX_CLINE_H__FE7C9427_DCB7_441C_BC03_5B2E996C9016__INCLUDED_)
