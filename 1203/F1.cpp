#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
bool mysort(pair<int, int> a, pair<int, int> b){
	if(a.first > b.first)
		return true;
	else if(a.first == b.first){
		if(a.second < b.second)
			return true;
	}
	return false;
}

int main(){
	int n;
	long long int r;
	cin >> n >> r;
	vector<pair<int, int> > p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i].first >> p[i].second;
	
	
	sort(p.rbegin(), p.rend(), mysort);
	vector<pair<int, int> > p2;
	for (int i = 0; i < n; ++i)
		if(p[i].second > 0 && r >= p[i].first){
			r += p[i].second;
		}else{
			p2.push_back(p[i]);
		}

	sort(p2.rbegin(), p2.rend());
	vector<int> visited(p2.size());
	
	for (int i = 0; i < p2.size(); ++i)
		for (int j = 0; j < p2.size() - 1; ++j){
			if(r + p2[j].second < p2[j + 1].first)
				swap(p2[j], p2[j + 1]);
		}

	for (int i = 0; i < p2.size(); ++i){
		if(r >= p2[i].first && visited[i] == 0){
			visited[i] = 1;
			// cout << p2[i].second << " " << r << endl;
			r += p2[i].second;
		}
	}

	for (int i = 0; i < p2.size(); ++i){
		if(!visited[i]){
			cout << "NO" << endl;
			return 0;
		}
	}
	if(r >= 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}