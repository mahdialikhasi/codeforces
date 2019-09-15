#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<int> >grid(h, vector<int>(w));
	for (int i = 0; i < h; ++i)
	{
		string t;
		cin >> t;
		for (int j = 0; j < w; ++j){
			if(t[j] == '.')
				grid[i][j] = 1;
		}
	}
	int q;
	vector<vector<int>> row(h, vector<int>(w));
	for (int i = 0; i < h; ++i){
		for (int j = 1; j < w; ++j){
			if(grid[i][j] == 1 && grid[i][j] == grid[i][j - 1])
				row[i][j] = row[i][j - 1] + 1;
			else
				row[i][j] = row[i][j - 1];
		}
	}
	vector<vector<int>> col(w, vector<int>(h));
	for (int i = 0; i < w; ++i){
		for (int j = 1; j < h; ++j){
			if(grid[j][i] == 1 && grid[j][i] == grid[j - 1][i])
				col[i][j] = col[i][j - 1] + 1;
			else
				col[i][j] = col[i][j - 1];
		}
	}
	cin >> q;
	while(q--){
		int r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;
		c1--;
		r2--;
		c2--;
		long long int ansi = 0;
		for (int i = r1; i < r2 + 1; ++i){
			ansi += row[i][c2] - row[i][c1];
		}
		for (int i = c1; i < c2 + 1; ++i)
		{
			ansi += col[i][r2] - col[i][r1];
		}
		cout << ansi << endl;
	}
	return 0;
}