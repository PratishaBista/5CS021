//print hello world and explain its structure 
// #include <stdio.h>
// void main () {
//     printf("Hello World!");
// }




//add two numbers (statically and dynamically) and print the result
//dynamic
// #include <stdio.h>
// int main (){
//     int a, b;
//     printf("Enter the value of a: ");
//     scanf("%d", &a);
    
//     printf("Enter the value of b: ");
//     scanf("%d", &b);
    
//     int sum = a + b;
//     printf("The sum of %d and %d is: %d", a, b, sum);
    
//     return 0;
// }

//static

// #include <stdio.h>
// int main (){
//     int a=2, b=1;
//     int sum = a + b;
//     printf("The sum of %d and %d is: %d", a, b, sum);
    
//     return 0;
// }

//interest find

// #include <stdio.h>
// int main (){
//     int p, t;
//     float r;
    
//     printf("Enter the principal amount, time in years and rate of interest (enter space to write another value): ");
//     scanf("%d %d %f", &p, &t, &r);
    
//     float i = (p * t * r)/ 100;
//     printf("The interest amount is: %.2f ", i);
//     return 0;
// }

//temperature conversion


// #include <stdio.h>
// int main (){
//     float c;
    
//     printf("Enter the temp in celsius: ");
//     scanf("%f", &c);
    
//     float f = 32 + ((c * 9)/5);
//     printf("The temperature in fahrenheit is: %.2f ", f);
//     return 0;
// }



//odd even

// #include <stdio.h>
// int main (){
//     int n;
//     printf("Enter any number: ");
//     scanf("%d", &n);
    
//     if(n%2==1){
//         printf("odd -.-");
//     }
//     else {
//         printf("even :)");
//     }
    
//     return 0;
// }


//man am i the greatest
// #include <stdio.h>
// int main (){
//     int x, y, z;
//     printf("enter the values for x, y and z: ");
//     scanf("%d %d %d", &x, &y, &z);
    
//     if (x>y && x>z){
//         printf("x is greater");
//     }
//     else if (y>x && y>z){
//         printf("y is greater");
//     }
    
//     else {
//         printf("z is greater");
//     }
    
//     return 0;
    
// }


//printing even numbers

// #include <stdio.h>
// int main (){
//     int i;
//     for (i = 2; i<=100; i+=2){
//         printf("%d\n", i);
//     }
    
//     return 0;
    
// }


//multiplication table

// #include <stdio.h>
// int main (){
//     int num, i;
    
//     printf("Enter the number: ");
//     scanf("%d", &num);
   
//     for (i = 1; i<=10; i++){
//         int res = num * i;
//         printf("%d x %d = %d\n", num, i, res);
//     }
    
//     return 0;
    
// }


//pattern programming

#include <stdio.h>
int main (){
    int i, j;
   
    for (i = 1; i<=5; i+=1){
        for (j = 1; j<=i+1; j++){
            printf("%d", i);
    }
    printf("\n");
    }
    
    return 0;
    
}
