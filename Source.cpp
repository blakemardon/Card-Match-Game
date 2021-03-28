#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "Icon.h"
#include "Color.h"
#include "CardComponent.h"
#include "IClickable.h"
#include "TextComponent.h"

CardComponent* card = nullptr;

void init(void)
{
	glClearColor(PaletteColors::DarkGreen);//get white background color
	glColor3f(0.0f, 0.0f, 0.0f);//set drawing color
	glPointSize(4.0);//a dot is 4x4
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//replace current matrix with identity matrix
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void initilizeCard() {
	Icon cat(Icons::Cat, 250, 250, 0.8, PaletteColors::Tan, PaletteColors::Yellow);
	card = new CardComponent(cat, 250, 250);
}

void display(void)
{
    TextComponent text("TEST TEST", PaletteColors::Red, 500,482, Anchor::Center);
    text.setDrawDepth(0);
    IDrawable::drawObjects();
    glFlush();
}

void onMouseButton(int button, int state, int x, int y) {
	if (GLUT_DOWN == state) {
		IClickable::triggerClicks(x, y);
		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);//initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set display mode: single bufferring, RGBA model
	glutInitWindowSize(500, 500);//set window size on screen
	glutInitWindowPosition(100, 150); //set window position on screen
	glutCreateWindow(argv[0]);//open screen window
	init();
	initilizeCard();
	glutDisplayFunc(display);//points to display function
	glutMouseFunc(onMouseButton);
	glutMainLoop();//go into perpetual loop
	return 0;
}