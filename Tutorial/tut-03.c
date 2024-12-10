//Q1 WAP to find the largest element of an array

#include <stdio.h>

// int main () {
//     int arr[5] = {1, 2, 3, 4, 5};
//     int max = arr[0];
//     for (int i = 1; i < 5; i++) {
//         if (arr[i] > max) {
//             max = arr[i];
//         }
//     }    
//     printf("The largest element of the array is %d", max);
//     return 0;
// }

//Q2 WAP to sort array elements in ascending order

// #include <stdio.h>

int main () {
    int arr[11] = {56, 14, 84, 21, 85, 2, 35, 74, 66, 52, 45};
    printf("The unsorted array is: ");
    for (int i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }
    int temp;
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 11; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for (int i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }
    return 0;

}

// example
// #include <stdio.h>
// int main()
// {
//   int var = 5;
//   printf("var: %d\n", var);

//   // Notice the use of & before var
//   printf("address of var: %p", &var);  
//   return 0;
// }

//Q3 wap to read 10 numbers from keyboard to store these num into array and then calculate sum of these num using function


// #include <stdio.h>

// int main() {
//     int arr[10];
//     int sum = 0;
//     printf("Enter the 10 elements:\n ");
//     for (int i = 0; i < 10; i++) {
//         scanf("%d", &arr[i]);
//         sum += arr[i];
//         }   
//         printf("The sum of the array is %d", sum);
//         return 0;
//     }

// #include <stdio.h>
// int main()
// {
//    int* pc, c;
   
//    c = 22;
//    printf("Address of c: %p\n", &c);
//    printf("Value of c: %d\n\n", c);  // 22
   
//    pc = &c;
//    printf("Address of pointer pc: %p\n", pc);
//    printf("Content of pointer pc: %d\n\n", *pc); // 22
   
//    c = 11;
//    printf("Address of pointer pc: %p\n", pc);
//    printf("Content of pointer pc: %d\n\n", *pc); // 11
   
//    *pc = 2;
//    printf("Address of c: %p\n", &c);
//    printf("Value of c: %d\n\n", c); // 2
//    return 0;
// }

//Q5 wap to store the name of week days and print them all

// #include <stdio.h>
// int main() {
//     char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//     for (int i = 0; i < 7; i++) {
//         printf("%s\n", days[i]);
//     }
//     return 0;
// }

//Q6 wap to swap the number using a pointer (call by value and call by reference).


// #include <stdio.h>
// //call by value

// void swap ( int a, int b) {
//     int temp = a;
//     a = b;
//     b = temp;
//     printf("Before swapping: a = %d, b = %d\n", a, b);
// }

// int main () {
//     int a, b;
//     printf("Enter the first number: ");
//     scanf("%d", &a);
//     printf("Enter the second number: ");
//     scanf("%d", &b);
//     swap(a, b);
//     printf("After swapping: a = %d, b = %d\n", a, b);

// }


// call by reference

// #include <stdio.h>

// void swap(int *, int *);

// int main () {
//     int a= 5;
//     int b = 4;
//     printf("Before swapping: a = %d, b = %d\n", a, b);
//     swap(&a, &b);
//     printf("After swapping: a = %d, b = %d\n", a, b);
//     return 0;
// }

// void swap(int *a, int *b) {
//     int temp;
//     temp= *a;
//     *a = *b;
//     *b = temp;
// }

//Q4 WAP reads two 2-D arrays,adds the corresponding elements and
// displays the result on the screen

#include <stdio.h>  
int main() {  
    // Declare two matrices with 3 rows and 4 columns  
    int matrix1[3][4], matrix2[3][4];  
      
    // Assign values to the first matrix  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 4; j++) {  
            matrix1[i][j] = i * 4 + j;  
        }  
    }  
      
    // Assign values to the second matrix  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 4; j++) {  
            matrix2[i][j] = i * 4 + j + 12;  
        }  
    }  
      
    // Declare a new matrix to store the result of the addition  
    int result[3][4];  
      
    // Add the two matrices and store the result in the new matrix  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 4; j++) {  
            result[i][j] = matrix1[i][j] + matrix2[i][j];  
        }  
    }  
      
    // Print the result  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 4; j++) {  
            printf("%d ", result[i][j]);  
        }  
        printf("\n");  
    }  
      
    return 0;  
}