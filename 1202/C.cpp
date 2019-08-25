#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string>
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		pair<int, int> ud = make_pair(0, 0);
		pair<int, int> cud = make_pair(1, 1);
		pair<int, int> rl = make_pair(0, 0);
		pair<int, int> crl = make_pair(1, 1);
		pair<int, int> pos = make_pair(0, 0);
		for (int i = 0; i < s.size(); ++i){
			if(s[i] == 'W'){
				pos.first++;
				if(pos.first > ud.first){
					ud.first = pos.first;
					cud.first = 1;
				}else if(pos.first == ud.first){
					cud.first += 1;
				}

			}else if(s[i] == 'S'){
				pos.first--;
				if(pos.first < ud.second){
					ud.second = pos.first;
					cud.second = 1;
				}else if(pos.first == ud.second){
					cud.second += 1;
				}
			}else if(s[i] == 'D'){
				pos.second++;
				if(pos.second > rl.first){
					rl.first = pos.second;
					crl.first = 1;
				}else if(pos.second == rl.first){
					crl.first += 1;
				}
			}else if(s[i] == 'A'){
				pos.second--;
				if(pos.second < rl.second){
					rl.second = pos.second;
					crl.second = 1;
				}else if(pos.second == rl.second){
					crl.second += 1;
				}
			}
		}
		// cout << u << " " << d << " " << r << " " << l << endl;
		long long int current = (ud.first - ud.second + 1) * (rl.first - rl.second + 1);
		int first = 1;
		int second = 1;
		if((ud.first == 1 && ud.second == 0) || (ud.first == 0 && ud.second == -1)){
			first = 0;
		}
		if((rl.first == 1 && rl.second == 0) || (rl.first == 0 && rl.second == -1)){
			second = 0;
		}
		if(ud.first == 0 && ud.second == 0){
			first = 0;
		}
		if(rl.first == 0 && rl.second == 0){
			second = 0;
		}
		if(cud.first + cud.second > 2){
			first = 0;
		}
		if(crl.first + crl.second > 2){
			second = 0;
		}
		if(current > (ud.first - ud.second + 1 - first) * (rl.first - rl.second + 1))
			current = (ud.first - ud.second + 1 - first) * (rl.first - rl.second + 1);
		if(current > (ud.first - ud.second + 1) * (rl.first - rl.second + 1 - second))
			current = (ud.first - ud.second + 1) * (rl.first - rl.second + 1 - second);
		cout << current << endl;
		
	}
	return 0;
}