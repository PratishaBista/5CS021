/**
 * @file task-3.c
 * @brief Multi-threaded prime number finder from multiple files.
 * 
 * This program reads numbers from three input files and uses multi-threading to find prime numbers.
 * The prime numbers are written to an output file ("output.txt").
 * 
 * Usage:
 *  - Compile with: gcc -pthread task-3.c -o task-3 
 *  - Run: ./task-3.exe (on windows)
 *  - Ensure input files "PrimeData1.txt", "PrimeData2.txt", and "PrimeData3.txt" exist with integer data.
 * 
 * Features:
 *  - Reads numbers from three text files.
 *  - Uses four threads to check for prime numbers in parallel.
 *  - Stores prime numbers in "output.txt" using thread-safe file operations.
 *  - Utilizes mutex locks to avoid race conditions while writing to the output file.
 * 
 * @author Pratisha Bista
 * @student_id 2408284
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
 
pthread_mutex_t mutex;  

int *numbersArray;      
int primeCount = 0;    

struct ThreadData {
    int startIndex, endIndex;
};

int is_prime(int number) {
    if (number < 2) return 0;
    if (number == 2) return 1;
    if (number % 2 == 0) return 0;

    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

void *find_primes(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    int start = data->startIndex;
    int end = data->endIndex;

    FILE *outputFile = fopen("output.txt", "a"); 
    if (!outputFile) {
        perror("Error opening output file");
        pthread_exit(NULL);
    }

    for (int i = start; i <= end; i++) {
        if (is_prime(numbersArray[i])) {
            pthread_mutex_lock(&mutex);  
            fprintf(outputFile, "%d\n", numbersArray[i]);
            primeCount++;
            pthread_mutex_unlock(&mutex);  
        }
    }

    fclose(outputFile); 
    pthread_exit(NULL);
}

int main() {
    FILE *file1, *file2, *file3;
    int totalNumbers = 0, tempNum;

    file1 = fopen("PrimeData1.txt", "r");
    file2 = fopen("PrimeData2.txt", "r");
    file3 = fopen("PrimeData3.txt", "r");

    if (!file1 || !file2 || !file3) {
        perror("Error opening input files");
        return 1;
    }

    while (fscanf(file1, "%d", &tempNum) != EOF) totalNumbers++;
    while (fscanf(file2, "%d", &tempNum) != EOF) totalNumbers++;
    while (fscanf(file3, "%d", &tempNum) != EOF) totalNumbers++;

    printf("Total numbers in all 3 files: %d\n", totalNumbers);

    numbersArray = (int *)malloc(totalNumbers * sizeof(int));
    if (!numbersArray) {
        perror("Memory allocation failed");
        return 1;
    }

    rewind(file1);
    rewind(file2);
    rewind(file3);

    int index = 0;
    while (fscanf(file1, "%d", &numbersArray[index]) != EOF) index++;
    while (fscanf(file2, "%d", &numbersArray[index]) != EOF) index++;
    while (fscanf(file3, "%d", &numbersArray[index]) != EOF) index++;

    fclose(file1);
    fclose(file2);
    fclose(file3);

    pthread_mutex_init(&mutex, NULL);

    pthread_t threads[1000];
    struct ThreadData threadData[4];

    int baseSize = totalNumbers / 4;
    int extra = totalNumbers % 4;

    int startIndex = 0;
    for (int i = 0; i < 4; i++) {
        threadData[i].startIndex = startIndex;
        threadData[i].endIndex = startIndex + baseSize - 1;
        if (i < extra) {
            threadData[i].endIndex++;  
        }
        startIndex = threadData[i].endIndex + 1;

        pthread_create(&threads[i], NULL, find_primes, &threadData[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total Prime Numbers: %d\n", primeCount);

    pthread_mutex_destroy(&mutex);
    free(numbersArray);

    return 0;
}
