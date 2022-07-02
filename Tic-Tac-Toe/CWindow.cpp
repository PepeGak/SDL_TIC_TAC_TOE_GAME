#include "CWindow.h"

CWindow::CWindow()
{
    this->names[0] = "Tic-Tac-Toe";
    this->names[1] = "Basurmanov O717B";

    this->window = nullptr;
};

bool CWindow::Load()
{
    this->window = SDL_CreateWindow(WINDOW_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN);
    if (this->window == nullptr)
        return false;

    return true;
};

CWindow::~CWindow()
{
    SDL_DestroyWindow(this->window);
    this->window = nullptr;
};
