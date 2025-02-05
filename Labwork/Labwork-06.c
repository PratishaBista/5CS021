// 1. Create a structure named student having members: studentName, age and marks. Use this
// structure to read the name, age and salary of n (ask from user) employees and write entered
// information to a file student.txt.
// 2. Write a program to read information from the above file student.txt.
// 3. WAP to add n number of new students in the employee.txt file (open file in “a” mode).
// 4. Write a C program to read integers from the user until the user inputs "stop". Save all prime
// numbers to a file named prime.txt and all composite numbers to a file named composite.txt.
// 5. Write a program to combine the contents of prime.txt and composite.txt into a new file called
// numbers_combined.txt.
// 6. Write a c program to read integers from the user and append the sum to the end in the file
// name sum.txt.

// #include <stdio.h>

// typedef struct
// {
//     char studentName[30];
//     int age;
//     float marks;
// } Student;

// int main()
// {
//     int n;
//     printf("How many students' details do you want to store? ");
//     scanf("%d", &n);

//     Student students[n];
//     FILE *file = fopen("student.txt", "w");

//     printf("Enter details of students (Name Age Marks)");

//     for (int i = 0; i < n; i++)
//     {
//         printf("Student %d: ", i + 1);
//         scanf("%s %d %f", students[i].studentName, &students[i].age, &students[i].marks);
//         fprintf(file, "Student %d:\nName: %s\nAge: %d\nMarks: %.2f\n\n",
//                 i + 1, students[i].studentName, students[i].age, students[i].marks);
//     }

//     fclose(file);
//     printf("Student details saved to student.txt\n");
//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     FILE *fp;
//     char ch;

//     // Open the file in read mode
//     fp = fopen("student.txt", "r");
//     printf("Contents of the file student.txt:\n");

//     // Read and display the file contents character by character
//     while ((ch = fgetc(fp)) != EOF)
//     {
//         putchar(ch);
//     }

//     // Close the file
//     fclose(fp);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int isPrime(int num);

// int main() {
//     char stopString[20];
//     int num, i = 0;
//     int True = 1;
//     FILE *primeFile, *compositeFile;

//     // Open files for writing
//     primeFile = fopen("prime.txt", "w");
//     compositeFile = fopen("composite.txt", "w");

//     // Write labels to both files
//     fprintf(primeFile, "The prime numbers are: ");
//     fprintf(compositeFile, "The composite numbers are: ");

//     printf("Enter the number (or type 'stop' to finish)\n");
//     while (True) {
//         printf("Number %d: ", i + 1);
//         scanf("%s", stopString);

//         // Exit if user types "stop"
//         if (strcmp(stopString, "stop") == 0) break;

//         num = atoi(stopString); // Convert input to an integer

//         // Write the number to the appropriate file
//         if (isPrime(num)) {
//             fprintf(primeFile, "%d ", num); // Write prime number to prime.txt
//         } else {
//             fprintf(compositeFile, "%d ", num); // Write composite number to composite.txt
//         }
//         i++;
//     }

//     // Close the files
//     fclose(primeFile);
//     fclose(compositeFile);

//     printf("Numbers have been saved to prime.txt and composite.txt.\n");
//     return 0;
// }

// int isPrime(int num) {
//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0) return 0; //not prime (composite)
//     }
//     return 1; // prime
// }






// #include <stdio.h>

// typedef struct
// {
//     char studentName[30];
//     int age;
//     float marks;
// } Student;

// int main()
// {
//     int n;
//     printf("How many students' details do you want to store? ");
//     scanf("%d", &n);

//     Student students[n];
//     // Open the file in append mode to add data without overwriting
//     FILE *file = fopen("student.txt", "a");

//     if (file == NULL) {
//         printf("Error opening file!\n");
//         return 1;
//     }

//     printf("Enter details of students (Name Age Marks)\n");

//     for (int i = 0; i < n; i++)
//     {
//         printf("Student %d: ", i + 1);
//         scanf("%s %d %f", students[i].studentName, &students[i].age, &students[i].marks);
//         fprintf(file, "Student %d:\nName: %s\nAge: %d\nMarks: %.2f\n\n",
//                 i + 1, students[i].studentName, students[i].age, students[i].marks);
//     }

//     fclose(file);
//     printf("Student details added to student.txt\n");
//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int num, sum = 0;
//     char choice;
    
//     printf("Enter two numbers:\n");
//     scanf("%d %d", &num);
//         sum += num;

//     do {
//         printf("Do you want to enter another number? (y/n): ");
//         scanf(" %c", &choice);

//         if (choice == 'y' || choice == 'Y') {
//             printf("Enter the number: ");
//             scanf("%d", &num);
//             sum += num; // Add the additional number to the sum
//         }
//     } while (choice == 'y' || choice == 'Y');

//     // Write the sum to the file
//     FILE *fp = fopen("sum.txt", "a");

//     fprintf(fp, "Sum: %d\n", sum); // Append the sum to the file
//     fclose(fp);

//     printf("Sum appended to sum.txt\n");
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *primeFile, *compositeFile, *mergedFile;

    // Open the source files for reading
    primeFile = fopen("prime.txt", "r");
    compositeFile = fopen("composite.txt", "r");

    // Open the destination file for writing
    mergedFile = fopen("numbers_combined.txt", "w");

    char line[256];
    fprintf(mergedFile, "Contents from prime.txt\n");
    while (fgets(line, sizeof(line), primeFile)) {
        fputs(line, mergedFile);
    }

    // Add a separator between contents
    fprintf(mergedFile, "\n\n");

    // Read from compositeFile and write to mergedFile
    fprintf(mergedFile, "Contents from composite.txt\n");
    while (fgets(line, sizeof(line), compositeFile)) {
        fputs(line, mergedFile);
    }

    // Close all the files
    fclose(primeFile);
    fclose(compositeFile);
    fclose(mergedFile);

    printf("Contents of prime.txt and composite.txt have been merged into merged.txt.\n");

    return 0;
}
