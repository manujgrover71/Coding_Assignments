/*
 * Program to find the kth smallest element from an unsorted array.
 * 
 * Compilation: gcc kth_smallest.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
*/
#include <stdio.h>

// function to swap two integers.
int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// find the pivot point and fix the element smaller than pivot element in before the actual position of pivot element.
int get_pivot_point(int arr[], int left, int right) {
    
    int pivotElement = arr[right];
    int pivotPoint = left;
    
    for(int i = left; i <= right; i++) {
        if(arr[i] < pivotElement) {
            swap(&arr[i], &arr[pivotPoint++]);
        }
    }
    
    swap(&arr[pivotPoint], &arr[right]);
    
    return pivotPoint;
}

// if the pivot element is smaller than k, search in the right half,
// if the pivot element is greate than k, search in left half.
int get_kth_smallest_number(int arr[], int left, int right, int k) {
    
    int pivot_point = get_pivot_point(arr, left, right);
    
    if(pivot_point == k - 1) {
        return arr[pivot_point];
    }else if(pivot_point < k - 1) {
        return get_kth_smallest_number(arr, pivot_point + 1, right, k);
    }else {
        return get_kth_smallest_number(arr, left, pivot_point - 1, k);
    }
    
}

int kth_smallest_number(int arr[], int n, int k) {
    return get_kth_smallest_number(arr, 0, n - 1, k);
}

int main() {
    // take input the n and k.
    int n, k;
    scanf("%d %d", &n, &k);
    
    // take input array.
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // print the kth smallest number.
    printf("%d", kth_smallest_number(arr, n, k));
}