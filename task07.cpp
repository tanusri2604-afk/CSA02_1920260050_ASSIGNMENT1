#include <stdio.h>
#include <math.h>

int main()
{
    int units = 150;
    long amount = 16250L;
    float price = 2.25f;
    double total;
    int result;
    long paise;
    
    
    total = units + price;
    printf("Implicit conversion = %.2f\n", total);

  
    printf("Integer division = %d\n", units / 100);

   
    printf("Floating division = %.2f\n", units / 100.0);

    
    result = (int)amount;
    printf("Explicit casting = %d\n", result);


    amount = 3000000000L;
    result = (int)amount;
    printf("Large value casting = %d\n", result);

    
    float a = 0.1f;
    float b = 0.2f;
    printf("Float addition = %.10f\n", a + b);

   
    total = 162.505;
    paise = (long)round(total * 100);

    printf("Rounded bill = Rs %ld.%02ld\n",
           paise / 100, paise % 100);

    return 0;
}