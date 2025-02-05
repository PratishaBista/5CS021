#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "lodepng.h"
#include "lodepng.c"

const float gaussian_kernel[3][3] = {
    {0.0625f, 0.1250f, 0.0625f},
    {0.1250f, 0.2500f, 0.1250f},
    {0.0625f, 0.1250f, 0.0625f}};

typedef struct
{
    unsigned char *image;
    unsigned char *output;
    unsigned width;
    unsigned height;
    int start;
    int end;
} ThreadParams;

/**
 * applies a gaussian blur filter to a section of the image.
 *
 * @param data a struct containing the image data, output buffer, dimensions, and row range.
 * @return void (no return value).
 */

void apply_gaussian_blur(ThreadParams *data)
{
    int kernel_radius = 3 / 2;
    unsigned char *image = data->image;
    unsigned char *output = data->output;
    unsigned width = data->width;
    unsigned height = data->height;
    int start = data->start;
    int end = data->end;

    for (int row = start; row < end; row++)
    {
        for (int col = 0; col < width; col++)
        {
            float red_sum = 0, green_sum = 0, blue_sum = 0;
            float weight_sum = 0;

            for (int kernel_row = -kernel_radius; kernel_row <= kernel_radius; kernel_row++)
            {
                for (int kernel_col = -kernel_radius; kernel_col <= kernel_radius; kernel_col++)
                {
                    int neighbor_col = col + kernel_col;
                    int neighbor_row = row + kernel_row;

                    /** If the target pixel is at (row, col), the neighboring pixels are:
                    Top-left: (row - 1, col - 1)
                    Top-center: (row - 1, col)
                    Top-right: (row - 1, col + 1)
                    Left: (row, col - 1)
                    Right: (row, col + 1)
                    Bottom-left: (row + 1, col - 1)
                    Bottom-center: (row + 1, col)
                    Bottom-right: (row + 1, col + 1)
                    */

                    if (neighbor_col >= 0 && neighbor_col < width && neighbor_row >= 0 && neighbor_row < height)
                    {
                        int neighbor_index = 4 * (neighbor_row * width + neighbor_col);
                        float weight = gaussian_kernel[kernel_row + kernel_radius][kernel_col + kernel_radius];
                        red_sum += image[neighbor_index] * weight;
                        green_sum += image[neighbor_index + 1] * weight;
                        blue_sum += image[neighbor_index + 2] * weight;
                        weight_sum += weight;
                    }
                }
            }
            int pixel_index = 4 * (row * width + col);
            output[pixel_index] = (unsigned char)(red_sum / weight_sum);
            output[pixel_index + 1] = (unsigned char)(green_sum / weight_sum);
            output[pixel_index + 2] = (unsigned char)(blue_sum / weight_sum);
            output[pixel_index + 3] = image[pixel_index + 3];
        }
    }
}

/**
 * thread function that applies gaussian blur to a portion of the image.
 *
 * @param threadParams pointer to a ThreadParams struct containing the image section to process.
 * @return always returns NULL.
 */
void *thread_function(void *threadParams)
{
    apply_gaussian_blur((ThreadParams *)threadParams);
    return NULL;
}

/**
 * loads an image, applies a gaussian blur using multithreading, and saves the output image.
 *
 * @param input_path file path of the input png image.
 * @param output_path file path to save the processed output image.
 * @return 0 on success, 1 on failure.
 */
int process_image(const char *input_path, const char *output_path)
{
    unsigned char *image = NULL, *output = NULL;
    unsigned width, height;

    if (lodepng_decode32_file(&image, &width, &height, input_path) != 0)
    {
        printf("Error: Could not load the image.\n");
        return 1;
    }

    int center_row = height / 2;
    int center_col = width / 2;
    printf("Image dimensions: %dx%d\n", width, height);
    printf("Total values: %d\n", width * height * 4);
    printf("Center pixel: (%d, %d)\n", center_col, center_row);

    printf("\nNeighbors of the center pixel:\n");
    for (int dr = -1; dr <= 1; dr++)
    {
        for (int dc = -1; dc <= 1; dc++)
        {
            int neighbor_row = center_row + dr;
            int neighbor_col = center_col + dc;

            if (neighbor_row >= 0 && neighbor_row < height && neighbor_col >= 0 && neighbor_col < width)
            {
                int index = 4 * (neighbor_row * width + neighbor_col);
                printf("Pixel at (%d, %d): R=%d, G=%d, B=%d, A=%d\n",
                       neighbor_row, neighbor_col,
                       image[index], image[index + 1], image[index + 2], image[index + 3]);
            }
        }
    }

    output = (unsigned char *)malloc(width * height * 4);
    if (!output)
    {
        printf("Error: Could not allocate memory for the output image.\n");
        free(image);
        return 1;
    }

    pthread_t threads[4];
    ThreadParams thread_data[4];
    int rows_per_thread = height / 4;

    for (int i = 0; i < 4; i++)
    {
        thread_data[i] = (ThreadParams){image, output, width, height, i * rows_per_thread, (i == 4 - 1) ? height : (i + 1) * rows_per_thread};
        pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    if (lodepng_encode32_file(output_path, output, width, height) != 0)
    {
        printf("Error: Could not save the output image.\n");
        free(image);
        free(output);
        return 1;
    }

    printf("\nOutput saved to: %s\n", output_path);
    free(image);
    free(output);
    return 0;
}

/**
 * entry point of the program, processes an image using gaussian blur.
 *
 * @return 0 if the image processing is successful, 1 if an error occurs.
 */
int main()
{
    return process_image("input.png", "output.png");
}
