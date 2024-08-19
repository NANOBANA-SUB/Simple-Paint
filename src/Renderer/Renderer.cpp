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

    glViewport(0, 0, 1280, 720);
}

void Renderer::render(const std::vector<Point>& points)
{
    // バッファのクリア
        glClear(GL_COLOR_BUFFER_BIT);

        // 三角形の描画
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f); // 赤色
            glVertex2f(-0.5f, -0.5f); // 左下
            glColor3f(0.0f, 1.0f, 0.0f); // 緑色
            glVertex2f(0.5f, -0.5f);  // 右下
            glColor3f(0.0f, 0.0f, 1.0f); // 青色
            glVertex2f(0.0f, 1.0f);   // 上
        glEnd();
}

