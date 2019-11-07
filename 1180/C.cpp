#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <deque>
#include <vector>
int main(){
	long long int n,q;
	cin >> n >> q;
	deque<long long int> p;
	for (int i = 0; i < n; ++i){
		long long int t;
		cin >> t;
		p.push_back(t);
	}
	vector<pair<long long int, long long int> > vec(n);
	for (int i = 0; i < n; ++i){
		long long int a, b;
		a = p.front();
		p.pop_front();
		b = p.front();
		p.pop_front();
		vec[i] = make_pair(a, b);
		if(a > b){
			p.push_front(a);
			p.push_back(b);
		}else{
			p.push_front(b);
			p.push_back(a);
		}
	}
	vector<long long int> v2(n);
	for (int i = 0; i < n; ++i){
		v2[i] = p.front();
		// cout << v2[i] << endl;
		p.pop_front();
	}
	while(q--){
		long long int m;
		cin >> m;
		m--;
		if(m < n){
			cout << vec[m].first << " " << vec[m].second;
		}else{
			m -= n;
			cout << v2[0] << " " << v2[m % (n - 1) + 1];
		}
		cout << endl;
	}
	return 0;
}