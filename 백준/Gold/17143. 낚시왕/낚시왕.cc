#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

/*17143*/

struct info {
	int r, c, s, d, z;
	// (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기
	// d : 위, 아래, 오른쪽, 왼쪽
};

struct pair {
	int x, y;
};

int R, C, M, result;
int px, py;
vector<info> sharks;
vector<vector<int>> board(101, vector<int>(101, -1));

int dis(int idx) {
	return abs(px - sharks[idx].r) + abs(py - sharks[idx].c);
}

void catch_shark() {
	int temp = INT_MAX, idx = -1;

	//가까운 상어 잡기
	for (int i = 1; i <= R; i++) {
		if (board[i][py] == -1) continue;
		int now = board[i][py];
		if (temp > sharks[now].r) {
			temp = sharks[now].r;
			idx = now;
		}
	}

	if (idx == -1) return;
	result += sharks[idx].z; // 상어 크기
	sharks[idx].z = -1;
}

vector<vector<int>> move_shark() {
	vector<vector<int>> clone(101, vector<int>(101, -1));

	for (int i = 0; i < sharks.size(); i++) {
		info now = sharks[i];
		if (now.z == -1) continue;

		int tempr,tempc, tempd, temps, cnt, cntr;
		if (now.d == 2) { // 오른쪽
			tempr = now.s + now.r - 1;

			cnt = tempr / (R - 1);
			cntr = tempr % (R - 1);
			if (cntr > 0) cnt++;

			if (cnt % 2 == 0) {
				if (cntr == 0) {
					sharks[i].r = 1;
				}
				else { 
					sharks[i].r = R - cntr; 
				}
				sharks[i].d = 1;
			}
			else {
				if (cntr == 0) {
					sharks[i].r = R;
				}
				else {
					sharks[i].r = cntr + 1;
				}
			}
		}
		else if (now.d == 1) {
			tempr = now.s + R - now.r;

			cnt = tempr / (R - 1);
			cntr = tempr % (R - 1);
			if (cntr > 0) cnt++;

			if (cnt % 2 != 0) {
				if (cntr == 0) {
					sharks[i].r = 1;
				}
				else {
					sharks[i].r = R - cntr;
				}
			}
			else {
				sharks[i].d = 2;
				if (cntr == 0) {
					sharks[i].r = R;
				}
				else {
					sharks[i].r = cntr + 1;
				}
			}
		}
		else if (now.d == 3) { // 오른쪽
			tempc = now.s + now.c - 1;

			cnt = tempc / (C - 1);
			cntr = tempc % (C - 1);
			if (cntr > 0) cnt++;

			if (cnt % 2 == 0) {
				if (cntr == 0) {
					sharks[i].c = 1;
				}
				else {
					sharks[i].c = C - cntr;
				}
				sharks[i].d = 4;
			}
			else {
				if (cntr == 0) {
					sharks[i].c = C;
				}
				else {
					sharks[i].c = cntr + 1;
				}
			}
		}
		else if (now.d == 4) {
			tempc = now.s + C - now.c;

			cnt = tempc / (C - 1);
			cntr = tempc % (C - 1);
			if (cntr > 0) cnt++;

			if (cnt % 2 != 0) {
				if (cntr == 0) {
					sharks[i].c = 1;
				}
				else {
					sharks[i].c = C - cntr;
				}
			}
			else {
				sharks[i].d = 3;
				if (cntr == 0) {
					sharks[i].c = C;
				}
				else {
					sharks[i].c = cntr + 1;
				}
			}
		}

		// 같은 칸에 있는 상어 확인
		if (clone[sharks[i].r][sharks[i].c] != -1) {
			int prev = clone[sharks[i].r][sharks[i].c];
			if (sharks[i].z > sharks[prev].z) {
				sharks[prev].z = -1;
				clone[sharks[i].r][sharks[i].c] = i;
			}
			else {
				sharks[i].z = -1;
			}
		}
		else {
			clone[sharks[i].r][sharks[i].c] = i;
		}
	}

	return clone;
}

void show_sharks(){
	cout << "------------------------------\n";
	cout << result<<"\n";
	cout << "사람: " << px << " " << py << "\n";
	cout << "위치    속도   방향   크기\n";
	for (info shark : sharks) {
		if (shark.d == 3 || shark.d == 4) continue;
		cout <<"["<< shark.r << ", " << shark.c << "]    " << shark.s << ",    " << shark.d << ",    " << shark.z << "\n";
	}
}

void show_board() {
	cout << "------------------------------\n";
	cout << result << "\n";
	cout << "사람: " << px << " " << py << "\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << board[i][j] << "  ";
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C >> M;
	result = 0;

	sharks.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
		board[sharks[i].r][sharks[i].c] = i;
	}
	
	px = 0;
	py = 0;
	//cout << "d : 위, 아래, 오른쪽, 왼쪽\n";
	//show_sharks();
	while (py < C) {
		py++; // 1. 사람 이동
		catch_shark();
		board = move_shark();
		//show_board();
		//show_sharks();
	}
	
	cout << result;
}