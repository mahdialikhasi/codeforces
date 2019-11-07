#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
long long int pp(long long int p, long long int count){
	long long int q = 1;
	if(count > 1){
		q *= pp(p, count / 2);
		q %= 1000000000 + 7;
		if(count % 2 == 0){
			q *= q;
			q %= 1000000000 + 7;
		}else{
			q *= q;
			q %= 1000000000 + 7;
			q *= p;
			q %= 1000000000 + 7;
		}		
	}else if(count == 1){
		q = p;
		q %= 1000000000 + 7;
	}else{
		q = 1;
	}
	return q;
}
long long int gcd(long long int a, long long int b){
	if(a > b)
		swap(a, b);
	if(a == 0)
		return b;
	return gcd(b % a, a);
}
int isPrime(long long int x){
	int st = 0;
	for (long long int i = 2; i <= sqrt(x); ++i){
		if(x % i == 0){
			st = 1;
			break;
		}
	}
	return !st;
}
int main(){
	long long int x, n;
	cin >> x >> n;
	map<long long int, long long int> m;
	for (long long int i = 2; i <= sqrt(x) ; ++i){
		if(x % i == 0){
			if(isPrime(i)){
				m[i] = 0;
			}
			if(isPrime(x / i)){
				m[x / i] = 0;
			}
		}
	}
	if(isPrime(x))
		m[x] = 0;
	for (auto i = m.begin(); i != m.end(); ++i){
		long long int z = i->first;
		long long int b = n;
		while(b / z > 0){
			i->second += b / z;
			b /= i->first;
		}
	}
	long long int f = 1;
	for (auto i = m.begin(); i != m.end(); ++i){
		long long int count = i->second;
		long long int p = i->first;
		// cout << "p" << p << "c" << count << endl;
		// cout << "pp" << pp(p, count) << endl;
		f *= pp(p, count);
		f %= 1000000000 + 7;
	}
	cout << f << endl;
	return 0;
}