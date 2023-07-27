/*20*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
using namespace std;

struct info { int x, y; };
int board[9][9];
int N;
vector<info>A;
vector<vector<int>>B;
bool is_find = false;

void find_num(int t, info v) {
	bool num[10] = { false };
	//좌우
	for (int i = 0; i < 9; i++) {
		if (board[v.x][i] != 0) num[board[v.x][i]] = true;
	}

	//상하
	for (int i = 0; i < 9; i++) {
		if (board[i][v.y] != 0) num[board[i][v.y]] = true;
	}

	//네모
	for (int i = v.x- v.x%3; i < v.x - v.x % 3 + 3; i++) {
		for (int j = v.y - v.y % 3; j < v.y - v.y % 3 + 3; j++) {
			if (board[i][j] != 0) num[board[i][j]] = true;
		}
	}

	//들어갈 수 있는 수 탐색
	for (int i = 1; i < 10; i++) {
		if (!num[i]) B[t].push_back(i);
	}
}

bool check(info v, int num) {
	//좌우, 상하
	for (int i = 0; i < 9; i++) {
		if (board[v.x][i] == num) return false;
		if (board[i][v.y] == num) return false;
	}

	//네모
	for (int i = v.x - v.x % 3; i < v.x - v.x % 3 + 3; i++) {
		for (int j = v.y - v.y % 3; j < v.y - v.y % 3 + 3; j++) {
			if (board[i][j] == num) return false;
		}
	}
	return true;
}

void dfs(int t) {
	if (t == N) {
		is_find = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout << board[i][j] << ' ';
			cout << '\n';
		}
		return;
	}

	for (int i = 0; i < B[t].size(); i++) {
		info v = A[t];
		//check
		if (check(v, B[t][i])) {
			board[v.x][v.y] = B[t][i];
			dfs(t + 1);
			if (is_find) return;//찾았을 시 종료 시점을 이곳으로 해야함
			board[v.x][v.y] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) A.push_back({ i, j });
		}
	}
	N = A.size();
	B.resize(N);

	//들어갈 수 있는 수 찾기
	for (int i = 0; i < A.size(); i++) {
		find_num(i, A[i]);
	}

	dfs(0);
}