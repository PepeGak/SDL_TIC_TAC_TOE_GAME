#include "CApp.h"

void CApp::onQuit()
{
    delete this->font;
    this->font = nullptr;

    delete this->mus;
    this->mus = nullptr;

    delete this->type1[1];
    this->type1[1] = nullptr;

    delete this->screen;
    this->screen = nullptr;
    
    delete this->background1;
    this->background1 = nullptr;

    delete this->background2;
    this->background2 = nullptr;

    delete this->stone_x;
    this->stone_x = nullptr;

    delete this->stone_o;
    this->stone_o = nullptr;

    Mix_Quit();
    SDL_Quit();
    TTF_Quit();
};
