#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
long long int inf = 100000000000000000;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, a,b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		vector<pair<long long int, long long int> > pillar(n + 1, make_pair(inf,inf));
		pillar[0].first = b;
		for (int i = 1; i < n; ++i){
			if(s[i] == '0' && s[i - 1] == '0'){
				pillar[i].first = min(pillar[i - 1].first + a + b, pillar[i - 1].second + 2 * a + b);
				pillar[i].second = min(pillar[i - 1].first + 2 * a + 2 * b, pillar[i - 1].second + a + 2 * b);
			}else{
				pillar[i].second = min(pillar[i - 1].first + 2 * a + 2 * b, pillar[i - 1].second + a + 2 * b);
			}
		}
		pillar[n].first = min(pillar[n - 1].first + a + b, pillar[n -1].second + 2 * a + b);
		cout << pillar[n].first << endl;
	}
	return 0;
}