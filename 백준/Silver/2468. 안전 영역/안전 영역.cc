/*2468*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;

int N, value_max = 0, value_min = 100;
int A[101][101] = { 0 };
int ans = 0, result = 1;

void dfs(vector<vector<bool>>&visited, int i, int j, int t) {
	visited[i][j] = true;

	if (i - 1 >= 0 && !visited[i - 1][j] && A[i - 1][j] > t) dfs(visited, i - 1, j, t);
	if (i + 1 < N && !visited[i + 1][j] && A[i + 1][j] > t) dfs(visited, i + 1, j, t);
	if (j - 1 >= 0 && !visited[i][j-1] && A[i][j-1] > t) dfs(visited, i, j-1, t);
	if (j + 1 < N && !visited[i][j+1] && A[i][j+1] > t) dfs(visited, i, j+1, t);
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			value_max = max(value_max, A[i][j]);
			value_min = min(value_min, A[i][j]);
		}
	}

	for (int t = value_min; t <= value_max; t++) {
		vector<vector<bool>>visited(N, vector<bool>(N, false));
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && A[i][j] > t) {
					dfs(visited, i, j, t);
					ans++;
				}
			}
		}
		result = max(ans, result);
	}

	cout << result;
}