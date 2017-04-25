#include <iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

static bool paused = false;

/*void *currentfont;
int f = 0;
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
                glColor3f(0.0, 0.0, 0.0);
                glutBitmapCharacter(currentfont, *c);
         }
}
 void first_page()
{
        //glClear(GL_COLOR_BUFFER_BIT);
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.529, 0.808, 0.922);
        drawstring(100.0, 455.0, 1.0,"******* * * * * * * * * * INTRODUCTION * * * * * * * * * *********");
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.0, 0.0, 1.0);
        drawstring(160.0, 430.0, 1.0,"PESIT BANGLORE SOUTH CAMPUS");
        glColor3f(0.0, 0.0, 1.0);
        drawstring(100.0, 400.0, 1.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
        glColor3f(0.863, 0.078, 0.235);
        drawstring(130.0, 360.0, 1.0,"A MINI PROJECT ON SODIUM/POTASSIUM PUMP");
        glColor3f(1.000, 0.843, 0.000);
        drawstring(120.0, 330.0, 1.0,"");
        glColor3f(0.678, 1.000, 0.184);
        setFont(GLUT_BITMAP_9_BY_15);
        drawstring(120.0, 250.0, 1.0,"BY");
        glColor3f(1.000, 0.843, 0.000);
        drawstring(120.0, 330.0, 1.0,"");
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.502, 0.000, 0.502);
        drawstring(120.0, 230.0, 1.0,"1. GUNJAN DWIVEDI                                1PE14CS044");
        glColor3f(0.502, 0.000, 0.502);
        drawstring(120.0, 210.0, 1.0,"2. MAYANK PRAKASH                             1PE14CS070");
        glColor3f(0.95, 0.15, 0.0);
        drawstring(120.0, 150.0, 1.0,"UNDER THE GUIDANCE OF");
        glColor3f(0.502, 0.502, 0.000);
        drawstring(120.0, 130.0, 1.0,"1. Ms. Shubha Raj");
        glColor3f(0.502, 0.502, 0.000);
        drawstring(120.0, 110.0, 1.0,"2. Dr. Sarasvathi");
        glColor3f(0.196, 0.804, 0.196);
        drawstring(200.0, 50.0, 1.0,"PRESS ENTER TO START");
        //glFlush();
} */

float cmxl = 0, cmxu = 0; // cell membrane selective opening
void cell_membrane(void)
{
        glColor3f(0, 1, 0);
        glBegin(GL_QUADS); // Draw a filled rectangle with current color
                glVertex2d(-85, 20);
                glVertex2d(-100, 20);
                glVertex2d(-100, -30);
                glVertex2d(-85, -30);
        glEnd();
        glBegin(GL_QUADS);
                glVertex2d(-55, 20);
                glVertex2d(-40, 20);
                glVertex2d(-40, -30);
                glVertex2d(-55, -30);
        glEnd();
        //glPushMatrix();
        //movable parts
        if (cmxu <= 30 && !paused)
        {
                glPushMatrix();
                glTranslatef(cmxu  , 0, 0);
                glColor3f(1, 0.15, 0);
                glBegin(GL_QUADS);
                        glVertex2d(-85, 20);
                        glVertex2d(-55, 20);
                        glVertex2d(-55, 22);
                        glVertex2d(-85, 22);
                glEnd();
                cmxu += 0.01;
                glPopMatrix();
        }
        if(cmxl >= -30 && !paused)
        {
                glPushMatrix();
                glTranslated(cmxl, 0, 0);
                glBegin(GL_QUADS);
                        glVertex2d(-55, -30);
                        glVertex2d(-85, -30);
                        glVertex2d(-85, -32);
                        glVertex2d(-55, -32);
                glEnd();
                cmxl -= 0.01;
                glPopMatrix();
        }
        //glPopMatrix();
}

float cpxl = 0, cpxu = 0; // active transport initiation for glucose transportation when potential builds up
void channel_protein(void)
{
        glColor3f(0, 1, 1);
        glBegin(GL_QUADS); // Draw a filled rectangle with current color
                glVertex2d(30, 20);
                glVertex2d(45, 20);
                glVertex2d(45, -30);
                glVertex2d(30, -30);
        glEnd();
        glBegin(GL_QUADS);
                glVertex2d(75, 20);
                glVertex2d(90, 20);
                glVertex2d(90, -30);
                glVertex2d(75, -30);
        glEnd();

        //movable parts
        if (cpxl >= -30 && cpxu <= 30 && !paused)
        {
                glPushMatrix();
                glTranslatef(cpxu  , 0, 0);
                glColor3f(0.25, 0.15, 0.75);
                glBegin(GL_QUADS);
                        glVertex2d(45, 20);
                        glVertex2d(75, 20);
                        glVertex2d(75, 22);
                        glVertex2d(45, 22);
                glEnd();
                cpxu += 0.005;
                glPopMatrix();

                glPushMatrix();
                glTranslated(cpxl, 0, 0);
                glBegin(GL_QUADS);
                        glVertex2d(75, -30);
                        glVertex2d(45, -30);
                        glVertex2d(45, -32);
                        glVertex2d(75, -32);
                glEnd();
                cpxl -= 0.005;
                glPopMatrix();
        }
}

