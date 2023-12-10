void InputNamaPemain(Player *p1, Player *p2, char **currmenu)
{
    printf("Masukkan Nama Pemain 1 (X) : ");
    scanf(" %[^\n]", &p1->nama);
    printf("Masukkan Nama Pemain 2 (O) : ");
    scanf(" %[^\n]", &p2->nama);
    bool invalid = false;
    for (int i = 0; i < strlen(p1->nama); i++)
    {
        if (isspace(p1->nama[i]) != 0) // terdapat spasi pada input nama, sehingga nama tidak valid
        {
            invalid = true;
        }
    }
    for (int i = 0; i < strlen(p2->nama); i++)
    {
        if (isspace(p2->nama[i]) != 0)
        {
            invalid = true;
        }
    }
    if (strlen(p1->nama) >= 12 || strlen(p2->nama) >= 12 || invalid == true)
    {
        printf("\n\t\t\tMaksimal Nama Pemain Adalah 12 Karakter Tanpa Spasi...");
        getch();
        system("cls");
        // InputNamaPemain(p1, p2);
    }
    *currmenu = "playgame";
}

int chooseBoard()
{
    int chSize;
    printf("Choose the board size : \n1. 3x3\n2. 5x5\n3. 7x7\n");
    do
    {
        printf("Choose :");
        scanf("%d", &chSize);
        if (chSize == 1 || chSize == 2 || chSize == 3)
        {
            switch (chSize)
            {
            case 1:
                size = 3;
                break;

            case 2:
                size = 5;
                break;

            case 3:
                size = 7;
                break;
            }
        }
        else
        {
            printf("Invalid board size. Please choose 1, 2, or 3.\n");
        }
    } while (chSize != 1 && chSize != 2 && chSize != 3);

    return 0;
}
int chooseOpponent(char **currmenu)
{
    do
    {
        printf("Choose your opponent : \n1. Player vs Player\n2. Player vs BOT\nChoose : ");
        scanf("%d", &opponent);
        if (opponent != 1 && opponent != 2)
        {
            printf("Invalid Choice Please choose just two if them.\n");
        }
    } while (opponent != 1 && opponent != 2);
    system("CLS");

    *currmenu = "inputNama";
}
int mainMenu(char **curmenu)
{
    printf("Welcome to Tic Toe Game\n");
    printf("1. Play Game\n2. Exit the game\n");
    do
    {
        printf("Choose :");
        scanf("%d", &start);
        if (start == 1)
        {
            *curmenu = "oponent";
        }
        else if (start == 2)
        {
            *curmenu = "exit";
        }
        else
        {
            printf("Please choose just between of them\n");
        }
    } while (start != 1 && start != 2);
    system("cls");
}

void PlayGame(char **currmenu)
{
    int row, col;
    symbolX = 'X';
    symbolO = 'O';
    currentNamePlayer = player1.nama;
    currentPlayer = symbolX;
    time_t waktu = time(NULL); // variabel yang berisi waktu saat modul dijalankan
    if (opponent == 1)
    {
        chooseBoard();
        system("CLS");
        initializeBoard(); 

        do
        {
            printBoard();
            time_t waktu = time(NULL); // variabel yang berisi waktu saat modul dijalankan
            // Input and move validation
            do
            {

                printf("Player %s, enter your move : \n", currentNamePlayer);
                printf("your row : ");
                scanf("%d", &row);
                printf("your collumn : ");
                scanf("%d", &col);
                row--;
                col--;

            } while (!isMoveValid(row, col));

            time_t waktugiliran = time(NULL);
            if (waktugiliran - waktu >= 10)
            {
                printf("!!!!!Waktu Habis!!!!!");
                printf("\n\tTekan Enter Untuk Lanjut..\n");
                time_t waktugiliran = time(NULL);
                getch();
            }
            else
            {
                board[row][col] = currentPlayer;
            }

            if (checkWin(currentPlayer, size))
            {
                printBoard();
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
            currentNamePlayer = (currentNamePlayer == player1.nama) ? player2.nama : player1.nama;

        } while (1);
        system("cls");

        *currmenu = "result";
    }
    else if (opponent == 2)
    {
        chooseBoard();
    }
}

void resultMenu(char **currmenu)
{
    int choise;
    if (currentNamePlayer == player1.nama)
    {
        player1.score = player1.score + 1;
    }
    else if (currentNamePlayer == player2.nama)
    {
        player2.score = player2.score + 1;
    }
    printf("    Result\n");
    printf("%s = %d kali menang\n%s = %d kali menang\n", player1.nama, player1.score, player2.nama, player2.score);
    printf("Ulangi permainan ? \n 1. Ya \n 2. Tidak\n");
    printf("Input : ");
    scanf("%d", &choise);
    printf("%d", choise);
    *currmenu = (choise == 1) ? "playgame" : "winner";
}

void winmenu(char **currmenu)
{
    printf("%s wins!\n", currentNamePlayer);
    tulisHighscore(player1);
    tulisHighscore(player2);
    sortHighscore();
    *currmenu = "home";
    char input;

    printf("Tekan Enter untuk keluar...\n");

    input = getch();
    if (input == '\r' || input == '\n')
    {
        printf("%d", input);
        printf("\nProgram berakhir.\n");
        // return 0;
    }
}
