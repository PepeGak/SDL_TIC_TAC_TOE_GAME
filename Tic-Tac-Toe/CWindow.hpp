#pragma once
#ifndef _CWINDOW_H_
#define _CWINDOW_H_

#include "Defines.hpp"

class CWindow
{
public:
    CWindow();
    virtual bool Load();
    virtual ~CWindow();

    friend class CApp;
protected:
    SDL_Window* window;
    
    std::string names[2];
    const int x[2] = { 40, 10 };
    const int y[2] = { 340, 380 };
};

#endif
