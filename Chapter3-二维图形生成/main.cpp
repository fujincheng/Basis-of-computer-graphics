/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	��άͼ�β�������
* ���ϼ������� 2017/3/29 11:26
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#if defined(_WIN32) || defined(WIN32)
#include <windows.h> 
#endif
#include "Test.h"


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// draw line

	/*
	glColor3f(1.0, 0.0, 0.0);
	glDrawLine(350.0, 480.0, 10.0, 10.0);//����OpenGL��������ֱ��
	glColor3f(0.0, 1.0, 0.0);
	LineDDA(350.0, 480.0, 10.0, 10.0);//����DDA�㷨����ֱ��
	glColor3f(1, 0, 0);
	LineMidP(350.0, 480.0, 10.0, 10.0);
	glColor3f(0, 1, 0);
	LineBres(350.0, 480.0, 10.0, 10.0);
	glColor3f(0, 0, 1);
	LinePPC(350.0, 480.0, 10.0, 10.0);
	*/

	// draw circle

	//��ҵ��ʵ��һ
	glColor3f(1, 0, 0);
	CircleBres(320, 240, 200);

	////glColor3f(0, 1, 0);
	//CircleMidP(320, 240, 200);

	//��ҵ��ʵ���
	//glColor3f(1, 0, 0);
	//Arc_OpenGL(320, 240, 50, 0, 2 * PI);
	//Arc_OpenGL(320, 240, 100, 0, 2 * PI);
	//Arc_OpenGL(320, 240, 200, 0, 2 * PI);

	//glColor3f(1, 1, 0);
	//MyCricle(320, 240, 300, 200, 0, 2 * PI);

	glFlush();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("����");
	init();

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}