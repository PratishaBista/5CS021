// #include <stdio.h>
// Write a program in C to take two numbers from the user and print the
// maximum between two numbers using a pointer.

// int max(int *a, int *b) {
//     if(*a > *b) {
//         return *a;
//     } else {
//         return *b;
//     }
// }
// int main () {
//     int a, b;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);
//     printf("Maximum number is: %d", max(&a, &b));
//     return 0;
// }

// Write a program to count and find the sum of all the numbers in the array
//  which are exactly divisible by 7 and not divisible by 2 and 3.

// void sum_divisible_by_7(int arr[], int size) {
//     int sum = 0;
//     for(int i = 0; i < size; i++) {
//         if(arr[i] % 7 == 0 && arr[i] % 2 != 0 && arr[i] % 3 != 0) {
//             sum += arr[i];
//         }
//     }
//     printf("Sum of numbers divisible by 7 and not divisible by 2 and 3: %d", sum);
// }
// int main() {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 21, 63, 105};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     sum_divisible_by_7(arr, size);
//     return 0;
// }

// Write a program to initialize an integer array with values {10,5,7,91,54,24}.
//  Pass this array to a function. If element is found, print out its index number
//  and if element is not found then display the message “Element Not found” in
//  the function

// void find_element(int arr[], int element) {
//     int found = 0;
//     for(int i = 0; i < 6; i++) {
//         if(arr[i] == element) {
//             printf("The element %d found at index %d", element, i);
//             found = 1;
//             break;
//         }
//     }
//     if(found == 0) {
//         printf("Element not found");
//     }

// }
// int main () {
//     int arr[] = {10, 5, 7, 91, 54, 24};
//     int element;
//     printf("Enter the element to be searched: ");
//     scanf("%d", &element);
//     find_element(arr, element);
// }

//
// Write a program to read three integers using an array and find the smallest
// and largest among them.You must write a function for finding the largest and
// smallest integer and the result must be displayed in the main function itself.
// You are not allowed to create global variables

// void find_largest_and_smallest(int arr[]) {
//     int max = arr[0];
//     int min = arr[0];
//     for(int i = 1; i < 3; i++) {
//         if(arr[i] > max) {
//             max = arr[i];
//         }
//         if(arr[i] < min) {
//             min = arr[i];
//         }
//     }

// }
// int main () {
//     int arr[3];
//     printf("Enter three integers: ");
//     scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
//     find_largest_and_smallest(arr);
//     printf("Largest number is: %d\n", max);
//     printf("Smallest number is: %d", min);
//     return 0;
// }

// #include <stdio.h>

// void find_largest_and_smallest(int arr[], int *max, int *min) {
//     *max = arr[0];
//     *min = arr[0];
//     for (int i = 1; i < 3; i++) {
//         if (arr[i] > *max) {
//             *max = arr[i];
//         }
//         if (arr[i] < *min) {
//             *min = arr[i];
//         }
//     }
// }

// int main() {
//     int arr[3];
//     int max, min;

//     printf("Enter three integers: ");
//     scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

//     find_largest_and_smallest(arr, &max, &min);

//     printf("Largest number is: %d\n", max);
//     printf("Smallest number is: %d\n", min);

//     return 0;
// }

// Write a program to take three numbers from the user and save it in three
//  different variables. You must swap the value of three numbers using
//  function. You must use call by references.

// void swap(int *a, int *b, int *c) {
//     int temp = *a;
//     *a = *b;
//     *b = *c;
//     *c = temp;
// }
// int main () {
//     int a, b, c;
//     printf("Enter three numbers: ");
//     scanf("%d %d %d", &a, &b, &c);
//     swap(&a, &b, &c);
//     printf("After swapping: a = %d, b = %d, c = %d", a, b, c);
//     return 0;
// }

// 3b
// Write a program in C to take three numbers from the user and print the sum,
//  multiplication, quotient, subtraction and minimum between three numbers
//  using a pointer

// #include <stdio.h>

