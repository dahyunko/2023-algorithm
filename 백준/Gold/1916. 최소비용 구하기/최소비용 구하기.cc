/*057(1916)-최소 비용 구하기*/
#include<queue>
#include <limits.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> Edge;

void dikstra(vector<vector<Edge>> & graph, vector<char> &visited, vector<int> &D, int start,int end) {
	priority_queue <Edge, vector<Edge>, greater<Edge>> pq;
	//first: 거리, second: 노드
	pq.push(Edge(0, start));
	D[start] = 0;

	while (!pq.empty()) {
		Edge current = pq.top();
		int x = current.second;//노드

		pq.pop();
		if (visited[x] == 'T') continue;
		visited[x] = 'T';

		for (int i = 0; i < graph[x].size(); i++) {
			int t = graph[x][i].first;
			int p = graph[x][i].second+ D[x];
			if (D[t] > p) {
				D[t] = p;
				pq.push(Edge(D[t], t));
			}
		}
	}
}

int main() {
	int N, M;//도시, 버스

	cin >> N;
	cin >> M;
	vector<vector<Edge>> graph;
	//first: 연결 노드, second: weight
	graph.resize(N + 1);
	vector<char> visited(N + 1, 'F');
	vector<int> D(N + 1, INT_MAX);

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(Edge(v, w));
	}
	int start, end;

	cin >> start >> end;

	dikstra(graph, visited, D, start, end);

	cout << D[end];
}