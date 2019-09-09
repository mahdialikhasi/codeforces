#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int n;
	cin >> n;
	vector<long long int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	vector<long long int> circle(n);
	circle[0] = a[0];
	circle[circle.size() - 1] = a[1];
	circle[1] = a[2];
	for (int i = 2; i < n - 1; ++i){
		circle[i] = a[i + 1];
	}
	// check
	int st = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		if(circle[i - 1] + circle[i + 1] <= circle[i]){
			st = 1;
			break;
		}
	}
	if(circle[0] >= circle[n - 1] + circle[1] || circle[n - 1] >= circle[n - 2] + circle[0])
		st = 1;
	if(st){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << circle[i] << " ";
		}
		cout << endl;
	}
	return 0;
}