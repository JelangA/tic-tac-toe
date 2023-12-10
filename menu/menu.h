#if !defined(MENU_H)
#define MENU_H

#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

#include "menu.c"


int chooseBoard();
int chooseOpponent();
int mainMenu();
void InputNamaPemain(Player *p1, Player *p2, char **currmenu);
void PlayGame();

#endif // MENU_H