#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <math.h>
int main(){
	long long int n, k;
	cin >> n >> k;
	long long int m = (sqrt(4 + 4 * (2 * k + 2 * n)) - 2) / 2;
	cout << n - m << endl;
	return 0;
}