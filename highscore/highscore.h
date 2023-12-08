#if !defined(HIGHSCORE_H)
#define HIGHSCORE_H

#include "../player.h"
#include "highscore.c"
#include <stdio.h>

void tulisHighscore(Player pemain);

int hitungBarisFile();

void sortHighscore();

#endif // HIGHSCORE_H
