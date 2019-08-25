#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int t;
	cin >> t;
	vector<pair<int, int> > a(t);
	for (int i = 0; i < t; ++i)
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	int s = a[0].first;
	sort(a.begin(), a.end());
	int k = 0;
	int total = 0;
	int count = 0;
	for (int i = 0; i < t; ++i)
	{
		if(a[i].first <= s / 2){
			k += a[i].first;
			count++;
		}
		total += a[i].first;
	}
	if(k + s > total / 2){
		cout << count + 1 << endl;
		for (int i = 0; i < t && a[i].first <= s / 2; ++i){
			cout << a[i].second << " ";
		}	
		cout << 1 << endl;
	}else{
		cout << 0 << endl;
	}
	return 0;
}