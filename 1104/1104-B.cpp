#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	string s;
	cin >> s;
	vector<char> a;
	int count = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		char b = s[i];
		if(a.size() && a[a.size() - 1] == b){
			a.pop_back();
			count++;
		}
		else
			a.push_back(b);
	}
	if(count % 2 == 0)
		cout << "No";
	else
		cout << "Yes";
	cout << endl;
	return 0;
}