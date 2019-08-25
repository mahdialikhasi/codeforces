#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
int main(){
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int> > t(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		t[i][i] = 1;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		if(s[i] == s[i + 1])
			t[i][i + 1] = 1;
	}
	for (int i = 2; i < n; ++i){
		for (int j = 0; j < n - i; ++j){
			if(s[j] == s[j + i] && t[j+1][j + i - 1])
				t[j][j+i] = 1;
		}
	}
	long long int ansi = 0;
	long long int count = 0;
	vector<int> jj(n);
	vector<int> ii(n);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			jj[j] += t[i][j];
			if(i > 0)
				ii[i - 1] += t[i][j];
			count += t[i][j];
		}
	}
	for (int i = 1; i < n; ++i)
	{
		// jj[i] += jj[i - 1];
		ii[n - 1 - i] += ii[n - i];  
	}
	for (int i = 0; i < n; ++i)
	{
		// cout << i << " -> " << jj[i] << " " << ii[i] << endl;
	}
	long long int sofar = 0;
	for (int i = 0; i < n; ++i){
			ansi += jj[i] * ii[i];
	}
	cout << ansi << endl;
	return 0;
}