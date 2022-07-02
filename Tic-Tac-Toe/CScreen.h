#pragma once

#include "Defines.h"

class CScreen
{
public:
    CScreen();
    virtual ~CScreen();
    void getWindowSurface(SDL_Window* window);
    void updateWindow(SDL_Window* window);
    virtual void drawSurface(int x, int y);
    virtual void drawSurface(int x, int y, SDL_Surface* screenDest);

    friend class CApp;
protected:
    SDL_Surface* screen;
};
