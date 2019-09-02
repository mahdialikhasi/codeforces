#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<int> > nu(3 * 100000, vector<int>(40));
	vector<int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	for (int i = 0; i < n; ++i){
		int t = a[i];
		int count = 0;
		while(t != 0){
			nu[t][count] += 1;
			t /= 2;
			count ++;
		}
		nu[t][count] += 1;
	}
	long long int ansi = 40 * n;
	for (int i = 0; i < nu.size(); ++i){
		long long int count = 0;
		long long int cost = 0;
		for (int j = 0; j < nu[i].size(); ++j){
			if(count >= k)
				break;
			if(count + nu[i][j] > k){
				int t = k - count;
				count = k;
				cost += j * t;
			}else{
				count += nu[i][j];
				cost += nu[i][j] * j;
			}
		}
		if(count >= k)
			ansi = min(ansi, cost);
	}
	cout << ansi << endl;
	return 0;
}