// void calculate(int *a, int *b, int *c, int *sum, int *mul, int *quotient, int *sub, int *min) {
//     *sum = *a + *b + *c;
//     *mul = *a * *b * *c;
//     *sub = *a - *b - *c;
//     *min = *a;
//     if(*b < *min) {
//         *min = *b;
//     }
//     if(*c < *min) {
//         *min = *c;
//     }

//     *quotient = *a / *b / *c;

// }
// int main () {
//     int a, b, c;
//     printf("Enter three numbers: ");
//     scanf("%d %d %d", &a, &b, &c);
//     int sum, mul, quotient, sub, min;
//     calculate(&a, &b, &c, &sum, &mul, &quotient, &sub, &min);
//     printf("Sum = %d\n", sum);
//     printf("Multiplication = %d\n", mul);
//     printf("Quotient = %d\n", quotient);
//     printf("Subtraction = %d\n", sub);
//     printf("Minimum = %d\n", min);
//     return 0;
// }

// Write a program to count and find the sum of all the numbers in the array
// which are exactly divisible by 5 and not divisible by 2 and 3

// #include <stdio.h>
// void sum_divisible_by_5(int arr[], int size)
// {
//     int sum = 0, i;
//     for (i = 0; i < size; i++)
//     {
//         if (arr[i] % 5 == 0 && arr[i] % 2 != 0 && arr[i] % 3 != 0)
//         {
//             sum += arr[i];
//         }
//     }
//     printf("Sum of numbers divisible by 5 and not divisible by 2 and 3: %d", sum);
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     sum_divisible_by_5(arr, size);
//     return 0;
// }

 
 //Write a program to replace each element in an array with the integer value 5.
// You must take input from users in the main function and save it in an array.
// You must also take the size of an array from the user. You must create a
// function that takes two parameters: an array and length of the array. Your
// function should not return anything and it should not print anything. You
// must print before and after replacing an element in an array in the main
// function.


#include<stdio.h>
void replace_element(int arr[], int length) {
    for (int i = 0; i < length; i++ ) {
        arr[i] = 5;
    }
}

int main () {
    int length;
    printf("Enter the size of the array: ");
    scanf("%d", &length);
    int arr[length];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < length; i ++ ) {
        scanf("%d", &arr[i]);
    }
    printf("Before replacing: ");
    for (int i = 0; i < length; i ++ ) {
        printf("%d ", arr[i]);
    }
    replace_element(arr, length);
    printf("\nAfter replacing: ");
    for (int i = 0; i < length; i ++ ) {
        printf("%d ", arr[i]);
    }

    printf("Enter a value to replace each element in the array: ");
    int value;
    scanf("%d", &value);
    replace(arr, length, value);

    return 0;
}

// Add a new function in the program you have created in Qno. 3 which takes
// three parameters: an array, length of the array and value to replace each
// element in an array. You must receive an integer value in the main function.
// Your function should not return anything and it should not print anything.
// You must print a new array in the main function.

void replace(int arr[], int length, int value) {
    for (int i = 0; i < length; i++ ) {
        arr[i] = value;
    }
}

// the prime factors of 13195 are 5, 7, 13, and 29 
// what is the largest prime factro of the number 600851475143?
// #include <stdio.h>

// long long largest_prime_factor(long long n) {
//     long long max_prime = -1;
    
//     // Divide out all factors of 2
//     while (n % 2 == 0) {
//         max_prime = 2;
//         n /= 2;
//     }

//     // Check odd factors from 3 onwards
//     for (long long i = 3; i * i <= n; i += 2) {
//         while (n % i == 0) {
//             max_prime = i;
//             n /= i;
//         }
//     }

//     // If n is still greater than 2, then it's a prime factor
//     if (n > 2) {
//         max_prime = n;
//     }

//     return max_prime;
// }

// int main() {
//     long long number = 13195;
//     printf("The largest prime factor of %lld is: %lld\n", number, largest_prime_factor(number));
//     return 0;
// }
