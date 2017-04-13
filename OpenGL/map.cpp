/******************************************************************************************
* �����ͼ��ѧ������OpenGL�棩	--	����OpenGL�ĵ�ͼ����
* ���ϼ������� 2017/4/13 21:20
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <GL/glut.h>

using namespace std;

class MapPoint
{
public:
	double longitude;
	double latitude;
};

class Polygon
{
public:
	vector<MapPoint> points; // ����εĶ�������
};

vector<Polygon*> polys; // ����μ���
vector<Polygon*> ReadMapData(char* filename)
{
	int PointCount;
	vector<Polygon*> polygons;
	ifstream fs(filename);
	while(fs.eof() != true)
	{
		Polygon* poly = new Polygon;
		fs >> PointCount;
		cout << PointCount << endl;
		for(int i = 0;i < PointCount;i++)
		{
			MapPoint p;
			fs >> p.longitude >> p.latitude;
			poly->points.push_back(p);
		}
		polygons.push_back(poly);
	}
	return polygons;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// ����ɫ���Ƹ�ʡ�߽�
	glColor3f(0.0, 0.0, 1.0);
	// ��������Ϊ���ģʽ
	glPolygonMode(GL_BACK, GL_LINE);
	for (int i = 0;i < polys.size();i++)
	{
		vector<MapPoint> points = polys[i]->points;
		glBegin(GL_LINE_LOOP); // ʹ�ñպ����߷�ʽ���Ƹ�ʡ�߽�
		for (int j = 0;j < points.size();j++)
		{
			glVertex3f(points[j].longitude , points[j].latitude , 0.0);
		}
		glEnd();
	}
	glFlush();
}

void init(void)
{
	// ���ñ�����ɫ
	glClearColor(1.0, 1.0, 1.0, 0.0);
	// ��ʼ���۲�ֵ
	glMatrixMode(GL_PROJECTION); // ������ģʽ��ΪͶӰ
	glLoadIdentity(); // �Ծ�����е�λ��
	glOrtho(70, 140, 0, 60, -1, 1);
	// ����ƽ��ͶӰ����ע�����������
}

int main(int argc,char** argv)
{
	char* filename = "HenanCounty.txt";
	polys = ReadMapData(filename);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // �������RGB
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Map");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}