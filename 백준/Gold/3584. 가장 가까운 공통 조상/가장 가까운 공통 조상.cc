/*3584*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;
int N;

void bfs(int v, vector<vector<int>>&graph, vector<int>&dep) {
	vector<bool>visited(N + 1, false);

	queue<int>q;
	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < graph[v].size(); i++) {
			int t = graph[v][i];

			if (!visited[t]) {
				visited[t] = true;
				dep[t] = dep[v] + 1;
				q.push(t);
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;
		vector<vector<int>>graph(N+1);
		vector<int>parent(N+1, -1);
		vector<int>dep(N+1, 0);
		
		for (int i = 0; i < N - 1; i++) {
			int A, B;
			cin >> A >> B;

			parent[B] = A;
			graph[A].push_back(B);
		}

		//root 찾기
		int idx = find(parent.begin() + 1, parent.end(), -1) - parent.begin();

		bfs(idx, graph, dep);

		//찾기 시작
		int a, b;
		cin >> a >> b;

		if (dep[a] < dep[b]) swap(a, b);
		int a_dep = dep[a];
		int b_dep = dep[b];

		while (a_dep != b_dep) {
			a = parent[a];
			a_dep--;
		}

		while (a != b) {
			a = parent[a];
			b = parent[b];
		}

		cout << b << "\n";
	}
}