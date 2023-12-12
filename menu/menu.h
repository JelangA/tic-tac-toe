#if !defined(MENU_H)
#define MENU_H

#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

#include "menu.c"


void InputNamaPemain(Player *p1, Player *p2, char **currmenu);
int chooseBoard();
int chooseOpponent(char **currmenu);
int mainMenu(char **curmenu);
void PlayGame(char **currmenu);
void resultMenu(char **currmenu);
void winmenu(char **currmenu);

#endif // MENU_H