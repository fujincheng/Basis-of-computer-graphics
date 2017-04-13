/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	������Բ�㷨
* ���ϼ������� 2017/4/5 10:16
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include"../OpenGL/Util.h"
#include<cmath>

void MyCricle(int xc,int yc,double xr,double yr,double ts,double te)
{
	if (te < ts)
		te += 2 * PI;
	double dt = 0.4 / MAX(xr, yr);
	int n = (int)((te - ts) / dt + 0.5); // ȷ���ܲ���
	double ta = ts;
	int x = xc + int(xr * cos(ts));
	int y = yc + int(yr * sin(ts));
	glBegin(GL_LINE_STRIP);
	glVertex2f(x, y);
	for (int i = 1;i <= n;++i)
	{
		ta += dt;
		double cost = cos(ta);
		double sint = sin(ta);
		int x = xc + int(xr * cost);
		int y = yc + int(yr * sint);
		glVertex2f(x, y);
	}
	glEnd();
}