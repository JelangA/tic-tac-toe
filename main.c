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
    mainMenu();
    chooseOpponent();
    InputNamaPemain(&player1, &player2);
    winner();
    return 0;
}