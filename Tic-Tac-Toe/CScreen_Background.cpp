#include "CScreen_Background.h"

CScreen_Background::CScreen_Background(const char* filePath)
{
    this->background = nullptr;

    SDL_Surface* temp = SDL_LoadBMP(filePath);
    if (temp == nullptr)
        return;

    this->background = SDL_ConvertSurface(temp, this->screen->format, 0);
    SDL_FreeSurface(temp);
}
CScreen_Background::CScreen_Background(const char* filePath, SDL_Surface* screenDest)
{
    this->screen = screenDest;
    this->background = nullptr;
    SDL_Surface* temp = SDL_LoadBMP(filePath);
    
    this->background = SDL_ConvertSurface(temp, this->screen->format, 0);
    SDL_FreeSurface(temp);
};

CScreen_Background::~CScreen_Background()
{
    SDL_FreeSurface(this->background);
    this->background = nullptr;
};

void CScreen_Background::drawSurface(int x, int y)
{
    if (this->background == nullptr)
        return;

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;

    SDL_BlitSurface(this->background, nullptr, this->screen, &dstRect);
};

void CScreen_Background::drawSurface(int x, int y, SDL_Surface* screenDest)
{
    if (this->background == nullptr)
        return;

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;

    SDL_BlitSurface(this->background, nullptr, screenDest, &dstRect);
};
