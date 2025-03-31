#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

bool is_jpeg(uint8_t file[])
{
    return (file[0] == 0xff) && (file[1] == 0xd8) && (file[2] == 0xff) && ((file[3] & 0xf0) == 0xe0);
}

int main(int argc, char *argv[])
{
    // Validate inputs
    if (argc != 2)
    {
        printf("Usage: %s inpufile\n", argv[0]);
        return 1;
    }

    // Open file
    char *input_filename = argv[1];

    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = NULL;
    if (input_file == NULL)
    {
        printf("Usage: %s inputfile\n", argv[0]);
        return 1;
    }

    // Define buffers
    char output_filename[8]; // i.e 001 .jpg
    uint8_t buffer[BLOCK_SIZE];

    int image_count = 0;

    // Read until I cant read BLOCK_SIZE
    while (fread(buffer, BLOCK_SIZE, 1, input_file) == 1)
    {
        if (is_jpeg(buffer))
        {
            if (output_file != NULL)
            {
                fclose(output_file);
            }
            // Create a new image
            sprintf(output_filename, "%03i.jpg", image_count);
            output_file = fopen(output_filename, "w");

            if (output_file == NULL)
            {
                fclose(input_file);
                return 1;
            }

            image_count++;
        }

        if (output_file != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
