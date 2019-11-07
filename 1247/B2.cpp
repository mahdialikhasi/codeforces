#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k,d;
		cin >> n >> k >> d;
		map<int, int> m;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < d; ++i){
			m[a[i]]++;
		}
		int ansi = 0;
		ansi = m.size();
		for (int i = d; i < n; ++i){
			m[a[i - d]]--;
			m[a[i]]++;
			if(m[a[i - d]] == 0)
				m.erase(a[i - d]);
			ansi = min(ansi, (int)m.size());
		}
		cout << ansi << '\n';
	}
	return 0;
}