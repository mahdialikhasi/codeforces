#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int q;
	cin >> q;
	while(q--){
		long long int k, n, a, b;
		cin >> k >> n >> a >> b;
		long long int q = max((long long int)0, k - 1) / b;
		if(q < n){
			cout << -1 << endl;
			continue;
		}
		long long int p = max((long long int)0, k - 1) / a;
		long long int upper = p;
		long long int lower = 0;
		while(lower < upper){
			long long int mid = (upper + lower + 1) / 2;
			if(k - (mid * a + (n - mid) * b) > 0 && k - mid * a > 0){
				lower = mid;
			}else{
				upper = mid - 1;
			}
		}
		cout << min(n, lower) << endl;
	}
	return 0;
}
