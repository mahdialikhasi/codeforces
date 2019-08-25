#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
int main(){
	int n;
	cin >> n;
	long long int ansi = 0;
	vector<long long int> a(n);
	for (int i = 0; i < n; ++i)
	{
		long long int tmp;
		cin >> tmp;
		long long int z = 1;
		while(tmp != 0){
			z = (z % 998244353);
			int x = tmp % 10;
			tmp /= 10;
			x *= 11;
			ansi += z * x;
			ansi %= 998244353;
			z *= 100;
		}

	}
	ansi *= n;
	ansi %= 998244353;
	cout << ansi << endl;
	return 0;
}