#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n, k;
	cin >> n >> k;
	vector<long long int> nu(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nu[i];
	}
	vector<long long int> tmp(n- 1);
	tmp[0] = nu[0];
	for (int i = 1; i < n - 1; ++i)
	{
		tmp[i] = tmp[i - 1] + nu[i];
	}
	vector<long long int> tmp2(n- 1);
	tmp2[n - 2] = nu[n - 1];
	for (int i = n - 3; i >= 0; --i)
	{
		tmp2[i] = tmp2[i + 1] + nu[i + 1];
		// cout << i << ":" << tmp2[i] << endl;
	}

	// for (int i = 0; i < n - 1; ++i)
	// {
	// 	cout << tmp[i] << ":" << tmp2[i] << endl;
	// }

	vector<pair<long long int, long long int> > diff(n - 1);
	for (int i = 0; i < n - 1; ++i)
	{
		diff[i] = make_pair(tmp2[i] - tmp[i], i);
	}

	vector<int> flag(n - 1);
	sort(diff.begin(), diff.end());
	reverse(diff.begin(), diff.end());
	for (int i = 0; i < k - 1; ++i)
	{
		flag[diff[i].second] = 1;
	}

	long long int count = 1;
	long long int ansi = 0;

	for (int i = 0; i < n; ++i)
	{
		ansi += nu[i] * count;
		if(i < n - 1 && flag[i])
			count++;
	}

	cout << ansi << endl;

	return 0;
}