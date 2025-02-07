#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototype
int average(string text);

int main()
{
    // Prompt the user for input
    string text = get_string("Text: ");

    // Caulcate grade
    int index = average(text);

    // Check grade bounds
    if (index < 1 ) 
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

// Calulcate grade
int average(string text)
{
    // Keep count of end of sentences
    int words = 1;
    int letters = 0;
    int sentences = 0;

    // Count the number of letter in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        } 
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    // Calculate grade
    float l = (letters / (float) words ) * 100.0;
    float s = (sentences / (float) words ) * 100.0;

    return round(0.0588 * l - 0.296 * s - 15.8);
}
