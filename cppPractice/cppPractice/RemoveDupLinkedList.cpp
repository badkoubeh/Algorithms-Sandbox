#include <list>

using namespace std;

void RemoveDupLinkedList(list<int> &ls)
{
	list<int> ::iterator it;
	list<int> ::iterator it2;
	for (it = ls.begin(); it != ls.end(); advance(it, 1))
	{
		for (it2 = next(it, 1); it2 != ls.end(); advance(it2, 1))
		{
			if (*it == *it2)
			{
				ls.erase(it2);
				it2 = it;
			}
		}
	}
}