#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <map>
long long int gcd(long long int a, long long int b){
	if(a < b)
		swap(a, b);
	if(a % b == 0)
		return b;
	return gcd(a % b, b);
}
int main(){
	long long int n;
	cin >> n;
	vector<long long int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	long long int pr = a[0];
	for (int i = 1; i < n; ++i)
	{
		pr = gcd(pr, a[i]);
	}
	// cin >> pr;
	
	// cout << pr << endl;
	map<long long int, long long int> m;
	while(pr != 1){
		int i = 2;
		for (; i <= sqrt(pr); ++i){
			// cout << pr << endl;
			if(!(pr % i)){
				m[i]++;
				pr /= i;
				break;
			}
		}
		if(pr > 1 && i > sqrt(pr)){
			// cout << pr << endl;
			m[pr]++;
			pr /= pr;
		}
	}
	long long int ansi = 1;
	for (auto i = m.begin(); i != m.end(); ++i)
	{
		// cout << i->second << endl;
		ansi *= i->second + 1;
	}
	cout << ansi << endl;
	return 0;
}