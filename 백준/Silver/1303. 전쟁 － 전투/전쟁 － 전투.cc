/*전투- 1303*/
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> info;

int N, M;

long bfs(vector<string>& A, vector<vector<bool>>& visited, int v_i, int v_j, char c) {
	visited[v_i][v_j] = true;

	int cnt = 1;
	queue<info> q;
	q.push(info(v_i, v_j));
	
	while (!q.empty()) {
		info now = q.front();
		int n_i = now.first, n_j = now.second;
		q.pop();

		if (n_i + 1 < M && !visited[n_i + 1][n_j] && A[n_i+1][n_j] == c) {
			cnt++;
			visited[n_i + 1][n_j] = true;
			q.push(info(n_i + 1, n_j));
		}
		if (n_i - 1 >= 0 && !visited[n_i - 1][n_j] && A[n_i - 1][n_j] == c) {
			cnt++;
			visited[n_i - 1][n_j] = true;
			q.push(info(n_i - 1, n_j));
		}
		if (n_j + 1 < N && !visited[n_i][n_j + 1] && A[n_i][n_j + 1] == c) {
			cnt++;
			visited[n_i][n_j + 1] = true;
			q.push(info(n_i, n_j + 1));
		}
		if (n_j - 1 >= 0 && !visited[n_i][n_j - 1] && A[n_i][n_j - 1] == c) {
			cnt++;
			visited[n_i][n_j - 1] = true;
			q.push(info(n_i, n_j - 1));
		}
	}

	return cnt;
}

int main() {
	cin >> N >> M;

	vector<string>A(M);
	vector<vector<bool>>visited(M, vector<bool>(N, false));
	long t1 = 0, t2 = 0;

	for (int i = 0; i < M; i++) cin >> A[i];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			if (A[i][j] == 'W' && !visited[i][j]) {
				temp = bfs(A, visited, i, j, 'W');
				t1 += temp * temp;
			}
			else if (A[i][j] == 'B' && !visited[i][j]) {//blue
				temp = bfs(A, visited, i, j, 'B');
				t2 += temp * temp;
			}
		}
	}

	cout << t1<<' '<< t2;
}