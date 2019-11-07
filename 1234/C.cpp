#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		string row1;
		cin >> row1;
		string row2;
		cin >> row2;
		vector<vector<int> > data(2, vector<int>(n));
		for (int i = 0; i < n; ++i){
			data[0][i] = row1[i] - '0';
			data[1][i] = row2[i] - '0';
		}
		vector<vector<vector<int> > > table(2, vector<vector<int> >(n, vector<int>(4)));
		// initial
		if(data[0][0] == 1 || data[0][0] == 2){
			table[0][0][1] = 1;
		}else{
			table[0][0][2] = 1;
		}

		if(data[1][0] > 2 && table[0][0][2]){
			table[1][0][1] = 1;
		}
		for (int i = 1; i < n; ++i){
			if(table[0][i - 1][1]){
				if(data[0][i] == 1 || data[0][i] == 2){
					table[0][i][1] = 1;
				}else{
					table[0][i][2] = 1;
				}
			}

			if(table[1][i - 1][1]){
				if(data[1][i] == 1 || data[1][i] == 2){
					table[1][i][1] = 1;
				}else{
					table[1][i][0] = 1;
				}
			}

			if(table[1][i][0]){
				if(data[0][i] > 2){
					table[0][i][1] = 1;
				}
			}

			if(table[0][i][2]){
				if(data[1][i] > 2){
					table[1][i][1] = 1;
				}
			}
		}
		if(table[1][n - 1][1])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}