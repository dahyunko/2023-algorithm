/*18*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct info { int x, y, z; };
int A[1001][1001];
int visited[1001][1001][2];//이동 횟수 기록
int a[4] = { 1, -1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };

int main() {
	int N, M, ans =-1;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) A[i][j] = s[j]-'0';
	}

	queue<info>q;
	visited[0][0][0] = 1;
	visited[0][0][1] = 1;
	q.push({ 0,0,0 });
	q.push({ 0,0,1 });
	while (!q.empty()) {
		info v = q.front();
		q.pop();

		if (v.x == N - 1 && v.y == M - 1) {
			ans = visited[v.x][v.y][v.z];
			break;
		}

		for (int i = 0; i < 4; i++) {
			if (v.x + a[i] >= 0 && v.x + a[i] < N && v.y + b[i] >= 0 && v.y + b[i] < M) {
				if (visited[v.x+a[i]][v.y+b[i]][v.z]) continue;

				if (A[v.x + a[i]][v.y + b[i]] == 0) {
					visited[v.x + a[i]][v.y + b[i]][v.z] = visited[v.x][v.y][v.z] + 1;
					q.push({ v.x + a[i], v.y + b[i], v.z });
				}
				else if (v.z == 0 && A[v.x + a[i]][v.y + b[i]] == 1) {
					visited[v.x + a[i]][v.y + b[i]][1] = visited[v.x][v.y][v.z] + 1;
					q.push({ v.x + a[i], v.y + b[i], 1});
				}
			}
		}
	}
    
    cout << ans;
}