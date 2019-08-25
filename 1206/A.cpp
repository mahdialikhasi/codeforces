#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int tmp = a[i] + b[j];
			int st = 0;
			for (int k = 0; k < n; ++k){
				if(a[k] == tmp){
					st = 1;
					break;
				}
			}

			for (int k = 0; k < m; ++k)
			{
				if(b[k] == tmp){
					st = 1;
					break;
				}
			}

			if(st == 0){
				cout << a[i] << " " << b[j] << endl;
				return 0;
			}
		}
	}
	return 0;
}