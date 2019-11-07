#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector <int> input(k);

	stack <int> descending;

	int point = 1;

	int num;
	int st = 0;
	for (int i = 0; i < k; ++i){
		cin >> num;
		input[i] = num;
		if(descending.empty())
			descending.push(num);
		else if(!descending.empty() && descending.top() > num)
			descending.push(num);
		else
			return cout << -1 << endl, 0;
		while(!descending.empty() && descending.top() == point){
			point++;
			descending.pop();
		}
	}
	for (int i = 0; i < input.size(); ++i){
		cout << input[i] << " ";
	}
	while(!descending.empty()){
		while(!descending.empty() && descending.top() != point){
			descending.push(descending.top() - 1);
			cout << descending.top() << " ";
		}
		while(!descending.empty() && descending.top() == point){
			point++;
			descending.pop();
		}
	}
	for (int i = n; i >= point; --i){
		cout << i << " ";
	}
	cout << endl;


	return 0;
}