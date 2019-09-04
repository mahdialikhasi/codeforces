#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <string>
int main(){
	int n;
	cin >> n;
	string b;
	cin >> b;
	stack<char> st;
	int stat = 0;
	for (int i = 0; i < n; ++i){
		if(b[i] == '(')
			st.push('(');
		else if(!st.empty() && b[i] == ')')
			st.pop();
		else{
			if(stat == 0)
				stat = 1;
			else
				stat = 2;
		}
	}
	if(!st.empty() && stat == 1)
		st.pop();
	else if(stat == 1 || stat == 2)
		st.push(')');
	if(st.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}