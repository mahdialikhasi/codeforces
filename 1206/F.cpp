#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>

void dfs2(int s, vector<int> &visited, vector<vector<int> > &graph, vector<int> &numbers, int next){
	visited[s] = 1;
	for (int i = 0; i < graph[s].size(); ++i){
		if(visited[i] == 0 && graph[s][i] > 0){
			if(next + graph[s][i] < numbers.size()){
				// cout << next + graph[s][i] << "s" << endl;
				numbers[next + graph[s][i]] = 1;
				// cout << numbers.size() << endl;
			}
			dfs2(i, visited, graph, numbers, next + graph[s][i]);
		}
	}
}

void dfs(int s, vector<int> &visited, vector<vector<int> > &graph, vector<int> &numbers, int &next){
	visited[s] = 1;
	for (int i = 0; i < graph[s].size(); ++i){
		if(graph[s][i] == 0 && visited[i] == 0){
			for (int j = next; j < numbers.size(); ++j, next++){
				if(numbers[j] == -1)
					break;
			}
			numbers[next] = 1;
			// cout << next << "sss";
			graph[s][i] = graph[i][s] = next;
			vector<int> visited2(visited.size());
			dfs2(i, visited2, graph, numbers, 0);
			dfs(i, visited, graph, numbers, next);
		}
	}
}

void depth(int s, vector<int> &visited, vector<vector<int> > &graph, vector<int> &dep){
	visited[s] = 1;
	for (int i = 0; i < graph[s].size(); ++i){
		if(graph[s][i] == 0 && visited[i] == 0){
			dep[i] = dep[s] + 1;
			depth(i, visited, graph, dep);
		}
	}
}


int main(){
	int n;
	cin >> n;
	vector<vector<int> > graph(n, vector<int>(n, -1));
	vector<pair<int, int> > input(n);
	for (int i = 0; i < n - 1; ++i){
		int x,y;
		cin >> x >> y;
		input[i] = make_pair(x, y);
		graph[x - 1][y - 1] = 0;
		graph[y - 1][x - 1] = 0;
	}
	vector<int> visited(n);
	vector<int> numbers(ceil(2 * n * n / 9) + 10, -1);
	// cout << ceil(2 * n * n / 9) << endl;
	numbers[0] = 1;
	int next = 1;
	// vector<int> v2(n);
	// vector<int> dep(n);
	// depth(0, v2,graph,dep);
	// int index = -1;
	// int maxi = -1;
	// for (int i = 0; i < n; ++i)
	// {
	// 	if(dep[i] > maxi){
	// 		maxi = dep[i];
	// 		index = i;
	// 	}
	// }
	dfs(0, visited, graph, numbers, next);

	for (int i = 0; i < n - 1; ++i){
		cout << input[i].first << " " << input[i].second << " " << graph[input[i].first - 1][input[i].second - 1] << endl;
	}
	// cout << "--" << endl;
	// cout << ceil(2 * n * n / 9) << endl;
	// for (int i = 1; i < ceil(2 * n * n / 9) + 1; ++i)
	// {
	// 	cout << numbers[i] << " ";
	// }
	return 0;
}