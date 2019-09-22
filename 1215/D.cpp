#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int n;
	cin >> n;
	string st;
	cin >> st;
	int c1 = 0, c2 = 0;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i){
		if(i < n / 2){
			if(st[i] != '?')
				sum1 += st[i] - '0';
			else
				c1++;
		}else{
			if(st[i] != '?')
				sum2 += st[i] - '0';
			else
				c2++;
		}
	}
	if(c1 > c2){
		swap(sum1, sum2);
		swap(c1, c2);
	}
	if(((c2 - c1) / 2) * 9 == sum1 - sum2){
		cout << "Bicarp" << endl;
	}else{
		cout << "Monocarp" << endl;
	}
	return 0;
}