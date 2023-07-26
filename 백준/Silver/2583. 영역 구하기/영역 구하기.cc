/*4*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int M, N, K;
int board[101][101] = { 0 };
bool visited[101][101] = { false };
int a[4] = { 1, -1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };
int cnt;

typedef pair<int, int> info;

int main() {
	cin >> M >> N >> K;

	vector<int> ans;
	//그래프 생성
	for (int t = 0; t < K; t++) {
		int a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;

		if (a1 > b1) swap(a1, b1);
		if (a2 > b2) swap(a2, b2);

		for (int i = a1; i < b1; i++) {
			for (int j = a2; j < b2; j++) board[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && board[i][j] == 0) {
				//갯수 세기 시작
				cnt = 0;

				queue<info>q;
				q.push({ i, j });
				while (!q.empty()){
					info v = q.front();
					q.pop();

					if (visited[v.first][v.second]) continue;
					visited[v.first][v.second] = true;
					cnt++;

					for (int t = 0; t < 4; t++) {
						if (v.first + a[t] >= 0 && v.first + a[t] < N && v.second + b[t] >= 0 && v.second + b[t] < M) {
							if (board[v.first + a[t]][v.second + b[t]] == 0) {
								q.push({ v.first + a[t], v.second + b[t] });
							}
						}
					}

				}				

				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}