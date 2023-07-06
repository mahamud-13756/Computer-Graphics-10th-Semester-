
#include <windows.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <GL/gl.h> 

float cloudX = -1.5f; // Initial x-position of the cloud

void drawHill()
{
    glColor3f(0.2, 0.6, 0.2); // Green color for hills
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0, -0.6);
    glVertex2f(0.0, 0.4);
    glVertex2f(1.0, -0.6);
    glEnd();
}

void drawSun()
{
    glColor3f(1.0, 1.0, 0.0); // Yellow color for sun
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0);
    for (int i = 0; i <= 360; ++i) {
        float angle = i * 3.14159 / 180.0;
        float x = 0.2 * sin(angle);
        float y = 0.2 * cos(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawCloud(float x, float y)
{
    glColor3f(1.0, 1.0, 1.0); // White color for clouds
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; ++i) {
        float angle = i * 3.14159 / 180.0;
        float cx = x + 0.1 * sin(angle);
        float cy = y + 0.05 * cos(angle);
        glVertex2f(cx, cy);
    }
    glEnd();
}

void display()
{
    glClearColor(0.7, 0.9, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawHill();
    drawSun();
    drawCloud(cloudX, 0.7);

    cloudX += 0.005f; // Move the cloud to the right

    glFlush();
}

int main()
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Animation", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        display();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}