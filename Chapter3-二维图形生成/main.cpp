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
	/*
	glColor3f(1.0, 0.0, 0.0);
	glDrawLine(350.0, 480.0, 10.0, 10.0);//����OpenGL��������ֱ��
	glColor3f(0.0, 1.0, 0.0);
	LineDDA(350.0, 480.0, 10.0, 10.0);//����DDA�㷨����ֱ��
	*/
	glColor3f(1, 0, 0);
	LineBres(350.0, 480.0, 10.0, 10.0);
	glFlush();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("����ֱ��");
	init();

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}