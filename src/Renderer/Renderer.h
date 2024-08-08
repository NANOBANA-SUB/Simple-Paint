#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "Application/Application.h"

class Renderer
{
public:
    static void initOpenGL();
    static void render(const std::vector<Point>& points);
};

#endif