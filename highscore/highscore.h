#if !defined(HIGHSCORE_H)
#define HIGHSCORE_H

#include "../player.h"
#include "highscore.c"

void tulisHighscore(Player pemain);
int hitungBarisFile();
void sortHighscore();
void displayHighscores();

#endif // HIGHSCORE_H