#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	long long int m;
	cin >> m;
	vector<long long int> a(10000000);
	for (long long int i = 0; i < a.size(); ++i){
		a[i] = i * i;
	}
	for (int j = 0; j < 60; ++j){
		long long int k = 0;
		for (long long int i = 0; i < a.size(); ++i){
			k += a[i];
			if(k > m)
				break;
			if(k == m){
				cout << j + 3 << " " << i << endl;
				return 0;
			}
		}
		for (long long int i = 0; i < a.size(); ++i){
			a[i] *= i;
		}
	}
	cout << "impossible" << endl;
	return 0;
}