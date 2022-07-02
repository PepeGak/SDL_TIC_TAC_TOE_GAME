#pragma once
#ifndef _CWINDOW_ICON_H_
#define _CWINDOW_ICON_H_

#include "CWindow.hpp"
class CWindow_Icon : public CWindow
{
public:
    CWindow_Icon(SDL_Window* window);
    bool Load() override;
    ~CWindow_Icon();

private:
    SDL_Surface* icon;
};

#endif
