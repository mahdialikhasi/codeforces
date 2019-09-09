#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int st = 1;
void dfs(int start, vector<int> &visited, vector<vector<int> > &graph, vector<vector<int> > &color){
	visited[start] = 1;
	for (int i = 0; i < graph[start].size(); ++i){
		// if(start == 2)
			// cout << graph[start][i] << " s " << visited[i] << endl;
		if(graph[start][i] && !visited[i]){
			dfs(i, visited, graph, color);
			color[start][i] = 1;
		}else if(graph[start][i] && visited[i] == 1){
			st = 2;
			// cout << start << "    " << i << endl;
			color[start][i] = 2;
		}else if(graph[start][i] && visited[i] == 2){
			color[start][i] = 1;
		}
	}
	visited[start] = 2;
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n, vector<int>(n));
	vector<vector<int> > color(n, vector<int>(n));
	vector<pair<int, int> > edge(m);
	for (int i = 0; i < m; ++i){
		int a,b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		edge[i] = make_pair(a - 1, b - 1);
	}
	vector<int> visited(n);
	for (int i = 0; i < n; ++i){
		if(visited[i] == 0)
			dfs(i,visited,graph,color);
	}
	cout << st << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << color[edge[i].first][edge[i].second] << " ";
	}
	cout << endl;
	return 0;
}