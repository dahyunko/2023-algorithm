#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

/*4485*/
int p[4] = { 1, -1, 0 , 0 };
int q[4] = { 0 , 0, 1, -1 };

struct info {
	int x, y, w;
};

struct comp {
	bool operator()(info a, info b) {
		return a.w > b.w;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		t++;
		vector<vector<int>>A(N, vector<int>(N));
		vector<vector<bool>>visited(N, vector<bool>(N, false));
		vector<vector<int>>D(N, vector<int>(N, INT_MAX));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)cin >> A[i][j];
		}

		//bfs
		priority_queue<info, vector<info>, comp> pq;
		D[0][0] = A[0][0];
		pq.push({ 0, 0, D[0][0] });
		while (!pq.empty()) {
			info v = pq.top();
			pq.pop();

			if (v.x == N - 1 && v.y == N - 1) break;

			if (visited[v.x][v.y]) continue;
			visited[v.x][v.y] = true;

			for (int i = 0; i < 4; i++) {
				int xx = v.x + p[i];
				int yy = v.y + q[i];
				if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
					if (D[v.x][v.y] + A[xx][yy] < D[xx][yy]) {
						D[xx][yy] = D[v.x][v.y] + A[xx][yy];
						pq.push({ xx, yy, D[xx][yy] });
					}
				}
			}
		}
		cout << "Problem " <<  t<< ": " << D[N - 1][N - 1] << '\n';
	}
}