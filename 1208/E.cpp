#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <deque>
#include <vector>
void push(deque<pair< long long int, int> > &tmp, long long int a, int index){
	while(!tmp.empty() && a > tmp.back().first)
		tmp.pop_back();
	tmp.push_back(make_pair(a, index));
}
void pop(deque<pair< long long int, int> > &tmp, int index){
	while(!tmp.empty() && tmp.front().second <= index)
		tmp.pop_front();
}
int main(){
	ios_base::sync_with_stdio(false);
	int n, w;
	cin >> n >> w;
	vector<vector<long long int> > t;
	for (int i = 0; i < n; ++i){
		int l;
		cin >> l;
		t.push_back(vector<long long int>(l));
		for (int j = 0; j < l; ++j){
			cin >> t[i][j];
		}
	}
	vector<long long int> grid(w);
	for (int i = 0; i < n; ++i){
		deque<pair<long long int, int> > tmp;
		int deg = w - t[i].size();
		for (int j = 0; j < w; ++j){
			if(j < t[i].size())
				push(tmp, t[i][j], j);
			// grid[i][j] = tmp.front().first;
			long long int total = tmp.front().first;
			if(j < deg || j >= w - deg){
				if(total < 0) 
					total = 0;
			}
			pop(tmp, j - deg);
			grid[j]+= total;
		}
		
	}
	for (int i = 0; i < w; ++i)
	{
		cout << grid[i] << " ";
	}
	cout << endl;
	return 0;
}