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
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * (i / 100);
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f(x, y);

    }
    glEnd();


}

void Draw()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    circle(3, 3, 0, 0);


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