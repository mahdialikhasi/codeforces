#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>

int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > intervals(n);
	vector<pair<int, int> > queries(m);
	for (int i = 0; i < n; ++i)
	{
		cin >> intervals[i].first >> intervals[i].second;
	}
	sort(intervals.begin(), intervals.end());

	vector<int> after(n);

	for (int i = 0; i < n; ++i){
		int maxi = intervals[i].second;
		int maxiIndex = i;
		for (int j = i + 1; j < n; ++j){
			if(intervals[i].second >= intervals[j].first && intervals[i].second <= intervals[j].second){
				if(intervals[j].second > maxi){
					maxi = intervals[j].second;
					maxiIndex = j;
				}
			}else if(intervals[i].second < intervals[j].first){
				break;
			}
		}
		after[i] = maxiIndex;
	}

		
	for (int i = 0; i < m; ++i){
		cin >> queries[i].first >> queries[i].second;
		int startpoint = queries[i].first;
		
		int startI = -1;
		int maxi = -1;
		
		for (int j = 0; j < n; ++j){
			if(startpoint >= intervals[j].second)
				continue;
			else if(intervals[j].first <= startpoint && intervals[j].second > startpoint){
				if(intervals[j].second > maxi){
					maxi = intervals[j].second;
					startI = j;
				}
			}
			else if(startpoint < intervals[j].first)
				break;
		}

		int count = 1;
		if(startI != -1){
			while(intervals[startI].second < queries[i].second){
				// cout << intervals[startI].first << endl;
				if(after[startI] != startI){
					startI = after[startI];
					count ++;
				}else
					break;
			}
			if(intervals[startI].second >= queries[i].second)
				cout << count << endl;
			else
				cout << -1 << endl;	
		}else{
			cout << -1 << endl;
		}
		
	}
	return 0;
}
