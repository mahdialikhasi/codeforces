#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
long long int nu = 998244353;

void check(long long int &ansi){
	while(ansi < 0)
		ansi += nu;
	if(ansi > nu)
		ansi %= nu;
}

long long int fac(int a){
	long long int ansi = 1;
	for (int i = 1; i < a + 1; ++i)
	{
		long long int co = i;
		check(co);
		ansi *= co;
		check(ansi);
	}
	return ansi;
}

long long int cal(vector<int> rep){
	long long int ansi = 1;
	for (int i = 0; i < rep.size(); ++i){
		ansi *= fac(rep[i]);
		check(ansi);
	}
	return ansi;
}

int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;
	
	long long int ma = fac(n);
	long long int ansi = 0;
	{
		vector<int> rep;
		sort(a.begin(), a.end());
		int count = 1;
		for (int i = 1; i < n; ++i){
			if(a[i].first == a[i - 1].first)
				count++;
			else{
				rep.push_back(count);
				count = 0;
			}
		}
		rep.push_back(count);
		ansi = cal(rep);
	}

	int st = 0;
	for (int i = 1; i < n; ++i){
		if(a[i].second < a[i - 1].second){
			st = 1;
			break;
		}
	}

	if(!st){
		vector<int> rep;
		int count = 1;
		for (int i = 1; i < n; ++i){
			if(a[i].first == a[i - 1].first && a[i].second == a[i - 1].second)
				count++;
			else{
				rep.push_back(count);
				count = 0;
			}
		}
		rep.push_back(count);
		ansi -= cal(rep);
		check(ansi);
	}
	
	{
		vector<int> rep;

		for (int i = 0; i < n; ++i){
			swap(a[i].first, a[i].second);
		}		
		sort(a.begin(), a.end());
		int count = 1;
		for (int i = 1; i < n; ++i){
			if(a[i].first == a[i - 1].first)
				count++;
			else{
				rep.push_back(count);
				count = 0;
			}
		}
		rep.push_back(count);
		ansi += cal(rep);	
	}
	
	check(ansi);
	ma -= ansi;
	
	check(ma);
	cout << ma << endl;
	
	return 0;
}