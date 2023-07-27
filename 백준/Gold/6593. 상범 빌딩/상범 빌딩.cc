/*13*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct info { int x, y, z, time; };
char build[31][31][31];
bool visited[31][31][31];
int a[6] = { 0, 0, 0, 0, 1, -1 };
int b[6] = { 0, 0, 1, -1, 0, 0 };
int c[6] = { 1, -1, 0, 0, 0, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		int L, R, C;
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) break;
		int x, y, z, time = -1;

		for (int l = 0; l < L; l++) {
			for (int r = 0; r < R; r++) {
				string s;
				cin >> s;

				for (int c = 0; c < C; c++) {
					build[l][r][c] = s[c];
                    visited[l][r][c] = false;
					if (build[l][r][c] == 'S') {
						x = l; y = r; z = c;
					}
				}
			}
		}

		//층이동 
		queue<info>q;
		q.push({ x,y,z, 0 });
		while (!q.empty()) {
			info v = q.front();
			q.pop();

			if (build[v.x][v.y][v.z] == 'E') {
				time = v.time;
				break;
			}
			if (visited[v.x][v.y][v.z]) continue;
			visited[v.x][v.y][v.z] = true;

			for (int i = 0; i < 6; i++) {
				if (v.x + a[i] >= 0 && v.x + a[i] < L && v.y + b[i] >= 0 && v.y + b[i] < R && v.z + c[i] >= 0 && v.z + c[i] < C) {
					if (build[v.x + a[i]][v.y + b[i]][v.z + c[i]] != '#') {
						q.push({ v.x + a[i], v.y + b[i], v.z + c[i], v.time + 1 });
					}
				}
			}
		}

		if (time == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << time << " minute(s).\n";
	}
}