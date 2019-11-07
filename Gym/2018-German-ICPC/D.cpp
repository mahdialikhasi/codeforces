#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	long long int n;
	cin >> n;
	vector<long long int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<long long int> b(n + 1);
	b[0] = a[0];
	for (int i = 0; i < n; ++i){
		b[i + 1] = a[i] - b[i];
	}
	long long int minO = 10000000000;
	long long int minE = 10000000000;
	for (int i = 0; i < n + 1; ++i)
	{
		if(i % 2)
			minO = min(minO, b[i]);
		else
			minE = min(minE, b[i]);
	}
	// cout << minE << endl;
	// cout << minO << endl;
	long long int count = 0;
	count = minO + minE;
	if(count >= 0)
		cout << count + 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}