#if !defined(GAME_H)
#define GAME_H

#include "../player.h"
#include "game.c"

void initializeBoard();
void printBoard();
int isMoveValid(int row, int col);
int checkWin(char symbol, int size);
int isBoardFull();

#endif // GAME_H
