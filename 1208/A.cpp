#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int t;
	cin >> t;
	while(t--){
		long long int a, b, n;
		cin >> a >> b >> n;
		long long int c = a ^ b;
		if(n % 3 == 0){
			cout << a << endl;
			continue;
		}else if(n % 3 == 1){
			cout << b << endl;
			continue;
		}else{
			cout << c << endl;
		}
		
	}
	return 0;
}