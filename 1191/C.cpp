#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>

int main(){
	long long int n, m, k;
	cin >> n >> m >> k;
	vector<long long int> data(m);
	for (int i = 0; i < m; ++i){
		cin >> data[i];
		data[i]--;
	}
	sort(data.begin(), data.end());
	long long int page = data[0] / k;
	long long int removes = 0;
	long long int d = 0;
	long long int count = 1;
	for (int i = 0; i < m; ++i){
		if((data[i] - d) / k == page){
			removes++;
			continue;
		}else{
			d = removes;
			page = (data[i] - d) / k;
			i--;
			count ++;
		}
	}
	cout << count << endl;
	return 0;
}