// 1. Apply a negative filter on an image file. This is the process
// of reversing the RGB values. For example, if the Red value
// of the pixel is 100, the inverse is 155. NOTE: 0 is minimum
// and 255 is maximum.
// 2. Write a program that reads an image file into 1D array and
// converts it into a grayscale image. A color of gray is one in
// which Red=Green=Blue. Large values are white and small
// values are black.
// An easy way to make an grayscale image out of color is to
// set each color value to the average of all three:
// gray=(R+G+B)/3;
// R=gray; G=gray; B=gray;
// 3. Write a program to crop a PNG image to a specified
// rectangular region. Input: start_x, start_y, width, and
// height for the region to crop.
// 4. Write a program to overlay text on a PNG image at a
// specified location.
// 5. Write a program to flip a PNG image horizontally or vertically
// based on user input.
// Adding a Border:
// 6. Implement a program to rotate a PNG image by 90, 180, or
// 270 degrees.


include "lodepng.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int error;
unsigned char *image;
unsigned int width, height;
char *filename = "tony.png";

int main () {
    // Decode the image from the file
    error = lodepng_decode32_file(&image, &width, &height, filename);
    if (error) {
        printf("Error %d: %s\n", error, lodepng_error_text(error));
        return -1;
    }

    // Invert the colors of the image (negative)
    for (unsigned int i = 0; i < width * height; ++i) {
        unsigned int pixelIndex = i * 4;

        image[pixelIndex] = 255 - image[pixelIndex];         // Red
        image[pixelIndex + 1] = 255 - image[pixelIndex + 1]; // Green
        image[pixelIndex + 2] = 255 - image[pixelIndex + 2]; // Blue
    }

    // Encode the modified image to a new file
    error = lodepng_encode32_file("tony_negative.png", image, width, height);
    if (error) {
        printf("Error %d: %s\n", error, lodepng_error_text(error)); // Handle errors
        free(image); // Free the memory
        return -1;
    }

    // Free the image memory after processing is complete
    free(image);

    printf("Image processing complete, saved as 'tony_negative.png'\n");
    return 0;
}



