#include<iostream>
#include<string.h>

using namespace std;

bool isUniqueChars(char str[]) {
	if (sizeof(str) > 128) return false;
		
	
	int checker = 0;
	for (int i = 0; i < sizeof(str); i++) {
		int val = int(str[i])- int('a');
		if ((checker & (1 << val)) > 0) {//Already found this char in string
			cout << "repeated char found, "<< str[i]<< endl;
			return false;			
		}
		checker = checker | (1 << val);
		//cout << checker << endl;
	}
	return true;
	
}