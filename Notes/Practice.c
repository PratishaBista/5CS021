// #include <stdio.h>
// void reverseArray(int *arr, int size)
// {
//     int temp;
//     for (int i = 0; i < size / 2; i++)
//     {
//         temp = arr[i];
//         arr[i] = arr[size - i - 1];
//         arr[size - i - 1] = temp;
//     }
// }
// void printArray(int *arr, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     reverseArray(arr, size);
//     printArray(arr, size);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// int *createArray(int size)
// {
//     int *arr = (int *)malloc(size * sizeof(int));
//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = i + 1;
//     }
//     return arr;
// }
// void freeArray(int *arr)
// {
//     free(arr);
// }
// int main()
// {
//     int size = 5;
//     int *arr = createArray(size);
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     freeArray(arr);
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     FILE *fp = fopen("data.txt", "w+");
//     if (!fp)
//     {
//         printf("File cannot be opened\n");
//         return 1;
//     }
//     fprintf(fp, "Hello, World!\nWelcome to File Handling in C.");
//     rewind(fp);
//     char ch;
//     while ((ch = fgetc(fp)) != EOF)
//     {
//         putchar(ch);
//     }
//     fclose(fp);
//     return 0;
// }

// #include <stdio.h>
// int factorial(int n)
// {
//     if (n == 0)
//         return 1;
//     return n * factorial(n - 1);
// }
// int main()
// {
//     int num = -3;
//     printf("Factorial of %d is %d\n", num, factorial(num));
//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// void compressString(char *str, char *result)
// {
//     int count = 1;
//     int j = 0;
//     for (int i = 1; i <= strlen(str); i++)
//     {
//         if (str[i] == str[i - 1])
//         {
//             count++;
//         }
//         else
//         {
//             result[j++] = str[i - 1];
//             if (count > 1)
//             {
//                 j += sprintf(&result[j], "%d", count);
//             }
//             count = 1;
//         }
//     }
//     result[j] = '\0';
// }
// int main()
// {
//     char str[100], result[200];
//     printf("Enter a string: ");
//     scanf("%s", str);
//     compressString(str, result);
//     printf("Compressed string: %s\n", result);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &cols);
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }
    printf("Sum of all elements: %d\n", sum);
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
