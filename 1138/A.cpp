#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<int> t(n);
	int tmp;
	for (int i = 0; i < n; ++i){
		cin >> t[i]; 
	}
	vector<int> no;
	no.push_back(1);
	for (int i = 1; i < n; ++i)
	{
		if(t[i] == t[i - 1])
			no[no.size() - 1]++;
		else
			no.push_back(1);
	}
	int ansi = 0;
	for (int i = 1; i < no.size(); ++i)
	{
		ansi = max(ansi, min(no[i], no[i - 1]));
	}
	cout << 2 * ansi << endl;
	return 0;
}