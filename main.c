#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./gameplay/game.c"
#include "./highscore/highscore.h"
#include "./choosingOpponent/opponent.c"
#include "player.h"

int main()
{

    char symbolX;
    char symbolO;

    int row, col;
    symbolX = 'X';
    symbolO = 'O';
    char currentPlayer = symbolX;

    //inisialisasi player
    Player player1;
    Player player2;

    //player 1
    strcpy(player1.nama, "bamkong");//input nama ke ADT
    player1.score = 12; //input nama ke ADT
    tulisHighscore(player1); //Simpan Data ADT ke FILE 
    sortHighscore(); //Sorting FILE 3

    strcpy(player2.nama, "bamkong"); //input nama ke ADT
    player2.score = 12; //input nama ke ADT
    tulisHighscore(player2); //Simpan Data ADT ke FILE
    sortHighscore(); //Sorting FILE 

    chooseOpponent();

    if(opponent == 1){
        printf("Choose the board size : \n1. 3x3\n2. 5x5\n3. 7x7\n");
        scanf("%d", &size);
        switch (size)
        {
        case 1:
            size = 3;
            break;

        case 2:
            size = 5;
            break;

        case 3:
            size = 7;
            break;
        default:
            printf("invalid choice");
        }

        if (size < 3 || size > 7 || size % 2 == 0)
        {
            printf("Invalid board size. Please choose 3, 5, or 7.\n");
            return 1;
        }
        system("CLS");
        initializeBoard();

        do
        {
            printBoard();
            // Input and move validation
            do
            {
                printf("Player %c, enter your move : \n", currentPlayer);
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
            }printf("Choose the board size : \n1. 3x3\n2. 5x5\n3. 7x7\n");
        scanf("%d", &size);
        switch (size)
        {
        case 1:
            size = 3;
            break;

        case 2:
            size = 5;
            break;

        case 3:
            size = 7;
            break;
        default:
            printf("invalid choice");
        }

        if (size < 3 || size > 7 || size % 2 == 0)
        {
            printf("Invalid board size. Please choose 3, 5, or 7.\n");
            return 1;
        }
        system("CLS");
        initializeBoard();

        do
        {
            printBoard();
            // Input and move validation
            do
            {
                printf("Player %c, enter your move : \n", currentPlayer);
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

        } while (1);

            if (isBoardFull())
            {
                printBoard();
                printf("draw!\n");
                break;
            }
            system("CLS");

            // Switch player
            currentPlayer = (currentPlayer == symbolX) ? symbolO : symbolX;

        } while (1);   
    }

    return 0;
}