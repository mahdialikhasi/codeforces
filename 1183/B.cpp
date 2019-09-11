#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		long long int k;
		cin >> n >> k;
		vector<long long int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		long long int upper, lower;
		lower = max((long long int)0, a[0] - k);
		upper = a[0] + k;
		for (int i = 1; i < n; ++i){
			lower = max(lower, a[i] - k);
			upper = min(upper, a[i] + k);
		}
		if(lower > upper)
			cout << -1 << endl;
		else
			cout << upper << endl;
	}
	return 0;
}