#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./gameplay/game.h"
#include "./highscore/highscore.h"
#include "player.h"
#include "./menu/menu.h"
// #include "./menu/menuUtama.c"

int main()
{

    Player player1;
    Player player2;

    InputNamaPemain(&player1, &player2);
    player1.score = 21; // input nama ke ADT
    // player 1

    tulisHighscore(player1); // Simpan Data ADT ke FILE

    // player 2
    //  strcpy(player2.nama, "aaaaa"); //input nama ke ADT
    player2.score = 31;      // input nama ke ADT
    tulisHighscore(player2); // Simpan Data ADT ke FILE
    sortHighscore();         // Sorting FILE

    printf("%s : %d \n%s : %d\n", player1.nama, player1.score, player2.nama, player2.score);
}