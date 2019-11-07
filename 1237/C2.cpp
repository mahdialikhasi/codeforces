#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<pair<long long int, pair<long long int, pair<long long int, int> > > > a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second.first >> a[i].second.second.first;
		a[i].second.second.second = i;
	}
	
	sort(a.begin(), a.end());
	vector<int> v(n);
	vector<int> order;
	// cout << a[0].first << " " << a[0].second.first << " " << a[0].second.second << endl;
	// cout << a[1].first << " " << a[1].second.first << " " << a[1].second.second << endl;
	// cout << a[2].first << " " << a[2].second.first << " " << a[2].second.second << endl;
	for (int i = 0; i < n; ++i){
		if(v[i])
			continue;
		for (int j = i + 1; j < n; ++j){
			if(v[j])
				continue;
			if(a[i].first == a[j].first && a[i].second.first == a[j].second.first){
				v[i] = 1;
				v[j] = 1;
				cout << a[i].second.second.second + 1 << " " << a[j].second.second.second + 1 << endl;
				break;
			}else{
				break;
			}
		}
		
	}
	for (int i = 0; i < n; ++i){
		if(v[i])
			continue;
		for (int j = i + 1; j < n; ++j){
			if(v[j])
				continue;
			if(a[i].first == a[j].first){
				v[i] = 1;
				v[j] = 1;
				cout << a[i].second.second.second + 1 << " " << a[j].second.second.second + 1 << endl;
				break;
			}else{
				break;
			}
		}
		
	}
	for (int i = 0; i < n; ++i){
		if(v[i])
			continue;
		for (int j = i + 1; j < n; ++j){
			if(v[j])
				continue;
			
				v[i] = 1;
				v[j] = 1;
				cout << a[i].second.second.second + 1 << " " << a[j].second.second.second + 1 << endl;
				break;
		}
		
	}
	
	return 0;
}
