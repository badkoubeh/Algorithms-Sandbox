#include<iostream>
#include<unordered_set>

using namespace std;

bool canFormPalindrome(string str)
{
	unordered_set<unsigned char> hashTbl;

	for (unsigned char c : str)
	{
		if (hashTbl.find(c) == hashTbl.end())
		{
			hashTbl.insert(c);
		}
		else
		{
			hashTbl.erase(c);
		}
	}
	if ((hashTbl.size() == 0 && (str.length() & 1) == 0) ||
		(hashTbl.size() == 1 && (str.length() & 1) == 1))
	{
		cout << "can form a palindrome." << endl;
		return true;
	}
	cout << "cannot form a palindrome" << endl;
	return false;
}