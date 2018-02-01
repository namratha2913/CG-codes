#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<math.h>
#include<stdio.h>


void init()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
	glColor3f(1,0,0);
}

void display()
{	
	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(10,10);
	glVertex2f(100,10);
	glVertex2f(45,100);
	glEnd();
	glFlush();
}

/*void draw()
{	
	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(10,10);
	glVertex2f(100,10);
	glVertex2f(100,100);
	glVertex2f(10,100);
	glEnd();
	glFlush();
}*/



void menu(int v)
{
	switch(v)
	{
		case 1:glColor3f(1,0,0);
			break;
		case 2:glColor3f(0,1,0);
			break;
		case 3:glColor3f(0,0,1);
			break;
		//case 4:draw();
		//	break;
		//case 5:display();
		//	break;
		case 4:exit(0);
	}
	glutPostRedisplay();
}


int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Drawing");
	init();
	int sub1=glutCreateMenu(menu);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Green",2);
	glutAddMenuEntry("Blue",3);
	glutCreateMenu(menu);
	glutAddSubMenu("Colors",sub1);
	glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutMainLoop();
}

