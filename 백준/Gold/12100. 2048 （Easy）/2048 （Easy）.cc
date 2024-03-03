#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include <cmath>
#include <limits.h>

using namespace std;

int a[4] = { -1, 1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };

int N, result = 0;
int list[4];
bool visited[4] = { false };

bool checked(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N) return true;
	return false;
}

int find_max_number(vector<vector<int>> board) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) temp = max(temp, board[i][j]);
	}
	return temp;
}

void print_board(vector<vector<int>> board, int dir, int flag) {
	if (flag == 0) cout << "--------- 이전 -------\n";
	else cout << "--------- " << dir << " -------\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j]<<' ';
		}
		cout << '\n';
	}
}

vector<vector<int>> move_up(vector<vector<int>> board, int dir) {
	//print_board(board, dir, 0);
	vector<vector<bool>> visited(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;
			int xx = i + a[dir];
			int yy = j + b[dir];

			//0이 보일때 까지 올라감
			while (true) {
				if (!checked(xx, yy)) { // 범위 넘어감
					if (xx - a[dir] == i && yy - b[dir] == j) break;
					board[xx - a[dir]][yy - b[dir]] = board[i][j];
					board[i][j] = 0;
					break; 
				}
				if (board[xx][yy] != 0) { // 
					if (board[xx][yy] == board[i][j]) { // 같으면 합치고
						if (!visited[xx][yy]) {
							board[xx][yy] += board[i][j];
							board[i][j] = 0;
							visited[xx][yy] = true;
						}
						else {
							if (xx - a[dir] == i && yy - b[dir] == j) break;
							board[xx - a[dir]][yy - b[dir]] = board[i][j];
							board[i][j] = 0;
						}
					}
					else { // 다르면 이전 것에 저장
						if (xx - a[dir] == i && yy - b[dir] == j) break;
						board[xx - a[dir]][yy - b[dir]] = board[i][j];
						board[i][j] = 0;
					}
					break;
				}
				xx += a[dir];
				yy += b[dir];
			}
		}
	}
	//print_board(board, dir, 1);
	return board;
}

vector<vector<int>> move_down(vector<vector<int>> board, int dir) {
	//print_board(board, dir, 0);
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for (int i = N-1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;
			int xx = i + a[dir];
			int yy = j + b[dir];

			//0이 보일때 까지 내려감
			while (true) {
				if (!checked(xx, yy)) { // 범위 넘어감
					if (xx - a[dir] == i && yy - b[dir] == j) break;
					board[xx - a[dir]][yy - b[dir]] = board[i][j];
					board[i][j] = 0;
					break;
				}
				if (board[xx][yy] != 0) { // 
					if (board[xx][yy] == board[i][j]) { // 같으면 합치고
						if (!visited[xx][yy]) {
							board[xx][yy] += board[i][j];
							board[i][j] = 0;
							visited[xx][yy] = true;
						}
						else {
							if (xx - a[dir] == i && yy - b[dir] == j) break;
							board[xx - a[dir]][yy - b[dir]] = board[i][j];
							board[i][j] = 0;
						}
					}
					else { // 다르면 이전 것에 저장
						if (xx - a[dir] == i && yy - b[dir] == j) break;
						board[xx - a[dir]][yy - b[dir]] = board[i][j];
						board[i][j] = 0;
					}
					break;
				}
				xx += a[dir];
				yy += b[dir];
			}
		}
	}
	//print_board(board, dir, 1);
	return board;
}

vector<vector<int>> move_right(vector<vector<int>> board, int dir) {
	//print_board(board, dir, 0);
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j >= 0; j--) {
			if (board[i][j] == 0) continue;
			int xx = i + a[dir];
			int yy = j + b[dir];

			//0이 보일때 까지 내려감
			while (true) {
				if (!checked(xx, yy)) { // 범위 넘어감
					if (xx - a[dir] == i && yy - b[dir] == j) break;
					board[xx - a[dir]][yy - b[dir]] = board[i][j];
					board[i][j] = 0;
					break;
				}
				if (board[xx][yy] != 0) { // 
					if (board[xx][yy] == board[i][j]) { // 같으면 합치고
						if (!visited[xx][yy]) {
							board[xx][yy] += board[i][j];
							board[i][j] = 0;
							visited[xx][yy] = true;
						}
						else {
							if (xx - a[dir] == i && yy - b[dir] == j) break;
							board[xx - a[dir]][yy - b[dir]] = board[i][j];
							board[i][j] = 0;
						}
					}
					else { // 다르면 이전 것에 저장
						if (xx - a[dir] == i && yy - b[dir] == j) break;
						board[xx - a[dir]][yy - b[dir]] = board[i][j];
						board[i][j] = 0;
					}
					break;
				}
				xx += a[dir];
				yy += b[dir];
			}
		}
	}
	//print_board(board, dir, 1);
	return board;
}

vector<vector<int>> move_left(vector<vector<int>> board, int dir) {
	//print_board(board, dir, 0);
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;
			int xx = i + a[dir];
			int yy = j + b[dir];

			//0이 보일때 까지 왼쪽으로 이동
			while (true) {
				if (!checked(xx, yy)) { // 범위 넘어감
					if (xx - a[dir] == i && yy - b[dir] == j) break;
					board[xx - a[dir]][yy - b[dir]] = board[i][j];
					board[i][j] = 0;
					break;
				}
				if (board[xx][yy] != 0) { // 칸에 숫자 있음
					if (board[xx][yy] == board[i][j]) { // 같으면 합치고
						if (!visited[xx][yy]) {
							board[xx][yy] += board[i][j];
							board[i][j] = 0;
							visited[xx][yy] = true;
						}
						else {
							if (xx - a[dir] == i && yy - b[dir] == j) break;
							board[xx - a[dir]][yy - b[dir]] = board[i][j];
							board[i][j] = 0;
						}
					}
					else { // 다르면 이전 것에 저장
						if (xx - a[dir] == i && yy - b[dir] == j) break;
						board[xx - a[dir]][yy - b[dir]] = board[i][j];
						board[i][j] = 0;
					}
					break;
				}
				xx += a[dir];
				yy += b[dir];
			}
		}
	}
	//print_board(board, dir, 1);
	return board;
}

void dfs(int cnt , vector<vector<int>> board) {
	if (cnt == 5) {
		result = max(result, find_max_number(board));
		return;
	}
		
	dfs(cnt + 1, move_up(board, 0));
	dfs(cnt + 1, move_down(board, 1));
	dfs(cnt + 1, move_right(board, 2));
	dfs(cnt + 1, move_left(board, 3));
}


int main() {
	cin >> N;

	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> board[i][j];
	}

	dfs(0, board);
	cout << result;
	return 0;
}