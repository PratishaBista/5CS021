//example of malloc()

// #include <stdio.h>
// #include <stdlib.h>

// void main() {
//     int a[8];
//     int *p = &a[0];
//     // p = (int *)malloc(8 * sizeof(int));

//     int i, j;
//     printf("Enter the elements of the array: ");
//     for (i = 0; i < 8; i++) {
//         scanf("%d", p + i);
//     }

//     for(j = 0; j < 8; j++) {
//         printf("%d ", *(p + j));
//     }
    
// }
// #include <stdio.h>
// #include <stdlib.h>

// void main () {
//     int *p, n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     p = (int *)malloc(n * sizeof(int));

//     int i, j;

//     printf("Enter %d elements: ", n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", p + i);
//     }

//     printf("The elements are: ");
//     for (j = 0; j < n; j++) {
//         printf("%d ", *(p + j));
//     }
// }

//example of calloc()

// #include <stdio.h>
// #include <stdlib.h>

// void main () {
//     int *p, n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     p = (int *) calloc(n, sizeof(int));

//     int i, j;

//     // printf("Enter %d elements: ", n);
//     // for (i = 0; i < n; i++) {
//     //     scanf("%d", p + i);
//     // }

//     printf("The elements are: ");
//     for (j = 0; j < n; j++) {

//         printf("%d ", *(p + j));
//     }
// }

//examples of realloc()

#include <stdio.h>
#include <stdlib.h>

void main () {

    int *p, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    p = (int *) malloc(n * sizeof(int));
    p = realloc(p, (n + 1) * sizeof(int));

    int i, j;

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", p + i);
    }

    printf("The elements are: ");
    for (j = 0; j < n; j++) {
        printf("%d ", *(p + j));
    }   

    free(p);
} 
