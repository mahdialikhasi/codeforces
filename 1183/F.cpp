#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<long long int> c(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> c[i];
		}
		sort(c.rbegin(), c.rend());
		vector<long long int> a;
		a.push_back(c[0]);
		for (int i = 1; i < n; ++i)
		{
			if(c[i] != c[i - 1])
				a.push_back(c[i]);
		}
		long long int ansi = 0;
		for (int k = 0; k < 10 && k < a.size(); ++k){
			vector<int> t;
			t.push_back(a[k]);
			long long int count = a[k];
			for (int i = k + 1; i < a.size(); ++i){
				if(t[0] % a[i] != 0){
					if(t.size() == 1){
						t.push_back(a[i]);
						count += a[i];
					}else if(t[1] % a[i] != 0){
						t.push_back(a[i]);
						count += a[i];
					}
				}
				if(t.size() == 3)
					break;
			}
			ansi = max(ansi, count);
		}
		cout << ansi << endl;
	}
	return 0;
}