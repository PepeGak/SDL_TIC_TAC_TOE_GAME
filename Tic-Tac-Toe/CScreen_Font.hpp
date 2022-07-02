#pragma once
#ifndef _CSCREEN_H_
#define _CSCREEN_H_

#include "CScreen.hpp"
class CScreen_Font : public CScreen
{
public:
    CScreen_Font(int size, SDL_Surface* screenDest);
    ~CScreen_Font();
    void drawFont(const char* text, int x, int y, int r, int g, int b);

private:
    TTF_Font* font;
    int font_size;
};

#endif
