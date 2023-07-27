/*14*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct info { int x, y, day; };
int a[4] = { 1, -1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };

int main() {
	int M, N;
	cin >> M >> N;

	vector<vector<int>> A(N, vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	int total = 0, day = 1, temp = 0;
	queue<info>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			if (A[i][j] != -1) {
				if (A[i][j] == 1) {
					q.push({ i, j , 1});
					temp++;//익은 거 개수
				}
				total++;
			}
		}
	}

	if (total == temp) cout << 0;
	else {
		bool every_is_okay = false;
		while (!q.empty()) {
			info v = q.front();

			if (day < v.day) {
				day++;
				continue;
			}
			q.pop();

			if (visited[v.x][v.y]) continue;
			visited[v.x][v.y] = true;

			for (int i = 0; i < 4; i++) {
				if (v.x + a[i] >= 0 && v.x + a[i] < N && v.y + b[i] >= 0 && v.y + b[i] < M) {
					if (A[v.x + a[i]][v.y + b[i]] == 0) {
						temp++;
						A[v.x + a[i]][v.y + b[i]] = 1;
						q.push({ v.x + a[i],v.y + b[i],v.day + 1 });
					}
				}
			}

			if (temp == total) {
				every_is_okay = true;
				break;
			}
		}

		if (every_is_okay) cout << day;
		else cout << -1;
	}
	
}