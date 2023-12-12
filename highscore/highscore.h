#if !defined(HIGHSCORE_H)
#define HIGHSCORE_H

#include "highscore.c"

void tulisHighscore(Player pemain);
int hitungBarisFile();
void sortHighscore();
void displayHighscores();
void clearPlayer(Player *player);

#endif // HIGHSCORE_H
