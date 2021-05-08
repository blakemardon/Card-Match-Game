#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <windows.h>
#include "Icon.h"
#include "Color.h"
#include "CardComponent.h"
#include "IClickable.h"
#include "TextComponent.h"
#include "CardMatch.h"


CardComponent* card = nullptr;

int viewWidth = 500;
int viewHeight = 500;

CardMatch game = CardMatch(5, 4);

void init(void)
{
	glClearColor(PaletteColors::DarkGreen);//get white background color
	glColor3f(0.0f, 0.0f, 0.0f);//set drawing color
	glPointSize(4.0);//a dot is 4x4
	glLineWidth(4);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//replace current matrix with identity matrix
	gluOrtho2D(0.0, viewWidth, 0.0, viewHeight);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(PaletteColors::DarkGreen);
    IDrawable::drawObjects();
    glFlush();
	if (game.needsDelay) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		game.needsDelay = false;
		game.DelayDone();
	}
	
}

void onMouseButton(int button, int state, int x, int y) {
	float worldx = (float)x / glutGet(GLUT_WINDOW_WIDTH) * viewWidth;
	float worldy = 500 - (float)y / glutGet(GLUT_WINDOW_HEIGHT) * viewHeight;
	if (GLUT_DOWN == state) {
		IClickable::triggerClicks(worldx, worldy);
		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);//initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set display mode: single bufferring, RGBA model
	glutInitWindowSize(700, 700);//set window size on screen
	glutInitWindowPosition(100, 150); //set window position on screen
	glutCreateWindow(argv[0]);//open screen window
	init();
	glutDisplayFunc(display);//points to display function
	glutMouseFunc(onMouseButton);
	glutMainLoop();//go into perpetual loop
	return 0;
}