#include "Application.h"
#include "Renderer/Renderer.h"
#include <iostream>

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
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init_Error:" << SDL_GetError() << std::endl;
        return false;
    }

    // OpenGLコンテクストの設定
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    mWindow = SDL_CreateWindow
    (
        "Simple Paint",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1280,720,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if (!mWindow) 
    {
        std::cerr << "SDL_CreateWindow Error:" << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    mglContext = SDL_GL_CreateContext(mWindow);
    if (!mglContext)
    {
        std::cerr << "SDL_GL_CreateContext Error:" << SDL_GetError() << std::endl;
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        return false;
    }

    Renderer::initOpenGL();

    return true;
}

void Application::run()
{
    while (!mQuit)
    {
        handleEvents();
        update();
        render();
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
                mPoints.push_back({static_cast<float>(e.button.x), static_cast<float>(e.button.y)});
            }
        }
        else if (e.type == SDL_MOUSEBUTTONUP)
        {
            if (e.button.button == SDL_BUTTON_LEFT)mDrawing = false;
        }
        else if (e.type == SDL_MOUSEMOTION)
        {
            if (mDrawing)
            {
                mPoints.push_back({static_cast<float>(e.motion.x), static_cast<float>(e.motion.y)});
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
    SDL_GL_SwapWindow(mWindow);
}