#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<int> count(2 * n);
	vector<int> pile(n);
	int st = 0;
	int max = 0;
	int maxI = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> pile[i];
		count[pile[i]]++;
		if(count[pile[i]] > 1)
			st = 1;
		if(pile[i] > max){
			max = pile[i];
			maxI = i;
		}
	}

	for (int i = maxI + 1; i < n; ++i)
	{
		if(pile[i] >= pile[i - 1])
			st = 1;
	}

	for (int i = 0; i < maxI; ++i)
	{
		if(pile[i] >= pile[i + 1])
			st = 1;
	}
	if(st == 1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}