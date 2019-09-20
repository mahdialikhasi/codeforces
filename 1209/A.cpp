#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> c(n);
	int count = 1;
	for (int i = 0; i < n; ++i){
		if(c[i] == 0){
			c[i] = count;
			count++;
		}else
			continue;
		for (int j = 0; j < n; ++j){
			if(a[j] % a[i] == 0)
				c[j] = c[i];
		}
	}
	cout << count - 1 << endl;
	return 0;
}