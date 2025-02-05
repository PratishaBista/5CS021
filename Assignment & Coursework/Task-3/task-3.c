#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAX_NUMBERS 1000  
#define NUM_THREADS 4      

pthread_mutex_t lock;  

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
            pthread_mutex_lock(&lock);  
            fprintf(outputFile, "%d\n", numbersArray[i]);
            primeCount++;
            pthread_mutex_unlock(&lock);  
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

    pthread_mutex_init(&lock, NULL);

    pthread_t threads[NUM_THREADS];
    struct ThreadData threadData[NUM_THREADS];

    int baseSize = totalNumbers / NUM_THREADS;
    int extra = totalNumbers % NUM_THREADS;

    int startIndex = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].startIndex = startIndex;
        threadData[i].endIndex = startIndex + baseSize - 1;
        if (i < extra) {
            threadData[i].endIndex++;  
        }
        startIndex = threadData[i].endIndex + 1;

        pthread_create(&threads[i], NULL, find_primes, &threadData[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total Prime Numbers: %d\n", primeCount);

    pthread_mutex_destroy(&lock);
    free(numbersArray);

    return 0;
}
