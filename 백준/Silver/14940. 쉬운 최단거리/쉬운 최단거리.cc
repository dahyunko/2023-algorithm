/*14940*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

struct info {
	int x, y;
};
int a[4] = { 1, -1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>>graph(N, vector<int>(M));
	vector<vector<bool>>visited(N, vector<bool>(M, false));
	vector<vector<int>>A(N, vector<int>(M, -1));

	int x, y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] != 2) continue;
			x = i; y = j;
		}
	}

	//bfs
	queue<info>q;
	q.push({ x, y });
	A[x][y] = 0;
	visited[x][y] = true;
	while (!q.empty()) {
		info v = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = v.x + a[i];
			int yy = v.y + b[i];

			if (xx >= 0 && xx < N && yy >= 0 && yy < M) {
				if (visited[xx][yy] || graph[xx][yy] != 1) continue;
				visited[xx][yy] = true;
				A[xx][yy] = A[v.x][v.y] + 1;
				q.push({ xx, yy });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) cout << 0 << ' ';
			else cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}