#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <deque>
#include <map>
int main(){
	int n, k;
	cin >> n >> k;
	map<int, int> a; 
	deque<long long int> q;
	for (int i = 0; i < n; ++i){
		long long int id;
		cin >> id;
		if(a.find(id) == a.end() || a[id] == 0){
			if(q.size() >= k){
				long long int x = q.front();
				a[x]--;
				q.pop_front();
			}
			q.push_back(id);
			a[id]++;
		}
	}
	cout << q.size() << endl;
	int count = q.size();
	for (int i = 0; i < count; ++i){
		cout << q.back() << " ";
		q.pop_back();
	}
	cout << endl;
	return 0;
}