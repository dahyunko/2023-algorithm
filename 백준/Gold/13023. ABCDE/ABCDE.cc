/*025(13023)- 친구관계 파악하기*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

static bool arrive = false;

void dfs(vector<vector<int>>& graph, vector<char>& visited, int depth, int v) {
	if (depth == 5 || arrive) {
		arrive = true;
		return; 
	}
	visited[v] = 'T';
	for (int i = 0; i < graph[v].size(); i++) {
		int t = graph[v][i];
		if (visited[t] == 'F') {
			dfs(graph, visited, depth+1, t);
		}
	}
    
    //실패한 경로에 대해서 삭제 반환하는 작업 필요
    visited[v] = 'F';
}


int main() {
	int N, M;

	cin >> N >> M;
	vector<vector<int>> graph;
	vector<char> visited(N + 1, 'F');
	graph.resize(N+1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		dfs(graph, visited, 1, i);
		if (arrive) break;
		fill(visited.begin(), visited.end(), 'F');
	}
	if (arrive) cout << 1;
	else cout << 0;
}