#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
int main(){
	int l;
	cin >> l;
	long long int x = 0;
	long long int depth = 1;
	long long int tresh = pow(2, 32) - 1;
	
	int st = 0;
	int depthst = 0;
	
	stack<long long int> nus;
	nus.push(depth);

	for (int i = 0; i < l; ++i)
	{
		string cmd;
		cin >> cmd;
		if(cmd == "add"){
			if(depthst == 1){
				st = 1;
			}
			x += depth;
			// cout << "d" << depth << endl;
		}else if(cmd == "for"){
			int nu;
			cin >> nu;
			if(depth * nu > tresh || depth == -1){
				depthst = 1;
				depth = -1;
				// cout << "nu" << nu  << "d" << depth << endl;
			}else{
				depth *= nu;
			}
			nus.push(depth);
			
		}else if(cmd == "end"){
			// cout << " b " << nus.top() << endl;
			nus.pop();
			// cout << " a " << nus.top() << endl;
			depth = nus.top();
			if(depth == -1)
				depthst = 1;
			else
				depthst = 0;
		}
		if(x > tresh)
			st = 1;
	}
	if(st)
		cout << "OVERFLOW!!!" << endl;
	else
		cout << x << endl;
	return 0;
}