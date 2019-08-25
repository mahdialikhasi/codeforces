#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		vector<long long int> neg(n);
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			neg[i] = a[i] % 2;
			if(neg[i])
				count++;
		}
		
		if((count - k) % 2 == 1 || count < k)
			cout << "NO" << endl;
		else{
			int c = 0;
			cout << "YES" << endl;
			for (int i = 0; i < n && c < k - 1; ++i){
				if(neg[i] == 1){
					cout << i + 1 << " ";
					c++;
				}
			}
			cout << n << endl;
		}

	}
	return 0;
}