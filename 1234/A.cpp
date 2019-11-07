#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <math.h>
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		long long int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			long long int t;
			cin >> t;
			sum += t;
		}
		if(sum % n == 0)
			cout << (sum / n) << endl;
		else
			cout << (sum / n) + 1 << endl;
	}

	return 0;
}