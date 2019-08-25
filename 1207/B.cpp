#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > A(n, vector<int>(m));
	vector<vector<int> > B(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> A[i][j];
		}
	}

	vector<pair<int, int> > p;
	for (int i = 0; i < n - 1; ++i){
		for (int j = 0; j < m - 1; ++j){
			if(A[i][j] == A[i + 1][j + 1] && A[i + 1][j] == A[i][j + 1] && A[i + 1][j] == A[i][j] && A[i][j] == 1){
				B[i][j] = B[i + 1][j + 1] = B[i + 1][j] = B[i][j + 1] = 1;
				p.push_back(make_pair(i + 1, j + 1));
			}
		}
	}

	int st = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(A[i][j] != B[i][j]){
				st = 1;
				break;
			}
		}
	}

	if(st){
		cout << -1 << endl;
		return 0;
	}

	int count = p.size();
	cout << count << endl;
	for (int i = 0; i < p.size(); ++i){
		cout << p[i].first << " " << p[i].second << endl;
	}
	
	return 0;
}