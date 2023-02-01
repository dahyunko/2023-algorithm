/*028(1167)- 트리의 지름 구하기*/
#include<queue>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef pair<int, int> node;

void bfs(vector<vector<node>>& graph, vector<int>& result, vector<char>& visited, int v) {
	queue<int> q;
	visited[v] = 'T';
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 0; i < graph[v].size();i++) {
			int t = graph[v][i].first;
			int w = graph[v][i].second;
			if (visited[t] == 'F') {
				result[t] = result[v] + w;
				visited[t] = 'T';
				q.push(t);
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	cin >> N;
	vector<vector<node>>graph;
	graph.resize(N + 1);
	vector<char> visited(N + 1, 'F');
	vector<int> result(N + 1, 0);

	for (int i = 0; i < N; i++) {
		int idx, a, b;
		cin >> idx;
		cin >> a;
		if (a == -1) continue;
		while (a != -1) {
			cin >> b;
			graph[idx].push_back(node(a, b));
			cin >> a;
		}
	}

	//임의의 노드 1에서 가장 큰 거리를 찾고
	bfs(graph, result, visited, 1);
	int max_idx = max_element(result.begin(), result.end()) - result.begin();
	//그 거리에서(max_idx) 다시 bfs 실행
	fill(visited.begin(), visited.end(), 'F');
	fill(result.begin(), result.end(),0);
	bfs(graph, result, visited, max_idx);
	
	cout << *max_element(result.begin(), result.end());
}