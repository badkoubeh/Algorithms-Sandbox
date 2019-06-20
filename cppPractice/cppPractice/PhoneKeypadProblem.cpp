#include "Header.h"

// iterative letter combination of a phone number based on keypad letters

void letterCombinaiton(string number)
{
	map<int, string> keypad;
	keypad.insert(pair<char, string>('2', "abc"));
	keypad.insert(pair<int, string>('3', "def"));
	keypad.insert(pair<int, string>('4', "ghi"));
	keypad.insert(pair<int, string>('5', "jkl"));
	keypad.insert(pair<int, string>('6', "opq"));
	keypad.insert(pair<int, string>('7', "rst"));
	keypad.insert(pair<int, string>('8', "uvw"));
	keypad.insert(pair<int, string>('9', "xyz"));
	keypad.insert(pair<int, string>('0', " "));

	vector<string> result;
	char *str_builder = new char[5];
	
	int index = 0;

	letterCombinaitonUtil(number, index, keypad, result, str_builder);
	for (auto itr = result.begin(); itr != result.end(); ++itr)
	{
		cout << *itr << endl;
	}
}

void letterCombinaitonUtil(string number, int index, map<int, string> keypad, vector<string> &result, char str_builder[])
{
	// index is equivalent to the level of the tree
	if (index == number.size())
	{
		int j = 0;
		char c = str_builder[j];

		string s;
		while (j < index)
		{
			s.append(1, c);
			j++;
			c = str_builder[j];
		}
		result.push_back(s);
		return;
	}


	string candidates = keypad.at(number[index]);
	for (int i = 0; i < candidates.size(); ++i)
	{
		string candidates = keypad.at(number[index]);
		str_builder[index] = candidates[i];
		letterCombinaitonUtil(number, index+1 , keypad, result, str_builder);
		if (number[index] == '0' || number[index] == '1')
			return;
	}
}