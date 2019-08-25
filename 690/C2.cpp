#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <vector>

void dfs(vector<vector<int> > &graph, vector<int> &visited, vector<int> &depth, int s){
	visited[s] = 1;
	for (int i = 0; i < graph[s].size(); ++i)
	{
		if(!visited[graph[s][i]]){
			depth[graph[s][i]] = depth[s] + 1;
			dfs(graph, visited, depth, graph[s][i]);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n);
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	vector<int> visited(n);
	vector<int> depth(n);
	depth[0] = 0;
	dfs(graph, visited, depth, 0);
	
	int maxi = 0, maxindex = -1;
	for (int i = 0; i < n; ++i)
	{
		if(depth[i] > maxi){
			maxi = depth[i];
			maxindex = i;
		}
	}
	

	vector<int> visited2(n);
	vector<int> depth2(n);
	dfs(graph, visited2, depth2, maxindex);

	maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		if(depth2[i] > maxi){
			maxi = depth2[i];
			maxindex = i;
		}
	}

	cout << maxi << endl;
	
	return 0;
}