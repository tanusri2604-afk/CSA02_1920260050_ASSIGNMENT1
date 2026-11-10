#include <stdio.h>

int main()
{
    int household_number;
    unsigned int previous, current, units;
    char category[30];

    long energy_charge, fixed_charge = 5000L;
    long total_bill;

    printf("Enter household number: ");
    if (scanf("%d", &household_number) != 1)
    {
        printf("Invalid household number!\n");
        return 1;
    }

    printf("Enter category: ");
    if (scanf("%29s", category) != 1)
    {
        printf("Invalid category!\n");
        return 1;
    }

    printf("Enter previous reading: ");
    if (scanf("%u", &previous) != 1)
    {
        printf("Invalid previous reading!\n");
        return 1;
    }

    printf("Enter current reading: ");
    if (scanf("%u", &current) != 1)
    {
        printf("Invalid current reading!\n");
        return 1;
    }

    if (previous > 65535 || current > 65535)
    {
        printf("Invalid meter reading!\n");
        return 1;
    }

    units = (current - previous) & 65535U;

    if (units <= 100)
        energy_charge = 0;
    else if (units <= 200)
        energy_charge = (units - 100) * 225L;
    else
        energy_charge = 100 * 225L +(units - 200) * 450L;

    total_bill = energy_charge + fixed_charge;

    printf("\n----- ELECTRICITY BILL -----\n");
    printf("Household Number : %d\n", household_number);
    printf("Category         : %s\n", category);
    printf("Units Consumed   : %u\n", units);

    printf("Energy Charge    : Rs %ld.%02ld\n",
           energy_charge / 100,
           energy_charge % 100);

    printf("Fixed Charge     : Rs %ld.%02ld\n",
           fixed_charge / 100,
           fixed_charge % 100);

    printf("Total Bill       : Rs %ld.%02ld\n",
           total_bill / 100,
           total_bill % 100);

    return 0;
}