#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<ctime>
#include<time.h>
#include<Windows.h>
#include<iostream> //for cin/cout
#include<vector> //for vectors
#include<cstdlib> //for rand()
using namespace std;

void *currentfont;

void setFontS(void *font)
{
	currentfont = font;
}

void colorS()
{
	glColor3f(1.0, 1.0, 1.0);
}

void drawstringS(float x, float y, float z, char *string)
{
	char *c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glColor3f(0.0, 0.0, 0.0);
		glutBitmapCharacter(currentfont, *c);
	}
}

void plot_pointS(float x, float y, float xc, float yc)
{
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}

void fillItS(float x, float y, float xc, float yc)
{

	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}


void circleS(int r, int xc, int yc)
{
	int k;
	int x = 0, y = r;
	float pk = (5.0 / 4.0) - r;
	plot_pointS(x, y, xc, yc);

	while (x < y)
	{
		x = x + 1;
		if (pk < 0)
			pk = pk + 2 * x + 1;
		else
		{
			y = y - 1;
			pk = pk + 2 * (x - y) + 1;
		}
		plot_pointS(x, y, xc, yc);
	}
	glFlush();
}

void circleFillS(int r, int xc, int yc)
{
	int k;
	int x = 0, y = r;
	float pk = (5.0 / 4.0) - r;

	fillItS(x, y, xc, yc);


	while (x < y)
	{
		x = x + 1;
		if (pk < 0)
			pk = pk + 2 * x + 1;
		else
		{
			y = y - 1;
			pk = pk + 2 * (x - y) + 1;
		}
		fillItS(x, y, xc, yc);
	}
	glFlush();
}

void setUnitsS(int k, int pos)
{
	int u = k % 10;
	if (u == 1)
		circleFillS(45, pos, 100);
	else if (u == 2)
		circleFillS(45, pos, 210);
	else if (u == 3)
	{
		circleFillS(45, pos, 100);
		circleFillS(45, pos, 210);
	}
	else if (u == 4)
		circleFillS(45, pos, 320);
	else if (u == 5)
	{
		circleFillS(45, pos, 320);
		circleFillS(45, pos, 100);
	}
	else if (u == 6)
	{
		circleFillS(45, pos, 320);
		circleFillS(45, pos, 210);
	}
	else if (u == 7)
	{
		circleFillS(45, pos, 100);
		circleFillS(45, pos, 210);
		circleFillS(45, pos, 320);
	}
	else if (u == 8)
		circleFillS(45, pos, 430);
	else if (u == 9)
	{
		circleFillS(45, pos, 430);
		circleFillS(45, pos, 100);
	}
}

void setTensS(int k, int pos)
{
	int l = k % 10, u = (k - l) / 10;
	if (u == 1)
		circleFillS(45, pos, 100);
	else if (u == 2)
		circleFillS(45, pos, 210);
	else if (u == 3)
	{
		circleFillS(45, pos, 100);
		circleFillS(45, pos, 210);
	}
	else if (u == 4)
		circleFillS(45, pos, 320);
	else if (u == 5)
	{
		circleFillS(45, pos, 320);
		circleFillS(45, pos, 100);
	}
	else if (u == 6)
	{
		circleFillS(45, pos, 320);
		circleFillS(45, pos, 210);
	}
	else if (u == 7)
	{
		circleFillS(45, pos, 100);
		circleFillS(45, pos, 210);
		circleFillS(45, pos, 320);
	}
	else if (u == 8)
		circleFillS(45, pos, 430);
	else if (u == 9)
	{
		circleFillS(45, pos, 430);
		circleFillS(45, pos, 100);
	}
}

