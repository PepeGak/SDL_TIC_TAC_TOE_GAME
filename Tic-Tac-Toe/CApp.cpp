#include "CApp.h"
#pragma warning (disable : 4996)

CApp::CApp()
{
    this->isRunning = true;
    this->isGame = false;
    this->isSetting = false;

    this->choice = 0;
    this->rec_choice = 0;
    this->pas_choice = 0;

    this->type1[0] = nullptr;
    this->type1[1] = nullptr;

    this->screen = nullptr;
    this->background1 = nullptr;
    this->stone_x = nullptr;
    this->stone_o = nullptr;

    this->mus = nullptr;

    this->reset();
};

CApp::~CApp()
{

};

int CApp::onExecute()
{
    if (!this->onInit())
        return -1;

    this->Menu();

    this->onQuit();
    return 0;
};

void CApp::Menu()
{
    SDL_Event gameEvent;
    while (this->isRunning)
    {
        while (SDL_PollEvent(&gameEvent))
            this->onEvent(&gameEvent);

        this->onRender();
    }

};

void CApp::LoadInFile()
{
    std::ofstream fout;
    fout.open("Assets/Records.txt", std::ofstream::trunc | std::ofstream::out);

    for (int i = 0; i < 10 && i < this->info.size(); i++)
    {
        auto t = this->info[i];
        if (t.name == "")
            fout << "Unknown";
        else
            fout << t.name;
        fout << ' ' << t.score_player << ' ' << t.score_pc << ' ' << t.score_draw << '\n';
    }
    fout.close();

    //FILE* f;
    //f = fopen("Assets/Records.bin", "wb");
    //
    //for (int i = 0; i < this->info.size() && i < 10; i++)
    //{
    //    auto t = this->info[i];
    //    fwrite(&t, sizeof(Info), 1, f);
    //}
    //fclose(f);

};

void CApp::LoadFromFile()
{
    std::ifstream fin;
    fin.open("Assets/Records.txt");
    
    fin.seekg(0, std::ios::ios_base::end);

    std::ios_base::streampos size = fin.tellg();
    if (size < 7)
        return;

    Info t;
    fin.seekg(0, std::ios::ios_base::beg);
    while (!fin.eof())
    {
        fin >> t.name;
        fin >> t.score_player;
        fin >> t.score_pc;
        fin >> t.score_draw;
        this->info.push_back(t);
    }

    fin.close();

    /*FILE* f;
    f = fopen("Assets/Records.bin", "rb");
    
    fseek(f, 0, SEEK_END);
    int size = ftell(f) / sizeof(Info);
    fseek(f, 0, SEEK_SET);
    
    Info t;
    for (int i = 0; i < size; i++)
    {
        fwrite(&t, sizeof(Info), 1, f);
        this->info.push_back(t);
    }

    fclose(f);*/
};

void CApp::field_init()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            this->field[i][j] = 0;
};

void CApp::reset()
{
    this->score_player = 0;
    this->score_pc = 0;
    this->score_draw = 0;
    this->field_init();
};

void CApp::check_end()
{
    if (this->check_playerWin())
    {
        this->score_player++;
        this->mus->playAudio(CMusic::WIN);
        this->onRender();
        SDL_Delay(1500);
        this->field_init();
    }
    else if (this->check_PCWin())
    {
        this->score_pc++;
        this->mus->playAudio(CMusic::LOSE);
        this->onRender();
        SDL_Delay(1500);
        this->field_init();
    }
    else if (this->check_draw())
    {
        this->score_draw++;
        this->mus->playAudio(CMusic::DRAW);
        this->onRender();
        SDL_Delay(1500);
        this->field_init();
    }
};

bool CApp::check_playerWin()
{
    if (this->field[0][0] == TYPE_X &&
        this->field[0][1] == TYPE_X &&
        this->field[0][2] == TYPE_X)
        return true;
    if (this->field[1][0] == TYPE_X &&
        this->field[1][1] == TYPE_X &&
        this->field[1][2] == TYPE_X)
        return true;
    if (this->field[2][0] == TYPE_X &&
        this->field[2][1] == TYPE_X &&
        this->field[2][2] == TYPE_X)
        return true;
    
    if (this->field[0][0] == TYPE_X &&
        this->field[1][0] == TYPE_X &&
        this->field[2][0] == TYPE_X)
        return true;
    if (this->field[0][1] == TYPE_X &&
        this->field[1][1] == TYPE_X &&
        this->field[2][1] == TYPE_X)
        return true;
    if (this->field[0][2] == TYPE_X &&
        this->field[1][2] == TYPE_X &&
        this->field[2][2] == TYPE_X)
        return true;

    if (this->field[0][0] == TYPE_X &&
        this->field[1][1] == TYPE_X &&
        this->field[2][2] == TYPE_X)
        return true;
    if (this->field[0][2] == TYPE_X &&
        this->field[1][1] == TYPE_X &&
        this->field[2][0] == TYPE_X)
        return true;

    return false;
};

void CApp::find_move()
{
    if (this->find_win())
        return;
    
    if (this->find_lose())
        return;

    if (this->find_centre())
        return;

    this->find_random();
};

void CApp::find_random()
{
    srand(time(nullptr));
    while (true)
    {
        int i = rand() % 3;
        int j = rand() % 3;

        if (this->field[i][j] == 0)
        {
            this->field[i][j] = TYPE_O;
            break;
        }
    }
};

bool CApp::find_win()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->field[i][j] == 0)
            {
                this->field[i][j] = TYPE_O;
                if (this->check_PCWin())
                    return true;
                else
                    this->field[i][j] = 0;
            }
        }
    }

    return false;
};

bool CApp::find_lose()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->field[i][j] == 0)
            {
                this->field[i][j] = TYPE_X;
                if (this->check_playerWin())
                {
                    this->field[i][j] = TYPE_O;
                    return true;
                }
                else
                    this->field[i][j] = 0;
            }
        }
    }

    return false;
};

bool CApp::find_centre()
{
    srand(time(nullptr));
    
    if (rand() % 2 < 1 && field[1][1] == 0)
    {
        this->field[1][1] = TYPE_O;
        return true;
    }

    return false;
};

bool CApp::check_draw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (this->field[i][j] == 0)
                return false;
    return true;
};

bool CApp::check_PCWin()
{
    if (this->field[0][0] == TYPE_O &&
        this->field[0][1] == TYPE_O &&
        this->field[0][2] == TYPE_O)
        return true;
    if (this->field[1][0] == TYPE_O &&
        this->field[1][1] == TYPE_O &&
        this->field[1][2] == TYPE_O)
        return true;
    if (this->field[2][0] == TYPE_O &&
        this->field[2][1] == TYPE_O &&
        this->field[2][2] == TYPE_O)
        return true;

    if (this->field[0][0] == TYPE_O &&
        this->field[1][0] == TYPE_O &&
        this->field[2][0] == TYPE_O)
        return true;
    if (this->field[0][1] == TYPE_O &&
        this->field[1][1] == TYPE_O &&
        this->field[2][1] == TYPE_O)
        return true;
    if (this->field[0][2] == TYPE_O &&
        this->field[1][2] == TYPE_O &&
        this->field[2][2] == TYPE_O)
        return true;

    if (this->field[0][0] == TYPE_O &&
        this->field[1][1] == TYPE_O &&
        this->field[2][2] == TYPE_O)
        return true;
    if (this->field[0][2] == TYPE_O &&
        this->field[1][1] == TYPE_O &&
        this->field[2][0] == TYPE_O)
        return true;

    return false;
};
