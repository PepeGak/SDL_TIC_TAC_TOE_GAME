#pragma once
#ifndef _CEVENT_H_
#define _CEVENT_H_

#include "Defines.h"

class CEvent
{
public:
    CEvent();
    virtual ~CEvent();

    virtual void onEvent(SDL_Event* ev); //Используется
    virtual void onExit(); //Используется

    virtual void onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode); //Используется
    virtual void onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle); //Используется

    virtual void onArrowDownDown(); //Используется
    virtual void onArrowUpDown(); //Используется

    virtual void onArrowLeftDown(); //Используется
    virtual void onArrowRightDown(); //Используется

    virtual void onTextInput(char* text); //Используется
    virtual void onBackspaceDown(); //Используется

    virtual void onReturn(); //Используется


    virtual void onLButtonDown(int xm, int ym); //Используется

protected:
    bool isQuit;
};

#endif
