#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "highscore.h"
#include "player.h"

int main(int argc, char const *argv[])
{
    Player player;
    strcpy(player.nama, "bamkong");
    player.score = 12;
    tulisHighscore(player);
    sortHighscore();
    return 0;
}

