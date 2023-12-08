#include "../menu/menu.h"

char board[7][7];

/*
Deskripsi Modul:
Modul ini berfungsi untuk menginisialisasi papan permainan Tic-Tac-Toe dengan mengisi seluruhnya dengan spasi kosong.
I.S.: Papan belum diinisialisasi
F.S.: Papan diisi dengan spasi kosong
*/
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

/*
Deskripsi Modul:
Modul ini mencetak keadaan terkini papan permainan Tic-Tac-Toe ke konsol.
*/
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

/*
Deskripsi Modul:
Modul ini memeriksa apakah sebuah gerakan pada baris dan kolom tertentu valid.
Input: baris dan kolom
Output: 1 jika gerakan valid, 0 jika tidak valid
*/
int isMoveValid(int row, int col)
{
    // Memeriksa apakah posisi yang ditentukan berada dalam batas papan dan masih kosong.
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
                return 0; //papan masih belum penuh
            }
        }
    }
    return 1; // Papannya penuh coy
}

/*
Deskripsi Modul:
Modul ini memeriksa apakah terdapat kemenangan berdasarkan simbol dan ukuran papan yang ditentukan.
Input: simbol pemain, ukuran papan
Output: 1 jika terdapat kemenangan, 0 jika tidak
*/
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
            return 1; // Win
        }

        return 0;
    }

    case 5:
    {
        // Check rows and columns
        for (int i = 0; i < size; i++)
        {
            int rowWin = 0;
            int colWin = 0;
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == symbol)
                {
                    rowWin++;
                }
                if (board[j][i] == symbol)
                {
                    colWin++;
                }
            }
            if (rowWin >= 4 || colWin >= 4)
            {
                return 1; // Win
            }
        }

        // Check diagonals
        int diag1Win = 0;
        int diag2Win = 0;
        for (int i = 0; i < size; i++)
        {
            if (board[i][i] == symbol)
            {
                diag1Win++;
            }
            if (board[i][size - 1 - i] == symbol)
            {
                diag2Win++;
            }
        }
        if (diag1Win >= 4 || diag2Win >= 4)
        {
            return 1; // Win
        }

        return 0;
    }

    case 7:
    {
        // Check rows and columns
        for (int i = 0; i < size; i++)
        {
            int rowWin = 0;
            int colWin = 0;
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == symbol)
                {
                    rowWin++;
                }
                if (board[j][i] == symbol)
                {
                    colWin++;
                }
            }
            if (rowWin >= 5 || colWin >= 5)
            {
                return 1; // Win
            }
        }

        // Check diagonals
        int diag1Win = 0;
        int diag2Win = 0;
        for (int i = 0; i < size; i++)
        {
            if (board[i][i] == symbol)
            {
                diag1Win++;
            }
            if (board[i][size - 1 - i] == symbol)
            {
                diag2Win++;
            }
        }
        if (diag1Win >= 5 || diag2Win >= 5)
        {
            return 1; // Win
        }

        return 0;
    }
    }

    return 0;
}
