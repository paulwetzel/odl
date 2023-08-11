#include <stdio.h>
#include <math.h>

#define PY_SSIZE_T_CLEAN

/*
 * Calculates the mean of the dataset.
 *
 * Parameters:
 *   data - List of datapoints that is passed to the function.
 *   dimension - Dimension of the total dataset, e.g. dim1 = x, dim2 = x,y, dim3=x,y,z
 *   length - Length of the dataset, e.g. how many elements are there?
 *
 * Returns:
 *   mean (int) - the mean value of the whole dataset
 *
 * Example Usage:
 *   
 */
double compute_mean(double *data, int rows, int cols) {
    double sum = 0.0;
    double *dataPtr = data; 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += *dataPtr++; 
        }
    }

    return sum / (rows * cols);
}
