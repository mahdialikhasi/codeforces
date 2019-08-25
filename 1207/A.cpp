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
		int b, p, f;
		cin >> b >> p >> f;
		int h, c;
		cin >> h >> c;
		int ansi = 0;
		if(h > c){
			int ch = min(p, b / 2);
			ansi += h * ch;
			b -= ch * 2;
			int cc = min(f, b / 2);
			ansi += c * cc;
		}else{
			int cc = min(f, b / 2);
			ansi += c * cc;
			b -= cc * 2;
			int ch = min(p, b / 2);
			ansi += h * ch;
		}
		cout << ansi << endl;
	}
	return 0;
}