#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	// vector<long long int> a(n);
	long long int ansi = 0;
	long long int count = 0;
	long long int zero = 0;
	for (int i = 0; i < n; ++i){
		// cin >> a[i];
		long long int tmp;
		cin >> tmp;
		if(tmp < 0){
			ansi += -1 - tmp;
			count++;
		}else if(tmp > 0){
			ansi += tmp - 1;
		}else{
			ansi += 1;
			zero++;
		}
	}
	if(count % 2 == 0)
		cout << ansi << endl;
	else{
		if(zero)
			cout << ansi << endl;
		else
			cout << ansi + 2 << endl;
	}
	return 0;
}