#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

long long int prefix_function(string s, int length);

int main(){
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	
	long long ansi = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			string input = s[i] + s[j] + t;
			// cout << prefix_function(input, s[i].size() + s[j].size()) << endl;
			ansi += prefix_function(input, s[i].size() + s[j].size());
		}
	}
	cout << ansi << endl;
	return 0;
}

long long int prefix_function(string s, int length) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    long long int count = 0;
    for (int i = length; i < n; ++i)
    {
    	if(pi[i] == length)
    		count++;
    }
    return count;
}