void cells(void)
{
        int j = 0, k = 0;
        //right lower portion
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS);
                        glVertex2d(-35 + k, -30);
                        glVertex2d(-40 + k, -30);
                        glVertex2d(-40 + k, -25);
                        glVertex2d(-35 + k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(-35 + k, -30);
                        glVertex2d(-30 + k, -30);
                        glVertex2d(-30 + k, -25);
                        glVertex2d(-35 + k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        //lower middle portion
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS);
                        glVertex2d(-35 + k, -30);
                        glVertex2d(-40 + k, -30);
                        glVertex2d(-40 + k, -25);
                        glVertex2d(-35 + k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(-35 + k, -30);
                        glVertex2d(-30 + k, -30);
                        glVertex2d(-30 + k, -25);
                        glVertex2d(-35 + k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        //left lower portions
        j = 0;
        k = 0;
        for(int i = 1; i <= 9; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS); // Draw a filled rectangle with current color
                        glVertex2d(-105 - k, -30);
                        glVertex2d(-100 - k, -30);
                        glVertex2d(-100 - k, -25);
                        glVertex2d(-105 - k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 8; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(-105 - k, -30);
                        glVertex2d(-110 - k, -30);
                        glVertex2d(-110 - k, -25);
                        glVertex2d(-105 - k, -25);
                glEnd();
                j += 0.07;
                k += 10;
        }
}

void display(void)
{
        glClear(GL_COLOR_BUFFER_BIT ); //clear the window with current clearing color, i.e. removes the last drawing from the window
//     first_page();
        cell_membrane();
        cells();
        // sodium();
        //potassium();
        //ATP();
        //glucose();
        channel_protein();
        glFlush(); //causes any un-executed commands to be executed
        glutPostRedisplay(); // iteration over rendering
}

void reshape(GLsizei w, GLsizei h)
{
        GLfloat aspectRatio;
        if(h == 0)  // Prevent a divide by zero
        {
                h = 1;
        }
        glViewport(0, 0, w, h); // Set Viewport to window dimensions
        // Reset coordinate system
        glMatrixMode(GL_PROJECTION); // actual view volume defined here
        glLoadIdentity(); // required as "glOrtho(x1, x2, y1, y2, z1, z2)" modifies the existing clipping volume and doesn't establish the clipping volume
        // Establish clipping volume (left, right, bottom, top, near, far)
        aspectRatio = (GLfloat)w / (GLfloat)h;
        // maintaining the square window
        if (w <= h) // vertical modification
        {
                glOrtho (-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
        }
        else // horizontal modification
        {
                glOrtho (-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
        }
        // all the updates are to be registered on the model
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void handleKeypress(unsigned char key, int x, int y)
 {
         //text();
        switch (key)
        {
                //case 13:
                case 27:        exit(0); //Escape key
                case 'p':       paused = !paused;
                                         break;
        }
        //glutPostRedisplay();
}

/*void init()
{
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glColor3f(1.0, 0.0, 0.0);
        gluOrtho2D(0.0, 639.0, 0.0, 479.0);
}*/

int main(int argc, char **argv)
{
        glutInit(&argc, argv); //to pass command line arguments and initialize GLUT library
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA); /*type of display mode : DOUBLE buffered, i.e. drawing commands executed off-screen
                                                                                                                        *and swapped into view of the window, for ANIMATION
                                                                                                                        *SINGLE buffered, i.e. drawing commands are performed on the window displayed
                                                                                                                        *RGBA, i.e. specify colors with separate intensities */
        glutInitWindowSize(640, 480);
        glutInitWindowPosition(0,0);
//        init();
        glutCreateWindow("K+/Na+ pump"); // creates window on the screen
        glClearColor(1,1,1,1); //initialization before rendering
        glutDisplayFunc(display); //called whenever window needs to be drawn
        glutKeyboardFunc(handleKeypress);
        glutReshapeFunc(reshape);
        glutMainLoop();
        return 0;
}
