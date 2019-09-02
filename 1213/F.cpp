#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> p1(n);
	vector<int> p2(n);
	for (int i = 0; i < n; ++i)
		cin >> p1[i];
	
	for (int i = 0; i < n; ++i)
		cin >> p2[i];
	
	set<int> a;
	set<int> b;
	int count = 0;
	int start = 0;
	vector<int> real(n);
	for (int i = 0; i < n; ++i){
		if(b.find(p1[i]) != b.end())
			b.erase(p1[i]);
		else
			a.insert(p1[i]);
		
		if(a.find(p2[i]) != a.end())
			a.erase(p2[i]);
		else
			b.insert(p2[i]);

		if(a.empty() && b.empty()){
			for (int j = start; j <= i; ++j){
				real[p1[j] - 1] = count;
			}
			start = i + 1;
			count++;
		}
	}

	if(count < k)
		cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i)
		{
			if(real[i] < k - 1)
				printf("%c", real[i] + 'a');
			else
				printf("%c", 'z');
		}
		cout << endl;
	}
	return 0;
}