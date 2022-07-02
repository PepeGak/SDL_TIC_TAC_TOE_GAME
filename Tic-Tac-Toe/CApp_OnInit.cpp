#include "CApp.h"

bool CApp::onInit()
{
    this->LoadFromFile();

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;

    this->type1[0] = new CWindow;
    if (this->type1[0] == nullptr)
        return false;
    if (!this->type1[0]->Load())
        return false;

    this->screen = new CScreen;
    if (this->screen == nullptr)
        return false;
    this->screen->getWindowSurface(this->type1[0]->window);
    

    this->background1 = new CScreen_Background("Assets/Background.bmp", this->screen->screen);
    if (this->background1 == nullptr)
        return false;
    
    this->background2 = new CScreen_Background("Assets/Background3.bmp", this->screen->screen);
    if (this->background2 == nullptr)
        return false;

    this->type1[1] = new CWindow_Icon(this->type1[0]->window);
    if (this->type1[1] == nullptr)
        return false;
    if (!this->type1[1]->Load())
        return false;

    this->stone_x = new CScreen_Stone(this->screen->screen, "Assets/Stone1.bmp", 30, 129, 192);
    if (this->stone_x == nullptr)
        return false;

    this->stone_o = new CScreen_Stone(this->screen->screen, "Assets/Stone2.bmp", 30, 129, 192);
    if (this->stone_o == nullptr)
        return false;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        return false;

    this->mus = new CMusic();
    if (this->mus == nullptr)
        return false;
    if (!this->mus->LoadMedia())
        return false;

    if (TTF_Init() == -1)
        return false;

    this->font = new CScreen_Font(24, this->screen->screen);
    if (this->font == nullptr)
        return false;

    return true;
};
