/*3190*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <cmath>
#include <deque>

using namespace std;

struct info {
	int time;
	char c;
};

struct snake {
	int x, y;
};

int N, K, L, T = 0;
int a[4] = { 0, 1, 0, -1 };
int b[4] = { 1, 0, -1, 0 };

bool checked(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N) return true;
	return false;
}

int main() {
	cin >> N;
	cin >> K;

	vector<vector<int>>board(N, vector<int>(N, 0));
	vector<vector<bool>>visited(N, vector<bool>(N, false));

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;

		board[a-1][b-1] = 1;
	}

	cin >> L;
	vector<info> m(L);
	for (int i = 0; i < L; i++) {
		cin >> m[i].time >> m[i].c;
	}
	
	int idx = 0, dir = 0;
	T = 0;
	deque<snake>dq;
	dq.push_front({ 0, 0 });

	while (true) {
		T++;
		// 회전
		if (idx < m.size() && m[idx].time < T) {
			if (m[idx].c == 'L') {
				if (dir == 0) dir = 3;
				else dir--;
			}
			else {
				if (dir == 3) dir = 0;
				else dir++;
			}

			idx++;
		}

		// 이동
		int xx = dq.front().x + a[dir];
		int yy = dq.front().y + b[dir];

		if (!checked(xx, yy)) break;
		else if (visited[xx][yy]) break;
		else if (board[xx][yy] == 1) { // 사과
			visited[xx][yy] = true;
			dq.push_front({ xx, yy });
            board[xx][yy] = 0; // 사과 치우기
		}
		else if (board[xx][yy] == 0) {
			visited[xx][yy] = true;
			visited[dq.back().x][dq.back().y] = false;
			dq.push_front({ xx, yy });
			dq.pop_back();
		}
	}

	cout << T;
}