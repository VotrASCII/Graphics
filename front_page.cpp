#include <stdlib.h>
#include <GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int f=0;
void *currentfont;
void keyboard(int, int, int);
void nextpage();

void setFont(void *font)
{
        currentfont = font;
}

void drawstring(float x, float y, float z, char *string)
{
         char *c;
         glRasterPos3f(x,y,z);
         for(c = string; *c != '\0'; c++)
         {
                glutBitmapCharacter(currentfont, *c);
         }

}

void text()
{       
        glClear(GL_COLOR_BUFFER_BIT);
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(1, 0.5, 0);
        drawstring(-85.0, 90, 1.0,"******* * * * * * * * * * TITLE * * * * * * * * * *********");
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.0, 0.0, 1.0);
        drawstring(-55.0, 75, 1.0,"PESIT BANGLORE SOUTH CAMPUS");
        glColor3f(0.0, 1.0, 1.0);
        drawstring(-100, 60, 1.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
        glColor3f(0.863, 0.078, 0.235);
        drawstring(-90.0, 36, 1.0,"A MINI PROJECT ON   \"SODIUM/POTASSIUM\"    PUMP");
        glColor3f(1, 0.84, 0.0);
        setFont(GLUT_BITMAP_9_BY_15);
        drawstring(-120.0, 10, 1.0,"BY:...");
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.502, 0.000, 0.502);
        drawstring(-120.0, 0.0, 1.0,"1. GUNJAN DWIVEDI                                                                   1PE14CS044");
        glColor3f(0.502, 0.000, 0.502);
        drawstring(-120.0, -10.0, 1.0,"2. MAYANK PRAKASH                                                                1PE14CS070");
        setFont(GLUT_BITMAP_9_BY_15);
        glColor3f(0.95, 0.15, 0.0);
        drawstring(-120.0, -40.0, 1.0,"UNDER THE GUIDANCE OF");
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.502, 0.502, 0.000);
        drawstring(-120.0, -50.0, 1.0,"1. Ms. SHUBHA RAJ");
        glColor3f(0.502, 0.502, 0.000);
        drawstring(-120.0, -60.0, 1.0,"2. Dr. SARASVATHI");
        glColor3f(0.196, 0.804, 0.196);
        drawstring(-30.0, -80.0, 1.0,"RIGHT CLICK TO START");
        glutSwapBuffers();
        glutPostRedisplay();
}

/*void mydisplay()
{
        glClear(GL_COLOR_BUFFER_BIT);
        if(f==0)
                text();
        else if(f==1)
                nextpage();
}*/

void NormalKey(GLubyte key, GLint x, GLint y)
{
        if(f==0)
        {
                switch ( key )
                {
                        case 13:
                                f = 1;
                                nextpage();
                                break;
//                        default: text();
                }
        }
}

void nextpage()
{
        glClearColor(1.0, 1.0, 1.0, 1.0);
         glClear(GL_COLOR_BUFFER_BIT );
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
         glColor3f(0.0, 0.0, 0.0);
         drawstring(100.0, 455.0, 1.0,"COMING SOON");
         glFlush();
}

void init()
{
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glColor3f(1.0, 0.0, 0.0);
        gluOrtho2D(0.0, 639.0, 0.0, 479.0);
}

int main(int argc, char **argv)
 {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
        glutInitWindowSize(640, 480);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("Na+/K+ pump");
        init();
        glutDisplayFunc(text);
        glutKeyboardFunc(NormalKey);
        glutMainLoop();
        return 0;
}
