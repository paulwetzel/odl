#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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


void partition(double arr[], int left, int right, int *pivotLeft, int *pivotRight) {
    double pivot = arr[right];
    int i = left - 1;
    int j = left - 1;

    for (int k = left; k <= right - 1; k++) {
        if (arr[k] < pivot) {
            i++;
            j++;
            double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if (i != j) {
                temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        } else if (arr[k] == pivot) {
            j++;
            double temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
        }
    }

    double temp = arr[j + 1];
    arr[j + 1] = arr[right];
    arr[right] = temp;
    *pivotLeft = i + 1;
    *pivotRight = j + 1;
}


double quickselect(double arr[], int left, int right, int k) {
    while (1) {
        int pivotLeft, pivotRight;
        partition(arr, left, right, &pivotLeft, &pivotRight);

        if (k >= pivotLeft && k <= pivotRight) {
            return arr[k];
        } else if (k < pivotLeft) {
            right = pivotLeft - 1;
        } else {
            left = pivotRight + 1;
        }
    }
}