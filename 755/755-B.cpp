#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
int main(){
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<string> b(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(a[i] == b[j])
				count++; 
		}
	}
	if(count % 2 == 1)
		m -= 1;
	n -= count;
	m -= count;
	if(m >= n)
		cout << "NO" << endl;
	else
		cout << "YES" << endl; 
	return 0;
}