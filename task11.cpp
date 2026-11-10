#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>

#define SLAB1 100
#define SLAB2 200
#define RATE1 0
#define RATE2 225
#define RATE3 450
#define FIXED_CHARGE 5000LL
int64_t calculate_bill(int units)
{
    int64_t bill = FIXED_CHARGE;

    if (units > SLAB2)
    {
        bill += 100LL * RATE2;
        bill += (int64_t)(units - SLAB2) * RATE3;
    }
    else if (units > SLAB1)
    {
        bill += (int64_t)(units - SLAB1) * RATE2;
    }

    return bill;
}
int read_tariff(int *slab1, int *slab2,
                int *rate1, int *rate2,
                int *rate3, int64_t *fixed)
{
    FILE *fp = fopen("tariff.txt", "r");

    if (fp == NULL)
        return 0;

    int result = fscanf(fp, "%d %d %d %d %d %lld",slab1, slab2, rate1,rate2, rate3, fixed);

    fclose(fp);

    if (result != 6 || *slab1 < 0 ||
        *slab2 <= *slab1 || *rate1 < 0 ||
        *rate2 < 0 || *rate3 < 0 || *fixed < 0)
        return 0;

    return 1;
}


int64_t calculate_file_bill(int units, int slab1,int slab2, int rate1,int rate2, int rate3,int64_t fixed)
{
    int64_t bill = fixed;

    if (units > slab2)
    {
        bill += (int64_t)(slab2 - slab1) * rate2;
        bill += (int64_t)(units - slab2) * rate3;
    }
    else if (units > slab1)
    {
        bill += (int64_t)(units - slab1) * rate2;
    }

    return bill;
}

int main(void)
{
    int households[] = {4000, 60000, 800000};
    int units = 150;

    int slab1, slab2, rate1, rate2, rate3;
    int64_t fixed;

    clock_t start, end;
    printf("\nCompiled Tariff:\n");
    printf("Bill for 150 units = Rs. %lld.%02lld\n",
           calculate_bill(units) / 100,
           calculate_bill(units) % 100);

    printf("\nHousehold Scale Testing:\n");

    for (int i = 0; i < 3; i++)
    {
        int64_t total = calculate_bill(units) *
                        (int64_t)households[i];

        printf("%d households = Rs. %lld.%02lld\n",
               households[i], total / 100, total % 100);
    }

    start = clock();

    if (read_tariff(&slab1, &slab2, &rate1,
                    &rate2, &rate3, &fixed))
    {
        end = clock();

        int64_t file_bill = calculate_file_bill(
            units, slab1, slab2, rate1,
            rate2, rate3, fixed);

        printf("\nConfiguration File Tariff:\n");
        printf("Bill for 150 units = Rs. %lld.%02lld\n",
               file_bill / 100, file_bill % 100);

        printf("File reading time = %.6f seconds\n",
               (double)(end - start) / CLOCKS_PER_SEC);
    }
    else
    {
        printf("\nInvalid or missing tariff.txt file.\n");
    }

    printf("\nData Type Sizes:\n");
    printf("uint16_t = %zu bytes\n", sizeof(uint16_t));
    printf("int64_t = %zu bytes\n", sizeof(int64_t));
    printf("int maximum = %d\n", INT_MAX);
    printf("Long long maximum = %lld\n", LLONG_MAX);

#ifdef DEBUG
    printf("\nDEBUG MODE ENABLED\n");
    printf("Units = %d\n", units);
    printf("Fixed charge = %lld paise\n", FIXED_CHARGE);
#endif

    return 0;
}