#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // For every row
    for (int i = 0; i < height; i++)
    {
        // For every column
        for (int j = 0; j < width; j++)
        {
            // Get the color
            int greyscale =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtBlue = greyscale;
            image[i][j].rgbtGreen = greyscale;
            image[i][j].rgbtRed = greyscale;
        }
    }
}

// Check and return a value in RBG bounds
int rbgBound(double value)
{
    int num = round(value);
    if (value < 0)
    {
        return 0;
    }
    else if (value > 255)
    {
        return 255;
    }

    return num;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // For every row
    for (int i = 0; i < height; i++)
    {
        // For every column
        for (int j = 0; j < width; j++)
        {
            BYTE originalRed = image[i][j].rgbtRed;
            BYTE originalGreen = image[i][j].rgbtGreen;
            BYTE originalBlue = image[i][j].rgbtBlue;

            // Change the color
            image[i][j].rgbtRed =
                rbgBound((0.393 * originalRed) + (0.769 * originalGreen) + (0.189 * originalBlue));
            image[i][j].rgbtGreen =
                rbgBound((0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * originalBlue));
            image[i][j].rgbtBlue =
                rbgBound((0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // For every row
    for (int i = 0; i < height; i++)
    {
        // For every column
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
// Blur function
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Apply the blur effect
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            // Loop through neighboring pixels (3x3 grid)
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di; // Neighbor row index
                    int nj = j + dj; // Neighbor column index

                    // Check if the neighbor is within image bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumRed += copy[ni][nj].rgbtRed;
                        sumGreen += copy[ni][nj].rgbtGreen;
                        sumBlue += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Compute the average values
            image[i][j].rgbtRed = round((float)sumRed / count);
            image[i][j].rgbtGreen = round((float)sumGreen / count);
            image[i][j].rgbtBlue = round((float)sumBlue / count);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Weighted values
    int gx[3][3] = {
        { -1, 0, 1},
        { -2, 0, 2},
        { -1, 0, 1}
    };

    int gy[3][3] = {
        { -1, -2, -1},
        { 0, 0, 0},
        { 1, 2, 1}
    };

    // Copy orginal image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Detect Edges
    for (int i = 0; i < height; i++)
    {
        // For every column
        for (int j = 0; j < width; j++)
        {
            // Hold weighted values
            int gxRed = 0, gxGreen = 0, gxBlue = 0;
            int gyRed = 0, gyGreen = 0, gyBlue = 0;

            for (int ti = -1; ti <= 1; ti++)
            {
                for (int tj = -1; tj <= 1; tj++)
                {
                    // Neighbouring pixel
                    int ni = i + ti;
                    int nj = j + tj;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        // Sum of the weighted red pixles
                        gxRed += copy[ni][nj].rgbtRed * gx[ti + 1][tj + 1];
                        gyRed += copy[ni][nj].rgbtRed * gy[ti + 1][tj + 1];

                        // Sum of the weighted green pixels
                        gxGreen += copy[ni][nj].rgbtGreen * gx[ti + 1][tj + 1];
                        gyGreen += copy[ni][nj].rgbtGreen * gy[ti + 1][tj + 1];

                        // Sum of the weighted blue pixels
                        gxBlue += copy[ni][nj].rgbtBlue * gx[ti + 1][tj + 1];
                        gyBlue += copy[ni][nj].rgbtBlue * gy[ti + 1][tj + 1];
                    }
                }
            }

            // Change original image
            image[i][j].rgbtRed = rbgBound(sqrt(pow(gxRed, 2) + pow(gyRed, 2)));
            image[i][j].rgbtGreen = rbgBound(sqrt(pow(gxGreen, 2) + pow(gyGreen, 2)));
            image[i][j].rgbtBlue = rbgBound(sqrt(pow(gxBlue, 2) + pow(gyBlue, 2)));
        }
    }
}
