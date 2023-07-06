#include <windows.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <GL/gl.h> 
float p = 10.0;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers 
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack 
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1 
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (p <= 10)
    {
        p = p + 0.005;
    }
    else
    {
        p = -10;
    }
    glutPostRedisplay();
    glColor3f(0, 1, 3);
    glBegin(GL_QUADS);
    glVertex2i(-3, p);
    glVertex2i(-3, p + 3);
    glVertex2i(3, p + 3);
    glVertex2i(3, p);
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