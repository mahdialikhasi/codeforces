#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int n;
	cin >> n;
	string clown;
	string acrobat;
	cin >> clown;
	cin >> acrobat;
	int justClown = 0;
	int justAcrobat = 0;
	int nothing = 0;
	int all = 0;
	for (int i = 0; i < n; ++i)
	{
		if(clown[i] == '1' && acrobat[i] == '0'){
			justClown++;
		}else if(clown[i] == '0' && acrobat[i] == '1'){
			justAcrobat++;
		}else if(clown[i] == '0' && acrobat[i] == '0'){
			nothing++;
		}else{
			all++;
		}
	}
	int st = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	for (int i = 0; i < justClown + 1; ++i){
		for (int j = 0; j < justAcrobat + 1; ++j)
		{
			// group one ::
			a = i;
			b = j;
			d = (justAcrobat + all - a - b) / 2;
			c = n / 2 - a - b - d;

			// cout << a << " " << b << " " << c << " " << d << endl;
			if(a >= 0 && a <= justClown && b >= 0 && b <= justAcrobat && c >= 0 && c <= nothing && d >= 0 && d <= all && a + b + c + d == n / 2 && a + b + 2 * d == justAcrobat + all){
				st = 1;
				break;
			}
		}
		if(st == 1)
			break;
	}

	if(st == 0){
		cout << -1 << endl;
		return 0;
	}

	
	for (int j = 0; j < n && c > 0; ++j){
		if(clown[j] == '0' && acrobat[j] == '0'){
			cout << j + 1 << " ";
			c--;
		}
	}
	
	for (int j = 0; j < n && b > 0; ++j)
	{
		if(clown[j] == '0' && acrobat[j] == '1'){
			cout << j + 1 << " ";
			b--;
		}
	}	

	
	for (int j = 0; j < n && a > 0; ++j)
	{
		if(clown[j] == '1' && acrobat[j] == '0'){
			cout << j + 1 << " ";
			a--;
		}
	}
	for (int i = 0; i < n && d > 0; ++i)
	{
		if(clown[i] == '1' && acrobat[i] == '1'){
			cout << i + 1 << " ";
			d--;
		}
	}
	cout << endl;
	return 0;
}