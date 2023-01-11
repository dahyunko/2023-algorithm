/*046(18352)-특정 거리의 도시 찾기*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &graph, int x, vector<char> &visited, vector<int>& dis) {
	queue<int> que;
	int now = dis[x];
	visited[x] = 'T';
	que.push(x);
	
	while (!que.empty()) {
		x = que.front();
		now = dis[x];
		que.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int t = graph[x][i];
			if (visited[t] == 'F') {
				visited[t] = 'T';
				dis[t] = now + 1;
				que.push(t);
			}
		}
	}
}

int main() {
	int N, M, K, X;//도시 N, 도로 M, 거리 K, 출발 X

	cin >> N >> M >> K >> X;
	vector<vector<int>> graph;
	graph.resize(N + 1);
	vector<char> visited(N + 1, 'F');
	vector<int> dis(N + 1, 0);//거리
	int flag = 0;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	bfs(graph, X, visited,dis);

	for (int i = 1; i <= N; i++) {
		if (dis[i] == K) {
			cout << i << '\n';
			flag = 1;
		}
	}

	if (flag == 0) {
		cout << -1 << '\n';
	}
}