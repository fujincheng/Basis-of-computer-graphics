/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	��ˮ�����(Flood-Fill-Algorithm)
* ���ϼ������� 2017/4/5 10:41
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include "../OpenGL/Util.h"
#include <stack>

using namespace std;

class Pixel
{
public:
	int x, y;
	Color3ub * color;
	Pixel(int x = 0, int y = 0, Color3ub * color = nullptr) :x(x), y(y)
	{ 
		this->color = getpixelcolor3ub(x, y);
	}
};

void FloodFill_R(int x, int y, Color3ub * newColor, Color3ub * boundaryColor)
{
	// �������ڶ�������ʱ����if(getpixel(x,y) != newcolor)�жϼ���
	if (getpixelcolor3ub(x, y)->operator!=(newColor) && getpixelcolor3ub(x, y)->operator!=(boundaryColor))
	{
		setpixel_3ub(x, y, newColor);
		FloodFill_R(x - 1, y, newColor, boundaryColor);
		FloodFill_R(x, y + 1, newColor, boundaryColor);
		FloodFill_R(x + 1, y, newColor, boundaryColor);
		FloodFill_R(x, y - 1, newColor, boundaryColor);
	}
}

void FloodFill_I(int x, int y, Color3ub * newColor, Color3ub * boundaryColor)
{
	stack<Pixel> Stack;
	Pixel pixel;
	Stack.push(Pixel(x, y));
	while (!Stack.empty())
	{
		pixel = Stack.top(); Stack.pop();
		if (pixel.color->operator!=(newColor) && pixel.color->operator!=(boundaryColor))
		{
			int xx = pixel.x; int yy = pixel.y;
			setpixel_3ub(xx, yy, newColor);
			Stack.push(Pixel(xx - 1, yy));
			Stack.push(Pixel(xx, yy + 1));
			Stack.push(Pixel(xx + 1, yy));
			Stack.push(Pixel(xx, yy - 1));
		}
	}
}
//
//void zzFill(int startX, int startY, int r, int g, int b) {
//	stack<Point> pixelStack;
//	//x,y�Ǹ������������ص㣬rgb����Ҫ������ɫ��RGBֵ
//	Point point = { startX,startY };
//	pixelStack.push(point);
//	int saveX;
//	int xRight, xLeft;
//	int x, y;
//	//���ջ��Ϊ��
//	while (!pixelStack.empty()) {
//		//��ȡ��˵�Ԫ��
//		Point tempPoint = pixelStack.top();
//		//ɾ����˵�Ԫ��
//		pixelStack.pop();
//		saveX = tempPoint.x;
//		x = tempPoint.x;
//		y = tempPoint.y;
//		glReadPixels(x + halfWidth, y + halfHeight, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//		//���û�е����ұ߽磬�����
//		while (!sameColor(iPixel[0], iPixel[1], iPixel[2], borderColor[0], borderColor[1], borderColor[2])) {
//			glPoint(x, y, r, g, b);
//			x = x + 1;
//			glReadPixels(x + halfWidth, y + halfHeight, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//		}
//		xRight = x - 1;
//		x = saveX - 1;
//		glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//		//���û�е�����߽磬�����
//		while (!sameColor(iPixel[0], iPixel[1], iPixel[2], borderColor[0], borderColor[1], borderColor[2])) {
//			glPoint(x, y, r, g, b);
//			x = x - 1;
//			glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//		}
//		//������˵�
//		xLeft = x + 1;
//		//���ұߵĵ㿪ʼ
//		x = xRight;
//		//����϶˵�ɨ����
//		y = y + 1;
//		while (x >= xLeft) {
//			glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//			if (!sameColor(iPixel[0], iPixel[1], iPixel[2], borderColor[0], borderColor[1], borderColor[2]) && !sameColor(iPixel[0], iPixel[1], iPixel[2], r, g, b)) {
//				//����Ϸ��ĵ㲻�Ǳ߽�㣬ֱ��ѹ��
//				Point p = { x,y };
//				pixelStack.push(p);
//				//ѹ��֮��ֹͣѭ��
//				break;
//			}
//			else {
//				x--;
//				glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//			}
//		}
//		//����¶˵�ɨ����
//		y = y - 2;
//		//���ұߵĵ㿪ʼ
//		x = xRight;
//		while (x >= xLeft) {
//			glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//			if (!sameColor(iPixel[0], iPixel[1], iPixel[2], borderColor[0], borderColor[1], borderColor[2]) && !sameColor(iPixel[0], iPixel[1], iPixel[2], r, g, b)) {
//				//����Ϸ��ĵ㲻�Ǳ߽�㣬ֱ��ѹ��
//				Point p = { x,y };
//				//ѹ��֮��ֹͣѭ��
//				pixelStack.push(p);
//				break;
//			}
//			else {
//				x--;
//				glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//			}
//		}
//	}
//}