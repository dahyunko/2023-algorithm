/*15591*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<tuple>
#include<cmath>

using namespace std;

struct info {
	int v;
	int u;
};

int main() {
	int N, Q;

	cin >> N >> Q;
	vector<vector<info>> graph(N + 1);

	for (int i = 0; i < N-1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		graph[p].push_back({ q , r});
		graph[q].push_back({p, r});
	}

	for (int j = 0; j < Q; j++) {
		int k, t, c = 0;
		cin >> k >> t;
		vector<bool>visited(N + 1, false);

		//탐색 시작
		queue<int> q;
		q.push(t);
		visited[t] = true;
		while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (int i = 0; i < graph[v].size(); i++) {
				int w = graph[v][i].v;
				int u = graph[v][i].u;
				if (u < k || visited[w]) continue;
				visited[w] = true;
				c++;
				q.push(w);
			}
		}
		
		cout << c << '\n';
	}
}