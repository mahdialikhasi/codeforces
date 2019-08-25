#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int n;
	cin >> n;
	vector<vector<int> > graph(n, vector<int >(n, 3000));
	for (int i = 0; i < n; ++i){
		string st;
		cin >> st;
		for (int j = 0; j < st.size(); ++j){
			if(st[j] == '1'){
				graph[i][j] = 1;
			}
		}
		graph[i][i] = 0;
	}
	for (int k = 0; k < n; ++k){
		for (int j = 0; j < n; ++j){
			for (int i = 0; i < n; ++i){
				if(graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	int m;
	cin >> m;
	vector<int> p(m);
	vector<int> st(m);
	for (int i = 0; i < m; ++i){
		cin >> p[i];
	}
	
	st[0] = 1;
	st[m - 1] = 1;
	int first = 0;
	for (int i = 2; i < m; ++i)
	{
		if(graph[p[first] - 1][p[i] - 1] < i - first){
			// cout << i << 's' << first << endl;
			st[i - 1] = 1;
			first = i - 1;
		}
	}

	int count = 0;
	for (int i = 0; i < m; ++i){
		if(st[i])
			count++;
	}
	cout << count << endl;
	for (int i = 0; i < m; ++i)
	{
		if(st[i])
			cout << p[i] << " ";
	}
	cout << endl;
	return 0;
}