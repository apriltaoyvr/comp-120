#include <stdio.h>

int main(void) {
    char name[26];
    int cups_per_day;
    float price_per_cup;

    int days_per_month = 30;
    int months_per_year = 12;

    float monthly_cost;
    double yearly_cost;
    
    printf("What is your name: ");
    scanf("%s", name);

    printf("Enter how many cups of coffee you drink per day: ");
    scanf("%d", &cups_per_day);
    
    printf("Enter the price per cup: ");
    scanf("%f", &price_per_cup);

    monthly_cost = cups_per_day * price_per_cup * days_per_month;
    yearly_cost = monthly_cost * 12;
    
    printf("Hey %s! You drink %d cups of coffee per day.\n", name, cups_per_day);
    printf("Your monthly cost on coffee is %.2lf.\n", monthly_cost);
    printf("Your yearly cost on coffee is %.2lf.\n", yearly_cost);


    return 0;
}