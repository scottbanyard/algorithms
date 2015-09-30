// insertion sort algorithms - pg 18 in intro to algorithms book
// scott banyard 28/09/15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sort() {

	int c, d, temp, n;
	int array[1000];

	printf("Enter length of array: \n");
	scanf("%d", &n);

	printf("Enter %d integers: \n", n);

	// loop to enter array up to n-1 (arrays start at 0)
	for (c = 0; c < n; c++) {
		scanf("%d", &array[c]);
	}

	// sorting method: like a hand of cards [a] [b] [c] [d] [e]
	// while loop swaps cards to the left if [c] < [b] for e.g.
	// so [a] [c] [b] [d] [e]
	for (c = 1; c <= n; c++) {
		d = c;

		while ((d > 0) && (array[d] < array[d-1])) {
			temp 		= array[d];
			array[d]	= array[d-1];
			array[d-1] 	= temp;

			d--;
		}
	}

	printf("Array in the ascending order is: \n");
    
    // loop to print array
    for(c = 0; c <= n - 1; c++) {
        printf("%d ", array[c]);
    }

    printf("\n");
    
}

int main() {

	sort();
	return 0;

}