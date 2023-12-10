#include "globalvar.H"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./gameplay/game.h"
#include "./highscore/highscore.h"
#include "./menu/menu.h"

// int move;
int main()
{

    char *currentMenu = "home";
    do
    {
        system("cls");
        if (currentMenu == "home")
        {
            displayHighscores();
            mainMenu(&currentMenu);
        }
        else if (currentMenu == "oponent")
        {
            chooseOpponent(&currentMenu);
        }
        else if (currentMenu == "inputNama")
        {
            InputNamaPemain(&player1, &player2, &currentMenu);
        }
        else if (currentMenu == "playgame")
        {
            PlayGame(&currentMenu);
        }
        else if (currentMenu == "winner")
        {
            winmenu(&currentMenu);
        }
        else if (currentMenu == "result")
        {
            resultMenu(&currentMenu);
        }
        else
        {
            return 1;
        }
    } while (currentMenu != "exit");
    

    return 0;
}