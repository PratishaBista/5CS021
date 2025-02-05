// 1. Create a structure named student that has a name, roll number and marks as members. Assume appropriate types and size of members. Use this structure to read and display records of n number of students (n is given by the user). Create two functions: One is to read information of students and other to display the information.

// #include <stdio.h>

// // Define the structure for students
// struct Student {
//     char name[50];
//     int roll;
//     float marks;
// };

// // Function prototypes
// void readInfo(struct Student students[], int n);
// void displayInfo(struct Student students[], int n);

// int main() {
//     int n;

//     // Prompt user to enter the number of students
//     printf("Enter the number of students: ");
//     scanf("%d", &n);

//     // Array of students
//     struct Student students[n];

//     // Call functions to read and display student information
//     readInfo(students, n);
//     displayInfo(students, n);

//     return 0;
// }

// // Function to read information of students
// void readInfo(struct Student students[], int n) {
//     for (int i = 0; i < n; i++) {
//         printf("Enter details for student %d:\n", i + 1);
//         printf("Name: ");
//         scanf("%s", students[i].name); // Read the name
//         printf("Roll number: ");
//         scanf("%d", &students[i].roll); // Read the roll number
//         printf("Marks: ");
//         scanf("%f", &students[i].marks); // Read the marks
//     }
// }

// // Function to display information of students
// void displayInfo(struct Student students[], int n) {
//     printf("\nStudent Information:\n");
//     for (int i = 0; i < n; i++) {
//         printf("Student %d:\n", i + 1);
//         printf("Name: %s\n", students[i].name);
//         printf("Roll Number: %d\n", students[i].roll);
//         printf("Marks: %.2f\n", students[i].marks);
//     }
// }

// 2. WAP to input name, post and salary of ten employees from main () function and pass to structure type user defined function (argument of this function should also be a structure type). This function returns a structure variable which keeps the record of only those employees whose salary is greater than 10,000. This modified record is also displayed from the main () function

// #include <stdio.h>

// // Define the structure for Employee
// struct Employee {
//     char name[50];
//     char post[50];
//     float salary;
// };

// // Function to filter and display employees with salary > 10,000
// void filterAndDisplayEmployees(struct Employee employees[], int n) {
//     printf("\nEmployees with salary greater than 10,000:\n");
//     int count = 0;

//     for (int i = 0; i < n; i++) {
//         if (employees[i].salary > 10000) {
//             printf("Name: %s\n", employees[i].name);
//             printf("Post: %s\n", employees[i].post);
//             printf("Salary: %.2f\n\n", employees[i].salary);
//             count++;
//         }
//     }

//     if (count == 0) {
//         printf("No employees have a salary greater than 10,000.\n");
//     }
// }

// int main() {
//     struct Employee employees[10];
//     int n = 10;

//     // Input details of 10 employees
//     for (int i = 0; i < n; i++) {
//         printf("Enter details for employee %d:\n", i + 1);
//         printf("Name: ");
//         scanf("%s", employees[i].name);
//         printf("Post: ");
//         scanf("%s", employees[i].post);
//         printf("Salary: ");
//         scanf("%f", &employees[i].salary);
//         printf("\n");
//     }

//     // Call the function to filter and display employees
//     filterAndDisplayEmployees(employees, n);

//     return 0;
// }

// Write a program that asks the user for two inputs: lower limit and upper limit. Now
// write a function named display() that prints all the numbers between those limits.
// NOTE: You are only allowed to pass one parameter to the function and lower limit
// and upper limit variables should not be made as global variables.

// #include <stdio.h>

// struct LimitType
// {
//     int lower;
//     int upper;
// };

// void display (struct LimitType limit);

// int main ()
// {
//     if (limit.lower >= limit.upper || limit.upper < = limit.lower){
//         printf("Lower limit should be smaller than the upper limit and vice verca enter again, enter again:");
//         return 1
//     }
//     else {
//         continue;
//     }

// }

// #include <stdio.h>

// struct LimitType {
//     int lower;
//     int upper;
// };

// void display(struct LimitType number_between_limits) {
//     printf("Result: ", number_between_limits.lower, number_between_limits.upper);
//     for (int i = number_between_limits.lower + 1; i < number_between_limits.upper; i++) {
//         printf("%d ", i);
//     }
//     printf("\n");
// }

// struct LimitType getLimits() {
//     struct LimitType number_between_limits;
//     while (1) {
//         printf("Enter the lower and upper limits: ");
//         scanf("%d %d", &number_between_limits.lower, &number_between_limits.upper);

