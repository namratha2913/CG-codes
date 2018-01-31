#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<math.h>
#include<stdio.h>

GLfloat x=0,y=0;
int th=0;
int n=1;
float RAD=(22.0/7)/180.0;

void init()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	//gluOrtho2D(-250,250,-250,250);
		gluOrtho2D(-1,1,-1,1);
}

void timer(int v)
{
	glutPostRedisplay();
	glutTimerFunc((500/v),timer,n);
}


void draw()
{
    glColor3f(0,1,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(x,y-2);
	glVertex2f(-y,x);
	glVertex2f(-x,-y-2);
	//glVertex2f(y,-x);
	glEnd();
	glFlush();
}

void idle(void)
{
	th=th+2;
	if(360<th)
	th=th-360;
	x=0.5*cos(RAD*th);
	y=0.5*sin(RAD*th);
	
	glutPostRedisplay();
} 

void keypress(unsigned char key, int x,int y)
{
	switch(key)
	{
		case 'r':glutIdleFunc(idle);
				break;
		case 's':glutIdleFunc(NULL);
				break;
	}
}

void display()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glutSwapBuffers();
}

int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Drawing");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(500,timer,n);
	glutIdleFunc(idle);
	glutKeyboardFunc(keypress);
	glutMainLoop();
}

