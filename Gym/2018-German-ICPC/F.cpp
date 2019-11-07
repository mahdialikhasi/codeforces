#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > a(10000000);
	vector<int> one;
	for (int i = 0; i < n; ++i){
		int t;
		cin >> t;
		a[t].first = 1;
		a[t].second = i + 1;
		if(t == 1)
			one.push_back(i + 1);
	}
	long long int x, y;
	x = y = 1;
	while(x < 10000000 && y < 10000000){
		if(a[x].first == 1 && a[y].first == 1){
			if(x == y && x == 1 && one.size() > 1){
				cout << one[0] << " " << one[1] << endl;
				return 0;
			}
			if(x != y){
				cout << a[min(x, y)].second << " " << a[max(x, y)].second << endl; 
				return 0;
			}
		}
		if(x > y)
			swap(x, y);
		x += y;
		
	}
	cout << "impossible" << endl;
	return 0;
}