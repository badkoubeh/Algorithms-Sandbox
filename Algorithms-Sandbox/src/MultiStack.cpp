#include "Header.h"

using namespace std;



class MultiStack
{
private:

	static vector<int> values_vec; // pointer to array of values

	class StackInfo
	{
	public:
		int start, size, capacity;
		StackInfo(int start, int capacity) : start(start), capacity(capacity)
		{

		}
		// Check if an index on the full array is whithin the stack boundaries.
		bool isWithinStackCapacity(int index)
		{
			if (index < 0 || index >= values_vec.size())
				return false;

			int contiguous_index = index < start ? index + values_vec.size() : index;
			int end = start + capacity;
			return start <= contiguous_index && contiguous_index < end;
		}
		int lastCapacityIndex()
		{
			return adjustIndex(start + capacity - 1);
		}
		int lastElementIndex()
		{

		}
		bool isFull() { return size == capacity; }
		bool isEmpty() { return size == 0; }
	};

	vector<StackInfo> info_vec_;

public:
	MultiStack(int num_of_stacks, int default_size)
	{
		for (int i = 0; i < num_of_stacks; ++i)
		{
			StackInfo info(default_size*i,default_size);
			info_vec_.push_back(info);
		}
		values_vec.assign(num_of_stacks*default_size,0);
	}
	void push(int stack_num, int value)
	{

	}
	int pop(int stack_num)
	{

	}
	int top(int stack_num)
	{

	}

private:
	void shift(int stack_num)
	{

	}
	void expand(int stack_num)
	{

	}
	bool areAllStacksFull()
	{

	}
	static int adjustIndex(int index)
	{

	}
	int nextIndex(int index)
	{

	}
	int previousIndex(int index)
	{

	}
};
