/*  Project Name: Country Scene by a Highway.
    Group No: 07.
    Group Members:
    1) Alimul Mahfuz Tushar (19-39831-1)
    2) Abdul Wazed (19-39806-1)
*/
//Press n: For Night;
//Press d: For Day;


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

GLfloat position1 = 0.0f;
GLfloat speed1 = 0.02f;

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.01f;

GLfloat position3 = 0.0f;
GLfloat speed3 = 0.009f;

//float _rain = 0.0;
//bool rainday = false;

float sr=1.0, sg=1.0, sb=0.0;
float skyr=0.0, skyg=0.5, skyb=1.0;
float skyr1=0.0, skyg1=0.5, skyb1=1.0;

char text[] = "School";


void update(int value) {

    if(position > 1.3)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}

void update1(int value) {

    if(position1 > 1.3)
        position1 = -1.0f;

    position1 += speed1;

	glutPostRedisplay();


	glutTimerFunc(100, update1, 0);
}
void update2(int value) {

    if(position2 > 0.0)
        position2 = -1.0f;

    position2 += speed2;

	glutPostRedisplay();


	glutTimerFunc(100, update2, 0);
}

void update3(int value) {

    if(position3 > 1.7)
        position3 = -1.1f;

    position3 += speed3;

	glutPostRedisplay();


	glutTimerFunc(100, update3, 0);
}

void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0f,0.0f,0.0f);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);

    }
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);

}

void rain()
{

    int i=0,j=0;
    float x,y;
    x=-1.0f;
    y=1.0f;

    while(j<=100)
    {
        x = -1.0f;
        while(i<=100)
        {
            glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f,1.0f);
            glVertex2f(x,y);
            glVertex2f(x-0.02f,y-0.07f);
            glEnd();

            x=x+0.03f;
            i++;
        }
        y = y-0.10f;
        j++;
        i=0;
    }

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

case 'n':
    skyr=0.0;
    skyg=0.0;
    skyb=0.2;

    skyr1=1.0;
    skyg1=1.0;
    skyb1=1.0;

    sr=1.0;
    sg=1.0;
    sb=1.0;

    break;
glutPostRedisplay();

case 'N':
    skyr=0.0;
    skyg=0.0;
    skyb=0.2;

    skyr1=1.0;
    skyg1=1.0;
    skyb1=1.0;

    sr=1.0;
    sg=1.0;
    sb=1.0;
    break;
glutPostRedisplay();

case 'd':
    skyr=0.0;
    skyg=0.5;
    skyb=1.0;

    skyr1=0.0;
    skyg1=0.5;
    skyb1=1.0;

    sr=1.0;
    sg=1.0;
    sb=0.0;
    break;
glutPostRedisplay();

case 'D':
    skyr=0.0;
    skyg=0.5;
    skyb=1.0;

    skyr1=0.0;
    skyg1=0.5;
    skyb1=1.0;

    sr=1.0;
    sg=1.0;
    sb=0.0;
    break;
glutPostRedisplay();

	case 'r':
	    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    rain();
    glPopMatrix();
        //rainday = true;
        //sndPlaySound("River.wav",SND_ASYNC|SND_LOOP);
        //sndPlaySound("River.wav",SND_MEMORY|SND_ASYNC);
        break;


        glutPostRedisplay();
	}
}


void car(){

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, -0.44f);
    glVertex2f(-0.22f, -0.44f);
    glVertex2f(-0.22f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f, -0.44f);
    glVertex2f(-0.45f, -0.39f);
    glVertex2f(-0.3f, -0.39f);
    glVertex2f(-0.25f, -0.44f);
    glEnd();

}
//==========================================================

void circle()
{
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
}

void circle1()
{
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.003;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
}

void circle2()
{
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.03;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
}



//===========================================================

void wheel()
{
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-0.45f, -0.5f, 0.0f);
    circle();
	glPopMatrix();

	glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-0.29f, -0.5f, 0.0f);
    circle();
	glPopMatrix();
}

void flag()
{
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.73f, 0.235f, 0.0f);
    circle2();
	glPopMatrix();
}
//======================================================

void cloud()
{
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.9f, 0.89f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.82f, 0.87f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.88f, 0.81f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.8f, 0.79f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();
}


//=========================================================

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
    glColor3f(skyr, skyg, skyb);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(-1.0f, 0.6f);
glEnd();
//==================================================

//====================================================
//SUN CODE
glPushMatrix();
    glColor3f(sr, sg, sb);
    glTranslatef(-0.25f, 0.9f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();


glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.8f, 0.8f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.9f, 0.84f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.97f, 0.74f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.6f, 0.93f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.69f, 0.86f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.73f, 0.98f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.66f, 0.8f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.55f, 0.71f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.4f, 0.9f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.45f, 0.85f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.3f, 0.75f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.2f, 0.77f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.17f, 0.668f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.1f, 0.9f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.0f, 0.64f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.8f, 0.8f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.9f, 0.84f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.97f, 0.74f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.6f, 0.93f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.69f, 0.86f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.73f, 0.98f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.66f, 0.8f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.55f, 0.71f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.4f, 0.9f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.45f, 0.85f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.3f, 0.75f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.2f, 0.63f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.2f, 0.75f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.1f, 0.9f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.8f, 0.629f, 0.0f);
    circle1();
glPopMatrix();

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

//School Text
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.1f, 0.49f);
    glVertex2f(0.3f, 0.49f);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.1f, 0.4f);
glEnd();

glPushMatrix();
glTranslatef(0.27f, 0.42f, 0.0f);
Sprint(-0.12f, 0.0f, text);
glPopMatrix();
//End of Text


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

//Flag Code
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.66f, 0.31f);
    glVertex2f(0.67f, 0.31f);
    glVertex2f(0.67f, 0.0f);
    glVertex2f(0.66f, 0.0f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(0.67f, 0.3f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(0.8f, 0.17f);
    glVertex2f(0.67f, 0.17f);
glEnd();

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
glTranslatef(position1,0.0f, 0.0f);

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

    glPushMatrix();
glTranslatef(position,0.0f, 0.0f);
    car();
    wheel();
    glPopMatrix();

    glPushMatrix();
glTranslatef(position2,0.0f, 0.0f);
    //rain();
    glPopMatrix();

    glPushMatrix();
glTranslatef(position3,0.0f, 0.0f);
    cloud();
    glPopMatrix();

    flag();
    tree();

    glutSwapBuffers();
    glFlush();
}
//=================================================================





int main(int argc, char** argv) {

   printf("\n\n******************Country Scene by a Highway****************\n\n");
   printf("Press n: For Night\n\n");
   printf("Press d: For Day\n\n");
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(1000, 600);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Country Scene by a Highway");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(100, update, 0);
   glutTimerFunc(100, update1, 0);
   glutTimerFunc(100, update2, 0);
   glutTimerFunc(100, update3, 0);
   glutMainLoop();
   return 0;
}
