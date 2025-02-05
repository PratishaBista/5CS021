// 1.	Write a program to find both the largest and smallest elements of an array using only one traversal (both in one loop).
// objective of this program:

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



// 3.	Write a program to print all unique elements in an array.  For example:  a[ ] =  {1,2,4,8,4,2,4,9,6} answer : 1,2,4,8,9,6. 
#include <stdio.h>

void find_unique_elements(int arr[], int n) {
    printf("Unique elements: ");
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;

        // Check if the element has already been printed
        for (int j = 0; j < i - 1; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break; // Already printed
            }
        }

        // If not a duplicate, print it
        if (!isDuplicate) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 4, 8, 4, 2, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    find_unique_elements(arr, n);

    return 0;
}



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


// 6.	WAP reads two 2-D arrays of user defined dimensions, adds the corresponding elements and displays the  result on the screen. Include error handling for unequal dimensions. (For eg: a 2x2 array and 2x3 array cannot be added because of unequal dimensions.)
// #include <stdio.h>

// void addMatrices(int m, int n, int arr1[m][n], int arr2[m][n], int result[m][n]) {
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             result[i][j] = arr1[i][j] + arr2[i][j];
//         }
//     }
// }

// int main() {
//     int m1, n1, m2, n2;

//     while (1) {
//         // Read dimensions for the first matrix
//         printf("Enter the number of rows and columns for the first matrix: ");
//         scanf("%d %d", &m1, &n1);

//         // Read dimensions for the second matrix
//         printf("Enter the number of rows and columns for the second matrix: ");
//         scanf("%d %d", &m2, &n2);

//         // Check if dimensions are the same for both matrices
//         if (m1 != m2 || n1 != n2) {
//             printf("Please enter the dimensions again. Matrices have unequal dimensions.\n");
//         } else {
//             break;  // Exit the loop if the dimensions are valid
//         }
//     }

//     // Declare the matrices
//     int arr1[m1][n1], arr2[m2][n2], result[m1][n1];

//     // Read the elements of the first matrix
//     printf("Enter the elements of the first matrix:\n");
//     for (int i = 0; i < m1; i++) {
//         for (int j = 0; j < n1; j++) {
//             scanf("%d", &arr1[i][j]);
//         }
//     }

//     // Read the elements of the second matrix
//     printf("Enter the elements of the second matrix:\n");
//     for (int i = 0; i < m2; i++) {
//         for (int j = 0; j < n2; j++) {
//             scanf("%d", &arr2[i][j]);
//         }
//     }
//     // Add the matrices
//     addMatrices(m1, n1, arr1, arr2, result);

//     // Display the result
//     printf("Resultant Matrix after addition:\n");
//     for (int i = 0; i < m1; i++) {
//         for (int j = 0; j < n1; j++) {
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

