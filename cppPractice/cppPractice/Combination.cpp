#include "Header.h"

// Combination where repetition/replacement is allowed so we can have (1,1) or (2,2) 
// in combination , order does NOT matter
/* arr[]  ---> Input Array
  chosen[] ---> Temporary array to store indices of
				   current combination
   start & end ---> Staring and Ending indexes in arr[]
   r ---> Size of a combination to be printed */
void CombinationRepetitionUtil(int chosen[], int arr[],
	int index, int r, int start, int end)
{

	// Since index has become r, current combination is 
	// ready to be printed, print 
	if (index == r)
	{
		
		for (int i = 0; i < r; i++)
			cout<<("%d ", arr[chosen[i]])<<"\t";
		cout << endl;
		return;
	}

	// One by one choose all elements (without considering 
	// the fact whether element is already chosen or not) 
	// and recur 
	for (int i = start; i <= end; i++)
	{
		chosen[index] = i;
		//cout << "index: " << index << endl;
		CombinationRepetitionUtil(chosen, arr, index + 1, r, i, end);
	}
	return;
}

// The main function that prints all combinations of size r 
// in arr[] of size n with repitions. This function mainly 
// uses CombinationRepetitionUtil() 
void CombinationRepetition(int arr[], int n, int r)
{
	// Allocate memory 
	int *chosen = new int[r + 1];

	// Call the recursice function 
	CombinationRepetitionUtil(chosen, arr, 0, r, 0, n - 1);
}


// The main function that prints  
// all combinations of size r  
// in arr[] of size n. This function 
// mainly uses combinationUtil()  
// Combination where repetication/replacement is NOT allowed so we cannot have (1,1) or (2,2)
void CombinationNoRepetition(int arr[], int n, int r)
{
	// A temporary array to store 
	// all combination one by one  
	int *data = new int[r];

	// Print all combination using 
	// temprary array 'data[]'  
	combinationNoRepetitionUtil(arr, data, 0, n - 1, 0, r);
}

/* arr[] ---> Input Array
data[] ---> Temporary array to store current combination
start & end ---> Staring and Ending indexes in arr[]
index ---> Current index in data[]
r ---> Size of a combination to be printed */
void combinationNoRepetitionUtil(int arr[], int data[],
	int start, int end,
	int index, int r)
{
	// Current combination is ready 
	// to be printed, print it  
	if (index == r)
	{
		for (int j = 0; j < r; j++)
			cout << data[j] << " ";
		cout << endl;
		return;
	}

	// replace index with all possible  
	// elements. The condition "end-i+1 >= r-index" 
	// makes sure that including one element  
	// at index will make a combination with  
	// remaining elements at remaining positions  
	for (int i = start; i <= end && end - i + 1 >= r - index; i++)
	{
		data[index] = arr[i];
		combinationNoRepetitionUtil(arr, data, i + 1,
			end, index + 1, r);
	}
}