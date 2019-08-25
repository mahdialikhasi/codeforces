#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>

int kmp(const string &T, const string &P) {
	vector<int> b(T.size());
	if (P.empty()) return 0;

	vector<int> pi(P.size(), 0);
	for (int i = 1, k = 0; i < P.size(); ++i) {
		while (k && P[k] != P[i]) k = pi[k - 1];
		if (P[k] == P[i]) ++k;
		pi[i] = k;
	}

	for (int i = 0, k = 0; i < T.size(); ++i) {
		while (k && P[k] != T[i])
			k = pi[k - 1];
		if (P[k] == T[i])
			++k;
		b[i] = k;
		// if (k == P.size()) return i - k + 1;
	}
	return b[b.size() - 1];
	// return -1;
}

int main(){
	int n;
	cin >> n;
	string m;
	cin >> m;
	for (int i = 0; i < n - 1; ++i)
	{
		string str;
		cin >> str;
		int res;
		if(str.size() < m.size()){
			string tmp(m.begin() + m.size() - str.size(), m.end());
			res = kmp(tmp, str);
		}else
			res = kmp(m, str);
		string tmp(str.begin() + res, str.end());
		m += tmp;
	}
	cout << m << endl;
	
	return 0;
}