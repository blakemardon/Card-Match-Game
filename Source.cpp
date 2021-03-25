#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "Icon.h"
#include "Color.h"


void init(void)
{
	glClearColor(Color(PaletteColors::DarkGreen));//get white background color
	glColor3f(0.0f, 0.0f, 0.0f);//set drawing color
	glPointSize(4.0);//a dot is 4x4
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//replace current matrix with identity matrix
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display(void)
{
	Icon i(Icons::Cat, 0.5, Color(PaletteColors::Blue, 1.0), Color(PaletteColors::Yellow));
	i.draw(250, 250);
	/* color class test
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Color c(static_cast<Colors>(i * 4 + j));
			c.applyColor();
			//glColor3f(1.0f, 1.0f, 0.0f);
			glBegin(GL_POLYGON);
			glVertex2i(i * 125, j * 125);
			glVertex2i(i * 125, j * 125 + 125);
			glVertex2i(i * 125 + 125, j * 125 + 125);
			glVertex2i(i * 125 + 125, j * 125);
			glEnd();
			glFlush();
		}
	}
	*/
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);//initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set display mode: single bufferring, RGBA model
	glutInitWindowSize(500, 500);//set window size on screen
	glutInitWindowPosition(100, 150); //set window position on screen
	glutCreateWindow(argv[0]);//open screen window
	init();
	glutDisplayFunc(display);//points to display function
	glutMainLoop();//go into perpetual loop
	return 0;
}