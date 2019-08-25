#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>

int main(){
	string s;
	cin >> s;
	int st = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if(s[i] == '1'){
			st = 1;
		}
	}

	if(st)
		cout << (s.size() + 1) / 2 << endl;
	else if(s.size() % 2)
		cout << (s.size() + 1) / 2 - 1 << endl;
	else
		cout << (s.size() + 1) / 2 << endl;
	return 0;
}