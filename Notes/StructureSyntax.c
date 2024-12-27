// struct structure_name
// {
//     data_type member1;
//     data_type member2;
//     data_type member3;
//     .
//     .
//     .
//     data_type memberN;
// };

// struct Book {
//     char title[50];
//     int pages;
//     float price;
// };

struct Book books;

// #include <stdio.h>

// struct Book
// {
//     char title[50];
//     int pages;
//     float price;
// } books[3];

// int main()
// {
//     strcpy(books[0].title, "C Programming");
//     books[0].pages = 350;
//     books[0].price = 29.99;

//     strcpy(books[1].title, "Data Structures");
//     books[1].pages = 450;
//     books[1].price = 39.99;

//     strcpy(books[2].title, "Algorithms");
//     books[2].pages = 500;
//     books[2].price = 49.99;
//     for (int i = 0; i < 3; i++)
//     {
//         printf("Book %d:\n", i + 1);
//         printf("Title: %s\n", books[i].title);
//         printf("Pages: %d\n", books[i].pages);
//         printf("Price: $%.2f\n\n", books[i].price);
//     }

// } 


// #include <stdio.h>

struct Book {
    char title[50];
    int pages;
    float price;
};

// Declare and initialize the array of 3 Book structures
struct Book books[3] = {
    {"C Programming", 350, 29.99},
    {"Data Structures", 450, 39.99},
    {"Algorithms", 500, 49.99}
}; //array of 3 book structures

int main() {
    // Print the book details
    for (int i = 0; i < 3; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Pages: %d\n", books[i].pages);
        printf("Price: $%.2f\n\n", books[i].price);
    }

    return 0;
}

// #include <stdio.h>

// struct Book {
//     char title[50];
//     int pages;
//     float price;
// };

// // Declare an array of 3 Book structures
// struct Book books[3];

// int main() {
//     // Get input from the user
//     for (int i = 0; i < 3; i++) {
//         printf("Enter details for Book %d:\n", i + 1);

//         printf("Title: ");
//         scanf(" %[^\n]", books[i].title); // %[^\n] reads a line of input until newline

//         printf("Pages: ");
//         scanf("%d", &books[i].pages);

//         printf("Price: ");
//         scanf("%f", &books[i].price);

//         printf("\n");
//     }

//     // Print the book details
//     printf("You entered the following book details:\n");
//     for (int i = 0; i < 3; i++) {
//         printf("Book %d:\n", i + 1);
//         printf("Title: %s\n", books[i].title);
//         printf("Pages: %d\n", books[i].pages);
//         printf("Price: $%.2f\n\n", books[i].price);
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h> // For malloc and free

struct Book {
    char title[50];
    int pages;
    float price;
};

int main() {
    struct Book* books;
    int n;

    // Ask the user how many books they want to enter
    printf("How many books do you want to enter? ");
    scanf("%d", &n);

    books = (struct Book*)malloc(n * sizeof(struct Book));
    if (books == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with error
    }

    // Get input for each book
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Book %d:\n", i + 1);

        printf("Title: ");
        scanf(" %[^\n]", books[i].title);

        printf("Pages: ");
        scanf("%d", &books[i].pages);

        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    // Print the book details
    printf("\nYou entered the following book details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Pages: %d\n", books[i].pages);
        printf("Price: $%.2f\n", books[i].price);
    }

    // Free the dynamically allocated memory
    free(books);

    return 0;
}
