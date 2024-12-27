// 1. Write a C program that opens a text file called data.txt for writing, and
// writes "Hello, World!" to the file, and then closes the file. If the file doesn't
// exist, create it.

// #include <stdio.h>

// int main()
// {
//     FILE *fp;
//     char filename[] = "data.txt";
//     char message[] = "Hello, World!";

//     fp = fopen(filename, "w");
//     if (fp == NULL)
//     {
//         printf("There is an error opening the file %s\n", filename);
//         return 1;
//     }
//     fprintf(fp, "%s", message);
//     fclose(fp);
//     return 0;
// }

// 2. Write a C program to demonstrate the all three file opening modes:
// "r" (read mode) - to open an existing file for reading.
// "w" (write mode) - to create a new file or overwrite an existing file.
// "a" (append mode) - to open a file for appending data at the end.
// First open in “w” mode to write a sentence to a file named demo.txt, then
// read it in “r” mode and print in console. Then open it in “a” mode to add
// another sentence, and again read it in “r” mode to print both sentences in
// the console.

#include <stdio.h>

int main () {
    FILE *fp;
    char filename[] = "demo.txt";
    char message[] = "This is a demo file.";
    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("There is an error opening the file %s\n", filename);
        return 1;
    }

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("There is an error opening the file %s\n", filename);
        return 1;
    }

    fp = fopen(filename, "a");
    if (fp == NULL){
        printf("There is an error opening the file %s\n", filename);
        return 1;
    }


    }





// 3. Write a C program that accepts an integer from the user and stores it in a
// file called numbers.txt. Ensure that the program creates the file if it
// doesn't exist.

// 4. Write a C program that reads an integer from a file called numbers.txt and prints it to the console.
// The integer was stored earlier by the program in Question 3