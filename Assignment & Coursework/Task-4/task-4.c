/**
 * @file task-4.c
 * @brief Multi-threaded Gaussian Blur filter for PNG images.
 * 
 * This program applies a Gaussian blur filter to an input PNG image using multiple threads.
 * It reads an image, processes it using pthreads, and then saves the blurred image.
 * 
 * Usage:
 *  - Compile with: gcc -pthread task-4.c -o task-4 -lpthread 
 *  - Run: ./task-4.exe (on windows)
 *  - Enter the input PNG filename, output PNG filename, and number of threads.
 * 
 * Features:
 *  - Uses a 3x3 Gaussian kernel to blur the image.
 *  - Supports multi-threading for efficient processing.
 *  - Reads and writes PNG images using the LodePNG library.
 * 
 * @author Pratisha Bista
 * @student_id 2408284
 */

#include <pthread.h> 
#include <stdio.h>   
#include <stdlib.h> 
#include "lodepng.h" 
#include "lodepng.c"

unsigned char *blurredImg;
unsigned char *originalImg;
unsigned imgWidth, imgHeight;

const float kernel[3][3] = {
    {1 / 16.0, 2 / 16.0, 1 / 16.0},
    {2 / 16.0, 4 / 16.0, 2 / 16.0},
    {1 / 16.0, 2 / 16.0, 1 / 16.0}
};

struct ThreadRange {
    unsigned int startRow;
    unsigned int endRow;
};

void *applyGaussianBlur(void *arg) {
    struct ThreadRange *range = (struct ThreadRange *)arg;
    int startRow = range->startRow;
    int endRow = range->endRow;

    for (int y = startRow; y <= endRow; y++) {
        for (int x = 0; x < imgWidth; x++) {
            float red = 0, green = 0, blue = 0, alpha = 0;

            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int pixelX = x + kx;
                    int pixelY = y + ky;

                    if (pixelX >= 0 && pixelX < imgWidth && pixelY >= 0 && pixelY < imgHeight) {
                        int pixelIndex = (pixelY * imgWidth + pixelX) * 4;
                        float weight = kernel[ky + 1][kx + 1];

                        red += originalImg[pixelIndex] * weight;
                        green += originalImg[pixelIndex + 1] * weight;
                        blue += originalImg[pixelIndex + 2] * weight;
                        alpha += originalImg[pixelIndex + 3] * weight;
                    }
                }
            }

            int outputIndex = (y * imgWidth + x) * 4;
            blurredImg[outputIndex] = (unsigned char)red;
            blurredImg[outputIndex + 1] = (unsigned char)green;
            blurredImg[outputIndex + 2] = (unsigned char)blue;
            blurredImg[outputIndex + 3] = (unsigned char)alpha;
        }
    }

    pthread_exit(NULL);
}

int main() {
    unsigned error;
    char inputFile[50], outputFile[50];

    printf("Enter input PNG file name: ");
    scanf("%s", inputFile);

    error = lodepng_decode32_file(&originalImg, &imgWidth, &imgHeight, inputFile);
    if (error) {
        printf("Error decoding image %u: %s\n", error, lodepng_error_text(error));
        return 1;
    }
    
    printf("Image dimensions: Width = %u px, Height = %u px\n", imgWidth, imgHeight);

    printf("Enter output PNG file name: ");
    scanf("%s", outputFile);

    blurredImg = (unsigned char *)malloc(imgWidth * imgHeight * 4 * sizeof(unsigned char));

    int numThreads;
    printf("Enter the number of threads: ");
    scanf("%d", &numThreads);

    int rowsPerThread = imgHeight / numThreads;
    int extraRows = imgHeight % numThreads; 

    struct ThreadRange threadRanges[numThreads];
    pthread_t threads[numThreads];

    int currentStartRow = 0;

    for (int i = 0; i < numThreads; i++) {
        threadRanges[i].startRow = currentStartRow;
        threadRanges[i].endRow = currentStartRow + rowsPerThread - 1;

        if (extraRows > 0) {
            threadRanges[i].endRow++;
            extraRows--;
        }

        currentStartRow = threadRanges[i].endRow + 1;

        pthread_create(&threads[i], NULL, applyGaussianBlur, &threadRanges[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    error = lodepng_encode32_file(outputFile, blurredImg, imgWidth, imgHeight);
    if (error) {
        printf("Error encoding image %u: %s\n", error, lodepng_error_text(error));
        return 1;
    }

    printf("Blurred image saved successfully.\n");

    free(blurredImg);
    free(originalImg);

    return 0;
}
