//다익스트라
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>

using namespace std;

struct info {
	int next, money;
};

struct comp {
	bool operator()(info a, info b) {
		return a.money > b.money;
	}
};

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<info>>graph(N+1);
	vector<int>sum(N + 1, INT_MAX);
	vector<bool>visited(N + 1, false);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	priority_queue<info, vector<info>, comp>pq;
	sum[1] = 0;
	pq.push({ 1, 0 });
	while (!pq.empty()) {
		info v = pq.top();
		pq.pop();

		if (visited[v.next]) continue;
		visited[v.next] = true;

		for (int i = 0; i < graph[v.next].size(); i++) {
			info t = graph[v.next][i];

			if (v.money + t.money < sum[t.next]) {
				sum[t.next] = sum[v.next] + t.money;
				pq.push({ t.next, sum[t.next] });
			}
		}
	}
	
	cout << sum[N];
}