#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float compute_data_mean(int rows, int cols, float arr[rows][cols]) { //rows = i; cols = j
    float sum = 0.0;
    for(int i; i<rows;i++) {
        for(int j; j<cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum/rows*cols;
}

void compute_squared_difference(float mean, int rows, int cols, float arr[rows][cols]) {
   for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i][j] - mean;
            arr[i][j] = arr[i][j] * arr[i][j]; 
        }
    }
}

float compute_zscore(float data[][2], int rows, int cols) {
    float mean = compute_data_mean(rows, cols, data); 
    compute_squared_difference(mean, rows, cols, data);
    float var = compute_data_mean(rows, cols, data);
    float stddev = sqrt(var);
    printf("%f\n", stddev);
    for (int i; i < rows; i++) {
        
    }
    return 0; 
}

int main() {
    float test_array[][2] = {
        {3.6, 2.1}, //A
        {3.3, 3.7}, //B
        {4.9, 3.4}, //C
        {4.9, 2.1}, //D
        {7.0, 2.8}, //E
        {5.3, 4.4}, //F
        {4.7, 4.4}, //G
        {4.3, 3.4}, //H
        {5.7, 2.8}, //I
        {6.5, 1.4}, //J
        {4.0, 1.4}, //K
        {3.1, 2.6}, //L
        {2.1, 3.4}, //M
        {3.0, 1.5}, //N
        {6.6, 8.6}, //O
        {13.0, 6.9}, //P
        {10.8, 1.5}, //Q
        {7.7, 6.4}, //R
        {2.0, 6.0} //S
    };
    int rows = 19; // Has to be passed by the python function, is the metric for how many markers are there in the image
    compute_zscore(test_array, rows, 2);
    return 0;
}