int x = 0;
void drawS(void)
{
	int i = 10;
	colorS();
	circleS(45, 100, 100);//H
	if(!x)Sleep(300);
	colorS();
	circleS(45, 100, 210);//H
	if(!x)Sleep(300);
	colorS();
	circleS(45, 210, 100);//H
	if(!x)Sleep(300);
	colorS();
	circleS(45, 210, 210);//H
	if(!x)Sleep(300);
	colorS();
	circleS(45, 210, 320);//H
	if(!x)Sleep(300);
	colorS();
	circleS(45, 210, 430);//H
	if(!x)Sleep(300);
	colorS();

	circleS(45, 430, 100);//M
	if(!x)Sleep(300);
	colorS();
	circleS(45, 430, 210);//M
	if(!x)Sleep(300);
	colorS();
	circleS(45, 430, 320);//M
	if(!x)Sleep(300);
	colorS();
	circleS(45, 540, 100);//M
	if(!x)Sleep(300);
	colorS();
	circleS(45, 540, 210);//M
	if(!x)Sleep(300);
	colorS();
	circleS(45, 540, 320);//M
	if(!x)Sleep(300);
	colorS();
	circleS(45, 540, 430);//M
	if(!x)Sleep(300);
	colorS();

	circleS(45, 760, 100);//S
	if(!x)Sleep(300);
	colorS();
	circleS(45, 760, 210);//S
	if(!x)Sleep(300);
	colorS();
	circleS(45, 760, 320);//S
	if(!x)Sleep(300);
	colorS();
	circleS(45, 870, 100);//S
	if(!x)Sleep(300);
	colorS();
	circleS(45, 870, 210);//S
	if(!x)Sleep(300);
	colorS();
	circleS(45, 870, 320);//S
	if(!x)Sleep(300);
	colorS();
	circleS(45, 870, 430);//S
	if(!x)Sleep(300);
	colorS();
	x = 1;
	time_t t = time(NULL);
	struct tm *tmp = localtime(&t);

	int h = (t / 3600) % 24 - 4;
	int m = (t / 60) % 60;
	int s = t % 60;

	//printf("%02d:%02d:%02d\n",h,m,s);

	setUnitsS(tmp->tm_hour, 210);
	setUnitsS(tmp->tm_min, 540);
	setUnitsS(s, 870);
	setTensS(tmp->tm_hour, 100);
	setTensS(tmp->tm_min, 430);
	setTensS(s, 760);
	char hour[3], min[3], sec[3];
	sprintf(hour, "%02d", tmp->tm_hour);
	setFontS(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0, 1.0, 1.0);
	drawstringS(135.0, 500.0, 1.0, hour);
	sprintf(min, "%02d", tmp->tm_min);
	setFontS(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0, 1.0, 1.0);
	drawstringS(465.0, 500.0, 1.0, min);
	sprintf(sec, "%02d", s);
	setFontS(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0, 1.0, 1.0);
	drawstringS(795.0, 500.0, 1.0, sec);
	glFlush();
	Sleep(1000);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glutSwapBuffers();
	//usleep(100000);//usleep(100000); is the best
	glutPostRedisplay();
}


void color_fillP(int, int, int);

