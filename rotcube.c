#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<stdio.h>


int x,y,z;
double th;
int n=1;
int axis[3]={0,0,1};
GLfloat f[8][3] = {{-0.5f,-0.5f,-0.5f},{0.5f,-0.5f,-0.5f},{0.5f,0.5f,-0.5f},{-0.5f,0.5f,-0.5f},{-0.5f,-0.5f,0.5f},{0.5f,-0.5f,0.5f},{0.5f,0.5f,0.5f},{-0.5f,0.5f,0.5f}};
//GLfloat color[8][3]={(0,1,1),(1,0,1),(0,1,1),(1,1,0),(0,1,0),(0,0,1),(1,0,0),(0,1,0.5)}

void init()
{
	 glClearColor(1,1,1,0);
	 //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	 glMatrixMode(GL_PROJECTION);
	 glOrtho(-2,2,-2,2,-2,2);
}

void timer(int v)
{
	glutPostRedisplay();
	glutTimerFunc((500/v),timer,n);
}

void draw()
{
	glBegin(GL_POLYGON);
	 glColor3f(0,1,1);
	 glVertex3f(f[0][0],f[0][1],f[0][2]);
	 glVertex3f(f[1][0],f[1][1],f[1][2]);
	 glVertex3f(f[2][0],f[2][1],f[2][2]);
	 glVertex3f(f[3][0],f[3][1],f[3][2]);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glColor3f(1,0,1);
	 glVertex3f(f[1][0],f[1][1],f[1][2]);
	 glVertex3f(f[5][0],f[5][1],f[5][2]);
	 glVertex3f(f[6][0],f[6][1],f[6][2]);
	 glVertex3f(f[2][0],f[2][1],f[2][2]);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glColor3f(1,0,0);
	 glVertex3f(f[5][0],f[5][1],f[5][2]);
	 glVertex3f(f[4][0],f[4][1],f[4][2]);
	 glVertex3f(f[7][0],f[7][1],f[7][2]);
	 glVertex3f(f[6][0],f[6][1],f[6][2]);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glColor3f(1,1,0);
	 glVertex3f(f[4][0],f[4][1],f[4][2]);
	 glVertex3f(f[0][0],f[0][1],f[0][2]);
	 glVertex3f(f[3][0],f[3][1],f[3][2]);
	 glVertex3f(f[7][0],f[7][1],f[7][2]);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glColor3f(0,1,0);
	 glVertex3f(f[4][0],f[4][1],f[4][2]);
	 glVertex3f(f[5][0],f[5][1],f[5][2]);
	 glVertex3f(f[1][0],f[1][1],f[1][2]);
	 glVertex3f(f[0][0],f[0][1],f[0][2]);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glColor3f(0,0,1);
	 glVertex3f(f[6][0],f[6][1],f[6][2]);
	 glVertex3f(f[7][0],f[7][1],f[7][2]);
	 glVertex3f(f[3][0],f[3][1],f[3][2]);
	 glVertex3f(f[2][0],f[2][1],f[2][2]);
	 glEnd();
	 glFlush();
	 
}

void idle(void)
{
	th=1;
	//if(360<th)
	//th=th-360;
	//printf("%d  %d  %d  \n",x,y,z);
	glRotatef(th,axis[0],axis[1],axis[2]);
	glutPostRedisplay();
}

void keypress(unsigned char key, int a,int b)
{
	switch(key)
	{
		case 'x':
				axis[0]=1;
				axis[1]=0;
				axis[2]=0;
				break;
		case 'y':
				axis[0]=0;
				axis[1]=1;
				axis[2]=0;
				break;
		case 'z':
				axis[0]=0;
				axis[1]=0;
				axis[2]=1;
				break;
	}
}

void mouse(int btn,int state,int x,int y)
{ 
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		glutIdleFunc(idle);
	}
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		glutIdleFunc(NULL);
	}
}


void display()
{	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	x=y=0;
	z=1;
	draw();
	glFlush();
	glutSwapBuffers();
} 



int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Drawing");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keypress);
	glutMainLoop();
}

