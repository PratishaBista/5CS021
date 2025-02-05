#include <stdio.h>
#include <pthread.h>

int total_iterations;
int num_threads;
double pi_sum = 0.0;
pthread_mutex_t mutex;

/**
 * @brief Calculates a portion of the value of Pi using the Leibniz formula.
 *
 * This function is executed by each thread to calculate a part of Pi. 
 * Each thread computes a range of terms from the series based on the total 
 * number of iterations and the number of threads. The results are then 
 * accumulated in a shared variable, `pi_sum`, with thread synchronization
 * using a mutex to prevent race conditions.
 *
 * @param threadParams Pointer to the thread ID.
 * 
 * @return NULL (void return type for thread functions in C).
 */
void *calculate_pi(void *threadParams)
{
    int thread_id = *((int *)threadParams);

    int range = total_iterations / num_threads;
    int start_index = thread_id * range;
    int end_index = (thread_id == num_threads - 1) ? total_iterations - 1 : start_index + range - 1;

    for (int i = start_index; i <= end_index; i++)
    {
        double term = ((i % 2 == 0 ? 1 : -1) * 1.0) / (2 * i + 1);

        pthread_mutex_lock(&mutex);
        pi_sum += term;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

/**
 * @brief The main function that initializes the program, handles user input,
 *        creates threads, and calculates Pi.
 *
 * This function is responsible for:
 * - Asking the user to input the number of iterations and threads.
 * - Creating the threads to calculate parts of Pi.
 * - Synchronizing threads using `pthread_join`.
 * - Finalizing the result by multiplying the calculated sum by 4.
 *
 * @return 0 on successful completion of the program.
 */
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
            printf("%d %s %s quite not enough. For better accuracy, it is recommended at least 15 iterations.\nPlease enter again.\n",
                   total_iterations,
                   total_iterations == 1 ? "iteration" : "iterations",
                   total_iterations == 1 ? "is" : "are");
        }
    } while (total_iterations <= 0 || num_threads <= 0 || total_iterations < 15);

    pthread_mutex_init(&mutex, NULL);

    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    for (int i = 0; i < num_threads; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_pi, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    double pi_value = 4.0 * pi_sum;

    printf("Calculated value of Pi: %.15lf\n", pi_value);

    pthread_mutex_destroy(&mutex);

    return 0;
}
//=================================OUTPUT================================
// You will be asked to input two values:
// 1. Number of iterations (a positive integer).
//    - The higher the number of iterations, the more accurate the result.
//    - For basic calculations, you can use 15-100 iterations.
//    - For better accuracy, consider using 1000 or more iterations.
// 2. Number of threads (a positive integer).
//    - The number of threads determines how many parts the task is divided into.

// Enter the number of iterations: 4
// Enter the number of threads: 4
// 4 iterations are quite not enough. For better accuracy, it is recommended at least 15 iterations.
// Please enter again.
// Enter the number of iterations: 20
// Enter the number of threads: 3
// Calculated value of Pi: 3.091623806667839