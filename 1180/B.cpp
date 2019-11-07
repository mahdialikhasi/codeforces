#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	long long int n;
	cin >> n;
	vector<long long int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<pair<long long int, int> > b(n);
	for (int i = 0; i < n; ++i){
		if(a[i] >= 0)
			a[i] = -1 - a[i];
		// cout << "s" << a[i] << endl;
		b[i] = make_pair(a[i], i);
	}
	sort(b.begin(), b.end());
	if(n % 2 == 0){
		
	}else{
		if(b[0].first == -1){
			b[0].first = 0;
		}else{
			b[0].first = -1 - b[0].first;
		}

		for (int i = 0; i < n; ++i){
			a[b[i].second] = b[i].first;
		}
	}

	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
		
	return 0;
}