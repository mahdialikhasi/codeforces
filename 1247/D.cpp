#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <map>
#include <set>
int isPrime(int n){
	int count = 0;
	for (int i = 2; i <= sqrt(n); ++i){
		if(n % i == 0)
			count++;
	}
	return count;
}
set<int> u_s(set<int> a, set<int> b){
	set<int> t;
	for (auto i = b.begin(); i != b.end(); ++i){
		if(a.find(*i) != a.end())
			t.insert(*i);
	}
	return t;
}
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<vector<set<int> > > table(a[n - 1] + 1, vector<set<int> >(k));
	long long int ansi = 0;
	long long int c = 0;
	vector<map<int, int> > cov;
	for (int i = 0; i < n; ++i){
		map<int, int> co;
		int t = a[i];

		if(t == 1){
			
		}else{
			for (int j = 2; j <= sqrt(a[i]); ++j){

				if(t % j == 0){
					while(t % j == 0){
						co[j]++;
						t /= j;
					}
					co[j] = co[j] % k;
					if(co[j] == 0)
						co.erase(j);
				}
			}

			if(t != 1)
				co[t]++;
		}
		int count = 0;
		for (auto j = co.begin(); j != co.end(); ++j){
			if(j->second % k != 0){
				count++;
				table[j->first][j->second % k].insert(i);
			}
		}
		if(count == 0)
			c++;
		cov.push_back(co);
	}

	for (int i = 0; i < cov.size(); ++i){
		if(cov[i].size() == 0)
			continue;
		auto j = cov[i].begin();
		set<int> x = table[j->first][k - j->second];
		for (; j != cov[i].end(); ++j){
			
			x = u_s(x, table[j->first][k - j->second]);
			

			if(x.size() == 0)
				break;
		}
		if(x.size() == 0)
			continue;
		else{	
			x.erase(i);
			ansi += x.size();
		}
	}
	int yek = 0;
	for (int i = 0; i < n; ++i){
		if(a[i] == 1)
			yek++;
		else
			break;
	}

	cout << ansi / 2 + yek * (c - yek) + (yek * (yek - 1)) / 2 << endl;
	return 0;
}