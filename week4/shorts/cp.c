#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Validate inputs
    if (argc < 3)
    {
        printf("Usage: %s source_file ... target_file\n", argv[0]);
        return 1;
    }

    // Open the last file to write to 
    char *target_filename = argv[argc - 1];
    FILE *target_file = fopen(target_filename, "w");
    if (!target_file)
    {
        perror("Error opening file");
        return 1;
    }

    // Iterate over every file
    for (int i = 1; i < argc - 1; i++)
    {
        // Set filename
        char *source_filename = argv[i];

        // Skip matching files
        if (strcmp(source_filename, target_filename) == 0)
        {
            fprintf(stderr, "Warning: Skipping destination file as source: %s\n", source_filename);
            continue;
        }

        // Skip bad files
        FILE *source_file = fopen(source_filename, "r");
        if (!source_file)
        {
            fprintf(stderr, "Error opening source file: %s. Skipping.\n", source_filename);
            perror("Error opening file");
            return 2;
        }
        
        char ch;
        while ((ch = fgetc(source_file)) != EOF)
        {
            if(fputc(ch, target_file) == EOF)
            {
                perror("Error writing to destination file");
                fclose(source_file);
                fclose(target_file);
                return 1;
            }
        }
        fclose(source_file);
    }

    // Close file
    fclose(target_file);
    return 0;
}
