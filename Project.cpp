#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<math.h>

GLfloat angle1 = 160.0;
GLfloat angle2 = 200.0;
GLfloat angle3 = 200.0;
float m = 0;
float mount = 0;
float mm = 500;
float flag = 0;
float flag2 = 500;
int F = 0;
float b2_speed = 5;
float ba_posion = 0;
int counter = 0;
float scale_cloud;
void sceenario(void);
void girl();
void hare_walking();
void cloud();
void circle(GLdouble rad);
void hare();
void hare_sleep();
#define PI 3.1416

// For Tortois
void drawLeftCircle()   // the filled one
{
    /**-----------Head------------**/
    glPushMatrix();
    glColor3f(0, .5, 0);
    glScalef(.5, .7, .5);
    glTranslatef(110 + 350, 245, 1);
    circle(20);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0, 0, 0);
    glScalef(.5, .7, .5);
    glTranslatef(110 + 350, 245, 1);
    circle(5);
    glPopMatrix();
    /**-----------Neck-----------**/
    glPushMatrix();
    glColor3f(0, .5, 0);
    glScalef(.5, .7, .5);
    glTranslatef(210 + 350, 180, 1);
    glRotatef(20, 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-70, 90, 1);
    glVertex3f(-70, 50, 1);
    glVertex3f(-50, 50, 1);
    glVertex3f(-50, 90, 1);
    glEnd();
    glPopMatrix();
    /**-----------Leg1-----------**/
    glPushMatrix();
    glColor3f(0, .7, 0);
    glScalef(.5, .7, .5);
    glTranslatef(230 + 350, 110, 1);

    glBegin(GL_POLYGON);
    glVertex3f(-80, 90, 1);
    glVertex3f(-85, 70, 1);
    glVertex3f(-45, 70, 1);
    glVertex3f(-50, 90, 1);
    glEnd();
    glPopMatrix();
    /**-----------LEg2-----------**/
    glPushMatrix();
    glColor3f(0, .7, 0);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 350, 110, 1);
    //glRotatef(20,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(-80, 90, 1);
    glVertex3f(-85, 70, 1);
    glVertex3f(-45, 70, 1);
    glVertex3f(-50, 90, 1);
    glEnd();
    glPopMatrix();
    /**-----------Body-----------------**/
    glPushMatrix();
    float radius = 70;
    float twoPI = 2 * PI;

    glColor3f(0, .5, 0);
    glScalef(.5, 0.7, .5);
    glTranslatef(200 + 350, 200, 1);
    //glTranslatef(550,150,1);
    glRotatef(-90, 0, 0, 1);
    glBegin(GL_TRIANGLE_FAN);

    for (float i = PI; i <= twoPI; i += 0.001)
        glVertex2f((sin(i) * radius), (cos(i) * radius));

    glEnd();
    glPopMatrix();

}








void myInit(void)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void sleeping_body2()
{
    glColor3f(0.0, 0.5, 0.1);
    glLineWidth(4.0);
    glPushMatrix();
    glScalef(.15, .15, .15);
    glTranslatef(200 - m * 6.68, 2050, 0);
    glRotatef(70, 0, 0, 1);

    glBegin(GL_LINE_LOOP);
    glVertex2i(40, 10);
    glVertex2i(0, 0);
    glVertex2i(-40, 10);
    glVertex2i(-40, 160);
    glVertex2i(-10, 180);
    glVertex2i(60, 180);
    glVertex2i(20, 100);
    glVertex2i(60, 60);
    glEnd();
    glPopMatrix();

    /**------------------------------Body Starts---------------------------**/

    //glViewport(1000,100,500,500);
    glColor3f(0.7, .2, 0);
    glPushMatrix();
    glScalef(.15, .15, .15);
    glTranslatef(120 - m * 6.68, 2400, 0);
    glRotatef(70 + 190, 0, 0, 1);

    //glTranslatef(1000, 500, 0);
    glBegin(GL_POLYGON);
    glVertex2i(400, 300);
    glVertex2i(310, 370);
    glVertex2i(280, 400);  //(x,y) First point
    glVertex2i(180, 400);
    glVertex2i(130, 370);
    glVertex2i(130, 340);
    glVertex2i(155, 330);
    glVertex2i(130, 310);
    glVertex2i(130, 290);
    glVertex2i(180, 270);
    glVertex2i(180, 150);
    glVertex2i(250, 150);
    glVertex2i(300, 80);
    glVertex2i(390, 80);
    glVertex2i(430, 120);
    glEnd();
    glPopMatrix();
    /**-------------------------------------Body Ends----------------------------**/



}



