#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string> 
int main(){
	string s;
	cin >> s;
	for (int x = 0; x < 10; ++x)
	{
		for (int y = 0; y < 10; ++y)
		{
			
			vector<vector<int> >graph(10, vector<int>(10));
			for (int i = 0; i < 10; ++i){
				graph[i][(i + x) % 10] = 1;
				// graph[(i + x) % 10][i] = 1;
				graph[i][(i + y) % 10] = 1;
				// graph[(i + y) % 10][i] = 1;
			}
			vector<vector<int> > ASP(vector<vector<int> >(10, vector<int>(10, 10000)));
			
			for (int i = 0; i < 10; ++i)
				for (int j = 0; j < 10; ++j)
					ASP[i][j] = (graph[i][j] == 1 ? 1 : 10000);
			
			
			for (int k = 0; k < 10; ++k)
				for (int i = 0; i < 10; ++i)
					for (int j = 0; j < 10; ++j){
						// if(i == j && ASP[i][j] > ASP[i][k] + ASP[k][j]){
						// 	cout << i << endl;
						// 	cout << k  << " --> " << ASP[i][k] << endl;
						// }
						ASP[i][j] = min(ASP[i][j], ASP[i][k] + ASP[k][j]);
					}						

			// for (int i = 0; i < 10; ++i)
			// {
			// 	for (int j = 0; j < 10; ++j)
			// 	{
			// 		cout << ASP[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			// cout << "---" << endl;

					
			long long int ansi = 0;
			int st = 0;
			for (int i = 0; i < s.size() - 1; ++i)
			{
				ansi += ASP[s[i] - '0'][s[i + 1] - '0'] - 1;
				if(ASP[s[i] - '0'][s[i+1] - '0'] == 10000){
					st = 1;
				}
			}

			cout << (st == 1 ? -1 : ansi) << " ";
		}
		cout << endl;
	}
	
	


	return 0;
}