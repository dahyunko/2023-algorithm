/*2638*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;
struct info { int x, y; };

int a[4] = { 0, 0, 1, -1 };
int b[4] = { 1, -1, 0, 0 };
int N, M;
int board[104][104];

bool isIn(int x, int y) {
	return x >= 0 && x <= N + 1 && y >= 0 && y <= M + 1;
}

int findWetPlace() {
	vector<info> result;
	vector<vector<bool>>visited(N + 2, vector<bool>(M + 2, false));
	vector<vector<int>>wetBoard(N + 2, vector<int>(M + 2, 0));

	queue<info> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		info v = q.front();
		q.pop();

		if (visited[v.x][v.y]) continue;
		visited[v.x][v.y] = true;

		for (int i = 0; i < 4; i++) {
			int xx = v.x + a[i];
			int yy = v.y + b[i];

			if (isIn(xx, yy) && !visited[xx][yy]) {
				if (board[xx][yy] == 0) {
					q.push({ xx, yy });
				}
				else if (board[xx][yy] == 1) { // 젖은 곳
					wetBoard[xx][yy]++;
				}
			}
		}
	}

	int temp = 0;
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= M+1; j++) {
			if (wetBoard[i][j] >= 2 ) {
				board[i][j] = 0;
				temp++;
			}
		}
	}
	
	return temp;
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}

	int time = 0;
	while (true) {
		if (findWetPlace() == 0) break;
		time++;
	}

	cout << time;
}