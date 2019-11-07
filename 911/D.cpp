#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stack>
int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i){
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		for (int i = 0; i < (l + r) / 2; ++i){
			swap(p[l + i], p[r - i]);
		}
		int count;
		stack<int> d;
		d.push(p[0]);
		for (int i = 1; i < n; ++i){
			if()
		}
	}
	return 0;
}