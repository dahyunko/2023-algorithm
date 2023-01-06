#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

//깊이 우선 탐색
void dfs(vector<vector<int>>& graph, vector<char>& visited, int first) {
	if (visited[first] == 'T') return; //방문 했을 시 return

	visited[first] = 'T';//방문
	cout << first << ' ';

	for (int i = 0; i < graph[first].size(); i++) {
		int j = graph[first][i];
		if (visited[j] == 'F') {
			dfs(graph, visited, j);
		}
	}
}

//너비 우선 탐색
void bfs(vector<vector<int>>& graph, vector<char>& visited, int first) {
	queue<int> que;//큐 이용

	visited[first] = 'T';//방문
	que.push(first);

	while (!que.empty()) {
		for (int i = 0; i < graph[first].size(); i++) {
			int j = graph[first][i];
			if (visited[j] == 'F') {
				visited[j] = 'T';
				que.push(j);
			}
		}
		cout << que.front() << ' ';
		que.pop();
		if(!que.empty()) first = que.front();
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int N, M, first;//정점,  간선

	cin >> N >> M>> first;

	vector<vector<int>>graph;
	graph.resize(N + 1);
	vector<char> visited(N + 1, 'F');

	//그래프 생성
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(graph, visited, first);
	cout << '\n';
	fill(visited.begin(), visited.end(), 'F');//배열 방문 초기화
	bfs(graph, visited, first);
	cout << '\n';
}