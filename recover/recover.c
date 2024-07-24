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
    char filename[4];
    FILE *img;
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", i);
            *img = fopen(filename, "w");
            fwrite(buffer, 1 , 512, img);
            i++;
            fclose(img);
        }
        else
        {
            fopen(img, "w");
            fwrite(buffer, 1 , 512, img);
            fclose(img);
        }
    }
    fclose(card);
}
