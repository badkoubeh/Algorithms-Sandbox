#include<iostream>
#include<algorithm>
#include <string>
using namespace std;

bool checkPermutation(string str1, string str2)
{
	if (str1.length() != str2.length())
	{
		cout << "different string size" << endl;
		return false;
	}


	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	if (str1 != str2)
	{
		cout << "they are not equal" << endl;
		return false;
	}
		

	cout << "Permutation of each other" << endl;
	return true;
}