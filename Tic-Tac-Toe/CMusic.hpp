#pragma once
#ifndef _CMUSIC_H_
#define _CMUSIC_H_
#include "Defines.hpp"

class CMusic
{
public:
    enum Which
    {
        WIN = 0,
        LOSE,
        DRAW,
        PLACE
    };

    CMusic();
    ~CMusic();
    bool LoadMedia();
    void playAudio(Which which);

private:
    Mix_Chunk* mus_draw;
    Mix_Chunk* mus_win;
    Mix_Chunk* mus_lose;
    Mix_Chunk* mus_place;
};

#endif
