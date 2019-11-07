#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<int> > graph(h * w, vector<int>(h * w));
	vector<string> inp(h + 1);
	string st;
	getline(cin, st);
	for (int i = 0; i < h + 1; ++i){
		getline(cin, st);
		inp[i] = st;
	}
	for (int i = 0; i < h + 1; ++i){
		for (int j = 0; j < 2 * w + 1; ++j){
			if(i != 0 && j % 2){
				if(inp[i - 1][j] != '_'){
					// i - 1, j / 2 -> i-2 , j/2
					// cout << i << ":" << j << " :: ";
					// cout << (j / 2) + (i - 1) * w << endl;
					graph[(j / 2) + (i - 1) * w][(j / 2) + (i - 2) * w] = 1;
					graph[(j / 2) + (i - 2) * w][(j / 2) + (i - 1) * w] = 1;
				}
				if(inp[i][j] != '_'){
					// i - 1, j/2 -> i, j/ 2
					graph[(j / 2) + (i - 1) * w][(j / 2) + (i - 0) * w] = 1;
					graph[(j / 2) + (i - 0) * w][(j / 2) + (i - 1) * w] = 1;	
				}
				if(inp[i][j + 1] != '|'){
					// i - 1, j / 2 -> i - 1, j / 2 + 1
					graph[(j / 2) + (i - 1) * w][(j / 2 + 1) + (i - 1) * w] = 1;
					graph[(j / 2 + 1) + (i - 1) * w][(j / 2) + (i - 1) * w] = 1;	
				}
				if(inp[i][j - 1] != '|'){
				// 	// i - 1, j / 2 -> i - 1 , j / 2 - 1
					graph[(j / 2) + (i - 1) * w][(j / 2 - 1) + (i - 1) * w] = 1;
					graph[(j / 2 - 1) + (i - 1) * w][(j / 2) + (i - 1) * w] = 1;	
				}
			}
		}
	}

	

	return 0;
}