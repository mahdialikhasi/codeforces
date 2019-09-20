#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int gcd(int a, int b){
	if(a > b){
		swap(a, b);
	}
	if(a == 0)
		return b;
	return gcd(b % a, a);
}
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int g;
	vector<pair<int, int> > inf(n);
	vector<int> t(7);
	for (int i = 0; i < n; ++i){
		cin >> inf[i].first >> inf[i].second;
		t[inf[i].first] = 1;
	}
	g = inf[0].first;
	for (int i = 0; i < n; ++i){
		g = gcd(g, inf[i].first);
	}
	int d = 1;
	for (int i = 0; i < 7; ++i){
		if(t[i])
			d *= i;
	}
	d /= g;
	vector<vector<int> > table(10 * d, vector<int>(n));
	for (int i = 0; i < n; ++i){
		int f = s[i] == '1' ? 1 : 0;
		// cout << i << " s " << endl;
		for (int j = 0; j < inf[i].second; ++j){
			table[j][i] = f;
		}
		for (int j = inf[i].second; j < 10 * d; j++){
			if((j - inf[i].second) % inf[i].first == 0)
				f ^= 1;
			table[j][i] = f;
		}
	}
	int maxi = 0;
	for (int i = 0; i < 10 * d; ++i){
		int count = 0;
		for (int j = 0; j < n; ++j){
			count += table[i][j];
		}
		maxi = max(maxi , count);
	}
	cout << maxi << endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < 20; ++j)
	// 	{
	// 		cout << table[j][i] << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}