#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int main(){
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	char first, second, last;
	last = a[0];
	cout << "YES" << endl;
	if(b[0] == b[1] || a[0] == a[1]){
		if(b[0] == b[1] && a[0] != a[1]){
			first = a[1];
			second = a[0];
			if('a' != a[0] && 'a' != a[1])
				last = 'a';
			else if('b' != a[0] && 'b' != a[1])
				last = 'b';
			else
				last = 'c';
		}else if(a[0] == a[1] && b[0] != b[1]){
			first = b[1];
			second = b[0];
			if('a' != b[0] && 'a' != b[1])
				last = 'a';
			else if('b' != b[0] && 'b' != b[1])
				last = 'b';
			else
				last = 'c';
		}else{
			first = 'a';
			second = 'b';
			last = 'c';
		}
		for (int i = 0; i < n; ++i){
			printf("%c%c%c", first, second, last);
		}
		cout << endl;

	}else{
		if(b[0] == a[0]){
			if(last == 'a'){
				first = 'c';
				second = 'b';
			}else if(last == 'b'){
				first = 'c';
				second = 'a';
			}else{
				first = 'a';
				second = 'b';
			}
		}else{
			if(b[1] == last){
				first = b[0];
				if('a' != last && 'a' != first){
					second = 'a';
				}else if('b' != last && 'b' != first){
					second = 'b';
				}else{
					second = 'c';
				}
			}else{
				second = b[0];
				if('a' != last && 'a' != second){
					first = 'a';
				}else if('b' != last && 'b' != second){
					first = 'b';
				}else{
					first = 'c';
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%c", first);
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%c", second);
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%c", last);
		}
		cout << endl;
	}
	return 0;
}