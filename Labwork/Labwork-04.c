// 1. Write a program  in  C to compute  the  sum  of all  elements  in  an  array
// using  pointer.
// 2.  Write a C program  to search an element  in array using  pointers.
// 3.  C  program  to  create  memory  for  int,  char  and  float  variables  at  run
// time.
// 4.   Finding  maximum  in an array using  dynamic  memory  allocation.
// 5.  Write a program  that  allocates memory  space as required  by the user
// for  three  arrays.  User  enters  the  numbers for  two arrays  and  the
// program  sums  the  corresponding  array  elements  and  stores them  in
// the third  array.
// 6.  Write a C program  to take  an array using  dynamic  memory  allocation
// and  print  them,  later  add  elements  onto  that  array  using  the  realloc
// function  and  print them  all.
// #include <stdio.h>

// int main() {
//     int arr[5] = {1, 2, 3, 4, 5};
//     int sum = 0;
//     int *ptr = arr;

//     // Using while loop with pointer comparison to check the end of the array
//     while (ptr < arr + 5) {
//         sum += *ptr;
//         ptr++;
//     }

//     printf("Sum of array elements: %d\n", sum);
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Array of elements
//     int target; // Element to search for
//     int *ptr = arr; // Pointer to the array
//     int size = sizeof(arr) / sizeof(arr[0]); // Array size

//     // Ask the user for input
//     printf("Enter the element to search for: ");
//     scanf("%d", &target);

//     // Search for the element using pointers
//     while (ptr < arr + size) {
//         if (*ptr == target) {
//             printf("Element %d found at index %ld.\n", target, ptr - arr);
//             break; // Exit the loop if the element is found
//         }
//         ptr++; // Increment the pointer only if the element is not found
//     }

//     // Handle element not found
//     if (ptr == arr + size) {
//         printf("Element %d not found in the array.\n", target);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     // Declare pointers for int, char, and float variables
//     int *p_int;
//     char *p_char;
//     float *p_float;

//     // Dynamically allocate memory for each variable
//     p_int = (int *)malloc(sizeof(int));
//     p_char = (char *)malloc(sizeof(char));
//     p_float = (float *)malloc(sizeof(float));

//     // Assign values to the variables
//     *p_int = 10;      // int value
//     *p_char = 'A';    // char value
//     *p_float = 3.14f; // float value

//     // Print the values
//     printf("Int value: %d, Char value: %c, Float value: %f\n", *p_int, *p_char, *p_float);

//     // Free the dynamically allocated memory
//     free(p_int);
//     free(p_char);
//     free(p_float);

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int i, n;
//     float *element;   // Pointer to store elements
//     float largest;    // Variable to store the largest element

//     // Input the total number of elements
//     printf(" Input total number of elements (1 to 100): ");
//     scanf("%d", &n);
//     // Allocate memory for 'n' elements
//     element = (float *)calloc(n, sizeof(float));

//     printf(" Enter %d numbers (separated by spaces):\n", n);

//     // Read 'n' numbers in a single line
//     for (i = 0; i < n; ++i) {
//         scanf("%f", &element[i]);
//     }

//     // Find the largest element
//     largest = *element; // Initialize with the first element
//     for (i = 1; i < n; ++i) {
//         if (largest < *(element + i)) {
//             largest = *(element + i);
//         }
//     }

//     printf(" The Largest element is :  %.2f \n\n", largest);

//     free(element);

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int initialSize, newSize, i;
//     int *arr;

//     // Step 1: Input the initial size of the array
//     printf("Enter the initial size of the array: ");
//     scanf("%d", &initialSize);

//     // Step 2: Allocate memory for the initial array
//     arr = (int *)malloc(initialSize * sizeof(int));
//     // Step 3: Input elements into the initial array
//     printf("Enter %d elements:\n", initialSize);
//     for (i = 0; i < initialSize; i++) {
//         scanf("%d", &arr[i]);
//     }

//     // Step 4: Print the initial array
//     printf("Initial array: ");
//     for (i = 0; i < initialSize; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // Step 5: Input the new size of the array
//     printf("Enter the new size of the array: ");
//     scanf("%d", &newSize);

//     // Step 6: Reallocate memory to expand the array
//     arr = (int *)realloc(arr, newSize * sizeof(int));

//     // Step 7: Input new elements into the expanded array
//     printf("Enter %d new elements:\n", newSize - initialSize);
//     for (i = initialSize; i < newSize; i++) {
//         scanf("%d", &arr[i]);
//     }

//     // Step 8: Print the updated array
//     printf("Updated array: ");
//     for (i = 0; i < newSize; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // Step 9: Free allocated memory
//     free(arr);

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int n, i;
//     int *array1, *array2, *array3; // Pointers for the three arrays

//     // Step 1: Input the size of the arrays
//     printf("Enter the size of the arrays: ");
//     scanf("%d", &n);

//     // Step 2: Allocate memory for the arrays
//     array1 = (int *)malloc(n * sizeof(int));
//     array2 = (int *)malloc(n * sizeof(int));
//     array3 = (int *)malloc(n * sizeof(int));

//     // Step 3: Input elements for the first array
//     printf("Enter %d elements for the first array:\n", n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &array1[i]);
//     }

//     // Step 4: Input elements for the second array
//     printf("Enter %d elements for the second array:\n", n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &array2[i]);
//     }

//     // Step 5: Compute the sum of corresponding elements
//     for (i = 0; i < n; i++) {
//         array3[i] = array1[i] + array2[i];
//     }

//     // Step 6: Print the resulting third array
//     printf("The resulting third array is:\n");
//     for (i = 0; i < n; i++) {
//         printf("%d ", array3[i]);
//     }
//     printf("\n");

//     // Step 7: Free allocated memory
//     free(array1);
//     free(array2);
//     free(array3);

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int arr[5] = {1, 2, 3, 4, 5};  // Declare and initialize an array
//     int *ptr = arr;  // Assign the array's base address to the pointer

//     // Access elements using the pointer
//     printf("First element: %d\n", *ptr); // Dereferencing the pointer to get the first element
//     printf("Second element: %d\n", *(ptr + 1)); // Accessing the second element
//     printf("Third element: %d\n", *(ptr + 2)); // Accessing the third element

//     // You can also use the pointer as an array
//     printf("Fourth element: %d\n", ptr[3]); // ptr behaves like an array here, so ptr[3] gives arr[3]
//     printf("Fifth element: %d\n", ptr[4]); // Similarly, ptr[4] gives arr[4]

//     return 0;
// }

#include <stdio.h>

int main (){
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    int i;

    for (i = 0; i<5; i++){
        printf("%d ", *(p + i));

    }
    return 0;
}