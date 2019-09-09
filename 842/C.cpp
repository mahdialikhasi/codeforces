#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
long long int gcd(long long int a, long long int b){
	if(a < b)
		swap(a,b);
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

void dfs_sol(int start, vector<vector<int> > &graph, vector<int> &visited, vector<long long int> &a, vector<long long int> &sol, vector<bool> &change){
	visited[start] = 1;
	for (int i = 0; i < graph[start].size(); ++i){
		if(!visited[graph[start][i]]){
			long long int tmp = gcd(a[graph[start][i]], sol[start]);
			if(tmp > sol[graph[start][i]]){
				change[graph[start][i]] = true;
				sol[graph[start][i]] = tmp;
			}
			dfs_sol(graph[start][i], graph, visited, a, sol, change);
		}
	}
}

// root < child not OK
// root > child OK
int main(){
	int n;
	cin >> n;
	vector<vector<int> > graph(n);
	vector<long long int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int p,q;
		cin >> p >> q;
		graph[p - 1].push_back(q - 1);
		graph[q - 1].push_back(p - 1);
	}
	vector<long long int> sol(n, 0);
	for (int i = 0; i < n; ++i){
		vector<long long int> at(a);
		at[i] = 0;
		sol[0] = at[0];
		vector<int> visited(n);
		vector<bool> change(n);
		dfs_sol(0, graph, visited, at, sol, change);
	}
	sol[0] = a[0];
	
	
	for (int i = 0; i < n; ++i)
	{
		cout << sol[i] << " ";
	}
	cout << endl;
	return 0;
}