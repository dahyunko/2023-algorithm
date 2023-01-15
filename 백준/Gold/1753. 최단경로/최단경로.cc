/*056(1753)-최단 경로 구하기*/
//다익스트라
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>//최대값 알려줌
#include <queue>

using namespace std;

typedef pair<int, int> Edge;//가중치 포함

void BFS(vector<vector<Edge>> &graph, vector<char> & visited, vector<int> & D, Edge x){
	priority_queue <Edge, vector<Edge>,greater<Edge>> que;
	//거리가 작은 것부터 나옴, first: 거리, second: 노드 
	
	D[x.second] = 0;//처음 들어오는 노드는 0
	que.push(x);
	
	while (!que.empty()) {
		x = que.top();
		int n = x.second;//현재 노드
		que.pop();

		//이미 방문한 노드는 다시 큐에 넣지 않는다.
		if (visited[n] == 'T') continue;
		visited[n] = 'T';

		for (int i = 0; i < graph[n].size();i++) {
			int t = graph[n][i].first;
			int p = graph[n][i].second + D[n];

			if (D[t] > p) {//최단경로 갱신
				D[t] = p;
				que.push(Edge(D[t], t));
			}
		}
	}
}

int main() {
	int N, M, V;

	cin >> N >> M;
	cin >> V;//시작 노드
	vector<vector<Edge>> graph;//방향 가중치 그래프
	vector<char> visited(N + 1, 'F');
	vector<int> D(N + 1, INT_MAX);//최종 거리
	graph.resize(N + 1);


	for (int i = 1; i <= M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(Edge(v, w));
	}

	Edge x(0, V);
	
	BFS(graph, visited, D, x);	

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 'T') {
			cout << D[i] << '\n';
		}
		else cout << "INF" << '\n';
	}
}