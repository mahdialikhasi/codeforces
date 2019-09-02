#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int q;
	cin >> q;
	while(q--){
		long long int n, m;
		cin >> n >> m;
		vector<int> cycle;
		cycle.push_back(m % 10);
		while((cycle[cycle.size() - 1] + m) % 10 != cycle[0]){
			cycle.push_back((cycle[cycle.size() - 1] + m) % 10);
		}
		// for (int i = 0; i < cycle.size(); ++i)
		// {
		// 	cout << cycle[i] << "ss"<< endl;
		// }
		long long int total = n / m;
		long long int count = total / cycle.size();
		long long int rem = total % cycle.size();
		long long int ansi = 0;
		for (int i = 0; i < cycle.size(); ++i){
			ansi += cycle[i] * count;
		}
		for (int i = 0; i < rem; ++i)
		{
			ansi += cycle[i];
		}
		cout << ansi << endl;

	}
	return 0;
}