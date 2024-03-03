#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include <cmath>
#include <limits.h>

using namespace std;

struct loc {
	int x, y;
};

struct info {
	loc rm, bm;
	int cnt, pin; // 개수, 방향
};

int a[4] = { 1, -1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };
int N, M, result = -1;
char board[11][11];
loc red_marble, blue_marble, hole;

bool check_with_hole(loc now) {
	if (hole.x == now.x && hole.y == now.y) return true;
	return false;
}

bool check_same(loc now, loc next) {
	if (now.x == next.x && now.y == next.y) return true;
	return false;
}

loc move_marble(loc now, loc near,int now_p) {
	int xx = now.x + a[now_p];
	int yy = now.y + b[now_p];

	while (true) {
		if (board[xx][yy] != '.') {
			// 구멍 빠진 것
			if (board[xx][yy] == 'O') return { xx, yy };
			return { xx - a[now_p], yy - b[now_p] };
		}
		if (near.x == xx && near.y == yy) { // 겹치는 것 확인
			return { xx - a[now_p], yy - b[now_p] };
		}
		xx += a[now_p];
		yy += b[now_p];
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'R') {
				red_marble = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				blue_marble = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'O') hole = { i, j };
		}
	}
    
	queue<info> q;
	// pin-> 0 : 아래, 1 : 위, 2 : 오른 , 3 : 왼, -1: default
	q.push({ red_marble, blue_marble, 0, -1 });
    
	while (!q.empty()) {
		info now = q.front();
		q.pop();

		if (now.cnt > 10) { // 구슬 못 뺌
			break;
		}
		if (check_with_hole(now.rm) && !check_with_hole(now.bm)) {
			result = now.cnt;
			break;
		}
        if (check_with_hole(now.bm)) { // 파란공이 먼저 빠짐
	        continue;
        }

		for (int i = 0; i < 4; i++) {
			if (i == now.pin) continue;
			loc next_r, next_b;

			if (i == 0 && now.rm.y == now.bm.y) { // 아래, 같은 col
				if (now.rm.x > now.bm.x) { // red 아래 있음, red 먼저 이동
					next_r = move_marble(now.rm, now.bm, i);
					next_b = move_marble(now.bm, next_r, i);
				}
				else { // blue가 아래 있음
					next_b = move_marble(now.bm, now.rm, i);
					next_r = move_marble(now.rm, next_b, i);
				}
			}
			else if (i == 1 && now.rm.y == now.bm.y){ // 위, 같은 col
				if (now.rm.x > now.bm.x) { // red 아래 있음, blue 먼저 이동
					next_b = move_marble(now.bm, now.rm, i);
					next_r = move_marble(now.rm, next_b, i);
				}
				else { // blue가 아래 있음, red 먼저 이동
					next_r = move_marble(now.rm, now.bm, i);
					next_b = move_marble(now.bm, next_r, i);
				}
			}
			else if (i == 2 && now.rm.x == now.bm.x) { // 오른쪽, 같은 row
				if (now.rm.y > now.bm.y) { // red 오른쪽 있음, red 먼저 이동
					next_r = move_marble(now.rm, now.bm, i);
					next_b = move_marble(now.bm, next_r, i);
				}
				else { // blue가 오른쪽 있음, blue 먼저 이동
					next_b = move_marble(now.bm, now.rm, i);
					next_r = move_marble(now.rm, next_b, i);
				}
			}
			else if (i == 3 && now.rm.x == now.bm.x) { // 오른쪽, 같은 row
				if (now.rm.y > now.bm.y) { // red 오른쪽 있음, blue 먼저 이동
					next_b = move_marble(now.bm, now.rm, i);
					next_r = move_marble(now.rm, next_b, i);
				}
				else { // blue가 오른쪽 있음, red 먼저 이동
					next_r = move_marble(now.rm, now.bm, i);
					next_b = move_marble(now.bm, next_r, i);
				}
			}
			else {
				next_r = move_marble(now.rm, now.bm, i);
				next_b = move_marble(now.bm, now.rm, i);
			}
			
			if (check_same(now.rm, next_r) && check_same(now.bm, next_b)) continue;
			q.push({ next_r, next_b, now.cnt + 1, i });
		}

	}
	cout << result;
}