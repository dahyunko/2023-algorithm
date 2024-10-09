/*17182*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int N, K, answer = INT_MAX;
int graph[11][11] = { 0 };
vector<bool> visited(11, false);

void backDfs(int s, int cnt, int sum) {
	if (cnt == N) {
		answer = min(answer, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;

		backDfs(i, cnt + 1, sum + graph[s][i]);
		visited[i] = false;
	}
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> graph[i][j];
	}

	// 플로이드 워셜 최단 거리 구하기
	for (int r = 0; r < N; r++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] > graph[i][r] + graph[r][j]) {
					graph[i][j] = graph[i][r] + graph[r][j];
				}
			}
		}
	}

	// 백트래킹으로 최단 거리 탐색
	visited[K] = true;
	backDfs(K, 1, 0);

	cout << answer;
}