/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	Bresenham�е�ֱ���㷨
* ���ϼ������� 2017/3/29 18:57
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include "../OpenGL/Util.h"
#include<cmath>

void LineMidP(int x0,int y0,int x1,int y1,Color3f* color = nullptr)
{
	int a, b, d, x, y, flag = 0;
	if (abs(x1 - x0) < abs(y1 - y0)) // ��б�ʵľ���ֵ����1����x�����y���껥��
	{
		swap_vlaue(&x0, &y0);
		swap_vlaue(&x1, &y1);
		flag = 1;
	}
	if (x0 > x1) // ��֤x0 < x1
	{ // ȷ��x��С������Ϊ��ʼ��
		swap_vlaue(&x0, &x1);
		swap_vlaue(&y0, &y1);
	}
	a = y0 - y1;
	b = x1 - x0;
	d = a + b / 2;
	if(y0 < y1) // б��Ϊ��
	{
		x = x0;y = y0;
		setpixel(x, y, &Color3f(225, 0, 0));
		while (x < x1)
		{
			if(d < 0)
			{
				x++;y++;d = d + a + b;
			}
			else
			{
				x++;d += a;
			}
			if (flag) // ��б�ʵľ���ֵ����1����x�����y���껥������
				setpixel(y, x, color);
			else
				setpixel(x, y, color);
		} /* while */
	}
	else
	{
		x = x1;y = y1;
		setpixel(x, y, &Color3f(255, 0, 0));
		while (x > x0)
		{
			if(d < 0)
			{
				x--;y++;d = d - a + b;
			}
			else
			{
				x--;d -= a;
			}
			if (flag) // ��б�ʵľ���ֵ����1����x�����y���껥������
				setpixel(y, x, color);
			else
				setpixel(x, y, color);
		} /* while */
	}

}