void drawP()
{
	time_t currentTime;
	struct tm *localTime;
	time(&currentTime);
	localTime = localtime(&currentTime);
	int Hour = localTime->tm_hour;
	int Min = localTime->tm_min;
	int Sec = localTime->tm_sec;

	int h1 = Hour / 10;
	int h2 = Hour % 10;
	int m1 = Min / 10;
	int m2 = Min % 10;
	int s1 = Sec / 10;
	int s2 = Sec % 10;

	color_fillP(h1, 0, 20);
	setFontS(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstringS(19, 32, 0, ":");
	color_fillP(h2, 8, 20);
	color_fillP(m1, 18, 20);
	setFontS(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstringS(37, 24, 0, ":");
	color_fillP(m2, 26, 20);
	color_fillP(s1, 36, 20);
	setFontS(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstringS(37, 32, 0, ":");
	color_fillP(s2, 44, 20);
	setFontS(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstringS(19, 24, 0, ":");

	color_fillP(h1, 0, 20);
	color_fillP(h2, 8, 20);
	color_fillP(m1, 18, 20);
	color_fillP(m2, 26, 20);
	color_fillP(s1, 36, 20);
	color_fillP(s2, 44, 20);
	glFlush();
	Sleep(1000);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutPostRedisplay();
}

void color_fillP(int k, int i, int j)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);

	switch (k){

	case 0:    {
		glVertex3f(5.0 + i, 4.0 + j, 0.0); glVertex3f(3.0 + i, 2.0 + j, 0.0); glVertex3f(9.0 + i, 2.0 + j, 0.0); glVertex3f(7.0 + i, 4.0 + j, 0.0);//1 bottom
		glVertex3f(7.0 + i, 5.0 + j, 0.0); glVertex3f(9.0 + i, 3.0 + j, 0.0); glVertex3f(9.0 + i, 9.0 + j, 0.0); glVertex3f(7.0 + i, 7.0 + j, 0.0);//1 right lower
		glVertex3f(3.0 + i, 3.0 + j, 0.0); glVertex3f(5.0 + i, 5.0 + j, 0.0); glVertex3f(5.0 + i, 7.0 + j, 0.0); glVertex3f(3.0 + i, 9.0 + j, 0.0);//1 left lower
		glVertex3f(3.0 + i, 10.0 + j, 0.0); glVertex3f(5.0 + i, 12.0 + j, 0.0); glVertex3f(5.0 + i, 14.0 + j, 0.0); glVertex3f(3.0 + i, 16.0 + j, 0.0);//1 left upper
		glVertex3f(3.0 + i, 17.0 + j, 0.0); glVertex3f(5.0 + i, 15.0 + j, 0.0); glVertex3f(7.0 + i, 15.0 + j, 0.0); glVertex3f(9.0 + i, 17.0 + j, 0.0);//1 top
		glVertex3f(7.0 + i, 12.0 + j, 0.0); glVertex3f(9.0 + i, 10.0 + j, 0.0); glVertex3f(9.0 + i, 16.0 + j, 0.0); glVertex3f(7.0 + i, 14.0 + j, 0.0);//1 right upper
		break;
	}

	case 1:
	{
		glVertex3f(7.0 + i, 5.0 + j, 0.0); glVertex3f(9.0 + i, 3.0 + j, 0.0); glVertex3f(9.0 + i, 9.0 + j, 0.0); glVertex3f(7.0 + i, 7.0 + j, 0.0);//1 right lower
		glVertex3f(7.0 + i, 12.0 + j, 0.0); glVertex3f(9.0 + i, 10.0 + j, 0.0); glVertex3f(9.0 + i, 16.0 + j, 0.0); glVertex3f(7.0 + i, 14.0 + j, 0.0);//1 right upper
		break;
	}
	case 2:
	{
		glVertex3f(3.0 + i, 17.0 + j, 0.0); glVertex3f(5.0 + i, 15.0 + j, 0.0); glVertex3f(7.0 + i, 15.0 + j, 0.0); glVertex3f(9.0 + i, 17.0 + j, 0.0);//1 top
		glVertex3f(7.0 + i, 12.0 + j, 0.0); glVertex3f(9.0 + i, 10.0 + j, 0.0); glVertex3f(9.0 + i, 16.0 + j, 0.0); glVertex3f(7.0 + i, 14.0 + j, 0.0);//1 right upper
		glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 11.0 + j, 0.0); glVertex3f(5.0 + i, 11.0 + j, 0.0); glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 8.0 + j, 0.0); glVertex3f(5.0 + i, 8.0 + j, 0.0);//mid
		glVertex3f(3.0 + i, 3.0 + j, 0.0); glVertex3f(5.0 + i, 5.0 + j, 0.0); glVertex3f(5.0 + i, 7.0 + j, 0.0); glVertex3f(3.0 + i, 9.0 + j, 0.0);//1 left lower
		glVertex3f(5.0 + i, 4.0 + j, 0.0); glVertex3f(3.0 + i, 2.0 + j, 0.0); glVertex3f(9.0 + i, 2.0 + j, 0.0); glVertex3f(7.0 + i, 4.0 + j, 0.0);//1 bottom
		break;
	}
	case 3:
	{
		glVertex3f(7.0 + i, 5.0 + j, 0.0); glVertex3f(9.0 + i, 3.0 + j, 0.0); glVertex3f(9.0 + i, 9.0 + j, 0.0); glVertex3f(7.0 + i, 7.0 + j, 0.0);//1 right lower
		glVertex3f(3.0 + i, 17.0 + j, 0.0); glVertex3f(5.0 + i, 15.0 + j, 0.0); glVertex3f(7.0 + i, 15.0 + j, 0.0); glVertex3f(9.0 + i, 17.0 + j, 0.0);//1 top
		glVertex3f(7.0 + i, 12.0 + j, 0.0); glVertex3f(9.0 + i, 10.0 + j, 0.0); glVertex3f(9.0 + i, 16.0 + j, 0.0); glVertex3f(7.0 + i, 14.0 + j, 0.0);//1 right upper
		glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 11.0 + j, 0.0); glVertex3f(5.0 + i, 11.0 + j, 0.0); glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 8.0 + j, 0.0); glVertex3f(5.0 + i, 8.0 + j, 0.0);//mid
		glVertex3f(5.0 + i, 4.0 + j, 0.0); glVertex3f(3.0 + i, 2.0 + j, 0.0); glVertex3f(9.0 + i, 2.0 + j, 0.0); glVertex3f(7.0 + i, 4.0 + j, 0.0);//1 bottom
		break;
	}
	case 4:
	{
		glVertex3f(7.0 + i, 5.0 + j, 0.0); glVertex3f(9.0 + i, 3.0 + j, 0.0); glVertex3f(9.0 + i, 9.0 + j, 0.0); glVertex3f(7.0 + i, 7.0 + j, 0.0);//1 right lower
		glVertex3f(7.0 + i, 12.0 + j, 0.0); glVertex3f(9.0 + i, 10.0 + j, 0.0); glVertex3f(9.0 + i, 16.0 + j, 0.0); glVertex3f(7.0 + i, 14.0 + j, 0.0);//1 right upper
		glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 11.0 + j, 0.0); glVertex3f(5.0 + i, 11.0 + j, 0.0); glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 8.0 + j, 0.0); glVertex3f(5.0 + i, 8.0 + j, 0.0);//mid
		glVertex3f(3.0 + i, 10.0 + j, 0.0); glVertex3f(5.0 + i, 12.0 + j, 0.0); glVertex3f(5.0 + i, 14.0 + j, 0.0); glVertex3f(3.0 + i, 16.0 + j, 0.0);//1 left upper
		break;
	}
	case 5:
	{
		glVertex3f(7.0 + i, 5.0 + j, 0.0); glVertex3f(9.0 + i, 3.0 + j, 0.0); glVertex3f(9.0 + i, 9.0 + j, 0.0); glVertex3f(7.0 + i, 7.0 + j, 0.0);//1 right lower
		glVertex3f(3.0 + i, 17.0 + j, 0.0); glVertex3f(5.0 + i, 15.0 + j, 0.0); glVertex3f(7.0 + i, 15.0 + j, 0.0); glVertex3f(9.0 + i, 17.0 + j, 0.0);//1 top
		glVertex3f(3.0 + i, 10.0 + j, 0.0); glVertex3f(5.0 + i, 12.0 + j, 0.0); glVertex3f(5.0 + i, 14.0 + j, 0.0); glVertex3f(3.0 + i, 16.0 + j, 0.0);//1 left upper
		glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 11.0 + j, 0.0); glVertex3f(5.0 + i, 11.0 + j, 0.0); glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 8.0 + j, 0.0); glVertex3f(5.0 + i, 8.0 + j, 0.0);//mid
		glVertex3f(5.0 + i, 4.0 + j, 0.0); glVertex3f(3.0 + i, 2.0 + j, 0.0); glVertex3f(9.0 + i, 2.0 + j, 0.0); glVertex3f(7.0 + i, 4.0 + j, 0.0);//1 bottom
		break;
	}
	case 6:
	{
		glVertex3f(7.0 + i, 5.0 + j, 0.0); glVertex3f(9.0 + i, 3.0 + j, 0.0); glVertex3f(9.0 + i, 9.0 + j, 0.0); glVertex3f(7.0 + i, 7.0 + j, 0.0);//1 right lower
		glVertex3f(3.0 + i, 17.0 + j, 0.0); glVertex3f(5.0 + i, 15.0 + j, 0.0); glVertex3f(7.0 + i, 15.0 + j, 0.0); glVertex3f(9.0 + i, 17.0 + j, 0.0);//1 top
		glVertex3f(3.0 + i, 10.0 + j, 0.0); glVertex3f(5.0 + i, 12.0 + j, 0.0); glVertex3f(5.0 + i, 14.0 + j, 0.0); glVertex3f(3.0 + i, 16.0 + j, 0.0);//1 left upper
		glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 11.0 + j, 0.0); glVertex3f(5.0 + i, 11.0 + j, 0.0); glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 8.0 + j, 0.0); glVertex3f(5.0 + i, 8.0 + j, 0.0);//mid
		glVertex3f(5.0 + i, 4.0 + j, 0.0); glVertex3f(3.0 + i, 2.0 + j, 0.0); glVertex3f(9.0 + i, 2.0 + j, 0.0); glVertex3f(7.0 + i, 4.0 + j, 0.0);//1 bottom
		glVertex3f(3.0 + i, 3.0 + j, 0.0); glVertex3f(5.0 + i, 5.0 + j, 0.0); glVertex3f(5.0 + i, 7.0 + j, 0.0); glVertex3f(3.0 + i, 9.0 + j, 0.0);//1 left lower
		break;
	}

	case 7:
	{
		glVertex3f(3.0 + i, 17.0 + j, 0.0); glVertex3f(5.0 + i, 15.0 + j, 0.0); glVertex3f(7.0 + i, 15.0 + j, 0.0); glVertex3f(9.0 + i, 17.0 + j, 0.0);//1 top
		glVertex3f(7.0 + i, 5.0 + j, 0.0); glVertex3f(9.0 + i, 3.0 + j, 0.0); glVertex3f(9.0 + i, 9.0 + j, 0.0); glVertex3f(7.0 + i, 7.0 + j, 0.0);//1 right lower
		glVertex3f(7.0 + i, 12.0 + j, 0.0); glVertex3f(9.0 + i, 10.0 + j, 0.0); glVertex3f(9.0 + i, 16.0 + j, 0.0); glVertex3f(7.0 + i, 14.0 + j, 0.0);//1 right upper
		break;
	}
	case 8:
	{
		glVertex3f(5.0 + i, 4.0 + j, 0.0); glVertex3f(3.0 + i, 2.0 + j, 0.0); glVertex3f(9.0 + i, 2.0 + j, 0.0); glVertex3f(7.0 + i, 4.0 + j, 0.0);//1 bottom
		glVertex3f(7.0 + i, 5.0 + j, 0.0); glVertex3f(9.0 + i, 3.0 + j, 0.0); glVertex3f(9.0 + i, 9.0 + j, 0.0); glVertex3f(7.0 + i, 7.0 + j, 0.0);//1 right lower
		glVertex3f(3.0 + i, 3.0 + j, 0.0); glVertex3f(5.0 + i, 5.0 + j, 0.0); glVertex3f(5.0 + i, 7.0 + j, 0.0); glVertex3f(3.0 + i, 9.0 + j, 0.0);//1 left lower
		glVertex3f(3.0 + i, 10.0 + j, 0.0); glVertex3f(5.0 + i, 12.0 + j, 0.0); glVertex3f(5.0 + i, 14.0 + j, 0.0); glVertex3f(3.0 + i, 16.0 + j, 0.0);//1 left upper
		glVertex3f(3.0 + i, 17.0 + j, 0.0); glVertex3f(5.0 + i, 15.0 + j, 0.0); glVertex3f(7.0 + i, 15.0 + j, 0.0); glVertex3f(9.0 + i, 17.0 + j, 0.0);//1 top
		glVertex3f(7.0 + i, 12.0 + j, 0.0); glVertex3f(9.0 + i, 10.0 + j, 0.0); glVertex3f(9.0 + i, 16.0 + j, 0.0); glVertex3f(7.0 + i, 14.0 + j, 0.0);//1 right upper
		glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 11.0 + j, 0.0); glVertex3f(5.0 + i, 11.0 + j, 0.0); glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 8.0 + j, 0.0); glVertex3f(5.0 + i, 8.0 + j, 0.0);//mid
	}
	case 9:
	{
		glVertex3f(5.0 + i, 4.0 + j, 0.0); glVertex3f(3.0 + i, 2.0 + j, 0.0); glVertex3f(9.0 + i, 2.0 + j, 0.0); glVertex3f(7.0 + i, 4.0 + j, 0.0);//1 bottom
		glVertex3f(7.0 + i, 5.0 + j, 0.0); glVertex3f(9.0 + i, 3.0 + j, 0.0); glVertex3f(9.0 + i, 9.0 + j, 0.0); glVertex3f(7.0 + i, 7.0 + j, 0.0);//1 right lower
		glVertex3f(3.0 + i, 10.0 + j, 0.0); glVertex3f(5.0 + i, 12.0 + j, 0.0); glVertex3f(5.0 + i, 14.0 + j, 0.0); glVertex3f(3.0 + i, 16.0 + j, 0.0);//1 left upper
		glVertex3f(3.0 + i, 17.0 + j, 0.0); glVertex3f(5.0 + i, 15.0 + j, 0.0); glVertex3f(7.0 + i, 15.0 + j, 0.0); glVertex3f(9.0 + i, 17.0 + j, 0.0);//1 top
		glVertex3f(7.0 + i, 12.0 + j, 0.0); glVertex3f(9.0 + i, 10.0 + j, 0.0); glVertex3f(9.0 + i, 16.0 + j, 0.0); glVertex3f(7.0 + i, 14.0 + j, 0.0);//1 right upper
		glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 11.0 + j, 0.0); glVertex3f(5.0 + i, 11.0 + j, 0.0); glVertex3f(3.5 + i, 9.5 + j, 0.0); glVertex3f(8.5 + i, 9.5 + j, 0.0); glVertex3f(7.0 + i, 8.0 + j, 0.0); glVertex3f(5.0 + i, 8.0 + j, 0.0);//mid
	}
	}
	glEnd();
	glFlush();
}


