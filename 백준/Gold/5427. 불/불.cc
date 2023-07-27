/*17*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct info { int h, w, time; };
char build[1001][1001];
int a[4] = { 1, -1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	info user, fire;
	for (int t = 0; t < T; t++) {
		int W, H, b_time=0, u_time= 0, ans = -1;
		cin >> W >> H;
		
		vector<vector<bool>>visited(H, vector<bool>(W, false));
		queue<info>burn_q;
		queue<info>q;

		//지도
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				cin >> build[h][w];
				if (build[h][w] == '@') {
					build[h][w] == '.';
					q.push({ h,w,0 });
				}
				if (build[h][w] == '*') burn_q.push({ h,w,0 });
			}
		}

		bool user_out = false;
		while (true) {
			bool no_move = true;
			//불 번짐
			while(!burn_q.empty()){
				info v = burn_q.front();

				if (v.time > b_time) {
					b_time++;
					break;
				}
				burn_q.pop();
				if (visited[v.h][v.w]) continue;
				visited[v.h][v.w] = true;

				for (int i = 0; i < 4; i++) {
					if (v.h + a[i] >= 0 && v.h + a[i] < H && v.w + b[i] >= 0 && v.w + b[i] < W) {
						if (build[v.h + a[i]][v.w + b[i]] == '.' ) {
							no_move = false;
							build[v.h + a[i]][v.w + b[i]] == '*';
							burn_q.push({ v.h + a[i], v.w + b[i], v.time + 1 });
						}
					}
				}
			}
			
			//user 이동
			while (!q.empty()) {
				info v = q.front();

				if (v.time > u_time) {
					u_time++;
					break;
				}
				q.pop();
				if (visited[v.h][v.w]) continue;
				visited[v.h][v.w] = true;

				for (int i = 0; i < 4; i++) {
					if (v.h + a[i] >= 0 && v.h + a[i] < H && v.w + b[i] >= 0 && v.w + b[i] < W) {
						if (build[v.h + a[i]][v.w + b[i]] == '.') {
							no_move = false;
							q.push({ v.h + a[i], v.w + b[i], v.time + 1 });
						}
					}
					else {
						ans = v.time+1;
						user_out = true;
						break;
					}
				}
			}

			if (user_out || no_move ) break;
		}
		
		if (user_out) cout << ans << '\n';
		else cout << "IMPOSSIBLE\n";
	}
}