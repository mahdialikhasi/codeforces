//https://codeforces.com/contest/1138/problem/C
 
#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
int main(void){
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
 
	vector < vector <long long int> > _main(n, vector<long long int>(m));
 
	vector < vector<pair<long long int, int> > > rows(n, vector<pair<long long int, int> >(m));
	vector < vector<pair<long long int, int> > > columns(m, vector<pair<long long int, int> >(n));
 
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			long long int x;
			cin >> x;
			_main[i][j] = x;
			rows[i][j] = make_pair(x, j);
			columns[j][i] = make_pair(x, i);
		}

 	
 	vector<int> maxRow(n);
 	vector<vector<int> > rows2(n, vector<int>(m));
 	for (int i = 0; i < n; ++i)
 	{
 		sort(rows[i].begin(), rows[i].end());
 		rows2[i][rows[i][0].second] = 0;
 		for (int j = 1; j < m; ++j)
 		{
 			int pr = rows2[i][rows[i][j - 1].second];
 			if(rows[i][j - 1].first == rows[i][j].first)
 				rows2[i][rows[i][j].second] = pr;
 			else
 				rows2[i][rows[i][j].second] = pr + 1;
 		}
 		maxRow[i] = rows2[i][rows[i][m - 1].second];
 	}

 	
 	
 	vector<int> maxCol(m);
 	vector<vector<int> > columns2(m, vector<int>(n));
 	for (int i = 0; i < m; ++i)
 	{
 		sort(columns[i].begin(), columns[i].end());
 		columns2[i][columns[i][0].second] = 0;
 		for (int j = 1; j < n; ++j)
 		{
 			int pr = columns2[i][columns[i][j - 1].second];
 			if(columns[i][j - 1].first == columns[i][j].first)
 				columns2[i][columns[i][j].second] = pr;
 			else
 				columns2[i][columns[i][j].second] = pr + 1;	
 		}
 		maxCol[i] = columns2[i][columns[i][n - 1].second];
 	}

 	
	vector < vector <int> > result(n, vector <int>(m));
 
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			if(rows2[i][j] > columns2[j][i])
				result[i][j] = max(maxRow[i], maxCol[j] + rows2[i][j] - columns2[j][i]);
			else{
				result[i][j] = max(maxCol[j], maxRow[i] - rows2[i][j] + columns2[j][i]); 
			}
		}
 
	for(auto a : result){
		for(auto b : a)
			cout << b + 1 << ' ';
		cout << endl;
	}
	return 0;
}