void sceenario()
{

    /**Road------------------**/
    glColor3f(.7, 0.7, 0.7);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 20);
    glVertex2i(700, 20);
    glVertex2i(700, 300);
    glVertex2i(0, 300);
    glEnd();
    glPopMatrix();

    /**--------grass2----------**/
    glColor3f(.5, 1, 0.5);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 20);
    glVertex2i(700, 20);
    glVertex2i(700, 0);
    glVertex2i(0, 0);
    glEnd();
    glPopMatrix();



    /**-------------tree---------------**/
    glColor3f(.1, 0.2, 0.1);
    glPushMatrix();
    glTranslatef(-m, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(72, 300);
    glVertex2i(78, 300);
    glVertex2i(78, 405);
    glVertex2i(72, 405);
    glEnd();

    glColor3f(.1, 0.5, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2i(75, 450);
    glVertex2i(100, 390);
    glVertex2i(50, 390);

    glVertex2i(75, 420);
    glVertex2i(100, 360);
    glVertex2i(50, 360);


    glVertex2i(75, 400);
    glVertex2i(100, 340);
    glVertex2i(50, 340);

    glEnd();
    glPopMatrix();



    /**-------------tree2---------------**/

    glPushMatrix();
    glTranslatef(-m, 0, 0);
    glColor3f(.1, 0.2, 0.1);
    glTranslatef(250, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(72, 300);
    glVertex2i(78, 300);
    glVertex2i(78, 405);
    glVertex2i(72, 405);
    glEnd();

    glColor3f(.1, 0.5, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(75, 450);
    glVertex2i(100, 390);
    glVertex2i(50, 390);

    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(75, 420);
    glVertex2i(100, 360);
    glVertex2i(50, 360);

    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(75, 400);
    glVertex2i(100, 340);
    glVertex2i(50, 340);

    glEnd();
    glPopMatrix();


    /**-------------tree3---------------**/
    glPushMatrix();
    glColor3f(.1, 0.2, 0.1);
    glTranslatef(150 - m, 150, 0);
    glScalef(.5, .5, .5);
    glBegin(GL_POLYGON);
    glVertex2i(72, 300);
    glVertex2i(78, 300);
    glVertex2i(78, 405);
    glVertex2i(72, 405);
    glEnd();

    glColor3f(.1, 0.5, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(75, 450);
    glVertex2i(100, 390);
    glVertex2i(50, 390);

    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(75, 420);
    glVertex2i(100, 360);
    glVertex2i(50, 360);

    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(75, 400);
    glVertex2i(100, 340);
    glVertex2i(50, 340);

    glEnd();


    glPopMatrix();
}

void mountain()
{
    /**----------Sky----**/

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(.8, .89, 1);
    glVertex2i(0, 350);

    glColor3f(.8, .89, 1);
    glVertex2i(700, 350);

    glColor3f(.2, .58, 1);
    glVertex2i(700, 500);

    glColor3f(.2, .58, 1);
    glVertex2i(0, 500);
    glEnd();
    glPopMatrix();

    /**----------Grass----**/
    glColor3f(.5, 1, 0.5);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 350);
    glVertex2i(700, 350);
    glVertex2i(700, 300);
    glVertex2i(0, 300);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    int k = 1, i;
    for (i = 0;i < 10;i++) {
        glTranslatef(+mount * k - 600 * i * .5, -10, 0);
        k = k * .05;
        cloud();
        glColor3f(.2, .8, .2);
        glBegin(GL_TRIANGLES);
        glVertex2i(0, 360);
        glVertex2i(50, 400);
        glVertex2i(100, 360);

        glVertex2i(80, 350);
        glVertex2i(200, 450);
        glVertex2i(300, 350);

        glVertex2i(280, 360);
        glVertex2i(360, 430);
        glVertex2i(450, 360);

        glVertex2i(480, 340);
        glVertex2i(560, 430);
        glVertex2i(640, 340);
        glEnd();
    }

    glPopMatrix();

}

void my_control_func()
{
    counter++;
    if (counter > 16800 || counter < 3800)
    {
        m = m;
        mm = mm;
        mount = mount;
        //hare();
    }
    else {
        mount += .2;
        if (flag > -800) {
            m -= .2;
            flag -= .2;
        }
        else {
            m = 350;
            flag = 700;

            F++;
        }
        if (flag2 > -1200)
        {
            mm -= .2;
            flag2 -= .2;
        }
        else
        {
            mm = 350;
            flag2 = 700;
        }
        if (F == 2)
        {
            b2_speed = 10;
        }
    }
}




void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mountain();
    sceenario();


    if (F == 0) {

        //body2();
        hare();
    }
    //body1();
    if (F == 1) {
        // sleeping_body2();

        hare_sleep();

    }
    drawLeftCircle();

    if (F == 2) {
        // body2();
        hare();

        ba_posion = 1500;
    }


    //hare();
    glFlush();
    glutPostRedisplay();
    my_control_func();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1350, 700);
    glutCreateWindow("Slow and Steady wins the race");

    //    glutIdleFunc( Walk );

    glutDisplayFunc(display);
    //glutDisplayFunc(hare_walking);
    myInit();
    glutMainLoop();
}




void cloud() {

    float scale_cloud = .3;
    int trns_x = -1000;
    int trns_y = 1150;

    glColor3f(0.8, .9, 1);


}

int i;
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for (i = 0; i <= 50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta), rad * sin(theta));
        }
    }
    glEnd();
}
void hare()
{
    /**-----------Head------------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(110 + 360 + 2 * m, 245 + 100, 1);
    circle(20);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glScalef(.5, .7, .5);
    glTranslatef(110 + 350 + 2 * m, 245 + 100, 1);
    circle(5);
    glPopMatrix();
    /**-----------Neck-----------**/

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(230 + 350 + 2 * m, 110 + 100, 1);

    glBegin(GL_POLYGON);
    glVertex3f(-80, 90, 1);
    glVertex3f(-85, 70, 1);
    glVertex3f(-45, 70, 1);
    glVertex3f(-50, 90, 1);
    glEnd();
    glPopMatrix();
    /**-----------LEg2-----------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 345 + 2 * m, 110 + 100, 1);
    //glRotatef(20,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(-80, 90, 1);
    glVertex3f(-85, 70, 1);
    glVertex3f(-45, 70, 1);
    glVertex3f(-50, 90, 1);
    glEnd();
    glPopMatrix();

    /**-----------Body-----------------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 200 + 2 * m, 120 + 200, 1);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 270 + 2 * m, 110 + 215, 1);
    circle(35);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 350 + 2 * m, 110 + 100, 1);

    glBegin(GL_POLYGON);
    glVertex3f(-80, 150, 1);
    glVertex3f(-85, 80, 1);
    glVertex3f(-145, 80, 1);
    glVertex3f(-150, 130, 1);
    glEnd();
    glPopMatrix();


    glVertex2i(-55, 110);
    glVertex2i(-25, 135);
    glVertex2i(-55, 90);
    glEnd();
    glPopMatrix();
}

void hare_sleep()
{
    /**-----------Head------------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .5, 1);
    glTranslatef(110 + 60 - 2 * m, 640, 1);
    circle(20);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glScalef(.5, .5, 1);
    glTranslatef(110 + 50 - 2 * m, 640, 1);
    circle(2);
    glPopMatrix();
    /**-----------Body-----------------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .5, 1);
    glTranslatef(200 - 2 * m, 620, 1);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .5, 1);
    glTranslatef(260 - 2 * m, 630, 1);
    circle(30);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1, 1, 1);
    //glScalef(.5,.5,1);

    glBegin(GL_POLYGON);
    glVertex3f(100 - m, 320, 1);
    glVertex3f(100 - m, 300, 1);
    glVertex3f(130 - m, 300, 1);
    glVertex3f(130 - m, 330, 1);
    glEnd();
    glPopMatrix();
    /**tail**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .5, 1);
    glTranslatef(340 - 2 * m, 220 + 300, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(-55, 110);
    glVertex2i(-30, 120);
    glVertex2i(-55, 90);
    glEnd();
    glPopMatrix();
    /**ear**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .5, 1);
    glTranslatef(235 - 2 * m, 400 + 145, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(-55, 110);
    glVertex2i(-25, 120);
    glVertex2i(-55, 90);

    glVertex2i(-55, 110);
    glVertex2i(-25, 135);
    glVertex2i(-55, 90);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-m, 0, 1);
    glPopMatrix();
}

// GOOD PROJECT