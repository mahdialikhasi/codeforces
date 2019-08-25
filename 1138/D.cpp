#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
vector<int> prefix_function(string s) {
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
    return pi;
}

int main(){
	string s, t;
	cin >> s >> t;
	int ones = 0;
	int zeros = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '0')
			zeros++;
		else if(s[i] == '1')
			ones++;
	}
	vector<int> no = prefix_function(t);
	int number = no[no.size() - 1];
	int pointer = 0;
	while(zeros != 0 || ones != 0){
		if(t[pointer] == '0' && zeros){
			cout << 0;
			zeros--;
		}else if(t[pointer] == '1' && ones){
			cout << 1;
			ones--;
		}else if(t[pointer] == '0' && zeros == 0 && ones){
			cout << 1;
			ones--;
		}else if(t[pointer] == '1' && ones == 0 && zeros){
			cout << 0;
			zeros--;
		}
		pointer++;
		if(pointer == t.size())
			pointer = number;
	}
	cout << endl;
	return 0;
}