// StackNode.h: interface for the CStackNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACKNODE_H__983F3128_2A1B_48EE_9D05_33810F141813__INCLUDED_)
#define AFX_STACKNODE_H__983F3128_2A1B_48EE_9D05_33810F141813__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"

class CStackNode  
{
public:
	CStackNode();
	virtual ~CStackNode();

public:
	CP2 PiexlPoint;
	CStackNode *pNext;
};

#endif // !defined(AFX_STACKNODE_H__983F3128_2A1B_48EE_9D05_33810F141813__INCLUDED_)
