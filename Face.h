// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__5D56BC20_879C_43A6_AAC4_517B2E6A5CBE__INCLUDED_)
#define AFX_FACE_H__5D56BC20_879C_43A6_AAC4_517B2E6A5CBE__INCLUDED_

#include "Vector.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFace  //正方体面类
{
public:
	CFace();
	virtual ~CFace();
	void SetNum(int);
	void SetFaceNormal(CP3,CP3,CP3);//设置小面法矢量
public:
	int vN;
	int *vI;
	CVector fNormal;
};

#endif // !defined(AFX_FACE_H__5D56BC20_879C_43A6_AAC4_517B2E6A5CBE__INCLUDED_)
