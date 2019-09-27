#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stack>
long long int n_digit(long long int n){
	long long int count = 0;
	do{
		++count;
		n /= 10;
	}while(n != 0);
	return count;
}
int main(){
	int q;
	cin >> q;
	while(q--){

		long long int k;
		cin >> k;
		long long int f1 = 0;
		long long int c = 0;
		long long int base = 0;
		long long int lbase = 0;
		long long int last = 0;
		while(f1 < k){
			long long int count = (9 * (pow(10, c)));
			last = (base * count) + (c + 1 + (c + 1) * count) * count / 2;
			f1 += last;
			c++;
			lbase = base;
			base += count * c;
			// cout << base << endl;
		}
		f1 -= last;
		k -= f1;
		
		long long int d = 0;
		last = 0;
		long long int count = 1;
		while(d < k){
			last = lbase + count * c;
			count++;
			d += last;
		}
		d -= last;
		k -= d;
		
		long long int i = 1;
		for (; ; ++i){
			k -= n_digit(i);
			if(k <= 0)
				break;
		}
		k += n_digit(i);
		long long int resualt = 0;
		
		count = n_digit(i) - k + 1;
		while(count > 0){
			resualt = i % 10;
			i /= 10;
			count--;
		}
		cout << resualt << endl;
		
	}
	

	return 0;
}