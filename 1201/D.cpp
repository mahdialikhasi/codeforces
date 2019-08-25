#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <queue> 
#include <vector>
#include <stack>
int n,m,k,q;

int main(){
	cin >> n >> m;
	vector<vector<int> > grid(n, vector<int>(m));
	vector<vector<int> > visited(n, vector<int>(m, -1));
	vector<vector<pair<int, int> > > parent(n, vector<pair<int, int> >(m));
	
	cin >> k >> q;
	for (int i = 0; i < k; ++i){
		int x, y;
		cin >> x >> y;
		grid[x - 1][y - 1] = 1;
	}
	vector<int> safe(m);
	for (int i = 0; i < q; ++i){
		int b;
		cin >> b;
		safe[b - 1] = 1;
	}
	stack<pair<int, int> > s;
	s.push(make_pair(0,0));
	visited[0][0] = 1;
	
	int t = 0;
	while(t != k && !s.empty()){
		pair<int, int> a = s.top();
		s.pop();
		if(grid[a.first][a.second]){
			// cout << a.first << ":" << a.second << endl;
			t++;
		}
		
		if(a.first < n - 1 && safe[a.second] && visited[a.first + 1][a.second] == -1){
			visited[a.first + 1][a.second] = 1;
			parent[a.first + 1][a.second] = make_pair(a.first ,a.second);
			s.push(make_pair(a.first +1, a.second));
		}
		if(a.second > 0 && visited[a.first][a.second - 1] == -1){
			visited[a.first][a.second - 1] = 1;
			parent[a.first][a.second - 1] = make_pair(a.first ,a.second);
			s.push(make_pair(a.first, a.second - 1));	
		}
		if(a.second < m -1 && visited[a.first][a.second + 1]){
			visited[a.first][a.second + 1] = 1;
			parent[a.first][a.second + 1] = make_pair(a.first ,a.second);
			s.push(make_pair(a.first, a.second + 1));
		}

	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << parent[i][j].first << ":" << parent[i][j].second << "     ";
		}
		cout << endl;
	}
	return 0;
}