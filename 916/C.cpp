#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>

long long int findNextPrime(long long int no){
	for (int i = 1; true; ++i)
	{
		int j = 2;
		for (; j < int(sqrt(no + i)) + 1; ++j)
		{
			if((no + i) % j == 0){
				break;
			}
		}
		if(j == int(sqrt(no + i)) + 1){
			return no + i;
		}
	}
}

void print(vector<vector<pair<int, int> > > &graph){
	for (int i = 0; i < graph.size(); ++i)
	{
		for (int j = 0; j < graph[i].size(); ++j)
		{
			cout << i + 1 << " " << graph[i][j].first + 1 << " " << graph[i][j].second << endl;
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > graph(n);
	graph[0].push_back(make_pair(n - 1, 2));
	long long int sum = 2;
	for (int i = 0; i < n - 3; ++i)
	{
		graph[0].push_back(make_pair(i + 1, 2));
		sum += 2;
	}
	if(m > 1){
		int next = findNextPrime(sum) - sum;
		graph[0].push_back(make_pair(n - 2, next));
		
		int f = 1;
		int l = 2;
		for (int i = 0; i < m - n + 1; ++i)
		{
			if(l == n){
				f++;
				l = f + 1;
			}
			graph[f].push_back(make_pair(l, max(2, next) + 1));
			l++;
		}
		cout << 2 << " " << sum + next << endl;
	}else{
		cout << 2 << " " << 2 << endl;
	}
	print(graph);
	return 0;
}