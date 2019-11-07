#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector <int> ks(3);
	cin >> ks[0] >> ks[1] >> ks[2];

	sort(ks.begin(), ks.end());
	vector <bool> arr(100, false);

	for(int i = 0; i < 100; i += ks[0])
		arr[i] = 1;

	int idx = 0;
	while(arr[idx] == true)
		++idx;

	for(; idx < 100; idx += ks[1])
		arr[idx] = true;

	idx = 0;
	while(arr[idx] == true)
		++idx;

	for(; idx < 100; idx += ks[2])
		arr[idx] = true;

	for(int i = 0; i < 100; ++i)
		if(arr[i] == false){
			cout << "NO" << endl;
			return 0;
		}
		
	cout << "YES" << endl;
}