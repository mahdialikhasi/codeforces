#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<pair<int, int> > a(n);
		vector<int> color(n);
		for (int i = 0; i < n; ++i){
			a[i].first = s[i] - '0';
			a[i].second = i;
		}
		sort(a.begin(), a.end());
		int p = 0;
		for (int i = 1; i < n; ++i){
			if(a[i].second < a[i - 1].second){
				p = i;
				break;
			}
		}
		color[a[p].second] = 1;
		pair<int, int> d = a[p];
		for (int i = p + 1; i < n; ++i){
			if(a[i].second > d.second && a[i].first >= d.first){
				color[a[i].second] = 1;
				d = a[i];
			}
		}
		int st = 0;
		int last = -1;
		for (int i = 0; i < n; ++i){
			if(!color[a[i].second] && a[i].first >= last)
				last = a[i].first;
			else
				st = 1;

		}
		
		if(st && 0){
			cout << '-' << endl;
		}else{
			for (int i = 0; i < n; ++i)
			{
				cout << color[i] + 1;
			}
			cout << endl;
		}
	}
	return 0;
}