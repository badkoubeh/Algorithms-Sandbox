#include "Header.h"

StackWithMin::StackWithMin(){}

void StackWithMin::push(int val)
{
	if (stk_.empty())
		min_.push_back(val);
	else
		if (val < min_.back())
			min_.push_back(val);

	stk_.push(val);
		
}
void StackWithMin::pop()
{
	if (stk_.top() == min_.back())
		min_.pop_back();
	stk_.pop();
}
int StackWithMin::peek()
{
	int temp = stk_.top();
	if (temp == min_.back())
		min_.pop_back();
	stk_.pop();
	return temp;
}
int StackWithMin::min()
{
	return min_.back();
}
