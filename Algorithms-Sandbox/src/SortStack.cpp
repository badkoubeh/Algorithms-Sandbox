#include"Header.h"

// Implementaiton with one extra stack as buffer
stack<int> sortStack(stack<int> &s)
{
	stack<int> sorted_stack; // another temp stack to sort the main stack

	while (!s.empty())
	{
		int val = s.top();
		s.pop();

		while (!sorted_stack.empty() && sorted_stack.top() > val)
		{
				s.push(sorted_stack.top());
				sorted_stack.pop();
		}
		sorted_stack.push(val);
	}

	return sorted_stack;
}

// recursive implementation 
void sortStackRecu(stack<int> &s)
{
	if (s.empty())
		return;

	int top = s.top();
	s.pop();
	sortStackRecu(s);

	sortedInsert(s, top);
}

void sortedInsert(stack<int> &s, int top)
{
	if (s.empty() || top > s.top())
	{
		s.push(top);
		return;
	}

	int new_top = s.top();
	s.pop();

	sortedInsert(s, top);

	s.push(new_top);
}

