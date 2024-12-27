// 1.	Write a program to find both the largest and smallest elements of an array using only one traversal (both in one loop).
// objective of this program:
// 1. to find both the largest and smallest elements of an array using only one traversal (both in one loop).
// 2. to learn about array
// 6. to learn about for loop
// 3. to learn about array indexing
// 4. to learn about if statement
// 5. to learn about else statement

// #include <stdio.h>

// void findMaxMin(int arr[], int n, int *max, int *min);

// int main () {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int arr[n];
//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     int max, min;
//     findMaxMin(arr, n, &max, &min);
//     printf("The largest element is: %d\n", max);
//     printf("The smallest element is: %d\n", min);

//     return 0;
// }

// void findMaxMin(int arr[], int n, int *max, int *min) {
//     *max = arr[0];
//     *min = arr[0];
//     for (int i = 1; i < n; i++) {
//         if (arr[i] > *max) {
//             *max = arr[i];
//         }
//         if (arr[i] < *min) {
//             *min = arr[i];
//         }
//     }
// }

// 1. **Function Declaration**:
//    - Declare a function `findMaxMin` that takes:
//      - An array (`arr`) of integers.
//      - The size of the array (`n`).
//      - Pointers to integers (`max` and `min`) to store the largest and smallest elements.

// 2. **Main Function**:
//    - **Input the number of elements (`n`)**:
//      - Prompt the user to enter the number of elements in the array.
//      - Store the input in the variable `n`.
//    - **Input array elements**:
//      - Declare an array of size `n`.
//      - Prompt the user to input the elements of the array and store them.
//    - **Initialize variables**:
//      - Declare variables `max` and `min` to store the largest and smallest values.
//    - **Call the function `findMaxMin`**:
//      - Pass the array, its size, and pointers to `max` and `min` as arguments.
//    - **Output results**:
//      - Print the largest and smallest elements.

// 3. **`findMaxMin` Function**:
//    - **Initialize `max` and `min`**:
//      - Set the first element of the array as the initial value for both `max` and `min`.
//    - **Iterate through the array**:
//      - For each element in the array (starting from the second element):
//        - If the element is greater than `max`, update `max`.
//        - If the element is smaller than `min`, update `min`.
//    - **Return results**:
//      - The function updates `max` and `min` through their pointers.




// 2.	Write a program to check whether two given strings are an anagram. 
// #include <stdio.h>
// #include <string.h>

// void sortString(char *str) {
//     int len = strlen(str);
//     for (int i = 0; i < len - 1; i++) {
//         for (int j = i + 1; j < len; j++) {
//             if (str[i] > str[j]) {
//                 char temp = str[i];
//                 str[i] = str[j];
//                 str[j] = temp;
//             }
//         }
//     }
// }

// int main() {
//     char str1[100], str2[100]; 

//     printf("Enter the first string: ");
//     scanf("%99s", str1); 
//     printf("Enter the second string: ");
//     scanf("%99s", str2); 

//     sortString(str1);
//     sortString(str2);

//     if (strcmp(str1, str2) == 0) {
//         printf("Strings are anagrams\n");
//     } else {
//         printf("Strings are not anagrams\n");
//     }

//     return 0;
// }
// 1. Start
// 2. Declare a function `sortString(str)`:
//    a. Calculate the length of `str`.
//    b. Use nested loops to compare characters and sort them in ascending order.
//    c. Swap characters when needed to achieve sorting.

// 3. In the `main` function:
//    a. Declare two arrays `str1` and `str2` to store input strings.
//    b. Prompt the user to input the first string and store it in `str1`.
//    c. Prompt the user to input the second string and store it in `str2`.

// 4. Call `sortString(str1)` to sort the characters of the first string.
// 5. Call `sortString(str2)` to sort the characters of the second string.

// 6. Use `strcmp` to compare `str1` and `str2`:
//    a. If the strings are equal:
//       i. Print "Strings are anagrams."
//    b. Otherwise:
//       i. Print "Strings are not anagrams."

// 7. End


// 3.	Write a program to print all unique elements in an array.  For example:  a[ ] =  {1,2,4,8,4,2,4,9,6} answer : 1,2,4,8,9,6. 
// #include <stdio.h>

// void find_unique_elements(int arr[], int n) {
//     printf("Unique elements: ");
//     for (int i = 0; i < n; i++) {
//         int isDuplicate = 0;

//         // Check if the element has already been printed
//         for (int j = 0; j < i; j++) {
//             if (arr[i] == arr[j]) {
//                 isDuplicate = 1;
//                 break; // Already printed
//             }
//         }

//         // If not a duplicate, print it
//         if (!isDuplicate) {
//             printf("%d ", arr[i]);
//         }
//     }
// }

// int main() {
//     int arr[] = {1, 2, 4, 8, 4, 2, 4, 9, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     find_unique_elements(arr, n);

//     return 0;
// }


// 1. **Function Declaration**:
//    - Declare a function `find_unique_elements_in_an_array(int arr[], int n)` to identify and print unique elements in an array.

