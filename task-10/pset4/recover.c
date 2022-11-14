#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }
    //Open file for reading
    FILE *infile = fopen(argv[1], "r");
    
    if (infile == NULL)
    {
        printf("Could not open file");
        return 2;
    }
    
    unsigned char buffer[512];

    int count = 0;

    //An uninitialize file pointer to use to output data gotten from input file
    FILE *outfile = NULL;

    char *file = malloc(8 * sizeof(char));
    //char filename[8];

    /*Read 512 bytes from input_file and store on the buffer*/
    while (fread(buffer, sizeof(char), 512, infile))
    {
        //check if bytes is start of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(file, "%03i.jpg", count);

            //open Out_file for writing
            outfile = fopen(file, "w");
            
            //count number of image found
            count++;
        }
        //Check if output have been used for valid input
        if (outfile != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outfile);
        }

    }
    free(file);
    fclose(outfile);
    fclose(infile);

    return 0;
}

