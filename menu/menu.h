#if !defined(MENU_H)
#define MENU_H

#include "menu.c"
#include "../player.h"

int chooseBoard();
int chooseOpponent();
int mainMenu();
void InputNamaPemain(Player *p1, Player *p2);

#endif // MENU_H