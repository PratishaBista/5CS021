// Q1.Apply a negative filter on an image file.This is the process of reversing the RGB
//     values.For example,
//     if the Red value of the pixel is 100, the inverse is 155. NOTE : 0 is minimum and 255 is maximum.

#include "lodepng.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *input_file = "input.png";
    const char *output_file = "output_negative.png";
    unsigned char *image;
    unsigned width, height;

    lodepng_decode32_file(&image, &width, &height, input_file);

    printf("Image dimensions: %ux%u, Total Pixels: %u, Total Bytes: %u\n", width, height, width * height, width * height * 4);

    for (unsigned i = 0; i < width * height * 4; i += 4)
    {
        image[i] = 255 - image[i];         // Red
        image[i + 1] = 255 - image[i + 1]; // Green
        image[i + 2] = 255 - image[i + 2]; // Blue
    }

    lodepng_encode32_file(output_file, image, width, height);
    printf("File saves as %s", output_file);

    free(image);
    return 0;
}

// Q2.Write a program that reads an image file into a 1D array and converts it into a
//     grayscale image.A color of gray is one in which Red = Green = Blue.Large values
//     are white and small values are black.An easy way to make an grayscale image
//     out of color is to set each color value to the average of all three : gray = (R + G + B) / 3;
// R = gray;
// G = gray;
// B = gray;

#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"

int main()
{
    const char *input_filename = "input.png";
    const char *output_filename = "output_grayscale.png";
    unsigned char *image;
    unsigned width, height;

    lodepng_decode32_file(&image, &width, &height, input_filename);
    printf("Image dimensions: %ux%u, Total Pixels: %u, Total bytes: %u\n", width, height, width * height, width * height * 4);

    for (unsigned i = 0; i < width * height * 4; i += 4)
    {
        unsigned char gray = (image[i] + image[i + 1] + image[i + 2]) / 3; // Grayscale value
        image[i] = image[i + 1] = image[i + 2] = gray;                     // Set R, G, B to grayscale
    }

    lodepng_encode32_file(output_filename, image, width, height);
    printf("Grayscale image saved as %s", output_filename);

    free(image);
    return 0;
}

// Q3.Write a program that reads an image file and stores its data in a 1D array.Then,
//     ask the user how many pixels to change to black from the right and bottom edges
//         of the image.For example,
//     if the original image size is 10 x 10, and the user specifies changing 2 pixels from the right and 3 pixels from the bottom to black,
//     the new image will have black pixels in those areas while keeping the rest of the
//         image unchanged.Finally,
//     save the modified image as a new file


#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"

int main()
{
    unsigned char *image;
    unsigned width, height, right, bottom;
    const char *input_file = "input.png";
    const char *output_file = "output_black.png";

    lodepng_decode32_file(&image, &width, &height, input_file);

    printf("Original Image Dimensions: %u x %u, Total Pixels: %u, Total bytes: %u\n", width, height, width * height, width * height * 4);

    printf("Enter pixels to black out from right and bottom: ");
    scanf("%u %u", &right, &bottom);

    for (unsigned y = height - bottom; y < height; y++)
    {
        for (unsigned x = 0; x < width; x++)
        {
            image[4 * (y * width + x)] = image[4 * (y * width + x) + 1] = image[4 * (y * width + x) + 2] = 0;
        }
    }

    for (unsigned x = width - right; x < width; x++)
    {
        for (unsigned y = 0; y < height; y++)
        {
            image[4 * (y * width + x)] = image[4 * (y * width + x) + 1] = image[4 * (y * width + x) + 2] = 0;
        }
    }

    lodepng_encode32_file(output_file, image, width, height);
    printf("Image saved as %s", output_file);

    free(image);
    return 0;
}

// Q4. Write a program that reads an image file and stores its data in a 1D array. Then
// ask the user to enter a number from -255 to 255 (to either darken or brighten the
// image). Then add or subtract that number from each pixel value (except for
// transparency) and make sure the pixel value stays within the range 0 to 255, so a
// certain validation check must be done.


#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"

int main()
{
    const char *input_file = "input.png";
    const char *output_file = "brightened_output.png";
    unsigned char *image;
    unsigned width, height;
    int adjustment;

    lodepng_decode32_file(&image, &width, &height, input_file);

    printf("Image dimensions (width x height): %u x %u, Total Pixels (width * height): %u, Total bytes (width*height*4): %u\n", width, height, width * height, width * height * 4);

    do
    {
        printf("Enter brightness adjustment (-255 to 255): ");
        scanf("%d", &adjustment);
        if (adjustment < -255 || adjustment > 255)
        {
            printf("Error: The number must be between -255 and 255.\n");
        }
    } while (adjustment < -255 || adjustment > 255); 

    for (unsigned i = 0; i < width * height * 4; i += 4)
        for (int j = 0; j < 3; j++)
            image[i + j] = (image[i + j] + adjustment > 255) ? 255 : (image[i + j] + adjustment < 0) ? 0
                                                                                                     : image[i + j] + adjustment;

    lodepng_encode32_file(output_file, image, width, height);
    printf("File saved as %s", output_file);

    free(image);
    return 0;
}
