#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

typedef pair<int, int> info;
int N;

void bfs(vector<vector<char>>& A, vector<vector<char>>& visited, int &result, int v_i, int v_j) {
	queue<info> q;
	visited[v_i][v_j] = 'T';
	q.push(info(v_i, v_j));

	while (!q.empty()) {
		int v_i = q.front().first;
		int v_j = q.front().second;
		q.pop();
		result++;
		if (v_j - 1 > 0) {
			if (A[v_i][v_j - 1] == '1' && visited[v_i][v_j - 1] == 'F') { q.push(info(v_i, v_j - 1)); visited[v_i][v_j - 1] = 'T'; }
		}
		if (v_j + 1 <= N) {
			if (A[v_i][v_j + 1] == '1' && visited[v_i][v_j + 1] == 'F') { q.push(info(v_i, v_j + 1)); visited[v_i][v_j + 1] = 'T'; }
		}
		if (v_i - 1 > 0) {
			if (A[v_i - 1][v_j] == '1' && visited[v_i - 1][v_j] == 'F') { q.push(info(v_i - 1, v_j)); visited[v_i - 1][v_j] = 'T'; }
		}
		if (v_i + 1 <= N) {
			if (A[v_i + 1][v_j] == '1' && visited[v_i + 1][v_j] == 'F') { q.push(info(v_i + 1, v_j)); visited[v_i + 1][v_j] = 'T'; }
		}
	}

}

int main() {
	cin >> N;
	vector<vector<char>>A(N + 1, vector<char>(N + 2, '0'));
	vector<vector<char>>visited(N + 1, vector<char>(N + 2, 'F'));
	//vector<vector<long>>ans(N + 1, vector<long>(N + 1, 0));
	vector<int>result;

	for (int i = 1; i <= N; i++) {
		string now;
		cin >> now;
		for (int j = 1; j <= N; j++) {
			A[i][j] = now[j - 1];
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] == '1' && visited[i][j] == 'F') {
				result.push_back(0);
				bfs(A, visited, result[cnt++],i, j);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) cout << result[i] << '\n';
}