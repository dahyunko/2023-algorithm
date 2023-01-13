/*054(1516)- 게임 개발하기*/
#include <queue>
#include <tuple>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bfs(vector <vector<int>>& graph, vector < tuple<int, int, long>>& D) {
	queue<int> que;

	for (int i = 1; i < D.size(); i++) {
		if (get<1>(D[i]) == 0) que.push(i);
	}

	while (!que.empty()) {
		int x = que.front();
		get<2>(D[x]) += get<0>(D[x]);//최종 시간
		que.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int t = graph[x][i];
			--get<1>(D[t]);
			if (get<2>(D[t]) < get<2>(D[x])) {
				get<2>(D[t]) = get<2>(D[x]);
			}
			if (get<1>(D[t]) == 0) que.push(t);
		}
	}
	for (int i = 1; i < D.size(); i++) {
		cout << get<2>(D[i]) << '\n';
	}
}

int main() {
	int N;

	cin >> N;
	vector<vector<int>> graph;
	vector<tuple <int, int, long>> D;
	graph.resize(N + 1);
	D.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int now;
		cin >> now;
		get<0>(D[i]) = now;//시간 저장
		while (now != -1) {
			cin >> now;
			if (now == -1) break;
			graph[now].push_back(i);
			++get<1>(D[i]);//접근 노드 개수 저장
		}
	}

	bfs(graph, D);
}