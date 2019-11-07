#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
int main(){
	long long int n,m;
	cin >> n >> m;
	vector<vector<int> > graph(n);
	for (int i = 0; i < m; ++i){
		int a,b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	vector<int> mark(n, 0);
	vector<int> th;
	vector<int> count(3);
	for (int i = 0; i < graph[0].size(); ++i){
		th.push_back(graph[0][i]);
		mark[graph[0][i]]++;
	}
	if(th.size() == 0){
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < graph[th[0]].size(); ++i){
		if(mark[graph[th[0]][i]] == 1)
			mark[graph[th[0]][i]]++;
	}
	for (int i = 0; i < n; ++i){
		count[mark[i]]++;
	}
	// check
	int st = 0;
	for (int i = 0; i < n; ++i){
		vector<int> c(3);
		for (int j = 0; j < graph[i].size(); ++j){
			c[mark[graph[i][j]]] ++;
		}
		if(mark[i] == 0){
			if(!(c[0] == 0 && count[1] == c[1] && count[2] == c[2]))
				st = 1;
		}else if(mark[i] == 1){
			if(!(count[0] == c[0] && c[1] == 0 && count[2] == c[2]))
				st = 1;
		}else{
			if(!(count[0] == c[0] && count[1] == c[1] && c[2] == 0))
				st = 1;
		}
	}
	if(st == 1 || (count[0] == 0 || count[1] == 0 || count[2] == 0)){
		cout << -1 << endl;
	}else{
		for (int i = 0; i < n; ++i){
			cout << mark[i] + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}