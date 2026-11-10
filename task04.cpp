#include <stdio.h>
#define RUPEES_TO_PAISE(r) ((r) * 100L)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(void)
{
    int a = 5;
    int b = 10;
    int i = 3;
    int j = 7;

    printf("Rupees to Paise: %ld\n", RUPEES_TO_PAISE(50));

    printf("Square of %d: %d\n", a, SQUARE(a));

    printf("Square of (a + 1): %d\n", SQUARE(a + 1));

    printf("Maximum of %d and %d: %d\n", a, b, MAX(a, b));

    printf("MAX(i, j): %d\n", MAX(i, j));

 
    return 0;
}