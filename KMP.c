// knuth-morris-pratt algorithm - O(patternLength) in pre-computation and O(stringLength) in time i.e. O(n)
// scott banyard 02/01/2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct that just contains an array of the pattern
typedef struct Pattern {
    char val[50];
} Pattern ;

// struct that just contains an array of the target string
typedef struct String {
    char val[50];
} String ;

int *prefixFunction(Pattern pattern, int patternLength) {
	int k = 0;
	// creates memory for prefix table
	int *pi = malloc(sizeof(int)*patternLength);

	if (!pi) {
		return NULL;
	}

	pi[0] = k;
	for (int i = 1; i < patternLength; i++) {
		while (k >= 1 && pattern.val[k+1] != pattern.val[i]) {
			k = pi[k];
		}
		if (pattern.val[i] == pattern.val[k+1]) {
			k++;
		}
		pi[i] = k;
	}
	return pi;
}


int KMP(String string, Pattern pattern, int stringLength, int patternLength) {
	// gets prefix table
	int *pi = prefixFunction(pattern, patternLength);
	int k = -1;

	// if prefix table returned null at pattern length is size 0, terminate
	if (!pi) {
		return -1;
	}

	for (int i = 0; i < stringLength; i++) {
		while (k > -1 && pattern.val[k+1] != string.val[i]) {
			k = pi[k];
		}
		if (pattern.val[k+1] == string.val[i]) {
			k++;
		}
		if (k == patternLength - 1) {
			free(pi);
			return i - k;
		}

	}
	free(pi);
	return -1;
}


int main() {
	char stringStore[] = "";
	char patternStore[] = "";
	int stringLength = 0;
	int patternLength = 0;
	int i = 0;

	// enter string and it will put it in a struct so that can send as a parameter
	printf("Enter string: \n");
	scanf("%s", stringStore);
	stringLength = strlen(stringStore);
	String stringToSend;
	for (int i = 0; i < stringLength; i++) {
		stringToSend.val[i] = stringStore[i];
	}

	// enter pattern and it will put it in a struct so that can to send as a parameter
	printf("Enter pattern: \n");
	scanf("%s", patternStore);
	patternLength = strlen(patternStore);
	Pattern patternToSend;
	for (int i = 0; i < patternLength; i++) {
		patternToSend.val[i] = patternStore[i];
	}
	
	printf("\n");

	// i will give the position where it initially matches
	i = KMP(stringToSend, patternToSend, stringLength, patternLength);
	if (i >= 0) {
		printf("Matched at position %d with the character: '%c'.\n", i, stringToSend.val[i]);
		printf("Rest of the string following the pattern: ");
		for (int j = i; j < stringLength; j++) {
			printf("%c", stringToSend.val[j]);
		}
		printf("\n");
	} else {
		printf("Pattern doesn't match at any parts of the target string.\n");
	}

	return 0;
}