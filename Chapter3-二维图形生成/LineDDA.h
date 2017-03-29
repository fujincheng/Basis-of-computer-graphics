/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	DDAֱ���㷨����ֵ΢�ַ���
* ���ϼ������ 2017/3/15 11:18
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#if defined(_WIN32) || defined(WIN32)
#include <windows.h> 
#endif
#include"../OpenGL/Util.h"
#include <cmath>

void LineDDA(int x1, int y1, int x2, int y2, Color3f* color = nullptr)
{
	int dm = 0;
	if (abs(x2 - x1) >= abs(y2 - y1))  //abs()�������ֵ��������cmath.h��
		dm = abs(x2 - x1);
	else
		dm = abs(y2 - y1);
	float dx = static_cast<float>(x2 - x1) / dm;
	float dy = static_cast<float>(y2 - y1) / dm;
	float x = x1 + 0.5;
	float y = y1 + 0.5;
	for (int i = 0; i < dm; ++i)
	{
		setpixel((int)x, (int)y,color);
		//glVertex2f(x, y);
		x += dx;
		y += dy;
	}
}


