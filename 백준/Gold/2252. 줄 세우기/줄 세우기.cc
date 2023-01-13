/*053(2252)-줄 세우기*/
//위상정렬
#include <queue>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& D) {
	queue<int> que;

	for (int i = 1; i < D.size(); i++) {
		if (D[i] == 0) que.push(i);
	}

	while (!que.empty()) {
		int x = que.front();
		que.pop();
		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int t = graph[x][i];
			D[t]--;
			if (D[t] == 0) que.push(t);
		}
	}
}

int main() {
	int N, M, x;
	
	cin >> N >> M;
	vector<vector<int>> graph;
	vector<int> D(N + 1, 0);
	//vector<char> visited(N+1, 'F');
	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (i == 0) x = a;
		graph[a].push_back(b);
		D[b]++;
	}

	bfs(graph, D);
}