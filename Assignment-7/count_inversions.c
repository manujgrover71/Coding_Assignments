/* 
 * Program to count number of inversion in a given array.
 * 
 * Compilation: gcc count_inversion.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Assignment - 7
 * 
*/

#include <stdio.h>

/*
 * Function to get the inversion count after merging the two arrays arr[left..mid] and arr[mid+1...right]
 * 
 * Parameters:
 * arr: the array whose two parts are to be merged.
 * left: starting index of first part.
 * mid: starting index of second part.
 * right: ending index of second part.
 * 
 * Returns: Count of inversion after merging both arrays.
*/
int merge(int arr[], int left, int mid, int right) {
    
    // count of inversion.
    int count = 0;
    
    // starting index of both arrays.
    int lStart = left, rStart = mid;
    
    // total elements.
    int total = right - left + 1;
    
    // temporary array to store the merged array.
    int temp[total];
    // index for temporary array.
    int tStart = 0;
    
    // iterate till both indicies are smaller than end.
    while(lStart < mid && rStart <= right) {
        // if element of first part is smaller than other, include it.
        if(arr[lStart] <= arr[rStart]) {
            temp[tStart++] = arr[lStart++];
        }else {
            // else we got an inversion, as here i < j && a[i] > a[j]
            // now as a[i] > a[j] and both arrays are sorted, all the array from a[i + 1...j - 1] is bigger for a[j]
            // hence add all these count to the inversion count.
            count += (mid - lStart);
            temp[tStart++] = arr[rStart++];
        }
    }
    
    // merge the left part if remaining.
    while(lStart < mid) {
        temp[tStart++] = arr[lStart++];
    }
    
    // merge the right part if remaining.
    while(rStart <= right) {
        temp[tStart++] = arr[rStart++];
    }
    
    tStart = 0;
    
    // fix the original array.
    for(int i = left; i <= right; i++) {
        arr[i] = temp[tStart++];
    }
    
    // return the inversion count.
    return count;
    
}


/*
 * Function to divide the array into two part and then merge both the parts.
 * 
 * Parameters:
 * arr: the array to be divided and merged.
 * left: starting of segment.
 * right: ending of segment.
 * 
 * Returns: Total inversion count of arr[left...right].
*/
int merge_sort(int arr[], int left, int right) {
    
    // count of inversions for current segment of [left..right] array.
    int count = 0;
    
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        // divide into two parts.    
        count += merge_sort(arr, left, mid);
        count += merge_sort(arr, mid + 1, right);
        
        // get the count after merging both paths
        count += merge(arr, left, mid + 1, right);
    }
    
    // return the inversion count.
    return count;
}

int main() {
    int n;
    // get size of array.
    scanf("%d", &n);
    
    int arr[n];
    
    // take the array input
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // count the number of inversion using merge sort.
    printf("%d\n", merge_sort(arr, 0, n - 1));
}