//         if (number_between_limits.upper > number_between_limits.lower) {
//             return number_between_limits;
//         } else {
//             printf("Upper limit should be greater than the lower limit. Please try again.\n");
//         }
//     }
// }

// int main() {
//     struct LimitType number_between_limits = getLimits();
//     printf("Lower limit: %d, Upper limit: %d\n", number_between_limits.lower, number_between_limits.upper);

//     display(number_between_limits);

//     return 0;
// }

// #include <stdio.h>

// struct LimitType {
//     int lower, upper;

// };

// // Updated display function to use a pointer
// void display(struct LimitType *number_between_limits) {
//     printf("Result (numbers between the given limits): ");
//     for (int i = number_between_limits->lower + 1; i < number_between_limits->upper; i++) {
//         printf("%d ", i);
//     }
// }

// // Updated getLimits function to remain the same (pass by value not needed here)
// struct LimitType getLimits() {
//     struct LimitType number_between_limits;
//     char True = 1;
//     while (True) {
//         printf("Enter the lower and upper limits: ");
//         scanf("%d %d", &number_between_limits.lower, &number_between_limits.upper);

//         if (number_between_limits.upper > number_between_limits.lower) {
//             return number_between_limits;
//         } else {
//             printf("Upper limit should be greater than the lower limit. Please try again.\n");
//         }
//     }
// }

// int main() {
//     // Get the limits (this still returns the structure by value)
//     struct LimitType number_between_limits = getLimits();

//     printf("Range: (%d-%d)\n", number_between_limits.lower, number_between_limits.upper);

//     // Pass the structure by reference to display function
//     display(&number_between_limits);

//     return 0;
// }

// #include <stdio.h>

// // Define the structure for limits
// struct Limits {
//     int lower;
//     int upper;
// };

// // Function to display numbers between the limits
// void display(struct Limits limits) {
//     for (int i = limits.lower + 1; i < limits.upper; i++) {
//         printf("%d ", i);
//     }
//     printf("\n");
// }

// int main() {
//     struct Limits limits;

//     // Input lower and upper limits
//     printf("Enter the lower limit: ");
//     scanf("%d", &limits.lower);

//     printf("Enter the upper limit: ");
//     scanf("%d", &limits.upper);

//     // Ensure the upper limit is greater than the lower limit
//     if (limits.upper <= limits.lower) {
//         printf("Invalid input! Upper limit must be greater than lower limit.\n");
//     } else {
//         printf("Numbers between %d and %d are:\n", limits.lower, limits.upper);
//         display(limits);
//     }

//     return 0;
// }

// Create a structure named Report_Card and inside that struct include two data
// members' student_name and roll_no, inside that struct student definition create
// another struct named subjects where you should include three data members i.e
// marks for NMC, OOPD, and AI and print it out for 3 students

#include <stdio.h>

// // Define the Report_Card structure with a nested Subjects structure
typedef struct 
{
    char student_name[30];
    int roll_no;
    struct
    {
        float NMC, OOPD, AI; // Nested structure for marks
    } marks;
}Report_Card;

int main()
{
    Report_Card student_reports[3];

    // Input student information
    for (int i = 0; i < 3; i++)
    {
        printf("Enter student %d's Name, Roll No, Marks of NMC, OOPD and AI: ", i + 1);
        scanf("%s %d %f %f %f", student_reports[i].student_name, &student_reports[i].roll_no, &student_reports[i].marks.NMC, &student_reports[i].marks.OOPD, &student_reports[i].marks.AI);
    }

    // Display student information
    printf("\nStudent Report Cards:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\nStudent %d:\nName: %s\nRoll No: %d\nMarks - NMC: %.2f, OOPD: %.2f, AI: %.2f\n",
               i + 1, student_reports[i].student_name, student_reports[i].roll_no,
               student_reports[i].marks.NMC, student_reports[i].marks.OOPD, student_reports[i].marks.AI);
    }

    return 0;
}

// 5. Write a structure to store the names, salary and hours of work per day of 5
//  employees in a company. Write a program to increase the salary depending on
//  the number of hours of work per day as follows and then print the name of all the
//  employees along with their final salaries.
//  Hours of work per
//  day
//  <6 >=6 && <=8 >8 && <=10 >10
//  Change in salary - $20 +$50 +$100 +$150

// #include <stdio.h>

// // Define the Employee structure
// struct Employee
// {
//     char name[30];
//     float salary;
//     float work_hour;
// };

