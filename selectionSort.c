// selection sort algorithm
// scott banyard 22/12/15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort() {
	int n; // size of array
	int A[1000]; // output array
	int min = 0; // min variable
	int temp = 0; // temp variable

	printf("Enter length of array: \n");
	scanf("%d", &n);
	printf("Enter %d integers: \n", n);

	// loop to enter array up to n-1 (arrays start at 1)
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}


	/* sorting method: finds smallest element of A, exchanges it with element in A[0],
	then finds second smallest and exchanges with element in A[1] etc. does this for
	first n-1 elements and leaves largest at A[n] */
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[min]) {
				min = j;
			}
		}
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}

	printf("Array in the ascending order is: \n");
    
    // loop to print array
    for(int k = 0; k <= n - 1; k++) {
        printf("%d ", A[k]);
    }

    printf("\n");
}



int main() {
	selectionSort();
	return 0;
}