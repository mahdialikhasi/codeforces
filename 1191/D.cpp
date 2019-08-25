#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int n, k;
	cin >> n >> k;
	string a;
	cin >> a;

	
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; ++i){
		if(a[i] != a[0])
			break;
		else
			x++;
	}
	for (int i = n - 1; i >= 0; --i){
		if(a[i] != a[n - 1])
			break;
		else
			y++;
	}

	if(x + k >= n || y + k >= n || (x + y + k >= n && a[0] == a[n - 1])){
		cout << "tokitsukaze" << endl;
		return 0;
	}
	if(x == n-k-1 && y == n-k-1 && a[0] != a[n-1] && k >= (n+1)/2){
		cout << "quailty" << endl;
	}else{
		cout << "once again" << endl;
	}
	
	
	return 0;
}