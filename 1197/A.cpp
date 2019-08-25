#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		if(min(a[n - 2] - 1, n - 2) < 0)
			cout << 0 << endl;
		else
			cout << min(a[n - 2] - 1, n - 2) << endl;
	}
	return 0;
}