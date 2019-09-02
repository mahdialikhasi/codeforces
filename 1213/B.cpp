#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		vector<long long int> m(a);
		m[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; --i)
		{
			if(a[i] < m[i + 1])
				m[i] = a[i];
			else
				m[i] = m[i + 1];
		}
		long long int ansi = 0;
		for (int i = 0; i < n; ++i)
		{
			if(a[i] > m[i])
				ansi++;
		}
		cout << ansi << endl;
	}
	return 0;
}