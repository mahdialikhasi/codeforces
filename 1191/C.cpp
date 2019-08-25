#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> data(m);
	for (int i = 0; i < m; ++i){
		cin >> data[i];
		data[i]--;
	}
	int page = data[0] / k;
	int removes = 0;
	int d = 0;
	int count = 1;
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