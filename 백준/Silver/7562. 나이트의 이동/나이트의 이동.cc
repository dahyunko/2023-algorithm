/*10*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct info {
	int x, y, cnt;
};
int a[8] = { 1, 2, 2, 1, -2, -1, -2, -1 };
int b[8] = { 2, 1, -1, -2, 1, 2, -1, -2 };

int main() {
	int T, ans;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int L, s1, s2, e1, e2;
		cin >> L;

		vector<vector<bool>>visited(L, vector<bool>(L, false));
		cin >> s1 >> s2;
		cin >> e1 >> e2;

		queue<info>q;
		q.push({ s1, s2, 0 });
		while (!q.empty()) {
			info v = q.front();
			q.pop();

			if (v.x == e1 && v.y == e2) {
				ans = v.cnt;
				break;
			}

			if (visited[v.x][v.y]) continue;
			visited[v.x][v.y] = true;

			for (int i = 0; i < 8; i++) {
				if (v.x + a[i] >= 0 && v.x + a[i] < L && v.y + b[i] >= 0 && v.y + b[i] < L) {
					q.push({ v.x + a[i] , v.y + b[i], v.cnt + 1 });
				}
			}
		}

		cout << ans << '\n';
	}
}