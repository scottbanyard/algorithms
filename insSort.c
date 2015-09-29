#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sort() {

	int c, d, t, n;
	int array[1000];

	printf("Enter length of array: \n");
	scanf("%d", &n);

	printf("Enter %d integers\n", n);

	for (c = 0; c < n; c++) {
		scanf("%d", &array[c]);
	}

	// sorting method; like a hand of cards [c] [c] [c] [c] [c]
	for (c = 1; c <= n; c++) {
		d = c;

		while ((d > 0) && (array[d] < array[d-1])) {
			t 			= array[d];
			array[d]	= array[d-1];
			array[d-1] 	= t;

			d--;
		}
	}

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