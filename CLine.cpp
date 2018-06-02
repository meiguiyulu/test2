// CLIne.cpp: implementation of the CCLIne class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test1.h"
#include "CLine.h"

#include "math.h"
#define Round(d) int(floor(d+0.5))//四舍五入宏定义

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CCLine::CCLine()
{ 
	
}

CCLine::~CCLine()
{
	
}

void CCLine::MoveTo(CDC *pDC,CP2 p0)
{	
	P0=p0;
}

void CCLine::MoveTo(CDC *pDC,double x,double y,CRGB c0)//重载函数
{	
	MoveTo(pDC,CP2(x,y,c0));
}

void CCLine::LineTo(CDC *pDC,CP2 p1)
{
	P1=p1;
	CP2 p,t;
	double d,d1,d2,k;

	if (P1.x < P0.x)
	{
		t = P0;
		P0 = P1;
		P1 = t;
	}
	p = P0;

	double dx = P1.x - P0.x;
	double dy = P1.y - P0.y;
	if (dx==0)
	{
		do 
		{
			p.c=Interpolation(p.y,P0.y,P1.y,P0.c,P1.c);
			pDC->SetPixelV(Round(p.x),Round(p.y),RGB(p.c.red*255,p.c.green*255,p.c.blue*255));
			p.y++;
		} while (p.y<P1.y);
	}
	else 
		k = dy/dx;

		if(k>1)//绘制k>1
		{
			d=2*dx-dy;
			d1=2*dx-2*dy;
			d2=2*dx;
			do
			{
				p.c=Interpolation(p.y,P0.y,P1.y,P0.c,P1.c);
				pDC->SetPixelV(Round(p.x),Round(p.y),RGB(p.c.red*255,p.c.green*255,p.c.blue*255));
				if(d>0)
				{
					d=d+d1;
					p.x++;
				}
				else
				{
					d=d+d2;
				}
				p.y++;
			}while(p.y<P1.y);
		}
		if(0<=k && k<=1)//绘制0≤k≤1
		{

			d=dx-2*dy;
			d1=-2*dy;
			d2=-2*(dy-dx);
			do
			{
				p.c=Interpolation(p.x,P0.x,P1.x,P0.c,P1.c);
				pDC->SetPixelV(Round(p.x),Round(p.y),RGB(p.c.red*255,p.c.green*255,p.c.blue*255));
				if(d>0)
					d=d+d1;
				else
				{
					d=d+d2;
					p.y++;
				}
				p.x++;
			}while(p.x<P1.x);
		}		
		if(k>=-1 && k<0)//绘制-1≤k＜0
		{
			 d=-2*dy-dx;
			 d1=-2*dy-2*dx;
			 d2=-2*dy;
			 do
			 {
			 	 p.c=Interpolation(p.x,P0.x,P1.x,P0.c,P1.c);
			     pDC->SetPixelV(Round(p.x),Round(p.y),RGB(p.c.red*255,p.c.green*255,p.c.blue*255));
				 if(d>0)
				 {
					 d=d+d1;
					 p.y--;
				 }
				 else
				 {
					 d=d+d2;
				 }
				 p.x++;
			 }while(p.x<P1.x);
		}
		if(k<-1)//绘制k＜-1 
		{
			 d=-2*dx-dy;
			 d1=-2*dx;
			 d2=2*(-dx-dy);
			 do
			 {
				p.c=Interpolation(p.y,P0.y,P1.y,P0.c,P1.c);
				pDC->SetPixelV(Round(p.x),Round(p.y),RGB(p.c.red*255,p.c.green*255,p.c.blue*255));
				if(d>0)
					d=d+d1;
				else
				{
					d=d+d2;
					p.x++;
				}
				p.y--;
			 }while(p.y>P1.y);
		}
}

void CCLine::LineTo(CDC *pDC,double x,double y,CRGB c1)//重载函数
{
	 LineTo(pDC,CP2(x,y,c1));
}

CRGB CCLine::Interpolation(double t,double t0,double t1,CRGB clr0,CRGB clr1)//颜色线性插值
{
	CRGB color;
	color=(t-t1)/(t0-t1)*clr0+(t-t0)/(t1-t0)*clr1;
	return color;
}
