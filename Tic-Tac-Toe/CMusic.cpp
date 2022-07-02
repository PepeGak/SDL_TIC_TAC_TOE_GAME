#include "CMusic.h"

CMusic::CMusic()
{
    this->mus_draw = nullptr;
    this->mus_win = nullptr;
    this->mus_lose = nullptr;
    this->mus_place = nullptr;
};

bool CMusic::LoadMedia()
{
    this->mus_draw = Mix_LoadWAV("Assets/Draw.wav");
    this->mus_lose = Mix_LoadWAV("Assets/Lose.wav");
    this->mus_place = Mix_LoadWAV("Assets/Place.wav");
    this->mus_win = Mix_LoadWAV("Assets/Win.wav");

    if (this->mus_draw == nullptr ||
        this->mus_lose == nullptr ||
        this->mus_place == nullptr ||
        this->mus_win == nullptr)
        return false;
    return true;
};
/*
* 0 = win
* 1 = lose
* 2 = draw
* 3 = place
*/
void CMusic::playAudio(Which which)
{
    switch (which)
    {
    case WIN:
        Mix_PlayChannel(-1, this->mus_win, 0);
        break;

    case LOSE:
        Mix_PlayChannel(-1, this->mus_lose, 0);
        break;

    case DRAW:
        Mix_PlayChannel(-1, this->mus_draw, 0);
        break;

    case PLACE:
        Mix_PlayChannel(-1, this->mus_place, 0);
        break;

    default:
        break;
    }
};

CMusic::~CMusic()
{
    Mix_FreeChunk(this->mus_draw);
    this->mus_draw = nullptr;

    Mix_FreeChunk(this->mus_lose);
    this->mus_lose = nullptr;

    Mix_FreeChunk(this->mus_place);
    this->mus_place = nullptr;

    Mix_FreeChunk(this->mus_win);
    this->mus_win = nullptr;
};
