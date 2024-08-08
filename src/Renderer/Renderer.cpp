#include "Renderer.h"
#include <GL/glew.h>
#include <iostream>

void Renderer::initOpenGL()
{
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        std::cerr << "Error initializing GLEW:" << glewGetErrorString(err) << std::endl;
        exit(1);
    }

    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800.0, 600.0, 0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Renderer::render(const std::vector<Point>& points)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);

    for (const auto& point : points)
    {
        glVertex2f(point.x, point.y);
    }
    glEnd();
}