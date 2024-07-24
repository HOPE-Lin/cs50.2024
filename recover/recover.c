#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == null)
    {
        printf("");
        return 1;
    }
    uint8_t buffer[512];
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[1] == 0xff && buffer[2] == 0xd8 && bufffer[3] == 0xff && (buffer[4] & 0xe0) == 0xe0)
        {
            
        }
    }
}
