#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<int> h(n);
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	vector<int> diff(n);
	for (int i = 0; i < n; ++i){
		diff[i] = v[i] - h[i];
	}
	int c = diff[0];
	if(c < 0){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < n; ++i){
		if(diff[i] == c)
			continue;
		else if(diff[i] < c){
			cout << c << endl;
			return 0;
		}else{
			cout << c + 1 << endl;
			return 0;
		}
	}
	cout << c << endl;
	return 0;
}