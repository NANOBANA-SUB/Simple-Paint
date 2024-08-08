#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include <vector>

struct Point
{
    float x;
    float y;
};

class Application
{
private:
    void handleEvents();
    void update();
    void render();

    SDL_Window* mWindow;
    SDL_GLContext mglContext;
    bool mQuit;
    bool mDrawing;
    std::vector<Point> mPoints;
public:
    Application();
    ~Application();
    bool Initialize();
    void run();
};

#endif
