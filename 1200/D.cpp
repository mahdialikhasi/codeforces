#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<int> > grid(n, vector<int>(n));
	vector<int> noRow(n);
	vector<int> noColumn(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			char block;
			scanf(" %c", &block);
			grid[i][j] = (block == 'B' ? 1 : 0);
			if(grid[i][j]){
				noRow[i]++;
				noColumn[j]++;
			}
		}
	vector<vector<int> > CRgrid = grid;
	vector<vector<int> > CCgrid = grid;
	for (int i = n - 1; i >= 0; --i)
		for (int j = n - 2; j >= 0; --j){
			CRgrid[i][j] = CRgrid[i][j] + CRgrid[i][j + 1];
			if(j + k < n)
				CRgrid[i][j] -= grid[i][j + k];
		}
	for (int i = n - 2; i >= 0; --i)
		for (int j = n - 1; j >= 0; --j){
			CCgrid[i][j] = CCgrid[i][j] + CCgrid[i + 1][j];
			if(i + k < n)
				CCgrid[i][j] -= grid[i + k][j];
		}
	int allCR = 0;
	int allCC = 0;
	for (int i = 0; i < n; ++i){
		if(!noRow[i])
			allCR++;
		if(!noColumn[i])
			allCC++;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			if(noRow[i] != 0 && noRow[i] - CRgrid[i][j] == 0){
				CRgrid[i][j] = 1;
			}else{
				CRgrid[i][j] = 0;
			}
		}
	vector<vector<int> > CRC = CRgrid;
	for (int i = n - 2; i >= 0; --i)
		for (int j = n - 1; j >= 0; --j){
			CRC[i][j] = CRC[i][j] + CRC[i + 1][j];
			if(i + k < n)
				CRC[i][j] -= CRgrid[i + k][j];
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			if(noColumn[j] != 0 && noColumn[j] - CCgrid[i][j] == 0){
				CCgrid[i][j] = 1;
			}else{
				CCgrid[i][j] = 0;
			}
		}
	vector<vector<int> > CCC = CCgrid;
	for (int i = n - 1; i >= 0; --i)
		for (int j = n - 2; j >= 0; --j){
			CCC[i][j] = CCC[i][j] + CCC[i][j + 1];
			if(j + k < n)
				CCC[i][j] -= CCgrid[i][j + k];
		}

	int maxi = 0;
	for (int i = 0; i < n - k + 1; ++i)
		for (int j = 0; j < n - k + 1; ++j)
			maxi = max(maxi, CCC[i][j] + CRC[i][j] + allCC + allCR);

	cout << maxi << endl;
	return 0;
}