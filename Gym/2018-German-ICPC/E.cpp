#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <math.h>
long long int gcd(long long int a, long long int b){
	if(a > b)
		swap(a, b);
	if(a == 0)
		return b;
	return gcd(a, b % a);
}

int prime(long long int a){
	if(a == 1)
		return 0;

	int count = 1;
	for (int i = 2; i <= sqrt(a); ++i){
		if(a % i == 0){
			count = 0;
			break;
		}
	}
	return count;
}
int main(){
	int n;
	cin >> n;
	while(n--){
		string a, b;
		cin >> a >> b;
		
		long long int c = 0;
		long long int d = 0;

		int st1 = 0;
		int count = 0;
		for (int i = 0; i < a.size(); ++i){
			if(a[i] != '.')
				c *= 10;
			if(a[i] != '.')
				c += a[i] - '0'; 
			else
				st1 = 1;
			if(st1)
				count++;
		}
		for (int i = count; i < 6; ++i){
			c *= 10;
		}

		int st2 = 0;
		count = 0;
		for (int i = 0; i < b.size(); ++i){
			if(b[i] != '.')
				d *= 10;
			if(b[i] != '.')
				d += b[i] - '0'; 
			else
				st2 = 1;
			if(st2)
				count++;
		}
		for (int i = count; i < 6; ++i){
			d *= 10;
		}

		// cout << c << " " << d << endl;
		long long int g = gcd(c,d);
		c /= g;
		d /= g;

		if(c == d){
			c = 2;
			d = 2;
		}

		if(prime(c) && prime(d))
			cout << c << " " << d << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}