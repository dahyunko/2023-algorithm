/*15650*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int ans[9];

void dfs(int cnt, vector<bool>&visited, int j) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = j; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans[cnt] = i;
			dfs(cnt + 1, visited,i+1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	vector<bool>visited(9, false);
	dfs(0, visited, 1);
}