// // Function to increase/decrease salary based on work hours
// void adjustSalary(struct Employee employee_details[])
// {
//     for (int i = 0; i < 5; i++)
//     {
//         if (employee_details[i].work_hour < 6)
//         {
//             employee_details[i].salary -= 20; // Decrease salary by $20
//         }
//         else if (employee_details[i].work_hour >= 6 && employee_details[i].work_hour <= 8)
//         {
//             employee_details[i].salary += 50; // Increase salary by $50
//         }
//         else if (employee_details[i].work_hour > 8 && employee_details[i].work_hour <= 10)
//         {
//             employee_details[i].salary += 100; // Increase salary by $100
//         }
//         else if (employee_details[i].work_hour > 10)
//         {
//             employee_details[i].salary += 150; // Increase salary by $150
//         }
//     }
// }

// // Function to print employee details
// void printEmployeeDetails(struct Employee employee_details[])
// {
//     printf("\nEmployee Details (after salary adjustment):\n");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("Name: %s\nSalary: $%.2f\n",
//                employee_details[i].name,
//                employee_details[i].salary);
//     }
// }

// int main()
// {
//     struct Employee employee_details[5];
//     printf("Enter employee name, salary, work hour:");
//     // Input employee details
//     for (int i = 0; i < 5; i++)
//     {
//         printf("For employee %d: \n", i + 1);
//         scanf("%s %f %f", employee_details[i].name, &employee_details[i].salary, &employee_details[i].work_hour);
//     }

//     // Adjust salary based on work hours
//     adjustSalary(employee_details);

//     // Print updated employee details
//     printEmployeeDetails(employee_details);

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// // Define the Employee structure
// struct Employee
// {
//     char name[30];
//     float salary;
//     float work_hour;
// };

// // Function to find and print the employee with the highest salary
// void findHighestSalary(struct Employee *employees, int n)
// {
//     float max_salary = employees[0].salary; // Initialize max salary with the first employee's salary
//     int max_index = 0;                      // Index of the employee with the highest salary

//     for (int i = 1; i < n; i++)
//     {
//         if (employees[i].salary > max_salary)
//         {
//             max_salary = employees[i].salary;
//             max_index = i;
//         }
//     }

//     printf("\nThe employee with the highest salary is:\n");
//     printf("Name: %s\nSalary: $%.2f\n", employees[max_index].name, employees[max_index].salary);
// }

// int main()
// {
//     int n;

//     // Get the number of employees
//     printf("How many employees details you want to store? ");
//     scanf("%d", &n);

//     // Dynamically allocate memory for 'n' Employee structures
//     struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));
//     if (employees == NULL)
//     {
//         printf("Memory allocation failed.\n");
//         return 1;
//     }

//     printf("Enter employee name, salary, work hour:\n");

//     // Input employee details
//     for (int i = 0; i < n; i++)
//     {
//         printf("\nEmployee %d: ", i + 1);
//         scanf("%s %f %f", employees[i].name, &employees[i].salary, &employees[i].work_hour);
//     }

//     // Find and print the employee with the highest salary
//     findHighestSalary(employees, n);

//     // Free dynamically allocated memory
//     free(employees);

//     return 0;
// }

// // Function to increase/decrease salary based on work hours
// void adjustSalary(struct Employee employee_details[])
// {
//     for (int i = 0; i < 5; i++)
//     {
//         // Determine the salary adjustment based on work hours
//         float adjustment = (employee_details[i].work_hour < 6)  ? -20 :
//                            (employee_details[i].work_hour <= 8) ? 50 :
//                            (employee_details[i].work_hour <= 10) ? 100 : 150;
//         employee_details[i].salary += adjustment;
//     }
// }

// // Function to print employee details
// void printEmployeeDetails(struct Employee employee_details[])
// {
//     printf("\nEmployee Name and Salary (after salary adjustment):\n");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("\n[%s, $%.2f]\n",
//                employee_details[i].name,
//                employee_details[i].salary);
//     }
// }

// int main()
// {
//     struct Employee employee_details[5];
// printf("Enter employee name, salary, work hour:\n");

// // Input employee details
// for (int i = 0; i < 5; i++)
// {
//     printf("\nEmployee %d:", i + 1);
//     scanf("%s %f %f", employee_details[i].name, &employee_details[i].salary, &employee_details[i].work_hour);
// }

//     // Adjust salary based on work hours
//     adjustSalary(employee_details);

//     // Print updated employee details
//     printEmployeeDetails(employee_details);

//     return 0;
// }
