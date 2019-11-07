#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>

int main(){
	long long int n, p;
	cin >> n >> p;
	long long int m = 0;
	while(true){
		long long t = n - m * p;
		if(t < 0)
			break;
		long long num = t;
		long long int count2 = 0;
		while(t > 0){
			if(t % 2){
				count2++;
			}
			t /= 2;
		}
		if(num >= m && m >= count2){
			cout << m << endl;
			return 0;
		}
		
		m++;
	}
	cout << -1 << endl;
	return 0;
}