#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>
#include <math.h>
int main(){
	long long int n, I;
	cin >> n >> I;
	long long int m = min(double(2 * n), pow(2, I * 8 / n));
	// cout << m << endl;
	vector<int> nu(n);
	vector<pair<int, int> > a;
	for (int i = 0; i < n; ++i){
	 	cin >> nu[i];
	}
	sort(nu.begin(), nu.end());
	a.push_back(make_pair(nu[0], 1));
	for (int i = 1; i < n; ++i){
		if(nu[i] == nu[i - 1])
			a[a.size() - 1].second++;
		else
			a.push_back(make_pair(nu[i], 1));
	}

	// initial
	long long int ansi = 0;
	long long int pr = 0;
	for (int i = 0; i < m && i < a.size(); ++i){
		ansi += a[i].second;
	}
	pr = ansi;

	for (int i = 1; i + m - 1 < a.size(); ++i)
	{
	 	pr = pr + a[i + m - 1].second - a[i - 1].second;
	 	ansi = max(ansi, pr);
	}
	
	cout << n - ansi << endl;
	return 0;
}