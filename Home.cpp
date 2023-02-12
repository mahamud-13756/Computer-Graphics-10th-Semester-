#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100, 0.0, 100, -1.0, 1.0);

}


void Draw()
{

    // home
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(25, 25);
    glVertex2i(50, 25);
    glVertex2i(50, 50);
    glVertex2i(25, 50);
    glEnd();

    glColor3f(2, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(20, 50);
    glVertex2i(55, 50);
    glVertex2i(37, 70);
    glEnd();
    glColor3f(2, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(33, 25);
    glVertex2i(41, 25);
    glVertex2i(41, 37);
    glVertex2i(33, 37);
    glEnd();
    glColor3f(2, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(40, 39);
    glVertex2i(47, 39);
    glVertex2i(47, 45);
    glVertex2i(40, 45);
    glEnd();


    // Write your Code


    glutSwapBuffers();
}

int main(int argc, char** argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}