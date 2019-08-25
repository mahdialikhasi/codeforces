#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>
#include <vector>
int main(){
	int n;
	cin >> n;
	vector<pair<string, long long int> > list(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> list[i].first >> list[i].second;
	}

	map<string, long long int> names;
	for (int i = 0; i < n; ++i){
		string name = list[i].first;
		long long int score = list[i].second;
		
		names[name] += score;
	}
	long long int ansi = -1000000;

	for (auto i = names.begin(); i != names.end(); ++i){
		ansi = max(ansi, i->second);
	}

	map<string, long long int> names2;
	for (int i = 0; i < n; ++i){

		string name = list[i].first;
		long long int score = list[i].second;
		
		names2[name] += score;
		if(names2[name] >= ansi){
			cout << name << endl;
			break;
		}
		
	}
	return 0;
}