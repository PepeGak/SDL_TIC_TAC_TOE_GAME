#include "CApp.h"

void CApp::onRender()
{
    if (!this->isRecord && !this->isSetting)
        this->background1->drawSurface(0, 0);
    else
        this->background2->drawSurface(0, 0);

    if (this->isChanging)
        this->change_draw();
    else if (this->isRecord)
        this->record_draw();
    else if (this->isSetting)
        this->settings_draw();
    else if (this->isPause)
        this->pause_draw();
    else if (this->isGame)
        this->field_draw();
    else
        this->menu_draw();

    this->screen->updateWindow(this->type1[0]->window);
};

void CApp::field_draw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (field[i][j] == TYPE_X)
                this->stone_x->drawSurface(FIELD_LEFT + i * 140, FIELD_RIGHT + j * 140);
            else if (field[i][j] == TYPE_O)
                this->stone_o->drawSurface(FIELD_LEFT + i * 140, FIELD_RIGHT + j * 140);

    std::string score_Player = "Player wins: " + std::to_string(this->score_player);
    std::string score_Computer = "PC wins: " + std::to_string(this->score_pc);
    std::string score_Draw = "Draws: " + std::to_string(this->score_draw);

    this->font->drawFont(this->name == ""  ? "Unknown" : this->name.c_str(), 10, 340, 0, 0, 0);
    this->font->drawFont(score_Player.c_str(), 10, 370, 0, 0, 255);
    this->font->drawFont(score_Computer.c_str(), 10, 400, 255, 0, 0);
    this->font->drawFont(score_Draw.c_str(), 10, 430, 0, 0, 0);
};

void CApp::menu_draw()
{
    std::string menu[] =
    {
        "Play",
        "About",
        "Exit",
        "Change player",
        "Records"
    };
    
    this->font->drawFont(this->type1[0]->names[0].c_str(), this->type1[0]->x[0], this->type1[0]->y[0], 255, 0, 0);
    this->font->drawFont(this->type1[0]->names[1].c_str(), this->type1[0]->x[1], this->type1[0]->y[1], 255, 0, 0);
    this->font->drawFont(this->name == "" ? "Unknown" : this->name.c_str(), 10, 420, 0, 0, 0);

    this->font->drawFont(menu[0].c_str(), this->choice == 0 ? 310 : 300, 180, this->choice == 0 ? 255 : 0, 0, 0);
    this->font->drawFont(menu[1].c_str(), this->choice == 1 ? 310 : 300, 220, this->choice == 1 ? 255 : 0, 0, 0);
    this->font->drawFont(menu[2].c_str(), this->choice == 2 ? 310 : 300, 260, this->choice == 2 ? 255 : 0, 0, 0);
    this->font->drawFont(menu[3].c_str(), this->choice == 3 ? 310 : 300, 300, this->choice == 3 ? 255 : 0, 0, 0);
    this->font->drawFont(menu[4].c_str(), this->choice == 4 ? 310 : 300, 340, this->choice == 4 ? 255 : 0, 0, 0);
};

void CApp::settings_draw()
{
    std::string menu[] =
    {
        "This game is tic-tac-toe. Here, using the mouse",
        "you need to place stones on field in order to win",
        "Howeven, your enemy (PC) will do the same.",
        "Place 3 your stones in row to win!"
    };

    this->font->drawFont(menu[0].c_str(), 80, 20, 0, 0, 0);
    this->font->drawFont(menu[1].c_str(), 80, 60, 0, 0, 0);
    this->font->drawFont(menu[2].c_str(), 80, 100, 0, 0, 0);
    this->font->drawFont(menu[3].c_str(), 80, 140, 0, 0, 0);
};

void CApp::record_draw()
{
    std::string fields = "|NAME     | WINS | LOSES | DRAWS |";
    this->font->drawFont(fields.c_str(), 120, 20, 0, 0, 0);

    for (int i = 0; i < this->info.size() && i < 10; i++)
    {
        std::string temp = std::to_string(i + 1);
        this->font->drawFont(temp.c_str(), 100, 60 + i * 20, 127, 127, 127);

        temp = this->info[i].name;
        this->font->drawFont(temp.c_str(), 135, 60 + i * 20, 127, 127, 127);

        temp = std::to_string(this->info[i].score_player);
        this->font->drawFont(temp.c_str(), 260, 60 + i * 20, 127, 127, 127);

        temp = std::to_string(this->info[i].score_pc);
        this->font->drawFont(temp.c_str(), 340, 60 + i * 20, 127, 127, 127);

        temp = std::to_string(this->info[i].score_draw);
        this->font->drawFont(temp.c_str(), 420, 60 + i * 20, 127, 127, 127);
    }
    this->font->drawFont("Menu", 130, 450, this->rec_choice == 0 ? 255 : 0, 0, 0);
    this->font->drawFont("Clear", 305, 450, this->rec_choice == 1 ? 255 : 0, 0, 0);
    this->font->drawFont("Save", 480, 450, this->rec_choice == 2 ? 255 : 0, 0, 0);
};

void CApp::change_draw()
{
    std::string ch = "Write your nickname: ";
    this->font->drawFont(ch.c_str(), 200, 200, 0, 0, 0);
    this->font->drawFont(this->name.c_str(), 200, 240, 255, 0, 0);
};

void CApp::pause_draw()
{
    std::string pause[] =
    {
        "Pause",
        "Continue",
        "Exit"
    };
    this->font->drawFont(pause[0].c_str(), 300, 120, 0, 0, 0);
    this->font->drawFont(pause[1].c_str(), this->pas_choice == 0 ? 310 : 300, 150, this->pas_choice == 0 ? 255 : 0, 0, 0);
    this->font->drawFont(pause[2].c_str(), this->pas_choice == 1 ? 310 : 300, 180, this->pas_choice == 1 ? 255 : 0, 0, 0);
};