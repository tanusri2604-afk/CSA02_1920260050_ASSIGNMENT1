#include <stdio.h>
#include <limits.h>
#include <float.h>
typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
 
    return (unsigned short)(current - previous);
}

int main(void)
{
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",
           sizeof(meter_t), (unsigned)USHRT_MAX);

    printf("Consumption: %u units\n",
           consumption(1200, 1530));

    printf("Consumption: %u units\n",
           consumption(65400, 120));

 
    printf("\n--- DATA TYPE SIZES ---\n");
    printf("char       = %zu bytes\n", sizeof(char));
    printf("short      = %zu bytes\n", sizeof(short));
    printf("int        = %zu bytes\n", sizeof(int));
    printf("long       = %zu bytes\n", sizeof(long));
    printf("long long  = %zu bytes\n", sizeof(long long));
    printf("float      = %zu bytes\n", sizeof(float));
    printf("double     = %zu bytes\n", sizeof(double));

 
    printf("\n--- INTEGER RANGES ---\n");
    printf("INT_MIN     = %d\n", INT_MIN);
    printf("INT_MAX     = %d\n", INT_MAX);
    printf("UINT_MAX    = %u\n", UINT_MAX);
    printf("LONG_MAX    = %ld\n", LONG_MAX);
    printf("LLONG_MAX   = %lld\n", LLONG_MAX);
    printf("USHRT_MAX   = %u\n", (unsigned)USHRT_MAX);

   
    printf("\n--- FLOATING POINT RANGES ---\n");
    printf("FLT_MIN     = %e\n", FLT_MIN);
    printf("FLT_MAX     = %e\n", FLT_MAX);
    printf("DBL_MIN     = %e\n", DBL_MIN);
    printf("DBL_MAX     = %e\n", DBL_MAX);

    return 0;
}