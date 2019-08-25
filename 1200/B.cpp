#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int t;
	cin >> t;
	while(t--){
		long long int n,m,k;
		cin >> n >> m >> k;
		vector<long long int> height(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> height[i];
		}
		// cout << "--" << endl;
		int st = 0;
		for (int i = 0; i < n - 1; ++i){
			if(height[i] >= height[i + 1]){
				m += height[i] - height[i + 1];
				height[i] = height[i + 1];
				if(height[i] >= k){
					m += k;
					height[i] -= k;
				}else{
					m += height[i];
					height[i] = 0;
				}
			}else{
				if(height[i + 1] - height[i] <= k){
					long long int diff = k - (height[i + 1] - height[i]);
					if(diff > height[i]){
						m += height[i];
						height[i] = 0;
					}else{
						m += diff;
						height[i] = height[i + 1] - k;
					}
				}else{
					long long int diff = height[i + 1] - height[i] - k;
					if(diff > m){
						st = 1;
						break;
					}else{
						m -= diff;
						height[i] += diff;
					}
				}
			}
			// cout << height[i] << " ";
		}
		// cout << endl;
		if(st)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}