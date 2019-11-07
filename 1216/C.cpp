#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	vector<long long int> s1(4);
	cin >> s1[0] >> s1[1] >> s1[2] >> s1[3];
	vector<long long int> s2(4);
	cin >> s2[0] >> s2[1] >> s2[2] >> s2[3];
	vector<long long int> s3(4);
	cin >> s3[0] >> s3[1] >> s3[2] >> s3[3];
	if(s2[1] > s3[1]){
		vector<long long int> t(s2);
		s2 = s3;
		s3 = t;
	}
	if((s1[0] >= s2[0] && s1[2] <= s2[2] && s1[1] >= s2[1] && s1[3] <= s2[3]) || (s1[0] >= s3[0] && s1[2] <= s3[2] && s1[1] >= s3[1] && s1[3] <= s3[3])){
		cout << "NO" << endl;
		return 0;
	}
	if((s1[0] >= s2[0] && s1[1] >= s2[1] && s1[2] <= s2[2]) && (s1[0] >= s3[0] && s1[3] <= s3[3] && s1[2] <= s3[2])){
		if(s2[3] >= s3[1]){
			cout << "NO" << endl;
			return 0;
		}
	}
	if(s2[0] > s3[0]){
		vector<long long int> t(s2);
		s2 = s3;
		s3 = t;
	}
	if((s1[0] >= s2[0] && s1[1] >= s2[1] && s1[3] <= s2[3]) && (s1[1] >= s3[1] && s1[3] <= s3[3] && s1[2] <= s3[2])){
		if(s2[2] >= s3[0]){
			cout << "NO" << endl;
			return 0;		
		}
	}
	cout << "YES" << endl;
	return 0;
}