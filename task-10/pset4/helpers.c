#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    //iterate through each pixel
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Red = image[i][j].rgbtRed;
            int Blue = image[i][j].rgbtBlue;
            int Green = image[i][j].rgbtGreen;
            avg = round(((float)Red + (float)Blue + (float)Green) / 3);
            //declaring the avg of red, green, blue to each pixel of the image
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalBlue, originalGreen;
    int sepiaRed, sepiaBlue, sepiaGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalBlue = image[i][j].rgbtBlue;
            originalGreen = image[i][j].rgbtGreen;
            
            // calculate sepia Red and assign the new value
            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            
            // calculate sepia Blue and assign the new value
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            
            // calculate sepia Green and assign the new value
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // similar process of swaping
            // to swap a and b, we introduce variable c
            // c = a
            // a = b
            // b = c
            // same algorithm is used here
            int temp_red = image[i][j].rgbtRed;
            int temp_blue = image[i][j].rgbtBlue;
            int temp_green = image[i][j].rgbtGreen;
            
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            
            image[i][width - j - 1].rgbtRed = temp_red;
            image[i][width - j - 1].rgbtBlue = temp_blue;
            image[i][width - j - 1].rgbtGreen = temp_green;
            
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_Red, total_Blue, total_Green;
            total_Red = total_Blue = total_Green = 0;
            float counter = 0.00;

            //get the neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //check for valid neighbouring pexels
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    //Get the image value
                    total_Red += image[currentX][currentY].rgbtRed;
                    total_Green += image[currentX][currentY].rgbtGreen;
                    total_Blue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                //do the average of neigbhouring pixels
                temp[i][j].rgbtRed = round(total_Red / counter);
                temp[i][j].rgbtGreen = round(total_Green / counter);
                temp[i][j].rgbtBlue = round(total_Blue / counter);
            }
        }

    }

    //copy the blurr image to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
