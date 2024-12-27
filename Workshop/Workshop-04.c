//1. C program to create memory for int, char, and float variables at run time

// #include <stdio.h>
// #include <stdlib.h>


// int main () {
//     int *ptr_int;
//     char *ptr_char;
//     float *ptr_float;

//     ptr_int = (int *) malloc(sizeof(int));
//     ptr_char = (char *) malloc(sizeof(char));
//     ptr_float = (float *) malloc(sizeof(float));

//     printf("Enter an integer: ");
//     scanf("%d", ptr_int);
//     printf("Enter a character: ");
//     scanf("%c", ptr_char);
//     printf("Enter a float: ");
//     scanf("%f", ptr_float);

//     printf("Integer: %d\n", *ptr_int);
//     printf("Character: %c\n", *ptr_char);
//     printf("Float: %f\n", *ptr_float);

//     free(ptr_int);
//     free(ptr_char);
//     free(ptr_float);

//     return 0;
// }

//2. Finding maximum in an array using dynamic memory allocation

// #include <stdio.h>
// #include <stdlib.h>

// void findMax(int *arr, int n, int *max) {
//     *max = arr[0];
//     for (int i = 1; i < n; i++) {
//         if (arr[i] > *max) {
//             *max = arr[i];
//         }
//     }
// }

// int main () {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int *arr = (int *) malloc(n * sizeof(int));
//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     int max;
//     findMax(arr, n, &max);

//     printf("The largest element is: %d\n", max);

//     free(arr);

// }


//3. Write a program that allocates memory space as required by the user for three arrays. User enters the numbers for two arrays and the program sums the corresponding array elements and stores them in the third array.

// #include <stdio.h>
// #include <stdlib.h>

// void addelements(int *arr1, int *arr2, int *arr3, int n) {
//     for (int i = 0; i < n; i++) {
//         arr3[i] = arr1[i] + arr2[i];
//     }
// }
// int main () {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int *arr1 = (int *) malloc(n * sizeof(int));
//     int *arr2 = (int *) malloc(n * sizeof(int));
//     int *arr3 = (int *) malloc(n * sizeof(int));

//     printf("Enter the elements of the first array: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr1[i]);
//     }

//     printf("Enter the elements of the second array: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr2[i]);
//     }

//     addelements(arr1, arr2, arr3, n);

//     printf("The sum of the two arrays is: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr3[i]);
//     }

//     free(arr1);
//     free(arr2); 
//     free(arr3);

//     return 0;
// }



//Write a program that reads 'n' from the user and allocates memory to hod n integer numbers. Pass these numbers to a function that returns the sum. 


// #include <stdio.h>
// #include <stdlib.h>

// int sumElements (int *arr, int n) {
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += arr[i];
//     }
//     return sum; 
// }

// int main () {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int *arr = (int *) malloc(n * sizeof(int));

//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     int sum = sumElements(arr, n);

//     printf("The sum of the elements is: %d\n", sum);    

//     free(arr);
// }