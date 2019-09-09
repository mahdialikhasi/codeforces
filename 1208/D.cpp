#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>

bool comp(pair<long long int, int>a, pair<long long int , int> b){
	if(a.first < b.first)
		return true;
	else if(a.first == b.first)
		if(a.second > b.second)
			return true;
	return false;
}
int main(){
	int n;
	cin >> n;
	vector<pair<long long int, int> > a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	vector<int> nu(n);
	
	sort(a.begin(), a.end(), comp);
	
	int count = 1;
	for (int i = 0; i < n; ++i){
		nu[a[i].second] = count++;		
	}

	for (int i = 0; i < n; ++i)
	{
		cout << nu[i] << " ";
	}
	cout << endl;
	return 0;
}