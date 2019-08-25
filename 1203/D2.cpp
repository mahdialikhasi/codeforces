#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
int main(){
	string s, t;
	cin >> s >> t;
	vector<pair<int, int> > m(t.size(), make_pair(s.size() + 1, -1));
	for (int j = 0; j < t.size(); ++j){
		for (int i = 0; i < s.size(); ++i){
			if(s[i] == t[j]){
				m[j].first = min(m[j].first, i);
				j++;
			}
		}
	}

	for (int j = t.size() - 1; j >= 0 ; --j){
		for (int i = s.size() - 1; i >= 0; --i){
			if(s[i] == t[j]){
				m[j].second = max(m[j].second, i);
				j--;
			}
		}
	}

	int ansi = 0;
	ansi = max(m[0].second, int(s.size() - 1 - m[m.size() - 1].first));

	for (int i = 1; i < m.size(); ++i)
	{
		ansi = max(ansi, m[i].second - m[i - 1].first - 1);
	}
	cout << ansi << endl;
	return 0;
}
