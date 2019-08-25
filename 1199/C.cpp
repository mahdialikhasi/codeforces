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
	map<long long int, long long int> a;
	int distinc = 0;
	for (int i = 0; i < n; ++i){
	 	long long int tmp;
	 	cin >> tmp;
	 	a[tmp]++;
	 	if(a[tmp] == 1)
	 		distinc++;
	}
	long long int m = pow(2, I * 8 / n);
	long long int count = 0;
	
	for (auto i = a.begin(); i != a.end(); ++i){
		long long int tmp = i->second;
		i->second = count;
		count += tmp;
		// cout << i->first << " " << i->second << endl;
	}
	
	long long int ansi = 0;
	auto i = a.begin();
	auto j = i;
	
	for (; j != a.end() && m > 0; ++j){
		m--;
	}

	for (; i != a.end(); ++i){
		// cout << x << endl;
		if(j == a.end()){
			ansi = max(ansi, count - i->second);	
			j--;
		}else{
			ansi = max(ansi, j->second - i->second);
		}
		// cout << i->first << ":" << j->first << ":" <<  j->second - i->second  << endl;
		j++;
	}
	
	// cout << ansi << endl;
	//cout << (--a.end())->second << endl;
	
	cout << count - ansi << endl;
	return 0;
}