#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
int main(){
	int n;
	cin >> n;
	int ce = 0;
	int co = 0;
	for (int i = 0; i < n; ++i)
	{
		long long int t;
		cin >> t;
		if(t % 2)
			ce++;
		else
			co++;
	}
	cout << min(co, ce) << endl;
	return 0;
}