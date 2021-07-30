/*
 *
 * Program to find the time taken by selection sort on array with different data sets.
 * 
 * Compilation: gcc selection_sort.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Day2_Coding_Assignment
 * Date: 29/07/2021
*/

#include <stdio.h>
#include <stdlib.h> // for rand()
#include <sys/time.h> // for gettimeofday()

/*
 * Function to fill the array with approriate data value.
 * 
 * Parameters:
 * arr: array to be filled.
 * n: the size of array.
 * type: type of data to be filled (1: random data, 2: sorted data, 3: reverse sorted data).
 * 
 * Returns: Nothing.
*/
void fill_arr(int arr[], int n, int type) {
    
    if(type == 1) {
        // random
        for(int i = 0; i < n; i++) {
            arr[i] = rand() % (n + 1);
        }    
    }else if(type == 2) {
        // sorted
        for(int i = 0; i < n; i++) {
            arr[i] = i * 10;
        }
    }else {
        // reverse sorted
        for(int i = 0; i < n; i++) {
            arr[i] = (n - i - 1) * 10;
        }
    }
}

/*
 * Function that take two variables by reference and swap them.
 *
 * Parameters:
 * a: first number
 * b: second number
 *
 * Returns: Nothing.
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Function that sorts the array using selection sort.
 * 
 * Parameters:
 * arr: the array to be sorted.
 * n: the size of array.
 * 
 * Returns: nothing.
*/
void selection_sort(int arr[], int n) {
    
    for(int i = 0; i < n - 1; i++) {
        int min_element = arr[i];
        int pos = i;
        
        for(int j = i + 1; j < n; j++) {
            if(min_element > arr[j]) {
                min_element = arr[j];
                pos = j;
            }
        }
        
        swap(&arr[i], &arr[pos]);
    }
    
}

/*
 * Function that creates an array with a given size and appropriate data set and run selection sort and find the execution time.
 * 
 * Parameters:
 * n: the size of array.
 * type: the type of data set to be used (1: random data, 2: sorted data, 3: reverse sorted data).
 * 
 * Returns: nothing.
*/
void run_tests(int n, int type) {
    // the array to used.
    int arr[n];
    
    // fill the array with appropriate data.
    fill_arr(arr, n, type);
    
    // start time, end time.
    struct timeval start, end;
    
    // take current time as start time.
    gettimeofday(&start, NULL);
    
    // sort the array using selection sort.
    selection_sort(arr, n);
    
    // take current time as end time.
    gettimeofday(&end, NULL);
    
    // convert the elapsed time into second and microseconds.
    long seconds = (end.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    
    // print the time for a given data size and data set.
    printf("For n=%d ", n);
    if(type == 1) {
        printf("and random set\n");
    }else if(type == 2) {
        printf("and sorted set\n");
    }else {
        printf("and reverse sorted set\n");
    }
    printf("The elapsed time is %d seconds and %d micros\n", seconds, micros);
}

int main() {
    // run the tests for different data sizes and data sets.
    for(int i = 8; i <= 36; i += 4) {
        for(int type = 1; type <= 3; type++) {
            run_tests(i * 1000, type);
        }
        printf("\n");
    }
}