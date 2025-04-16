#include <cs50.h>
#include <stdio.h>

// Function Prototype
char *replace(char *str);

int main(int argc, string argv[])
{
    // Check if exactly once command-line argument was provided
    if (argc != 2)
    {
        printf("Usage: %s word\n", argv[0]);
        return 1;
    }
    
    // Get the word from the command-line 
    char *input_word = argv[1];

    // Replace vowels in input word
    char *replaced_word = replace(input_word);

    // Print out replaced word
    printf("%s\n", replaced_word);

    // Successfull execution 
    return 0;
}

char *replace(char *str)
{
    // Iterate through str replacing instances of vowels with numbers
    for (char *c = str; *c != '\0'; c++)
    {
        // Check the character currently pointed to by c
        switch (*c)
        {
            case 'a':
            case 'A': // Optional: Handle uppercase 'A' as well
                *c = '6';
                break;
            case 'e':
            case 'E': // Optional: Handle uppercase 'E'
                *c = '3';
                break;
            case 'i':
            case 'I': // Optional: Handle uppercase 'I'
                *c = '1';
                break;
            case 'o':
            case 'O': // Optional: Handle uppercase 'O'
                *c = '0';
                break;
                // Note: 'u' is often replaced with '|_|' or similar in leetspeak,
                // but sticking to the original code's replacements.
            default:
                // Do nothing if the character is not one of the targeted vowels
                break;
        }
    }

    // Return the pointer to the beginning of the (now modified) string
    return str;
}
