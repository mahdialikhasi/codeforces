#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n >> k;
		string c;
		cin >> c;
		vector<int> s(n);
		for (int i = 0; i < n; ++i){
			if(c[i] == 'R')
				s[i] = 0;
			else if(c[i] == 'G')
				s[i] = 1;
			else
				s[i] = 2;
		}

		// for (int i = 0; i < n; ++i)
		// {
		// 	cout << s[i] << " ";
		// }
		// cout << endl;

		vector<vector<int> > t(3, vector<int>(n));
		for (int i = 0; i < n; ++i){
			t[0][i] = (i) % 3;
			t[1][i] = (i + 1) % 3;
			t[2][i] = (i + 2) % 3;	
		}

		vector<vector<int> > dif(3, vector<int>(n));
		for (int j = 0; j < 3; ++j){
			for (int i = 0; i < n; ++i){
				if(s[i] != t[j][i])
					dif[j][i] = 1;
				else
					dif[j][i] = 0;
			}
		}

		// for (int i = 0; i < 3; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout << dif[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		vector<vector<int> > sum(3, vector<int>(n));

		for (int j = 0; j < 3; ++j){
			sum[j][0] = dif[j][0];
			for (int i = 1; i < k; ++i){
				sum[j][i] = sum[j][i - 1] + dif[j][i];
			}
		}
		
		for (int j = 0; j < 3; ++j){
			for (int i = k; i < n; ++i){
				sum[j][i] = sum[j][i - 1] + dif[j][i] - dif[j][i - k];
			}
		}

		// cout << "-----" << endl;
		// for (int i = 0; i < 3; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout << sum[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		

		int ansi = n;
		for (int i = k - 1; i < n; ++i){
			for (int j = 0; j < 3; ++j)
			{
				ansi = min(ansi, sum[j][i]);
			}
		}
		
		cout << ansi << endl;
	}
	return 0;
}