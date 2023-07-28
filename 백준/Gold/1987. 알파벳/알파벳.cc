/*21*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
using namespace std;

int R, C, ans = -1;
char A[21][21];
bool visited[21][21] = { false };
bool alpha[27] = { false };
int a[4] = { 1, -1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int cnt) {
	if (cnt > R * C) return;
	ans = max(ans, cnt);

	bool is_in = false;
	for (int i = 0; i < 4; i++) {
		int next_x = x + a[i];
		int next_y = y + b[i];
		if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C) {
			if (!visited[next_x][next_y] && !alpha[A[next_x][next_y]-'A']) {
				is_in = true;
				visited[next_x][next_y] = true;
				alpha[A[next_x][next_y]-'A'] = true;
				dfs(next_x, next_y, cnt + 1);
				alpha[A[next_x][next_y] - 'A'] = false;
				visited[next_x][next_y] = false;
			}
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) cin >> A[i][j];
	}

	visited[0][0] = true;
	alpha[A[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << ans;
}