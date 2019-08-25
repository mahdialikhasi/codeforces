#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> co;
		co.push_back(1);
		int nu = 1;
		int curr = 1;
		int lastRow = 1;
		while(nu < 1000000){
			nu += 2 * (lastRow + (curr)) + curr + 1;
			lastRow = lastRow + curr + curr + 1;
			curr++;
			co.push_back(nu);
		}
		// for (int i = 0; i < co.size(); ++i)
		// {
		// 	cout << co[i] << endl;
		// }
		vector<int> a(co.size());
		int last = co.size() - 1;
		int current = 0;
		while(n > 0){
			n -= co[current];
			if(n < 0){
				n += co[current];
				last = current;
			}else{
				a[current]++;
			}
			current++;
			if(current > last)
				current = 0;
		}
		// cout << "----" << endl;
		// for (int i = 0; i < a.size(); ++i)
		// {
		// 	cout << a[i] << endl;
		// }
		// cout << co.size() << endl;
		for (int i = a.size() - 1; i >=0 ; --i)
		{
			if(a[i]){
				for (int j = 0; j < a[i]; ++j)
				{
					cout << 1;
				}
				cout << 337;
			}
		}
		cout << endl;
	}
	return 0;
}