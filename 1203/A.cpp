#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> student(n);
		int index = -1;
		for (int i = 0; i < n; ++i)
		{
			cin >> student[i];
			if(student[i] == n)
				index = i;
		}
		// check clockwise
		int st1 = 1;
		for (int i = 1; i <= index; ++i)
		{
			if(student[i] != student[i - 1] + 1){
				st1 = 0;
				break;
			}
		}
		for (int i = index + 2; i < n; ++i)
		{
			if(student[i] != student[i - 1] + 1){
				st1 = 0;
				break;
			}
		}

		//check counterclockwise
		int st2 = 1;
		for (int i = 1; i < index; ++i)
		{
			if(student[i] != student[i - 1] - 1){
				st2 = 0;
				break;
			}
		}
		for (int i = index + 1; i < n; ++i)
		{
			if(student[i] != student[i - 1] - 1){
				st2 = 0;
				break;
			}
		}
		cout << (st1 || st2 ? "YES" : "NO") << endl;
	}
	return 0;
}