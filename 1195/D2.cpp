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
	vector<long long int> c(n);
	long long int b[12] = {};
	for (int i = 0; i < n; ++i){
		long long int tmp;
		cin >> tmp;
		a[i] = tmp;
		long long int z = 0;
		while(tmp != 0){
			tmp /= 10;
			z ++;
		}
		b[z]++;
		c[i] = z;
	}

	for (int i = 0; i < n; ++i){
		long long int count = 0;
		//cout << "i:" << a[i] << endl; 
		for (int j = 0; j < c[i]; ++j){
			// c[i] - j
			if(b[j] == 0)
				continue;
			//cout << "j:" << b[j] << ":" << j << endl;
			long long int tmp = a[i];
			for (int i = 0; i < j; ++i){
				tmp /= 10;
			}
			tmp *= 2 * b[j];
			tmp %= 998244353;
			for (int i = 0; i < 2 * j; ++i){
				tmp *= 10;
				tmp %= 998244353;
			}
			ansi += tmp;
			ansi %= 998244353;
			//cout << "first part :" << tmp << endl;

			int d = pow(10, j);
			int tmp2 = a[i] % d;
		
			long long int z = 1;
			long long int ansi2 = 0;
			while(tmp2 != 0){
				z = (z % 998244353);
				int x = tmp2 % 10;
				tmp2 /= 10;
				x *= 11;
				ansi2 += z * x;
				ansi2 %= 998244353;
				z *= 100;
			}
			ansi2 *= b[j];
			ansi2 %= 998244353;

			//cout << "second part : " << ansi2 << endl;

			ansi += ansi2;
			ansi %= 998244353;
			count += b[j];
		}

		long long int z = 1;
		long long int tmp = a[i];
		long long int ansi2 = 0;
		while(tmp != 0){
			z = (z % 998244353);
			int x = tmp % 10;
			tmp /= 10;
			x *= 11;
			ansi2 += z * x;
			ansi2 %= 998244353;
			z *= 100;
		}
		ansi2 *= n - count;
		ansi2 %= 998244353;
		ansi += ansi2;
		ansi %= 998244353;

	}
	cout << ansi << endl;
	return 0;
}