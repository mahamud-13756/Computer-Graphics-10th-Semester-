#include <iostream>
#include <GL/glut.h>// include GLUT library
#include <string>
//***********************************************************************************
float x, y;
std::string input;
float red = 1.0f, blue = 1.0f, green = 1.0f;
void drawPoints()
{

    //print text
    //glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glColor3f(red, blue, green);
    glRasterPos2i(x, y);
    for (std::size_t x = 0; x < input.size(); x++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, input[x]);
    }


    //axis labels
    glColor3f(0, 0, 0);
    glRasterPos2i(155, -5);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'X');
    glRasterPos2i(-5, 155);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Y');

    glPointSize(1);
    glBegin(GL_POINTS); // use points to form X-/Y-axes


    // change drawing color to black
    for (int x = -150; x <= 150; x++) // draw X-axis
        glVertex2i(x, 0);
    for (int y = -150; y <= 150; y++) // draw Y-axis
        glVertex2i(0, y);
    glEnd();




}
//***********************************************************************************
void mouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x = mousex - 400 / 2;
        y = -mousey + 400 / 2;
        red = 0.0;
        green = 0.0;
        blue = 1.0;

    }

    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)//undo(clear)the drawing
    {
        //x = mousex - 400 / 2;
        //y = -mousey + 400 / 2;
        red = 0.0;
        green = 1.0;
        blue = 0.0;
    }


    //glutPostRedisplay();
}
void keyPressed(unsigned char key, int x, int y) {

    std::getline(std::cin, input);
}
//***********************************************************************************
void myInit()
{
    glClearColor(1, 1, 1, 0);   // specify a background clor: white
    gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT); // draw the background

    drawPoints();

    glFlush(); // flush out the buffer contents
}

//***********************************************************************************
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                  // optional in our environment

    //std::cout << "Enter a string: ";


    glutInitWindowSize(400, 400);    // specify a window size
    glutInitWindowPosition(100, 0);   // specify a window position
    glutCreateWindow("Simple Point Drawing"); // create a titled window

    myInit();         // setting up

    glutDisplayFunc(myDisplayCallback);  // register a callback
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyPressed);
    glutMainLoop();       // get into an infinite loop

    return 0;
}