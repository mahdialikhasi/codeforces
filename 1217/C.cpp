/** Simplicity is the final achievement **/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define what_is(x) cerr <<#x<<" is "<<x<<endl;
#define wis(x,y) cerr <<#x<<" is "<<x<<" and "<<#y<<" is "<<y<<endl;
 
const long long MD=1e9 + 7;
long long INF=1e17;
const int N=2e6+73;
 
long long n,m,t,k,P;
long long arr[N];
long long x, y;
string s;
 
typedef pair<int, int> PII;
pair<int, int> inp[N];
 
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    /** ONLY FOOLS RUSH IN **/
    cin >> t;
 
    while (t--) {
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                for (int a = i, b = i, q = 0; a >= 0 && b < s.size(); b++) {
                    q = q * 2 + (s[b] == '1' ? 1 : 0);
                    bool is = 1;
                    while (a > 0 && q > b-a+1) {
                        if (s[a-1] == '0') a--;
                        else {is = 0; break;}
                    }
                    if (is && q == b-a+1){
                    	ans++;
                    	cout << "s" << a << " " << b << " " << i << endl;	
                    } 
                    else break;
                }
            }
        }
        cout << ans << "\n";
    }
 
    return 0;
}