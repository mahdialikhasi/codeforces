#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

int main(){
	vector<string> a;
	string tmp;
	cin >> tmp;
	a.push_back(tmp);
	cin >> tmp;
	a.push_back(tmp);
	cin >> tmp;
	a.push_back(tmp);
	sort(a.begin(), a.end());

	
	// search for shuntsu
	if(a[0] == a[1] && a[0] == a[2]){
		cout << 0 << endl;
		return 0;
	}

	// search for koutso
	if(a[0][0] + 1 == a[1][0] && a[1][0] + 1 == a[2][0]){
		if(a[0][1] == a[1][1] && a[0][1] == a[2][1]){
			cout << 0 << endl;
			return 0;
		}
	}

	// search for shuntsu
	if(a[0] == a[1] || a[0] == a[2] || a[1] == a[2]){
		cout << 1 << endl;
		return 0;
	}
	
	// search for koutso
	if(a[0][0] + 1 == a[1][0] && a[0][1] == a[1][1]){
		cout << 1 << endl;
		return 0;
	}
	if(a[0][0] + 2 == a[1][0] && a[0][1] == a[1][1]){
		cout << 1 << endl;
		return 0;
	}



	if(a[0][0] + 1 == a[2][0] && a[0][1] == a[2][1]){
		cout << 1 << endl;
		return 0;
	}
	if(a[0][0] + 2 == a[2][0] && a[0][1] == a[2][1]){
		cout << 1 << endl;
		return 0;
	}


	if(a[1][0] + 1 == a[2][0] && a[1][1] == a[2][1]){
		cout << 1 << endl;
		return 0;
	}
	if(a[1][0] + 2 == a[2][0] && a[1][1] == a[2][1]){
		cout << 1 << endl;
		return 0;
	}

	// else
	cout << 2 << endl;
	return 0;
}