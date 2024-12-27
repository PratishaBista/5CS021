//Q1. Write a C program to find the cube of a number using function.

// #include <stdio.h>
// int findCube(int num) {
//     int result = num * num * num;
//     printf("The cube of %d is %d",num, result);
// }

// int main () {
//     int num;
//     printf("Enter a number to find its cube: ");
//     scanf("%d", &num);
//     findCube(num);
//     return 0;
// }

//the algorithm to find the cube of a number using a function is:

// step 1: start
// step 2: declare a function to find the cube of a number
// step 3: declare a variable to store the cube of the number
// step 4: calculate the cube of the number by multiplying the number three times
// step 5: print the cube of the number
// step 6: end

//Q2. Write a program in C to swap two numbers using function.
//pass by value
// #include <stdio.h>

// void swap(int a, int b) {
//     //w/o using third variable
//     a = a + b;
//     b = a - b;
//     a = a - b;
//     printf("After swapping: a = %d, b = %d", a, b);

// }

// int main () {
//     int a, b;
//     printf("Enter two numbers to swap: ");
//     scanf("%d %d", &a, &b);
//     swap(a, b);
//     return 0;
// }
//objective of this program are:
//to swaap two variable 
//to create a logic to swap two numbers without using third variable


//algorithm to swap two numbers using a function

//step 1: start
//step 2: declare a function to swap two numbers with two parameters to store two values
//step 3: declare a variable to store the swapped values
//step 4: swap without using third variable 
//step 5: set a as a + b
//step 6: set b as a - b
//step 7: set a as a - b    
//step 8: in the driver function, ask the user to enter two numbers
//step 9: call the function and pass the two numbers as arguments
//step 4: print the swapped values
//step 5: end   

//Write a void function which finds and prints the midpoint coordinates of a line. The
// function should take in four parameters (x1, y1, x2 and y2).
// xmid=(x1+x2)/2, ymid=(y1+y2)/2

// #include<stdio.h>

// void midpoint(double x1, double y1, double x2, double y2) {
//     double xmid = (x1 + x2) / 2;
//     double ymid = (y1 + y2) / 2;
//     printf("The midpoint is (%0.1lf, %0.1lf)", xmid, ymid);
// }

// int main () {
//     double x1, y1, x2, y2;
//     printf("Enter the coordinates of the line (x1, y1, x2, y2): ");
//     scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
//     midpoint(x1, y1, x2, y2);
//     return 0;    
// }


//objective of this program: 
//to find the mid point coordinates of a line
//to 

//algorithm of a function which finds and prints the midpoint coordinates of a line . the function should take in four parameters(x1, y2, x2, y1). xmid = (x1+x2)/2, ymid = (y1+y2)/2   
//step 1: start
//step 2: declare a function to find the midpoint of a line with four parameters to store the coordinates of the line
//step 3: declare a variable to store the midpoint of the line
//step 4: calculate the midpoint of the line by adding the coordinates of the line and dividing by 2
//step 5: print the midpoint of the line
//step 6: end

//Q4. Write a program in C to check Armstrong and perfect numbers using the function.

#include <stdio.h>
#include <math.h>

// Function to check if a number is an Armstrong number
void isArmstrong(int arm_num) {
    int sum = 0, temp, rem, num_digits;
    temp = arm_num;

    // Count the number of digits in the number
    num_digits = 0;
    while (temp > 0) {
        temp = temp / 10;
        num_digits++;
    }

    temp = arm_num;  // Reset temp to the original number

    // Calculate the sum of the digits raised to the power of the number of digits
    while (temp > 0) {
        rem = temp % 10;
        sum += pow(rem, num_digits);  // Raise the digit to the power of num_digits
        temp = temp / 10;
    }

    if (sum == arm_num) {
        printf("%d is an Armstrong number.\n", arm_num);
    } else {
        printf("%d is not an Armstrong number.\n", arm_num);
    }
}

// Function to check if a number is a perfect number
void isPerfect(int perfect_num) {
    int sum = 0;
    for (int i = 1; i < perfect_num; i++) {
        if (perfect_num % i == 0) {
            sum = sum + i;
        }
    }
    if (sum == perfect_num) {
        printf("%d is a perfect number.\n", perfect_num);
    } else {
        printf("%d is not a perfect number.\n", perfect_num);
    }
}

int main() {
    int arm_num;
    int perfect_num;

    // Input for Armstrong number
    printf("Enter a number to check if it is an Armstrong number: ");
    scanf("%d", &arm_num);
    isArmstrong(arm_num);  // Call the function

    // Input for perfect number
    printf("Enter a number to check if it is a perfect number: ");
    scanf("%d", &perfect_num);
    isPerfect(perfect_num);  // Call the function

    return 0;  // Return statement for main
}

// Q4. Write a function named "velocityCalc" which returns an appropriate value for the formula "v= u + at", where v is the final velocity, u is the initial velocity, a is the acceleration and t is the time that has elapsed. Depending upon which variable is set to "NAN" when the function is called, your function should work it out and return the value. 

// #include <stdio.h>
// #include <math.h>

// // Function to calculate the missing variable
// double velocityCalc(double v, double u, double a, double t) {
//     if (isnan(v)) { 
//         return u + a * t;
//     }
//     if (isnan(u)) { 
//         return v - a * t;
//     }
//     if (isnan(a)) { 
//         return (v - u) / t;
//     }
//     if (isnan(t)) { 
//         return (v - u) / a;
//     }
//     return NAN; 
// }

// int main() {
//     double v = NAN, u = 10, a = 2, t = 5; // Example input
//     double result = velocityCalc(v, u, a, t);

//     // Determine which variable is being calculated and print the result with units
//     if (isnan(v)) {
//         printf("The calculated final velocity (v) is: %.2f m/s\n", result);
//     } else if (isnan(u)) {
//         printf("The calculated initial velocity (u) is: %.2f m/s\n", result);
//     } else if (isnan(a)) {
//         printf("The calculated acceleration (a) is: %.2f m/s²\n", result);
//     } else if (isnan(t)) {
//         printf("The calculated time (t) is: %.2f s\n", result);
//     } else {
//         printf("All variables are known; no calculation needed.\n");
//     }

//     return 0;
// }



//Q5. Write a void function named “equations” which solves simultaneous equations. Your
// program will take six parameters. E.g. function(double a, double b, double c, double d,
// double e, double f){}. By solving simultaneous equations, you are finding where the two
// lines cross each other, so your function should print an x and y coordinate.
// ax+by=c …...(i)
// dx+ey=f........(ii)
// a = number in front of x of equation one
// b = number in front of y of equation one
// c = constant of equation one
// d = number in front of x of equation two
// e = number in front of y of equation two
// f = constant of equation two


// #include <stdio.h>

// void equations(double a, double b, double c, double d, double e, double f) {
//     // ax + by = c
//     // dx + ey = f

//     double y = (a*f - c*d) / (a*e - b*d);

//     // Now that we have y, solve for x using Equation 1
//     double x = (c - b*y) / a;

//     printf("x = %.2f, y = %.2f\n", x, y);
// }

// int main() {

//     equations(1, 2, 3, 4, 5, 6);  // ax + by = c, dx + ey = f
//     return 0;
// }

//