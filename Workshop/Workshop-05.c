//1. Create a structure to hold any complex number x+iy. Write a program that uses the structure to read two complex numbers and display a third complex number

//any complex number x + iy;
#include <stdio.h>

typedef struct Complex {
    float x;
    float y;
} Complex;



Complex addComplexNumbers(Complex n1, Complex n2){
    Complex result;
    result.x = n1.x + n2.x;
    result.y = n1.y + n2.y;
    return result;
};

// int main () {
//     Complex n1, n2, result;
//     printf("Enter the real and imaginary parts of the first complex number: ");
//     scanf("%f %f", &n1.x, &n1.y);

//     printf("Enter the real and imaginary parts of the second complex number: ");
//     scanf("%f %f", &n2.x, &n2.y);

//     result = addComplexNumbers(n1, n2);
//     printf("The sum of the complex numbers is: %.2f + %.2fi\n", result.x, result.y);

//     return 0;
    
// }
//2. Write a program that uses the above structure to input two complex numbers and pass them to function, which returns the sum of entered complex numbers in the main function and displays the sum.

// #include <stdio.h>

// typedef struct Complex {
//     float x;
//     float y;
// } Complex;

// int main () {
//     Complex n1, n2, result;
//     printf("Enter the real and imaginary parts of the first complex number: ");
//     scanf("%f %f", &n1.x, &n1.y);

//     printf("Enter the real and imaginary parts of the second complex number: ");
//     scanf("%f %f", &n2.x, &n2.y);

//     result.x = n1.x + n2.x;
//     result.y = n1.y + n2.y;
//     printf("The sum of the complex numbers is: %.2f + %.2fi\n", result.x, result.y);

//     return 0;
    
// }

//3. Create a structure named student that has a name, roll number and marks as members. Assume appropriate types and size of members. Use this structure to read and display records of 10 students. Create two functions: One is to read information of students and other to display the information

// #include <stdio.h>
// #include <string.h>


// typedef struct Student {
//     char name[50];
//     int rollNumber;
//     float marks;

// } Student;


// int takeInfo(Student s[10]){
//     int i;
//     for (i = 0; i < 10; i++){
//         printf("Enter the name of student %d: ", i + 1);
//         scanf("%s", s[i].name);
//         printf("Enter the roll number of student %d: ", i + 1);
//         scanf("%d", &s[i].rollNumber);
//         printf("Enter the marks of student %d: ", i + 1);
//         scanf("%f", &s[i].marks);
//     }
//     return 0;
// }

// int displayInfo(Student s[10]){
//     int i;
//     for (i = 0; i < 10; i++){
//         printf("Name: %s\n", s[i].name);
//         printf("Roll number: %d\n", s[i].rollNumber);
//         printf("Marks: %.2f\n", s[i].marks);
//         return 0;
//     }
// }

// int main (){
//     Student s[10];
//     takeInfo(s);
//     displayInfo(s);
//     return 0;
// }

//4. 