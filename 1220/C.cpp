#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
int main(){
	string s;
	cin >> s;
	vector<char> a(s.size());
	a[0] = s[0];
	for (int i = 1; i < s.size(); ++i){
		if(s[i] < a[i - 1])
			a[i] = s[i];
		else
			a[i] =  a[i - 1];
	}
	cout << "Mike" << endl;
	for (int i = 1; i < s.size(); ++i){
		if(a[i] < s[i])
			cout << "Ann" << endl;
		else
			cout << "Mike" << endl;
	}
	return 0;
}