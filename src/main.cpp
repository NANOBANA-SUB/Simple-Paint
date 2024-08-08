#include "Application/Application.h"

int SDL_main(int argc, char* argv[])
{
    Application app;
    if (app.Initialize())
    {
        app.run();
    }

    return 0;
}