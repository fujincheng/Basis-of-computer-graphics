/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	ͼ�α任�ľ�����
* ���ϼ������� 2017/4/26 12:00
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#include"gl/glut.h"
#include<cstdlib>
#include<cmath>
#include<iostream>

using namespace std;

int SCREEN_WIDTH = 400; // ��Ļ�ߴ�
int SCREEN_HEIGHT = 400;
int posx1 = 150;
int posy1 = 200;
int posx2 = 250;
int posy2 = 200;
int select_point = 0; // 1�ǵ�һ����

void init()
{
	glClearColor(1, 1, 1, 1);
}

void draw(GLenum mode)
{
	glPointSize(10.0);
	const static GLfloat color_selected[] = { 1,0,0 };
	const static GLfloat color_unselected[] = { 0,0,1 };
	for (int i = 1;i <= 5;i++)
	{
		if (mode == GL_SELECT) glLoadName(i);
		glColor3fv((select_point == i) ? color_selected : color_unselected);
		glBegin(GL_POINTS);
		glVertex2f(i * 70, 200);
		glEnd();
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw(GL_RENDER); //������Ⱦģʽ
	glFlush();
}

void reshape(int width,int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH,0, SCREEN_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
}

void processHits(GLint hits,GLuint buffer[])
{
	unsigned int i;
	GLuint name;
	for (i = 0;i < hits;i++)
	{
		name = buffer[3 + i * 4];
		select_point = name; // ÿ��ѡ������ռ������ջ�е�4����λ����4�������������ֵ
		cout << "��" << name << "����" << endl;
	}
}


#define  SIZE 500
#define N 10
void mouse(int button,int state,int x,int y)
{
	GLuint selectBuffer[SIZE]; // ����������ֵ�ջ
	GLint hits; // �������ѡ�и���
	GLint viewport[4]; // ��ſ���������
	if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) // ������������
	{
		glGetIntegerv(GL_VIEWPORT, viewport); // ��ȡ��ǰ�ӿ��������
		glSelectBuffer(SIZE, selectBuffer); // ѡ������ջ���ѡ����������
		glRenderMode(GL_SELECT); // ���õ�ǰΪѡ��ģʽ
		glInitNames(); // ��ʼ������ջ
		glPushName(0);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluPickMatrix(x, viewport[3] - y, N, N, viewport); // ��������ѡ���ͶӰ����ջ
		gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); // ����ͶӰ��ʽ
		draw(GL_SELECT); // ���Ƴ�����ѡ��ģʽ
		glPopMatrix();
		glFlush();
		hits = glRenderMode(GL_RENDER);
		glMatrixMode(GL_MODELVIEW);
		if (hits > 0) processHits(hits, selectBuffer);
		glutPostRedisplay();
	}
	if(state == GLUT_UP && button == GLUT_LEFT_BUTTON) // ��������̧��
	{
		select_point = 0;
		glRenderMode(GL_RENDER);
		draw(GL_RENDER);
		glutPostRedisplay();
	}
}

int main(int argc,char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("ͼ��ʰȡ���ʵ��");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 1;
}