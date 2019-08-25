#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int max1 = 0;
	int max2 = 0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i] != a[0])
			max1 = i;
	}
	for (int i = n - 1; i > 0; --i)
	{
		if(a[i] != a[n - 1])
			max2 = n - 1 - i;
	}
	cout << max(max1, max2) << endl;
	return 0;
}