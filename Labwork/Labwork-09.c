// 1. Write a program that creates two threads to display the numbers from 1-1000. The two
// threads should equally contribute to displaying the numbers.

// #include <pthread.h>
// #include <stdio.h>

// void *printNumbers(void *arg)
// {
//     int thread_id = *(int *)arg; 
//     int start_index = thread_id * (1000 / 2) + 1; 
//     int end_index = start_index + (1000 / 2) - 1; 

//     for (int i = start_index; i <= end_index; i++)
//     {
//         printf("%d (Thread %d)\n", i, thread_id + 1);
//     }

//     return NULL;
// }

// int main()
// {
//     pthread_t threads[2]; 
//     int thread_ids[2] = {0, 1};

//     for (int i = 0; i < 2; i++)
//     {
//         pthread_create(&threads[i], NULL, printNumbers, &thread_ids[i]);
//     }

//     for (int i = 0; i < 2; i++)
//     {
//         pthread_join(threads[i], NULL);
//     }

//     return 0;
// }


// 2. Write a program that creates two threads to display all the prime numbers from 1-500.
// The two threads should equally contribute to displaying the numbers.

// #include <pthread.h>
// #include <stdio.h>
// #include <stdbool.h>

// bool isPrime(int n)
// {
//     if (n <= 1)
//         return false;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

// void *printPrimes(void *arg)
// {
//     int thread_id = *(int *)arg; 
//     int start_index = thread_id * (500 / 2) + 1; 
//     int end_index = start_index + (500 / 2) - 1;

//     for (int i = start_index; i <= end_index; i++)
//     {
//         if (isPrime(i))
//         {
//             printf("%d (Thread %d)\n", i, thread_id + 1);
//         }
//     }

//     return NULL;
// }

// int main()
// {
//     pthread_t threads[2];
//     int thread_ids[2] = {0, 1};

//     for (int i = 0; i < 2; i++)
//     {
//         pthread_create(&threads[i], NULL, printPrimes, &thread_ids[i]);
//     }

//     for (int i = 0; i < 2; i++)
//     {
//         pthread_join(threads[i], NULL);
//     }

//     return 0;
// }


// 3. Write a program that creates 5 threads to display the numbers from 1-1000.The five
// threads should equally contribute to display the numbers.

// #include <pthread.h>
// #include <stdio.h>

// void *printNumbers(void *arg)
// {
//     int thread_id = *(int *)arg; // Get thread ID

//     int start_index = thread_id * (1000 / 5) + 1; 
//     int end_index = start_index + (1000 / 5) - 1; 

//     for (int i = start_index; i <= end_index; i++)
//     {
//         printf("%d (Thread %d)\n", i, thread_id + 1);
//     }

//     return NULL;
// }

// int main()
// {
//     pthread_t threads[5];
//     int thread_ids[5] = {0, 1, 2, 3, 4};

//     for (int i = 0; i < 5; i++)
//     {
//         pthread_create(&threads[i], NULL, printNumbers, &thread_ids[i]);
//     }

//     for (int i = 0; i < 5; i++)
//     {
//         pthread_join(threads[i], NULL);
//     }

//     return 0;
// }


// 4. Convert program no.3 to accept an integer to specify the number of threads and then
// create that number of threads dynamically. All the threads will equally contribute to
// display the numbers from 1-1000.

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>

// void *printNumbers(void *arg) {
//     int *args = (int *)arg;
//     int thread_id = args[0];
//     int num_threads = args[1];
    
//     free(arg); 
//     int start = thread_id * (1000 / num_threads) + 1;             
//     int end = (thread_id == num_threads - 1) ? 1000 : start + (1000 / num_threads) - 1;

//     for (int i = start; i <= end; i++) {
//         printf("%d (Thread %d)\n", i, thread_id + 1);
//     }

//     return NULL;
// }

// int main() {
//     int num_threads;

//     printf("Enter the number of threads: ");
//     scanf("%d", &num_threads);

//     pthread_t threads[num_threads];

//     for (int i = 0; i < num_threads; i++) {
//         int *thread_arg = malloc(2 * sizeof(int)); 
//         thread_arg[0] = i;      
//         thread_arg[1] = num_threads; 

//         pthread_create(&threads[i], NULL, printNumbers, thread_arg);
//     }

//     for (int i = 0; i < num_threads; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     return 0;
// }


//5. Create a multithreaded program to display all the odd numbers from 1-1000. Your
// program should ask the user to input the number of threads. Based on the number of
// threads you should divide the workload among the threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printOddNumbers(void *arg) {
    int *args = (int *)arg;
    int thread_id = args[0];
    int num_threads = args[1];

    free(arg); 
    int start_index = thread_id * (1000 / num_threads) + 1;
    int end_index = (thread_id == num_threads - 1) ? 1000 : start_index + (1000 / num_threads) - 1;

    for (int i = start_index; i <= end_index; i++) {
        if (i % 2 != 0) { 
            printf("%d (Thread %d)\n", i, thread_id + 1);
        }
    }

    return NULL;
}

int main() {
    int num_threads;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);


    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        int *thread_arg = malloc(2 * sizeof(int)); 
        thread_arg[0] = i;       // Thread ID
        thread_arg[1] = num_threads; // Total number of threads

        pthread_create(&threads[i], NULL, printOddNumbers, thread_arg);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

//6. search an element in an array using thread

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>

// int array[5] = {1, 2, 3, 4, 5};
// int target = 5;

// void *search(void *arg) {
//     int thread_id = *(int *)arg;
//     free(arg);

//     for (int i = thread_id; i < 5; i += 2) {
//         if (array[i] == target) {
//             printf("Element found\n");
//         }
//     }

//     return NULL;
// }

// int main() {
//     pthread_t threads[2];

//     for (int i = 0; i < 2; i++) {
//         int *thread_arg = malloc(sizeof(int)); 
//         *thread_arg = i;                     
//         pthread_create(&threads[i], NULL, search, thread_arg);
//     }

//     for (int i = 0; i < 2; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     return 0;
// }



