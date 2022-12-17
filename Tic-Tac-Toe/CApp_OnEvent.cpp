#include "CApp.hpp"

void CApp::onEvent(SDL_Event* ev)
{
    CEvent::onEvent(ev);
};



void CApp::onExit()
{
    if (this->isQuit)
        this->isRunning = false;
    else
    {
        switch (this->choice)
        {
        case 0:
            if (this->isPause)
            {
                this->isPause = false;
                this->isGame = true;
            }
            else if (this->isGame)
            {
                this->isGame = false;
                this->isPause = true;
            }
            else
                this->isRunning = false;
            break;

        case 1:
            if (this->isSetting)
                this->isSetting = false;
            else
                this->isRunning = false;
            break;

        case 2:
            this->isRunning = false;
            break;

        case 3:
            if (this->isChanging)
                this->isChanging = false;
            else
                this->isRunning = false;
            break;

        case 4:
            if (this->isRecord)
                this->isRecord = false;
            else
                this->isRunning = false;
            break;

        default:
            break;
        }
    }
};

void CApp::onLButtonDown(int xm, int ym)
{
    if (this->isPause)
    {
        if (xm > 280 && xm < 440)
        {
            if (ym >= 135 && ym < 165)
            {
                this->pas_choice = 0;
                this->onReturn();
            }
            else if (ym >= 165 && ym < 195)
            {
                this->pas_choice = 1;
                this->onReturn();
            }
            
        }
    }
    else if (this->isGame) //Только во время игры
    {
        int i = floor(xm - FIELD_LEFT) / 140;
        int j = floor(ym - FIELD_RIGHT) / 140;

        if ((i < 0 || i > 2) || (j < 0 || j > 2))
            return;

        if (this->field[i][j] != 0)
            return;

        field[i][j] = TYPE_X;
        this->mus->playAudio(CMusic::PLACE);
        this->check_end();

        this->find_move();

        this->check_end();
    }
    else if (this->isRecord)
    {
        if (ym > 430 && ym < 465)
        {
            if (xm > 125 && xm <= 180)
            {
                this->choice = 4;
                this->rec_choice = 0;
                this->onReturn();
            }
            else if (xm > 300 && xm <= 355)
            {
                this->choice = 4;
                this->rec_choice = 1;
                this->onReturn();
            }
            else if (xm > 470 && xm <= 555)
            {
                this->choice = 4;
                this->rec_choice = 2;
                this->onReturn();
            }
        }
    }
    else if (!this->isSetting && !this->isChanging && !this->isGame && !this->isRecord && !this->isPause)
    {
        if (xm > 300 && xm < 400)
            if (ym > 180 && ym <= 219)
            {
                this->choice = 0;
                this->onReturn();
            }
            else if (ym > 220 && ym <= 259)
            {
                this->choice = 1;
                this->onReturn();
            }
            else if (ym > 260 && ym <= 299)
            {
                this->choice = 2;
                this->onReturn();
            }
            else if (ym > 300 && ym <= 339)
            {
                this->choice = 3;
                this->onReturn();
            }
            else if (ym > 340 && ym <= 379)
            {
                this->choice = 4;
                this->onReturn();
            }
    }
};

void CApp::onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle)
{
    if (this->isPause)
    {
        int pas_changed = this->pas_choice;
        if (xm > 280 && xm < 440)
        {
            if (ym >= 135 && ym < 165)
                this->pas_choice = 0;
            else if (ym >= 165 && ym < 195)
                this->pas_choice = 1;

            if (pas_changed - this->pas_choice != 0)
            {
                pas_changed = this->pas_choice;
                this->mus->playAudio(CMusic::PLACE);
            }
        }
    }
    else if (this->isRecord)
    {
        int rec_changed = this->rec_choice;

        if (ym > 430 && ym < 465)
        {
            if (xm > 130 && xm <= 180)
                this->rec_choice = 0;
            else if (xm > 300 && xm <= 355)
                this->rec_choice = 1;
            else if (xm > 470 && xm <= 555)
                this->rec_choice = 2;
        }
        if (this->rec_choice - rec_changed != 0)
        {
            rec_changed = this->choice;
            this->mus->playAudio(CMusic::PLACE);
        }
    }
    else if (!this->isSetting && !this->isChanging && !this->isGame && !this->isRecord && !this->isPause)
    {
        int changed = this->choice;
        if (xm > 280 && xm < 440)
        {
            if (ym > 180 && ym <= 214)
                this->choice = 0;
            else if (ym > 215 && ym <= 254)
                this->choice = 1;
            else if (ym > 255 && ym <= 294)
                this->choice = 2;
            else if (ym > 295 && ym <= 334)
                this->choice = 3;
            else if (ym > 335 && ym <= 374)
                this->choice = 4;
        }
        if (this->choice - changed != 0)
        {
            changed = this->choice;
            this->mus->playAudio(CMusic::PLACE);
        }
    }
};

