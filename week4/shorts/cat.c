#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Validate inputs
    if (argc < 2)
    {
        printf("Usage: %s [ filename ... ]\n", argv[0]);
        return 1;
    }

    // Iterate over every file
    for (int i = 1; i < argc; i++)
    {
        // Open for reading
        FILE *file = fopen(argv[i], "r");
        if (!file)
        {
            printf("Unable to open file %s\n", argv[i]);
            return 2;
        }
        
        char ch;
        while ((ch = fgetc(file)) != EOF)
        {
            printf("%c", ch);
        }
        fclose(file);
    }
    return 0;
}
