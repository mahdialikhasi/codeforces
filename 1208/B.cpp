#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <map>
int main(){
	int n;
	cin >> n;

	vector<long long int> a(n);
	for (int i = 0; i < n; ++i){
	 	cin >> a[i];
	}


	int ansi =  n + 2;

	for (int i = 0; i < n; ++i){
		// check
		map<long long int, int> d;
		int st = 0;
		for (int k = 0; k < i; ++k){
			d[a[k]]++;
			if(d[a[k]] == 2){
				st = 1;
				break;
			}
		}
		if(st)
			continue;

		for (int k = n - 1; k >= i; --k){
			d[a[k]]++;
			if(d[a[k]] == 2){
				ansi = min(ansi, k - i + 1);
				break;
			}
		}
	}
	if(ansi == n + 2)
		cout << 0 << endl;
	else
		cout << ansi << endl;
	
	return 0;
}