void CApp::onArrowDownDown()
{
    if (this->isPause)
    {
        if (this->pas_choice != 1)
        {
            this->pas_choice++;
            this->mus->playAudio(CMusic::PLACE);
        }
    }
    if (!this->isGame && !this->isChanging && !this->isRecord && !this->isSetting && !this->isPause) //Только в меню
    {
        if (this->choice != 4)
        {
            this->choice++;
            this->mus->playAudio(CMusic::PLACE);
        }
    }
};

void CApp::onArrowUpDown()
{
    if (this->isPause)
    {
        if (this->pas_choice != 0)
        {
            this->pas_choice--;
            this->mus->playAudio(CMusic::PLACE);
        }
    }
    if (!this->isGame && !this->isChanging && !this->isRecord && !this->isSetting && !this->isPause) //Только в меню
    {
        if (this->choice != 0)
        {
            this->choice--;
            this->mus->playAudio(CMusic::PLACE);
        }
    }
};

void CApp::onArrowLeftDown()
{
    if (this->isRecord) //Если в рекордах
        if (this->rec_choice != 0)
        {
            this->rec_choice--;
            this->mus->playAudio(CMusic::PLACE);
        }
};

void CApp::onArrowRightDown()
{
    if (this->isRecord) //Если в рекордах
        if (this->rec_choice != 2)
        {
            this->rec_choice++;
            this->mus->playAudio(CMusic::PLACE);
        }
};

void CApp::onTextInput(char* text)
{
    if (this->isChanging)
        this->name += text;
    if (this->name[0] == ' ')
        this->name = "";
};

void CApp::onBackspaceDown()
{
    if (this->isChanging)
        if (this->name.length() != 0)
            this->name.pop_back();
};

void CApp::onReturn() //Когда нажат enter
{
    switch (this->choice)
    {
    case 0:
        if (this->isPause) //Если стоит пауза
        {
            switch (this->pas_choice)
            {
            case 0:
                this->isGame = true;
                this->isPause = false;
                break;

            case 1:
            {
                this->isGame = false;
                this->isPause = false;

                Info t;
                t.name = this->name;
                t.score_player = this->score_player;
                t.score_pc = this->score_pc;
                t.score_draw = this->score_draw;
                info.push_back(t);

                std::sort(info.begin(), info.end(), [](const Info& p1, const Info& p2) {
                    return p1.score_player > p2.score_player;
                    });
                this->LoadInFile();
            }
                break;

            default:
                break;
            }
        }
        else if (this->name == "")
        {
            this->choice = 3;
            this->isChanging = true;
            this->isGame = false;
        }
        else
            this->isGame = true;
        break;

    case 1:
        this->isSetting = true;
        break;

    case 2:
        this->isRunning = false;
        break;

    case 3:
        if (this->isChanging) //Когда ввели имя
            this->isChanging = false;
        else //Когда входим в смену игрока
            this->isChanging = true;
        break;

    case 4:
        if (this->isRecord) //Когда в рекордах
        {
            switch (this->rec_choice)
            {
            case 0:
                this->isRecord = false;
                break;

            case 1:
                this->info.clear();
                break;

            case 2:
                if (this->info.size() != 0)
                    this->LoadInFile();
                break;

            default:
                break;
            }
        }
        else
            this->isRecord = true;
        break;

    default:
        break;
    }
};
