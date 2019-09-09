#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n;
	cin >> n;
	vector <vector<int> > nums;
	vector <vector<int> > numsodd;
	nums.push_back(vector<int>(n));
	for(int i = 0; i < n; ++i){
		cin >> nums[0][i];
	}
	vector<vector<int> > candy(n, vector<int>(n));
	int level = 1;
	long long int q = 1;
	while(nums[level - 1].size() >= 2){
		vector<int> tmp;
		nums.push_back(tmp);
		int size = nums[level - 1].size();
		for (int i = 0; i < size && i + q < size; i++){
			int count = nums[level - 1][i] + nums[level - 1][i + q];
			nums[level].push_back(count % 10);
			if(count >= 10){
				candy[nums[level].size() - 1][(2 << (level - 1)) + (nums[level].size() - 1) - 1] = 1;
			}
		}
		q *= 2;
		level++;
	}
	
	vector<vector<int> > c(candy);
	for (int i = 4; i <= n; i *= 2){
		for (int j = 0; j < n && j + i - 1 < n; ++j){
			c[j][j + i - 1] = c[j][(j + i - 1)/2] + c[(j + i - 1)/2 + 1][j + i - 1] + c[j][j + i - 1];
		}
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << c[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "---" << endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << candy[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	

	int t;
	cin >> t;
	for(int Q = 0; Q < t; ++Q){
		int l, r, candy_count = 0;
		cin >> l >> r;
		cout << c[l - 1][r - 1] << endl;
	}
	return 0;
}
