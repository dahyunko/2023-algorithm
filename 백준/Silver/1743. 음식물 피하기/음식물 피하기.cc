/*음식물 피하기*/
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int N, M, K, cnt;

void dfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int v1, int v2) {
	visited[v1][v2] = true;
	cnt++;

	if (v1 + 1 <= N && graph[v1 + 1][v2] == 1 && !visited[v1 + 1][v2]) {
		dfs(graph, visited, v1 + 1, v2);
	}
	if (v1 - 1 > 0 && graph[v1 - 1][v2] == 1 && !visited[v1 - 1][v2]) {
		dfs(graph, visited, v1 - 1, v2);
	}
	if (v2 + 1 <= M && graph[v1][v2 + 1] == 1 && !visited[v1][v2 + 1]) {
		dfs(graph, visited, v1, v2 + 1);
	}
	if (v2 - 1 > 0 && graph[v1][v2 - 1] == 1 && !visited[v1][v2 - 1]) {
		dfs(graph, visited, v1, v2 - 1);
	}
}


int main() {
	cin >> N >> M >> K;

	vector<vector<int>>graph(N + 1, vector<int>(M + 1, 0));
	vector<vector<bool>>visited(N+1, vector<bool>(M+1, false));

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		//쓰레기: 1
		graph[a][b] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (graph[i][j] == 1 && !visited[i][j]) {
				cnt = 0;
				dfs(graph, visited, i, j);
				ans = max(cnt, ans);
			}
		}
	}

	cout << ans;
}