#include <GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>


void init()
{
 //Background color
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT );
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,500,0,500);
   //glFlush();
}

void drawclock()
{
   int i;
   const float DEG2RAD = 3.14159/180;
   glBegin(GL_LINE_LOOP);
   glLineWidth(5.0);
   glColor3f(0,0,0);
   for ( i=0; i<360; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f((cos(degInRad)*100)+150,(sin(degInRad)*100)+150);
   }
   glEnd();
   glBegin(GL_LINES);
   //glLineWidth(5.0);
   glColor3f(0,0,0);
   for ( i=0; i<360; i=i+30)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f((cos(degInRad)*100)+150,(sin(degInRad)*100)+150);
      glVertex2f((cos(degInRad)*80)+150,(sin(degInRad)*80)+150);
   }
   glEnd();
   glBegin(GL_LINES);
   glLineWidth(5.0);
   glColor3f(0,0,0);
   int hr=((30 * 4) + (0.5*30))*DEG2RAD;
   int min =((6*0))*DEG2RAD;
     glVertex2f(150,150);
    glVertex2f((cos(min)*90)+150,(sin(min)*90)+150);
     glVertex2f(150,150);
    glVertex2f((cos(hr)*70)+150,(sin(hr)*70)+150);
  
   glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  //Simple buffer
  glutInitDisplayMode( GLUT_RGB|GLUT_SINGLE );
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Clock window");
  init();
  glutDisplayFunc(drawclock);
  glutMainLoop();
  return 0;
}
