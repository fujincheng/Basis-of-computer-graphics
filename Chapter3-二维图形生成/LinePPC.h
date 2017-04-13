/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	PPCֱ���㷨�����ȽϷ� Point by Point comparison method��
* ���ϼ������� 2017/3/29 12:21
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#if defined(_WIN32) || defined(WIN32)
#include <windows.h> 
#endif
#include"../OpenGL/Util.h"

void LinePPC(int x1,int y1,int x2,int y2,Color3f* color = nullptr)
{
	int x, y, xA, yA;
	if(y1>y2) // ƽ��ֱ�ߵ����꣬ʹyֵ��С�ĵ�λ������ԭ��
	{
		yA = y1 - y2;
		xA = x1 - x2;
	}
	else
	{
		yA = y2 - y1;
		xA = x2 - x1;
	}

	int F = x = y = 0;
	int n = abs(xA) + abs(yA);
	for (int i = 0; i < n; ++i)
	{
		if(xA > 0) // ��б��Ϊ��,��Ϊ�������ϵ��жϣ�y�϶��Ǵ�����
		{
			if(F >= 0)
			{
				x++;F -= yA;
			}
			else
			{
				y++;F += xA;
			}
		}
		else
		{
			if(F >= 0)
			{
				y++;F += xA;
			}
			else
			{
				x--;F += yA;
			}
		}
		if (y1 > y2) // ͨ���ж�ʹyֵ��С�ĵ�λ������ԭ��
			setpixel(x + x2, y + y2);
		else
			setpixel(x + x1, y + y1);
	}
}