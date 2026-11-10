#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX_READINGS 35040
#define DIVISOR 100000ULL

int main()
{
    FILE *fp;
    uint64_t rate, fixed_charge;
    uint64_t total_wh = 0;
    uint64_t cost = 0;
    uint64_t energy_charge, total_bill;

    uint32_t wh;
    int n, hour;

    /* Create tariff file if it does not exist */
    fp = fopen("tariff.txt", "r");

    if (fp == NULL)
    {
        fp = fopen("tariff.txt", "w");

        if (fp == NULL)
        {
            printf("Cannot create tariff file!\n");
            return 1;
        }

        fprintf(fp, "300 5000\n");
        fclose(fp);

        fp = fopen("tariff.txt", "r");
    }

    /* Read tariff values */
    if (fscanf(fp, "%" SCNu64 " %" SCNu64,
               &rate, &fixed_charge) != 2)
    {
        printf("Invalid tariff file!\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);

    printf("SMART METER BILLING SYSTEM\n");

    printf("Enter number of readings: ");

    if (scanf("%d", &n) != 1 ||
        n < 1 || n > MAX_READINGS)
    {
        printf("Invalid number of readings!\n");
        return 1;
    }

    /* Process meter readings */
    for (int i = 0; i < n; i++)
    {
        printf("Enter watt-hours and hour: ");

        if (scanf("%" SCNu32 " %d", &wh, &hour) != 2 ||
            wh > 1000000 || hour < 0 || hour > 23)
        {
            printf("Invalid input!\n");
            return 1;
        }

        total_wh += wh;

        /* Peak hours: 6 PM to 10 PM */
        if (hour >= 18 && hour < 22)
        {
            cost += (uint64_t)wh * rate * 120;
        }
        else
        {
            cost += (uint64_t)wh * rate * 100;
        }
    }

    /* Calculate bill in paise */
    energy_charge = (cost + DIVISOR / 2) / DIVISOR;

    total_bill = energy_charge + fixed_charge;

    printf("\n----- BILL DETAILS -----\n");

    printf("Total Energy: %" PRIu64 " Wh\n", total_wh);

    printf("Energy Charge: Rs. %" PRIu64 ".%02" PRIu64 "\n",
           energy_charge / 100, energy_charge % 100);

    printf("Fixed Charge: Rs. %" PRIu64 ".%02" PRIu64 "\n",
           fixed_charge / 100, fixed_charge % 100);

    printf("Total Bill: Rs. %" PRIu64 ".%02" PRIu64 "\n",
           total_bill / 100, total_bill % 100);

    return 0;
}