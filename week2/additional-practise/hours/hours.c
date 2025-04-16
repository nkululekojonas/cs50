#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);
int sumof(int hour[], int weeks);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Calculate hours
float calc_hours(int hours[], int weeks, char output)
{
    if (output == 'T')
    {
        return sumof(hours, weeks);
    }
    else if (output, 'A')
    {
        return (float)sumof(hours, weeks) / weeks;
    }
}

int sumof(int hours[], int weeks)
{
    int total = 0;
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }
    return total;
}
