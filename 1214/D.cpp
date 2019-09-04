#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > table(n, vector<int>(m));
	for (int i = 0; i < n; ++i){
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j){
			if(s[j] == '.')
				table[i][j] = 1;
			else
				table[i][j] = 0;
		}
	}
	int ansi = 2;
	vector<vector<int> > grid(n, vector<int>(m, 0));
	grid[0][0] = 1;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(grid[i][j]){
				if(i + 1 < n && table[i+1][j] == 1)
					grid[i + 1][j] = 1;
				if(j + 1 < m && table[i][j+1] == 1)
					grid[i][j+1] = 1;	
			}
			
		}
	}
	grid[n-1][m-1] += 1;
	for (int i = n - 1; i >= 0; --i){
		for (int j = m - 1; j >= 0; --j){
			if(grid[i][j] == 2){
				if(i - 1 >= 0 && table[i-1][j] == 1 && grid[i - 1][j] == 1)
					grid[i - 1][j] = 2;
				if(j - 1 >= 0 && table[i][j-1] == 1 && grid[i][j-1] == 1)
					grid[i][j-1] = 2;
			}
			
		}
	}
	if(grid[n - 1][m - 1] == 1)
		ansi = 0;
	else{
		for (int k = 1; k < m + n - 2; ++k){
			int count = 0;
			int i = 0;
			if(k >= m)
				i = k - m + 1;
			for (; i <= k && i < n; ++i){
				if(k - i < m && grid[i][k - i] == 2)
					count++;
			}
			if(count == 1)
				ansi = 1;
		}
	}
	cout << ansi << endl;
	// cout << "----" << endl;
	// for (int i = 0; i < n; ++i){
	// 	for (int j = 0; j < m; ++j){
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}