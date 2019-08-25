#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int m, n;
	cin >> n >> m;
	vector<int> a(n);
	vector<pair<int, int> > b(m);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		b[i] = make_pair(t, i);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> f(m);
	int first = 0;
	for (int i = 0; i < m; ++i)
	{
		int count = first;
		for (int j = first; j < n; ++j)
		{
			first = j;
			if(a[j] <= b[i].first)
				count++;
			else
				break;
		}
		f[b[i].second] = count;
		
	}
	for (int i = 0; i < m; ++i)
	{
		cout << f[i] << " ";
	}
	cout << endl;
	return 0;
}