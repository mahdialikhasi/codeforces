#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> stick(4 * n);
		for (int i = 0; i < n * 4; ++i){
			cin >> stick[i];
		}
		sort(stick.rbegin(), stick.rend());
		vector<int> sides(2 * n);
		int st = 0;
		for (int i = 0; i < 2 * n; ++i){
			if(stick[i * 2] != stick[i * 2 + 1]){
				// cout << stick[i * 2] << endl;
				// cout << stick[i * 2 + 1] << endl;
				st = 1;
			}
			sides[i] = stick[i * 2];
		}
		map<long long int, long long int> posible;
		for (int i = 0; i < 2 * n; ++i){
			if(sides[0] * sides[2*n - 1] != sides[i] * sides[2*n - 1 - i]){
				st = 1;
			}
		}
		
		if(st){
			cout << "NO" << endl;
			continue;
		}else{
			cout << "YES" << endl;
		}
		
		continue;

	}
	return 0;
}