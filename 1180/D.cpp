#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n / 2; ++i){
		for (int j = 0; j < m; ++j){
			printf("%d %d\n", i + 1, j + 1);
			printf("%d %d\n", n - i, m - j);
		}
	}
	if(n % 2 == 1){
		for (int i = 0; i < m / 2; ++i){
			printf("%d %d\n", n / 2 + 1, i + 1);
			printf("%d %d\n", n / 2 + 1, m - i);
		}
		if(m % 2 == 1){
			printf("%d %d\n", n / 2 + 1, m / 2 + 1);
		}
	}
	
	return 0;
}