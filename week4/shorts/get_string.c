#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Get a string
char* get_string(const char *prompt)
{
    // Display the prompt
    printf("%s", prompt);

    // Initialise a buffer
    size_t buffer_size = 16;
    char *buffer = malloc(buffer_size);

    if (!buffer)
    {
        // Return null if mem allocation fails
        return NULL;
    }

    // Track the lenght
    size_t length = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // If we out grow out buffer
        if (length + 1 >= buffer_size)
        {
            buffer_size *= 2;
            char *temp = realloc(buffer, buffer_size);
            if (!temp)
            {
                return NULL; // Unable to get more memory
            }

            buffer = temp;
        }
        buffer[length++] = ch;
    }

    // Terminate the string
    buffer[length] = '\0';

    return buffer;
}

int main(void)
{
    char *name = get_string("Enter a name: ");
    if (name)
    {
        printf("Hello, %s!\n", name);
        free(name);
        return 0;
    }
    
    printf("Hello, World!");
    return 0;
}
