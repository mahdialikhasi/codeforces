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
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<pair<int , int> > ct;
		int count = 1;
		for (int i = 1; i < n; ++i)
		{
			if(a[i] == a[i - 1])
				count++;
			else{
				ct.push_back(make_pair(count, a[i - 1]));
				count = 1;
			}
		}
		ct.push_back(make_pair(count, a[n - 1]));
		sort(ct.rbegin(), ct.rend());
		int ccount = ct[0].first;
		long long int ansi = ccount;
		for (int i = 1; i < ct.size(); ++i)
		{
			if(ct[i].first < ccount){
				ccount = ct[i].first;
				ansi += ccount;
			}else{
				ccount--;
				if(ccount > 0)
					ansi += ccount;
			}
		}
		cout << ansi << endl;
		
	}
	return 0;
}