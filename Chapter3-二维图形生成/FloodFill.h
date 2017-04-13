/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	��ˮ�����(Flood-Fill-Algorithm)
* ���ϼ������� 2017/4/5 10:41
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include "../OpenGL/Util.h"

void FloodFill_R(int x, int y, Color3f * newColor, Color3f * boundaryColor)
{
	// �������ڶ�������ʱ����if(getpixel(x,y) != newcolor)�жϼ���
	if (getpixel(x, y)->operator!=(newColor) && getpixel(x, y)->operator!=(boundaryColor))
	{
		setpixel(x, y, newColor);
	}
}
