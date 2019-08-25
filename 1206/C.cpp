#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<int> t(2 * n, -1);
	int count = 1;
	int count2 = 2 * n;
	int st = 0;
	for (int i = 0; i < 2 * n; ++i){
		if(t[i] == -1 && t[(i + n) % (2 * n)] == -1){
			st ^= 1;
			if(st){
				t[i] = count++;
				t[(i + n) % (2 * n)] = count++;
			}else{
				t[i] = count2--;
				t[(i + n) % (2 * n)] = count2--;
			}
		}
	}
	int d = 0;
	for (int i = 0; i < n; ++i){
		d += t[i];
	}
	int mini = d, maxi = d;
	for (int i = 1; i < 2 * n; ++i){
		d -= t[i - 1];
		d += t[(n + i - 1) % (2 * n)];
		mini = min(mini, d);
		maxi = max(maxi, d);
	}
	// for (int i = 0; i < 2 * n; ++i)
	// {
	// 	cout << t[i] << " ";
	// }
	// cout << endl;
	// cout << mini << " " << maxi << endl;
	if(maxi - mini > 1)
		cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for (int i = 0; i < 2 * n; ++i)
		{
			cout << t[i] << " ";
		}
		cout << endl;
	}
	return 0;
}