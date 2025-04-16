#include <cs50.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Validity function 
bool valid(string password)
{
    bool is_upper = false;
    bool is_lower = false;

    bool is_num = false;
    bool is_sym = false;

    for (char *c = password; *c != '\0'; c++)
    {
        if (*c >= 48 && *c <= 57)
        {
            is_num = true;
        }
        else if (*c >= 65 && *c <= 90)
        {
            is_upper = true;
        }
        else if (*c >= 97 && *c <= 122)
        {
            is_lower = true;
        }
        else if (*c >= 33 && *c <= 47)
        {
            is_sym = true;
        }
    }
    return is_upper && is_lower && is_num && is_sym;
}
