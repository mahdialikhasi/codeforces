#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int n, m;
	cin >> n >> m;
	vector<string> answer(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> answer[i];
	}
	vector<int> score(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> score[i];
	}
	vector<vector<int> > count(m, vector<int>(5));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			count[j][answer[i][j] - 'A']++;
		}
	}
	long long int ansi = 0;
	for (int i = 0; i < m; ++i)
	{
		ansi += max(count[i][0], max(count[i][1], max(count[i][2], max(count[i][3], count[i][4])))) * score[i];
	}
	cout << ansi << endl;
	return 0;
}