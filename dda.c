#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>

float X1, Y1, X2, Y2;

float round_value(float v)
{
  return floor(v + 0.5);
}

void DDAline(void)
{
  float dx=(X2-X1);
  float dy=(Y2-Y1);
  float steps;
  float xInc,yInc,x=X1,y=Y1;
  /* Find out whether to increment x or y */
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0,0,0);
  glBegin(GL_LINES);
  glPointSize(5.0);
  //glVertex2d(x,y);
  int k;
 
  for(k=0;k<steps;k++)
  {
    glVertex2d(round_value(x), round_value(y));
    x+=xInc;
    y+=yInc;
    //printf("%f,  %f\n",x,y);
    glVertex2d(round_value(x), round_value(y));
  }
  glEnd();

  glFlush();
}

void init()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
	gluOrtho2D(-1,1,-1,1);
}


void main(int argc, char **argv)
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
  glutCreateWindow("DDA_Line");
  init();
  glutDisplayFunc(DDAline);
  glutMainLoop();
}

