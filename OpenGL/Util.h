/******************************************************************************************
* �����ͼ��ѧ(OpenGL��) -- ���õ��Զ����༰����
* ���ϼ������� 2017/3/29 11:09
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once
#include <gl/glut.h>



/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
// ��
/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/

class Color3f
{
public:
	float r, g, b;

	Color3f(float r,float g,float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
};


/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
// ����
/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/

// ��ͼ��ʼ��ͨ�� begin

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

// ��ͼ��ʼ��ͨ�� end

// ����ͼ�λ��� begin

void setpixel(float x, float y, Color3f* color3_f = nullptr)
{
	if (color3_f != nullptr)
		glColor3f(color3_f->r, color3_f->g, color3_f->b);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void glDrawLine(float x1,float y1,float x2,float y2,float a = 0,int size = 1)
{
	glLineWidth(size);
	glBegin(GL_LINES);
	glVertex3f(x1, y1, a);
	glVertex3f(x2, y2, a);
	glEnd();
}

// ����ͼ�λ��� end

inline void swap_vlaue(int* a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

