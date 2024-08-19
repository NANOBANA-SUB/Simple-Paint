#include "Application.h"
#include "Renderer/Renderer.h"
#include <iostream>
#include <GL/glew.h>

Application::Application()
    : mWindow(nullptr),
    mglContext(nullptr),
    mQuit(false),
    mDrawing(false)
{

}

Application::~Application()
{
    if (mglContext) SDL_GL_DeleteContext(mglContext);
    if (mWindow) SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

bool Application::Initialize()
{
    // SDL初期化
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init_Error:" << SDL_GetError() << std::endl;
        return false;
    }

    // SDLウィンドウの作成
    mWindow = SDL_CreateWindow(
        "Simple Paint",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1280, 720,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if (!mWindow)
    {
        std::cerr << "SDL_CreateWindow Error:" << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // SDLでOpenGLのコンテキストを作成
    mglContext = SDL_GL_CreateContext(mWindow);
    if (!mglContext)
    {
        std::cerr << "SDL_GL_CreateContext Error:" << SDL_GetError() << std::endl;
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        return false;
    }

    //Renderer::initOpenGL();

    glViewport(0, 0, 800, 600);

    return true;
}

void Application::run()
{
    while (!mQuit)
    {
        handleEvents();
        render();
        SDL_GL_SwapWindow(mWindow);
    }
}

void Application::handleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            mQuit = true;
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            if (e.button.button == SDL_BUTTON_LEFT)
            {
                mDrawing = true;
                mPoints.push_back(convertToOpenGLCoords(e.button.x, e.button.y));
            }
        }
        else if (e.type == SDL_MOUSEBUTTONUP)
        {
            if (e.button.button == SDL_BUTTON_LEFT) mDrawing = false;
        }
        else if (e.type == SDL_MOUSEMOTION)
        {
            if (mDrawing)
            {
                mPoints.push_back(convertToOpenGLCoords(e.motion.x, e.motion.y));
            }
        }
    }
}

void Application::update()
{

}

void Application::render()
{
    Renderer::render(mPoints);
}

Point Application::convertToOpenGLCoords(int x, int y)
{
    float openglX = (2.0f * x) / 1280.0f - 1.0f;  // ウィンドウ幅を1280として計算
    float openglY = 1.0f - (2.0f * y) / 720.0f;   // ウィンドウ高さを720として計算
    return {openglX, openglY};
}
