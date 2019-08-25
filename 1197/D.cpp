#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long int> a(n);
	vector<pair<long long int, int> > b(n);
	long long int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		b[i] = make_pair(a[i] - k * ceil(1 / double(m)), 1);
		maxi = max(maxi, b[i].first);
	}
	for (int i = 1; i < n; ++i)
	{
		if(ceil(b[i - 1].second / double(m)) != ceil((b[i - 1].second + 1) / double(m))){
			if(b[i - 1].first > 0){
				b[i].second = b[i - 1].second + 1;
				b[i].first = b[i - 1].first + k * ceil(b[i - 1].second / double(m)) + a[i] - k * ceil(b[i].second / double(m));
			}	
		}else{
			if(b[i - 1].first + k * ceil(b[i - 1].second / double(m)) > 0){
				b[i].second = b[i - 1].second + 1;
				b[i].first = b[i - 1].first + k * ceil(b[i - 1].second / double(m)) + a[i] - k * ceil(b[i].second / double(m));
			}
		}
		
	}
	for (int i = 0; i < n; ++i)
	{
		maxi = max(maxi, b[i].first);
		//cout << b[i].first << ":" << b[i].second << endl;
	}
	cout << maxi << endl;
	return 0;
}