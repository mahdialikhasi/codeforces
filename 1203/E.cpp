#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	vector<int> all(150000);
	cin >> n;
	vector<pair<int, int> > no;
	for (int i = 0; i < n; ++i){
		int t;
		cin >> t;
		all[t - 1]++;
	}
	
	for (int i = 0; i < all.size(); ++i){
		if(all[i]){
			// cout << all[i] << endl;
			no.push_back(make_pair(all[i], i));
		}
	}
	sort(no.rbegin(), no.rend());
	for (int i = 0; i < no.size(); ++i)
	{
		if(no[i].first >= 3){
			if(no[i].second > 0){
				all[no[i].second]--;
				all[no[i].second - 1]++;				
			}
			if(no[i].second < 150000 - 2){
				all[no[i].second]--;
				all[no[i].second + 1]++;
				// cout << no[i].second << "to" << no[i].second + 1 << endl;
			}
		}else if(no[i].first == 2){
			if(no[i].second < 150000 - 2 && !all[no[i].second + 1]){
				all[no[i].second]--;
				all[no[i].second + 1]++;
			}else if(no[i].second > 0 && all[no[i].second - 1]){
				all[no[i].second]--;
				all[no[i].second - 1]++;
			}
		}else{
			if(no[i].second < 150000 - 2 && !all[no[i].second + 1]){
				all[no[i].second]--;
				all[no[i].second + 1]++;
			}else if(all[no[i].second] > 1 && no[i].second > 0){
				all[no[i].second]--;
				all[no[i].second - 1]++;	
			}
		}
	}

	int ansi = 0;
	for (int i = 0; i < all.size(); ++i)
	{
		if(all[i])
			ansi++;
	}
	cout << ansi << endl;
	return 0;
}