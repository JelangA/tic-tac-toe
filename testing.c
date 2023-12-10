#include <stdio.h>
#include <conio.h>

int main()
{
    char input;

    printf("Tekan Enter untuk keluar...\n");

    input = getch(); // Membaca satu karakter tanpa menunggu Enter
    if (input == '\r' || input == '\n')
    {
        printf("%d", input);
        printf("\nProgram berakhir.\n");
        return 0;
    }
        printf("salah.\n");
        return 0;
}
