#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	long long int n;
	cin >> n;
	long long int d, e;
	cin >> d >> e;
	long long int a = 5 * e;
	long long int b = d;
	long long int ansi = n;
	for (int i = 0; i < n / d + 2; ++i){
		long long int s = i * b;
		long long int t = n - s;
		if(t >= 0){
			ansi = min(ansi, t % a);
		}
	}
	// long long int ansi2 = 
	cout << ansi << endl;
	return 0;
}