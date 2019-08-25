#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
int main(){
	int t;
	cin >> t;
	while(t--){
		string x, y;
		cin >> x >> y;
		int firstY1 = y.size();
		for (int i = y.size() - 1; i >= 0; --i)
		{
			if(y[i] == '1'){
				firstY1 = y.size() - 1 - i;
				break;
			}
		}
		int firstX1 = firstY1;
		for (int i = x.size() - 1 - firstY1; i >= 0; --i)
		{
			if(x[i] == '1'){
				firstX1 = x.size() - 1 - i;
				break;
			}
		}
		cout << firstX1 - firstY1 << endl;	
	}
	
	return 0;
}