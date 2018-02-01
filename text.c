#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<string.h>
#include<stdio.h>


void init()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);	
}

void disptext(char *text,int x,int y)
{
	int n,i;
	n=strlen(text);
	glRasterPos2f(x,y);
	for(i=0;i<n;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
	}
	glFlush();
}

void display()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	disptext("graphics",100,200);
	glColor3f(0.5,1,0);
	disptext("Google",300,300);
}

int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Drawing");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

