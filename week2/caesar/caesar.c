#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Function prototype
bool is_valid(string str);

int main(int argc, string argv[]) 
{
    // Validate program arguements
    if (argc != 2 || !is_valid(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    // Convert argv[1] from string to int
    int key = atoi(argv[1]) % 26;
    
    // Prompt the user for plaint text
    string text = get_string("Plaintext: ");

    // For eacher character in plain
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Get character
        char c = text[i];

        // Rotate the character if its a letter
        if (isupper(c)) {

           text[i] = (c - 'A' + key) % 26 + 'A';
        } 
        else if (islower(c))
        {

            text[i] = (c - 'a' + key) % 26 + 'a';
        }
    }

    // Output cipher
    printf("Cipher: %s\n", text);

    // Exit program
    return 0;
}

// Function to validate inputs are digits
bool is_valid(string str)
{
    // Validate every character
    for (int i = 0, len = strlen(str); i < len; i++)
    {
       if (!isdigit(str[i]))
       {
           return false;
       }
    }
    return true;
}
