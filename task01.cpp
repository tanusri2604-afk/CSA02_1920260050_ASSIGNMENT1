#include <stdio.h>

int main()
{
    int householdNo;
    int category;
    int previousReading, currentReading;
    int units;

    float energyCharge;
    float fixedCharge;
    float totalBill;

    const float RATE = 5.0;
    const float FIXED_CHARGE = 100.0;

    printf("Enter Household Number: ");
    scanf("%d", &householdNo);

    printf("Enter Category: ");
    scanf("%d", &category);

    printf("Enter Previous Reading: ");
    scanf("%d", &previousReading);

    printf("Enter Current Reading: ");
    scanf("%d", &currentReading);

    /* Validation */
    if (previousReading < 0 || currentReading < 0)
    {
        printf("Invalid meter reading.\n");
        return 0;
    }

    if (currentReading < previousReading)
    {
        printf("Invalid reading: Current reading cannot be less than previous reading.\n");
        return 0;
    }

    units = currentReading - previousReading;
    energyCharge = units * RATE;
    fixedCharge = FIXED_CHARGE;
    totalBill = energyCharge + fixedCharge;

    /* Display bill */
    printf("\n----- ELECTRICITY BILL -----\n");
    printf("Household Number : %d\n", householdNo);
    printf("Category         : %d\n", category);
    printf("Previous Reading : %d\n", previousReading);
    printf("Current Reading  : %d\n", currentReading);
    printf("Units Consumed   : %d\n", units);
    printf("Energy Charge    : %.2f\n", energyCharge);
    printf("Fixed Charge     : %.2f\n", fixedCharge);
    printf("Total Bill       : %.2f\n", totalBill);

    return 0;
}