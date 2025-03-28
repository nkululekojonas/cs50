#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Mapping by index of Letters A -> Z to letter score
const int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

// Function prototype
int score(string word);
int char_score(char letter);

int main(void)
{
    // Get user input
    string first_word = get_string("Player 1: ");
    string second_word = get_string("Player 2: ");

    // Calcuate score for first word
    int score_1 = score(first_word);

    // Calcuate score for second word
    int score_2 = score(second_word);

    // Determine winner based on score
    if (score_1 != score_2)
    {
        string winner = (score_1 > score_2) ? "Player 1" : "Player 2";
        printf("%s wins!\n", winner);
        printf("Player 1: %i\nPlayer 2: %i", score_1, score_2);
        return 0;
    }

    // Print Tie
    printf("Tie!\n");

    // Successfull
    return 0;
}

int score(string word)
{
    // Decalre score
    int total = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // If character is a alphaberic determine score
        if (isalpha(word[i]))
        {
            // non alphabetic character move on to next letter
            total += char_score(toupper(word[i]));
        }
    }

    // Return score
    return total;
}

// Given a character return the scarrble score
int char_score(char letter)
{
    return scores[letter - 'A'];
}