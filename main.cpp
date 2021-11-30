#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
#include <stdio.h>


GLfloat position = 0.0f;
GLfloat speed = 0.1f;


void update(int value) {

    if(position > 1.0)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0, 0, 0, 0);
   glMatrixMode(GL_MODELVIEW);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'a':
    speed = 0.0f;
    break;
case 'w':
    speed = 0.1f;
    break;


glutPostRedisplay();


	}
}


/*void wheel(int x, int y)
{
    float t;

    glBegin(GL_LINE_LOOP);
    for(int i=0.0f;i<360.0f;i++)
    {
        t=i*3.142/180;
        glVertex2f(x+0.03*cos(t),y+0.03*sin(t));
    }
    glEnd();
}*/

void car(){

    glBegin(GL_LINE_LOOP);
    //glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, -0.44f);
    glVertex2f(-0.2f, -0.44f);
    glVertex2f(-0.2f, -0.5f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f, -0.44f);
    glVertex2f(-0.45f, -0.4f);
    glVertex2f(-0.3f, -0.4f);
    glVertex2f(-0.25f, -0.44f);
    glEnd();

    //wheel(-0.4, -0.5);
    //wheel(-0.27, -0.5);

}


void tree()
{
    //=======================================================
//Tree Code
//Left Side Tree
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();

glTranslatef(0.0, 0.4, 0.0);
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();

glTranslatef(0.6, -0.4, 0.0);
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();

glTranslatef(0.0, 0.45, 0.0);
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();


glTranslatef(1.2, -0.23, 0.0);
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();
}

void display() {
    glClearColor(0.0f, 0.7f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

//================================================
//Sky Code
glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(-1.0f, 0.6f);
glEnd();
//==================================================



//==================================================
//Left side
//HILL CODE 1
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(-0.8f, 0.75f);
    glVertex2f(-0.7f, 0.6f);
    glVertex2f(-0.9f, 0.6f);
glEnd();

//HILL CODE 2
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(-0.7f, 0.75f);
    glVertex2f(-0.6f, 0.6f);
    glVertex2f(-0.8f, 0.6f);
glEnd();

//HILL CODE 3
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(-0.6f, 0.75f);
    glVertex2f(-0.5f, 0.6f);
    glVertex2f(-0.7f, 0.6f);
glEnd();


//Right side
//HILL CODE 4
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(0.8f, 0.75f);
    glVertex2f(0.7f, 0.6f);
    glVertex2f(0.9f, 0.6f);
glEnd();

//HILL CODE 5
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(0.7f, 0.75f);
    glVertex2f(0.6f, 0.6f);
    glVertex2f(0.8f, 0.6f);
glEnd();

//HILL CODE 6
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(0.6f, 0.75f);
    glVertex2f(0.5f, 0.6f);
    glVertex2f(0.7f, 0.6f);
glEnd();
//=============================================



//=============================================
//ROAD CODE
glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(-1.0f, -0.6f);
glEnd();

//Road white color right side
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.3f, -0.35f);
    glVertex2f(0.6f, -0.35f);
    glVertex2f(0.6f, -0.36f);
    glVertex2f(0.3f, -0.36f);
glEnd();


//Road white color middle side
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.3f, -0.35f);
    glVertex2f(0.0f, -0.35f);
    glVertex2f(0.0f, -0.36f);
    glVertex2f(-0.3f, -0.36f);
glEnd();


//Road white color left side
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-0.6f, -0.35f);
    glVertex2f(-0.6f, -0.36f);
    glVertex2f(-0.9f, -0.36f);
glEnd();
//================================================



//================================================
//RIVER CODE
glBegin(GL_QUADS);
    glColor3f(0.6f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
glEnd();
//================================================



//================================================
//SCHOOL CODE
//School Roof
glBegin(GL_QUADS);
    glColor3f(0.9f, 1.0f, 0.0f);
    glVertex2f(-0.18f, 0.55f);
    glVertex2f(0.6f, 0.55f);
    glVertex2f(0.55f, 0.4);
    glVertex2f(-0.2f, 0.4f);
glEnd();

//School Right Side
glBegin(GL_QUADS);
    glColor3f(0.8f, 1.0f, 0.5f);
    glVertex2f(0.55f, 0.4f);
    glVertex2f(0.6f, 0.55f);
    glVertex2f(0.6f, 0.05f);
    glVertex2f(0.55f, 0.0f);
glEnd();

//School Left Side
glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(0.55f, 0.4f);
    glVertex2f(0.55f, 0.0f);
    glVertex2f(-0.2f, 0.0f);
glEnd();

//School Door
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.1f, 0.125f);
    glVertex2f(0.25f, 0.125f);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(0.1f, 0.0f);
glEnd();

/*
//House to Road Code
glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.22f, 0.0f);
    glVertex2f(0.13f, 0.0f);
    glVertex2f(0.13f, -0.1f);
    glVertex2f(0.22f, -0.1f);
glEnd();*/


