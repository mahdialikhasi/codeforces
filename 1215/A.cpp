#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>

int main(){
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	int mini = 0, maxi = 0;
	int b = n;
	if(k1 > k2){
		swap(k1, k2);
		swap(a1, a2);
	}
	int t = min((n / k1), a1);
	n -= t * k1;
	maxi += t;
	t = min((n / k2), a2);
	maxi += t;
	
	t = 0;
	n = b;
	n = max(0, n - (k1 - 1) * (a1));
	n = max(0, n - (k2 - 1) * (a2));
	t = min(n, a2 + a1);
	mini += t;

	cout << mini << " " << maxi << endl;
	return 0;
}