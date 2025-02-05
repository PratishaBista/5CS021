// 1. Create a structure named employee having members: empName, age, and salary. Use this structure to read the name, age, and salary of the 5 employees and write entered information to a file employee.txt in D:\drive.
//  #include <stdio.h>

// struct Employee {
//     char empName[50];
//     int age;
//     float salary;
// };

// int main () {
//     int i;
//     struct Employee employee[5];
//     FILE *file;
//     file = fopen("C:\\Users\\USER\\Desktop\\employee.txt", "w");
//     if (file == NULL) {
//         printf("Error opening file.\n");
//         return 1;
//     }

//     printf("Enter 5 employee details:\n");

//     for (i = 0; i < 5; i ++)
//     {
//         printf("Enter employee name: ");
//         scanf("%s", employee[i].empName);
//         printf("Enter employee age: ");
//         scanf("%d", &employee[i].age);
//         printf("Enter employee salary: ");
//         scanf("%f", &employee[i].salary);
//         printf("\n");
//     }

//     for (i = 0; i<5; i++)
//     {
//         fprintf(file, "Employee %d:\n", i + 1);
//         fprintf(file, "Name:%s\n", employee[i].empName);
//         fprintf(file, "Age:%d\n", employee[i].age);
//         fprintf(file, "Salary:%.2f\n", employee[i].salary);
//     }

//     fclose(file);
//     printf("Successfully written to file.\n");
// }

// 2. WAP to copy content from employee.txt File to newemployee.txt file.

#include <stdio.h>

int main()
{
    FILE *originalFile, *newFile;
    char c;

    originalFile = fopen("C:\\Users\\USER\\Desktop\\employee.txt", "r");
    if (originalFile == NULL)
    {
        printf("Error: Could not open employee.txt for reading.\n");
        return 1;
    }

    newFile = fopen("C:\\Users\\USER\\Desktop\\newemployee.txt", "w");
    if (newFile == NULL)
    {
        printf("Error: Could not open newemployee.txt for writing.\n");
        fclose(originalFile);
        return 1;
    }

    while ((c = fgetc(originalFile)) != EOF)
    {
        fputc(c, newFile);
    }

    fclose(originalFile);
    fclose(newFile);

    printf("File copied successfully.\n");
    return 0;
}


// 3. WAP to add new employee details in newemployee.txt file

#include <stdio.h>

int main()
{
    // Open the new file in append mode
    FILE *newFile = fopen("C:\\Users\\USER\\Desktop\\newemployee.txt", "a");
    if (newFile == NULL)
    {
        printf("Error: Could not open newemployee.txt for appending.\n");
        return 1;
    }

    // Append new employee details to the file
    fprintf(newFile, "\nNew Employee Details:\n");
    fprintf(newFile, "Name: Jane Smith\n");
    fprintf(newFile, "Position: Project Manager\n");
    fprintf(newFile, "Salary: $95,000\n");

    // Close the file
    fclose(newFile);

    printf("New employee details appended successfully.\n");
    return 0;
}


// 4. Write a program in C to read integers from the user until the user says "no". After
//  reading the data write all the odd numbers to a file named odd.txt and all the
//  even numbers to file even.txt.

#include <stdio.h>

int main()
{
    FILE *oddFile, *evenFile;
    int num;

    // Open the files in write mode
    oddFile = fopen("odd.txt", "w");
    evenFile = fopen("even.txt", "w");
    if (oddFile == NULL || evenFile == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read numbers from the user until they say "no"
    printf("Enter numbers (type 'no' to stop):\n");

    while (1)
    {
        printf("Enter an integer (or type 'no' to stop): ");
        if (scanf("%d", &num) == 1)  // Check if the input is a valid integer
        {
            if (num % 2 == 0)
                fprintf(evenFile, "%d\n", num); // Write even number to even.txt
            else
                fprintf(oddFile, "%d\n", num);  // Write odd number to odd.txt
        }
        else
        {
            char stop[4];
            scanf("%s", stop); // Read input like "no"
            if (stop[0] == 'n' && stop[1] == 'o')
                break; // Exit loop if user types "no"
            else
                scanf("%d", &num); // If invalid input, prompt again
        }
    }

    // Close the files
    fclose(oddFile);
    fclose(evenFile);

    printf("Odd and even numbers have been written to the respective files.\n");

    return 0;
}

// struct Employee {
//     char name[50];
//     int age;
//     float salary;
// }

// int main () {
//     FILE *file;
//     file = fopen("C:\\Users\\USER\\Desktop\\sample.txt", "w");

//     for (int i = 0; i < 5; i ++) {
//         scanf()

//     }

// }