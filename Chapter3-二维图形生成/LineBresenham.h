/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	Bresenhamֱ���㷨
* ���ϼ������� 2017/3/29 12:49
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once
#include "../OpenGL/Util.h"
#include <cmath>

void LineBres(int x1,int y1,int x2,int y2,Color3f* color = nullptr)
{
	setpixel(x1, y1, color);
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	if (dx == 0 && dy == 0) // �����һ�͵���غϣ��򲻴���
		return;
	int flag = 0; // ���б���Ƿ�|k| < 1
	if(dx < dy) // ���潫б�ʱ仯��0<=|k|<=1����
	{
		flag = 1;
		swap_vlaue(&x1, &y1);
		swap_vlaue(&x2, &y2);
		swap_vlaue(&dx, &dy);
	}

	int tx = (x2 - x1) > 0 ? 1 : -1; // �ж�x��y��ǰ������
	int ty = (y2 - y1) > 0 ? 1 : -1;
	int curx = x1;
	int cury = y1;
	int dS = 2 * dy; // D(i) < 0ʱ��D(i+1)�ĵ���ֵ
	int dT = 2 * (dy -dx); // ---D(i) >= 0---
	int d = dS - dx; // ��һ�����dֵ
	while (curx != x2)
	{
		if (d < 0)
			d += dS;
		else
		{ cury += ty;d += dT; }
		if (flag) // ���б��|k| > 1����Ҫ������棬��x,y��ת
			setpixel(cury, curx, color);
		else
			setpixel(curx, cury, color);
		curx += tx;
	}
}