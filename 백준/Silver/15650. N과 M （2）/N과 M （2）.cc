/*15650*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int ans[9];

void dfs(int cnt, vector<bool>&visited) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans[cnt] = i;
			dfs(cnt + 1, visited);
			for (int j = i + 1; j <= N; j++) visited[j] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	vector<bool>visited(9, false);
	dfs(0, visited);
}