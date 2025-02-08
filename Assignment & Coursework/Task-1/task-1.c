/**
 * @file task-1.c
 * @brief Multi-file linear regression calculator using the least squares method.
 * 
 * This program reads data points (x, y) from multiple files and calculates
 * the equation of the regression line using the formula:
 * 
 *      y = b * x + a
 * 
 * Where:
 *      - b (slope) = (n * Σxy - Σx * Σy) / (n * Σx² - (Σx)²)
 *      - a (intercept) = (Σy - b * Σx) / n
 * 
 * Features:
 *  - Reads data from four separate text files.
 *  - Computes the best-fit line using least squares regression.
 *  - Allows the user to input an x-value to predict the corresponding y-value.
 * 
 * Usage:
 *  - Ensure that datasetLR1.txt, datasetLR2.txt, datasetLR3.txt, and datasetLR4.txt 
 *    exist in the same directory and contain comma-separated (x, y) values.
 *  - Compile with: gcc -pthread task-1.c -o task-1
 *  - Run: ./task-1.exe (on windows)
 * 
 * @author Pratisha Bista
 * @student_id 2408284
 * @last_modified 2025-02-08
 */

#include <stdio.h>
#include <stdlib.h>

void calculate_linear_regression();  

int main()
{
    calculate_linear_regression();  
    return 0;
}

/**
 * @brief Reads data points from multiple files and calculates the regression line equation.
 *
 * This function reads (x, y) values from four text files, sums up the required values, 
 * and calculates the slope (b) and intercept (a) of the regression line using the 
 * least squares method. It then predicts a y-value for a given x-input from the user.
 */
void calculate_linear_regression()
{
    FILE *f1, *f2, *f3, *f4;  
    float x, y;
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
    int n = 0;

    f1 = fopen("datasetLR1.txt", "r");
    f2 = fopen("datasetLR2.txt", "r");
    f3 = fopen("datasetLR3.txt", "r");
    f4 = fopen("datasetLR4.txt", "r");

    if (f1 == NULL || f2 == NULL || f3 == NULL || f4 == NULL)
    {
        printf("Error! Could not open one of the files.\n");
        exit(1);
    }

    while (fscanf(f1, "%f,%f", &x, &y) != EOF)
    {
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_xx += x * x;
        n++;
    }
    fclose(f1); 

    while (fscanf(f2, "%f,%f", &x, &y) != EOF)
    {
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_xx += x * x;
        n++;
    }
    fclose(f2);

    while (fscanf(f3, "%f,%f", &x, &y) != EOF)
    {
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_xx += x * x;
        n++;
    }
    fclose(f3);

    while (fscanf(f4, "%f,%f", &x, &y) != EOF)
    {
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_xx += x * x;
        n++;
    }
    fclose(f4);

    float b = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    float a = (sum_y - b * sum_x) / n;

    printf("\nEquation of regression line: y = %.3f * x + %.3f\n", b, a);

    float x_input;
    printf("Enter a value for x: ");
    scanf("%f", &x_input);

    float result = b * x_input + a;
    printf("Predicted y value: %.3f\n", result);
}
