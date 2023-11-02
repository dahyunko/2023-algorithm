/*14466*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<cmath>

using namespace std;

struct info {
	int x, y;
};
int  N, ef = 0;
int list[3];
bool visited[37] = { false };
int a[4] = { 0, 1, 0, -1 };
int b[4] = { 1, 0, -1, 0 };
vector<info>teacher;
vector<info>empty_field;
bool is_okay = false;

void back_tracking(int c, int j, vector<vector<char>> &field) {
	if (is_okay) return;
	if (c == 3) {
		//탐색 시작
		bool yes_chiledren = false;//학생이 있으면 중지
		int tx, ty;

		for (int i = 0; i < teacher.size(); i++) {
			tx = teacher[i].x;
			ty = teacher[i].y;

			//상하좌우 탐색
			for (int r = 0; r < 4; r++) {
				int mx = tx;
				int my = ty;
				bool stop_searching = false;
	
				while (true) {
					if (stop_searching) break;
					mx += a[r];
					my += b[r];

					//범위를 넘어갈 경우 중지
					if (mx < 0 || mx >=  N || my < 0 || my >= N) break;
					
					if (field[mx][my] == 'S') {
						yes_chiledren = true;
						break;
					}

					//해당 구역에 장애물 있다면 탐색 중지
					for (int p = 0; p < 3; p++) {
						if (mx == empty_field[list[p]].x && my == empty_field[list[p]].y) {
							stop_searching = true;
							break;
						}
					}
				}
				if (yes_chiledren) break;
			}
			if (yes_chiledren) break;
		}
		if (!yes_chiledren) is_okay = true;
		
		return;
	}
	
	//가능한 장애물 3개씩
	for (int i = j; i < ef; i++) {
		list[c] = i;
		back_tracking(c + 1, i + 1, field);
		if (is_okay) return;
	}
}

int main() {
	cin >> N;

	vector<vector<char>>field(N, vector<char>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'T') teacher.push_back({ i, j });
			else if (field[i][j] == 'X') empty_field.push_back({ i, j });
		}
	}
	ef = empty_field.size();

	back_tracking(0, 0, field);
	if (is_okay) cout << "YES";
	else cout << "NO";
}