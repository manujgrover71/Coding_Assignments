/*
 * Program to reverse the given array of length n.
 *
 * Compilation: gcc reverse_array.c
 * Execution: ./a.out
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 23/07/2021
*/

#include <stdio.h>

/*
 * Function to swap two numbers passed by reference.
 *
 * Parameters:
 * a: first number
 * b: second number
 *
 * Returns: nothing
*/
void swap(int *a, int *b) {
    (*a) += (*b);
    (*b) = (*a) - (*b);
    (*a) -= (*b);
}

/*
 * Function to reverse the array of length n.
 *
 * Parameters:
 * arr: integer array to be reversed.
 * n: length of arr. 
 *
 * Returns: nothing.
*/
void reverse_array(int arr[], int n) {
    for(int i = 0; i < n / 2; i++) {
	swap(&arr[i], &arr[n - i - 1]);
    }
}


/*
 * Function to print the array of length n.
 *
 * Parameters:
 * arr: integer array to be printed.
 * n: length of arr.
*/
void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    // take length of array.
    scanf("%d", &n);

    int arr[n];
    // take the input from user.
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // print the array before reversing.
    printf("Before reverse:\n");
    print_array(arr, n);

    // reverse the array.
    reverse_array(arr, n);

    // print the array after reverse.
    printf("After reverse:\n");
    print_array(arr, n);
}
