#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
long long int gcd(long long int a, long long int b){
	if(a < b)
		swap(a, b);
	if(a % b == 0)
		return b;
	return gcd(a % b, b);
}
int main(){
	long long int n, m;
	int q;
	cin >> n >> m >> q;
	long long int g = gcd(n, m);
	// long long int common = (n / g) * m;
	long long int t1 = n / g;
	long long int t2 = m / g;
	// cout << common << endl;
	for (int i = 0; i < q; ++i)
	{
		long long int s1, s2;
		cin >> s1 >> s2;
		long long int e1, e2;
		cin >> e1 >> e2;
		if(s1 == 1){
			if(e1 == 1){
				if((s2 - 1) / t1 == (e2 - 1) / t1){
					cout << "YES" << endl;
				}else{
					cout << "NO" << endl;
				}
			}else{
				if((s2 - 1) / t1 == (e2 - 1) / t2){
					cout << "YES" << endl;
				}else{
					cout << "NO" << endl;
				}
			}
		}else{
			if(e1 == 1){
				if((s2 - 1) / t2 == (e2 - 1) / t1){
					cout << "YES" << endl;
				}else{
					cout << "NO" << endl;
				}
			}else{
				if((s2 - 1) / t2 == (e2 - 1) / t2){
					cout << "YES" << endl;
				}else{
					cout << "NO" << endl;
				}
			}
		}
	}
	return 0;
}