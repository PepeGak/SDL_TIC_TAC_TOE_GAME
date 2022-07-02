#pragma once
#ifndef _CEVENT_H_
#define _CEVENT_H_

#include "Defines.hpp"

class CEvent
{
public:
    CEvent();
    virtual ~CEvent();

    virtual void onEvent(SDL_Event* ev); //������������
    virtual void onExit(); //������������

    virtual void onKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode); //������������
    virtual void onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle); //������������

    virtual void onArrowDownDown(); //������������
    virtual void onArrowUpDown(); //������������

    virtual void onArrowLeftDown(); //������������
    virtual void onArrowRightDown(); //������������

    virtual void onTextInput(char* text); //������������
    virtual void onBackspaceDown(); //������������

    virtual void onReturn(); //������������


    virtual void onLButtonDown(int xm, int ym); //������������

protected:
    bool isQuit;
};

#endif
