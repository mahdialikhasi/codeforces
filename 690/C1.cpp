#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <vector>
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
	if(m != n - 1){
		cout << "no" << endl;
	}else{
		vector<int> visited(n);
		queue<int> q;
		q.push(0);
		visited[0] = 1;
		while(!q.empty()){
			int top = q.front();
			q.pop();
			for (int i = 0; i < graph[top].size(); ++i)
			{
				if(!visited[graph[top][i]]){
					visited[graph[top][i]] = 1;
					q.push(graph[top][i]);
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if(!visited[i]){
				cout << "no" << endl;
				return 0;
			}
		}
		cout << "yes" << endl;
	}
	return 0;
}