void tulisHighscore(Player pemain)
{
    FILE *fptr;

    fptr = fopen("highscore.dat", "a+"); // variabel yang menampung nama file dan fungsi yang akan digunakan

    if (fptr == NULL) // program akan tertutup apabila file tidak ada
    {
        exit(1);
    }

    fprintf(fptr, "%s %d\n", pemain.nama, pemain.score); // menulis nama pemain dan jumlah score kedalam file
    fclose(fptr);
}

/* DESKRIPSI MODUL
Function
Modul ini bertujuan untuk mengembalikan nilai yang berisi banyak baris file highscore.dat
*/
int hitungBarisFile()
{
    FILE *fp;
    int count = 0; // Line counter (result)
    char filename[50] = "highscore.dat";
    char c; // To store a character read from file

    // Open the file
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // Close the file
    fclose(fp);

    return count;
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk mengurutkan nama pemain berdasarkan perolehan skor dari tertinggi ke terendah
I.S : Nama pemain berdasarkan perolehan skor belum terurut
F.S : Nama pemain berdasarkan perolehan skor terurut dari tertinggi
*/
void sortHighscore()
{
    FILE *fptr;
    int total_line = hitungBarisFile();
    Player pemain[total_line], temp;
    strcpy(temp.nama, "default");
    temp.score = 0;

    fptr = fopen("highscore.dat", "r"); // variabel yang menampung nama file dan fungsi yang akan digunakan
    // printf("total line = %d\n", total_line);

    if (fptr == NULL) // program akan tertutup apabila file tidak ada
    {
        exit(1);
    }
    int j = 0;
    while (fscanf(fptr, "%s %d\n", pemain[j].nama, &pemain[j].score) != EOF) // membaca nama pemain dan jumlah score dari file
    {
        j++;
    }
    fclose(fptr);
    for (int i = 0; i < total_line; i++)
    {
        for (int j = i + 1; j < total_line; j++)
        {
            if (strcmp(pemain[i].nama, pemain[j].nama) == 0)
            {
                pemain[i].score = pemain[i].score + pemain[j].score;
                for (int k = j; k < total_line; k++)
                {
                    pemain[k] = pemain[k + 1];
                }
                total_line--;
                j--;
            }
        }
    }
    for (int i = 0; i < total_line; i++)
    {
        for (int j = i + 1; j < total_line; j++)
        {
            if (pemain[i].score < pemain[j].score)
            {
                temp = pemain[i];
                pemain[i] = pemain[j];
                pemain[j] = temp;
            }
        }
    }

    fptr = fopen("highscore.dat", "w");

    for (int i = 0; i < total_line; i++)
    {
        fprintf(fptr, "%s %d\n", pemain[i].nama, pemain[i].score);
    }

    fclose(fptr);
}