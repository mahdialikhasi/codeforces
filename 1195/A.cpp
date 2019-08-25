#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		a[t - 1]++;
	}
	int ansi = 0;
	int rem = 0;
	for (int i = 0; i < k; ++i)
	{
		ansi += a[i] / 2;
		rem += a[i] % 2;
	}
	cout << ansi * 2 + (rem + 1) / 2 << endl;
	return 0;
}