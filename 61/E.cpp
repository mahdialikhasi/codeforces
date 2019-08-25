#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <vector>

typedef struct node{
	pair<int, int> data;
	node * left = NULL;
	node * right = NULL;
	int size;
} node;
node nd;

int in(int data, int index, node *nd, vector<int> &power){
	if(data >= nd->data.first){
		if(nd->right == NULL){
			node * tmp = new node;
			tmp->data = make_pair(data, index); 
			tmp->size = nd->size + 1;
			nd->right = tmp;
			power[index] = nd->size;
			
		}else{
			nd->right->size = max(nd->size + 1, nd->right->size);
			in(data, index, nd->right, power);

		}
	}else{
		if(nd->left == NULL){
			node * tmp = new node;
			tmp->data = make_pair(data, index); 
			tmp->size = nd->size;
			nd->left = tmp;
			nd->size += 1;
			power[index] = tmp->size - 1;
			// power[nd->data.second] = nd->size - 1;
			
		}else{
			in(data, index, nd->left, power);
			nd->size += 1;

			// power[nd->data.second] = nd->size - 1;
		}
	}

	return nd->size;
}


int main(){
	int n;
	cin >> n;
	vector<int> power(n);
	nd.data = make_pair(-1, -1);
	nd.size = 0;

	vector<int> data(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> data[i];
	}
	for (int i = 0; i < n; ++i){
		int tmp = data[n - 1 - i];
		// cin >> tmp;
		in(tmp, i, &nd, power);
	}
	
	

	long long int ansi = 0;
	for (int i = 0; i < n; ++i)
	{
		//power[i] = n - 1 - power[i];
		cout << power[n - 1 - i] << endl;	
	}
	for (int i = 0; i < n; ++i)
	{
		ansi += power[i] * (power[i] - 1) / 2;
	}
	cout << ansi << endl;
	return 0;
}