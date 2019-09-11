#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <set>
#include <string>
int main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	set<string> a;
	int cost = 0;
	set<string> pr;
	a.insert(s);
	pr.insert(s);
	k--;
	while(k > 0){
		set<string> tmp;
		for (auto i = pr.begin(); i != pr.end(); ++i){
			string x = *i;
			for (int j = 0; j < x.size(); ++j){
				string temp = x;
				temp.erase(j, 1);
				tmp.insert(temp);
			}
		}
		pr = tmp;

		for (auto i = pr.begin(); i != pr.end() && k > 0; ++i){
			if(a.find(*i) == a.end()){
				cost += n - i->size();
				k--;
				a.insert(*i);
			}
		}
		if(pr.size() == 1 && (pr.begin())->size() == 0)
			break;
	}
	// for (auto i = a.begin(); i != a.end(); ++i){
	// 	cout << *i << endl;
	// }
	if(k <= 0)
		cout << cost << endl;
	else
		cout << -1 << endl;
	return 0;
}