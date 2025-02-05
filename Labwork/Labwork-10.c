// Write  a  multithreaded  C  program  with  three  threads that increment a shared
// counter.  Use  two  global  variables:  one  for  the  counter  and  one  for  a  check
// variable  that  stores  which  thread first reaches 50. Implement three functions:
// count_thread1(),  count_thread2()  and  count_thread3(),  where
// each thread increments the counter. When a thread reaches 50, it updates the
// check  variable  with  its  thread  number  (1,  2  or  3)  and  exits.  Ensure  proper
// synchronization to avoid race conditions when modifying the counter.The main
// function should print which thread first reached 50, based on the check variable.

#include <stdio.h>
#include <pthread.h>

int check = 0;
int count = 0;

pthread_mutex_t mutex;

void increment_counter(int thread_id)
{

    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (count >= 50)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        count++;
        printf("Thread %d is incrementing. Current count: %d\n", thread_id, count);

        if (count == 50 && check == 0)
        {
            check = thread_id;
        }
        pthread_mutex_unlock(&mutex);
    }
}

void *count_thread1(void *arg)
{
    increment_counter(1);
    return NULL;
}
void *count_thread2(void *arg)
{
    increment_counter(2);
    return NULL;
}
void *count_thread3(void *arg)
{
    increment_counter(3);
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, count_thread1, NULL);
    pthread_create(&t2, NULL, count_thread2, NULL);
    pthread_create(&t3, NULL, count_thread3, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Thread %d reached 50 first.\n", check);
    pthread_mutex_destroy(&mutex);
    return 0;
}

// Write a multithreaded C program where the user is prompted to enter a positive
// integer N. The program should create two threads, and both threads will call the
// same function, add_natural(), to compute the sum of the first N natural
// numbers. The shared variables sum (initialized to 0) and i (initialized to 1) should
// be used globally. Each thread will alternately add numbers to sum from 1 to N,
// and proper synchronization should be applied to avoid race conditions when
// updating these shared variables. After both threads have finished executing, the
// main function should print the total sum and indicate which thread added the final
// number to the sum. The program should ensure that each thread adds numbers
// one by one, and the last thread to add a number should be noted.

#include <stdio.h>
#include <pthread.h>

int sum = 0;  // To store the sum of numbers
int i = 1;    // To track the current number being added
int N;        // User-defined positive integer
int turn = 1; // To alternate between threads (1 for Thread 1, 2 for Thread 2)

pthread_mutex_t mutex;

void *add_natural(void *thread_id)
{
    int id = *(int *)thread_id;

    while (1)
    {
        pthread_mutex_lock(&mutex);

        if (i > N)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }

        if (turn == id)
        {
            sum += i;
            printf("Thread %d added %d. Current sum: %d\n", id, i, sum);

            i++;
            turn = (id == 1) ? 2 : 1;
        }

        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main()
{
    printf("Enter a positive integer N: ");
    scanf("%d", &N);

    pthread_t t1, t2;
    int id, id1 = 1, id2 = 2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, add_natural, &id1);
    pthread_create(&t2, NULL, add_natural, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Total sum of first %d natural numbers is: %d\n", N, sum);
    printf("Thread %d added the final number to the sum.\n", id);

    pthread_mutex_destroy(&mutex);

    return 0;
}
