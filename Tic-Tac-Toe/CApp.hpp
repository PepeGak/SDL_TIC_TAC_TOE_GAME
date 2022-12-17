#pragma once
#ifndef _CAPP_H_
#define _CAPP_H_


#include "CEvent.hpp"
#include "CMusic.hpp"
#include "CScreen_Background.hpp"
#include "CScreen_Font.hpp"
#include "CScreen_Stone.hpp"
#include "CWindow_Icon.hpp"

class CApp : public CEvent
{
public:
    CApp();
    ~CApp();
    
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

    int choice; //�� ����� ������ ���� �� ���������
    int rec_choice; //�� ����� ������ � �������� �� ���������
    int pas_choice; //�� ����� ������ ����� �� ���������
    
    void menu_draw(); //������� ����
    void settings_draw(); //������� ��������
    void record_draw(); //������� ��������
    void change_draw(); //������� ����� ������
    void pause_draw(); //������� �����
    std::string name; //��� ������


    bool isGame; //�������� �� ��, �� ������ � ���� ��� ���
    bool isSetting; //�������� �� ��, �� ������ � ���������� ��� ���
    bool isRecord; //�������� �� ��, �� ������ � �������� ��� ���
    bool isChanging; //�������� �� ��, �� ������ � ����� ������ ��� ���
    bool isPause; //�������� �� ��, �� ������ � ����� ��� ���

    void LoadInFile();
    void LoadFromFile();

    enum TYPE
    {
        TYPE_X = 1,
        TYPE_O = 2
    };
    
    void* arr[2];

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
    void Menu();

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
