/*048(1707)-이분 그래프 판별하기*/
//이분 그래프(Bipartite Graph)
//인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 두 가지 색으로만 칠할 수 있는 그래프
//같은 레벨이 연결되어있으면, 즉 사이클 존재하면 안됨
#include <queue>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<char, char> Node;

int bfs(vector<vector<int>>& graph, vector<Node>& visited, int x) {
	queue<int> que;
	visited[x].first = 'T';
	visited[x].second = 'R';
	que.push(x);

	while (!que.empty()) {
		x = que.front();
		que.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int t = graph[x][i];
			//같은 색일 경우, 사이클이 존재할 경우
			if (visited[t].second == visited[x].second) {
				return 1;//이분그래프 x
			}
			else if(visited[t].second == 'N') {//색이 없을 경우
				if (visited[x].second == 'R') {
					visited[t].second = 'B';
				}
				else {
					visited[t].second = 'R';
				}
				visited[t].first = 'T';
                que.push(t);
			}
		}
	}

	return 2;//이분그래프 0
}

int main() {
    ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int K, V, E;

	cin >> K;
	vector<int> result(K);

	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		//그래프 생성
		vector<vector<int>> graph;
		graph.resize(V + 1);
		vector <Node> visited(V+1, Node('F', 'N'));
		//first:방문, second: 색(n,r,b)
		for (int j = 0; j < E; j++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		//모든 노드가 연결이 안되어있을 수 있음
		for (int j = 1; j <= V; j++) {
			if (visited[j].first == 'F') {
				result[i] = bfs(graph, visited, j);
				if (result[i] == 1) {
					break;
				}
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		if (result[i] == 2) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
}