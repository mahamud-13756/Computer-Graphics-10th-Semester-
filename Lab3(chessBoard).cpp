#include <windows.h>
#include <GL/glut.h>


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 8, 0.0, 8, -1.0, 1.0);

}


void Draw()
{
    int x1 = 0, x2 = 1, x3 = 1, x4 = 0;
    int y1 = 0, y2 = 0, y3 = 1, y4 = 1;

    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0;i < 8;i += 2) {
        for (int j = 0; j < 8; j += 2) {
            glColor3f(1, 1, 1);
            glBegin(GL_POLYGON);
            glVertex2i(x1 + i, y1 + j);
            glVertex2i(x2 + i, y2 + j);
            glVertex2i(x3 + i, y3 + j);
            glVertex2i(x4 + i, y4 + j);
            glEnd();
        }
    }


    for (int i = 1;i < 8;i += 2) {
        for (int j = 1; j < 8; j += 2) {
            glColor3f(1, 1, 1);
            glBegin(GL_POLYGON);
            glVertex2i(x1 + i, y1 + j);
            glVertex2i(x2 + i, y2 + j);
            glVertex2i(x3 + i, y3 + j);
            glVertex2i(x4 + i, y4 + j);
            glEnd();
        }
    }

    // white

    // glColor3f(1, 1, 1);
    // glBegin(GL_POLYGON);
    // glVertex2i(x1 + i, 0);
    // glVertex2i(x2 + i, 0);
    // glVertex2i(x3 + i, 1);
    // glVertex2i(x4 + i, 1);
    // glEnd();


// // black
// glColor3f(1, 0, 0);
// glBegin(GL_POLYGON);
// glVertex2i(1, 0);
// glVertex2i(2, 0);
// glVertex2i(2, 1);
// glVertex2i(1, 1);
// glEnd();

// // white
// glColor3f(1, 1, 1);
// glBegin(GL_POLYGON);
// glVertex2i(2, 0);
// glVertex2i(3, 0);
// glVertex2i(3, 1);
// glVertex2i(2, 1);
// glEnd();




// Write your Code


    glutSwapBuffers();
}



int main(int argc, char** argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("chess Board");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}