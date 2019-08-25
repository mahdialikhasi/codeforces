#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
int main(){
	int w, h;
	cin >> w >> h;
	// vector<vector<vector<int> > > grid(h, vector<vector<int> >(w, vector<int>(4)));
	// grid[0][0][0] = grid[0][0][1] = grid[0][0][2] = grid[0][0][3] = 1;
	// for (int i = 0; i < h; ++i)
	// {
	// 	for (int j = 0; j < w; ++j)
	// 	{
	// 		for (int k = 0; k < 4; ++k)
	// 		{
	// 			// grid[i][j]
	// 			if(i > 0 && j > 0){
	// 				grid[i][j][0] = grid[i - 1][j][3] * grid[i][j - 1][1] + grid[i - 1][j][0] * grid[i][j - 1][0];
	// 				grid[i][j][1] = grid[i - 1][j][2] * grid[i][j - 1][0] + grid[i - 1][j][1] * grid[i][j - 1][1];
	// 				grid[i][j][2] = grid[i - 1][j][1] * grid[i][j - 1][3] + grid[i - 1][j][2] * grid[i][j - 1][2];
	// 				grid[i][j][3] = grid[i - 1][j][0] * grid[i][j - 1][2] + grid[i - 1][j][3] * grid[i][j - 1][3];
	// 			}else if(j > 0){
	// 				grid[i][j][0] = grid[i][j - 1][1] + grid[i][j - 1][0];
	// 				grid[i][j][1] = grid[i][j - 1][0] + grid[i][j - 1][1];
	// 				grid[i][j][2] = grid[i][j - 1][3] + grid[i][j - 1][2];
	// 				grid[i][j][3] = grid[i][j - 1][2] + grid[i][j - 1][3];
	// 			}else if(i > 0){
	// 				grid[i][j][0] = grid[i - 1][j][3]  + grid[i - 1][j][0];
	// 				grid[i][j][1] = grid[i - 1][j][2]  + grid[i - 1][j][1];
	// 				grid[i][j][2] = grid[i - 1][j][1]  + grid[i - 1][j][2];
	// 				grid[i][j][3] = grid[i - 1][j][0]  + grid[i - 1][j][3];
	// 			}
	// 			cout << grid[i][j][k] << " =>> " << i << "i" << j << "j" << k << "k" << endl;
	// 		}
	// 	}
	// }
	// cout << grid[h - 1][w - 1][0] + grid[h - 1][w - 1][1] + grid[h - 1][w - 1][2] + grid[h - 1][w - 1][3] << endl;
	long long int a = 1;
	for (int i = 0; i < w - 1; ++i)
	{
		a *= 2;
		a %= 998244353;
	}
	long long int b = 1;
	for (int i = 0; i < h - 1; ++i)
	{
		b *= 2;
		b %= 998244353;
	}
	
	long long int ansi = (a * b) % 998244353 ;
	cout << (4 * ansi) % 998244353 << endl;
	return 0;
}