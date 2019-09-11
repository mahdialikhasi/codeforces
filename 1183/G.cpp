#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<pair<int, int> > a(n);
		for (int i = 0; i < n; ++i){
			cin >> a[i].first >> a[i].second;
		}
		sort(a.begin(), a.end());
		vector<pair<int , int> > ct;
		int count = 1;
		int bad = a[0].second;
		for (int i = 1; i < n; ++i){
			if(a[i].first == a[i - 1].first){
				if(a[i].second){
					bad++;
				}
				count++;
			}
			else{
				ct.push_back(make_pair(count, bad));
				count = 1;
				bad = a[i].second;
			}
		}
		ct.push_back(make_pair(count, bad));
		sort(ct.rbegin(), ct.rend());
		

		int ccount = ct[0].first;
		int bb = ct[0].second;
		long long int ansi = ccount;
		
		// bad, count
		priority_queue<pair<int, int> > s;
		int index = 0;
		for (int i = 1; i < ct.size(); ++i){
			if(ct[i].first < ccount){
				ccount = ct[i].first;
				ansi += ccount;
				bb += ct[i].second;
			}else{
				ccount--;
				index = max(index, i);	
				for (int j = index; j < ct.size(); ++j, index++){
					if(ct[j].first < ccount)
						break;
					s.push(make_pair(ct[j].second, ct[j].first));
				}
				
				if(ccount > 0){
					pair<int, int> tmp = s.top();
					s.pop();
					ansi += ccount;
					bb += min(tmp.first, ccount);
				}
			}
		}
		cout << ansi << " " << bb << endl;
		
	}
	return 0;
}