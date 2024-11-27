/// multiply two numbers


#include <stdio.h>

int main() {
    int num5, num7, product;

    printf("Enter two integers: ");

    scanf("%d %d", &num5, &num7);

    product = num5 * num7;

    printf("Product of %d and %d is %d\n", num5, num7, product);

    return 0;
}

//// calculate the average of three numbers.
#include <stdio.h>

int main() {
    float num1, num2, num3, average;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    average = (num1 + num2 + num3) / 3;

    printf("The average of %.2f, %.2f, and %.2f is %.2f\n", num1, num2, num3, average);

    return 0;
}

/////// c program to check if a given number is even or odd

#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Checking if the number is even or odd
    if (num % 2 == 0) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }

    return 0;
}


