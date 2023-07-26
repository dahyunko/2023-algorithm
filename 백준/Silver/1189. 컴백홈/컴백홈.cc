/*11*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct info {
	int x, y, cnt;
};
char A[6][6];
bool visited[6][6] = { false };
int a[4] = { 1, -1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };
int R, C, K, ans = 0;

void dfs(info v) {
	if (v.cnt == K) {
		if (v.x == 0 && v.y == C - 1) ans++;
		return;
	}
	if (!visited[v.x][v.y]) visited[v.x][v.y] = true;

	for (int i = 0; i < 4; i++) {
		if (v.x + a[i] >= 0 && v.x + a[i] < R && v.y + b[i] >= 0 && v.y + b[i] < C) {
			if (A[v.x + a[i]][v.y + b[i]] == '.' && !visited[v.x + a[i]][v.y + b[i]]) {
				visited[v.x + a[i]][v.y + b[i]] = true;
				dfs({ v.x + a[i], v.y + b[i], v.cnt + 1 });
				visited[v.x + a[i]][v.y + b[i]] = false;
			}
		}
	}
}


int main(){
	cin >> R >> C >> K;
	
	for (int r = 0; r < R; r++) {
		string s;
		cin >> s;
		for (int c = 0; c < C; c++) A[r][c] = s[c];
	}

	dfs({ R-1, 0 , 1 });

	cout << ans;
}