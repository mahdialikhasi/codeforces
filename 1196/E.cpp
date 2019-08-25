#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int t;
	cin >> t;
	while(t--){
		int b, w;
		cin >> b >> w;
		int starti;
		int second;
		if(b <= w){
			starti = 3;
			second = 5;

		}else{
			starti = 2;
			second = 4;
			int t = b;
			b = w;
			w = t;
		}

		int maxi = b + b * 2 + 1;
		if(w > maxi)
			cout << "NO" << endl;
		else{
			if(w){
				cout << "YES" << endl;
				cout << starti << " " << 1 << endl;
				w --;
			}
			for (int i = 0; i < b; ++i)
			{
				int a[3][2] = {{-1, 0},{1, 0},{0, 1}};
				if(i % 10000 > 0){
					starti = second;
					a[0][0] = 0;
					a[0][1] = -1;
				}
				cout << starti << " " << 2 + i * 2 << endl;
				for (int j = 0; j < 3; ++j)
				{
					if(!w)
						break;
					w--;
					cout << starti + a[j][0] << " " << 2 + i * 2 + a[j][1] << endl;
				}
			}
		}	
		

	}
	return 0;
}