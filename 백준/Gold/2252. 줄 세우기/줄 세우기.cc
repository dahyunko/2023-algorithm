/*2252*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<tuple>

using namespace std;


int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>>graph(N + 1);
	vector<int>dep(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		dep[b]++;
	}

	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (dep[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (dep[v] == 0) cout << v << ' ';
		
		for (int i = 0; i < graph[v].size(); i++) {
			int t = graph[v][i];
			dep[t]--;

			if (dep[t] == 0) q.push(t);
		}
	}
}