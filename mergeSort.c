// merge sort pg. 31 in intro to algorithms book
// scott banyard 08/10/15

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// declares function because mergeSort uses merge before the function is even read
void merge(int[], int, int, int);

void mergeSort(int array[], int low, int high) {
	int mid;

	if (low < high) {
		mid = ((low+high)/2);
		mergeSort(array, low, mid);
		mergeSort(array, mid+1, high);
		merge(array, low, mid, high);
	}

}

void merge(int array[], int low, int mid, int high) {	

    int i = low, j = mid + 1, k = 0;
    // temp array to store new sorted array
    int temp[1000];
  	
  	// comparing two sub arrays using indexes
    while ((i <= mid) && (j <= high)) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        }
        else {
            temp[k++] = array[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = array[i++];
    }
  
    while (j <= high) {
        temp[k++] = array[j++];
    }
  
    k--;
    while (k >= 0) {
        array[low + k] = temp[k];
        k--;
    }
}


int main(void) {
	int n;
	int array[1000];


	printf("Please enter the length of the array:\n");
	scanf("%d", &n);

	printf("Please enter %d number(s) for your array:\n", n);

	// scans in array
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	mergeSort(array, 0, n-1);

	for(int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;	
}