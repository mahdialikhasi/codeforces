#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > a(m);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		
		a[i].first = x;
		a[i].second = y;
	}

	vector<pair<int , int> > p(4);
	p[0].first = p[1].first = a[0].first;
	for (int i = 1; i < m; ++i)
	{
		if(a[i].first == a[0].first || a[i].second == a[0].first)
			continue;
		else{
			p[0].second = a[i].first;
			p[1].second = a[i].second;
			break;
		}
	}

	p[2].first = p[3].first = a[0].second;
	for (int i = 1; i < m; ++i)
	{
		if(a[i].first == a[0].second || a[i].second == a[0].second)
			continue;
		else{
			p[2].second = a[i].first;
			p[3].second = a[i].second;
			break;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		int j = 0; 
		for (;j < m; ++j)
		{
			if(a[j].first == p[i].first || a[j].first == p[i].second || a[j].second == p[i].first || a[j].second == p[i].second)
				continue;
			else
				break;
		}
		if(j == m){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}