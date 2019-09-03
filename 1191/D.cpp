#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<long long int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	// check all zero
	int st = 0;
	for (int i = 0; i < n; ++i){
		if(a[i] != 0){
			st = 1;
			break;
		}
	}
	if(!st){
		cout << "cslnb" << endl;
		return 0;
	}
	// check double
	int count = 1;
	int countTWO = 0;
	for (int i = 1; i < n; ++i)
	{
		if(a[i] == a[i - 1])
			count++;
		else
			count = 1;
		if(count == 2)
			countTWO++;
		if(count > 2)
			break;
	}
	if(count > 2 || countTWO > 1){
		cout << "cslnb" << endl;
		return 0;
	}
	long long int ansi = 0;
	int turn = 1;
	for (int i = 0; i < n; ++i){
		ansi = a[i] - i;
		if(ansi < 0 || (i >= 2 && a[i] == a[i - 1] && a[i] == a[i - 2] + 1)){
			cout << "cslnb" << endl;
			return 0;
		}
		turn ^= ansi % 2;
	}
	if(turn == 1)
		cout << "cslnb" << endl;
	else
		cout << "sjfnb" << endl;
	return 0;
}