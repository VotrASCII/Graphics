#include <iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

static bool paused = false;
int obj, k;

#define title 0
#define initial 1
#define action 2
#define quit 3

//adding menu
void menu_select(int item)
{
        obj = item;
        glutPostRedisplay();
}

void *currentfont;
int f = 0;
void setFont(void *font)
{
        currentfont = font;
}

//BitMap strings
void drawstring(float x, float y, float z, char *string)
{
         char *c;
         glRasterPos3f(x,y,z);
         for(c = string; *c != '\0'; c++)
         {
                //glColor3f(0.0, 0.0, 0.0);
                glutBitmapCharacter(currentfont, *c);
         }
}

//Stroke Strings for they behave as objects
void draw_stroke_string(char *string)
{
         char *c;
         for(c = string; *c != '\0'; c++)
         {
                glutStrokeCharacter(currentfont, *c);
         }
}

void first_page()
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
        drawstring(-120.0, -40.0, 1.0,"UNDER THE GUIDANCE OF:...");
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(0.502, 0.502, 0.000);
        drawstring(-120.0, -50.0, 1.0,"1. Ms. SHUBHA RAJ");
        glColor3f(0.502, 0.502, 0.000);
        drawstring(-120.0, -60.0, 1.0,"2. Dr. SARASVATHI");
        glColor3f(0.196, 0.804, 0.196);
        drawstring(-30.0, -80.0, 1.0,"RIGHT CLICK TO SELECT");
        glutSwapBuffers();
        glutPostRedisplay();
}

float cmlxn = 0, cmlxp = 0,  cmuxn = 0, cmuxp = 0; // cell membrane selective opening
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

        //movable parts
        glPushMatrix();
        glColor3f(1, 0.15, 0);
        if(cmlxn >= -30 && !paused) //lower; synced with concentration gradient
        {
                if(cmlxn >= -14)
                {
                        cmlxn -= 0.02;
                }
                else
                {
                        cmlxn -= 0.00268;
                }
                glTranslated(cmlxn, 0, 0);
                cmlxp = cmlxn;
        }
        else if (cmlxp <= 0 && !paused)
        {
                if (cmlxp <= -29)
                {
                        cmlxp += 0.002;
                }
                else
                {
                        cmlxp += 0.02;
                }
                glTranslated(cmlxp, 0, 0);
        }
        glBegin(GL_QUADS);
                glVertex2d(-55, -30);
                glVertex2d(-85, -30);
                glVertex2d(-85, -32);
                glVertex2d(-55, -32);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        if (cmuxp <= 30 && !paused) //upper synced with concentration gradient
        {
                if (cmuxp <= 25 && !paused)
                {
                        cmuxp += 0.02;
                }
                else
                {
                        cmuxp += 0.002;
                }
                glTranslatef(cmuxp  , 0, 0);
                cmuxn = cmuxp;
        }
        else if (cmuxn >= 0 && !paused)
        {
                cmuxn -= 0.008;
                glTranslatef(cmuxn  , 0, 0);
        }
        glBegin(GL_QUADS);
                glVertex2d(-85, 20);
                glVertex2d(-55, 20);
                glVertex2d(-55, 22);
                glVertex2d(-85, 22);
        glEnd();
        glPopMatrix();
        glColor3f(0, 0, 0);
        glPushMatrix();
        glTranslatef(-45, -28, 0);
        glScalef(0.03, 0.05, 0);
        glRotatef(90, 0, 0, 1);
        setFont(GLUT_STROKE_ROMAN);
        draw_stroke_string("Cell Membrane");
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-90, -28, 0);
        glScalef(0.03, 0.05, 0);
        glRotatef(90, 0, 0, 1);
        draw_stroke_string("Cell Membrane");
        glPopMatrix();
}

