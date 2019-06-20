#include "Header.h"

//int SumLinkedList(list<int>::iterator &it1, list<int>::iterator &it2, int carry)
//{
//	
//
//	return (value % 10);
//}

list<int> SumLinkedList(list<int> &ls1, list<int> &ls2)
{
	

	list<int> result;
	list<int>::reverse_iterator it1;
	list<int>::reverse_iterator it2;

	int value = 0;
	int carry = 0;

	it2 = ls2.rbegin();
	

	for (it1 = ls1.rbegin(); it1 != ls1.rend(); it1++)
	{
		

		if (it2 != ls2.rend())
		{
			cout << "l1: " << *it1 << " l2: " << *it2 << endl;
			value = *it1 + *it2 + carry;
			advance(it2, 1);
		}
		else
		{
			value = *it1 + carry;
		}			
		carry = value / 10;
		result.push_back(value % 10);
	}

	return result;
}
