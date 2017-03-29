/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	Bresenham��Բ�㷨
* ���ϼ������� 2017/3/29 19:33
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include "../OpenGL/Util.h"

// ͨ��һ���������ӳ��İ˸���
void Cirpot(int x0,int y0,int x,int y,Color3f* color = nullptr)
{
	setpixel((x0 + x), (y0 + y), color);
	setpixel((x0 + y), (y0 + x), color);
	setpixel((x0 + y), (y0 - x), color);
	setpixel((x0 + x), (y0 - y), color);
	setpixel((x0 - x), (y0 - y), color);
	setpixel((x0 - y), (y0 - x), color);
	setpixel((x0 - y), (y0 + x), color);
	setpixel((x0 - x), (y0 + y), color);
}

void CircleBres(int x0,int y0,double r)
{
	int x, y, d;
	x = 0;
	y = static_cast<int>(r);
	d = static_cast<int>(3 - 2 * r);
	while (x < y)
	{
		Cirpot(x0, y0, x, y);
		if (d < 0)
			d += 4 * x + 6;
		else
		{
			d += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	if (x == y)
		Cirpot(x0, y0, x, y);
}