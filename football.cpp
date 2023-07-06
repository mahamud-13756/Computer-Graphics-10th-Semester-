#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float  cx, cy, rx, ry, i;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15.0, 15.0, 15.0, -15.0, -1.0, 1.0);

}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    glColor3f(255, 255, 255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * (i / 100);
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f(x, y);

    }
    glEnd();


    // glBegin(GL_POLYGON);
    // glColor3f(0.0, 0.0, 0.0);
    // glVertex2f(0.520f, 1.193f);
    // glVertex2f(1.190f, 0.191f);
    // glVertex2f(0.805f, -1.830f);
    // glVertex2f(-1.624f, -1.166f);
    // glVertex2f(-1.662f, 1.111f);

    // glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-5.0f, 0.0f);
    glVertex2f(-2.5f, 4.33f);
    glVertex2f(2.5f, 4.33f);
    glVertex2f(5.0f, 0.0f);
    glVertex2f(0.0f, -4.33f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 0);
    glVertex2f(9, 15);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 0);
    glVertex2f(-9, 15);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 0);
    glVertex2f(-30, 0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 0);
    glVertex2f(0, -15);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 0);
    glVertex2f(30, 0);
    glEnd();


    //
    // glBegin(GL_TRIANGLES);
    // glColor3f(0.0f, 0.0f, 0.0f);
    // glVertex2f(13.0f, 17.0f);
    // glVertex2f(13.0f, -2.0f);
    // glVertex2f(-2.0f, 2.0f);
    // glEnd();




}

void Draw()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255, 255, 255);
    circle(10, 10, 0, 0);


    glutSwapBuffers();
}




int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Drawing Algo");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}