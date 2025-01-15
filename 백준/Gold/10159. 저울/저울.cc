/* 10159 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int N, M;

int bfs(vector<vector<int>> graph, int now) {
	vector<bool> visited(N, false);
	queue<int> q;
	q.push(now);
	int cnt = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (visited[v]) continue;
		visited[v] = true;
		cnt++;

		for (int i = 0; i < graph[v].size(); i++) {
			int w = graph[v][i];

			if (visited[w]) continue;
			q.push(w);
		}
	}

	return cnt - 1;
}

int main() {
	cin >> N;
	cin >> M;

	vector<vector<int>> graphUp(N);
	vector<vector<int>> graphDown(N);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		a--;
		b--;
		graphUp[b].push_back(a);
		graphDown[a].push_back(b);
	}

	for (int i = 0; i < N; i++) {
		int result = 0;
		result += bfs(graphUp, i);
		result += bfs(graphDown, i);

		cout << N - 1 - result << '\n';
	}
}