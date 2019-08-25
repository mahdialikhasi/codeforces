#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <deque>

void add(deque<pair<int, int> > &deq, int no, int index){
	while(!deq.empty() && deq.back().first > no){
		deq.pop_back();
	}
	deq.push_back(make_pair(no, index));
	// cout << "putting " << no << endl;
	// cout << "head is " << deq.front().first << endl;
}

void rem(deque<pair<int, int> > &deq, int index){
	while(!deq.empty() && deq.front().second <= index){
		deq.pop_front();
	}
}

int mini(deque<pair<int, int> > &deq){
	return deq.front().first;
}

int main(){
	int m,n,a,b;
	cin >> n >> m >> a >> b;
	vector<long long int> g(n + m + m * n);
	int g0, x, y, z;
	cin >> g0 >> x >> y >> z;
	g[0] = g0;
	for (int i = 1; i < n + m + m * n; ++i)
	{
		g[i] = (g[i - 1] * x + y) % z;
	}
	vector<vector<int> > grid(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			grid[i][j] = g[i * m + j];
		}
	}
	// cout << "----" << endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }




	vector<vector<int> > mn(n, vector<int>(m));
	for (int j = 0; j < m; ++j)
	{
		deque<pair<int, int> > deq;
		for (int i = 0; i < n; ++i)
		{
			if(i < a)
				add(deq, grid[i][j], i);
			else{
				rem(deq, i - a);
				add(deq, grid[i][j], i);
			}
			mn[i][j] = mini(deq);
		}
	}
	// cout << "----" << endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		cout << mn[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }



	vector<vector<int> > mn2(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		deque<pair<int, int> > deq;
		for (int j = 0; j < m; ++j)
		{
			if(j < b)
				add(deq, mn[i][j], j);
			else{
				rem(deq, j - b);
				add(deq, mn[i][j], j);
			}
			mn2[i][j] = mini(deq);
		}
	}
	// cout << "----" << endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		cout << mn2[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }



	long long int ansi = 0;
	for (int i = a - 1; i < n; ++i)
	{
		for (int j = b - 1; j < m; ++j)
		{
			ansi += mn2[i][j];
		}
	}
	cout << ansi << endl;

	return 0;
}