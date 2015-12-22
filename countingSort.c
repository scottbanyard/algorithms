// counting sort algorithm
// scott banyard 22/12/15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSort(int A[], int k, int n) {
	int B[100]; // output array
	int C[100]; // count array

	// sorting method: counting sort
	for (int i = 0; i <= k; i++) {
		C[i] = 0;
	}

	// increments count of that value
	for (int j = 1; j <= n; j++) {
		C[A[j]] = C[A[j]] + 1;
	}

	// iterate through the new array and add the previous index to the current index
	for (int i = 1; i <= k; i++) {
		C[i] = C[i] + C[i-1];
	}

	/* from right to left, iterate through, get A[j] value, use that as index for C so C[A[j]]
	and then whatever the value is in that index, that is the index/position the A[j] value will
	be in in the output array and then C[A[j]] is decremented by 1 */
	for (int j = n; j >= 1; j--) {
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}

	printf("Array in the ascending order is: \n");
    
    // loop to print array
    for(int k = 1; k <= n; k++) {
        printf("%d ", B[k]);
    }

    printf("\n");
}


int main() {
	int n; // size of array
	int A[100]; // input array
	int k = 0; // max value

	printf("Enter length of array: \n");
	scanf("%d", &n);
	printf("Enter %d integers: \n", n);

	// loop to enter array up to n-1 (arrays start at 1)
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		if (A[i] > k) {
			k = A[i];
		}
	}
	countingSort(A, k, n);
	return 0;
}