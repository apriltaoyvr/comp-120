#include <stdio.h>

int main(void) {
    char name[26] = "Frank";       // Stores your name in a variable
    char size = 'M';               // Stores your cup size as a single character 'S', 'M', or 'L'
    float price_per_cup = 3.2f;    // Price for a medium ('M') cup (this should allow decimals!)
    int cups_per_day = 2;          // Stores the number of cups of coffee you drink per day
    int days_per_month = 30;       // Assume there are 30 days in a month
    int months_per_year = 12;

    float monthly_cost = cups_per_day * price_per_cup * days_per_month;
    double yearly_cost = monthly_cost * 12;

    // TODO: print info to match the sample run below
    printf("Hello, %s! Thanks for participating.\n", name);
    printf("You drink %d cups of size %c coffee per day.\n", cups_per_day, size);
    printf("Your monthly cost on coffee is %.2lf.\n", monthly_cost);
    printf("Your yearly cost on coffee is %.2lf.\n", yearly_cost);


    return 0;
}