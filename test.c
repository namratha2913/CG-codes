#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>

float X1, Y1, X2, Y2;

void bresenham();

void bresenham()
{
}

void init()
{
	
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
	
}

void main(int argc, char**argv)
{
	/*printf("Enter two end points of the line to be drawn:\n");
	printf("\nEnter Point1( X1 , Y1):\n");
	scanf("%f%f",&X1,&Y1);
	printf("\nEnter Point1( X2 , Y2):\n");
	scanf("%f%f",&X2,&Y2);*/

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
  	glutInitWindowSize(500,500);
	glutCreateWindow("Drawing");
	init();
	glutDisplayFunc(bresenham);
	glutMainLoop();
}

