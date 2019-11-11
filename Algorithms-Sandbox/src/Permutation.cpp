#include "Header.h"

// The main recursive method 
// to print all possible  
// strings of length k 
// Permutation of k of n where repetition is allowed. n^r possibilities
void permutationRepetitionUtil(char set[], string prefix,int n, int k)
{

	// Base case: k is 0, 
	// print prefix 
	if (k == 0)
	{
		cout << (prefix) << endl;
		return;
	}

	// One by one add all characters  
	// from set and recursively  
	// call for k equals to k-1 
	for (int i = 0; i < n; i++)
	{
		string newPrefix;

		// Next character of input added 
		newPrefix = prefix + set[i];

		// k is decreased, because  
		// we have added a new character 
		permutationRepetitionUtil(set, newPrefix, n, k - 1);
	}

}

void PermutationRepetition(char set[], int k, int n)
{
	permutationRepetitionUtil(set, "", n, k);
}


// nPr possibilities
// Algorithm Paradigm: Backtracking
//Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a a permutation.
// permutations with repetition allowed  

// Function to swap values at two pointers
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char *a, int start, int end)
{
	int i;
	if (start == end)
		cout << a << endl;
	else
	{
		for (i = start; i <= end; i++)
		{
			swap(a[start], a[i]);
			permute(a, start + 1, end);
			swap(a[start], a[i]); //backtrack  
		}
	}
}
