#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

#include "./gameplay/game.h"
#include "./highscore/highscore.h"
#include "player.h"

// int move;

int main()
{

    // inisialisasi player
    Player player1;
    Player player2;

    char symbolX;
    char symbolO;

    int row, col;
    symbolX = 'X';
    symbolO = 'O';
    char currentPlayer = symbolX;
    char *currentNamePlayer;

    // player 1
    // strcpy(player1.nama, "bamkong"); // input nama ke ADT
    // player1.score = 12;              // input nama ke ADT
    // tulisHighscore(player1);         // Simpan Data ADT ke FILE
    // sortHighscore();                 // Sorting FILE 3

    // strcpy(player2.nama, "bamkong"); // input nama ke ADT
    // player2.score = 12;              // input nama ke ADT
    // tulisHighscore(player2);         // Simpan Data ADT ke FILE
    // sortHighscore();                 // Sorting FILE

    mainMenu();
    chooseOpponent();
    InputNamaPemain(&player1, &player2);
    currentNamePlayer = player1.nama;

    if (opponent == 1)
    {
        chooseBoard();
        system("CLS");
        initializeBoard();

        do
        {
            printBoard();
            // Input and move validation
            do
            {
                printf("Player %s, enter your move : \n", currentNamePlayer);
                printf("your row : ");
                scanf("%d", &row);
                printf("your collumn : ");
                scanf("%d", &col);
                row--;
                col--;
            } while (!isMoveValid(row, col));

            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer, size))
            {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            if (isBoardFull())
            {
                printBoard();
                printf("draw!\n");
                break;
            }
            system("CLS");

            // Switch player
            currentPlayer = (currentPlayer == symbolX) ? symbolO : symbolX;
            currentNamePlayer = (currentNamePlayer == player1.nama) ? player2.nama : player1.nama;

        } while (1);
    }
    else if (opponent == 2)
    {
        chooseBoard();
    }
    return 0;
}