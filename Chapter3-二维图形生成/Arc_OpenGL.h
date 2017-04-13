/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	�е㻭Բ�㷨
* ���ϼ������� 2017/3/29 21:15
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include<gl/glut.h>
#include<cmath>
#include "../OpenGL/Util.h"

void Arc_OpenGL(int xc,int yc,double r,double ts,double te)
{
	if (te < ts) // ����ֹ�Ǳ���ʼ�ǻ�Сʱ������ֹ�Ǽ���2n
		te += 2 * PI; 
	double dt = 0.4 / r; // ���ð뾶ȡȡ�Ƕ���ɢֵ��ʹ����뾶�ɷ���
	int n = (int)((te - ts) / dt + 0.5);
	double ta = ts;
	int x = xc + int(r * cos(ts));
	int y = yc + int(r * sin(ts));
	glBegin(GL_LINE_STRIP); // ���������Բ��ѡȡGL_LINE_LOOP����
	glVertex2f(x, y);
	for (int i = 1; i <= n; ++i)
	{
		ta += dt;
		double cost = cos(ta);
		double sint = sin(ta);
		x = int(xc + r * cost);
		y = int(yc + r * sint);
		glVertex2f(x, y);
	}
	glEnd();
}
