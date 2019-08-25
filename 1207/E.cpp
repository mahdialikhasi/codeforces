#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	vector<int> a(100);
	vector<int> b(100);
	for (int i = 0; i < 100; ++i)
	{
		b[i] = i + 1;
		a[i] = i * 128;
	}

	cout << "? ";
	for (int i = 0; i < 100; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << flush;
	int x;
	cin >> x;
	cout << "? ";
	for (int i = 0; i < 100; ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << flush;
	int y;
	cin >> y;
	int ansi = x ^ y;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if(ansi == (a[i] ^ b[j])){
				cout << "! " << (x ^ a[i]) << endl;
				cout << flush;
				return 0;
			}
		}
	}
	return 0;
}