#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int t;
	cin >> t;
	while(t--){
		long long int str,intel, expr;
		cin >> str >> intel >> expr;
		long long int dif = str - intel;
		long long int ansi = 0;
		long long int b = (str - intel + expr) / 2;
		if(expr - b + str == b + intel && b >= 0)
			b--;
		if(b > expr)
			b = expr;
		if(b < 0)
			b = -1;
		if(b + intel > expr - b + str)
			b = -1;
		ansi = b + 1;		
		cout << ansi << endl;
	}
	return 0;
}