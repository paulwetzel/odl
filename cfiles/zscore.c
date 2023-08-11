#include <stdio.h>
#include <math.h>

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
float mean_of_dataset(float* data, int rows, int cols) {
    switch(cols):
    case 1:
        //Onedimensional data

    case 2:
        //Twodimensional data



    for (int i = 0; i < cols; i++) {
        printf("%f\n", data[i]);
    }
    return 0;
}