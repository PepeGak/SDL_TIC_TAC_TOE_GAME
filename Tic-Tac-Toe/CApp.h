#pragma once
#ifndef _CAPP_H_
#define _CAPP_H_


#include "CEvent.h"
#include "CMusic.h"
#include "CScreen_Background.h"
#include "CScreen_Font.h"
#include "CScreen_Stone.h"
#include "CWindow_Icon.h"

class CApp : public CEvent
{
public:
    CApp();
    virtual ~CApp();
    
    int onExecute();

private:

    void onEvent(SDL_Event* ev) override;
    void onExit() override;

    void onLButtonDown(int xm, int ym) override;
    void onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle) override;

    void onArrowDownDown() override;
    void onArrowUpDown() override;

    void onArrowLeftDown() override;
    void onArrowRightDown() override;

    void onTextInput(char* text) override;
    void onBackspaceDown() override;

    void onReturn() override;

    /*---------*/

    void Menu();
    int choice; //На каком пункте меню мы находимся
    int rec_choice; //На каком пункте в рекордах мы находимся
    int pas_choice; //На каком пункте паузы мы находимся
    
    void menu_draw(); //Рисовка меню
    void settings_draw(); //Рисовка настроек
    void record_draw(); //Рисовка рекордов
    void change_draw(); //Рисовка смены игрока
    void pause_draw(); //Риспока паузы
    std::string name; //Имя игрока


    bool isGame; //Отвечает за то, мы сейчас в игре или нет
    bool isSetting; //Отвечает за то, мы сейчас в настройках или нет
    bool isRecord; //Отвечает за то, мы сейчас в рекордах или нет
    bool isChanging; //Отвечает за то, мы сейчас в смене игрока или нет
    bool isPause; //Отвечает за то, мы сейчас в паузе или нет

    void LoadInFile();
    void LoadFromFile();

    enum TYPE
    {
        TYPE_X = 1,
        TYPE_O = 2
    };

    bool isRunning;
    
    CScreen_Background* background1;
    CScreen_Background* background2;

    CScreen* screen;
    
    CWindow* type1[2];
    
    CScreen_Stone* stone_x;
    CScreen_Stone* stone_o;

    int field[3][3];
    int score_player;
    int score_pc;
    int score_draw;
    
    struct Info
    {
        std::string name;
        int score_player;
        int score_pc;
        int score_draw;
    };
    std::vector<Info> info;

    CMusic* mus;

    CScreen_Font* font;

    bool onInit();
    void onRender();
    void onQuit();

    /*---------*/

    void field_init();
    void reset();
    void field_draw();
    
    void check_end();
    bool check_playerWin();
    bool check_PCWin();
    bool check_draw();

    void find_move();
    void find_random();
    bool find_win();
    bool find_lose();
    bool find_centre();
};

#endif