// all 5 square co-ordinates
float sc[5][4] = { -0.5f, 0.2f, -0.25f, 0.6f,
-0.5f, 0.6f, -0.25f, 1.0f,
-1.0f, 0.2f, -0.5f, 1.0f,
-1.0f, -1.0f, -0.25f, 0.2f,
-0.25f, -1.0f, 1.0f, 1.0f };

// All 5 fibonacci numbers
int fib[5] = { 1, 1, 2, 3, 5 }, i, j, hours, minutes;
// All possible value from fibonacci numbers stored in this vector(values)
vector <vector<int>> values[13];
// Tells which value to choose for hour and minute
vector <int> h, m;
// Marks values to be taken
bool hp[5], mp[5];

//prints rectangle
void rectD(float x1, float y1, float x2, float y2)
{
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

// Finds color according to state of block(hour,minute)
void colorD(bool h, bool m)
{
	if (h && m) glColor3f(0.0f, 0.0f, 1.0f); //Blue
	else if (h) glColor3f(1.0f, 0.0f, 0.0f); //Red
	else if (m) glColor3f(0.0f, 1.0f, 0.0f); //Green
	else glColor3f(1.0f, 1.0f, 1.0f); //White
}

void displayD()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

	// Takes hours and minutes from local time
	time_t t = time(NULL);
	struct tm *tmp = localtime(&t);
	hours = tmp->tm_hour;
	minutes = tmp->tm_min / 5;
	if (hours > 12) hours -= 12;
	cout << hours << ":" << minutes * 5 << endl;

	//Randomly takes possible indexes for hour and minutes and marks them
	srand(time(NULL));
	h = values[hours][rand() % values[hours].size()];
	m = values[minutes][rand() % values[minutes].size()];
	//Marks them
	for (i = 0; i < 5; i++) hp[i] = mp[i] = false;
	for (i = 0; i < h.size(); i++) hp[h[i]] = true;
	for (i = 0; i < m.size(); i++) mp[m[i]] = true;


	colorD(hp[0], mp[0]);
	rectD(sc[0][0], sc[0][1], sc[0][2], sc[0][3]);

	colorD(hp[1], mp[1]);
	rectD(sc[1][0], sc[1][1], sc[1][2], sc[1][3]);

	colorD(hp[2], mp[2]);
	rectD(sc[2][0], sc[2][1], sc[2][2], sc[2][3]);

	colorD(hp[3], mp[3]);
	rectD(sc[3][0], sc[3][1], sc[3][2], sc[3][3]);

	colorD(hp[4], mp[4]);
	rectD(sc[4][0], sc[4][1], sc[4][2], sc[4][3]);


	//LINES
	glLineWidth(2.5);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glVertex3f(sc[2][0], sc[2][1], 0.0);
	glVertex3f(sc[3][2], sc[3][3], 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(sc[4][0], sc[4][1], 0.0);
	glVertex3f(sc[4][0], sc[1][3], 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(sc[0][0], sc[0][1], 0.0);
	glVertex3f(sc[2][2], sc[2][3], 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(sc[1][0], sc[1][1], 0.0);
	glVertex3f(sc[0][2], sc[0][3], 0.0);
	glEnd();

	//Border Lines
	glLineWidth(5.5);

	glBegin(GL_LINES);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(-1.0, -1.0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(1.0, -1.0, 0);
	glEnd();

	glFlush();  // Render now
	Sleep(1000);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutPostRedisplay();
}

void process_Normal_Keys(int key, int x, int y);
int id;
void RunS()
{
	glutDestroyWindow(id);
	glutInitWindowPosition(60, 0);
	id=glutCreateWindow("binary_clock");
	gluOrtho2D(0, 960, 0, 640);
	glutDisplayFunc(drawS);
	glutSpecialFunc(process_Normal_Keys);
}
void RunD()
{
	glutDestroyWindow(id);
	glutInitWindowPosition(60, 0); // Position the window's initial top-left corner
	glutInitWindowSize(960, 640);   // Set the window's initial width & height
	id=glutCreateWindow("Fibonacci Clock"); // Create a window with the given title
	glutDisplayFunc(displayD); // Register display callback handler for window re-paint
	glutSpecialFunc(process_Normal_Keys);
}
void RunP()
{
	glutDestroyWindow(id);
	glutInitWindowPosition(60, 0);
	id=glutCreateWindow("seven_segment");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 70.0, 0.0, 70.0, -1.0, 1.0);
	glutDisplayFunc(drawP);
	glutSpecialFunc(process_Normal_Keys);
}
void process_Normal_Keys(int key, int x, int y)
{
	switch (key)
	{
	case 27:  break;
	case 100: RunD(); break; //Left key
	case 102: RunP(); break; //Right key
	case 101: RunS(); break; //Up key
	}
}

int main(int argc, char **argv)
{


	//Generates all subsets of 5 fibonacci numbers using bitmasking technique
	for (i = 0; i < (1 << 5); i++)
	{
		int sum = 0;
		vector <int> temp;
		for (j = 0; j < 5; j++)
		{
			if (i&(1 << j))
			{
				sum += fib[j];
				temp.push_back(j); //pushes indexes
			}
		}
		values[sum].push_back(temp);
	}


	int c = 1;
	glutInit(&argc, argv);//initialize GLUT library
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(960, 640);
	A: cout << "1. Binary Clock" << endl;
	cout << "2. Digital Clock" << endl;
	cout << "3. Fibonacci Clock" << endl;
	cout << "Enter choice: ";
	cin >> c;

	if (c == 1)
	{
		glutInitWindowPosition(60, 0);
		id = glutCreateWindow("binary_clock");
		gluOrtho2D(0, 960, 0, 640);
		glutDisplayFunc(drawS);
		glutSpecialFunc(process_Normal_Keys);
	}
	else if (c == 2)
	{
		glutInitWindowPosition(60, 0);
		id = glutCreateWindow("seven_segment");
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, 70.0, 0.0, 70.0, -1.0, 1.0);
		glutDisplayFunc(drawP);
		glutSpecialFunc(process_Normal_Keys);
	}
	else if(c == 3)
	{	
		glutInitWindowPosition(60, 0); // Position the window's initial top-left corner
		glutInitWindowSize(960, 640);   // Set the window's initial width & height
		id = glutCreateWindow("Fibonacci Clock"); // Create a window with the given title
		glutDisplayFunc(displayD); // Register display callback handler for window re-paint
		glutSpecialFunc(process_Normal_Keys);
	}
	else
	{
		cout<<"Wrong Choice!"<<endl;system("pause");system("CLS");goto A;
	}

	glutMainLoop();

	return 1;
}