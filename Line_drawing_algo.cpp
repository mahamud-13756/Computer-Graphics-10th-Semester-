#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

int x1, x2, y1, y2, dx, pk, step, dy, i;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 8, 0.0, 8, -1.0, 1.0);

}

void Draw()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);

    dy = (y2 - y1);
    dx = (x2 - x1);
    pk = (2 * dy) - dx;
    int x = x1, y = y1;



    glBegin(GL_POINTS);
    glVertex2i(x, y);

    if (dx > dy)
    {
        step = dx;
    }
    else {
        step = dy;
        for (i = 0; i < step; i++) {
            if (pk < 0) {
                x = x + 1;
                y = y;
                glVertex2i(x, y);
                pk = (pk + (2 * dy));
            }
            else {
                x = x + 1;
                y = y + 1;
                glVertex2i(x, y);
                pk = pk + (2 * dy) - (2 * dx);
            }
        }
    }
    glEnd();


    glutSwapBuffers();
}




int main(int argc, char** argv) {



    printf("Enter X1 value: ");
    scanf("%d", x1);
    printf("Enter Y1 value: ");
    scanf("%d", y1);

    printf("Enter X2 value: ");
    scanf("%d", x2);
    printf("Enter Y2 value: ");
    scanf("%d", y2);


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