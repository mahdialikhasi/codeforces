#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
int main(){
	int n;
	cin >> n;
	vector<vector<long long int> > m(n, vector<long long int>(n));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> m[i][j];
		}
	}
	vector<long long int> a(n);
	a[0] = m[0][1] * m[0][2] / m[1][2];
	for (int i = 1; i < n - 1; ++i){
		a[i] = m[i][0] * m[i + 1][i] / m[i + 1][0];
	}
	a[n - 1] = m[n - 1][0] * m[n - 2][n - 1] / m[n - 2][0];
	for (int i = 0; i < n; ++i){
		cout << (long long int)(sqrt(a[i])) << " ";
	}
	cout << endl;
	return 0;
}