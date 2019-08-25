#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<pair<int , int> > a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	vector<pair<long long int, long long int> > b(n);
	for (int i = 0; i < n; ++i)
	{
		b[i].first = 0, b[i].second = 1000000007;
	}
	for (int i = 0; i < n; ++i)
	{
		if(b[i].first == 0){
			b[i].first = 1, b[i].second = a[i].second;
		}
		// find first element that can put inside
		int l = i + 1;
		int r = n;
		while(l < r){
			int mid = (l + r) / 2;
			if(a[mid].first > a[i].second)
				l = mid + 1;
			else{
				r = mid;
			}
		}
		int mini = 0;
		for (int j = l; j < n && mini < a[j].first; ++j)
		{
			//cout << "i" << i << ":" << j << endl;
			if(b[i].second - (a[j].first - a[j].second) < b[j].second){
				b[j].first = b[i].first, b[j].second = b[i].second - (a[j].first - a[j].second);
			}else if(b[i].second - (a[j].first - a[j].second) == b[j].second){
				b[j].first += b[i].first;
				b[j].first %= 1000000007;
			}
			mini = max(mini, a[j].second);
		}
	}
	long long int mini = 1000000007;
	for (int i = 0; i < n; ++i)
	{
		//cout << i << " => " << a[i].first << ":" << a[i].second << " => " << b[i].first << ":" << b[i].second << endl;
		mini = min(mini, b[i].second);
	}
	long long int ansi = 0;
	for (int i = 0; i < n; ++i)
	{
		if(b[i].second == mini){
			ansi += b[i].first;
			ansi %= 1000000007;
		}
	}
	cout << ansi << endl;
	return 0;
}