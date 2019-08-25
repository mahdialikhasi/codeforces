#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
void dfs(int s, long long int c, vector<long long int> &k, vector<vector<int> > &graph, vector<int> &visited){
	c += k[s];
	visited[s]++;
	int target;
	if(c >= 0){
		target = c % graph[s].size();
	}else{
		target = (c + (-c/graph[s].size() + 1) * graph[s].size()) % graph[s].size();
	}
	cout << c << " " << graph[s].size() << " " << target << "-->" << s + 1<< endl;
	if(visited[graph[s][target]] == 3)
		return;
	else
		dfs(graph[s][target], c, k, graph, visited);
}
int main(){
	int n;
	cin >> n;
	vector<long long int> k(n);
	for (int i = 0; i < n; ++i)
		cin >> k[i];
	vector<vector<int> > graph(n);
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j){
			int tmp;
			cin >> tmp;
			graph[i].push_back(tmp - 1);
		}		
	}
	// cout << graph[3][0] << endl;
	int q;
	cin >> q;
	while(q--){
		int x;
		long long int y;
		cin >> x >> y;
		vector<int> visited(n);
		dfs(x - 1,y,k,graph,visited);
		int ansi = 0;
		for (int i = 0; i < n; ++i)
			if(visited[i] == 3)
				ansi++;
		cout << ansi << endl;
	}

	return 0;
}