#pragma once
#ifndef _CSCREEN_STONE_H_
#define _SCREEN_STONE_H_

#include "CScreen.h"

class CScreen_Stone : public CScreen
{
public:
    CScreen_Stone(const char* filePath, int r, int g, int b);
    CScreen_Stone(SDL_Surface* screenDest, const char* filePath, int r, int g, int b);
    ~CScreen_Stone();
    void drawSurface(int x, int y) override;

private:
    SDL_Surface* stone;
};

#endif
