#include <windows.h>
#include <GL/glut.h>

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-6, 6, -6, 6, -6, 6);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(2.0f, 3.0f);
    glVertex2f(0.0f, 6.0f);
    glVertex2f(-2.0f, 3.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-3.0f, 3.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(3.0f, 3.0f);
    glVertex2f(0.0f, 5.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-2.0f, -3.0f);
    glVertex2f(-0.0f, -6.0f);
    glVertex2f(2.0f, -3.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(3.0f, -3.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(-3.0f, -3.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.5f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(3.0f, -2.0f);
    glVertex2f(6.0f, 0.0f);
    glVertex2f(3.0f, 2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.5f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(3.0f, -3.0f);
    glVertex2f(5.0f, 0.0f);
    glVertex2f(3.0f, 3.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-3.0f, 2.0f);
    glVertex2f(-6.0f, 0.0f);
    glVertex2f(-3.0f, -2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-3.0f, 3.0f);
    glVertex2f(-5.0f, 0.0f);
    glVertex2f(-3.0f, -3.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Simple Square");
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}