/*1012*/
#include<queue>
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef pair<int, int> info;
int M, N, K;

void bfs(vector<vector<int>> &ground, vector<vector<bool>>& visited, int v_i, int v_j) {
	visited[v_i][v_j] = true;
	queue<info>q;
	q.push(info(v_i, v_j));
	
	while (!q.empty()) {
		info v = q.front();
		q.pop();
		int i = v.first;
		int j = v.second;

		if (i - 1 >= 0) {
			if (ground[i - 1][j] == 1 && visited[i - 1][j] == false) {
				visited[i - 1][j] = true;
				q.push(info(i - 1, j));
			}
		}
		if (i + 1 < N) {
			if (ground[i + 1][j] == 1 && visited[i + 1][j] == false) {
				visited[i + 1][j] = true;
				q.push(info(i + 1, j));
			}
		}
		if (j - 1 >= 0) {
			if (ground[i][j-1] == 1 && visited[i][j-1] == false) {
				visited[i][j-1] = true;
				q.push(info(i, j-1));
			}
		}
		if (j + 1 < M) {
			if (ground[i][j + 1] == 1 && visited[i][j + 1] == false) {
				visited[i][j + 1] = true;
				q.push(info(i, j + 1));
			}
		}
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		int cnt = 0;

		cin >> M >> N >> K;
		vector<vector<int>> ground(N, vector<int>(M, 0));
		vector<vector<bool>> visited(N, vector<bool>(M, false));
		for (int j = 0; j < K; j++) {
			int a, b;

			cin >> a >> b;
			ground[b][a] = 1;
		}
		
		for (int j = 0; j < N; j++) {
			for (int t = 0; t < M; t++) {
				if (ground[j][t] == 1 && visited[j][t] == false) {
					bfs(ground, visited, j, t);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}
}