void cells(void) //total static
{
        int j = 0;
        k = 0;
        //right upper portion
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS);
                        glVertex2d(90 + k, 20);
                        glVertex2d(95 + k, 20);
                        glVertex2d(95 + k, 15);
                        glVertex2d(90 + k, 15);
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
                        glVertex2d(95 + k, 20);
                        glVertex2d(100 + k, 20);
                        glVertex2d(100 + k, 15);
                        glVertex2d(95 + k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        //upper middle portion
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS);
                        glVertex2d(-35 + k, 20);
                        glVertex2d(-40 + k, 20);
                        glVertex2d(-40 + k, 15);
                        glVertex2d(-35 + k, 15);
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
                        glVertex2d(-35 + k, 20);
                        glVertex2d(-30 + k, 20);
                        glVertex2d(-30 + k, 15);
                        glVertex2d(-35 + k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        //left upper portions
        j = 0;
        k = 0;
        for(int i = 1; i <= 9; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS); // Draw a filled rectangle with current color
                        glVertex2d(-105 - k, 20);
                        glVertex2d(-100 - k, 20);
                        glVertex2d(-100 - k, 15);
                        glVertex2d(-105 - k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        j = 0;
        k = 0;
        for(int i = 1; i <= 9; i += 1)
        {
                glColor3f(0, 1.0, 0.5);
                glBegin(GL_QUADS);
                        glVertex2d(-105 - k, 20);
                        glVertex2d(-110 - k, 20);
                        glVertex2d(-110 - k, 15);
                        glVertex2d(-105 - k, 15);
                glEnd();
                j += 0.07;
                k += 10;
        }
        glColor3f(1, 1, 1);
        setFont(GLUT_BITMAP_HELVETICA_12);
        drawstring(-185, 25, 0, "Outer Region");
        drawstring(-185, -12.5, 0, "DIFFUSION");
        drawstring(-15, -12.5, 0, "DIFFUSION");
        drawstring(105, -12.5, 0, "DIFFUSION");
        //right lower portion
        j = 0;
        k = 0;
        for(int i = 1; i <= 7; i += 1)
        {
                glColor3f(0, 0.8, 0.7);
                glBegin(GL_QUADS);
                        glVertex2d(90 + k, -30);
                        glVertex2d(95 + k, -30);
                        glVertex2d(95 + k, -25);
                        glVertex2d(90 + k, -25);
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
                        glVertex2d(95 + k, -30);
                        glVertex2d(100 + k, -30);
                        glVertex2d(100 + k, -25);
                        glVertex2d(95 + k, -25);
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
        for(int i = 1; i <= 9; i += 1)
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
        glColor3f(1, 1, 1);
        setFont(GLUT_BITMAP_HELVETICA_12);
        drawstring(-185, -40, 0, "Inner Region");
        glColor3f(0, 0, 0);
        drawstring(-185, -29.5, 0, "CELLS");
        drawstring(-185, 16, 0, "CELLS");
        drawstring(-5, -29.5, 0, "CELLS");
        drawstring(-5, 16, 0, "CELLS");
        drawstring(115, -29.5, 0, "CELLS");
        drawstring(115, 16, 0, "CELLS");
}

float indpy = 0, indny = 0, x = 0;
void concentration_indicator(void)
{
        int l = 0;
        k = 0;
        for(int i=1; i <= 20; i += 1)
        {
                glColor3ub(230 - k, 0 + k, 0); // transparency indicating increase in electronic gradient potential
                glBegin(GL_QUADS);
                        glVertex2f(180, -45+l);
                        glVertex2f(183, -45+l);
                        glVertex2f(183, -50+l);
                        glVertex2f(180, -50+l);
                glEnd();
                l += 5;
                k += 10;
        }

        // indicator position
        glPushMatrix();
        if (indpy < 100 && !paused) /*when electrochemical potential builds up, the energy is invested in opening up of channel protein and transportation
                                                        of glucose*/
        {
                indpy += 0.013;//for syncing with channel protein gateway
                glTranslated(0, indpy, 0);
                indny = indpy;
        }
        else if (indny > 0 && !paused) /*added because when the transportation happens the built up energy is invested resulting in
                                                        decrease in built up potential which eventually results in closing of channel protein*/
        {
                indny -= 0.01305; //Why higher than "indpy"?? Because energy is consumed in opening channels and transportation
                glTranslated(0, indny, 0);
        }
        x = indpy;
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
                glVertex2d(179, -50);
                glVertex2d(177, -48);
                glVertex2d(177, -52);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glColor3f(1, 0.5, 0);
        glTranslatef(185, 35, 0);
        glScalef(0.05, 0.05, 0);
        glRotatef(-90, 0, 0, 1);
        setFont(GLUT_STROKE_ROMAN);
        draw_stroke_string("Concentration Gradient");
        glPopMatrix();
}

float nailx = 0, nairx = 0;
void sodium_in(void)
{
        k = 0;
        glPushMatrix();
        if (nairx <= 20 && !paused)
        {
                nairx += 0.0053;
                glTranslatef(nairx, 0, 0);
                nailx = nairx;
        }
        else if (nailx > 0 && !paused)
        {
                nailx -= 0.0053;
                glTranslatef(nailx, 0, 0);
        }
        for(int i = 1; i <= 6; i += 1)
        {
                glPushMatrix();
                glColor3f(0.5, 0.75, 0);
                if (i <= 3)
                {
                        glBegin(GL_POLYGON);
                                glVertex2d(-30 + k -10, -45);
                                glVertex2d(-35 + k -10, -50);
                                glVertex2d(-30 + k -10, -55);
                                glVertex2d(-25 + k -10, -50);
                        glEnd();
                        glTranslatef(-33 + k -10, -51.5, 0);
                }
                else
                {
                        glBegin(GL_POLYGON);
                                glVertex2d(-30 + k, -45);
                                glVertex2d(-35 + k, -50);
                                glVertex2d(-30 + k, -55);
                                glVertex2d(-25 + k, -50);
                        glEnd();
                        glTranslatef(-33 + k, -51.5, 0);
                }
                glColor3f(0, 0, 0.5);
                glScalef(0.03, 0.025, 0);
                setFont(GLUT_STROKE_ROMAN);
                draw_stroke_string("Na+");
                glPopMatrix();
                k += 12;
        }
        glPopMatrix();
}

float nalx = 0, narx = 0, nay = 0;
void sodium_in_out(void)
{
        glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glTranslatef(-60, 113, 0);
        if (cmlxn <= -14 && !paused)
        {
                if (nay <= 110 && !paused)
                {
                        nay += 0.035;
                }
        }
        glTranslatef(nay, 0, 0);
        k = 0;
        for(int i = 1; i <= 3; i += 1)
        {
                glPushMatrix();
                glColor3f(0.5, 0.75, 0.5);
                glBegin(GL_POLYGON);
                        glVertex2d(-10 + k, -45);
                        glVertex2d(-15 + k, -50);
                        glVertex2d(-10 + k, -55);
                        glVertex2d(-5 + k, -50);
                glEnd();
                glTranslatef(-11.5 + k, -47, 0);
                glColor3f(0, 0, 0.5);
                glRotatef(-90, 0, 0, 1);
                glScalef(0.03, 0.025, 0);
                setFont(GLUT_STROKE_ROMAN);
                draw_stroke_string("Na+");
                glPopMatrix();
                k += 12;
        }
        glPopMatrix();
}

float atplx = 0, atprx = 0;
void ATP(void)
{
        k = 0;
        glPushMatrix();
        if (atplx >= -20 && !paused)
        {
                atplx -= 0.0053;
                glTranslatef(atplx, 0, 0);
                atprx = atplx;
        }
        else if(atprx <= 0 && !paused)
        {
                atprx += 0.0053;
                glTranslatef(atprx, 0, 0);
        }
        for(int i = 1; i <= 3; i += 1)
        {
                glPushMatrix();
                glColor3f(0, 1, 1);
                glBegin(GL_POLYGON);
                        glVertex2d(-20 + k, -90);
                        glVertex2d(-10 + k, -90);
                        glVertex2d(-15 + k, -80);
                glEnd();
                glColor3f(1, 1, 0);
                glBegin(GL_POLYGON);
                        glVertex2d(-20 + k, -90);
                        glVertex2d(-23 + k, -95);
                        glVertex2d(-17 + k, -95);
                glEnd();
                glBegin(GL_POLYGON);
                        glVertex2d(-10 + k, -90);
                        glVertex2d(-13 + k, -95);
                        glVertex2d(-7 + k, -95);
                glEnd();
                glBegin(GL_POLYGON);
                        glVertex2d(-20 + k, -90);
                        glVertex2d(-23 + k, -95);
                        glVertex2d(-17 + k, -95);
                glEnd();
                glBegin(GL_POLYGON);
                        glVertex2d(-15 + k, -80);
                        glVertex2d(-12 + k, -75);
                        glVertex2d(-18 + k, -75);
                glEnd();
                glColor3f(1, 0, 0);
                glTranslatef(-21 + k, -87, 0);
                glScalef(0.05, 0.03, 0);
                setFont(GLUT_STROKE_ROMAN);
                draw_stroke_string("ATP");
                glPopMatrix();
                k += 20;
        }
        glPopMatrix();
}

float kolx = 0, korx = 0;
void potassium_out(void)
{
        k = 0;
        glPushMatrix();
        if (korx <= 20 && !paused)
        {
                korx += 0.0053;
                glTranslatef(korx, 0, 0);
                kolx = korx;
        }
        else if (kolx > 0 && !paused)
        {
                kolx -= 0.0053;
                glTranslatef(kolx, 0, 0);
        }
        for(int i = 1; i <= 4; i += 1)
        {
                glPushMatrix();
                glColor3f(0.8, 0.3, 0.5);
                if (i <= 2)
                {
                        glBegin(GL_POLYGON);
                                glVertex2d(-30 - 10 + k, 35);
                                glVertex2d(-37 - 10 + k, 42);
                                glVertex2d(-30 - 10 + k, 49);
                                glVertex2d(-23 - 10 + k, 42);
                        glEnd();
                        glTranslatef(-34 - 10 + k, 41, 0);
                }
                else
                {
                        glBegin(GL_POLYGON);
                                glVertex2d(-30 + k, 35);
                                glVertex2d(-37 + k, 42);
                                glVertex2d(-30 + k, 49);
                                glVertex2d(-23 + k, 42);
                        glEnd();
                        glTranslatef(-34 + k, 41, 0);
                }
                glColor3f(0, 0, 1);
                glScalef(0.05, 0.03, 0);
                setFont(GLUT_STROKE_ROMAN);
                draw_stroke_string("K+");
                glPopMatrix();
                k += 16;
        }
        glPopMatrix();
}

float klx = 0, krx = 0, ky = 0;
void potassium_out_in(void)
{
        glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glTranslatef(120, 35, 0);
        if (nay >= 110 && !paused)
        {
                if(ky >= -110 && !paused)
                {
                        ky -= 0.0285;
                }
        }
        glTranslatef(ky, 0, 0);
        k = 0;
        for(int i = 1; i <= 2; i += 1)
        {
                glPushMatrix();
                glColor3f(0.8, 0.4, 0);
                glBegin(GL_POLYGON);
                        glVertex2d(-70 -10 + k, 35);
                        glVertex2d(-77 -10 + k, 42);
                        glVertex2d(-70 -10 + k, 49);
                        glVertex2d(-63 -10 + k, 42);
                glEnd();
                glTranslatef(-72 + k - 10, 46, 0);
                glColor3f(0, 0, 1);
                glRotatef(-90, 0, 0, 1);
                glScalef(0.05, 0.03, 0);
                setFont(GLUT_STROKE_ROMAN);
                draw_stroke_string("K+");
                glPopMatrix();
                k += 16;
        }
        glPopMatrix();
}

float goxp = 0, goxn = 0;
void glucose_out(void)
{
        glPushMatrix();
        if(goxn >= -20 && !paused)
        {
                goxn -= 0.0053;
                glTranslatef(goxn, 0, 0);
                goxp = goxn;
        }
        else if(goxp <= 0 && !paused)
        {
                goxp += 0.0053;
                glTranslatef(goxp, 0, 0);
        }
        k = 0;
        for(int i = 1; i <= 3; i += 1)
        {
                glPushMatrix();
                glColor3f(0.5, 1, 0.4);
                glBegin(GL_POLYGON);
                        glVertex2f(-30 + k, 90);
                        glVertex2f(-35 + k, 85);
                        glVertex2f(-30 + k, 80);
                        glVertex2f(-25 + k, 80);
                        glVertex2f(-20 + k, 85);
                        glVertex2f(-25 + k, 90);
                glEnd();
                glColor3f(1, 0, 0);
                glTranslatef(-38 + k, 83.5, 0);
                glScalef(0.05, 0.03, 0);
                setFont(GLUT_STROKE_ROMAN);
                draw_stroke_string("Glucose");
                glPopMatrix();
                k += 30;
        }
        glPopMatrix();
}

float glulx = 0, glurx = 0, gluy = 0; //glucose movement 3 Right : 2 Left
void glucose_out_in(void)
{
        glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glTranslatef(190, -128, 0);
        if (x > 100 && !paused)
        {
                if(gluy >= -110 && !paused)
                {
                        gluy -= 0.02;
                }
                glTranslatef(gluy, 0, 0);
        }
        else
        {
                if(glulx >= -20 && !paused)
                {
                        glulx -= 0.0053;
                        glTranslatef(0, glulx, 0);
                        glurx = glulx;
                }
                else if(glurx <= 0 && !paused)
                {
                        glurx += 0.0053;
                        glTranslatef(0, glurx, 0);
                }
        }
        k = 0;
        for (int i = 1; i <= 2; i +=1)
        {
                glPushMatrix();
                glColor3f(1, 1, 0.2); //color difference just to show these clowns will be transported
                glBegin(GL_POLYGON);
                        glVertex2f(-143 + k, 75);
                        glVertex2f(-148 + k, 70);
                        glVertex2f(-148 + k, 65);
                        glVertex2f(-143 + k, 60);
                        glVertex2f(-138 + k, 65);
                        glVertex2f(-138 + k, 70);
                glEnd();
                glColor3f(1, 0, 0);
                glTranslatef(-145 + k, 75.5, 0);
                glScalef(0.05, 0.03, 0);
                glRotatef(-90, 0, 0, 1);
                setFont(GLUT_STROKE_ROMAN);
                draw_stroke_string("C6H12O6");
                glPopMatrix();
                k += 20;
        }
        glPopMatrix();
}

// active transport initiation for glucose transportation when potential builds up; i.e. channel protein opens-up
float cplxn = 0, cplxp = 0;
float cpuxp = 0, cpuxn = 0;
int c=0;
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
        glColor3f(0.25, 0.15, 0.75);
        glPushMatrix();

        //movable parts
        if (x > 100 && !paused)
        {
                if (cplxn >= -30 && !paused)
                {
                        cplxn -= 0.008;
                        glTranslatef(cplxn, 0, 0);
                        cplxp = cplxn;
                }
               else if (cplxp <= 0 && !paused)
                {
                        if (cplxp <= -24 && !paused)
                        {
                                cplxp += 0.002;
                        }
                        else
                        {
                                cplxp += 0.026;
                        }
                        glTranslatef(cplxp, 0, 0);
                }
        }
        glBegin(GL_QUADS);
                glVertex2d(75, -30);
                glVertex2d(45, -30);
                glVertex2d(45, -32);
                glVertex2d(75, -32);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        if (x > 100 && !paused)
        {
                if (cpuxp <= 30 && !paused)
                {
                        cpuxp += 0.024;
                        glTranslatef(cpuxp, 0, 0);
                        cpuxn = cpuxp;
                }
                else if (cpuxn >= 0 && !paused)
                {
                        if (cpuxn >= 20 && !paused)
                        {
                                cpuxn -= 0.002;
                        }
                        else
                        {
                                cpuxn -= 0.03;
                        }
                        glTranslatef(cpuxn, 0, 0);
                }
        }
        glBegin(GL_QUADS);
                glVertex2d(45, 20);
                glVertex2d(75, 20);
                glVertex2d(75, 22);
                glVertex2d(45, 22);
        glEnd();
        glPopMatrix();
        glColor3f(0, 0, 0);
        glPushMatrix();
        glTranslatef(40, -28, 0);
        glScalef(0.025, 0.045, 0);
        glRotatef(90, 0, 0, 1);
        setFont(GLUT_STROKE_ROMAN);
        draw_stroke_string("Channel Protein");
        glPopMatrix();
        glPushMatrix();
        glTranslatef(85, -28, 0);
        glScalef(0.025, 0.045, 0);
        glRotatef(90, 0, 0, 1);
        draw_stroke_string("Channel Protein");
        glPopMatrix();
}

void functionality(void)
{
        glClear(GL_COLOR_BUFFER_BIT );
        cell_membrane(); // DONE!!
        cells(); //DONE!!
        concentration_indicator(); //DONE!!
        sodium_in(); // DONE!!
        sodium_in_out(); // DONE!! synced with Concentration Indicator
        ATP(); // Please spare me!! :-P
        potassium_out(); // DONE!!
        potassium_out_in(); // DONE!! synced with Concentration Indicator
        glucose_out(); //DONE!!
        glucose_out_in(); //DONE!! behaving as it is supposed to
        channel_protein(); //DONE!!
//        glutSwapBuffers(); //for animation; glFlush() not required as it implicitly applies before rendering
//        glutPostRedisplay();// iteration over rendering to show the movable parts
}

void display(void)
{
        glClear(GL_COLOR_BUFFER_BIT );//clear the window with current clearing color, i.e. removes the last drawing from the window
        switch(obj)
        {
                case title:
                        first_page();
                        break;
                case initial:
                        paused = true;
                        functionality();
                        glutSwapBuffers();
                        break;
                case action:
                        paused = false;
                        functionality();
                        glutSwapBuffers(); //for animation; glFlush() not required as it implicitly applies before rendering
                        glutPostRedisplay();// iteration over rendering to show the movable parts
                        break;
                case quit:
                        exit(0);
                        break;
        }
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
        switch (key)
        {
                case 27:        exit(0); //Escape key
                case 'p':       paused = !paused;
                                         break;
        }
}

int main(int argc, char **argv)
{
        glutInit(&argc, argv); //to pass command line arguments and initialize GLUT library
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); /*type of display mode : DOUBLE buffered, i.e. drawing commands executed off-screen
                                                                                                                        *and swapped into view of the window, for ANIMATION
                                                                                                                        *SINGLE buffered, i.e. drawing commands are performed on the window displayed
                                                                                                                        *RGBA, i.e. specify colors with separate intensities */
        glutInitWindowSize(1000, 480);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Na+/K+ pump"); // creates window on the screen
        glClearColor(0, 0, 0 , 0); //initialization before rendering
        glutDisplayFunc(display); //called whenever window needs to be drawn
        glutCreateMenu(menu_select);
        glutAddMenuEntry("Title...", title);
        glutAddMenuEntry("Initial Configuration...", initial);
        glutAddMenuEntry("How It Happens??", action);
        glutAddMenuEntry("Quit!!", quit);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutKeyboardFunc(handleKeypress);
        glutReshapeFunc(reshape);
        glutMainLoop();
        return 0;
}
