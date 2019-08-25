#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
long long int rem = 0;
void solve(vector<vector<int> > &graph, vector<int> &visited, vector<int> &child, vector<int> &parent, int s){
	visited[s] = 1;
	child[s] = 1;
	for (int i = 0; i < graph[s].size(); ++i)
	{
		if(!visited[graph[s][i]]){
			parent[graph[s][i]] = s;
			solve(graph, visited, child, parent, graph[s][i]);
		}
	}

	for (int i = 0; i < graph[s].size(); ++i)
	{
		if(graph[s][i] != parent[s] && child[graph[s][i]] % 2 == 0){
			rem++;
		}
		else if(graph[s][i] != parent[s]){
			child[s] += child[graph[s][i]];
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<int> > graph(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	vector<int> visited(n);
	vector<int> child(n); 
	vector<int> parent(n);
	parent[0] = -1;
	solve(graph, visited, child, parent, 0);
	
	if(child[0] % 2 == 0){
		cout << rem << endl;
	}else{
		cout << -1 << endl;
	}

	return 0;
}