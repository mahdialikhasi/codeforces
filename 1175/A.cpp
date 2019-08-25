#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>

int main(){
	int t;
	cin >> t;
	while(t--){
		long long int n, k;
		cin >> n >> k;
		long long int count = 0;
		while(n != 0){
			if(!(n % k)){
				count++;
				n /= k;
			}else{
				long long int tmp = n - ((n / k) * k);
				count += tmp;
				n -= tmp;
			}
		}
		cout << count << endl;
	}
	return 0;
}