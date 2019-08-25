#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	long long  n;
	cin >> n;
	vector<long long > f(n);
	vector<long long > s(n);
	long long int max_so_far_1 = 0;
	long long int max_so_far_2 = 0;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> f[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; ++i)
	{
		long long int t1 = max(max_so_far_1, f[i]);
		t1 = max(t1, f[i] + max_so_far_2);

		long long int t2 = max(max_so_far_2, s[i]);
		t2 = max(max_so_far_2, s[i] + max_so_far_1);
		
		max_so_far_1 = t1;
		max_so_far_2 = t2;
	}
	
	cout << max(max_so_far_1, max_so_far_2) << endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << t1[i] << ":" << t2[i] << endl;
	// }
	return 0;
}