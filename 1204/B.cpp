#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n, l, r;
	cin >> n >> l >> r;
	vector<long long int> nu(n);
	nu[0] = 1;
	long long int ansi = 1;
	for (int i = 1; i < l; ++i){
		nu[i] = nu[i - 1] * 2;
		ansi += nu[i];
	}
	cout << ansi + (n - l) << " ";
	for (int i = l; i < r; ++i){
		nu[i] = nu[i - 1] * 2;
		ansi += nu[i];
	}
	cout << ansi + (n - r) * nu[r - 1] << endl;
	return 0;
}