//School Window 1 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.15f, 0.35f);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(-0.1f, 0.28f);
    glVertex2f(-0.15f, 0.28f);
glEnd();

//School Window 2 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.05f, 0.35f);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.0f, 0.28f);
    glVertex2f(-0.05f, 0.28f);
glEnd();


//School Window 3 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.05f, 0.35f);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(0.1f, 0.28f);
    glVertex2f(0.05f, 0.28f);
glEnd();

//School Window 4 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.15f, 0.35f);
    glVertex2f(0.2f, 0.35f);
    glVertex2f(0.2f, 0.28f);
    glVertex2f(0.15f, 0.28f);
glEnd();

//School Window 5 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.25f, 0.35f);
    glVertex2f(0.3f, 0.35f);
    glVertex2f(0.3f, 0.28f);
    glVertex2f(0.25f, 0.28f);
glEnd();


//School Window 6 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.35f, 0.35f);
    glVertex2f(0.4f, 0.35f);
    glVertex2f(0.4f, 0.28f);
    glVertex2f(0.35f, 0.28f);
glEnd();

//School Window 7 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.45f, 0.35f);
    glVertex2f(0.5f, 0.35f);
    glVertex2f(0.5f, 0.28f);
    glVertex2f(0.45f, 0.28f);
glEnd();

//School Window 1
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.15f, 0.25f);
    glVertex2f(-0.1f, 0.25f);
    glVertex2f(-0.1f, 0.18f);
    glVertex2f(-0.15f, 0.18f);
glEnd();

//School Window 2
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(0.0f, 0.25f);
    glVertex2f(0.0f, 0.18f);
    glVertex2f(-0.05f, 0.18f);
glEnd();


//School Window 3
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.05f, 0.25f);
    glVertex2f(0.1f, 0.25f);
    glVertex2f(0.1f, 0.18f);
    glVertex2f(0.05f, 0.18f);
glEnd();

//School Window 4
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.15f, 0.25f);
    glVertex2f(0.2f, 0.25f);
    glVertex2f(0.2f, 0.18f);
    glVertex2f(0.15f, 0.18f);
glEnd();

//School Window 5
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.18f);
    glVertex2f(0.25f, 0.18f);
glEnd();


//School Window 6
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.35f, 0.25f);
    glVertex2f(0.4f, 0.25f);
    glVertex2f(0.4f, 0.18f);
    glVertex2f(0.35f, 0.18f);
glEnd();

//School Window 7
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.45f, 0.25f);
    glVertex2f(0.5f, 0.25f);
    glVertex2f(0.5f, 0.18f);
    glVertex2f(0.45f, 0.18f);
glEnd();
//=======================================================



//=======================================================
//HOUSE CODE
glBegin(GL_QUADS);
    glColor3f(0.3f, 0.4f, 0.5f);
    glVertex2f(-0.7f, 0.4f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.6f, 0.2f);
    glVertex2f(-0.7f, 0.2f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.0f, 0.9f);
    glVertex2f(-0.7f, 0.4f);
    glVertex2f(-0.65f, 0.52f);
    glVertex2f(-0.6f, 0.4f);
glEnd();

//Door Code

glBegin(GL_QUADS);
    glColor3f(0.5f, 0.2f, 0.4f);
    glVertex2f(-0.67f, 0.33f);
    glVertex2f(-0.63f, 0.33f);
    glVertex2f(-0.63f, 0.2f);
    glVertex2f(-0.67f, 0.2f);
glEnd();




glBegin(GL_QUADS);
    glColor3f(0.3f, 0.4f, 0.5f);
    glVertex2f(-0.65f, 0.52f);
    glVertex2f(-0.47f, 0.52f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.6f, 0.4f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.1f, 0.3f, 0.3f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.6f, 0.2f);
glEnd();


//Window
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.58f, 0.37f);
    glVertex2f(-0.53f, 0.37f);
    glVertex2f(-0.53f, 0.3f);
    glVertex2f(-0.58f, 0.3f);
glEnd();

//Window L
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.49f, 0.37f);
    glVertex2f(-0.44f, 0.37f);
    glVertex2f(-0.44f, 0.3f);
    glVertex2f(-0.49f, 0.3f);
glEnd();
//=========================================





//=====================================================
glPushMatrix();
glTranslatef(position,0.0f, 0.0f);

//B0AT CODE
glBegin(GL_QUADS);
    glColor3f(0.9f, 0.8f, 0.5f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.4f, -0.8f);
    glVertex2f(-0.5f, -0.95f);
    glVertex2f(-0.7f, -0.95f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.6f, -0.625f);
    glVertex2f(-0.5f, -0.8f);
    glVertex2f(-0.6f, -0.8f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.6f, -0.7f);
    glVertex2f(-0.6f, -0.8f);
    glVertex2f(-0.7f, -0.8f);
glEnd();


    glPopMatrix();
    //car();
    tree();
    glutSwapBuffers();
    glFlush();
}
//=================================================================



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(1000, 600);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(25, update, 0);
   glutMainLoop();
   return 0;

}
