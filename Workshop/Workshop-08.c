// gcc -pthread Workshop-08.c -o Workshop-08
// gcc -pthread your_program.c -o (.exe file name)

// Write a program that creates two threads to display the numbers from 1 - 1000. The two threads should equally contribute to display the numbers.

#include <pthread.h>
#include <stdio.h>

void *threadOne(void *p)
{
    for (int i = 1; i <= 500; i++)
    {
        printf("%d (thread one)\n", i);
    }
}

void *threadTwo(void *p)
{
    for (int i = 501; i <= 1000; i++)
    {
        printf("%d (thread two)\n", i);
    }
}
void main()
{
    pthread_t printer_1_to_500, printer_501_to_1000;
    pthread_create(&printer_1_to_500, NULL, threadOne, NULL);
    pthread_create(&printer_501_to_1000, NULL, threadTwo, NULL);
    pthread_join(printer_1_to_500, NULL);
    pthread_join(printer_501_to_1000, NULL);
}

// Write a program that creates 5 threads to display the numbers from 1-1000.The five threads should equally contribute to display the numbers.

// #include <pthread.h>
// #include <stdio.h>

// #define MAX_NUMBER 1000

// void *threadOne(void *p) {
//     for (int i = 1; i <= 200; i++) {
//         printf("Thread One: %d\n", i);
//     }
//     return NULL;
// }

// void *threadTwo(void *p) {
//     for (int i = 201; i <= 400; i++) {
//         printf("Thread Two: %d\n", i);
//     }
//     return NULL;
// }

// void *threadThree(void *p) {
//     for (int i = 401; i <= 600; i++) {
//         printf("Thread Three: %d\n", i);
//     }
//     return NULL;
// }

// void *threadFour(void *p) {
//     for (int i = 601; i <= 800; i++) {
//         printf("Thread Four: %d\n", i);
//     }
//     return NULL;
// }

// void *threadFive(void *p) {
//     for (int i = 801; i <= 1000; i++) {
//         printf("Thread Five: %d\n", i);
//     }
//     return NULL;
// }

// int main() {
//     pthread_t thrID1, thrID2, thrID3, thrID4, thrID5;

//     pthread_create(&thrID1, NULL, threadOne, NULL);
//     pthread_create(&thrID2, NULL, threadTwo, NULL);
//     pthread_create(&thrID3, NULL, threadThree, NULL);
//     pthread_create(&thrID4, NULL, threadFour, NULL);
//     pthread_create(&thrID5, NULL, threadFive, NULL);

//     pthread_join(thrID1, NULL);
//     pthread_join(thrID2, NULL);
//     pthread_join(thrID3, NULL);
//     pthread_join(thrID4, NULL);
//     pthread_join(thrID5, NULL);

//     return 0;
// }
#include <pthread.h>
#include <stdio.h>

void *printNumbers(void *arg) {
    int thread_id = *(int *)arg;
    for (int i = thread_id + 1; i <= 1000; i += 5) {
        printf("Thread %d: %d\n", thread_id + 1, i);
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];

    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, printNumbers, &thread_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// Convert program no. 2 to accept an integer to specify the number of threads and then create that number of threads dynamically.
// All the threads will equally contribute to display the numbers from 1-1000
