#include "CWindow_Icon.hpp"

CWindow_Icon::CWindow_Icon(SDL_Window* window)
{
    this->icon = nullptr;
    this->window = window;
};

bool CWindow_Icon::Load()
{
    this->icon = IMG_Load("./Tic-Tac-Toe/Assets/icon.png");
    if (this->icon == nullptr)
        return false;
    SDL_SetWindowIcon(this->window, this->icon);
    
    return true;
};

CWindow_Icon::~CWindow_Icon()
{
    SDL_FreeSurface(this->icon);
    this->icon = nullptr;
};
