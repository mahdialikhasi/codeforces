#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>
int main(){
	int n;
	cin >> n;
	map<string, int> a;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		a[tmp]++;
		if(a[tmp] == 1)
			cout << "OK" << endl;
		else
			cout << tmp << a[tmp] - 1 << endl;
	}

	return 0;
}