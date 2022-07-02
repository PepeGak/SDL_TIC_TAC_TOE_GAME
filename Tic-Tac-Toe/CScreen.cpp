#include "CScreen.h"

CScreen::CScreen()
{
    this->screen = nullptr;
};

CScreen::~CScreen()
{
    SDL_FreeSurface(this->screen);
    this->screen = nullptr;
};

void CScreen::getWindowSurface(SDL_Window* window)
{
    this->screen = SDL_GetWindowSurface(window);
    SDL_SetSurfaceRLE(this->screen, 1);
};

void CScreen::updateWindow(SDL_Window* window)
{
    SDL_UpdateWindowSurface(window);
};

void CScreen::drawSurface(int x, int y)
{

};

void CScreen::drawSurface(int x, int y, SDL_Surface* screenDest)
{

};
