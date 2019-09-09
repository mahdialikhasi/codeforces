#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <math.h>
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		long long int x;
		cin >> n >> x;
		pair<long long int, long long int> a;
		long long int diff = 0;
		long long int largest = 0;
		for(int i = 0; i < n; ++i){
			long long int t1,t2;
			cin >> t1 >> t2;
			if(t1 - t2 > diff || (t1 - t2 == diff && t1 > a.first)){
				a.first = t1;
				a.second = t2;
				diff = t1 - t2;
			}
			largest = max(largest, t1);
		}
		if(x - largest <= 0){
			cout << 1 << endl;
			continue;
		}
		if(!diff){
			cout << -1 << endl;
			continue;
		}
		diff = a.first - a.second;
		x -= largest;
		long long int ansi = ceil(double(x) / diff);
				
		cout << ansi + 1 << endl;
	}
	return 0;
}