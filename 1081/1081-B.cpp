#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<int> state(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> state[i];
	}
	vector<int> b(n);
	for (int i = 0; i < n; ++i)
	{
		b[i] = i + 1;
	}
	int y = 0;
	for (int i = 0; i < n; ++i)
	{
		// state[i]
		if(b[i] > y)
			y = b[i];
		else if(b[i] <= y)
			continue;
		int x = n - 1 - state[i];
		if(x > 0)
			for (int j = i + 1; j < n; ++j)
			{
				if(state[j] == state[i]){
					x--;
					b[j] = b[i];
					if(x == 0)
						break;
				}

			}
		
		// cout << i << "s" << y << endl;
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout << b[i] << " ";
		// }
		// cout << endl << endl;
		if(x > 0){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}