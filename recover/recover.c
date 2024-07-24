#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("");
        return 1;
    }
    uint8_t buffer[512];
    int i = 0;
    char* filename[4];
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", i);
            fopen(filename, "w");
            fwrite(buffer, 1 , 512, filename);
            i++;
            fclose(filename);
        }
        else
        {
            fopen(filename, "w');
            fwrite(buffer, 1 , 512, filename);
            fclose(filename);
        }
    }
    fclose(card);
}
