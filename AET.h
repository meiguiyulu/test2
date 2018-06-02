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
	double  x;//��ǰɨ��������Ч�߽����x����
	int     yMax;//�ߵ����yֵ
	double  k;//б�ʵĵ���(x������)
	CPi2    ps;//�ߵ����
	CPi2    pe;//�ߵ��յ�
	CAET   *pNext;
};

#endif // !defined(AFX_AET_H__C681517A_680E_4762_A966_7930CED4A743__INCLUDED_)
