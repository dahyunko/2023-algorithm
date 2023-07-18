/*4179*/
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<map>
#include<set>
#include<queue>

using namespace std;

struct info {
	int x;
	int y;
	int cnt;
};

int a[4] = { 1, -1, 0 ,0 };
int b[4] = { 0 ,0, 1, -1 };
char board[1001][1001];
bool visited[1001][1001] = { false };
int x, y, R, C;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;

	queue<info> fire;
	queue<info> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'J') q.push({ i, j, 0 });
			if (board[i][j] == 'F') fire.push({ i, j, 0 });
		}
	}

	int idx = 0, flag = 0, answer, idx_f = 0;
	while (flag == 0) {
		//불 확장
		while (!fire.empty()) {
			info v = fire.front();
			if (v.cnt > idx_f) {
				idx_f++;
				break;
			}
			fire.pop();

			for (int t = 0; t < 4; t++) {
				if (v.x + a[t] >= 0 && v.x + a[t] < R && v.y + b[t] >= 0 && v.y + b[t] < C) {
					if (board[v.x + a[t]][v.y + b[t]] != '#' && board[v.x + a[t]][v.y + b[t]] != 'F') {
						board[v.x + a[t]][v.y + b[t]] = 'F'; 
						fire.push({ v.x + a[t],v.y + b[t],v.cnt + 1 });
					}
				}
			}
		}

		//탈출 가능한지
		int no_move = 0;
		while (!q.empty()) {
			info v = q.front();
			if (v.cnt > idx) {
				idx++;
				break;
			}
			q.pop();

			if (visited[v.x][v.y]) continue;
			visited[v.x][v.y] = true;

			//움직일 수 있는 범위
			for (int t = 0; t < 4; t++) {
				if (v.x + a[t] >= 0 && v.x + a[t] < R && v.y + b[t] >= 0 && v.y + b[t] < C) {
					if (board[v.x + a[t]][v.y + b[t]] == '.') {
						no_move = 1;
						q.push({ v.x + a[t], v.y + b[t], v.cnt + 1 });
					}
				}
				if ((v.x + a[t] < 0 || v.x + a[t] >= R) || (v.y + b[t] < 0 || v.y + b[t] >= C)) {
					flag = 1;
					answer = v.cnt+1;
					break;
				}
			}
			if (flag == 1) break;
		}
		if (no_move == 0) break;
	}

	if (flag == 1) cout << answer;
	else cout << "IMPOSSIBLE";
}