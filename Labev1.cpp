#include <windows.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <GL/gl.h> 
#include <math.h>
float p = 100;
float  cx, cy, rx, ry, i;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers 
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack 
    glLoadIdentity();
    glOrtho(-20.0, 100.0, -20.0, 100.0, -20.0, 100.0);
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1 
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


void DrawHill()
{



    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);
    circle(10, 10, 0, 0);






    glColor3f(0, 100, 0);
    glBegin(GL_POLYGON);

    glVertex2i(5, 0);
    glVertex2i(15, 20);
    glVertex2i(25, 0);

    glEnd();

    glBegin(GL_POLYGON);


    glVertex2i(25, 0);
    glVertex2i(30, 10);
    glVertex2i(35, 0);

    glEnd();




    glBegin(GL_POLYGON);


    glVertex2i(35, 0);
    glVertex2i(40, 15);
    glVertex2i(45, 0);

    glEnd();

    glBegin(GL_POLYGON);


    glVertex2i(45, 0);
    glVertex2i(55, 25);
    glVertex2i(65, 0);

    glEnd();

    glColor3f(0, 257, 127);
    glBegin(GL_QUADS);
    glVertex2i(-20, 0);
    glVertex2i(-20, -20);
    glVertex2i(100, -20);
    glVertex2i(100, 0);
    glEnd();






    if (p <= 10)
    {
        p = p + 0.005;
    }
    else
    {
        p = -10;
    }
    glutPostRedisplay();
    glColor3f(0, 257, 127);
    glBegin(GL_QUADS);
    glVertex2i(-3, p);
    glVertex2i(-3, p + 3);
    glVertex2i(3, p + 3);
    glVertex2i(3, p);
    glEnd();







    // Write your Code 


    glutSwapBuffers();


}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (p <= 100)
    {
        p = p + 0.004;
    }
    else
    {
        p = -20;
    }
    glutPostRedisplay();


    glColor3f(0, 1, 3);
    glBegin(GL_QUADS);

    glVertex2i(40, p - 80);
    glVertex2i(60, p - 80);
    glVertex2i(40, p - 40);
    glVertex2i(60, p - 40);
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

    glutDisplayFunc(DrawHill);

    glutMainLoop();
    return 0;
}