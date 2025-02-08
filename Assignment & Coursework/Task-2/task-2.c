/**
 * @file task-2.c
 * @brief Multi-threaded computation of Pi using the Leibniz series.
 * 
 * This program approximates the value of Pi using the Leibniz formula:
 * 
 *      Pi ≈ 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
 * 
 * The computation is divided among multiple threads, where each thread
 * calculates a portion of the series and contributes to the final sum.
 * 
 * Usage:
 *  - Compile with: gcc -pthread task-2.c -o task-2
 *  - Run: ./task-2.exe (on windows)
 *  - Input the number of iterations (higher values improve accuracy).
 *  - Input the number of threads to divide the workload.
 * 
 * Features:
 *  - User-defined number of iterations for precision.
 *  - Multi-threaded execution for computation.
 *  - Dynamic memory allocation for efficient storage of partial sums.
 *  - Outputs an approximation of Pi with 15 decimal places.
 * 
 * @author Pratisha Bista
 * @student_id 2408284
 * @last_modified 2025-02-08 18:19:52
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

//global variables
int total_iterations;
int num_threads;
double *thread_sums; //array to store the sum calculated by each thread

/*
 * Function to calculate a part of Pi using the Leibniz formula.
 * Pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
 * Each thread calculates a portion of the sum based on the given range.
 *
 * Parameters:
 * - threadParams: Pointer to the thread ID.
 *
 * Returns:
 * - NULL: Function does not return any value (void).
 */
void *calculate_pi(void *threadParams)
{
    int thread_id = *((int *)threadParams);

    int range = total_iterations / num_threads;
    int start_index = thread_id * range;
    int end_index = (thread_id == num_threads - 1) ? total_iterations - 1 : start_index + range - 1;

    double local_sum = 0.0;

    for (int i = start_index; i <= end_index; i++)
    {
        local_sum += pow(-1, i) / (2 * i + 1);
    }

    thread_sums[thread_id] = local_sum;

    return NULL;
}

int main()
{
    printf("You will be asked to input two values:\n");
    printf("1. Number of iterations (a positive integer).\n");
    printf("   - The higher the number of iterations, the more accurate the result.\n");
    printf("   - For basic calculations, you can use 15-100 iterations.\n");
    printf("   - For better accuracy, consider using 1000 or more iterations.\n");
    printf("2. Number of threads (a positive integer).\n");
    printf("   - The number of threads determines how many parts the task is divided into.\n\n");

    do
    {
        printf("Enter the number of iterations: ");
        scanf("%d", &total_iterations);

        printf("Enter the number of threads: ");
        scanf("%d", &num_threads);

        if (total_iterations <= 0 || num_threads <= 0)
        {
            printf("Invalid input. Both values must be positive integers.\n");
        }
        else if (total_iterations < 15)
        {
            printf("Try at least 15 iterations for accuracy.\n");
        }
    } while (total_iterations <= 0 || num_threads <= 0 || total_iterations < 15);

    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    thread_sums = (double *)malloc(num_threads * sizeof(double));
    if (thread_sums == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < num_threads; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_pi, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    double pi_sum = 0.0;
    for (int i = 0; i < num_threads; i++)
    {
        pi_sum += thread_sums[i];
    }

    free(thread_sums);

    printf("\nCalculated value of Pi: %.15lf\n", 4.0 * pi_sum);

    return 0;
}
