//simon game

#include "bsp.h"
#include "colors.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

#ifdef _WIN32
#include <conio.h>
#define clear_screen start:; system("cls");
#define play_again cout << "\nPlay Again (y/n)?\n"; char c = _getch();if (tolower(c) == 'y')goto start;
#else
#define clear_screen system("clear");
#define play_again
#endif

using namespace std;

class Simon
{

    int buttons;
    vector<int> vec;
    int score;

    int get_random()
    {
        return rand() % buttons;
    }

    void ShowSequence()
    {
        for (auto i : vec)
            BSP_blinkHwLight(i);
    }

    void restart()
    {
        vec.clear();
        score = 0;
        vec.push_back(get_random());
        cin.clear();
        fflush(stdin);
    }

public:
    Simon() :buttons(4), score(0)
    {
        srand((unsigned int)time(NULL));
#if BUTTONS_NUMBER > 0
        buttons = BUTTONS_NUMBER;
#endif
    }

    int get_buttons_number()
    {
        return buttons;
    }

    int play()
    {
        restart();
        int stp = 0;
        while (true)
        {
            cout << ANSI_UNDERLINE_WHITE <<"\nSTEP: " << ++stp << ANSI_RESET <<"\t\tCurrent Score: " << score++ << endl;
            cout << ANSI_BOLD_GREEN << "\nSimon Says:\n"<< ANSI_BOLD_YELLOW << endl;
            ShowSequence();
            cout << ANSI_UNDERLINE_WHITE << "\nPlayer Says:\n"<< ANSI_RESET << ANSI_BOLD_CYAN << endl;
            for (size_t i = 0; i < vec.size(); i++)
            {
                int btn = BSP_readHwButton();
                if (btn != vec[i])
                    return --score;
            }
            vec.push_back(get_random());
            clear_screen;
        }
        return score;
    }
};

int main()
{

    class Simon simon;
    clear_screen;
    cout << ANSI_BOLD_GREEN << "Start Game : Please choose numbers between 0 and " << simon.get_buttons_number() - 1 << " (inclusive)" << ANSI_RESET << endl;
    int scr = simon.play();
    cout << ANSI_RESET << "\nGame over \nFINAL SCORE : " << scr  << endl;
    play_again; 
    std::cout << ANSI_RESET;
    return scr;
}
