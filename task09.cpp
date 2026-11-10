#include <stdio.h>

#define MAX_READING 65535U
#define FIXED_CHARGE 5000L

int calculate_units(unsigned int previous,unsigned int current,unsigned int *units)
{
    if (previous > MAX_READING || current > MAX_READING)
        return 0;

    if (current >= previous)
        *units = current - previous;
    else if (previous >= 65000U && current <= 535U)
        *units = (MAX_READING - previous) + 1U + current;
    else
        return 0;

    return 1;
}

long calculate_bill(unsigned int units)
{
    long energy_charge = 0;

    if (units <= 100)
        energy_charge = 0;

    else if (units <= 200)
        energy_charge = (units - 100) * 225L;

    else
        energy_charge = 100 * 225L +
                        (units - 200) * 450L;

    return energy_charge + FIXED_CHARGE;
}

int main(void)
{
    unsigned int previous, current, units;
    long bill;

    printf("Enter previous reading: ");

    if (scanf("%u", &previous) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter current reading: ");

    if (scanf("%u", &current) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    if (!calculate_units(previous, current, &units))
    {
        printf("Invalid meter readings or rollover!\n");
        return 1;
    }

    bill = calculate_bill(units);

    printf("\n----- ELECTRICITY BILL -----\n");
    printf("Previous Reading : %u\n", previous);
    printf("Current Reading  : %u\n", current);
    printf("Units Consumed   : %u\n", units);

    printf("Total Bill       : Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}