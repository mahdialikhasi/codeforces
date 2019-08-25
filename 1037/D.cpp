#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
int main(){
	int n;
	cin >> n;
	vector<vector<int> > graph(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	queue<int> q;
	vector<int> visited(n);
	vector<int> parent(n);
	vector<int> level(n);
	q.push(0);
	visited[0] = 1;
	parent[0] = -1;
	level[0] = 0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for (int i = 0; i < graph[top].size(); ++i)
		{
			if(!visited[graph[top][i]]){
				q.push(graph[top][i]);
				visited[graph[top][i]] = 1;
				level[graph[top][i]] = level[top] + 1;
				parent[graph[top][i]] = top;
			}
		}
	}

	queue<int> sec;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		q.push(x - 1);
	}
	sec.push(q.front());
	q.pop();

	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(parent[top] == sec.front()){
			sec.push(top);
			continue;
		}else{
			sec.pop();
			while(!sec.empty()){
				if(parent[top] == sec.front()){
					sec.push(top);
					break;
				}
				sec.pop();
			}
			if(sec.empty()){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}