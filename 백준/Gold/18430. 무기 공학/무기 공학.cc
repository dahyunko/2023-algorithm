/*18430*/
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

bool isTrue(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < M);
}

int checkBoard(int y, int x) {
	int result = 0;

	for (int t = 0; t < 4; t++) {
		int y1 = y + a[t % 4];
		int x1 = x + b[t % 4];
		int y2 = y + a[(t + 1) % 4];
		int x2 = x + b[(t + 1) % 4];

		// 부메랑 만들 수 있는지 확인
		if (!isTrue(y1, x1) || !isTrue(y2, x2)) continue;
		if (visited[y1][x1] || visited[y2][x2]) continue;

		visited[y][x] = true;
		visited[y1][x1] = true;
		visited[y2][x2] = true;
		int sum = board[y][x] * 2 + board[y1][x1] + board[y2][x2];

		// 이동할 수 있는 조합 이동
		int temp = 0;
		int c = x + 1;
		for (int i = y; i < N; i++) {
			for (int j = c; j < M; j++) {
				if (visited[i][j]) continue;
				temp = max(temp, checkBoard(i, j));
			}
			c = 0;
		}
		visited[y1][x1] = false;
		visited[y2][x2] = false;
		visited[y][x] = false;

		result = max(result, temp + sum);
	}
	
	return result;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> board[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result = max(checkBoard(i, j), result);
		}
	}

	cout << result;
}