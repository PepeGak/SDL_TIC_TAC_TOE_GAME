#include "CScreen_Stone.h"

CScreen_Stone::CScreen_Stone(const char* filePath, int r, int g, int b)
{
    SDL_Surface* temp = SDL_LoadBMP(filePath);

    this->stone = SDL_ConvertSurface(temp, this->screen->format, 0);
    SDL_SetColorKey(this->stone, SDL_TRUE, SDL_MapRGB(this->stone->format, r, g, b));
    SDL_FreeSurface(temp);
};

CScreen_Stone::CScreen_Stone(SDL_Surface* screenDest, const char* filePath, int r, int g, int b)
{
    SDL_Surface* temp = SDL_LoadBMP(filePath);
    this->screen = screenDest;
    this->stone = SDL_ConvertSurface(temp, this->screen->format, 0);
    SDL_SetColorKey(this->stone, SDL_TRUE, SDL_MapRGB(this->stone->format, r, g, b));
    SDL_FreeSurface(temp);
};

CScreen_Stone::~CScreen_Stone()
{
    SDL_FreeSurface(this->stone);
    this->stone = nullptr;
};

void CScreen_Stone::drawSurface(int x, int y)
{
    if (this->stone == nullptr)
        return;

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;

    SDL_BlitSurface(this->stone, nullptr, this->screen, &dstRect);
};
