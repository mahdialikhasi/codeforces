#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n >> k;
		string c;
		cin >> c;
		vector<int> s(n);
		for (int i = 0; i < n; ++i)
		{
			if(c[i] == 'R')
				s[i] = 0;
			else if(c[i] == 'G')
				s[i] = 1;
			else
				s[i] = 2;
		}
		vector<vector<vector<int> > > mini(k + 1, vector<vector<int> >(n, vector<int>(3, 100000)));
		for (int j = 0; j < n; ++j)
		{
			for (int c = 0; c < 3; ++c)
			{
				if(s[j] == c)
					mini[1][j][c] = 0;
				else
					mini[1][j][c] = 1;
			}
		}
		
		for (int i = 2; i <= k; ++i)
		{
			for (int j = i - 1; j < n; ++j)
			{
				// mini[i - 1][j - 1]
				for (int c = 0; c < 3; ++c)
				{
					if(c == 0){
						if(s[j] == c){
							mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][2]);
						}else{
							mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][2] + 1);
						}
						//mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][1] + 1);
						//mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][0] + 1);
					}
					if(c == 1){
						
						if(s[j] == c){
							mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][0]);
						}else{
							mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][0] + 1);
						}
						//mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][1] + 1);
						//mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][2] + 1);
					}
					if(c == 2){
						if(s[j] == c){
							mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][1]);
						}else{
							mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][1] + 1);
						}
						//mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][0] + 1);
						//mini[i][j][c] = min(mini[i][j][c], mini[i - 1][j - 1][2] + 1);
					}
				}
			}
		}
		// for (int i = 1; i <= k; ++i)
		// {
		// 	cout << "k ===== " << i << endl;
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		for (int c = 0; c < 3; ++c)
		// 		{
		// 			//cout << i << j << c << endl;
		// 			cout << mini[i][j][c] << "  ";
		// 		}
		// 		cout << endl;
		// 	}
		// }
		int ansi = 100000;
		for (int i = k - 1; i < n; ++i)
		{
			for (int c = 0; c < 3; ++c)
			{
				ansi = min(ansi, mini[k][i][c]);
			}
		}
		cout << ansi << endl;
	}
	return 0;
}