#include "CScreen_Font.hpp"

CScreen_Font::CScreen_Font(int size, SDL_Surface* screenDest)
{
    this->font = nullptr;
    this->font = TTF_OpenFont("./Tic-Tac-Toe/Assets/CyrilicOld.ttf", size);
    this->screen = screenDest;
};

CScreen_Font::~CScreen_Font()
{
    TTF_CloseFont(this->font);
    this->font = nullptr;
};

void CScreen_Font::drawFont(const char* text, int x, int y, int r, int g, int b)
{
    if (this->font == nullptr)
        return;

    SDL_Color colour = { r, g, b };

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;

    SDL_Surface* txtFont = TTF_RenderUTF8_Solid(this->font, text, colour);

    SDL_BlitSurface(txtFont, nullptr, this->screen, &dstRect);
    SDL_FreeSurface(txtFont);
};
