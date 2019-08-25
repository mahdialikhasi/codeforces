#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>

int cost[70][70][70][70];

int find(int x1, int x2, int y1, int y2, vector<vector<int> > &a){
	int c = max(x2 - x1 + 1, y2 - y1 + 1);
	if(x2 - x1 == 0 && y2 - y1 == 0){
		c = a[x1][y1];
	}
	if(cost[x1][x2][y1][y2] == -1){
		for (int i = x1; i < x2; ++i){
			c = min(c, find(x1, i, y1, y2, a) + find(i + 1, x2, y1, y2, a));
		}
		for (int i = y1; i < y2; ++i){
			c = min(c, find(x1, x2, y1, i, a) + find(x1, x2, i + 1, y2, a));
		}
	}else{
		c = min(c, cost[x1][x2][y1][y2]);
	}
	cost[x1][x2][y1][y2] = c;
	// cout << x1 << " " << x2 << " " << y1 << " " << y2 << " :" << c << endl;
	return c;
}
int main(){
	int n;
	cin >> n;
	vector<vector<int> > a(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;
			a[i][j] = c == '.' ? 0 : 1;
		}
	}
	for (int i = 0; i < 70; ++i)
		for (int j = 0; j < 70; ++j)
			for (int k = 0; k < 70; ++k)
				for (int m = 0; m < 70; ++m)
					cost[i][j][k][m] = -1;

	cout << find(0,n - 1, 0, n - 1, a) << endl;
	
	// for (int i = 0; i < 5; ++i)
	// 	for (int j = 0; j < 5; ++j)
	// 		for (int k = 0; k < 5; ++k)
	// 			for (int m = 0; m < 5; ++m)
	// 				cout << i << " " << j << " " << k << " " << m << " " << cost[i][j][k][m] << endl;

	return 0;
}