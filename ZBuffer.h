// ZBuffer.h: interface for the CZBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZBUFFER_H__29CA6341_318C_4D7D_B38A_558790B271F6__INCLUDED_)
#define AFX_ZBUFFER_H__29CA6341_318C_4D7D_B38A_558790B271F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Bucket.h"//Ͱͷ�ļ�
#include "Vector.h"//ʸ��ͷ�ļ�
#include "Pi3.h"

class CZBuffer  
{
public:
	CZBuffer();
    virtual ~CZBuffer();
	void CreateBucket();//����Ͱ
	void CreateEdge();//�߱�
	void AddEt(CAET *);//�ϲ�ET��
	void ETOrder();
	void Gouraud(CDC *);//���
	void InitDeepBuffer(int,int,double);//��ʼ����Ȼ�����
    CRGB Interpolation(double,double,double,CRGB,CRGB);//���Բ�ֵ
	void SetPoint(CPi3 *,int);
	void ClearMemory();//�����ڴ�
	void DeleteAETChain(CAET* pAET);//ɾ���߱�
protected:
	int PNum;//�������
	CPi3 *P;//��������
	CAET *pHeadE,*pCurrentE,*pEdge;//��Ч�߱���ָ��
	CBucket *pCurrentB,*pHeadB;
	double **zBuffer;//����ȳ���
	int Width,Height;//����������
};

#endif // !defined(AFX_ZBUFFER_H__29CA6341_318C_4D7D_B38A_558790B271F6__INCLUDED_)
