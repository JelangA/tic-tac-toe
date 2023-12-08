char board[7][7];
int size;

void initializeBoard()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < size - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < size - 1)
        {
            for (int k = 0; k < size - 1; k++)
            {
                printf("----");
            }
            printf("--\n");
        }
    }
    printf("\n");
}

int isMoveValid(int row, int col)
{
    return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ';
}

int isBoardFull()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1; // Papannya penuh coy
}

int checkWin(char symbol, int size)
{
    switch (size)
    {
    case 3:
    {
        // Check rows and columns
        for (int i = 0; i < size; i++)
        {
            int rowWin = 1;
            int colWin = 1;
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] != symbol)
                {
                    rowWin = 0;
                }
                if (board[j][i] != symbol)
                {
                    colWin = 0;
                }
            }
            if (rowWin || colWin)
            {
                return 1; // Win
            }
        }

        // Check diagonals
        int diag1Win = 1;
        int diag2Win = 1;
        for (int i = 0; i < size; i++)
        {
            if (board[i][i] != symbol)
            {
                diag1Win = 0;
            }
            if (board[i][size - 1 - i] != symbol)
            {
                diag2Win = 0;
            }
        }
        if (diag1Win || diag2Win)
        {
            return 1;
        }

        return 0;
    }

    case 5:
    {
        // Check rows and columns
        for (int i = 0; i < size - 1; i++)
        {
            int rowWin = 1;
            int colWin = 1;
            for (int j = 0; j < size - 1; j++)
            {
                if (board[i][j] != symbol)
                {
                    rowWin = 0;
                }
                if (board[j][i] != symbol)
                {
                    colWin = 0;
                }
            }
            if (rowWin || colWin)
            {
                return 1; // Win
            }
        }

        // Check diagonals
        int diag1Win = 1;
        int diag2Win = 1;
        for (int i = 0; i < size - 1; i++)
        {
            if (board[i][i] != symbol)
            {
                diag1Win = 0;
            }
            if (board[i][size - 1 - i] != symbol)
            {
                diag2Win = 0;
            }
        }
        if (diag1Win || diag2Win)
        {
            return 1;
        }

        return 0;
    }

    case 7:
    {
        // Check rows and columns
        for (int i = 0; i < size - 2; i++)
        {
            int rowWin = 1;
            int colWin = 1;
            for (int j = 0; j < size - 2; j++)
            {
                if (board[i][j] != symbol)
                {
                    rowWin = 0;
                }
                if (board[j][i] != symbol)
                {
                    colWin = 0;
                }
            }
            if (rowWin || colWin)
            {
                return 1; // Win
            }
        }

        // Check diagonals
        int diag1Win = 1;
        int diag2Win = 1;
        for (int i = 0; i < size - 2; i++)
        {
            if (board[i][i] != symbol)
            {
                diag1Win = 0;
            }
            if (board[i][size - 1 - i] != symbol)
            {
                diag2Win = 0;
            }
        }
        if (diag1Win || diag2Win)
        {
            return 1;
        }

        return 0;
    }
    }

    return 0;
}
