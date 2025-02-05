#include <stdio.h>
#include <stdlib.h>

/**
 * Reads data from a file and stores x and y coordinates.
 * 
 * @param filename The name of the file to be read.
 * @param x_coordinate Array to store x coordinates.
 * @param y_coordinate Array to store y coordinates.
 * @param count The number of data points read from the file.
 * @return 0 if successful, -1 if an error occurs.
 */
int read_file(const char *filename, float *x_coordinate, float *y_coordinate, int *count)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open %s", filename);
        return -1;
    }

    char line[20]; 
    *count = 0;  

    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "%f,%f", &x_coordinate[*count], &y_coordinate[*count]) == 2)
        {
            (*count)++;
        }
    }

    fclose(file);
    return 0; 
}

/**
 * Calculates the slope (b) and intercept (a) for linear regression.
 * 
 * @param x Array of x coordinates.
 * @param y Array of y coordinates.
 * @param n Number of data points.
 * @param a Pointer to store the intercept value.
 * @param b Pointer to store the slope value.
 */
void calculate_linear_regression(float *x, float *y, int n, float *a, float *b)
{
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;

    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
    }

    // Calculate the slope (b)
    *b = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);

    // Calculate the intercept (a)
    *a = (sum_y * sum_x_squared - sum_x * sum_xy) / (n * sum_x_squared - sum_x * sum_x);
}

/**
 * Displays the equation of the line in the form y = bx + a.
 * 
 * @param a The intercept value.
 * @param b The slope value.
 */
void display_equation(float a, float b)
{
    printf("The equation of the line is: y = %.2fx + %.2f\n", b, a);
}

/**
 * Calculates the value of y given x using the linear equation y = bx + a.
 * 
 * @param a The intercept value.
 * @param b The slope value.
 * @param x The x value.
 * @return The calculated y value.
 */
float calculate_y(float a, float b, float x)
{
    return (b * x) + a;
}

int main()
{
    float x[1000], y[1000];
    int count = 0;
    float a = 0, b = 0;

    for (int i = 1; i <= 4; i++)
    {
        char filename[50];
        sprintf(filename, "datasetLR%d.txt", i); 

        if (read_file(filename, x, y, &count) != 0)
        {
            printf("Cannot read %s\n", filename);
            return 1; 
        }
    }

    calculate_linear_regression(x, y, count, &a, &b);

    display_equation(a, b);

    float x_input;
    printf("Enter a value for x: ");
    scanf("%f", &x_input);
    printf("Calculated y: %.2f\n", calculate_y(a, b, x_input));

    return 0;
}

// ===================OUTPUT=======================
// The equation of the line is: y = 0.17x + 171.62
// Enter a value for x: 9
// Calculated y: 173.16