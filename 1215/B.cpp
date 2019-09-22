#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<long long int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<pair<int, int> > count(n);
	// initial
	int c = a[0] < 0 ? 1 : 0;
	int o = a[0] < 0 ? 1 : 0;
	for (int i = 1; i < n; ++i){
		if(a[i] < 0){
			o++;
		}
		if(o % 2)
			c++;
	}
	count[0] = make_pair(c, n - c);
	for (int i = 1; i < n; ++i){
		int total = n - i;
		if(a[i - 1] > 0){
			count[i] = make_pair(count[i - 1].first, total - count[i - 1].first);
		}else{
			count[i] = make_pair(count[i - 1].second, total - count[i - 1].second);
		}
	}
	long long int e = 0;
	long long int odd = 0;
	for (int i = 0; i < n; ++i){
		// cout << count[i].first << " " << count[i].second << endl;
		odd += count[i].first;
		e += count[i].second;
	}
	cout << odd << " " << e << endl;
	return 0;
}