#include <stdio.h>

#define FIXED_CHARGE 5000L
#define RATE1 0
#define RATE2 225
#define RATE3 450

long calculate_bill(int units)
{
    long energy_charge = 0;

    if (units <= 100)
        energy_charge = units * RATE1;

    else if (units <= 200)
        energy_charge = 100 * RATE1 +
                        (units - 100) * RATE2;

    else
        energy_charge = 100 * RATE1 +
                        100 * RATE2 +
                        (units - 200) * RATE3;

    return energy_charge + FIXED_CHARGE;
}

int main(void)
{
    int units;
    long bill;

    printf("Enter electricity units: ");

    if (scanf("%d", &units) != 1 || units < 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    bill = calculate_bill(units);

    printf("Energy Bill = Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}