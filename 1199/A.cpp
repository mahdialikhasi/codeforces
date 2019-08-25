#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stdio.h>

int main(){
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	for (int i = 0; i < n; ++i){
		int tmp = a[i];
		int st = 0;
		for (int j = i - 1; j >= max(0, i - x); --j){
			if(tmp >= a[j]){
				st = 1;
				break;
			}
		}
		
		if(st == 1)
			continue;
		
		for (int j = i + 1; j <= min(i + y , n - 1); ++j){
			if(tmp >= a[j]){
				st = 1;
				break;
			}
		}
		
		if(st == 0){
			cout << i + 1 << endl;
			return 0;
		}
	}

	return 0;
}