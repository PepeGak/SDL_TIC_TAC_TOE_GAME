#include "CSurface.h"

CSurface::CSurface()
{

};

SDL_Surface* CSurface::LoadSurface(const char* fileName, SDL_Surface* screenSurface)
{
    SDL_Surface* temp = SDL_LoadBMP(fileName);
    if (temp == nullptr)
        return nullptr;

    SDL_Surface* newSurface = SDL_ConvertSurface(temp, screenSurface->format, 0);
    SDL_FreeSurface(temp);

    return newSurface;
};

SDL_Surface* CSurface::LoadSurface(const char* fileName, SDL_Surface* screenSurface, int r, int g, int b)
{
    SDL_Surface* temp = SDL_LoadBMP(fileName);
    if (temp == nullptr)
        return nullptr;

    SDL_Surface* newSurface = SDL_ConvertSurface(temp, screenSurface->format, 0);
    SDL_SetColorKey(newSurface, SDL_TRUE, SDL_MapRGB(newSurface->format, r, g, b));
    
    
    SDL_FreeSurface(temp);

    return newSurface;
};

void CSurface::drawSurface(SDL_Surface* source, SDL_Surface* destination, int x, int y)
{
    if (source == nullptr)
        return;

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;

    SDL_BlitSurface(source, nullptr, destination, &dstRect);

};

void CSurface::drawSurface(SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip, int x, int y)
{
    if (source == nullptr)
        return;

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;

    SDL_BlitSurface(source, clip, destination, &dstRect);

};

void CSurface::drawSurface(SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip, SDL_Rect* scale)
{
    if (source == nullptr)
        return;

    SDL_BlitSurface(source, clip, destination, scale);
};

void CSurface::drawFont(TTF_Font* font, SDL_Surface* screen, const char* text, int x, int y, int r, int g, int b)
{
    if (font == nullptr || screen == nullptr)
        return;

    SDL_Color colour = { r,g,b };
    
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;

    SDL_Surface* txtSurface = TTF_RenderUTF8_Solid(font, text, colour);
    if (txtSurface == nullptr)
        return;

    SDL_BlitSurface(txtSurface, nullptr, screen, &dstRect);
    SDL_FreeSurface(txtSurface);
};
