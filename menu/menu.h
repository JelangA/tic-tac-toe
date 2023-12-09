#if !defined(MENU_H)
#define MENU_H

#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

#include "menu.c"

int chooseBoard();
int chooseOpponent();
int mainMenu();
void InputNamaPemain(Player *p1, Player *p2);
void winner();

#endif // MENU_H