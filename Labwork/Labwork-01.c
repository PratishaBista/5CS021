// what are triangular numbers?
// A triangular number is a number that is the sum of the first n natural numbers.
// For example, the first 5 triangular numbers are 1, 3, 6, 10, and 15.
// Q1. Write a program that asks the user to enter a non-negative number and then prints the triangular numbers up to that number.
// #include <stdio.h>

// int main()
// {
//   int n, sum = 0;

//   printf("Enter a non-negative number to print triangular numbers up to n: ");
//   scanf("%d", &n);

//   while (n < 0)
//   {
//     printf("Please enter a non-negative number: ");
//     scanf("%d", &n);
//   }

//   printf("Triangular numbers up to %d are: \n", n);
//   for (int i = 1; i <= n; i++)
//   {
//     sum += i;
//     printf("T%d = %d\n", i, sum);
//   }

//   return 0;
// }

// #include <stdio.h>
// int main()
// {
//   int n, sum = 0;
//   printf("Enter a non-negative integer: ");
//   scanf("%d", &n);

//   while (n < 0)
//   {
//     printf("Enter positive interger only. Try again");
//     scanf("%d", &n);
//   }

//   for (int i = 1; i <= n; i++)
//   {
//     sum += i;
//     printf("T%d = %d\n", i, sum);
//   }
//   return 0;
// }

// Q2. Wap to print the sum of digits of the number provided by user.

#include<stdio.h>

int main () {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    printf("Sum of digits is: %d", sum);
    return 0;
}


// Q3 Write a program to create simple calculator using switch case. (The
//  operators +, -, *, /and % must be asked to user as a character.)

// #include <stdio.h>

// int main() {
//     char op;
//     double num1, num2;
//     int valid = 0;

//     printf("Enter two numbers: ");
//     scanf("%lf %lf", &num1, &num2);

//     while (!valid) {
//         printf("Enter an operator (+, -, *, /): ");
//         scanf(" %c", &op);

//         switch (op) {
//             case '+':
//                 printf("%.1lf + %.1lf = %.1lf\n", num1, num2, num1 + num2);
//                 valid = 1;
//                 break;
//             case '-':
//                 printf("%.1lf - %.1lf = %.1lf\n", num1, num2, num1 - num2);
//                 valid = 1;
//                 break;
//             case '*':
//                 printf("%.1lf * %.1lf = %.1lf\n", num1, num2, num1 * num2);
//                 valid = 1;
//                 break;
//             case '/':
//                 if (num2 != 0) {
//                     printf("%.1lf / %.1lf = %.1lf\n", num1, num2, num1 / num2);
//                 } else {
//                     printf("Error! Division by zero is not allowed.\n");
//                 }
//                 valid = 1;
//                 break;
//             default:
//                 printf("Error! Operator is not correct. Please enter again.\n");
//                 break;
//         }
//     }

//     return 0;
// }

// Q4 .Write a program to input a character from the user until an enter is
// pressed and print it in lowercase. If the character is in uppercase,
// then you must change it in lowercase and if it is in lowercase then
// you must print as it is.

// #include <stdio.h>
// #include <ctype.h> // For tolower() function

// int main() {
//     char ch;

//     printf("Enter characters (press Enter to stop): ");

//     while (1) {
//         scanf("%c", &ch); // Read a character

//         // Check if Enter key (newline) is pressed
//         if (ch == '\n') {
//             break;
//         }

//         // Convert uppercase to lowercase or print as it is
//         printf("%c", tolower(ch));
//     }

//     return 0;
// }

// Q5. Write a program to ask the final score from user and print it
//  whether he/she is passed in (distinction above 80%, first division
//  above 60% to 80%, second division above 50% to 60%, Third
//  division above 40% to 50%, and fail below 40%). It is mandatory to
//  use elseif statement to solve the task.

// #include <stdio.h>
// int main () {
//     float score;
//     printf("Enter your final score(0-100): ");
//     scanf("%f", &score);
//     if (score >= 80) {
//         printf("You are passed in Distinction.");
//     } else if (score >= 60 && score < 80) {
//         printf("You are passed in First Division.");
//     } else if (score >= 50 && score < 60) {
//         printf("You are passed in Second Division.");
//     } else if (score >= 40 && score < 50) {
//         printf("You are passed in Third Division.");
//     } else {
//         printf("You are failed.");
//     }
//     return 0;
// }
// algorithm for this code is:
// setp 1: start
// step 2: declare variables
// step 3: input score
// step 4: if score is greater than or equal to 80 then print "You are passed in Distinction."
// step 5: else if score is greater than or equal to 60 and less than 80 then print "You are passed in First Division."
// step 6: else if score is greater than or equal to 50 and less than 60 then print "You are passed in Second Division."
// step 7: else if score is greater than or equal to 40 and less than 50 then print "You are passed in Third Division."
// step 8: else print "You are failed."
// step 9: end

// Q6. Write a program to print the following pattern.
//  A
//  B B
//  C C C
//  D D D D
//  E E E E E

// #include <stdio.h>
// int main() {
//     char ch = 'A';
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j <= i; j++) {
//             printf("%c ", ch);
//         }
//         ch++;
//         printf("\n");
//     }
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//   int i, j;
//   char alphabet='A';
//   for(i=1; i<=5; i++)
//   {
//     for (j=1; j<=i; j++)
//     {
//       alphabet = alphabet+i;
//       printf("%c ", alphabet-1);
//       alphabet='A';
//     }
//     printf("\n");
//   }
//   return 0;
// }

// raw algorithm step wise
// step 1: start
// step 2: declare variables
// step 3: for loop
// step 4: for loop
// step 5: print alphabet
// step 6: print newline
// step 7: end
