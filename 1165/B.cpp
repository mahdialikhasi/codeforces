#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int count = 1;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i)
	{
		if(count <= a[i]){
			//cout << count << " " << a[i] << endl;
			count++;
		}
		else
			continue;
	}
	cout << count - 1 << endl;
	return 0;
}