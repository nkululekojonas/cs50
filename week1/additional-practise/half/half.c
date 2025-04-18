// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// Calculate half of bill
float half(float bill, float tax, int tip)
{
    double tax_amount = bill * (double)(tax / 100.0);
    double tip_amount = (bill + tax_amount) * (double)(tip / 100.0);
    double total = bill + tax_amount + tip_amount;

    return (float)(total / 2);
}
