/*1238*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

struct info {
	int next;
	int time;
};

struct cmp {
	bool operator()(info a, info b ) {
		return a.time > b.time;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<info>>graph(N + 1);
	vector<int>total(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;

		graph[a].push_back({ b, t });
	}
	
	for (int t = 1; t <= N; t++) {
		priority_queue<info, vector<info>, cmp>pq;
		vector<bool>visited(N + 1, false);
		
		//가는 거
		pq.push({ t, 0 });
		while (!pq.empty()) {
			info v = pq.top();
			pq.pop();

			if (v.next == X) {
				total[t] = v.time;
				break;
			}
			if (visited[v.next]) continue;
			visited[v.next] = true;

			for (int i = 0; i < graph[v.next].size(); i++) {
				info w = graph[v.next][i];
				pq.push({ w.next, v.time + w.time });
			}
		}
	
	}

	//오는 거
	priority_queue<info, vector<info>, cmp>pq;
	vector<bool>visited(N + 1, false);
	vector<int>dis(N + 1, INT_MAX);

	pq.push({ X, 0 });
	dis[X] = 0;
	while (!pq.empty()) {
		info v = pq.top();
		pq.pop();

		if (visited[v.next]) continue;
		visited[v.next] = true;

		for (int i = 0; i < graph[v.next].size(); i++) {
			info w = graph[v.next][i];

			if (dis[v.next] + w.time < dis[w.next]) {
				dis[w.next] = dis[v.next] + w.time;
				pq.push({ w.next, dis[w.next] });
			}			
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dis[i] + total[i]);
		//cout <<i<<": " << total[i] << ' ' << dis[i]<<'\n';
	}

	cout << ans;
}