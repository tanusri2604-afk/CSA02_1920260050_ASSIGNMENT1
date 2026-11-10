#include <stdio.h>
#include <limits.h>

int main(void)
{
    int counts[] = {4000, 60000, 800000};

    float bill = 162.50f;
    float float_total;

    long long paise_total;

    printf("ELECTRICITY BILL COMPARISON\n\n");

    for (int i = 0; i < 3; i++)
    {
        float_total = 0.0f;
        paise_total = 0;

        for (int j = 0; j < counts[i]; j++)
        {
            float_total += bill;
            paise_total += 16250LL;
        }

        printf("Households = %d\n", counts[i]);

        printf("Float Total = Rs %.2f\n", float_total);

        printf("Paise Total = Rs %lld.%02lld\n",
               paise_total / 100,
               paise_total % 100);

        printf("Difference = Rs %.2f\n\n",
               (double)float_total -
               (double)paise_total / 100.0);
    }

    printf("DATA TYPE SIZES\n");
    printf("int = %zu bytes\n", sizeof(int));
    printf("long = %zu bytes\n", sizeof(long));
    printf("long long = %zu bytes\n", sizeof(long long));
    printf("float = %zu bytes\n", sizeof(float));
    printf("double = %zu bytes\n", sizeof(double));

    printf("\nTYPE LIMITS\n");
    printf("INT_MAX = %d\n", INT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);

    return 0;
}