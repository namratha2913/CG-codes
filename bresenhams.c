#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>

float X1, Y1, X2, Y2;

void init()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}


//Bresenham line-drawing procedure for |m| < 1.0
void bresenham(void)
{
 GLint dx = abs(X2-X1);
 GLint dy = abs(Y2-Y1);
 GLint p = 2*dy - dx;
 GLint twoDy = 2*dy;
 GLint twoDyMinusDx = 2*(dy-dx);
 GLint x,y;
 // determine which endpoint to use as start position
 if (X1>X2){
	 x=X2;
	 y=Y2;
	 X2=x;
 }else{
	 x=X1; 
	 y=X1;
 }
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,0);
 glBegin(GL_LINES);
 while(x<X2){

	 glVertex2f(x,y); 
	 x++;
	 if(p<0)
	 p+=twoDy;
	 else{
	 y++;
	 p+=twoDyMinusDx;
 	}
	glVertex2f(x,y); 
 }
 glEnd();
 glFlush();
} 

void main(int argc, char**argv)
{
	printf("Enter two end points of the line to be drawn:\n");
	printf("\nEnter Point1( X1 , Y1):\n");
	scanf("%f%f",&X1,&Y1);
	printf("\nEnter Point1( X2 , Y2):\n");
	scanf("%f%f",&X2,&Y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
  	glutInitWindowSize(500,500);
	glutCreateWindow("Drawing");
	init();
	glutDisplayFunc(bresenham);
	glutMainLoop();
}

