void InputNamaPemain(Player *p1, Player *p2)
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
        InputNamaPemain(p1, p2);
    }
}

int chooseBoard()
{
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

void PlayGame(char **currmenu){
     int row, col;
    symbolX = 'X';
    symbolO = 'O';
    char currentPlayer = symbolX;
    char *currentNamePlayer = player1.nama;
    if (opponent == 1)
    {
        chooseBoard();
        system("CLS");
        initializeBoard();

        do
        {
            printBoard();
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

            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer, size))
            {
                printBoard();
                printf("Player %s wins!\n", currentNamePlayer);
                
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
        *currmenu = "exit"; 
    }
    else if (opponent == 2)
    {
        chooseBoard();
    }
}
