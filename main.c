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
            InputNamaPemain(&player1, &player2);
            PlayGame(&currentMenu);
        }else
        {
            return 1;
        }
        

    } while (currentMenu != "exit");

    return 0;
}