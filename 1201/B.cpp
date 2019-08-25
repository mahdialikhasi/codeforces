#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<long long int> a(n);
	long long int sum = 0;
	long long int maxi = -2;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
		maxi = max(maxi , a[i]);
		count += a[i] % 2;
	}
	
	if(count % 2 || maxi > sum - maxi)
		cout << "NO" << endl;
	else
		cout << "YES" << endl; 
	
	return 0;
}