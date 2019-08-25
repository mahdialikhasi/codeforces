#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> room(10);
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] == 'L'){
			for (int i = 0; i < 10; ++i)
			{
				if(!room[i]){
					room[i] = 1;
					break;
				}
			}
		}else if(s[i] == 'R'){
			for (int i = 9; i >= 0; --i)
			{
				if(!room[i]){
					room[i] = 1;
					break;
				}
			}
		}else{
			room[s[i] - '0'] = 0;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << (room[i] ? 1 : 0);
	}
	cout << endl;
	return 0;
}