// 2. **Iterate Over the Array**:
//    - Use a loop to iterate through each element of the array (`i`).

// 3. **Check for Duplicates**:
//    - For each element `arr[i]`, check if it has already been encountered by comparing it with all the previous elements (`arr[j]` where `j < i`).

// 4. **Mark Duplicate**:
//    - If `arr[i] == arr[j]`, mark it as a duplicate and stop further comparisons using `break`.

// 5. **Print Unique Element**:
//    - If the element is not marked as a duplicate, print it.

// 6. **Main Function**:
//    - Define the main function.
//    - Declare an array and initialize it with some elements.
//    - Calculate the size of the array.
//    - Call the `find_unique_elements_in_an_array` function with the array and its size as arguments.

// 4.	Write a program to sort an array of elements in ascending order
// #include <stdio.h>

// void selectionSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         // Find the minimum element in unsorted part of the array
//         int minIndex = i;
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//         }
        
//         // Swap the found minimum element with the first element
//         if (minIndex != i) {
//             int temp = arr[i];
//             arr[i] = arr[minIndex];
//             arr[minIndex] = temp;
//         }
//     }
// }

// int main() {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     selectionSort(arr, n);

//     printf("Sorted array in ascending order: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }
// Algorithm:
// For each element in the array from index 0 to n-1:

// Assume that the current element is the smallest (minIndex = i).
// Find the minimum element in the unsorted part of the array (from index i+1 to n-1):
// Compare the current element arr[i] with each element arr[j] (where j goes from i+1 to n-1).
// If arr[j] < arr[minIndex], update minIndex to j.
// Swap the minimum element found with the current element (arr[i]).
// Repeat the process for the next element until the entire array is sorted.

// End when all elements are sorted.


// 5.	Write a program to count and find the sum of all numbers in the array which are divisible by 5 but neither by 2 nor by 3. Also, print the indices of these numbers
// #include <stdio.h>

// void sum_divisible_by_7(int arr[], int size)
// {
//     int sum = 0, count = 0, i;
//     printf("Indices of numbers divisible by 7 but not by 2 or 3: ");
//     for (i = 0; i < size; i++)
//     {
//         if (arr[i] % 7 == 0 && arr[i] % 2 != 0 && arr[i] % 3 != 0)
//         {
//             sum += arr[i];
//             count++;
//             printf("%d ", i); // Print the index of the number
//         }
//     }
//     printf("\nSum of numbers divisible by 7 and not divisible by 2 and 3: %d\n", sum);
//     printf("Count of such numbers: %d\n", count);
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     sum_divisible_by_7(arr, size);
//     return 0;
// }

// 1. **Start**
// 2. **Input** the array and its size.
// 3. Initialize `sum = 0`, `count = 0`.
// 4. For each element in the array from index `i = 0` to `size - 1`:
//    - If `arr[i] % 7 == 0` and `arr[i] % 2 != 0` and `arr[i] % 3 != 0`:
//      - Add `arr[i]` to `sum`.
//      - Increment `count`.
//      - Print the index `i`.
// 5. **Print the sum** of numbers divisible by 7 but not by 2 or 3.
// 6. **Print the count** of such numbers.
// 7. **End**.

// 6.	WAP reads two 2-D arrays of user defined dimensions, adds the corresponding elements and displays the  result on the screen. Include error handling for unequal dimensions. (For eg: a 2x2 array and 2x3 array cannot be added because of unequal dimensions.)
#include <stdio.h>

void addMatrices(int m, int n, int arr1[m][n], int arr2[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

int main() {
    int m1, n1, m2, n2;

    while (1) {
        // Read dimensions for the first matrix
        printf("Enter the number of rows and columns for the first matrix: ");
        scanf("%d %d", &m1, &n1);

        // Read dimensions for the second matrix
        printf("Enter the number of rows and columns for the second matrix: ");
        scanf("%d %d", &m2, &n2);

        // Check if dimensions are the same for both matrices
        if (m1 != m2 || n1 != n2) {
            printf("Please enter the dimensions again. Matrices have unequal dimensions.\n");
        } else {
            break;  // Exit the loop if the dimensions are valid
        }
    }

    // Declare the matrices
    int arr1[m1][n1], arr2[m2][n2], result[m1][n1];

    // Read the elements of the first matrix
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    // Read the elements of the second matrix
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    // Add the matrices
    addMatrices(m1, n1, arr1, arr2, result);

    // Display the result
    printf("Resultant Matrix after addition:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// User Input for Matrix Dimensions:

// Ask for dimensions for the first matrix (m1 x n1).
// Ask for dimensions for the second matrix (m2 x n2).
// If the dimensions are not equal, repeat the input process until the dimensions match.
// Matrix Element Input:

// Read the elements of the first matrix.
// Read the elements of the second matrix.
// Matrix Addition:

// Create a result matrix.
// For each element in the matrices, perform the addition and store the result.
// Output:

// Display the resultant matrix.