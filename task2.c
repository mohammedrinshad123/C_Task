
//// c program to declare an array of integers with 5 elements and print the third element of the array

#include <stdio.h>
int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};
    printf("the third element of the array is:%d\n", numbers[2]);
    return 0;
}

////  c program to declare an array of 5 integers, assign values to it, and calculate the sum of all its elemnets.

#include <stdio.h>
int main()
{
    int numbers[5];
    int sum = 0;

    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    for (int i = 0; i < 5; i++)
    {
        sum += numbers[i];
    }
    printf("the sum of all elements is:%d\n", sum);

    return 0;
}

/////  c program to find the largest and smallest elements in an array:

#include <stdio.h>
int main()
{
    int n, i;
    int largest, smallest;

    printf("enter the number of elements in the array:");
    scanf("%d", &n);

    int arr[n];
    printf("enter the element of the array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    largest = smallest = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
        if (arr[i] > smallest)
        {
            smallest = arr[i];
        }
    }
    printf("largest element: %d\n", largest);
    printf("smallest element: %d\n", smallest);

    return 0;
}

//// c program to count the vowels and consonants in a given string :

#include <stdio.h>
#include <ctype.h>
int main()
{
    char str[100];
    int vowels = 0, consonants = 0, i = 0;
    printf("enter the string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        char ch = tolower(str[i]);
        if (isalpha(ch))
        {
            if (ch == 'a', ch == 'e', ch == 'i', ch == '0', ch == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        i++;
    }
    printf("number of vowels: %d\n", vowels);
    printf("number of consonants: %d\n", consonants);

    return 0;
}

///// a program to check if a given number is even or odd :



///// write a program to  check if a given number is palindrome :

#include <stdio.h>

int main() {
    int number, reversed = 0, remainder, original;

    // Prompt the user for input
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Store the original number
    original = number;

    // Reverse the number
    while (number != 0) {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    // Check if the original number is equal to the reversed number
    if (original == reversed) {
        printf("%d is a palindrome.\n", original);
    } else {
        printf("%d is not a palindrome.\n", original);
    }

    return 0;

}

////write a c program to count how many times a specific element appears in an array using linear search.

#include <stdio.h>

int main() {
    int n, i, searchElement, count = 0;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Declare the array
    int array[n];

    // Input the elements of the array
    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Input the element to search
    printf("Enter the element to count: ");
    scanf("%d", &searchElement);

    // Linear search to count occurrences
    for (i = 0; i < n; i++) {
        if (array[i] == searchElement) {
            count++;
        }
    }

    // Output the result
    printf("The element %d appears %d times in the array.\n", searchElement, count);
    return 0;
}

//// write a c program to implement bubblesort and count  the number of swaps performed during the sorting process.

#include <stdio.h>

void bubbleSort(int arr[], int n, int *swapCount) {
    int i, j, temp;
    *swapCount = 0; // Initialize swap counter

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swapCount)++; // Increment swap counter
            }
        }
    }
}

int main() {
    int n, i, swapCount;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Bubble Sort
    bubbleSort(arr, n, &swapCount);

    // Output the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Output the number of swaps
    printf("Number of swaps: %d\n", swapCount);
    return 0;
}



