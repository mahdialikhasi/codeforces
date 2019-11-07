#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(28);
	for (int i = 0; i < n; ++i){
		a[s[i] - 'a']++;
	}
	int count;
	count = a['n' - 'a'];
	for (int i = 0; i < count; ++i)
	{
		cout << 1 << " ";
	}
	count = a['z' - 'a'];
	for (int i = 0; i < count; ++i)
	{
		cout << 0 << " ";
	}
	cout << endl;
	return 0;
}