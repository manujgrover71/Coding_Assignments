/*
 * Implementation of Selection sort using Recursion.
 * 
 * Compilation: gcc selection_sort_using_recursion.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Recursion (Assignment - 5)
 * Date: 03/08/2021
*/
#include <stdio.h>

/*
 * Function that finds the smallest element index from a given position to the end of array of a given array.
 * 
 * Parameters:
 * pos: the starting position.
 * arr: the given array.
 * n: the size of array.
 * 
 * Returns: the index of smallest from pos to n in the array arr.
*/
int find_min(int pos, int arr[], int n) {
    
    // if we are at last, say current element is the smallest.
    if(pos == n - 1) {
        return pos;
    }
    
    // get the index from elements in the range [pos + 1, n]
    int next_pos = find_min(pos + 1, arr, n);
    
    // check if current position is better than answer from [pos + 1, n].
    return arr[next_pos] < arr[pos] ? next_pos : pos;
}

/*
 * Function that take two variables by reference and swap them.
 *
 * Parameters:
 * a: first number
 * b: second number
 *
 * Returns: nothing.
*/ 
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

/*
 * Function that sort the array using recursive selection sort.
 *
 * Parameters:
 * arr: the array to be sorted.
 * n: size of array.
 * pos: starting of array.
 * 
 * Returns: nothing.
*/
void selectionSort(int arr[], int n, int pos) {
    
    // not need to sort the last element of arr.
    if(pos == n - 1) {
        return;
    }
    
    // find the smaller element in range [pos, n - 1].
    int nextMinIndex = find_min(pos, arr, n);
    
    // swap the smallest element with current element.
    swap(&arr[pos], &arr[nextMinIndex]);
    
    // proceed to next element.
    selectionSort(arr, n, pos + 1);
}

int main() {
    
    // size of array.
    int n;
    scanf("%d", &n);
    
    // take the array as input.
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // apply recursive selection sort.
    selectionSort(arr, n, 0);
    
    // print the sorted array.
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}