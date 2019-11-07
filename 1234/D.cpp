#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
int find(set<int> table, int l, int r){
	int dis = table.size() / 2;
	for (auto i = table.begin(); i != table.end();){
		if(*i >= l && *i <= r)
			return 1;
		

	}
}
int calc(vector<set<int> > &table, int l, int r){
	int count = 0;
	for (int i = 0; i < 26; ++i){
		if(table[i].size() > 0 && find(table[i] , l, r))
			count++;
	}
	return count;
}
int main(){
	string s;
	cin >> s;
	string backup = s;
	vector<set<int> > table(26);
	for (int i = 0; i < s.size(); ++i){
		table[s[i] - 'a'].insert(i);
	}
	int q;
	cin >> q;
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int pos;
			char c;
			cin >> pos >> c;
			pos--;
			table[s[pos] - 'a'].erase(pos);
			table[c - 'a'].insert(pos);
		}else{
			int l, r;
			cin >> l >> r;
			int ansi = calc(table, l - 1, r - 1);
			
			
			cout << ansi << endl;
		}
	}
	return 0;
}