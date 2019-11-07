#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;


int dijkstra(vector < vector <pair <int, int> > > & Graph, int source)
{
	int n = Graph.size();
	vector <int> min_dis(n, -1);
	set <pair <int, int> > Heap;
	min_dis[source] = 0;
	Heap.insert(make_pair(0, source));

	while(!Heap.empty()){
		int top = Heap.begin()->second;
		Heap.erase(Heap.begin());

		for(auto a : Graph[top])
			if(min_dis[top] + a.second > min_dis[a.first]){
				Heap.erase(make_pair(min_dis[a.first], a.first));
				min_dis[a.first] = min_dis[top] + a.second;
				Heap.insert(make_pair(min_dis[a.first], a.first));
			}
	}

	int result = 0;
	for(auto a : min_dis)
		result = max(result, a);
	return result;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector < vector <pair <int, int> > > Graph(n);
	vector <int> is_mountain(n, 0);

	for(int i = 0; i < m; ++i){
		int s, t, c;
		cin >> s >> t >> c;

		--s, --t;
		Graph[s].push_back(make_pair(t, c));
		is_mountain[t]++;
	}

	int max_pleasure = 0;
	for(int i = 0; i < n; ++i)
		if(is_mountain[i] == 0)
			max_pleasure = max(max_pleasure, dijkstra(Graph, i));

	cout << max_pleasure << endl;
	return 0;
}