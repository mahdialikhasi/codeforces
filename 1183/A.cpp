#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int a;
	cin >> a;
	while(1){
		int t = a;
		int sum = 0;
		while(t != 0){
			sum += t % 10;
			t /= 10;
		}	
		if(sum % 4 == 0){
			cout << a << endl;
			break;
		}
		a++;
	}
	

	return 0;
}