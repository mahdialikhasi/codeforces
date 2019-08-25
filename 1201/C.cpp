#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	long long int n, k;
	cin >> n >> k;
	vector<long long int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	vector<long long int> diff(int(n / 2));
	
	for (int i = n / 2; i < n - 1; ++i)
	{
		diff[i - n/2] = a[i + 1] - a[i];
	}

	long long int count = 0;
	for (int i = 0; i < n / 2; ++i)
	{
		long long int tmp = (i + 1) * diff[i];
		if(k >= diff[i] && k >= tmp){
			// cout << tmp << endl;
			k -= tmp;
			count += diff[i];
		}else{
			count += k / (i + 1);
			// cout << count << endl;
			k = 0;
		}
		if(k <= 0)
			break;
	}
	count += k / (n / 2 + 1);

	cout << a[n / 2] + count << endl;

	return 0;
}