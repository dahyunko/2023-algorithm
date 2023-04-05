/*바이러스*/
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N, M, cnt = 0;

	cin >> N >> M;
	vector<vector<int>> graph(N + 1);
	vector<bool>visited(N + 1, false);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int>q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int v = q.front();
		cnt++;
		q.pop();

		for (int i = 0; i < graph[v].size(); i++) {
			int t = graph[v][i];

			if (!visited[t]) {
				visited[t] = true;
				q.push(t);
			}
		}
	}

	cout << cnt - 1;
}