/* 10282 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;
struct node {
	int n, t;
};

void makeGraph() {
	int N, d, c;
	cin >> N >> d >> c;

	vector<vector<node>>graph(N);

	for (int i = 0; i < d; i++) {
		int a, b, s;
		cin >> a >> b >> s;

		graph[b - 1].push_back({ a - 1 , s });
	}

	//search
	vector<int> D(N, INT_MAX);
	queue<node> q;
	q.push({ c - 1, 0 });

	while (!q.empty()) {
		node v = q.front();
		q.pop();

		if (D[v.n] <= v.t) continue;
		D[v.n] = v.t;

		for (int i = 0; i < graph[v.n].size(); i++) {
			int w = graph[v.n][i].n;
			int t = graph[v.n][i].t;

			if (D[v.n] != INT_MAX && D[w] > D[v.n] + t) {
				q.push({ w, D[v.n] + t });
			}
		}
	}

	int hackCnt = 0, hackTime = 0;
	for (int i = 0; i < N; i++) {
		if (D[i] == INT_MAX) continue;
		hackCnt++;
		hackTime = max(hackTime, D[i]);
	}

	cout << hackCnt << ' ' << hackTime << '\n';
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		makeGraph();
	}
}