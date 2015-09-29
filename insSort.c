// insertion sort algorithm : pg 18 in intro to algorithms book
// scott banyard 29/09/15


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sort() {

	int c, d, temp, n;
	int array[500];

	printf("Enter length of array: \n");
	scanf("%d", &n);

	// enter array
	printf("Enter %d integers\n", n);

	for (c = 0; c < n; c++) {
		scanf("%d", &array[c]);
	}

	// sorting method; like a hand of cards [c] [c] [c] [c] [c]
	for (c = 1; c <= n; c++) {
		d = c;

	// swapping method with 2 cards (to the left) then repeat if need to swap again
		while ((d > 0) && (array[d] < array[d-1])) {
			temp 		= array[d];
			array[d]	= array[d-1];
			array[d-1] 	= temp;

			d--;
		}
	}

	// print array loop
	printf("Array in the ascending order is: \n");
    
    for(c = 0; c <= n - 1; c++) {
        printf("%d ", array[c]);
    }

    printf("\n");
    
}

int main() {

	sort();
	return 0;
}