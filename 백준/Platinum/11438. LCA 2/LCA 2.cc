/*11438*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int>dep;
vector<vector<int>>parent(100001, vector<int>(18));

void bfs(int v) {
	vector<bool>visited(N + 1, false);
	visited[v] = true;
	queue<int>q;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i < graph[v].size(); i++) {
			int t = graph[v][i];
			if (!visited[t]) {
				visited[t] = true;
				dep[t] = dep[v] + 1;
				parent[t][0] = v;
				q.push(t);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	graph.resize(N + 1);
	dep.resize(N + 1, 0);

	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);

	for (int i = 0; i < 18; i++) {
		for (int j = 1; j <= N; j++) {
			int k = parent[j][i];
			if (k != 0) parent[j][i + 1] = parent[k][i];
		}
	}


	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		int aDep = dep[a];
		int bDep = dep[b];

		if (bDep > aDep) {
			swap(a, b);
			aDep = dep[a];
			bDep = dep[b];
		}
		int gap = aDep - bDep;
		int d = 0;
		while (gap) {
			if (gap % 2 == 1) a = parent[a][d];
			d++;
			gap /= 2;
		}

		if (a == b) { cout << a << '\n'; continue; }
		for (int j = 18 - 1; j >= 0; j--) {
			if (parent[a][j] != parent[b][j]) {
				a = parent[a][j];
				b = parent[b][j];
			}
		}

		a = parent[a][0];
		cout << a << '\n';
	}

}