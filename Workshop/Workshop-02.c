//Q1. write a void function which finds and prints the midpoint coordinates of a line. The function should take in four parameters: (x1, y1, x2, and y2)
// xmid = (x1 + x2) / 2, ymid = (y1 + y2) / 2

// #include <stdio.h>

// void midpoint(int x1, int y1, int x2, int y2) {
//     int xmid = (x1 + x2) /2;
//     int ymid = (y1 + y2) /2;
//     printf("The midpoint is (%d, %d)", xmid, ymid);

// }
// int main () {
//     midpoint(1, 2, 3, 4);
//     return 0;
// }
//Q2. write a function that takes two integers as arguments and return the greatest among them.

// #include <stdio.h>

// int greatest (int a, int b) {
//     if (a > b) {
//         printf("%d is greater than %d", a, b);
//     } else {
//         printf("%d is greater than %d", b, a);
//     }
// }
// int main () {
//     greatest(1, 2);
//     return 0;
// }


//Q3. Write a void fucnction which takes one integer (n) as a parameter. Your fucntion should then print out all triangular numbers from 1 up to the nth term.
// #include <stdio.h>

// void triangular(int n) {
//     int sum = 0;
//     for (int i = 1; i <= n; i++) {
//         sum += i;
//         printf("T%d = %d\n", i, sum);
//     }
// }
// int main () {
//     triangular(5);
//     return 0;
// }

//Q4. Write a function named "velocityCalc" which returns an appropriate value for the formula "v= u + at", where v is the final velocity, u is the initial velocity, a is the acceleration and t is the time that has elapsed. Depending upon which variable is set to "NAN" when the function is called, your function should work it out and return the value. 

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
