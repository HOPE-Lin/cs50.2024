#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int p = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            p = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = p;
            image[i][j].rgbtBlue = p;
            image[i][j].rgbtGreen = p;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaBlue = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen =  round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaRed =  round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
                sepiaBlue = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaRed > 255)
                sepiaRed = 255;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    int p;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            p = width - 1;
            tmp.rgbtRed = image[i][j].rgbtRed;
            tmp.rgbtGreen = image[i][j].rgbtGreen;
            tmp.rbhtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][p].rgbtRed;
            image[i][j].rgbtGreen = image[i][p].rgbtGreen;
            image[i][j].rgbtBlue = image[i][p].rgbtBlue;
            image[i][p].rgbtRed = tmp.rgbtRed;
            image[i][p].rgbtGreen = tmp.rghtGreen;
            image[i][p].rgbtBlue = tmp.rghtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int p = 0;
    RGBTRIPLE copy[height + 2][width + 2] = {0};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i + 1][j + 1] = image[i][j];
        }
    }
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            p = copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed
                copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed;
                copy[i][j].rgbtRed = round(p);
            p = copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtRGreen + copy[i - 1][j + 1].rgbtRGreen +
                copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen
                copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen;
                copy[i][j].rgbtGreen = round(p);
            p = copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue
                copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue;
                copy[i][j].rgbtBlue = round(p);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i + 1][j + 1];
        }
    }
    return;
}
