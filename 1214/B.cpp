#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>

int main(){
	int b;
	int g;
	cin >> b >> g;
	int n;
	cin >> n;
	long long int ansi = 0;
	for (int i = 0; i < n + 1; ++i)
	{
		int first, second;
		first = i;
		second = n - i;
		if(first > b || second > g){}else{
			ansi++;
		}
	}
	cout << ansi << endl;
	return 0;
}