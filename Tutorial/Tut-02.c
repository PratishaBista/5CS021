// 1. Write a C program to show the simple structure of a function
//  #include <stdio.h>

// int add(int a, int b);
// void main (){
//     int a = 5, b = 3, result;
//     result = add(a, b);
//     printf("Sum: %d", result);
// }

// int add(int a, int b){
//     return a + b;
// }

// 2. wap in c to find the square of any number using the function

// #include <stdio.h>
// int square(int n) {
//     return n * n;
// }

// void main () {
//     int n = 7, result;
//     printf("Square of %d is %d", n, square(n));
// }

// 3. wap in c to swap two numbers using the function

// #include <stdio.h>
// void swap(int a, int b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
//     printf("\nAfter swapping: a = %d, b = %d", a, b);
// }

// void main()
// {
//     int a = 5, b = 3;
//     printf("Before swapping: a = %d, b = %d", a, b);
//     swap(a, b);
   
// }

// 4. wap in c to check if a given number is odd or even using the function
// #include <stdio.h>
// int odd_even(int n)
// {
//     if (n % 2 == 0)
//     {
//         printf("%d is even", n);
//     }
//     else
//     {
//         printf("%d is odd", n);
//     }
// }

// void main () {
//     odd_even(9);
// }

//5. wap in c to convert decimal number to binary using the fucnction

// #include <stdio.h>  

// int decimalToBinary(int n);
  
// void main()  
// {  
//     int n = 10;
//     printf("Binary of %d is %d", n, decimalToBinary(n));
// }

// int decimalToBinary(int n){
//     int bin = 0, rem = 0, place = 1;
//     while(n)
//     {
//         rem = n % 2;
//         n = n / 2;
//         bin = bin + (rem * place);
//         place = place * 10;
//     }
    
// }
//6. wap in c to find whether a number is prime or not using the function
// #include <stdio.h>
// int prime(int n){
//     int i, flag = 0;
//     for (i = 2; i <= n / 2; ++i)
//     {
//         if (n % i == 0)
//         {
//             flag = 1;
//             break;
//         }
//     }
//     if (flag == 0)
//     {
//         printf("%d is a prime number.", n);
//     }
//     else
//     {
//         printf("%d is not a prime number.", n);
//     }
// }

// void main ()
// {
//     int n = 2;
//     prime(n);
// }

// 7. wap in c to check armstrong number using the fucntion
// #include <stdio.h>
// int armstrong(int n){
//     int temp, rem, sum = 0;
//     temp = n;
//     while (temp != 0)
//     {
//         rem = temp % 10;
//         sum = sum + (rem * rem * rem);
//         temp = temp / 10;
//     }
//     if (sum == n)
//     {
//         printf("%d is an Armstrong number.", n);
//     }
//     else
//     {
//         printf("%d is not an Armstrong number.", n);
//     }

// }
// void main () {
//     int n = 153;
//     armstrong(n);
// }

//8. wap in c to check perfect number using the function

// #include <stdio.h>
// int perfect(int n) {
//     int sum = 0;
//     for (int i = 1; i < n; i++) {
//         if (n % i == 0) {
//             sum = sum + i;
//         }
//     }
//     if (sum == n) {
//         printf("%d is a perfect number.", n);
//     } else {
//         printf("%d is not a perfect number.", n);
//     }
// }

// void main () {
//     int n = 6;
//     perfect(n);
// }


//9 wap in c to check whether two given strings are an anagram of each other using a function

#include <stdio.h>
#include<string.h>
int anagram(char str1[], char str2[]) {
    int i, j, flag = 0;
    for (i = 0; str1[i] != '\0'; i++) {
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1) {
        printf("The strings are anagrams.");
    } else {
        printf("The strings are not anagrams.");
    }
}

void main () {
    char str1[20], str2[20];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    anagram(str1, str2);
}
//Explaination of each line of code 
//anagram function takes two strings as input and checks if they are anagrams of each other. It does this by iterating through each character of the first string and checking if it is present in the second string. If it is, it sets the flag to 1 and breaks out of the inner loop. If the flag is 1, it means that all the characters of the first string are present in the second string, and hence the strings are anagrams. If the flag is 0, it means that not all the characters of the first string are present in the second string, and hence the strings are not anagrams.


