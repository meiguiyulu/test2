// ALine.h: interface for the CALine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALINE_H__DADB5F92_F1E8_421C_A594_9B728532EE6D__INCLUDED_)
#define AFX_ALINE_H__DADB5F92_F1E8_421C_A594_9B728532EE6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"

class CALine  
{
public:
	CALine();
	virtual ~CALine();
	void MoveTo(CDC *,CP2);
	void MoveTo(CDC *,double,double);
	void MoveTo(CDC *,double,double,CRGB);
	void LineTo(CDC *,CP2);
	void LineTo(CDC *,double,double);
	void LineTo(CDC *,double,double,CRGB);

public:
	CP2 P0;
	CP2 P1;
};

#endif // !defined(AFX_ALINE_H__DADB5F92_F1E8_421C_A594_9B728532EE6D__INCLUDED_)
