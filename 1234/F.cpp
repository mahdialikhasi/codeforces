#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	string s;
	cin >> s;
	vector<vector<int> > table(s.size(), vector<int>(20, -1));
	table[s.size() - 1][s[s.size() - 1] - 'a'] = s.size() - 1;
	for (int i = s.size() - 2 ; i >= 0; --i){
		table[i] = table[i + 1];
		table[i][s[i] - 'a'] = i;
	}
	vector<vector<int> > count(s.size(), vector<int>(20));
	for (int i = 0; i < s.size(); ++i){
		int d = i;
		for (; ; ++d){
			if(count[i][s[d] - 'a'] == 0)
				count[i][s[d] - 'a']++;
			else
				break;
		}
		int maxi = 0;
		for (int j = 0; j < 20; ++j){
			vector<int> temp = count[i];
			for (int k = table[i][j]; k >= i; --k){
				/* code */
			}
		}
		
	}
	return 0;
}