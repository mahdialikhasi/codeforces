#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
int main(){
	string s;
	cin >> s;
	vector<long long int> count(s.size());
	long long int k = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if(s[i] == 'v' && s[i - 1] == 'v'){
			count[i]++;
			k++;
		}
		if(s[i] == 'o')
			count[i] = k;
	}
	long long int c = 0;
	long long int ansi = 0;
	for (long long int i = s.size() - 1; i >= 0; --i){
		if(s[i] == 'v')
			c += count[i];
		else if(s[i] == 'o'){
			ansi += c * count[i];
		}
	}
	cout << ansi << endl;
	return 0;
}