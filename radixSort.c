// radix sort algorithm using counting sort as a subroutine
// scott banyard 07/01/16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void countingSort(int A[], int n, int digitSize, int stage) {
	// output array of size n
	int B[n]; 
	// count array only of size 10 as we are doing digits 0-10 : {0} initialises all to 0
	int C[10] = {0};

	// prints out what stage we are at on the sort i.e. if 1 then we are on the least significant digit
	printf("Stage %d of the Radix Sort: ", stage);


	// increments count of the value where A[j] is the index of the count array
	for (int j = 1; j <= n; j++) {
		C[(A[j]/digitSize)%10] = C[(A[j]/digitSize)%10] + 1;
	}

	// iterate through the count array and add the previous index to the current index
	for (int i = 1; i <= 10; i++) {
		C[i] = C[i] + C[i-1];
	}

	/* from right to left, iterate through, get A[j] value, use that as index for C so C[A[j]]
	and then whatever the value is in that index, that is the index/position the initial A[j] value 
	will be in in the output array and then the count (C[A[j]]) is decremented by 1 */
	for (int j = n; j >= 1; j--) {
		B[C[(A[j]/digitSize)%10]] = A[j];
		C[(A[j]/digitSize)%10] = C[(A[j]/digitSize)%10] - 1;
	}

	// copy output array to initial array so that now A[] contains sorted numbers according to current digit
	for (int i = 1; i <= n; i++) {
		A[i] = B[i];
	}

	// prints stage of radix sort - shows each digit/bit being sorted
	for (int i = 1; i <= n; i++) {
			printf("%d ", A[i]);
	}

	printf("\n");

}

void radixSort(int A[], int n, int k) {
	int stage = 0;
	for (int digitSize = 1; k/digitSize > 0; digitSize *= 10) {
		stage++;
		countingSort(A, n, digitSize, stage);
	}
}

int main() {
	int n; // size of array
	int A[100]; // input array
	int k = 0; // max value for size of count array

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

	radixSort(A, n, k);

	return 0;
}