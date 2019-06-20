#include "Header.h"

// 1. Knapsak Problem----------------------------------------------------------------------------

// DP solution : it is working only if the weights are integers. This has a polynomial time complexity 
int Knapsak(int left_capacaity, int index, int W[], int V[])
{
	if (index == 0 || left_capacaity == 0)
		return 0;

	if (W[index - 1] > left_capacaity)
		return Knapsak(left_capacaity, index - 1, W, V);
	else
		return max(V[index - 1] + Knapsak(left_capacaity - W[index - 1], index - 1, W, V),
			Knapsak(left_capacaity, index - 1, W, V));
}

// Another solution to this problem is Branch and Bound to optimize the Brute Force solution, (Brute force or Branching). 
// In the tree representation, we can do DFS of tree. 
//If we reach a point where a solution no longer is feasible, there is no need to continue exploring. 



// Pattern Searching
// 2. Anagram substring Search (search fro all permutations)
