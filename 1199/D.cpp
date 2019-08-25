#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<pair<int, long long int>> a(n);
	for (int i = 0; i < n; ++i)
	{
		long long int tmp;
		cin >> tmp;
		a[i] = make_pair(0, tmp);
	}
	int q;
	cin >> q;
	vector<long long int> e(q);
	for (int i = 0; i < q; ++i)
	{
		int type;
		cin >> type;
		if(type == 1){
			int p;
			long long int x;
			cin >> p >> x;
			a[p - 1] = make_pair(i, x);
		}
		if(type == 2){
			long long int x;
			cin >> x;
			e[i] = x;
		}
	}
	
	for (int i = q - 2; i >= 0; --i){
		e[i] = max(e[i], e[i + 1]);
	}

	// for (int i = 0; i < q; ++i)
	// {
	// 	cout << "s" << e[i] << endl;
	// }
	for (int i = 0; i < n; ++i){
		// cout << " p " << a[i].second << " i " << a[i].first << endl;
		// cout << " e " << e[a[i].first] << endl;
		cout << max(a[i].second, e[a[i].first]) << " ";
	}
	cout << endl;
	return 0;
}