#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<long long int> a(n);
		for (int i = 0; i < n; ++i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int l = a[0];
		int r = a[a.size() - 1];
		while(l < r){
			vector<long long int> left(n);
			vector<long long int> right(n);
			for (int i = 0; i < n; ++i)
			{
				left[i] = abs(a[i] - l);
				right[i] = abs(a[i] - r);
			}
			sort(left.begin(), left.end());
			sort(right.begin(), right.end());
			// cout << "l " << l << " r " << r << endl;
			// cout << left[k] << " " << right[k] << endl;
			if(left[k] < right[k])
				r = (r + l - 1) / 2;
			else
				l = (r + l + 1) / 2;
		}
		vector<long long int> c(n);
		for (int i = 0; i < n; ++i)
		{
			c[i] = abs(a[i] - r);
		}
		// cout << "r : " << r << endl;
		cout << r << endl;
	}
	return 0;
}