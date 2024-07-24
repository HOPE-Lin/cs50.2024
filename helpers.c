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
            sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen =  round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaBlue =  round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
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
            p = width - j;
            tmp.rgbtRed = image[i][j].rgbtRed;
            tmp.rgbtGreen = image[i][j].rgbtGreen;
            tmp.rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][p].rgbtRed;
            image[i][j].rgbtGreen = image[i][p].rgbtGreen;
            image[i][j].rgbtBlue = image[i][p].rgbtBlue;
            image[i][p].rgbtRed = tmp.rgbtRed;
            image[i][p].rgbtGreen = tmp.rgbtGreen;
            image[i][p].rgbtBlue = tmp.rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int p = 0, red = 0, green = 0, blue = 0;
    RGBTRIPLE copy[height + 2][width + 2];
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || j ==0 || i == height + 1 || j == height + 1)
            {
                copy[i][j].rgbtRed = 0;
                copy[i][j].rgbtGreen = 0;
                copy[i][j].rgbtBlue = 0;

            }
            else
                copy[i][j] = image[i - 1][j - 1];
        }
    }
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            p = 0;
            red = 0;
            green = 0;
            blue = 0;
            for (int k = i - 1; k < i + 2;k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if(k != 0 && k != height + 1 && l != 0 && l != width + 1)
                    {
                        p++;
                        red += copy[k][l].rgbtRed;
                        green +=copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
            }
            image[i][j].rgbtRed = round(red / (double)p);
            image[i][j].rgbtGreen = round(green / (double)p);
            image[i][j].rgbtBlue = round(blue / (double)p);
        }
    }
    return;
}
