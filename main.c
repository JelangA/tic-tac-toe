#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./gameplay/game.c"
#include "./highscore/highscore.h"
#include "player.h"

    // int move;

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
        chooseBoard();
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
    }else if (opponent == 2)
    {
        chooseBoard();
    }
    return 0;
}

// int minimax(int board[9], int player) {
//     //How is the position like for player (their turn) on board?
//     int winner = win(board);
//     if(winner != 0) return winner*player;

//     move = -1;
//     int score = -2;//Losing moves are preferred to no move
//     int i;
//     for(i = 0; i < 9; ++i) {//For all moves,
//         if(board[i] == 0) {//If legal,
//             board[i] = player;//Try the move
//             int thisScore = -minimax(board, player*-1);
//             if(thisScore > score) {
//                 score = thisScore;
//                 move = i;
//             }//Pick the one that's worst for the opponent
//             board[i] = 0;//Reset board after try
//         }
//     }
//     if(move == -1) return 0;
//     return score;
// }

// void computerMove(int board[9]) {
//     int move = -1;
//     int score = -2;
//     int i;
//     for(i = 0; i < 9; ++i) {
//         if(board[i] == 0) {
//             board[i] = 1;
//             int tempScore = -minimax(board, -1);
//             board[i] = 0;
//             if(tempScore > score) {
//                 score = tempScore;
//                 move = i;
//             }
//         }
//     }
//     //returns a score based on minimax tree at a given node.
//     board[move] = 1;
// }