// #include "lodepng.h"
// #include <stdio.h>
// #include <stdlib.h>

// void apply_negative_filter(unsigned char* image, unsigned width, unsigned height) {
//     for (unsigned i = 0; i < width * height * 4; i += 4) {
//         image[i] = 255 - image[i];
//         image[i + 1] = 255 - image[i + 1];
//         image[i + 2] = 255 - image[i + 2];
//     }
// }

// int main() {
//     const char* input_file = "pink.png";
//     const char* output_file = "pink_negative.png";
//     unsigned char* image;
//     unsigned width, height;
//     unsigned error;

//     error = lodepng_decode32_file(&image, &width, &height, input_file);
//     if (error) {
//         printf("Error %u: %s\n", error, lodepng_error_text(error));
//         return 1;
//     }

//     printf("Image loaded: %ux%u pixels\n", width, height);
//     apply_negative_filter(image, width, height);

//     error = lodepng_encode32_file(output_file, image, width, height);
//     if (error) {
//         printf("Error %u: %s\n", error, lodepng_error_text(error));
//     } else {
//         printf("Negative image saved to: %s\n", output_file);
//     }

//     free(image);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"

void convert_to_grayscale(unsigned char* image, unsigned width, unsigned height) {
    for (unsigned i = 0; i < width * height * 4; i += 4) {
        unsigned char R = image[i];
        unsigned char G = image[i + 1];
        unsigned char B = image[i + 2];
        unsigned char gray = (R + G + B) / 3;
        image[i] = gray;
        image[i + 1] = gray;
        image[i + 2] = gray;
    }
}

int main() {
    const char* input_filename = "pink.png";
    const char* output_filename = "pink_grayscale.png";

    unsigned char* image;
    unsigned width, height;

    unsigned error = lodepng_decode32_file(&image, &width, &height, input_filename);
    if (error) {
        printf("Error decoding PNG: %s\n", lodepng_error_text(error));
        return 1;
    }

    printf("Original image dimensions: %ux%u\n", width, height);
    convert_to_grayscale(image, width, height);

    error = lodepng_encode32_file(output_filename, image, width, height);
    if (error) {
        printf("Error encoding PNG: %s\n", lodepng_error_text(error));
        free(image);
        return 1;
    }

    printf("Grayscale image saved as '%s'\n", output_filename);

    free(image);

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include "lodepng.h"

// void make_pixels_black(unsigned char* image, unsigned width, unsigned height, unsigned right, unsigned bottom) {
//     for (unsigned y = height - bottom; y < height; y++) {
//         for (unsigned x = 0; x < width; x++) {
//             unsigned idx = 4 * (y * width + x);
//             image[idx] = 0;
//             image[idx + 1] = 0;
//             image[idx + 2] = 0;
//         }
//     }
//     for (unsigned x = width - right; x < width; x++) {
//         for (unsigned y = 0; y < height; y++) {
//             unsigned idx = 4 * (y * width + x);
//             image[idx] = 0;
//             image[idx + 1] = 0;
//             image[idx + 2] = 0;
//         }
//     }
// }

// int main() {
//     unsigned char* image;
//     unsigned width, height;
//     const char* input_file = "pink.png";
//     const char* output_file = "pink_black.png";
//     unsigned error;

//     error = lodepng_decode32_file(&image, &width, &height, input_file);
//     if (error) {
//         printf("Error %u: %s\n", error, lodepng_error_text(error));
//         return 1;
//     }

//     printf("Image dimensions: %u x %u\n", width, height);
//     printf("Each pixel contains 4 components (R, G, B, A).\n");

//     unsigned right, bottom;
//     printf("Enter the number of pixels to black out from the right edge: ");
//     scanf("%u", &right);
//     printf("Enter the number of pixels to black out from the bottom edge: ");
//     scanf("%u", &bottom);

//     if (right > width || bottom > height) {
//         printf("Error: Specified pixels exceed image dimensions.\n");
//         free(image);
//         return 1;
//     }

//     make_pixels_black(image, width, height, right, bottom);

//     error = lodepng_encode32_file(output_file, image, width, height);
//     if (error) {
//         printf("Error %u: %s\n", error, lodepng_error_text(error));
//         free(image);
//         return 1;
//     }

//     printf("Modified image saved as '%s'.\n", output_file);

//     free(image);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "lodepng.h"

// void adjust_brightness(unsigned char* image, unsigned width, unsigned height, int adjustment) {
//     for (unsigned y = 0; y < height; y++) {
//         for (unsigned x = 0; x < width; x++) {
//             unsigned idx = 4 * (y * width + x);
            
//             for (int i = 0; i < 3; i++) {
//                 int new_value = image[idx + i] + adjustment;
//                 if (new_value > 255) {
//                     image[idx + i] = 255;
//                 } else if (new_value < 0) {
//                     image[idx + i] = 0;
//                 } else {
//                     image[idx + i] = new_value;
//                 }
//             }
//         }
//     }
// }

// int main() {
//     unsigned char* image;
//     unsigned width, height;
//     const char* input_file = "pink.png";
//     const char* output_file = "output.png";
//     unsigned error;

//     error = lodepng_decode32_file(&image, &width, &height, input_file);
//     if (error) {
//         printf("Error %u: %s\n", error, lodepng_error_text(error));
//         return 1;
//     }

//     printf("Image dimensions: %u x %u\n", width, height);
//     printf("Each pixel contains 4 components (R, G, B, A).\n");

//     int adjustment;
//     printf("Enter a number from -255 to 255 to adjust brightness (-255 to darken, 255 to brighten): ");
//     scanf("%d", &adjustment);

//     if (adjustment < -255 || adjustment > 255) {
//         printf("Error: The number must be between -255 and 255.\n");
//         free(image);
//         return 1;
//     }

//     adjust_brightness(image, width, height, adjustment);

//     error = lodepng_encode32_file(output_file, image, width, height);
//     if (error) {
//         printf("Error %u: %s\n", error, lodepng_error_text(error));
//         free(image);
//         return 1;
//     }

//     printf("Modified image saved as '%s'.\n", output_file);

//     free(image);

//     return 0;
// }
