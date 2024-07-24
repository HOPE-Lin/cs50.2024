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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    int p;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            p = width - j - 1;
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
            if (i == 0 || j == 0 || i == height + 1 || j == width + 1)
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
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k != 0 && k != height + 1 && l != 0 && l != width + 1)
                    {
                        p++;
                        red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
            }
            image[i - 1][j - 1].rgbtRed = round(red / (double) p);
            image[i - 1][j - 1].rgbtGreen = round(green / (double) p);
            image[i - 1][j - 1].rgbtBlue = round(blue / (double) p);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int redx = 0, greenx = 0, bluex = 0, redy = 0, greeny = 0, bluey = 0;
    int gx[3][3] = {{-1, 0 , 1}, {-2, 0, 2}, {-1, 0, 1}};
    RGBTRIPLE copy[height + 2][width + 2];
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || j == 0 || i == height + 1 || j == width + 1)
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
            redx = 0;
            greenx = 0;
            bluex = 0;
            redy = 0;
            greeny = 0;
            bluey = 0;
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    redx += copy[k][l].rgbtRed * gx[k - i + 1][k - l + 1];
                    greenx += copy[k][l].rgbtGreen * gx[k - i + 1][k - l + 1];
                    bluex += copy[k][l].rgbtBlue * gx[k - i + 1][k - l + 1];
                    redy += copy[k][l].rgbtRed * gx[k - l + 1][k - i + 1];
                    greeny += copy[k][l].rgbtGreen * gx[k - l + 1][k - i + 1];
                    bluey += copy[k][l].rgbtBlue * gx[k - l + 1][k - i + 1];
                }
            }
            redx = round(sqrt((redx / 9.0) * (redx / 9.0) + (redy / 9.0) * (redy / 9.0)));
            greenx = round(sqrt((greenx / 9.0) * (greenx / 9.0) + (greeny / 9.0) * (greeny / 9.0)));
            bluex = round(sqrt((bluex / 9.0) * (bluex / 9.0) + (bluey / 9.0) * (bluey / 9.0)));
            if (redx > 255)
                redx = 255;
            if (greenx > 255)
                greenx = 255;
            if (bluex > 255)
                bluex = 255;
           image[i - 1][j - 1].rgbtRed = redx;
           image[i - 1][j - 1].rgbtGreen = greenx;
           image[i - 1][j - 1].rgbtBlue = bluex;
        }
    }
    return;
}
