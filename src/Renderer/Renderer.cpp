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

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1280.0, 720.0, 0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Renderer::render(const std::vector<Point>& points)
{
    /*
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    glClear(GL_COLOR_BUFFER_BIT);
    checkOpenGLError();

    glColor3f(1.0f, 1.0f, 1.0f);
    //checkOpenGLError();

    glBegin(GL_LINE_STRIP);
    //checkOpenGLError();

    for (const auto& point : points)
    {
        glVertex2f(point.x, point.y);
        //checkOpenGLError();
    }
    glEnd();
    //checkOpenGLError();
    */
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2d(-0.9, -0.9);
    glVertex2d(0.9, -0.9);
    glVertex2d(0.9, 0.9);
    glVertex2d(-0.9, 0.9);
    glEnd();
    glFlush();
}

void Renderer::checkOpenGLError()
{
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        std::cerr << "OpenGL error: " << err << std::endl;
    }
}
