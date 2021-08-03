/*
 * Program that prints the total number of moves required to solve tower of hanoi with n disks.
 * Also printing the movement of disks for solving.
 * 
 * Compilation: gcc tower_of_hanoi.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Recursion (Assignment - 5)
 * Date: 03/08/2021
 */
#include <stdio.h>

// for counting the number of moves used.
int count;

/*
 * Function that prints and count the moves required to solve tower of hanoi with n disks.
 * 
 * Parameters:
 * n: number of disks.
 * from: tower from which we move the n-th disk.
 * to: tower to which we move the n-th disk.
 * aux: auxilary tower used to move n-th disk.
 * 
 * Returns: nothing.
*/
void tower_of_hanoi(int n, char from, char to, char aux) {
    
    // if there are disks.
    if(n > 0) {
        // move n - 1 disks to aux tower, using to tower.
        tower_of_hanoi(n - 1, from, aux, to);
        
        // print the move.
        printf("%c to %c\n", from, to);
        
        // move n - 1 disks from aux tower to to-tower.
        tower_of_hanoi(n - 1, aux, to, from);
        
        // count number of moves used.
        count++;
    }
    
}

int main() {
    // reset the count of number of moves used to solve.
    count = 0;
    
    // print and count the moves.
    tower_of_hanoi(3, 'A', 'C', 'B');
    
    // print the number of moves used.
    printf("Total movements required = %d", count);
}