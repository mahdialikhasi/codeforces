#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> b(n - 1);
	for (int i = 0; i < n - 1; ++i)
	{
		b[i] = a[i] - a[i + 1];
	}
	long long int ansi = -a[0] + a[n - 1];
	sort(b.begin(), b.end());
	for (int i = 0; i < k - 1; ++i)
	{
		// cout << b[i] << endl;
		ansi += b[i];
	}
	cout << ansi << endl;

	return 0;
}