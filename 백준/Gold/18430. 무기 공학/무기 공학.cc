#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int N, M, result = 0;
int board[6][6];
bool visited[6][6] = { false };
int a[4] = { -1, 0, 1, 0 };
int b[4] = { 0, 1, 0, -1 };

bool isTrue(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

int checkBoard(int x, int y) {
	int answer = 0;

	for (int t = 0; t < 4; t++) {
		int x1 = x + a[t % 4];
		int y1 = y + b[t % 4];
		int x2 = x + a[(t + 1) % 4];
		int y2 = y + b[(t + 1) % 4];

		// 부메랑 만들 수 있는지 확인
		if (!isTrue(x1, y1) || !isTrue(x2, y2)) continue;
		if (visited[x1][y1] || visited[x2][y2]) continue;

		visited[x1][y1] = true;
		visited[x2][y2] = true;
		visited[x][y] = true;
		int sum = board[x][y] * 2 + board[x1][y1] + board[x2][y2];

		// 이동할 수 있는 조합 이동
		int temp = 0;
		int c = y + 1;
		for (int i = x; i < N; i++) {
			for (int j = c; j < M; j++) {
				if (visited[i][j]) continue;
				temp = max(temp, checkBoard(i, j));
			}
			c = 0;
		}
		visited[x1][y1] = false;
		visited[x2][y2] = false;
		visited[x][y] = false;

		answer = max(answer, temp + sum);
	}

	return answer;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> board[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result = max(result, checkBoard(i, j));
		}
	}

	cout << result;
}