// Bucket.h: interface for the CBucket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUCKET_H__861F4D28_54E1_4AE0_9B9F_4A23B14F102A__INCLUDED_)
#define AFX_BUCKET_H__861F4D28_54E1_4AE0_9B9F_4A23B14F102A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AET.h"

class CBucket  
{
public:
	CBucket();
	virtual ~CBucket();
public:
	int     ScanLine;
	CAET    *pET;
	CBucket *pNext;
};

#endif // !defined(AFX_BUCKET_H__861F4D28_54E1_4AE0_9B9F_4A23B14F102A__INCLUDED_)
