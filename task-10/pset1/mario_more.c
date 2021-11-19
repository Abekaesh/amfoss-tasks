#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    int i;
    int j;
    int h;
    
    // Prompt user to give height in between 1 and 8 , also inclusive
    do
    {
        h = get_int("Height : ");

    }
    while (!((h >= 1) & (h <= 8)));
    
    // Making rows
    
    for (i = 0; i < h; i++)
    {
        // Making columns
        
        for (j = 0; j < h ; j++)
        {
            if ((i + j) <= (h - 2))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (j = 0; j < h; j++)
        {
            if ((i + j) >= (h - 1))
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
