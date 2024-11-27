
#include <stdio.h>
int main()
{
    int num5, num7, product;
    printf("Enter two integers: ");
    scanf("%d %d", &num5, &num7);
    product = num5 * num7;
    printf("Product of %d and %d is %d\n", num5, num7, product);

    return 0;
}