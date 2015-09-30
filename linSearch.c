// linear search algorithm - type in value and matches if in array
// scott banyard 30/09/15

#include <stdio.h>
#include <stdlib.h>

void linear(int array[], int value, int n) {
	int d;
	int length = n;
	int v = value;

	// iterate through array and see if can match value to number in array
	for (d = 0; d < n; d++) {
		if (array[d] == v) {
			printf("%d is present at location %d.\n", v, d+1);
			break;
		}
	}

	// fully iterated through loop, so loop iterator is equal to length
	if (d == n) {
		printf("%d is not present in array.\n", v);
	}

}

int main() {

	int a, v, n, array[100];

	printf("Enter length of array: \n");
	scanf("%d", &n);

	printf("Enter %d numbers: \n", n);

	// scanning in array
	for (a = 0; a < n; a++) {
		scanf("%d", &array[a]);
	}

	printf("Enter a value to search for in array: \n");
	scanf("%d", &v);

	linear(array, v, n);
	return 0;

}